	.ifndef ASM_SCRIPT_INC
	.set ASM_SCRIPT_INC, 1
#pragma once
#include "constants/scrcmd.h"
#include "macros/movement.inc"

    .option alignment off

	.macro ScrDef offset
	.word \offset - . - 4
	.endm

	.macro ScrDefEnd
	.short SCRDEF_END
	.endm

	; Dummy command
	.macro Noop
	.short 0
	.endm

	; Dummy command
	.macro Dummy
	.short 1
	.endm

	; Exits script execution and returns control to the player
	.macro End
	.short 2
	.endm

	; Pauses for some frames, tracks the timer in a script variable
	.macro Wait frames, var
	.short 3
	.short \frames
	.short \var
	.endm

	; Loads 8-bit value into the specified script register
	.macro LoadByte reg, val
	.short 4
	.byte \reg
	.byte \val
	.endm

	; Loads 32-bit value into the specified script register
	.macro LoadWord reg, val
	.short 5
	.byte \reg
	.word \val
	.endm

	; Reads byte at a specific memory address into a script register
	; Because scripts are compiled in a code-agnostic fashion,
	; this command can never be assembled.
	.macro LoadByteFromAddr reg, addr
	.short 6
	.byte \reg
	.word \addr
	.endm

	; Writes byte to a specific memory address from a script register
	; Because scripts are compiled in a code-agnostic fashion,
	; this command can never be assembled.
	.macro WriteByteToAddr addr, reg
	.short 7
	.word \addr
	.byte \reg
	.endm

	; Writes byte literal to a specific memory address
	; Because scripts are compiled in a code-agnostic fashion,
	; this command can never be assembled.
	.macro SetPtrByte addr, val
	.short 8
	.word \addr
	.byte \val
	.endm

	; Copies a byte between script registers
	.macro CopyLocal to, from
	.short 9
	.byte \to
	.byte \from
	.endm

	; Copies a byte between two memory addresses
	; Because scripts are compiled in a code-agnostic fashion,
	; this command can never be assembled.
	.macro CopyByte to, from
	.short 10
	.word \to
	.word \from
	.endm

	; Compares values between script reg and script reg
	.macro CompareLocalToLocal a, b
	.short 11
	.byte \a
	.byte \b
	.endm

	; Compares script reg to byte literal
	.macro CompareLocalToValue reg, val
	.short 12
	.byte \reg
	.byte \val
	.endm

	; Compares script reg to memory address
	; Because scripts are compiled in a code-agnostic fashion,
	; this command can never be assembled.
	.macro CompareLocalToAddr reg, addr
	.short 13
	.byte \reg
	.word \addr
	.endm

	; Compares memory address to script reg
	; Because scripts are compiled in a code-agnostic fashion,
	; this command can never be assembled.
	.macro CompareAddrToLocal addr, reg
	.short 14
	.word \addr
	.byte \reg
	.endm

	; Compares memory address to byte literal
	; Because scripts are compiled in a code-agnostic fashion,
	; this command can never be assembled.
	.macro CompareAddrToValue addr, val
	.short 15
	.word \addr
	.byte \val
	.endm

	; Compares bytes at two memory addresses
	; Because scripts are compiled in a code-agnostic fashion,
	; this command can never be assembled.
	.macro CompareAddrToAddr a, b
	.short 16
	.word \a
	.word \b
	.endm

	; Compares variable to 16-bit literal
	.macro CompareVarToValue var, val
	.short 17
	.short \var
	.short \val
	.endm

	; Compares two variables
	.macro CompareVarToVar a, b
	.short 18
	.short \a
	.short \b
	.endm

	; Creates a new script context to run the indicated script asynchronously
	.macro RunScript id
	.short 19
	.short \id
	.endm

	; Creates a new script context to run the indicated script and wait
	.macro CallStd id
	.short 20
	.short \id
	.endm

	; Yield to parent context
	.macro RestartCurrentScript
	.short 21
	.endm

	; Absolute branch to offset in script
	.macro GoTo dest
	.short 22
	.word \dest-.-4
	.endm

	; Branch to offset in script if interacting with a specific object
	.macro ObjectGoTo object, dest
	.short 23
	.byte \object
	.word \dest-.-4
	.endm

	; Branch to offset in script if interacting with a specific bg event
	.macro BGGoTo bg, dest
	.short 24
	.byte \bg
	.word \dest-.-4
	.endm

	; Branch to offset in script if facing a specific direction
	.macro DirectionGoTo dir, dest
	.short 25
	.byte \dir
	.word \dest-.-4
	.endm

	; Call script as a subroutine
	.macro Call sub
	.short 26
	.word \sub-.-4
	.endm

	; Return from subroutine
	.macro Return
	.short 27
	.endm

	; Conditional branch to offset in script
	.macro GoToIf condition, dest
	.short 28
	.byte \condition
	.word \dest-.-4
	.endm

	; Conditional call subroutine
	.macro CallIf condition, sub
	.short 29
	.byte \condition
	.word \sub-.-4
	.endm

	; Set event flag
	.macro SetFlag flag
	.short 30
	.short \flag
	.endm

	; Clear event flag
	.macro ClearFlag flag
	.short 31
	.short \flag
	.endm

	; Check event flag, store result on context
	.macro CheckFlag flag
	.short 32
	.short \flag
	.endm

	; Set event flag referenced in var
	.macro SetFlagVar var
	.short 33
	.short \var
	.endm

	; Clear event flag referenced in var
	.macro ClearFlagVar var
	.short 34
	.short \var
	.endm

	; Check event flag referenced in var, store result in other var
	.macro CheckFlagVar var_flag, var_dest
	.short 35
	.short \var_flag
	.short \var_dest
	.endm

	; Set trainer defeated flag
	.macro SetTrainerFlag var_or_trno
	.short 36
	.short \var_or_trno
	.endm

	; Clear trainer defeated flag
	.macro ClearTrainerFlag var_or_trno
	.short 37
	.short \var_or_trno
	.endm

	; Check trainer defeated flag, store result on context
	.macro CheckTrainerFlag var_or_trno
	.short 38
	.short \var_or_trno
	.endm

	; Increment var value by value
	.macro AddVar var, var_or_addend
	.short 39
	.short \var
	.short \var_or_addend
	.endm

	; Decrement var value by value
	.macro SubVar var, var_or_addend
	.short 40
	.short \var
	.short \var_or_addend
	.endm

	; Set var to short literal
	.macro SetVar var, val
	.short 41
	.short \var
	.short \val
	.endm

	; Set var from other var
	.macro CopyVar dst, src
	.short 42
	.short \dst
	.short \src
	.endm

	; Set var from other var or short literal
	.macro SetOrCopyVar dst, src
	.short 43
	.short \dst
	.short \src
	.endm

	; Print non_npc_msg in field window from current map message bank
	.macro NonNPCMsg msg_id
	.short 44
	.byte \msg_id
	.endm

	; NPC dialogue window
	.macro NPCMsg msg_id
	.short 45
	.byte \msg_id
	.endm

	; Not sure what to call this but it
	; is also a message printer
	.macro NonNPCMsgVar msg_id
	.short 46
	.short \msg_id
	.endm

	.macro NPCMsgVar arg0
	.short 47
	.short \arg0
	.endm

	.macro NPCMsgAutoScrollInLink msg
	.short 48
	.byte \msg
	.endm

	; Waits for A or B button
	.macro WaitABPress
	.short 49
	.endm

	; Waits for A, B, or dpad. On pressing dpad, does a turn frame.
	.macro WaitButton
	.short 50
	.endm

	; Waits for A, B, or dpad. No turn frame.
	.macro WaitButtonOrDpad
	.short 51
	.endm

	.macro OpenMsg
	.short 52
	.endm

	.macro CloseMsg
	.short 53
	.endm

	; Like closemsg but does not clear the graphics.
	.macro HoldMsg
	.short 54
	.endm

	.macro DirectionSignpost message, type, map, out
	.short 55
	.byte \message
	.byte \type
	.short \map
	.short \out
	.endm

	.macro SetSignpostMap type, map
	.short 56
	.byte \type
	.short \map
	.endm

	.macro SetSignpostAction cmd
	.short 57
	.byte \cmd
	.endm

	.macro WaitSignpostAction
	.short 58
	.endm

	.macro TrainerTips message, out
	.short 59
	.byte \message
	.short \out
	.endm

	.macro TrainerTipsEx type, message
	SetSignpostMap \type, 0
	SetSignpostAction MAPSIGNCOMMAND_WIPE_IN
	WaitSignpostAction
	TrainerTips \message, VAR_SPECIAL_RESULT
	CallStd std_signpost
	.endm

	.macro WaitSignpost out
	.short 60
	.short \out
	.endm

	.macro DirectionSignpostEx type, map, message
	DirectionSignpost \message, \type, \map, VAR_SPECIAL_RESULT
	SetSignpostAction MAPSIGNCOMMAND_WIPE_IN
	WaitSignpostAction
	WaitSignpost VAR_SPECIAL_RESULT
	CallStd std_signpost
	.endm

	.macro ReopenStartMenuOnEnd
	.short 61
	.endm

	.macro ScrollMsgBg arg0, arg1, arg2, arg3, arg4, arg5
	.short 62
	.byte \arg0
	.byte \arg1
	.byte \arg2
	.byte \arg3
	.byte \arg4
	.byte \arg5
	.endm

	.macro YesNo arg0
	.short 63
	.short \arg0
	.endm

	.macro MultichoiceInitStdGmm x, y, cursor, cancellable, var
	.short 64
	.byte \x
	.byte \y
	.byte \cursor
	.byte \cancellable
	.short \var
	.endm

	.macro MultichoiceInit x, y, cursor, cancellable, var
	.short 65
	.byte \x
	.byte \y
	.byte \cursor
	.byte \cancellable
	.short \var
	.endm

	.macro MultichoiceItemAdd msg, value
	.short 66
	.byte \msg
	.byte \value
	.endm

	.macro MultichoiceExec
	.short 67
	.endm

	.macro ScriptListMenuInitStdGmm x, y, cursor, cancellable, var
	.short 68
	.byte \x
	.byte \y
	.byte \cursor
	.byte \cancellable
	.short \var
	.endm

	.macro ScriptListMenuInit x, y, cursor, cancellable, var
	.short 69
	.byte \x
	.byte \y
	.byte \cursor
	.byte \cancellable
	.short \var
	.endm

	.macro ScriptListMenuItemAdd msg, help_msg, value
	.short 70
	.short \msg
	.short \help_msg
	.short \value
	.endm

	.macro ScriptListMenuExec
	.short 71
	.endm

	.macro MultichoiceGridExec columns
	.short 72
	.byte \columns
	.endm

	.macro PlaySE arg0
	.short 73
	.short \arg0
	.endm

	.macro StopSE arg0
	.short 74
	.short \arg0
	.endm

	.macro WaitSE arg0
	.short 75
	.short \arg0
	.endm

	.macro PlayCry arg0, arg1
	.short 76
	.short \arg0
	.short \arg1
	.endm

	.macro WaitCry
	.short 77
	.endm

	.macro PlayFanfare fanfare
	.short 78
	.short \fanfare
	.endm

	.macro WaitFanfare
	.short 79
	.endm

	.macro PlayBGM bgm
	.short 80
	.short \bgm
	.endm

	.macro StopBGM arg0
	.short 81
	.short \arg0
	.endm

	.macro ResetBGM
	.short 82
	.endm

	.macro SetBGMOverride seq
	.short 83
	.short \seq
	.endm

	; Fade out the music to the target level
	; in the designated number of frames
	.macro FadeOutBGM target, frames
	.short 84
	.short \target
	.short \frames
	.endm

	.macro FadeInBGM arg0
	.short 85
	.short \arg0
	.endm

	.macro SetSoundPlayerPause player, paused
	.short 86
	.byte \player
	.byte \paused
	.endm

	.macro TempBGM arg0
	.short 87
	.short \arg0
	.endm

	.macro SetBGMDisabled disabled
	.short 88
	.byte \disabled
	.endm

	.macro ChatotHasCry arg0
	.short 89
	.short \arg0
	.endm

	.macro ChatotStartRecording arg0
	.short 90
	.short \arg0
	.endm

	.macro ChatotStopRecording
	.short 91
	.endm

	.macro ChatotSaveRecording
	.short 92
	.endm

	.macro SetSoundScene63
	.short 93
	.endm

	.macro ApplyMovement arg0, arg1
	.short 94
	.short \arg0
	.word \arg1-.-4
	.endm

	.macro WaitMovement
	.short 95
	.endm

	.macro LockAll
	.short 96
	.endm

	.macro ReleaseAll
	.short 97
	.endm

	.macro Lock arg0
	.short 98
	.short \arg0
	.endm

	.macro Release arg0
	.short 99
	.short \arg0
	.endm

	.macro ShowPerson arg0
	.short 100
	.short \arg0
	.endm

	.macro HidePerson arg0
	.short 101
	.short \arg0
	.endm

	.macro CreateCameraTarget x, y
	.short 102
	.short \x
	.short \y
	.endm

	.macro RemoveCameraTarget
	.short 103
	.endm

	.macro FacePlayer
	.short 104
	.endm

	.macro GetPlayerCoords arg0, arg1
	.short 105
	.short \arg0
	.short \arg1
	.endm

	.macro GetPersonCoords arg0, arg1, arg2
	.short 106
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro OffsetPlayerAndCamera x, y, z
	.short 107
	.short \x
	.short \y
	.short \z
	.endm

	.macro SetObjectKeep object, keep
	.short 108
	.short \object
	.byte \keep
	.endm

	.macro ChangeObjectMovement object, movement
	.short 109
	.short \object
	.short \movement
	.endm

	.macro AddMoney arg0
	.short 110
	.word \arg0
	.endm

	.macro SubMoneyImmediate arg0
	.short 111
	.word \arg0
	.endm

	.macro HasEnoughMoneyImmediate arg0, arg1
	.short 112
	.short \arg0
	.word \arg1
	.endm

	.macro ShowMoneyBox arg0, arg1
	.short 113
	.short \arg0
	.short \arg1
	.endm

	.macro HideMoneyBox
	.short 114
	.endm

	.macro UpdateMoneyBox
	.short 115
	.endm

	.macro ShowPointsBox type, x, y
	.short 116
	.byte \type
	.short \x
	.short \y
	.endm

	.macro HidePointsBox
	.short 117
	.endm

	.macro UpdatePointsBox type
	.short 118
	.byte \type
	.endm

	.macro GetCoinAmount arg0
	.short 119
	.short \arg0
	.endm

	.macro GiveCoins arg0
	.short 120
	.short \arg0
	.endm

	.macro TakeCoins arg0
	.short 121
	.short \arg0
	.endm

	.macro GiveAthletePoints arg0
	.short 122
	.short \arg0
	.endm

	.macro TakeAthletePoints arg0
	.short 123
	.short \arg0
	.endm

	.macro CheckAthletePoints arg0, arg1
	.short 124
	.short \arg0
	.short \arg1
	.endm

	.macro GiveItem arg0, arg1, arg2
	.short 125
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro TakeItem arg0, arg1, arg2
	.short 126
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro HasSpaceForItem arg0, arg1, arg2
	.short 127
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro HasItem arg0, arg1, arg2
	.short 128
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro ItemIsTMOrHM arg0, arg1
	.short 129
	.short \arg0
	.short \arg1
	.endm

	.macro GetItemPocket arg0, arg1
	.short 130
	.short \arg0
	.short \arg1
	.endm

	.macro SetStarterChoice arg0
	.short 131
	.short \arg0
	.endm

	.macro GenderMsgBox arg0, arg1
	.short 132
	.byte \arg0
	.byte \arg1
	.endm

	.macro GetSealQuantity arg0, arg1
	.short 133
	.short \arg0
	.short \arg1
	.endm

	.macro GiveOrTakeSeal arg0, arg1
	.short 134
	.short \arg0
	.short \arg1
	.endm

	.macro GiveRandomSeal arg0, arg1, arg2
	.short 135
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro GetPartyMonUnownLetter slot, var
	.short 136
	.short \slot
	.short \var
	.endm

	.macro GiveMon species, level, heldItem, form, ability, retvar
	.short 137
	.short \species
	.short \level
	.short \heldItem
	.short \form
	.short \ability
	.short \retvar
	.endm

	.macro GiveEgg arg0, arg1
	.short 138
	.short \arg0
	.short \arg1
	.endm

	.macro SetMonMove arg0, arg1, arg2
	.short 139
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro MonHasMove arg0, arg1, arg2
	.short 140
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro GetPartySlotWithMove arg0, arg1
	.short 141
	.short \arg0
	.short \arg1
	.endm

	.macro GetPhoneBookRematch arg0, arg1
	.short 142
	.short \arg0
	.short \arg1
	.endm

	.macro NameRival arg0
	.short 143
	.short \arg0
	.endm

	.macro GetFriendSprite arg0
	.short 144
	.short \arg0
	.endm

	.macro RegisterPokegearCard arg0
	.short 145
	.byte \arg0
	.endm

	.macro RegisterGearNumber arg0
	.short 146
	.short \arg0
	.endm

	.macro CheckRegisteredPhoneNumber arg0, arg1
	.short 147
	.short \arg0
	.short \arg1
	.endm

	.macro SetPhoneCallTrigger trigger, state
	.short 148
	.byte \trigger
	.byte \state
	.endm

	.macro UnsetPhoneCallTrigger arg0
	.short 149
	.byte \arg0
	.endm

	.macro RestoreOverworld
	.short 150
	.endm

	.macro StartPalPadRegistration
	.short 151
	.endm

	.macro OpenWifiClub
	.short 152
	.endm

	.macro FashionAppGetEntryIndex var
	.short 153
	.short \var
	.endm

	.macro OpenDressUp mode, result_var, arg
	.short 154
	.short \mode
	.short \result_var
	.short \arg
	.endm

	.macro OpenAccessoryPortrait mode, var
	.short 155
	.short \mode
	.short \var
	.endm

	.macro OpenBallCapsuleEditor
	.short 156
	.endm

	.macro TownMap
	.short 157
	.endm

	.macro OpenPCBox mode
	.short 158
	.byte \mode
	.endm

	.macro OpenDrawingSession
	.short 159
	.endm

	.macro OpenLinkTrainerCard
	.short 160
	.endm

	.macro OpenWirelessTrade
	.short 161
	.endm

	.macro OpenRecordMixing
	.short 162
	.endm

	.macro HOFCredits arg0
	.short 163
	.short \arg0
	.endm

	.macro OpenHallOfFameShowcase
	.short 164
	.endm

	.macro OpenGts mode, var
	.short 165
	.short \mode
	.short \var
	.endm

	.macro OpenWifiClubWithResult var
	.short 166
	.short \var
	.endm

	.macro ChooseStarter
	.short 167
	.endm

	.macro GetTrainerPathToPlayer arg0
	.short 168
	.short \arg0
	.endm

	.macro TrainerStepTowardsPlayer arg0, arg1
	.short 169
	.short \arg0
	.short \arg1
	.endm

	.macro GetTrainerEyeType arg0
	.short 170
	.short \arg0
	.endm

	; For when one or more trainers see you
	.macro GetEyeTrainerNum arg0, arg1
	.short 171
	.short \arg0
	.short \arg1
	.endm

	.macro NamePlayer arg0
	.short 172
	.short \arg0
	.endm

	.macro NicknameInput arg0, arg1
	.short 173
	.short \arg0
	.short \arg1
	.endm

	.macro FadeScreen arg0, speed, direction, color
	.short 174
	.short \arg0
	.short \speed
	.short \direction
	.short \color
	.endm

	.macro WaitFade
	.short 175
	.endm

	.macro Warp arg0, arg1=0, arg2, arg3, arg4
	.short 176
	.short \arg0
	.short \arg1
	.short \arg2
	.short \arg3
	.short \arg4
	.endm

	.macro RockClimb arg0
	.short 177
	.short \arg0
	.endm

	.macro Surf arg0
	.short 178
	.short \arg0
	.endm

	.macro Waterfall arg0
	.short 179
	.short \arg0
	.endm

	.macro FlyWarp map, x, y
	.short 180
	.short \map
	.short \x
	.short \y
	.endm

	.macro FlashEffect
	.short 181
	.endm

	.macro Whirlpool arg0
	.short 182
	.short \arg0
	.endm

	.macro PlayFieldMoveCutIn slot
	.short 183
	.short \slot
	.endm

	.macro PlayerOnBikeCheck arg0
	.short 184
	.short \arg0
	.endm

	.macro PlayerOnBikeSet arg0
	.short 185
	.byte \arg0
	.endm

	; If `lock` is 1, the player's bike state will
	; be locked, meaning they cannot mount or
	; dismount their bike; otherwise, if `lock` is
	; any other value, the bike state will be
	; unlocked. The main use for this command was
	; to block the player from dismounting their
	; bike while they were on Cycling Road.
	.macro SetBikeStateLock lock
	.short 186
	.byte \lock
	.endm

	; Get the player's overworld state.
	; Used in some places to determine whether
	; the player is masquerading as a member
	; of Team Rocket.
	.macro GetPlayerState var
	.short 187
	.short \var
	.endm

	.macro SetAvatarBits arg0
	.short 188
	.short \arg0
	.endm

	.macro UpdateAvatarState
	.short 189
	.endm

	; In the buffer_XXX commands, the maximum
	; acceptable value for the slot arg is 7.
	; This sets the message format placeholder
	; to whatever is buffered.
	.macro BufferPlayersName slot
	.short 190
	.byte \slot
	.endm

	; If you use this before naming your rival,
	; this will be an empty string.
	.macro BufferRivalsName slot
	.short 191
	.byte \slot
	.endm

	.macro BufferFriendsName slot
	.short 192
	.byte \slot
	.endm

	; For these commands, the additional argument
	; is a flex arg, meaning it can be a literal
	; or a variable.
	.macro BufferMonSpeciesName slot, party_pos
	.short 193
	.byte \slot
	.short \party_pos
	.endm

	.macro BufferItemName slot, item
	.short 194
	.byte \slot
	.short \item
	.endm

	.macro BufferPocketName slot, pocket
	.short 195
	.byte \slot
	.short \pocket
	.endm

	.macro BufferTMHMMoveName slot, tmhm
	.short 196
	.byte \slot
	.short \tmhm
	.endm

	.macro BufferMoveName slot, move
	.short 197
	.byte \slot
	.short \move
	.endm

	.macro BufferInt slot, value
	.short 198
	.byte \slot
	.short \value
	.endm

	.macro BufferPartyMonNick slot, party_pos
	.short 199
	.byte \slot
	.short \party_pos
	.endm

	.macro BufferTrainerClassName slot, trcls
	.short 200
	.byte \slot
	.short \trcls
	.endm

	.macro BufferPlayerUnionAvatarClassName slot
	.short 201
	.byte \slot
	.endm

	; The other two args here are unused
	.macro BufferSpeciesName slot, species, arg2, arg3
	.short 202
	.byte \slot
	.short \species
	.short \arg2
	.byte \arg3
	.endm

	.macro BufferStarterSpeciesName slot
	.short 203
	.byte \slot
	.endm

	; These two commands are leftover from Platinum.
	; As such, they are configured to check for the
	; Sinnoh starters instead of the Johto starters.
	; Since the player will never start with any of
	; Turtwig, Chimchar, or Piplup, this command
	; will always return TURTWIG, and the following
	; CHIMCHAR.
	; These commands are unused in HGSS.
	.macro BufferDPPtRivalStarterSpeciesName slot
	.short 204
	.byte \slot
	.endm

	.macro BufferDPPtFriendStarterSpeciesName slot
	.short 205
	.byte \slot
	.endm

	; Gets your starter species into the indicated
	; variable. Used to calculate which rival
	; party to use.
	.macro GetStarterChoice var
	.short 206
	.short \var
	.endm

	.macro BufferDecorationName slot, deco
	.short 207
	.byte \slot
	.short \deco
	.endm

	; Dummy
	.macro Dummy208 slot, unk
	.short 208
	.byte \slot
	.short \unk
	.endm

	; Dummy
	.macro Dummy209 slot, unk
	.short 209
	.byte \slot
	.short \unk
	.endm

	.macro BufferMapSecName slot, location
	.short 210
	.byte \slot
	.short \location
	.endm

	.macro GetSwarmMapAndSpecies var_map, var_species
	.short 211
	.short \var_map
	.short \var_species
	.endm

	; For when you talk to a trainer
	.macro GetTrainerNum arg0
	.short 212
	.short \arg0
	.endm

	.macro TrainerBattle trainer, arg1, arg2, arg3
	.short 213
	.short \trainer
	.short \arg1
	.byte \arg2
	.byte \arg3
	.endm

	.macro TrainerMessage trainer, param
	.short 214
	.short \trainer
	.short \param
	.endm

	.macro GetTrainerMsgParams intro, after, _1poke
	.short 215
	.short \intro
	.short \after
	.short \_1poke
	.endm

	.macro GetRematchMsgParams arg0, arg1, arg2
	.short 216
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro TrainerIsDoubleBattle arg0
	.short 217
	.short \arg0
	.endm

	.macro EncounterMusic arg0
	.short 218
	.short \arg0
	.endm

	.macro WhiteOut
	.short 219
	.endm

	; Is this loss?
	.macro CheckBattleWon var
	.short 220
	.short \var
	.endm

	.macro StaticWildWonOrCaughtCheck arg0, arg1
	.short 221
	.short \arg0
	.byte \arg1
	.endm

	.macro PartyCheckForDouble arg0
	.short 222
	.short \arg0
	.endm

	.macro TrainerBattleWithTrainer1
	.short 223
	.endm

	.macro SetLastInteractedTrainerFlag
	.short 224
	.endm

	.macro GoToIfTrainerDefeated arg0
	.short 225
	.word \arg0-.-4
	.endm

	.macro CommClubJoin type, arg1, arg2, var
	.short 226
	.short \type
	.short \arg1
	.short \arg2
	.short \var
	.endm

	.macro CommClubHost type, arg1, arg2, var
	.short 227
	.short \type
	.short \arg1
	.short \arg2
	.short \var
	.endm

	.macro Dummy228 unused
	.short 228
	.short \unused
	.endm

	.macro Dummy229 unused
	.short 229
	.short \unused
	.endm

	.macro LinkBattle
	.short 230
	.endm

	.macro Dummy231
	.short 231
	.endm

	.macro ConditionalLinkSyncStart sync_id
	.short 232
	.short \sync_id
	.endm

	.macro ConditionalLinkSyncWait sync_id
	.short 233
	.short \sync_id
	.endm

	.macro ConditionalLinkSyncCreate arg0, arg1, arg2, unused
	.short 234
	.short \arg0
	.short \arg1
	.short \arg2
	.short \unused
	.endm

	.macro ConditionalLinkSyncDestroy unused
	.short 235
	.short \unused
	.endm

	.macro SetVarZero var
	.short 236
	.short \var
	.endm

	.macro BeginTextAutoScroll
	.short 237
	.endm

	.macro PartyHasPokerus arg0
	.short 238
	.short \arg0
	.endm

	.macro MonGetGender arg0, arg1
	.short 239
	.short \arg0
	.short \arg1
	.endm

	.macro SetDynamicWarp arg0, arg1, arg2, arg3, arg4
	.short 240
	.short \arg0
	.short \arg1
	.short \arg2
	.short \arg3
	.short \arg4
	.endm

	.macro GetDynamicWarpFloorNo arg0
	.short 241
	.short \arg0
	.endm

	.macro ElevatorCurFloorBox arg0, arg1, arg2, arg3
	.short 242
	.byte \arg0
	.byte \arg1
	.short \arg2
	.short \arg3
	.endm

	.macro CountJohtoDexSeen var
	.short 243
	.short \var
	.endm

	.macro CountJohtoDexOwned var
	.short 244
	.short \var
	.endm

	.macro CountNationalDexSeen var
	.short 245
	.short \var
	.endm

	.macro CountNationalDexOwned var
	.short 246
	.short \var
	.endm

	; Dummy
	.macro Dummy247
	.short 247
	.endm

	; The actual Pokedex evaluation.
	; national: 0 = Johto dex, 1 = National dex
	; msg: Variable to return the message ID
	; fanfare: Variable to return the fanfare ID
	.macro GetDexEvalResult national, msg, fanfare
	.short 248
	.byte \national
	.short \msg
	.short \fanfare
	.endm

	.macro RocketTrapBattle arg0, arg1
	.short 249
	.short \arg0
	.short \arg1
	.endm

	.macro StartFirstBattle species, level
	.short 250
	.short \species
	.short \level
	.endm

	.macro CatchingTutorial
	.short 251
	.endm

	.macro OpenTrainerCardSignature
	.short 252
	.endm

	.macro GetSaveFileState arg0
	.short 253
	.short \arg0
	.endm

	.macro SaveGameNormal arg0
	.short 254
	.short \arg0
	.endm

	.macro FashionEntryIsSaved entry, var
	.short 255
	.short \entry
	.short \var
	.endm

	.macro FashionEntrySetMailWord word
	.short 256
	.short \word
	.endm

	.macro LinkSyncAndWait sync_id
	.short 257
	.short \sync_id
	.endm

	.macro LinkSyncClearPackets
	.short 258
	.endm

	.macro GetUnionRoomPartnerHometownMsg var
	.short 259
	.short \var
	.endm

	.macro GetUnionRoomOwnChatMsg var
	.short 260
	.short \var
	.endm

	.macro UnionRoomSetActivity activity
	.short 261
	.short \activity
	.endm

	.macro UnionRoomRefuseJoins
	.short 262
	.endm

	.macro UnionRoomResumeSearch
	.short 263
	.endm

	.macro BufferUnionRoomPartnerLanguage self
	.short 264
	.short \self
	.endm

	.macro FieldCommRegisterCommands
	.short 265
	.endm

	.macro UnionRoomRequestLeaveAll
	.short 266
	.endm

	.macro GetUnionRoomTalkMsg kind, var
	.short 267
	.short \kind
	.short \var
	.endm

	.macro GetUnionRoomPlayerActivity var
	.short 268
	.short \var
	.endm

	.macro UnionRoomWaitJoinStatus var
	.short 269
	.short \var
	.endm

	.macro UnionRoomRestoreObjects
	.short 270
	.endm

	.macro UnionRoomSendTalkResponse arg0, arg1
	.short 271
	.short \arg0
	.short \arg1
	.endm

	.macro UnionRoomWaitTalkChoice var
	.short 272
	.short \var
	.endm

	.macro UnionRoomWaitTalkReply var
	.short 273
	.short \var
	.endm

	.macro UnionRoomRequestJoinPlayer arg, var
	.short 274
	.short \arg
	.short \var
	.endm

	.macro MartBuy arg0
	.short 275
	.short \arg0
	.endm

	.macro SpecialMartBuy arg0
	.short 276
	.short \arg0
	.endm

	.macro DecorationMart arg0
	.short 277
	.short \arg0
	.endm

	.macro SealMart arg0
	.short 278
	.short \arg0
	.endm

	; Used with poison faint, but due to overworld
	; poison mechanics in gen 4, this is
	; never reached.
	.macro OverworldWhiteOut
	.short 279
	.endm

	.macro SetSpawn arg0
	.short 280
	.short \arg0
	.endm

	; Are you a boy? Or are you a girl?
	.macro GetPlayerGender var
	.short 281
	.short \var
	.endm

	.macro HealParty
	.short 282
	.endm

	.macro CommClubExit
	.short 283
	.endm

	.macro CommClubStartCardExchange
	.short 284
	.endm

	.macro SetCommPlayerFacing dir
	.short 285
	.short \dir
	.endm

	.macro EnterUnionRoom
	.short 286
	.endm

	.macro BufferUnionRoomAvatarChoices
	.short 287
	.endm

	.macro UnionRoomAvatarIdxToTrainerClass arg0, arg1
	.short 288
	.short \arg0
	.short \arg1
	.endm

	.macro SetPlayerProfileAvatar avatar
	.short 289
	.short \avatar
	.endm

	.macro CheckPokedex arg0
	.short 290
	.short \arg0
	.endm

	.macro GivePokedex
	.short 291
	.endm

	.macro CheckRunningShoes arg0
	.short 292
	.short \arg0
	.endm

	.macro GiveRunningShoes
	.short 293
	.endm

	.macro CheckBadge badge, var
	.short 294
	.short \badge
	.short \var
	.endm

	.macro GiveBadge badge
	.short 295
	.short \badge
	.endm

	; This command is never used because it is
	; assumed that you cannot get the 8th badge
	; before the other 7, or the 16th before the
	; other 15. This assumption does not account
	; for tweaking.
	.macro CountBadges var
	.short 296
	.short \var
	.endm

	.macro CheckFlagUnk960 var
	.short 297
	.short \var
	.endm

	.macro SetFlagUnk960
	.short 298
	.endm

	.macro CheckEscortMode arg0
	.short 299
	.short \arg0
	.endm

	.macro SetEscortMode
	.short 300
	.endm

	.macro ClearEscortMode
	.short 301
	.endm

	.macro CheckStepTakenFlag arg0
	.short 302
	.short \arg0
	.endm

	.macro SetStepTakenFlag
	.short 303
	.endm

	.macro GetStepTakenFlag
	.short 304
	.endm

	.macro CheckGameClearFlag arg0
	.short 305
	.short \arg0
	.endm

	.macro SetGameClearFlag
	.short 306
	.endm

	.macro DoorAnimationLoad block_x, block_y, x, y, id
	.short 307
	.short \block_x
	.short \block_y
	.short \x
	.short \y
	.byte \id
	.endm

	.macro DoorAnimationWait id
	.short 308
	.byte \id
	.endm

	.macro DoorAnimationUnload id
	.short 309
	.byte \id
	.endm

	.macro DoorAnimationOpen id
	.short 310
	.byte \id
	.endm

	.macro DoorAnimationClose id
	.short 311
	.byte \id
	.endm

	.macro BufferDaycareMonNicks
	.short 312
	.endm

	.macro GetDaycareState arg0
	.short 313
	.short \arg0
	.endm

	.macro EcruteakGymInit
	.short 314
	.endm

	.macro EcruteakGymBindCandleToTrainer
	.short 315
	.endm

	.macro EcruteakGymUnbindCandleFromTrainer
	.short 316
	.endm

	.macro EcruteakGymExtinguishCandle last_interacted
	.short 317
	.byte \last_interacted
	.endm

	.macro CianwoodGymInit
	.short 318
	.endm

	.macro CianwoodGymTurnWinch arg0
	.short 319
	.short \arg0
	.endm

	.macro VermilionGymInit
	.short 320
	.endm

	.macro VermilionGymLockAction arg0, arg1
	.short 321
	.byte \arg0
	.byte \arg1
	.endm

	.macro VermilionGymCanCheck arg0, arg1
	.short 322
	.byte \arg0
	.short \arg1
	.endm

	.macro ResampleVermilionGymCans
	.short 323
	.endm

	.macro VioletGymInit
	.short 324
	.endm

	.macro VioletGymElevator
	.short 325
	.endm

	.macro AzaleaGymInit
	.short 326
	.endm

	.macro AzaleaGymSpinarak arg0
	.short 327
	.byte \arg0
	.endm

	.macro AzaleaGymSwitch arg0
	.short 328
	.byte \arg0
	.endm

	.macro BlackthornGymInit
	.short 329
	.endm

	.macro FuchsiaGymInit
	.short 330
	.endm

	.macro ViridianGymInit
	.short 331
	.endm

	.macro GetPartyCount var
	.short 332
	.short \var
	.endm

	.macro BagSelectItem berries
	.short 333
	.byte \berries
	.endm

	.macro BagGetSelectedItem var
	.short 334
	.short \var
	.endm

	.macro BagPocketHasItems pocket, var
	.short 335
	.short \pocket
	.short \var
	.endm

	.macro BufferBerryName slot, item, quantity
	.short 336
	.byte \slot
	.short \item
	.short \quantity
	.endm

	.macro BufferNatureName slot, nature
	.short 337
	.byte \slot
	.short \nature
	.endm

	.macro MovePerson arg0, arg1, arg2
	.short 338
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro MovePersonFacing person, x, z, y, facing
	.short 339
	.short \person
	.short \x
	.short \z
	.short \y
	.short \facing
	.endm

	.macro SetObjectMovementType arg0, arg1
	.short 340
	.short \arg0
	.short \arg1
	.endm

	.macro SetObjectFacing arg0, arg1
	.short 341
	.short \arg0
	.short \arg1
	.endm

	.macro MoveWarp arg0, arg1, arg2
	.short 342
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro MoveBGEvent arg0, arg1, arg2
	.short 343
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro SetObjectFacingAndUpdateDraw object, dir
	.short 344
	.short \object
	.short \dir
	.endm

	.macro AddWaitingIcon
	.short 345
	.endm

	.macro RemoveWaitingIcon
	.short 346
	.endm

	.macro WriteScriptEnvField34 value
	.short 347
	.short \value
	.endm

	.macro WaitButtonOrDelay arg0
	.short 348
	.short \arg0
	.endm

	.macro PartySelectUI
	.short 349
	.endm

	.macro UnionRoomBattlePartySelect
	.short 350
	.endm

	.macro GetPartySelection arg0
	.short 351
	.short \arg0
	.endm

	.macro PokemonSummaryScreen arg0, arg1, arg2
	.short 352
	.byte \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro GetMoveSelection arg0, arg1
	.short 353
	.byte \arg0
	.short \arg1
	.endm

	.macro GetPartyMonSpecies slot, var
	.short 354
	.short \slot
	.short \var
	.endm

	.macro PartyMonIsMine slot, var
	.short 355
	.short \slot
	.short \var
	.endm

	.macro PartyCountNotEgg var
	.short 356
	.short \var
	.endm

	; Count Pokemon that are not fainted.
	; If except is set, exclude that slot
	; from the tally. Use 6 to disable.
	.macro CountAliveMons var, except=PARTY_SIZE
	.short 357
	.short \var
	.short \except
	.endm

	.macro CountAliveMonsAndPC arg0
	.short 358
	.short \arg0
	.endm

	.macro PartyCountEgg arg0
	.short 359
	.short \arg0
	.endm

	.macro SubMoneyVar var
	.short 360
	.short \var
	.endm

	.macro RetrieveDaycareMon arg0, arg1
	.short 361
	.short \arg0
	.short \arg1
	.endm

	.macro GiveLoanMon arg0, arg1, arg2
	.short 362
	.byte \arg0
	.byte \arg1
	.short \arg2
	.endm

	.macro CheckReturnLoanMon arg0, arg1, arg2
	.short 363
	.byte \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro ReturnLoanMon arg0
	.short 364
	.short \arg0
	.endm

	.macro ResetDaycareEgg
	.short 365
	.endm

	.macro GiveDaycareEgg
	.short 366
	.endm

	.macro BufferDaycareWithdrawCost arg0, arg1
	.short 367
	.short \arg0
	.short \arg1
	.endm

	.macro HasEnoughMoneyVar var, amount
	.short 368
	.short \var
	.short \amount
	.endm

	.macro EggHatchAnim
	.short 369
	.endm

	.macro BagSelectItemNoResult berries
	.short 370
	.byte \berries
	.endm

	.macro BufferDaycareMonGrowth arg0, arg1
	.short 371
	.short \arg0
	.short \arg1
	.endm

	.macro GetTailDaycareMonSpeciesAndNick arg0
	.short 372
	.short \arg0
	.endm

	.macro PutMonInDaycare arg0
	.short 373
	.short \arg0
	.endm

	.macro MakeObjectVisible object
	.short 374
	.short \object
	.endm

	.macro MakeObjectInvisible object
	.short 375
	.short \object
	.endm

	.macro OpenMailbox
	.short 376
	.endm

	.macro CountMailboxMessages var
	.short 377
	.short \var
	.endm

	.macro ViewRankings scope, page, record
	.short 378
	.short \scope * 3 + \page
	.short \record
	.endm

	.macro GetCurrentTimeOfDay var
	.short 379
	.short \var
	.endm

	.macro Random arg0, arg1
	.short 380
	.short \arg0
	.short \arg1
	.endm

	.macro Random2 var, modulo
	.short 381
	.short \var
	.short \modulo
	.endm

	.macro MonGetFriendship arg0, arg1
	.short 382
	.short \arg0
	.short \arg1
	.endm

	.macro MonAddFriendship arg0, arg1
	.short 383
	.short \arg0
	.short \arg1
	.endm

	.macro MonSubtractFriendship arg0, arg1
	.short 384
	.short \arg0
	.short \arg1
	.endm

	.macro BufferDaycareMonStats arg0, arg1, arg2, arg3
	.short 385
	.short \arg0
	.short \arg1
	.short \arg2
	.short \arg3
	.endm

	.macro GetPlayerFacing arg0
	.short 386
	.short \arg0
	.endm

	.macro GetDaycareCompatibility arg0
	.short 387
	.short \arg0
	.endm

	.macro CheckDaycareEgg arg0
	.short 388
	.short \arg0
	.endm

	.macro PlayerHasSpecies arg0, arg1
	.short 389
	.short \arg0
	.short \arg1
	.endm

	.macro SizeRecordCompare arg0, arg1
	.short 390
	.short \arg0
	.short \arg1
	.endm

	.macro SizeRecordUpdate arg0
	.short 391
	.short \arg0
	.endm

	.macro BufferMonSize arg0, arg1, arg2
	.short 392
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro BufferRecordSize arg0, arg1, arg2
	.short 393
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro OpenLearnForgetMove slot
	.short 394
	.short \slot
	.endm

	.macro GetLearnForgetMoveResult var
	.short 395
	.short \var
	.endm

	.macro CountMonMoves arg0, arg1
	.short 396
	.short \arg0
	.short \arg1
	.endm

	.macro MonForgetMove arg0, arg1
	.short 397
	.short \arg0
	.short \arg1
	.endm

	.macro MonGetMove arg0, arg1, arg2
	.short 398
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro BufferPartyMonMoveName slot, party_pos, move_pos
	.short 399
	.byte \slot
	.short \party_pos
	.short \move_pos
	.endm

	; action = 0: Deactivate strength
	; action = 1: Activate strength
	; action = 2: Check whether strength is active
	.macro StrengthFlagAction action, var=0
	.short 400
	.byte \action
	.if \action == 2
	.short \var
	.endif
	.endm

	.macro FlashAction action, var=0
	.short 401
	.byte \action
	.if \action == 2
	.short \var
	.endif
	.endm

	.macro DefogAction action, var=0
	.short 402
	.byte \action
	.if \action == 2
	.short \var
	.endif
	.endm

	.macro GiveAccessory accessory, count
	.short 403
	.short \accessory
	.short \count
	.endm

	.macro CanGiveAccessory accessory, count, var
	.short 404
	.short \accessory
	.short \count
	.short \var
	.endm

	.macro HasAccessoryCount accessory, count, var
	.short 405
	.short \accessory
	.short \count
	.short \var
	.endm

	.macro GiveContestBackground background
	.short 406
	.short \background
	.endm

	.macro HasWallpaper wallpaper, var
	.short 407
	.short \wallpaper
	.short \var
	.endm

	.macro OpenBattleRoomResults arg0, arg1
	.short 408
	.short \arg0
	.short \arg1
	.endm

	.macro FrontierAssertCleared
	.short 409
	.endm

	.macro FrontierFieldSystemInit resume, mode
	.short 410
	.short \resume
	.short \mode
	.endm

	.macro FrontierFieldSystemFree
	.short 411
	.endm

	.macro BattleTowerAction action, arg, var
	.short 412
	.short \action
	.short \arg
	.short \var
	.endm

	.macro BattleTowerGetAllyMonSpeciesAndMove ally, mon, var_species, var_move
	.short 413
	.short \ally
	.short \mon
	.short \var_species
	.short \var_move
	.endm

	.macro BattleTowerClaimRecordMilestone var
	.short 414
	.short \var
	.endm

	.macro BattleTowerGetRecordMilestone var
	.short 415
	.short \var
	.endm

	.macro BattleTowerSendLinkData kind, arg, var
	.short 416
	.short \kind
	.short \arg
	.short \var
	.endm

	.macro BattleTowerCheckLinkPartner arg, var
	.short 417
	.short \arg
	.short \var
	.endm

	.macro GetBattleRoomLeadersRoom var_a, var_b
	.short 418
	.short \var_a
	.short \var_b
	.endm

	.macro BattleRoomHasLeaders var
	.short 419
	.short \var
	.endm

	.macro IncGameStat stat
	.short 420
	.short \stat
	.endm

	.macro GetGameStatHiLo stat, var_hi, var_lo
	.short 421
	.short \stat
	.short \var_hi
	.short \var_lo
	.endm

	.macro ModifyGameStat stat, value_hi, value_lo, action
	.short 422
	.short \stat
	.short \value_hi
	.short \value_lo
	.byte \action
	.endm

	.macro CheckJohtoDexComplete arg0
	.short 423
	.short \arg0
	.endm

	.macro CheckNationalDexComplete arg0
	.short 424
	.short \arg0
	.endm

	.macro ShowCertificate arg0
	.short 425
	.short \arg0
	.endm

	.macro KenyaCheck arg0, arg1, arg2
	.short 426
	.short \arg0
	.short \arg1
	.byte \arg2
	.endm

	.macro Dummy427 var
	.short 427
	.short \var
	.endm

	.macro MonGiveMail arg0
	.short 428
	.short \arg0
	.endm

	.macro CountFossils arg0
	.short 429
	.short \arg0
	.endm

	.macro SetPhoneCall arg0, arg1, arg2
	.short 430
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro RunPhoneCall
	.short 431
	.endm

	.macro GetFossilPokemon arg0, arg1
	.short 432
	.short \arg0
	.short \arg1
	.endm

	.macro GetFossilMinimumAmount arg0, arg1, arg2
	.short 433
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro PartyCountMonsAtOrBelowLevel arg0, arg1
	.short 434
	.short \arg0
	.short \arg1
	.endm

	.macro SurvivePoisoning arg0, arg1
	.short 435
	.short \arg0
	.short \arg1
	.endm

	.macro LeaveOverworld
	.short 436
	.endm

	.macro DebugWatch arg0
	.short 437
	.short \arg0
	.endm

	.macro GetStdMsgNaix arg0, arg1
	.short 438
	.short \arg0
	.short \arg1
	.endm

	.macro NonNPCMsgExtern arg0, arg1
	.short 439
	.short \arg0
	.short \arg1
	.endm

	.macro MsgBoxExtern arg0, arg1
	.short 440
	.short \arg0
	.short \arg1
	.endm

	.macro NonNPCMsgEasyChat bank, msg, word1, word2
	.short 441
	.short \bank
	.short \msg
	.short \word1
	.short \word2
	.endm

	.macro MsgBoxEasyChat bank, msg, word1, word2
	.short 442
	.short \bank
	.short \msg
	.short \word1
	.short \word2
	.endm

	.macro MsgBoxFrontierOpponentIntro opponent
	.short 443
	.byte \opponent
	.endm

	.macro MsgBoxFrontierBannedSpecies msg, count, arg2, arg3
	.short 444
	.byte \msg
	.short \count
	.short \arg2
	.byte \arg3
	.endm

	.macro GetPreviousMapId var
	.short 445
	.short \var
	.endm

	.macro GetCurrentMapId var
	.short 446
	.short \var
	.endm

	.macro SafariZoneAction arg0, arg1
	.short 447
	.byte \arg0
	.byte \arg1
	.endm

	.macro WarpToColosseum map, unused, x, y, dir
	.short 448
	.short \map
	.short \unused
	.short \x
	.short \y
	.short \dir
	.endm

	.macro ReturnFromColosseum
	.short 449
	.endm

	.macro OpenGeonetGlobe
	.short 450
	.endm

	.macro GetLocalNetId var
	.short 451
	.short \var
	.endm

	.macro ShowPokemonPicWindow species, gender
	.short 452
	.short \species
	.short \gender
	.endm

	.macro ClosePokemonPicWindow
	.short 453
	.endm

	.macro SetLastTalkedTrainerMovement
	.short 454
	.endm

	.macro NPCMsgByObjectType
	.short 455
	.endm

	.macro TogglePlayerAutoHeightUpdate enabled
	.short 456
	.byte \enabled
	.endm

	.macro MonGetNature arg0, arg1
	.short 457
	.short \arg0
	.short \arg1
	.endm

	.macro GetPartySlotWithNature arg0, arg1
	.short 458
	.short \arg0
	.short \arg1
	.endm

	.macro LighthouseLightUp
	.short 459
	.endm

	.macro LoadPhoneDat arg0, arg1
	.short 460
	.short \arg0
	.short \arg1
	.endm

	.macro GetPhoneContactMsgIds arg0, arg1, arg2
	.short 461
	.byte \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro ClearPhoneRematchSeeking contact
	.short 462
	.short \contact
	.endm

	.macro EnableMassOutbreaks
	.short 463
	.endm

	.macro CreateRoamer arg0
	.short 464
	.byte \arg0
	.endm

	.macro FriendGroupAction action, arg1=0, arg2=0
	.short 465
	.short \action
	.if \action <= 3
		.short \arg1
		.short \arg2
	.else
		.if \action != 6
			.short \arg1
		.endif
	.endif
	.endm

	.macro MonHasRelearnableMoves var, slot
	.short 466
	.short \var
	.short \slot
	.endm

	.macro MoveRelearnerInit arg0
	.short 467
	.short \arg0
	.endm

	.macro MoveTutorInit arg0, arg1
	.short 468
	.short \arg0
	.short \arg1
	.endm

	.macro MoveRelearnerGetResult arg0
	.short 469
	.short \arg0
	.endm

	.macro LoadNPCTrade arg0
	.short 470
	.byte \arg0
	.endm

	.macro GetOfferedSpecies arg0
	.short 471
	.short \arg0
	.endm

	.macro NPCTradeGetReqSpecies arg0
	.short 472
	.short \arg0
	.endm

	.macro NPCTradeExec arg0
	.short 473
	.short \arg0
	.endm

	.macro NPCTradeEnd
	.short 474
	.endm

	.macro Dummy475
	.short 475
	.endm

	.macro EnablePokedexFormDetection
	.short 476
	.endm

	.macro NatDexFlagAction arg0, arg1
	.short 477
	.byte \arg0
	.short \arg1
	.endm

	.macro MonGetRibbonCount arg0, arg1
	.short 478
	.short \arg0
	.short \arg1
	.endm

	.macro GetPartyRibbonCount arg0
	.short 479
	.short \arg0
	.endm

	.macro MonHasRibbon arg0, arg1, arg2
	.short 480
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro GiveRibbon arg0, arg1
	.short 481
	.short \arg0
	.short \arg1
	.endm

	.macro BufferRibbonName arg0, arg1
	.short 482
	.byte \arg0
	.short \arg1
	.endm

	.macro GetEVTotal arg0, arg1
	.short 483
	.short \arg0
	.short \arg1
	.endm

	.macro GetWeekday arg0
	.short 484
	.short \arg0
	.endm

	.macro StartBattleRegulationMenuTask arg0
	.short 485
	.short \arg0
	.endm

	.macro Dummy486
	.short 486
	.endm

	.macro PokeCenAnim arg0
	.short 487
	.short \arg0
	.endm

	.macro ElevatorAnim direction, distance
	.short 488
	.short \direction
	.short \distance
	.endm

	.macro MysteryGift arg0, arg1=0, arg2=0
	.short 489
	.short \arg0
	.if \arg0 >= 1 && \arg0 <= 3
	.short \arg1
	.else
	.if \arg0 == 5 || \arg0 == 6
	.short \arg1
	.short \arg2
	.endif
	.endif
	.endm

	.macro NopVar490 arg0
	.short 490
	.short \arg0
	.endm

	.macro Dummy491 var
	.short 491
	.short \var
	.endm

	.macro PromptEasyChatOneWord kind, var_result, var_word
	.short 492
	.short \kind
	.short \var_result
	.short \var_word
	.endm

	.macro PromptEasyChat arg0, arg1, arg2
	.short 493
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro BufferEasyChatWord slot, word
	.short 494
	.short \slot
	.short \word
	.endm

	.macro GetGameVersion arg0
	.short 495
	.short \arg0
	.endm

	.macro GetPartyLead arg0
	.short 496
	.short \arg0
	.endm

	.macro GetMonTypes arg0, arg1, arg2
	.short 497
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro PrimoPasswordCheck1 arg0, arg1, arg2, arg3, arg4
	.short 498
	.short \arg0
	.short \arg1
	.short \arg2
	.short \arg3
	.short \arg4
	.endm

	.macro PrimoPasswordCheck2 arg0, arg1, arg2, arg3, arg4
	.short 499
	.short \arg0
	.short \arg1
	.short \arg2
	.short \arg3
	.short \arg4
	.endm

	.macro PCPropLoadAnimation id
	.short 500
	.byte \id
	.endm

	.macro PCPropPowerOn id
	.short 501
	.byte \id
	.endm

	.macro PCPropPowerOff id
	.short 502
	.byte \id
	.endm

	.macro LotoIDGet arg0
	.short 503
	.short \arg0
	.endm

	.macro LotoIDSearch arg0, arg1, arg2, arg3
	.short 504
	.short \arg0
	.short \arg1
	.short \arg2
	.short \arg3
	.endm

	.macro LotoIDSet
	.short 505
	.endm

	.macro BufferBoxMonNick arg0, arg1
	.short 506
	.byte \arg0
	.short \arg1
	.endm

	.macro CountPCEmptySpace arg0
	.short 507
	.short \arg0
	.endm

	.macro PalParkAction arg0
	.short 508
	.short \arg0
	.endm

	.macro MigratedPokemonIsFull var
	.short 509
	.short \var
	.endm

	.macro MoveMigratedPokemonToPC
	.short 510
	.endm

	.macro PalParkScoreGet arg0, arg1
	.short 511
	.short \arg0
	.short \arg1
	.endm

	.macro PlayerMovementSavingSet
	.short 512
	.endm

	.macro PlayerMovementSavingClear
	.short 513
	.endm

	; Animate placing the balls on the machine
	; for the Hall of Fame
	.macro HallOfFameAnim num
	.short 514
	.short \num
	.endm

	.macro AddSpecialGameStat arg0
	.short 515
	.short \arg0
	.endm

	.macro BufferFashionName arg0, arg1
	.short 516
	.byte \arg0
	.short \arg1
	.endm

	.macro PartyHasSpecies species, var
	.short 517
	.short \species
	.short \var
	.endm

	.macro SetPartyDeoxysForm form
	.short 518
	.short \form
	.endm

	.macro CountPartyBurmyForms var
	.short 519
	.short \var
	.endm

	.macro SetFlagUnk975
	.short 520
	.endm

	.macro ClearFlagUnk975
	.short 521
	.endm

	.macro GetCurrentHour var
	.short 522
	.short \var
	.endm

	.macro SpinObject object, arg1, arg2, arg3, arg4
	.short 523
	.short \object
	.short \arg1
	.short \arg2
	.short \arg3
	.short \arg4
	.endm

	.macro BlinkObject object, arg1, arg2
	.short 524
	.short \object
	.short \arg1
	.short \arg2
	.endm

	.macro HasAllRegisInParty var
	.short 525
	.short \var
	.endm

	.macro GetRandomGivableAccessory var
	.short 526
	.short \var
	.endm

	.macro MsgFont3 msg_id
	.short 527
	.short \msg_id
	.endm

	.macro GetAgbCartridgeVersion dest_var
	.short 528
	.short \dest_var
	.endm

	.macro GetPartyLeadAlive arg0
	.short 529
	.short \arg0
	.endm

	.macro MapEventKeyAction key, enable
	.short 530
	.short \key
	.byte \enable
	.endm

	.macro BufferBackgroundName arg0, arg1
	.short 531
	.byte \arg0
	.short \arg1
	.endm

	.macro CheckCoinsImmediate arg0, arg1
	.short 532
	.short \arg0
	.word \arg1
	.endm

	.macro CheckGiveCoins arg0, arg1
	.short 533
	.short \arg0
	.short \arg1
	.endm

	.macro GetVar4041 dest_var
	.short 534
	.short \dest_var
	.endm

	.macro MonGetLevel arg0, arg1
	.short 535
	.short \arg0
	.short \arg1
	.endm

	.macro TakeFashionAccessory accessory, quantity
	.short 536
	.short \accessory
	.short \quantity
	.endm

	.macro RandomizeVar4041
	.short 537
	.endm

	.macro UnlockRandomTrendySaying dest_var, buffer_idx
	.short 538
	.short \dest_var
	.short \buffer_idx
	.endm

	.macro CheckVar4042AtLeast5 dest_var
	.short 539
	.short \dest_var
	.endm

	.macro CheckAllTrendySayingsUnlocked dest_var
	.short 540
	.short \dest_var
	.endm

	.macro BufferIntEx arg0, arg1, arg2, arg3
	.short 541
	.byte \arg0
	.short \arg1
	.byte \arg2
	.byte \arg3
	.endm

	.macro MonGetContestValue arg0, arg1, arg2
	.short 542
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro CheckIsPlayerBirthday dest_var
	.short 543
	.short \dest_var
	.endm

	.macro SetSeqVolume seq, volume
	.short 544
	.short \seq
	.short \volume
	.endm

	.macro CountUnownLettersRegistered dest_var
	.short 545
	.short \dest_var
	.endm

	.macro CheckEventKey key, dest_var
	.short 546
	.byte \key
	.short \dest_var
	.endm

	.macro ShowPartyMonPic party_slot
	.short 547
	.short \party_slot
	.endm

	.macro AnimateMonPic
	.short 548
	.endm

	.macro WaitMonPicAnim var
	.short 549
	.short \var
	.endm

	.macro GetHallOfFameEntryCount dest_var
	.short 550
	.short \dest_var
	.endm

	.macro ChoosePartyMonForDayCare var
	.short 551
	.short \var
	.endm

	.macro GetDayCarePartySelection slot_var, action_var
	.short 552
	.short \slot_var
	.short \action_var
	.endm

	.macro RandomChance percent, dest_var
	.short 553
	.byte \percent
	.short \dest_var
	.endm

	.macro GetBattlePoints dest_var
	.short 554
	.short \dest_var
	.endm

	.macro GiveBattlePoints amount
	.short 555
	.short \amount
	.endm

	.macro TakeBattlePoints amount
	.short 556
	.short \amount
	.endm

	.macro CheckBattlePoints arg0, arg1
	.short 557
	.short \arg0
	.short \arg1
	.endm

	.macro UnionRoomAvatarIdxToSprite arg0, arg1
	.short 558
	.short \arg0
	.short \arg1
	.endm

	.macro MultichoiceAddItemVar msg_id, value
	.short 559
	.short \msg_id
	.short \value
	.endm

	.macro StartFieldMoveEffect kind, done_var
	.short 560
	.short \kind
	.short \done_var
	.endm

	.macro ScreenShake arg0, arg1, arg2, arg3
	.short 561
	.short \arg0
	.short \arg1
	.short \arg2
	.short \arg3
	.endm

	.macro MultiBattle arg0, arg1, arg2, arg3
	.short 562
	.short \arg0
	.short \arg1
	.short \arg2
	.byte \arg3
	.endm

	.macro WalkPersonToCoords person, x, z
	.short 563
	.short \person
	.short \x
	.short \z
	.endm

	.macro CheckHasWifiProfile dest_var
	.short 564
	.short \dest_var
	.endm

	.macro CountWifiFriends dest_var
	.short 565
	.short \dest_var
	.endm

	.macro ChoosePartyMonForTrade
	.short 566
	.endm

	.macro GetDPPlPrizeItemIDAndCost arg0, arg1, arg2
	.short 567
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro ItemIsPlate item, dest_var
	.short 568
	.short \item
	.short \dest_var
	.endm

	.macro TakeCoinsVar var
	.short 569
	.short \var
	.endm

	.macro CheckCoinsVar arg0, arg1
	.short 570
	.short \arg0
	.short \arg1
	.endm

	.macro CheckEasyChatWordsMatchFixedPhrase dest_var, word0, word1, word2, word3
	.short 571
	.short \dest_var
	.short \word0
	.short \word1
	.short \word2
	.short \word3
	.endm

	.macro GetUniqueSealsQuantity arg0
	.short 572
	.short \arg0
	.endm

	.macro SetMysteryGiftActive
	.short 573
	.endm

	.macro GetObjectMovementType dest_var, object_id
	.short 574
	.short \dest_var
	.short \object_id
	.endm

	.macro CountPlayingSeq seq, dest_var
	.short 575
	.short \seq
	.short \dest_var
	.endm

	.macro GetUnionRoomPartnerHometownMsg2 dest_var
	.short 576
	.short \dest_var
	.endm

	.macro CreateWirelessStatusIcon
	.short 577
	.endm

	.macro DestroyWirelessStatusIcon
	.short 578
	.endm

	.macro SyncMapObjectsToSave
	.short 579
	.endm

	.macro BufferSealName arg0, arg1
	.short 580
	.byte \arg0
	.short \arg1
	.endm

	.macro LockLastTalked
	.short 581
	.endm

	.macro SetSpecialSpawnWarp map, x, y
	.short 582
	.short \map
	.short \x
	.short \y
	.endm

	.macro ClearObjectFlag18 object_id, clear
	.short 583
	.short \object_id
	.byte \clear
	.endm

	.macro PartyLegalCheck arg0
	.short 584
	.short \arg0
	.endm

	.macro MultichoiceShowUnionRoom
	.short 585
	.endm

	.macro GetUnionRoomBattleCancel dest_var
	.short 586
	.short \dest_var
	.endm

	.macro CommClubLinkExit
	.short 587
	.endm

	.macro LatiCaughtCheck arg0
	.short 588
	.short \arg0
	.endm

	.macro WildBattle species, level, shiny=0
	.short 589
	.short \species
	.short \level
	.byte \shiny
	.endm

	.macro GetTrcardStars arg0
	.short 590
	.short \arg0
	.endm

	.macro SetBicycleBGMOverride
	.short 591
	.endm

	.macro NonNPCMsgVarAutoScroll msg
	.short 592
	.short \msg
	.endm

	.macro ShowSaveStats
	.short 593
	.endm

	.macro HideSaveStats
	.short 594
	.endm

	.macro SetWarpResetSuppressed value
	.short 595
	.byte \value
	.endm

	.macro FollowMonIsLarge dest_var
	.short 596
	.short \dest_var
	.endm

	.macro FollowMonShowEmoteBubble
	.short 597
	.endm

	.macro SwapPlayerAndFollowMonPositions mode
	.short 598
	.short \mode
	.endm

	.macro FollowMonHopIntoBall
	.short 599
	.endm

	.macro FollowMonRecall
	.short 600
	.endm

	.macro FollowMonFacePlayer
	.short 601
	.endm

	.macro ToggleFollowingPokemonMovement flag
	.short 602
	.short \flag
	.endm

	.macro WaitFollowingPokemonMovement
	.short 603
	.endm

	.macro FollowingPokemonMovement movement
	.short 604
	.short \movement
	.endm

	.macro FollowMonSetPositionNextToPlayer direction, facing
	.short 605
	.byte \direction
	.byte \facing
	.endm

	.macro FollowMonReleaseNextToPlayer
	.short 606
	.endm

	.macro FollowMonMoveToPlayer
	.short 607
	.endm

	.macro FollowMonSpawnReleaseBall
	.short 608
	.endm

	.macro FollowMonResetMovement
	.short 609
	.endm

	.macro StartCameraShift mode
	.short 610
	.short \mode
	.endm

	.macro Pokeathlon arg0, arg1, arg2, arg3, arg4, arg5, arg6
	.short 611
	.byte \arg0
	.byte \arg1
	.short \arg2
	.short \arg3
	.short \arg4
	.short \arg5
	.short \arg6
	.endm

	.macro GetNPCTradeUnusedFlag arg0
	.short 612
	.short \arg0
	.endm

	.macro GetPhoneContactRandomGiftBerry arg0
	.short 613
	.short \arg0
	.endm

	.macro GetPhoneContactGiftItem arg0
	.short 614
	.short \arg0
	.endm

	.macro CameronPhoto arg0
	.short 615
	.short \arg0
	.endm

	.macro CountSavedPhotos arg0
	.short 616
	.short \arg0
	.endm

	.macro OpenPhotoAlbum
	.short 617
	.endm

	.macro PhotoAlbumIsFull arg0
	.short 618
	.short \arg0
	.endm

	.macro RocketCostumeFlagCheck arg0
	.short 619
	.short \arg0
	.endm

	.macro RocketCostumeFlagAction arg0
	.short 620
	.byte \arg0
	.endm

	.macro PlaceStarterBallsInElmsLab
	.short 621
	.endm

	.macro GetObjectFacing object_id, dest_var
	.short 622
	.short \object_id
	.short \dest_var
	.endm

	.macro AnimApricornTree arg0
	.short 623
	.short \arg0
	.endm

	.macro ApricornTreeGetApricorn arg0
	.short 624
	.short \arg0
	.endm

	.macro GiveApricornFromTree arg0, arg1, arg2
	.short 625
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro BufferApricornName arg0, arg1
	.short 626
	.byte \arg0
	.short \arg1
	.endm

	.macro LaunchFrontier frontier_map_id
	.short 627
	.byte \frontier_map_id
	.endm

	.macro BattleFactoryResetStreak type, level_mode
	.short 628
	.short \type
	.short \level_mode
	.endm

	.macro RunSpinTradeFlow
	.short 629
	.endm

	.macro CheckUnionRoomPartnerVersionNotDummy dest_var
	.short 630
	.short \dest_var
	.endm

	.macro OpenFrontierRecords mode, facility, species
	.short 631
	.short \mode
	.short \facility
	.short \species
	.endm

	.macro CountPartyMonsOfSpecies arg0, arg1
	.short 632
	.short \arg0
	.short \arg1
	.endm

	.macro BattleHallAction cmd, arg, dest_var
	.short 633
	.short \cmd
	.short \arg
	.short \dest_var
	.endm

	.macro BattleHallCheckSpecies species, dest_var
	.short 634
	.short \species
	.short \dest_var
	.endm

	.macro BattleHallGetPartySelection slot0, slot1
	.short 635
	.short \slot0
	.short \slot1
	.endm

	.macro BattleHallResetStreak type
	.short 636
	.short \type
	.endm

	.macro BattleCastleAction cmd, arg, dest_var
	.short 637
	.short \cmd
	.short \arg
	.short \dest_var
	.endm

	.macro BattleCastleCheckTeam mon0, mon1, dest_var
	.short 638
	.short \mon0
	.short \mon1
	.short \dest_var
	.endm

	.macro BattleCastleGetPartySelection slot0, slot1, slot2
	.short 639
	.short \slot0
	.short \slot1
	.short \slot2
	.endm

	.macro BattleCastleResetStreak type
	.short 640
	.short \type
	.endm

	.macro SaveWipeExtraChunks
	.short 641
	.endm

	.macro CheckExtraSaveChunksExist dest_var
	.short 642
	.short \dest_var
	.endm

	.macro BattleArcadeAction cmd, arg, dest_var
	.short 643
	.short \cmd
	.short \arg
	.short \dest_var
	.endm

	.macro BattleArcadeCheckTeam mon0, mon1, dest_var
	.short 644
	.short \mon0
	.short \mon1
	.short \dest_var
	.endm

	.macro BattleArcadeGetPartySelection slot0, slot1, slot2
	.short 645
	.short \slot0
	.short \slot1
	.short \slot2
	.endm

	.macro BattleArcadeResetStreak type
	.short 646
	.short \type
	.endm

	.macro GetPartySlotWithSpecies arg0, arg1
	.short 647
	.short \arg0
	.short \arg1
	.endm

	.macro BattleHallRecordSpeciesListMenu type, dex_list, result_var, cursor_var, scroll_var
	.short 648
	.short \type
	.short \dex_list
	.short \result_var
	.short \cursor_var
	.short \scroll_var
	.endm

	.macro ScratchOffCard
	.short 649
	.endm

	.macro ScratchOffCardEnd
	.short 650
	.endm

	.macro GetScratchOffPrize arg0, arg1, arg2
	.short 651
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro GetTutorMoveListPageCount party_slot, tutor, dest_var
	.short 652
	.short \party_slot
	.short \tutor
	.short \dest_var
	.endm

	.macro MoveTutorChooseMove mon_slot, tutor_no, arg2, arg3
	.short 653
	.short \mon_slot
	.short \tutor_no
	.short \arg2
	.short \arg3
	.endm

	.macro TutorMoveTeachInSlot party_slot, move_slot, move
	.short 654
	.short \party_slot
	.short \move_slot
	.short \move
	.endm

	.macro TutorMoveGetPrice arg0, arg1
	.short 655
	.short \arg0
	.short \arg1
	.endm

	.macro MonCanLearnHeadbuttFromTutor party_slot, dest_var
	.short 656
	.short \party_slot
	.short \dest_var
	.endm

	.macro StatJudge mon_slot, iv_sum, best_stat, best_iv
	.short 657
	.short \mon_slot
	.short \iv_sum
	.short \best_stat
	.short \best_iv
	.endm

	.macro BufferStatName arg0, arg1
	.short 658
	.byte \arg0
	.short \arg1
	.endm

	.macro SetMonForm arg0, arg1
	.short 659
	.short \arg0
	.short \arg1
	.endm

	.macro BufferTrainerName arg0, arg1
	.short 660
	.byte \arg0
	.short \arg1
	.endm

	.macro BufferIntExWord idx, number, mode, digits
	.short 661
	.byte \idx
	.word \number
	.byte \mode
	.byte \digits
	.endm

	.macro LaunchGlobalTerminal arg0, arg1, dest_var
	.short 662
	.short \arg0
	.short \arg1
	.short \dest_var
	.endm

	.macro LaunchWiFiPlaza var
	.short 663
	.short \var
	.endm

	.macro Dummy664
	.short 664
	.endm

	.macro FieldBGMPlay seq
	.short 665
	.short \seq
	.endm

	.macro GetCurrentBGM dest_var
	.short 666
	.short \dest_var
	.endm

	.macro CheckABHeld dest_var
	.short 667
	.short \dest_var
	.endm

	.macro BufferTypeName arg0, arg1
	.short 668
	.byte \arg0
	.short \arg1
	.endm

	.macro GetItemQuantity arg0, arg1
	.short 669
	.short \arg0
	.short \arg1
	.endm

	.macro GetHiddenPowerType arg0, arg1
	.short 670
	.short \arg0
	.short \arg1
	.endm

	.macro SetFavoriteMon
	.short 671
	.endm

	.macro GetFavoriteMon arg0, arg1, arg2
	.short 672
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro GetOwnedRotomForms arg0, arg1, arg2, arg3, arg4
	.short 673
	.short \arg0
	.short \arg1
	.short \arg2
	.short \arg3
	.short \arg4
	.endm

	.macro CountTranformedRotomsInParty arg0, arg1
	.short 674
	.short \arg0
	.short \arg1
	.endm

	.macro UpdateRotomForm arg0, arg1, arg2, arg3
	.short 675
	.short \arg0
	.short \arg1
	.short \arg2
	.short \arg3
	.endm

	.macro GetPartyMonForm arg0, arg1
	.short 676
	.short \arg0
	.short \arg1
	.endm

	.macro MultichoiceShowListAtPosition scroll_var, row_var
	.short 677
	.short \scroll_var
	.short \row_var
	.endm

	.macro CreateCameraFocusObject x, y
	.short 678
	.short \x
	.short \y
	.endm

	.macro RemoveCameraFocusObject
	.short 679
	.endm

	.macro AddSpecialGameStat2 arg0
	.short 680
	.short \arg0
	.endm

	.macro EditBattleGreeting dest_var
	.short 681
	.short \dest_var
	.endm

	.macro CheckFieldHeapFreeSize mode
	.short 682
	.short \mode
	.endm

	.macro GetStaticEncounterOutcome arg0
	.short 683
	.short \arg0
	.endm

	.macro GetWeatherType dest_var
	.short 684
	.short \dest_var
	.endm

	.macro GetPlayerXYZ arg0, arg1, arg2
	.short 685
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro FatefulWildBattle species, level
	.short 686
	.short \species
	.short \level
	.endm

	.macro SetMonSeenFlag species
	.short 687
	.short \species
	.endm

	.macro GetPartySlotWithFatefulEncounter arg0, arg1
	.short 688
	.short \arg0
	.short \arg1
	.endm

	; Attempt to remove all Griseous Orbs and reset Pokemon
	; to forms present in Diamond and Pearl, to avoid
	; problems communicating with those games.
	.macro CommSanitizeParty var_result
	.short 689
	.short \var_result
	.endm

	.macro DaycareSanitizeMon arg0, arg1
	.short 690
	.short \arg0
	.short \arg1
	.endm

	.macro CheckPlazaLoginTimeElapsed dest_var
	.short 691
	.short \dest_var
	.endm

	.macro BufferBattleHallStreak arg0, arg1, arg2, arg3, arg4, arg5
	.short 692
	.byte \arg0
	.byte \arg1
	.byte \arg2
	.byte \arg3
	.short \arg4
	.short \arg5
	.endm

	.macro BattleHallCountUsedSpecies arg0
	.short 693
	.short \arg0
	.endm

	.macro BattleHallGetTotalStreak arg0
	.short 694
	.short \arg0
	.endm

	.macro MultichoiceShowListWithWidth width
	.short 695
	.short \width
	.endm

	.macro UpdatePartyGiratinaFormsAndCaughtFlags distortion
	.short 696
	.short \distortion
	.endm

	.macro CheckBattleHallStreakIs50 dest_var
	.short 697
	.short \dest_var
	.endm

	.macro FollowerPokeIsEventTrigger arg0, arg1, arg2
	.short 698
	.byte \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro SetOtherObjectsFlag13
	.short 699
	.endm

	.macro ClearOtherObjectsFlag13
	.short 700
	.endm

	.macro MonHasItem arg0, arg1
	.short 701
	.short \arg0
	.short \arg1
	.endm

	.macro BattleTowerSetUpMultiBattle
	.short 702
	.endm

	.macro SetPlayerVolume arg0
	.short 703
	.short \arg0
	.endm

	.macro AddGameStat stat, value
	.short 704
	.short \stat
	.short \value
	.endm

	.macro AddGameStatWord stat, value
	.short 705
	.short \stat
	.word \value
	.endm

	.macro CheckHallOfFameSaveInvalid dest_var
	.short 706
	.short \dest_var
	.endm

	.macro CheckMonSeen arg0, arg1
	.short 707
	.short \arg0
	.short \arg1
	.endm

	.macro PlayTrapEffect kind
	.short 708
	.short \kind
	.endm

	.macro PlayHideoutAlarm
	.short 709
	.endm

	.macro UpdateMapPropAnimsFromFlag96B
	.short 710
	.endm

	.macro FollowMonInteract
	.short 711
	.endm

	.macro LaunchPokeathlonRecordsApp kind
	.short 712
	.byte \kind
	.endm

	.macro AlphPuzzle arg0
	.short 713
	.byte \arg0
	.endm

	.macro OpenAlphHiddenRoom arg0
	.short 714
	.byte \arg0
	.endm

	.macro UpdateDaycareMonObjects
	.short 715
	.endm

	.macro LaunchSafariAreaCustomizer
	.short 716
	.endm

	.macro StartSafariDecoration dest_var
	.short 717
	.short \dest_var
	.endm

	.macro BufferSafariZoneObjectName idx, object
	.short 718
	.byte \idx
	.short \object
	.endm

	.macro GetFacingSafariObject dest_var, index_var
	.short 719
	.short \dest_var
	.short \index_var
	.endm

	.macro RemoveSafariObject index
	.short 720
	.short \index
	.endm

	.macro CheckSafariObjectPlacement dest_var
	.short 721
	.short \dest_var
	.endm

	.macro MagnetTrainRide arg0, arg1, map, x, y
	.short 722
	.byte \arg0
	.byte \arg1
	.short \map
	.short \x
	.short \y
	.endm

	.macro ShipVoyage arg0, arg1, map, x, y
	.short 723
	.byte \arg0
	.byte \arg1
	.short \map
	.short \x
	.short \y
	.endm

	.macro GetPokeathlonStat stat, dest_var
	.short 724
	.short \stat
	.short \dest_var
	.endm

	.macro AdjustPokeathlonStat11 subtract, amount
	.short 725
	.byte \subtract
	.short \amount
	.endm

	.macro ProcessSoundplate
	.short 726
	.endm

	.macro GetFollowPokePartyIndex arg0
	.short 727
	.short \arg0
	.endm

	.macro FollowMonFlash step, period
	.short 728
	.byte \step
	.byte \period
	.endm

	.macro FollowMonIsActive dest_var
	.short 729
	.short \dest_var
	.endm

	.macro FollowMonIsInactiveOrVisible dest_var
	.short 730
	.short \dest_var
	.endm

	.macro FollowMonGrowAndShrink
	.short 731
	.endm

	.macro FollowMonAddMood mood
	.short 732
	.byte \mood
	.endm

	.macro FirstAliveMonHasType type, dest_var
	.short 733
	.byte \type
	.short \dest_var
	.endm

	.macro FollowMonJumpOnSpot count
	.short 734
	.byte \count
	.endm

	.macro GetKurtApricornQuantity dest_var
	.short 735
	.short \dest_var
	.endm

	.macro ClearKurtApricorn
	.short 736
	.endm

	.macro GetKurtBall dest_var
	.short 737
	.short \dest_var
	.endm

	.macro GetTotalApricornCount arg0
	.short 738
	.short \arg0
	.endm

	.macro LaunchApricornBoxForKurt
	.short 739
	.endm

	.macro LaunchApricornBoxForJuice arg0, juice_used_var
	.short 740
	.short \arg0
	.short \juice_used_var
	.endm

	.macro GetApricornJuiceOffer index, juice_var, price_var, juice_unk0_var
	.short 741
	.short \index
	.short \juice_var
	.short \price_var
	.short \juice_unk0_var
	.endm

	.macro MonLearnsetHasMove party_slot, move, dest_var
	.short 742
	.short \party_slot
	.short \move
	.short \dest_var
	.endm

	.macro ShowPokeathlonRecords data
	.short 743
	.short \data
	.endm

	.macro CreatePokeathlonFriendshipRoomStatues
	.short 744
	.endm

	.macro BufferPokeathlonCourseName arg0, arg1
	.short 745
	.byte \arg0
	.short \arg1
	.endm

	.macro TouchscreenMenuHide
	.short 746
	.endm

	.macro TouchscreenMenuShow
	.short 747
	.endm

	.macro GetMenuChoice arg0
	.short 748
	.short \arg0
	.endm

	.macro MenuInitStdGmm arg0, arg1, arg2, arg3, arg4
	.short 749
	.byte \arg0
	.byte \arg1
	.byte \arg2
	.byte \arg3
	.short \arg4
	.endm

	.macro MenuInit arg0, arg1, arg2, arg3, arg4
	.short 750
	.byte \arg0
	.byte \arg1
	.byte \arg2
	.byte \arg3
	.short \arg4
	.endm

	.macro MenuItemAdd arg0, arg1, arg2
	.short 751
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro MenuExec
	.short 752
	.endm

	.macro RockSmashItemCheck arg0, arg1, arg2
	.short 753
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro TryHeadbuttEncounter arg0
	.short 754
	.short \arg0
	.endm

	.macro LegendCutsceneClearBellAnimBegin
	.short 755
	.endm

	.macro LegendCutsceneClearBellAnimEnd
	.short 756
	.endm

	.macro LegendCutsceneClearBellRiseFromBag
	.short 757
	.endm

	.macro LegendCutsceneClearBellShimmer arg0
	.short 758
	.short \arg0
	.endm

	.macro LegendCutsceneLugiaEyeGlimmerEffect
	.short 759
	.endm

	.macro UnusedHoOhAnim
	.short 760
	.endm

	.macro LegendCutsceneMoveCameraTo arg0
	.short 761
	.short \arg0
	.endm

	.macro LegendCutscenePanCameraTo arg0
	.short 762
	.short \arg0
	.endm

	.macro LegendCutsceneWaitCameraPan
	.short 763
	.endm

	.macro LegendCutsceneBirdFinalApproach
	.short 764
	.endm

	.macro LegendCutsceneWavesOrLeavesEffectBegin
	.short 765
	.endm

	.macro LegendCutsceneWavesOrLeavesEffectEnd
	.short 766
	.endm

	.macro LegendCutsceneLugiaArrivesEffectBegin
	.short 767
	.endm

	.macro LegendCutsceneLugiaArrivesEffectEnd
	.short 768
	.endm

	.macro LegendCutsceneLugiaArrivesEffectCameraPan
	.short 769
	.endm

	.macro CheckSeenAllLetterUnown arg0
	.short 770
	.short \arg0
	.endm

	.macro PokeathlonDailyMart
	.short 771
	.endm

	.macro PokeathlonDataCardMart
	.short 772
	.endm

	.macro Cinematic arg0
	.short 773
	.short \arg0
	.endm

	.macro ShowLegendaryWing arg0
	.short 774
	.short \arg0
	.endm

	.macro LanceFlyAway lance, dragonite
	.short 775
	.short \lance
	.short \dragonite
	.endm

	.macro GiveTogepiEgg
	.short 776
	.endm

	.macro MonIsFromTogepiEgg party_slot, dest_var
	.short 777
	.short \party_slot
	.short \dest_var
	.endm

	.macro GiveSpikyEarPichu
	.short 778
	.endm

	.macro RadioMusicIsPlaying arg0, arg1
	.short 779
	.short \arg0
	.short \arg1
	.endm

	.macro CasinoGame arg0, arg1
	.short 780
	.byte \arg0
	.byte \arg1
	.endm

	.macro KenyaCheckPartyOrMailbox arg0
	.short 781
	.short \arg0
	.endm

	.macro MartSell
	.short 782
	.endm

	.macro SetFollowMonInhibitState arg0
	.short 783
	.byte \arg0
	.endm

	.macro ScriptOverlayCmd arg0, arg1
	.short 784
	.byte \arg0
	.byte \arg1
	.endm

	.macro BugContestAction arg0, arg1
	.short 785
	.byte \arg0
	.short \arg1
	.endm

	.macro BufferBugContestWinner arg0
	.short 786
	.byte \arg0
	.endm

	.macro JudgeBugContest arg0, arg1, arg2
	.short 787
	.short \arg0
	.short \arg1
	.short \arg2
	.endm

	.macro BufferBugContestMonNick arg0, arg1
	.short 788
	.byte \arg0
	.short \arg1
	.endm

	.macro BugContestGetTimeLeft arg0
	.short 789
	.byte \arg0
	.endm

	.macro IsBugContestantRegistered arg0, arg1
	.short 790
	.short \arg0
	.short \arg1
	.endm

	.macro CheckSafariZoneChallengeCompleted arg0, arg1
	.short 791
	.byte \arg0
	.short \arg1
	.endm

	.macro UpdateSafariZoneIGT
	.short 792
	.endm

	.macro BankTransaction arg0, arg1
	.short 793
	.short \arg0
	.short \arg1
	.endm

	.macro CheckBankBalance arg0, arg1
	.short 794
	.short \arg0
	.word \arg1
	.endm

	.macro ShowSavingsBox x, y
	.short 795
	.short \x
	.short \y
	.endm

	.macro HideSavingsBox
	.short 796
	.endm

	.macro UpdateSavingsBox
	.short 797
	.endm

	.macro BufferRulesetName arg0
	.short 798
	.short \arg0
	.endm

	.macro BufferBattleRegulationName regulation_var
	.short 799
	.short \regulation_var
	.endm

	.macro SetActiveBattleRegulation regulation_var
	.short 800
	.short \regulation_var
	.endm

	.macro ShowBattleRegulationWindow regulation_var
	.short 801
	.short \regulation_var
	.endm

	.macro HideBattleRegulationWindow
	.short 802
	.endm

	.macro CheckPartyBattleRegulation regulation_var, dest_var
	.short 803
	.short \regulation_var
	.short \dest_var
	.endm

	.macro SetPokegearMapUnlockLevel level
	.short 804
	.byte \level
	.endm

	.macro LoadEventSoundEffects
	.short 805
	.endm

	.macro ShayminRevertToLandForm
	.short 806
	.endm

	.macro SetTrainerHouseSprite arg0, arg1
	.short 807
	.short \arg0
	.short \arg1
	.endm

	.macro TrainerHouseBattle trainer
	.short 808
	.short \trainer
	.endm

	.macro ShowTrainerHouseIntroMessage arg0
	.short 809
	.short \arg0
	.endm

	.macro CelebiTimeTravel
	.short 810
	.endm

	.macro PeekMomGift item_var, dest_var
	.short 811
	.short \item_var
	.short \dest_var
	.endm

	.macro PopMomGift
	.short 812
	.endm

	.macro MomGiftCheck arg0
	.short 813
	.short \arg0
	.endm

	.macro SetFlag99A
	.short 814
	.endm

	.macro SetSavedBottomScreenApp app
	.short 815
	.short \app
	.endm

	.macro UnownCircle
	.short 816
	.endm

	.macro SinjohGetEggCutscene kind
	.short 817
	.byte \kind
	.endm

	.macro MystriStageGymmickInit
	.short 818
	.endm

	.macro SinjohFreezeAllModels
	.short 819
	.endm

	.macro SinjohSetChosenLegend choice
	.short 820
	.byte \choice
	.endm

	.macro GetBuenasPassword arg0, arg1
	.short 821
	.short \arg0
	.short \arg1
	.endm

	.macro CustomSafariLinkExchange
	.short 822
	.endm

	.macro BufferSafariLinkLeaderName idx
	.short 823
	.short \idx
	.endm

	.macro CheckSafariZoneLinked dest_var
	.short 824
	.short \dest_var
	.endm

	.macro GetShinyLeafCount arg0, arg1
	.short 825
	.short \arg0
	.short \arg1
	.endm

	.macro TryGiveShinyLeafCrown arg0
	.short 826
	.short \arg0
	.endm

	.macro GetPartyMonForm2 arg0, arg1
	.short 827
	.short \arg0
	.short \arg1
	.endm

	.macro MonAddContestValue arg0, arg1, arg2
	.short 828
	.short \arg0
	.byte \arg1
	.short \arg2
	.endm

	.macro FollowMonIsNextToPlayer dest_var
	.short 829
	.short \dest_var
	.endm

	.macro CheckGiftAccessoriesFull dest_var
	.short 830
	.short \dest_var
	.endm

	.macro GetRandomGiftAccessory dest_var
	.short 831
	.short \dest_var
	.endm

	.macro CheckHasAllBackdrops dest_var
	.short 832
	.short \dest_var
	.endm

	.macro GetRandomMissingBackdrop dest_var
	.short 833
	.short \dest_var
	.endm

	.macro CheckPokeathlonDailyMartHasStock dest_var
	.short 834
	.short \dest_var
	.endm

	.macro CountPokeathlonDataCardsBought dest_var
	.short 835
	.short \dest_var
	.endm

	.macro CheckKyogreGroudonInParty arg0
	.short 836
	.short \arg0
	.endm

	.macro CheckHasLinkBattleRuleset dest_var
	.short 837
	.short \dest_var
	.endm

	.macro BankOrWalletIsFull arg0, arg1
	.short 838
	.short \arg0
	.short \arg1
	.endm

	.macro SysSetSleepFlag arg0
	.short 839
	.short \arg0
	.endm

	.macro GetMapPokeCenterOrLeagueType map, dest_var
	.short 840
	.short \map
	.short \dest_var
	.endm

	.macro MultichoiceSetAnchorRight value
	.short 841
	.byte \value
	.endm

	.macro MultichoiceSetAnchorBottom value
	.short 842
	.byte \value
	.endm

	.macro BufferItemNameIndef arg0, arg1
	.short 843
	.byte \arg0
	.short \arg1
	.endm

	.macro BufferItemNamePlural arg0, arg1
	.short 844
	.byte \arg0
	.short \arg1
	.endm

	.macro BufferPartyMonSpeciesNameIndef arg0, arg1
	.short 845
	.byte \arg0
	.short \arg1
	.endm

	.macro BufferSpeciesNameIndef arg0, arg1, arg2, arg3
	.short 846
	.byte \arg0
	.short \arg1
	.short \arg2
	.byte \arg3
	.endm

	.macro BufferDPPtFriendStarterSpeciesNameIndef arg0
	.short 847
	.byte \arg0
	.endm

	.macro BufferFashionNameIndef arg0, arg1
	.short 848
	.byte \arg0
	.short \arg1
	.endm

	.macro BufferTrainerClassNameIndef arg0, arg1
	.short 849
	.byte \arg0
	.short \arg1
	.endm

	.macro BufferSealNamePlural arg0, arg1
	.short 850
	.byte \arg0
	.short \arg1
	.endm

	.macro Capitalize arg0
	.short 851
	.byte \arg0
	.endm

	.macro BufferDeptStoreFloorNo arg0, arg1
	.short 852
	.byte \arg0
	.byte \arg1
	.endm

	; Script headers

	.macro MapScript kind, script
	.byte \kind
	.word \script
	.endm

	.macro MapScript2 var, val, script
	.short \var, \val, \script
	.endm

	; Convenience macros

	; Generic compare macro which attempts to deduce argument types based on their values
	; Any values between 0x4000 to 0x40FF and 0x8000 to 0x8015 are considered event variable identifiers
	.macro Compare var, arg
		.if ((\arg >= VARS_START && \arg <= VARS_END) || (\arg >= SPECIAL_VARS_START && \arg <= SPECIAL_VARS_END))
			CompareVarToVar \var, \arg
		.else
			CompareVarToValue \var, \arg
		.endif
	.endm

	.macro GoToIfUnset flag, dest
	CheckFlag \flag
	GoToIf FALSE, \dest
	.endm

	.macro GoToIfSet flag, dest
	CheckFlag \flag
	GoToIf TRUE, \dest
	.endm

	.macro GoToIfLt dest ; LESS THAN
	GoToIf 0, \dest
	.endm

	.macro GoToIfEq dest ; EQUAL
	GoToIf 1, \dest
	.endm

	.macro GoToIfGt dest ; GREATER THAN
	GoToIf 2, \dest
	.endm

	.macro GoToIfLe dest ; LESS THAN OR EQUAL
	GoToIf 3, \dest
	.endm

	.macro GoToIfGe dest ; GREATER THAN OR EQUAL
	GoToIf 4, \dest
	.endm

	.macro GoToIfNe dest ; NOT EQUAL
	GoToIf 5, \dest
	.endm

	.macro CallIfUnset flag, dest
	CheckFlag \flag
	CallIf FALSE, \dest
	.endm

	.macro CallIfSet flag, dest
	CheckFlag \flag
	CallIf TRUE, \dest
	.endm

	.macro CallIfLt dest ; LESS THAN
	CallIf 0, \dest
	.endm

	.macro CallIfEq dest ; EQUAL
	CallIf 1, \dest
	.endm

	.macro CallIfGt dest ; GREATER THAN
	CallIf 2, \dest
	.endm

	.macro CallIfLe dest ; LESS THAN OR EQUAL
	CallIf 3, \dest
	.endm

	.macro CallIfGe dest ; GREATER THAN OR EQUAL
	CallIf 4, \dest
	.endm

	.macro CallIfNe dest ; NOT EQUAL
	CallIf 5, \dest
	.endm

	.macro GoToIfDefeated trainer, dest
	CheckTrainerFlag \trainer
	GoToIf TRUE, \dest
	.endm

	.macro GoToIfNotDefeated trainer, dest
	CheckTrainerFlag \trainer
	GoToIf FALSE, \dest
	.endm

	.macro CallIfDefeated trainer, dest
	CheckTrainerFlag \trainer
	CallIf TRUE, \dest
	.endm

	.macro CallIfNotDefeated trainer, dest
	CheckTrainerFlag \trainer
	CallIf FALSE, \dest
	.endm

	.macro ItemVars item, quantity=1
	.if \item < 0x4000
	SetVar VAR_SPECIAL_x8004, \item
	.else
	CopyVar VAR_SPECIAL_x8004, \item
	.endif
	.if \quantity < 0x4000
	SetVar VAR_SPECIAL_x8005, \quantity
	.else
	CopyVar VAR_SPECIAL_x8005, \quantity
	.endif
	.endm

	.macro GoToIfNoItemSpace item, quantity, target
	ItemVars \item, \quantity
	HasSpaceForItem VAR_SPECIAL_x8004, VAR_SPECIAL_x8005, VAR_SPECIAL_RESULT
	Compare VAR_SPECIAL_RESULT, 0
	GoToIf eq, \target
	.endm

	.macro GoToIfNoItemSpace2 item, quantity, target
	ItemVars \item, \quantity
	HasSpaceForItem VAR_SPECIAL_x8004, VAR_SPECIAL_x8005, VAR_SPECIAL_RESULT
	Compare VAR_SPECIAL_RESULT, 1
	GoToIf ne, \target
	.endm

	.macro GiveItemNoCheck item, quantity
	ItemVars \item, \quantity
	CallStd std_give_item_verbose
	.endm

	.macro TakeItemNoCheck item, quantity
	ItemVars \item, \quantity
	TakeItem VAR_SPECIAL_x8004, VAR_SPECIAL_x8005, VAR_SPECIAL_RESULT
	.endm

	.macro Switch var
	CopyVar VAR_SPECIAL_x8008, \var
	.endm

	.macro Case value, target
	Compare VAR_SPECIAL_x8008, \value
	GoToIf eq, \target
	.endm

	.macro PhoneCall who, b, c
	SetVar VAR_SPECIAL_x8004, \who
	SetVar VAR_SPECIAL_x8005, \b
	SetVar VAR_SPECIAL_x8006, \c
	CallStd std_phone_call
	.endm

	.macro SimpleNPCMsg msgid
	PlaySE SEQ_SE_DP_SELECT
	LockAll
	FacePlayer
	NPCMsg \msgid
	WaitButton
	CloseMsg
	ReleaseAll
	.endm

	 /*
     * This flag is used by ScriptEntry and ScriptEntryEnd to control where
     * a user can add ScriptEntry commands (i.e., only at the start of the
     * input file). It is NOT meant for direct usage.
     */
    .set F_ACCEPT_SCRIPT_ENTRIES, TRUE

    .macro ScriptEntry name
    .if F_ACCEPT_SCRIPT_ENTRIES == TRUE
        .long \name-.-4
    .else
        .error "cannot specify ScriptEntry after ScriptEntryEnd"
    .endif
    .endm

    .macro ScriptEntryEnd
    .set F_ACCEPT_SCRIPT_ENTRIES, FALSE
    .short 0xFD13
    .endm

    .set F_INIT_SCRIPT_FRAME_TABLE_OPENED, FALSE
    .set F_INIT_SCRIPT_FRAME_TABLE_CLOSED, FALSE

    .macro InitScriptEntry_Fixed type, scriptID
    .if F_ACCEPT_SCRIPT_ENTRIES == TRUE
        .byte \type
        .short \scriptID, 0
    .else
        .error "cannot specify InitScriptEntry after InitScriptEntryEnd"
    .endif
    .endm

    .macro InitScriptEntry_OnFrameTable checksLabel
    .if F_ACCEPT_SCRIPT_ENTRIES == TRUE
        .set F_INIT_SCRIPT_FRAME_TABLE_OPENED, TRUE
        .byte INIT_SCRIPT_ON_FRAME_TABLE
        ScriptEntry \checksLabel
    .else
        .error "cannot specify InitScriptEntry after InitScriptEntryEnd"
    .endif
    .endm

    .macro InitScriptEntry_OnTransition scriptID
    InitScriptEntry_Fixed INIT_SCRIPT_ON_TRANSITION, \scriptID
    .endm

    .macro InitScriptEntry_OnResume scriptID
    InitScriptEntry_Fixed INIT_SCRIPT_ON_RESUME, \scriptID
    .endm

    .macro InitScriptEntry_OnLoad scriptID
    InitScriptEntry_Fixed INIT_SCRIPT_ON_LOAD, \scriptID
    .endm

    .macro InitScriptEntryEnd
    .set F_ACCEPT_SCRIPT_ENTRIES, FALSE
    .byte 0
    .endm

    .macro InitScriptGoToIfEqual var1, var2, scriptID
    .if F_INIT_SCRIPT_FRAME_TABLE_OPENED == TRUE
        .if F_INIT_SCRIPT_FRAME_TABLE_CLOSED == FALSE
            .short \var1, \var2, \scriptID
        .else
            .error "cannot specify InitScriptGoToIfEqual after InitScriptFrameTableEnd"
        .endif
    .else
        .error "cannot specify InitScriptGoToIfEqual before InitScriptEntry_OnFrameTable"
    .endif
    .endm

    .macro InitScriptFrameTableEnd
    .set F_INIT_SCRIPT_FRAME_TABLE_CLOSED, TRUE
    .short 0
    .endm

    .macro InitScriptEnd
    .if F_ACCEPT_SCRIPT_ENTRIES == TRUE
        .error "cannot specify InitScriptEnd before InitScriptEntryEnd"
    .endif
    .if F_INIT_SCRIPT_FRAME_TABLE_OPENED == TRUE
        .if F_INIT_SCRIPT_FRAME_TABLE_CLOSED == FALSE
            .error "must close InitScriptEntry_OnFrameTable with InitScriptFrameTableEnd before InitScriptEnd"
        .endif
    .endif
    .balign 4, 0
    .endm

	.endif ; ASM_SCRIPT_INC
