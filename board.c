#include <stdio.h>
#include "types.c"

void insert_in_board(square* s, board* b)
{
    b->brd[s->x][s->y] = *s;
}


void prompt_board(board* b)
{
    for(int i=0; i<9;i++)
    {
        int tmp_array[9];
        printf("Enter values for row #%d comma separated\n", i);
        scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d", &tmp_array[0],&tmp_array[1],&tmp_array[2],&tmp_array[3],&tmp_array[4],&tmp_array[5],&tmp_array[6],&tmp_array[7],&tmp_array[8]);

        for(int j=0; j<9; j++)
        {
            square s;
            s.x = i, s.y = j;
            s.val = tmp_array[j];
            insert_in_board(&s, b);
            
        }
    }
}


void display_board(board* b)
{
    for(int i=0; i<9; i++)
    {
        if(i%3==0)
        {
        printf("|\n-------------------\n");
        }else{
            printf("|\n");
        }
        for(int j=0; j<9; j++)
        {
            if(j%3 == 0)
            {
                printf("|");
            }
            printf("%d", b->brd[i][j].val);
            if(j%3 != 2)
            {
                printf(" ");
            }
        }
    }
    printf("|");
}

int find_empty_val(board* b, int* d)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            // printf("hello");
            // printf("%d", b->brd[i][j].val);
            if (b->brd[i][j].val == 0)
            {
                d[0] = i;
                d[1] = j;
                printf("%d\n", d[0]);
                printf("%d\n", d[1]);
                return 1;
            }
        }
    }
    return 0;
}

// int main()
// {
//     board tb1;
// }