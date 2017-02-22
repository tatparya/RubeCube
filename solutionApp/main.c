#include <stdio.h>

#include "cube.c"
#include "solution.c"

int main()
{
    printf( "Hello World!\n" );
    /*

    int cube [6][3][3] = {
        {
            {1,2,3},
            {8,0,4},
            {7,6,5}
        },
        {
            {5,6,7},
            {4,1,8},
            {3,2,1}
        },
        {
            {1,8,7},
            {2,2,6},
            {3,4,5}
        },
        {
            {5,4,3},
            {6,3,2},
            {7,8,1}
        },
        {
            {1,2,3},
            {8,4,4},
            {7,6,5}
        },
        {
            {5,6,7},
            {4,5,8},
            {3,2,1}
        }
    };
    */

    int cube [6][3][3] = {
        {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        },
        {
            {1,1,1},
            {1,1,1},
            {1,1,1}
        },
        {
            {2,2,2},
            {2,2,2},
            {2,2,2}
        },
        {
            {3,3,3},
            {3,3,3},
            {3,3,3}
        },
        {
            {4,4,4},
            {4,4,4},
            {4,4,4}
        },
        {
            {5,5,5},
            {5,5,5},
            {5,5,5}
        }
    };

    int input = -1;
    while( input != 0 )
    {
        printf( "\nPlease enter chose a function:\n");
        printf( "0:\tExit\t");
        printf( "1:\tSolve Cube\t");
        printf( "2:\tDisplay Cube\t");
        printf( "3:\tRotate Face\t");
        printf( "4:\tRotate Prime\n");
        printf( "5:\tUp\t");
        printf( "6:\tUp Prime\n");
        printf( "7:\tDown\t");
        printf( "8:\tDown Prime\n");
        printf( "9:\tLeft\t");
        printf( "10:\tLeft Prime\n");
        printf( "11:\tRight\t");
        printf( "12:\tRight Prime\n");
        printf( "13:\tFace\t");
        printf( "14:\tFace Prime\n");
        printf( "15:\tBottom\t");
        printf( "16:\tBottom Prime\n");
        printf( "17:\tScramble Cube\n");

        scanf( "%d", &input );

        switch ( input ) {
            case 1:
                if( solveCube( cube ) != 0 )
                {
                    printf( "SOLUTION FAILED\n" );
                    return -1;
                }
                continue;
                break;
            case 2:
                break;
            case 3:
                rotate( cube[0] );
                break;
            case 4:
                rotatePrime( cube[0] );
                break;
            case 5:
                up( cube );
                break;
            case 6:
                upPrime( cube );
                break;
            case 7:
                down( cube );
                break;
            case 8:
                downPrime( cube );
                break;
            case 9:
                left( cube );
                break;
            case 10:
                leftPrime( cube );
                break;
            case 11:
                right( cube );
                break;
            case 12:
                rightPrime( cube );
                break;
            case 13:
                face( cube );
                break;
            case 14:
                facePrime( cube );
                break;
            case 15:
                bottom( cube );
                break;
            case 16:
                bottomPrime( cube );
                break;
            case 17:
                scrambleCube( cube, 20 );
                break;
            default:
                printf( "Invalid Option, please chose a different option!\n\n" );
                break;
        }

        displayCube( cube );
    }

    return 0;
}
