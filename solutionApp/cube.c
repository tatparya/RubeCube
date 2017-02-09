#include "cube.h"

/*
    TODO :
    1. Work on cube funcitons( side rotations )
    2. Work on solution algorithm
*/

void displayCube( int cube[6][3][3] )
{
    int i,j;
    int r,c;

    r = 0;
    c = 0;

    printf( "Cube:\n");

    for( i = 0; i < 3; i++ )
    {
        for( r = 0; r < 3; r++ )
        {
            for( j = 0; j < 4; j++ )
            {
                if( i == 0 && j == 1 )
                {
                    //  Print side 5
                    displayCubeRow( cube, r, 4 );
                }

                else if( i == 1 && j == 0 )
                {
                    // Print side 1
                    displayCubeRow( cube, r, 0 );
                }

                else if( i == 1 && j == 1 )
                {
                    // Print side 2
                    displayCubeRow( cube, r, 1 );
                }

                else if( i == 1 && j == 2 )
                {
                    // Print side 3
                    displayCubeRow( cube, r, 2 );
                }

                else if( i == 1 && j == 3 )
                {
                    // Print side 4
                    displayCubeRow( cube, r, 3 );
                }

                else if( i == 2 && j == 1 )
                {
                    // Print side 6
                    displayCubeRow( cube, r, 5 );
                }

                else
                {
                    //  Print blanks
                    displayCubeRow( cube, r, -1 );
                }
            }

            printf( "\n\n" );
        }
    }
}

void displayCubeRow( int cube[6][3][3], int row, int side )
{
    for( int col = 0; col < 3; col++ )
    {
        //  Check if blank or not
        if( side == -1 )
        {
            printf( "   " );
        }
        else
        {
            printf( " %d ", cube[side][row][col] );
        }
    }
}
