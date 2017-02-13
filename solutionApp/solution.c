#include "solution.h"

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

void solveWhiteCross( int cube [6][3][3] )
{

}

void sovleWhiteCorners( int cube [6][3][3] )
{

}

void solveSecondLayer( int cube [6][3][3] )
{

}

void solveOrangeCross( int cube [6][3][3] )
{

}

void permuteOrangeCross( int cube [6][3][3] )
{

}

void solveOrangeCorners( int cube [6][3][3] )
{

}

void permuteOrangeCorners( int cube [6][3][3] )
{

}
