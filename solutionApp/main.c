#include "cube.c"
#include <stdio.h>

int main()
{
    printf( "Hello World!\n" );

    int cube [6][3][3] = { { {0,0,0}, {0,0,0}, {0,0,0} }, { {1,1,1}, {1,1,1}, {1,1,1} }, { {2,2,2}, {2,2,2}, {2,2,2} }, { {3,3,3}, {3,3,3}, {3,3,3} }, { {4,4,4}, {4,4,4}, {4,4,4} }, { {5,5,5}, {5,5,5}, {5,5,5} } };

    displayCube( cube );
    solveCube( cube );

    return 0;
}
