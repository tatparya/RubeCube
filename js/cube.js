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
        case 0: obj.style.backgroundColor = "#d50000"; // red;
                break;
        case 1: obj.style.backgroundColor = "#2962ff"; // blue;
                break;
        case 2: obj.style.backgroundColor = "#00c853"; // green;
                break;
        case 3: obj.style.backgroundColor = "#fafafa"; // grey;
                break;
        case 4: obj.style.backgroundColor = "#ff6d00"; // orange;
                break;
        case 5: obj.style.backgroundColor = "#ffd600"; // yellow;
                break;
        default:
                break;
    }
}

var printSide = function( side, sideObj ){
    //  Create three rows
    console.log( "Printing cube" );
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
        console.log( itr );
        printSide( invSide, invSides[itr] );
    }

    //  Populate sides
    for( itr = 0; itr < 6; itr++ ){
        //  Get cube side html object
        console.log( "side" + (itr + 1) );
        var sideObj = document.getElementById( "side" + (itr + 1) );
        printSide( cube[itr], sideObj );
    }
}

console.log( cube );
initCube();

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
