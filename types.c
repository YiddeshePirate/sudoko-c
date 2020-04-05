#ifndef TYPES_H
#define TYPES_H

typedef struct square
{
    int x;
    int y;
    int val;
}square;

typedef struct board
{
    square brd[9][9];
}board;

#endif /* GRANDPARENT_H */