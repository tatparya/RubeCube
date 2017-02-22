int solveCube( int [6][3][3] );

//  HELPER FUNCTIONS
int solveWhiteCross( int [6][3][3], int * [3][4][2] );
int sovleWhiteCorners( int [6][3][3], int * [2][4][3] );
int solveSecondLayer( int [6][3][3], int * [3][4][2] );
int solveOrangeCross( int [6][3][3], int * [3][4][2]  );
int permuteOrangeCross( int [6][3][3], int * [3][4][2] );
int solveOrangeCorners( int [6][3][3], int * [2][4][3] );
int permuteOrangeCorners( int [6][3][3], int * [2][4][3]  );
int orangeCornersDone( int  [6][3][3], int * [2][4][3] );
