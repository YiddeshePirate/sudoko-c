#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "square.h"
#include "board.h"

int count;

bool Solve(board* b)
{
    count++;
    int* l = malloc(2*sizeof(int));

    if (!find_empty_val(b, l))
    {
        return true;
    }

    for(int i=1; i<= 9; i++)
    {
        square s;
        s.x = l[0];
        s.y = l[1];
        s.val = i;
        if(is_valid_square(&s, b))
        {

        insert_in_board(&s, b);
        if(Solve(b))
        {
            return true;
        }

        s.val = 0;
        insert_in_board(&s, b);

        }

    }
    
    return false;

}

int main()
{
    board tb1;
    prompt_board(&tb1);
    Solve(&tb1);
    display_board(&tb1);
    printf("\n iterations: %d\n", count);
}
