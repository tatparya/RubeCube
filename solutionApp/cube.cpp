#include "cube.h"

using namespace std;

void Cube::displayCube()
{
    int i,j;
    int r,c;

    r = 0;
    c = 0;

    for( i = 0; i < 3; i++ )
    {
        for( r = 0; r < 3; r++ )
        {
            for( j = 0; j < 4; j++ )
            {
                if( i == 0 && j == 1 )
                {
                    //  Print side 5
                    displayCubeRow( r, 4 );
                }

                else if( i == 1 && j == 0 )
                {
                    // Print side 1
                    displayCubeRow( r, 0 );
                }

                else if( i == 1 && j == 1 )
                {
                    // Print side 2
                    displayCubeRow( r, 1 );
                }

                else if( i == 1 && j == 2 )
                {
                    // Print side 3
                    displayCubeRow( r, 2 );
                }

                else if( i == 1 && j == 3 )
                {
                    // Print side 4
                    displayCubeRow( r, 3 );
                }

                else if( i == 2 && j == 1 )
                {
                    // Print side 6
                    displayCubeRow( r, 5 );
                }

                else
                {
                    //  Print blanks
                    displayCubeRow( r, -1 );
                }
            }

            cout << endl << endl;
        }
    }
}

void Cube::displayCubeRow( int row, int side )
{
    for( int col = 0; col < 3; col++ )
    {
        //  Check if blank or not
        if( side == -1 )
        {
            cout << "   ";
        }
        else
        {
            cout << " " << cube[side][row][col] << " ";
        }
    }
}
