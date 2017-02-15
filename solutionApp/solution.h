void solveCube( int [6][3][3] );

//  HELPER FUNCTIONS
void solveWhiteCross( int [6][3][3], int * [3][4][2] );
void sovleWhiteCorners( int [6][3][3], int * [2][4][3] );
void solveSecondLayer( int [6][3][3], int * [3][4][2] );
void solveOrangeCross( int [6][3][3], int * [3][4][2]  );
void permuteOrangeCross( int [6][3][3], int * [3][4][2] );
void solveOrangeCorners( int [6][3][3] );
void permuteOrangeCorners( int [6][3][3] );
