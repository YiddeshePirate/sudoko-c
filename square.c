#include <stdbool.h>
#include <stdio.h>
#include "types.c"


bool is_valid_row(square* s, board* b)
{
    for(int i=0; i<9; i++)
    {
        if (b->brd[s->x][i].val == s->val)
        {
            return false;
        }
    }
    return true;
};

bool is_valid_col(square* s, board* b)
{
    for(int i=0; i<9; i++)
    {
        if (b->brd[i][s->y].val == s->val)
        {
            return false;
        }
    }
    return true;
};


bool is_valid_box(square* s, board* b)
{
    int base_x = (s->x)/3*3;
    int base_y = (s->y)/3*3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(b->brd[i+base_x][j+base_y].val == s->val)
            {
                return false;
            }
        }
    }
    return true;
}

bool is_valid_square(square* s, board* b)
{
    if(is_valid_box(s, b) && is_valid_col(s, b) && is_valid_row(s, b))
    {
        return true;
    }
    return false;
}



