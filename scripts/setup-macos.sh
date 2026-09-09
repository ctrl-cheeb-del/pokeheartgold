#!/usr/bin/env bash
# Reproduce this fork's macOS toolchain without changing system Wine settings.
set -euo pipefail
cd "$(dirname "$0")/.."
if [[ "$(uname -s)" != Darwin ]]; then
    echo 'This helper is for macOS. Other platforms: see INSTALL.md.' >&2
    exit 1
fi
command -v brew >/dev/null || { echo 'Install Homebrew first: https://brew.sh' >&2; exit 1; }
if [[ "$(uname -m)" == arm64 ]] && ! arch -x86_64 /usr/bin/true; then
    echo 'Rosetta 2 is required to run the original x86 compiler through Wine.' >&2
    exit 1
fi
HOMEBREW_NO_AUTO_UPDATE=1 brew install coreutils make gnu-sed arm-none-eabi-binutils pugixml libpng pkgconf sevenzip
python3 - <<'PY'
import hashlib
from pathlib import Path
import shutil
import subprocess
import tempfile
import urllib.request
import zipfile

root = Path.cwd()
local = root / '.local-tools'
local.mkdir(exist_ok=True)
assets = 'https://raw.githubusercontent.com/pret/pokeheartgold/workflows/assets/'

def download(url, path, expected):
    print(f'Downloading {path.name}', flush=True)
    urllib.request.urlretrieve(url, path)
    actual = hashlib.sha256(path.read_bytes()).hexdigest()
    if actual != expected:
        raise SystemExit(f'SHA256 mismatch for {path.name}: {actual}')

with tempfile.TemporaryDirectory(prefix='pokeheartgold-setup-') as folder:
    tmp = Path(folder)
    if not (root / 'tools/mwccarm/2.0/sp2p2/mwccarm.exe').exists():
        archive = tmp / 'mwccarm.zip'
        download(assets + archive.name, archive, 'dc386e37b2176e960954a733de928337d9b7e7620b9e94228008c31774339ace')
        with zipfile.ZipFile(archive) as z:
            z.extractall(tmp)
        shutil.copytree(tmp / 'mwccarm', root / 'tools/mwccarm', dirs_exist_ok=True)
    required = ['tools/bin/makelcf.exe', 'sub/ARM7-TS.lcf.template', 'ARM9-TS.lcf.template', 'mwldarm.response.template']
    if not all((root / p).exists() for p in required):
        archive = tmp / 'NitroSDK-3_2-060901.7z'
        download(assets + archive.name, archive, '0ee935e34237cb1954e657083cd80a31ec9de1aeddd9468cceef684cac75b491')
        subprocess.run(['7zz', 'x', str(archive), '-o' + str(tmp)], check=True, stdout=subprocess.DEVNULL)
        sdk = tmp / 'NitroSDK-3_2-060901'
        shutil.copytree(sdk / 'tools/bin', root / 'tools/bin', dirs_exist_ok=True)
        for name, dest in [('ARM7-TS.lcf.template', root / 'sub'), ('ARM9-TS.lcf.template', root), ('mwldarm.response.template', root)]:
            shutil.copy2(sdk / 'include/nitro/specfiles' / name, dest / name)
    if not (local / 'Wine Devel.app/Contents/Resources/wine/bin/wine').exists():
        archive = tmp / 'wine-devel-11.16-osx64.tar.xz'
        download('https://github.com/Gcenx/macOS_Wine_builds/releases/download/11.16/' + archive.name,
                 archive, '6f9af818b7af6001aeed7818cb32bf0155598c5ea4e3b33380a03cf814e033cd')
        subprocess.run(['tar', '-xf', str(archive), '-C', str(local)], check=True)
print('Toolchain ready. Run ./scripts/build.sh progress')
PY
