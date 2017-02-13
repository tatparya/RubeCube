#include <stdio.h>

//  HELPER FUNCTION
void displayCube( int [6][3][3] );
void displayCubeRow( int [6][3][3], int, int );
void displayCorners( int * [2][4][3] );
void displayEdges( int * [3][4][2] );
void calcMove( int [6][3][3], char, int );

//  CUBE FUNCTIONALITY
void left( int [6][3][3] );
void leftPrime( int [6][3][3] );
void right( int [6][3][3] );
void rightPrime( int [6][3][3] );
void up( int [6][3][3] );
void upPrime( int [6][3][3] );
void down( int [6][3][3] );
void downPrime( int [6][3][3] );
void face( int [6][3][3] );
void facePrime( int [6][3][3] );
void bottom( int [6][3][3] );
void bottomPrime( int [6][3][3] );
void rotate( int [3][3] );
void rotatePrime( int [3][3] );

//  SOLUTION FUNCTION
void sovleCube( int [6][3][3] );
