#include "cube.h"

/*
    TODO :
    1. Work on cube funcitons( side rotations )
    2. Work on solution algorithm
*/

void displayCorners( int * corners [2][4][3] )
{
    printf( "Displaying Corners\n" );
    for( int i = 0; i < 2; i++ )
    {
        printf( "Layer %d:\n", i + 1 );
        for( int j = 0; j < 4; j++ )
        {
            printf( "%d, %d, %d\n", *corners[i][j][0], *corners[i][j][1], *corners[i][j][2] );
        }
    }
}

void displayEdges( int * edges [3][4][2] )
{
    printf( "Displaying Edges\n" );
    for( int i = 0; i < 3; i++ )
    {
        printf( "Layer %d:\n", i + 1 );
        for( int j = 0; j < 4; j++ )
        {
            printf( "%d, %d\n", *edges[i][j][0], *edges[i][j][1] );
        }
    }
}

void solveCube( int cube[6][3][3] )
{
    printf( "Starting Solving!\n" );
    printf( "Setting Edges\n" );

    int * edges [3][4][2] = {
        {
            { &cube[4][1][0], &cube[0][0][1] },
            { &cube[4][2][1], &cube[1][0][1] },
            { &cube[4][1][2], &cube[2][0][1] },
            { &cube[4][0][1], &cube[3][0][1] }
        },
        {
            { &cube[0][1][0], &cube[3][1][2] },
            { &cube[1][1][0], &cube[0][1][2] },
            { &cube[2][1][0], &cube[1][1][2] },
            { &cube[3][1][0], &cube[2][1][2] }
        },
        {
            { &cube[5][1][0], &cube[0][2][1] },
            { &cube[5][0][1], &cube[1][2][1] },
            { &cube[5][1][2], &cube[2][2][1] },
            { &cube[5][2][1], &cube[3][2][1] }
        }
    };

    displayEdges( edges );
    printf( "Setting Corners\n" );

    int * corners[2][4][3] = {
        {
            { &cube[4][2][0],  &cube[0][0][2],  &cube[1][0][0] },
            { &cube[4][2][2],  &cube[1][0][2],  &cube[2][0][0] },
            { &cube[4][0][2],  &cube[2][0][2],  &cube[3][0][0] },
            { &cube[4][0][0],  &cube[3][0][2],  &cube[0][0][0] }
        },
        {
            { &cube[5][0][0],  &cube[0][2][2],  &cube[1][2][0] },
            { &cube[5][0][2],  &cube[1][2][2],  &cube[2][2][0] },
            { &cube[5][2][2],  &cube[2][2][2],  &cube[3][2][0] },
            { &cube[5][2][0],  &cube[3][2][2],  &cube[0][2][0] }
        }
    };

    displayCorners( corners );
    printf( "Solved!!\n" );
}

void displayCube( int cube[6][3][3] )
{ int i,j;
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

void rotate( int side[3][3] )
{
    for( int i = 0; i < 2; i++ )
    {
        int temp = side[0][i];
        side[0][i] = side[2-i][0];
        side[2-i][0] = side[2][2-i];
        side[2][2-i] = side[i][2];
        side[i][2] = temp;
    }
}

void rotatePrime( int side[3][3] )
{
    for( int i = 0; i < 2; i++ )
    {
        int temp = side[0][i];
        side[0][i] = side[i][2];
        side[i][2] = side[2][2-i];
        side[2][2-i] = side[2-i][0];
        side[2-i][0] = temp;
    }
}

void up( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[0][0][0];
    t2 = cube[0][0][1];
    t3 = cube[0][0][2];

    cube[0][0][0] = cube[1][0][0];
    cube[0][0][1] = cube[1][0][1];
    cube[0][0][2] = cube[1][0][2];

    cube[1][0][0] = cube[2][0][0];
    cube[1][0][1] = cube[2][0][1];
    cube[1][0][2] = cube[2][0][2];

    cube[2][0][0] = cube[3][0][0];
    cube[2][0][1] = cube[3][0][1];
    cube[2][0][2] = cube[3][0][2];

    cube[3][0][0] = t1;
    cube[3][0][1] = t2;
    cube[3][0][2] = t3;

    rotate( cube[4] );
}

void upPrime( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[3][0][0];
    t2 = cube[3][0][1];
    t3 = cube[3][0][2];

    cube[3][0][0] = cube[2][0][0];
    cube[3][0][1] = cube[2][0][1];
    cube[3][0][2] = cube[2][0][2];

    cube[2][0][0] = cube[1][0][0];
    cube[2][0][1] = cube[1][0][1];
    cube[2][0][2] = cube[1][0][2];

    cube[1][0][0] = cube[0][0][0];
    cube[1][0][1] = cube[0][0][1];
    cube[1][0][2] = cube[0][0][2];

    cube[0][0][0] = t1;
    cube[0][0][1] = t2;
    cube[0][0][2] = t3;

    rotatePrime( cube[4] );
}

void down( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[3][2][0];
    t2 = cube[3][2][1];
    t3 = cube[3][2][2];

    cube[3][2][0] = cube[2][2][0];
    cube[3][2][1] = cube[2][2][1];
    cube[3][2][2] = cube[2][2][2];

    cube[2][2][0] = cube[1][2][0];
    cube[2][2][1] = cube[1][2][1];
    cube[2][2][2] = cube[1][2][2];

    cube[1][2][0] = cube[0][2][0];
    cube[1][2][1] = cube[0][2][1];
    cube[1][2][2] = cube[0][2][2];

    cube[0][2][0] = t1;
    cube[0][2][1] = t2;
    cube[0][2][2] = t3;

    rotate( cube[5] );
}

void downPrime( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[0][2][0];
    t2 = cube[0][2][1];
    t3 = cube[0][2][2];

    cube[0][2][0] = cube[1][2][0];
    cube[0][2][1] = cube[1][2][1];
    cube[0][2][2] = cube[1][2][2];

    cube[1][2][0] = cube[2][2][0];
    cube[1][2][1] = cube[2][2][1];
    cube[1][2][2] = cube[2][2][2];

    cube[2][2][0] = cube[3][2][0];
    cube[2][2][1] = cube[3][2][1];
    cube[2][2][2] = cube[3][2][2];

    cube[3][2][0] = t1;
    cube[3][2][1] = t2;
    cube[3][2][2] = t3;

    rotatePrime( cube[5] );
}

void left( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[1][0][0];
    t2 = cube[1][1][0];
    t3 = cube[1][2][0];

    cube[1][0][0] = cube[4][0][0];
    cube[1][1][0] = cube[4][1][0];
    cube[1][2][0] = cube[4][2][0];

    cube[4][0][0] = cube[3][2][2];
    cube[4][1][0] = cube[3][1][2];
    cube[4][2][0] = cube[3][0][2];

    cube[3][2][2] = cube[5][0][0];
    cube[3][1][2] = cube[5][1][0];
    cube[3][0][2] = cube[5][2][0];

    cube[5][0][0] = t1;
    cube[5][1][0] = t2;
    cube[5][2][0] = t3;

    rotate( cube[0] );
}

void leftPrime( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[1][0][0];
    t2 = cube[1][1][0];
    t3 = cube[1][2][0];

    cube[1][0][0] = cube[5][0][0];
    cube[1][1][0] = cube[5][1][0];
    cube[1][2][0] = cube[5][2][0];

    cube[5][0][0] = cube[3][2][2];
    cube[5][1][0] = cube[3][1][2];
    cube[5][2][0] = cube[3][0][2];

    cube[3][2][2] = cube[4][0][0];
    cube[3][1][2] = cube[4][1][0];
    cube[3][0][2] = cube[4][2][0];

    cube[4][0][0] = t1;
    cube[4][1][0] = t2;
    cube[4][2][0] = t3;

    rotatePrime( cube[0] );
}

void right( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[1][0][2];
    t2 = cube[1][1][2];
    t3 = cube[1][2][2];

    cube[1][0][2] = cube[5][0][2];
    cube[1][1][2] = cube[5][1][2];
    cube[1][2][2] = cube[5][2][2];

    cube[5][0][2] = cube[3][2][0];
    cube[5][1][2] = cube[3][1][0];
    cube[5][2][2] = cube[3][0][0];

    cube[3][2][0] = cube[4][0][2];
    cube[3][1][0] = cube[4][1][2];
    cube[3][0][0] = cube[4][2][2];

    cube[4][0][2] = t1;
    cube[4][1][2] = t2;
    cube[4][2][2] = t3;

    rotate( cube[2] );

}

void rightPrime( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[1][0][2];
    t2 = cube[1][1][2];
    t3 = cube[1][2][2];

    cube[1][0][2] = cube[4][0][2];
    cube[1][1][2] = cube[4][1][2];
    cube[1][2][2] = cube[4][2][2];

    cube[4][0][2] = cube[3][2][0];
    cube[4][1][2] = cube[3][1][0];
    cube[4][2][2] = cube[3][0][0];

    cube[3][2][0] = cube[5][0][2];
    cube[3][1][0] = cube[5][1][2];
    cube[3][0][0] = cube[5][2][2];

    cube[5][0][2] = t1;
    cube[5][1][2] = t2;
    cube[5][2][2] = t3;

    rotatePrime( cube[2] );
}

void face( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[0][0][2];
    t2 = cube[0][1][2];
    t3 = cube[0][2][2];

    cube[0][0][2] = cube[5][0][0];
    cube[0][1][2] = cube[5][0][1];
    cube[0][2][2] = cube[5][0][2];

    cube[5][0][0] = cube[2][2][0];
    cube[5][0][1] = cube[2][1][0];
    cube[5][0][2] = cube[2][0][0];

    cube[2][2][0] = cube[4][2][2];
    cube[2][1][0] = cube[4][2][1];
    cube[2][0][0] = cube[4][2][0];

    cube[4][2][2] = t1;
    cube[4][2][1] = t2;
    cube[4][2][0] = t3;

    rotate( cube[1] );
}

void facePrime( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[0][0][2];
    t2 = cube[0][1][2];
    t3 = cube[0][2][2];

    cube[0][0][2] = cube[4][2][2];
    cube[0][1][2] = cube[4][2][1];
    cube[0][2][2] = cube[4][2][0];

    cube[4][2][2] = cube[2][2][0];
    cube[4][2][1] = cube[2][1][0];
    cube[4][2][0] = cube[2][0][0];

    cube[2][2][0] = cube[5][0][0];
    cube[2][1][0] = cube[5][0][1];
    cube[2][0][0] = cube[5][0][2];

    cube[5][0][0] = t1;
    cube[5][0][1] = t2;
    cube[5][0][2] = t3;

    rotatePrime( cube[1] );
}

void bottom( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[0][0][0];
    t2 = cube[0][1][0];
    t3 = cube[0][2][0];

    cube[0][0][0] = cube[4][0][2];
    cube[0][1][0] = cube[4][0][1];
    cube[0][2][0] = cube[4][0][0];

    cube[4][0][2] = cube[2][2][2];
    cube[4][0][1] = cube[2][1][2];
    cube[4][0][0] = cube[2][0][2];

    cube[2][2][2] = cube[5][2][0];
    cube[2][1][2] = cube[5][2][1];
    cube[2][0][2] = cube[5][2][2];

    cube[5][2][0] = t1;
    cube[5][2][1] = t2;
    cube[5][2][2] = t3;

    rotate( cube[3] );
}

void bottomPrime( int cube [6][3][3] )
{
    int t1, t2, t3;
    t1 = cube[0][0][0];
    t2 = cube[0][1][0];
    t3 = cube[0][2][0];

    cube[0][0][0] = cube[5][2][0];
    cube[0][1][0] = cube[5][2][1];
    cube[0][2][0] = cube[5][2][2];

    cube[5][2][0] = cube[2][2][2];
    cube[5][2][1] = cube[2][1][2];
    cube[5][2][2] = cube[2][0][2];

    cube[2][2][2] = cube[4][0][2];
    cube[2][1][2] = cube[4][0][1];
    cube[2][0][2] = cube[4][0][0];

    cube[4][0][2] = t1;
    cube[4][0][1] = t2;
    cube[4][0][0] = t3;

    rotatePrime( cube[3] );
}
