//  Init cube
var invSide = [[-1,-1,-1],[-1,-1,-1],[-1,-1,-1]];
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

var setColor = function( obj, color ){
    switch( color ){
        case 5: obj.style.backgroundColor = "#d50000"; // red;
                break;
        case 0: obj.style.backgroundColor = "#2962ff"; // blue;
                break;
        case 2: obj.style.backgroundColor = "#00c853"; // green;
                break;
        case 1: obj.style.backgroundColor = "#fafafa"; // grey;
                break;
        case 4: obj.style.backgroundColor = "#ff6d00"; // orange;
                break;
        case 3: obj.style.backgroundColor = "#ffd600"; // yellow;
                break;
        default:
                break;
    }
}

var printSide = function( side, sideObj ){
    //  Clear side
    while( sideObj.firstChild ){
        sideObj.removeChild( sideObj.firstChild );
    }
    //  Create three rows
    for( i = 0; i < 3; i++ ){
        var cubeRow = document.createElement( "div" );
        cubeRow.className = "cube-row";
        //  Create three blocks
        for( j = 0; j < 3; j++ ){
            var cubeBlock = document.createElement( "div" );
            cubeBlock.className = "cube-block";
            //  Set block color
            setColor( cubeBlock, side[i][j] );
            //  Append block
            cubeRow.appendChild( cubeBlock );
        }
        //  Append row
        sideObj.appendChild( cubeRow );
    }
}

var initCube = function(){
    //  Populate invalid sides
    var invSides = document.getElementsByClassName( "invSide" );
    for( itr = 0; itr < invSides.length; itr++ ){
        printSide( invSide, invSides[itr] );
    }

    //  Populate sides
    for( itr = 0; itr < 6; itr++ ){
        //  Get cube side html object
        var sideObj = document.getElementById( "side" + (itr + 1) );
        printSide( cube[itr], sideObj );
    }
}

var refreshCube = function(){
    //  Populate sides
    for( itr = 0; itr < 6; itr++ ){
        //  Get cube side html object
        var sideObj = document.getElementById( "side" + (itr + 1) );
        printSide( cube[itr], sideObj );
    }
}

console.log( cube );
initCube();

//  ------------- CUBE MOVES -------------

//  UP
var moveU = function( side ){

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
            break;
        case 5:
        case 6:
            temp = side5[2];
            side5[2] = [side1[2][2],side1[1][2], side1[0][2]];
            side1[0][2] = side6[0][0];
            side1[1][2] = side6[0][1];
            side1[2][2] = side6[0][2];
            side6[0] = [side3[2][0], side3[1][0], side3[0][0]];
            side3[0][0] = temp[0];
            side3[1][0] = temp[1];
            side3[2][0] = temp[2];
            rotateFace( side2 );
            break;

    }
    refreshCube();
}

var up = function(){
    console.log("UP");
    temp = side1[0];
    side1[0] = side2[0];
    side2[0] = side3[0];
    side3[0] = side4[0];
    side4[0] = temp;
    rotateFace( side5 );
    refreshCube();
}

var left = function(){
    console.log("LEFT");
    temp = [side2[0][0], side2[1][0], side2[2][0]];
    side2[0][0] = side5[0][0];
    side2[1][0] = side5[1][0];
    side2[2][0] = side5[2][0];
    side5[0][0] = side4[2][2];
    side5[1][0] = side4[1][2];
    side5[2][0] = side4[0][2];
    side4[2][2] = side6[0][0];
    side4[1][2] = side6[1][0];
    side4[0][2] = side6[2][0];
    side6[0][0] = temp[0];
    side6[1][0] = temp[1];
    side6[2][0] = temp[2];
    rotateFace( side1 );
    refreshCube();
}

var right = function(){
    console.log("RIGHT");
    temp = [side2[0][2], side2[1][2], side2[2][2]];
    side2[0][2] = side6[0][2];
    side2[1][2] = side6[1][2];
    side2[2][2] = side6[2][2];
    side6[0][2] = side4[2][0];
    side6[1][2] = side4[1][0];
    side6[2][2] = side4[0][0];
    side4[2][0] = side5[0][2];
    side4[1][0] = side5[1][2];
    side4[0][0] = side5[2][2];
    side5[0][2] = temp[0];
    side5[1][2] = temp[1];
    side5[2][2] = temp[2];
    rotateFace( side3 );
    refreshCube();
}

var down = function(){
    console.log("DOWN");
    temp = side1[2];
    side1[2] = side4[2];
    side4[2] = side3[2];
    side3[2] = side2[2];
    side2[2] = temp;
    rotateFace( side6 );
    refreshCube();
}

var face = function(){
    console.log("FACE");
    temp = side5[2];
    side5[2] = [side1[2][2],side1[1][2], side1[0][2]];
    side1[0][2] = side6[0][0];
    side1[1][2] = side6[0][1];
    side1[2][2] = side6[0][2];
    side6[0] = [side3[2][0], side3[1][0], side3[0][0]];
    side3[0][0] = temp[0];
    side3[1][0] = temp[1];
    side3[2][0] = temp[2];
    rotateFace( side2 );
    refreshCube();
}

var bottom = function(){
    console.log("BOTTOM");
    temp = side5[0];
    side5[0] = [side3[0][2],side3[1][2], side3[2][2]];
    side3[0][2] = side6[2][2];
    side3[1][2] = side6[2][1];
    side3[2][2] = side6[2][0];
    side6[2] = [side1[0][0], side1[1][0], side1[2][0]];
    side1[0][0] = temp[2];
    side1[1][0] = temp[1];
    side1[2][0] = temp[0];
    rotateFace( side4 );
    refreshCube();
}
