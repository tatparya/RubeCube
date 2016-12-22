//  Init cube
var side1 = [[0,0,0],[0,0,0],[0,0,0]];
var side2 = [[1,1,1],[1,1,1],[1,1,1]];
var side3 = [[2,2,2],[2,2,2],[2,2,2]];
var side4 = [[3,3,3],[3,3,3],[3,3,3]];
var side5 = [[4,4,4],[4,4,4],[4,4,4]];
var side6 = [[5,5,5],[5,5,5],[5,5,5]];

var cube = [ side1, side2, side3, side4, side5, side6 ];

var rotateFace = function( side ){
    for( i = 0; i < 2; i++ )
    {
        temp = side[0][i];
        side[0][i] = side[2-i][0];
        side[2-i][0] = side[2][2-i];
        side[2][2-i] = side[i][2];
        side[i][2] = temp;
    }
}

var printSide = function( side, sideObj ){
    var sideDiv = document.createElement( "div" );
}

console.log( cube );

var moveU = function( cube, side ){

    switch( side ){
        case 1:
        case 2:
        case 3:
        case 4:
            temp = side1[0];
            side1[0] = side2[0];
            side2[0] = side3[0];
            side3[0] = side4[0];
            side4[0] = temp;
            rotateFace( side5 );
        case 5: break;
        case 6: break;

    }
}
