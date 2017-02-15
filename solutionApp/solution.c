#include "solution.h"

void solveCube( int cube[6][3][3] )
{
    printf( "Starting Solving!\n" );

    // printf( "Setting Edges\n" );
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
    // displayEdges( edges );

    // printf( "Setting Corners\n" );
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
    // displayCorners( corners );

    printf( "Solving White Cross\n" );
    solveWhiteCross( cube, edges );

    displayCube( cube );

    printf( "Solving White Corners\n" );
    sovleWhiteCorners( cube, corners );

    displayCube( cube );

    printf( "Solved!!\n" );
}

void solveWhiteCross( int cube [6][3][3], int * edges [3][4][2] )
{
    int count = 0;
    int dst = -1;
    int move = 0;
    int layer = -1;
    int found = 0;

    while( count < 4 )
    {
        count = 0;
        //  Check if pieces in right place
        for( int side = 0; side < 4; side++ )
        {
            if( *edges[0][side][0] == 4 )
            {
                dst = *edges[0][side][1];
                if( dst == side )
                {
                    count++;
                }
            }
        }

        //  Check if solved
        if( count == 4 )
        {
            continue;
        }

        //  Layer 2
        layer = 2;
        for( int side = 0; side < 4; side++ )
        {
            found = 0;
            if( *edges[layer][side][0] == 4 )
            {
                printf( "(Cross) White found at 0: Layer %d, Side %d\n", layer, side );
                //  Calculate dst and move
                dst = *edges[layer][side][1];
                found = 1;
            }
            else if( *edges[layer][side][1] == 4 )
            {
                printf( "(Cross) White found at 1: Layer %d, Side %d\n", layer, side );
                //  Calculate dst and move
                dst = *edges[layer][side][0];
                found = 1;
            }

            if( found )
            {
                move = ( dst - side ) % 4;
                move = ( move == -3 ) ? 1 : move;
                move = ( move == 3 ) ? -1 : move;

                printf( "M: %d, D: %d\n", move, dst );

                //  Get pieve below right spot
                if( move == -1 )
                {
                    calcMove( cube, 'D', side );
                }
                else if( move == 1 )
                {
                    calcMove( cube, 'd', side );
                }
                else if( move == -2 || move == 2 )
                {
                    calcMove( cube, 'd', side );
                    calcMove( cube, 'd', side );
                }

                //  Get into right spot
                if( *edges[layer][side][0] == 4 )
                {
                    calcMove( cube, 'f', dst );
                    calcMove( cube, 'f', dst );
                }
                else if( *edges[layer][side][1] == 4 )
                {
                    calcMove( cube, 'F', dst );
                    calcMove( cube, 'R', dst );
                    calcMove( cube, 'D', dst );
                    calcMove( cube, 'r', dst );
                    calcMove( cube, 'f', dst );
                    calcMove( cube, 'f', dst );
                }
            }
        }

        //  Layer 1
        layer = 1;
        for( int side = 0; side < 4; side++ )
        {
            if( *edges[layer][side][0] == 4 )
            {
                calcMove( cube, 'l', side );
                calcMove( cube, 'd', side );
                calcMove( cube, 'L', side );
            }
            if( *edges[layer][side][1] == 4 )
            {
                calcMove( cube, 'F', side );
                calcMove( cube, 'd', side );
                calcMove( cube, 'f', side );
            }
        }

        //  Layer 0
        layer = 0;
        for( int side = 0; side < 4; side++ )
        {
            if( *edges[layer][side][0] == 4 || *edges[layer][side][1] == 4 )
            {
                //  Check if in right spot
                if( *edges[0][side][0] == 4 )
                {
                    dst = *edges[0][side][1];
                    if( dst == side )
                    {
                        continue;
                    }
                }

                calcMove( cube, 'f', side );
                calcMove( cube, 'f', side );
            }
        }
    }


}

void sovleWhiteCorners( int cube [6][3][3], int * corners [2][4][3] )
{
    int done = 0;
    int count = 0;
    int dst = -1;
    int move = 0;
    int op = -1;
    int layer = 1;

    while( count < 4 )
    {
        //  Check if corners solved
        count = 0;
        for( int side = 0; side < 4; side++ )
        {
            //  Check if corners in place
            if( *corners[0][side][0] == 4 )
            {
                dst = * corners[0][side][1];
                if( dst == side )
                {
                    count++;
                }
            }
        }

        //  Break if done
        if( count == 4 )
        {
            continue;
        }

        printf( "Done setting %d corners.", count );

        // Layer 1
        layer = 1;
        for( int side = 0; side < 4; side++ )
        {
            //  White on orange face
            if( *corners[layer][side][0] == 4 )
            {
                printf( "White found at 1: Layer %d, Side %d\n", layer, side );

                dst = *corners[layer][side][2];
                move = ( dst - side ) % 4;
                move = ( move == 3 ) ? -1 : move;
                move = ( move == -3 ) ? 1 : move;

                printf( "M: %d, D: %d\n", move, dst );

                //  Set below right spot
                if( move == -1 )
                {
                    calcMove( cube, 'D', side );
                }
                else if( move == 1 )
                {
                    calcMove( cube, 'd', side );
                }
                else if( move == 2 || move == -2 )
                {
                    calcMove( cube, 'd', side );
                    calcMove( cube, 'd', side );
                }

                //  Get into right spot
                calcMove( cube, 'R', dst );
                calcMove( cube, 'd', dst );
                calcMove( cube, 'd', dst );
                calcMove( cube, 'r', dst );
                calcMove( cube, 'd', dst );
                calcMove( cube, 'R', dst );
                calcMove( cube, 'D', dst );
                calcMove( cube, 'r', dst );
            }

            else if( *corners[layer][side][1] == 4 )
            {
                //  White on left side
                printf( "White found at 2: Layer %d, Side %d\n", layer, side );

                dst = *corners[layer][side][0];
                op = *corners[layer][side][2];
                move = ( dst - side ) % 4;
                move = ( move == 3 ) ? -1 : move;
                move = ( move == -3 ) ? 1 : move;

                printf( "M: %d, D: %d OP: %d\n", move, dst, op );

                if( move == -1 )
                {
                    calcMove( cube, 'D', side );
                }
                else if( move == 1 )
                {
                    calcMove( cube, 'd', side );
                }
                else if( move == 2 || move == -2 )
                {
                    calcMove( cube, 'd', side );
                    calcMove( cube, 'd', side );
                }

                calcMove( cube, 'l', op );
                calcMove( cube, 'd', op );
                calcMove( cube, 'L', op );
            }
            else if( *corners[layer][side][2] == 4 )
            {
                printf( "White found at 3: Layer %d, Side %d\n", layer, side );

                dst = *corners[layer][side][1];
                op = *corners[layer][side][0];
                move = ( dst - side ) % 4;
                move = ( move == 3 ) ? -1 : move;
                move = ( move == -3 ) ? 1 : move;

                printf( "M: %d, D: %d\n", move, dst );

                if( move == -1 )
                {
                    calcMove( cube, 'D', side );
                }
                else if( move == 1 )
                {
                    calcMove( cube, 'd', side );
                }
                else if( move == 2 || move == -2 )
                {
                    calcMove( cube, 'd', side );
                    calcMove( cube, 'd', side );
                }

                calcMove( cube, 'F', op );
                calcMove( cube, 'D', op );
                calcMove( cube, 'f', op );
            }

        }

        //  Layer 0
        layer = 0;
        for( int side = 0; side < 4; side++ )
        {
            //  Check if piece in place
            if( *corners[layer][side][0] == 4 )
            {
                dst = *corners[0][side][1];
                if( dst == side )
                {
                    continue;
                }
            }

            //  Bring piece to layer 1
            calcMove( cube, 'R', side );
            calcMove( cube, 'd', side );
            calcMove( cube, 'r', side );
        }
    }
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
