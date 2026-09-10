#include "grid_cursor_internal.h"

void sub_020957B0(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy) {
    GridMove move;

    move.type = sub_02095BF0(cursor, position, dimensions, dx, dy);
    switch (move.type) {
    default:
        break;
    case 1:
        move.value = position->y;
        sub_02095CB8(cursor, 3, (int)&move);
        return;
    case 2:
        move.value = position->y;
        sub_02095CB8(cursor, 3, (int)&move);
        return;
    case 3:
        move.value = position->x;
        sub_02095CB8(cursor, 5, (int)&move);
        return;
    case 4:
        move.value = position->x;
        sub_02095CB8(cursor, 5, (int)&move);
        return;
    }
}

void sub_02095838(GridCursor *cursor, GridPosition *position, const u8 *dimensions, const GridMove *move) {
    switch (move->type) {
    case 4:
        position->x = 2;
        position->y = 0;
        position->index = position->x + position->y * dimensions[0];
        break;
    case 3:
        position->x = 2;
        position->y = 4;
        position->index = position->x + position->y * dimensions[0];
        break;
    case 1:
        position->x = 5;
        position->y = move->value;
        position->index = position->x + position->y * dimensions[0];
        break;
    case 2:
        position->x = 0;
        position->y = move->value;
        position->index = position->y * dimensions[0];
        break;
    }
}

void sub_020958C0(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy) {
    GridMove move;

    move.type = sub_02095BF0(cursor, position, dimensions, dx, dy);
    move.value = position->x;
    if (move.type != 1) {
        if (move.type == 3) {
            move.value = 0;
            sub_02095CB8(cursor, 3, (int)&move);
            return;
        }
    } else {
        if (*(u8 *)cursor->userData == 0x12) {
            move.value = 0;
            sub_02095CB8(cursor, 6, (int)&move);
            return;
        }
        move.value = 4;
        sub_02095CB8(cursor, 2, (int)&move);
        return;
    }
}

void sub_02095920(void *unused, GridPosition *position) {
    position->x = 0;
    position->y = 0;
    position->index = 0;
}

void sub_0209592C(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy) {
    GridMove move;
    int type;

    type = sub_02095BF0(cursor, position, dimensions, dx, dy);
    move.type = type;
    if (position->y == 0) {
        move.value = 0;
    } else if (position->y == 1) {
        move.value = 2;
    } else {
        move.value = 3;
    }
    switch (type) {
    case 1:
        if (*(u8 *)cursor->userData == 0x12) {
            move.value = 0;
            sub_02095CB8(cursor, 6, (int)&move);
            return;
        }
        sub_02095CB8(cursor, 2, (int)&move);
        return;
    case 2:
        if (*(u8 *)cursor->userData == 0x12) {
            move.value = 0;
            sub_02095CB8(cursor, 6, (int)&move);
            return;
        }
        sub_02095CB8(cursor, 2, (int)&move);
        return;
    case 4:
        if (cursor->unk_02 != 0) {
            sub_02095CB8(cursor, 1, (int)&move);
        }
        return;
    }
}

void sub_020959D8(GridCursor *cursor, GridPosition *position, const u8 *dimensions, const GridMove *move) {
    switch (move->type) {
    case 3:
        position->index = ((dimensions[2] - 1) / dimensions[0]) * dimensions[0];
        position->x = position->index % dimensions[0];
        position->y = position->index / dimensions[0];
        break;
    case 1:
    case 2:
        if (move->value < 2) {
            position->index = 0;
        } else if (move->value > 2) {
            position->index = 2;
        } else {
            position->index = 1;
        }
        position->x = 0;
        position->y = position->index;
        break;
    }
}

void sub_02095A34(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy) {
    GridMove move;

    move.type = sub_02095BF0(cursor, position, dimensions, dx, dy);
    move.value = 0;
    switch (move.type) {
    default:
        break;
    case 3:
        sub_02095CB8(cursor, 4, (int)&move);
        return;
    case 4:
        sub_02095CB8(cursor, 4, (int)&move);
        return;
    }
}

void sub_02095A78(void) {
}

void sub_02095A7C(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy) {
    GridMove move;

    move.type = sub_02095BF0(cursor, position, dimensions, dx, dy);
    move.value = position->x;
    switch (move.type) {
    default:
        break;
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        if (*(u8 *)cursor->userData == 0x12) {
            sub_02095CB8(cursor, 6, (int)&move);
            return;
        }
        sub_02095CB8(cursor, 2, (int)&move);
        return;
    case 4:
        if (*(u8 *)cursor->userData == 0x12) {
            sub_02095CB8(cursor, 6, (int)&move);
            return;
        }
        sub_02095CB8(cursor, 2, (int)&move);
        return;
    }
}

void sub_02095AF8(void *unused, GridPosition *position) {
    position->x = 0;
    position->y = 0;
    position->index = 0;
}

void sub_02095B04(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy) {
    GridMove move;

    move.type = sub_02095BF0(cursor, position, dimensions, dx, dy);
    move.value = position->x;
    switch (move.type) {
    default:
        break;
    case 1:
        move.value = position->y;
        sub_02095CB8(cursor, 3, (int)&move);
        return;
    case 2:
        move.value = position->y;
        sub_02095CB8(cursor, 3, (int)&move);
        return;
    case 3:
        move.value = position->x;
        sub_02095CB8(cursor, 5, (int)&move);
        return;
    case 4:
        move.value = position->x;
        sub_02095CB8(cursor, 5, (int)&move);
        return;
    }
}

void sub_02095B88(GridCursor *cursor, GridPosition *position, const u8 *dimensions, const GridMove *move) {
    switch (move->type) {
    case 3:
    case 4:
        position->x = 2;
        position->y = 0;
        position->index = position->x + position->y * dimensions[0];
        break;
    case 1:
        position->x = 5;
        position->y = 0;
        position->index = position->x + position->y * dimensions[0];
        break;
    case 2:
        position->x = 0;
        position->y = 0;
        position->index = position->y * dimensions[0];
        break;
    }
}
