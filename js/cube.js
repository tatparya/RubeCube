//  ------------- CUBE SPECS -------------

var invSide = [[-1,-1,-1],[-1,-1,-1],[-1,-1,-1]];
var side1 = [[0,0,0],[0,0,0],[0,0,0]];
var side2 = [[1,1,1],[1,1,1],[1,1,1]];
var side3 = [[2,2,2],[2,2,2],[2,2,2]];
var side4 = [[3,3,3],[3,3,3],[3,3,3]];
var side5 = [[4,4,4],[4,4,4],[4,4,4]];
var side6 = [[5,5,5],[5,5,5],[5,5,5]];

var cube = [ side1, side2, side3, side4, side5, side6 ];

var edges =
[
    [
        [ side5[0][1], side4[0][1] ],
        [ side5[1][2], side3[0][1] ],
        [ side5[2][1], side2[0][1] ],
        [ side5[1][0], side1[0][1] ]
    ],
    [
        [ side1[1][0], side4[1][2] ],
        [ side2[1][0], side1[1][2] ],
        [ side3[1][0], side2[1][2] ],
        [ side4[1][0], side3[1][2] ]
    ],
    [
        [ side6[0][1], side2[2][1] ],
        [ side6[1][2], side3[2][1] ],
        [ side6[2][1], side4[2][1] ],
        [ side6[1][0], side1[2][1] ]
    ]
];

var corners =
[
    [
        [ side6[0][0], side1[0][0], side4[0][2] ],
        [ side6[0][2], side4[0][0], side3[0][2] ],
        [ side6[2][2], side3[0][0], side2[0][2] ],
        [ side6[2][0], side2[0][0], side1[0][2] ]
    ],
    [
        [ side5[0][0], side1[2][2], side2[2][0] ],
        [ side5[0][2], side2[2][2], side3[2][0] ],
        [ side5[2][2], side3[2][2], side4[2][0] ],
        [ side5[2][0], side4[2][2], side1[2][0] ]
    ]
];

//  ------------- HELPER FUNCTIONS -------------

var setColor = function( obj, color ){
    switch( color ){
        case 5: obj.style.backgroundColor = "#d50000"; // red;
                break;
        case 2: obj.style.backgroundColor = "#2962ff"; // blue;
                break;
        case 0: obj.style.backgroundColor = "#00c853"; // green;
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

var getRandomMove = function(){
    var random = Math.floor( ( Math.random() * 100 ) ) % 6;
    console.log( random );
    return random;
}

var randomMove = function(){
    move = getRandomMove();
    switch (move) {
        case 0:
            up();
            break;
        case 1:
            down();
            break;
        case 2:
            left();
            break;
        case 3:
            right();
            break;
        case 4:
            face();
            break;
        case 5:
            bottom();
            break;
        default:

    }
}

var scrambleCube = function(){
    for( x = 0; x < 30; x++ )
    {
        setTimeout( randomMove, 100 * x );
    }
}

var calcMove = function( move, side ){
    if( move == "up" ){
        switch( side ){
            case 1: up();
                    break;
            case 2: up();
                    break;
            case 3: up();
                    break;
            case 4: up();
                    break;
            case 5: bottom();
                    break;
            case 6: face();
                    break;
        }
    }
    else if( move == "upPrime" ){
        switch( side ){
            case 1: upPrime();
                    break;
            case 2: upPrime();
                    break;
            case 3: upPrime();
                    break;
            case 4: upPrime();
                    break;
            case 5: bottomPrime();
                    break;
            case 6: facePrime();
                    break;
        }
    }
    else if( move == "down" ){
        switch( side ){
            case 1: down();
                    break;
            case 2: down();
                    break;
            case 3: down();
                    break;
            case 4: down();
                    break;
            case 5: face();
                    break;
            case 6: bottom();
                    break;
        }
    }
    else if( move == "downPrime" ){
        switch( side ){
            case 1: downPrime();
                    break;
            case 2: downPrime();
                    break;
            case 3: downPrime();
                    break;
            case 4: downPrime();
                    break;
            case 5: facePrime();
                    break;
            case 6: bottomPrime();
                    break;
        }
    }
    else if( move == "left" ){
        switch( side ){
            case 1: bottom();
                    break;
            case 2: left();
                    break;
            case 3: face();
                    break;
            case 4: right();
                    break;
            case 5: left();
                    break;
            case 6: left();
                    break;
        }
    }
    else if( move == "leftPrime" ){
        switch( side ){
            case 1: bottomPrime();
                    break;
            case 2: leftPrime();
                    break;
            case 3: facePrime();
                    break;
            case 4: rightPrime();
                    break;
            case 5: leftPrime();
                    break;
            case 6: leftPrime();
                    break;
        }
    }
    else if( move == "right" ){
        switch( side ){
            case 1: face();
                    break;
            case 2: right();
                    break;
            case 3: bottom();
                    break;
            case 4: left();
                    break;
            case 5: right();
                    break;
            case 6: right();
                    break;
        }
    }
    else if( move == "rightPrime" ){
        switch( side ){
            case 1: facePrime();
                    break;
            case 2: rightPrime();
                    break;
            case 3: bottomPrime();
                    break;
            case 4: leftPrime();
                    break;
            case 5: rightPrime();
                    break;
            case 6: rightPrime();
                    break;
        }
    }
    else if( move == "face" ){
        switch( side ){
            case 1: left();
                    break;
            case 2: face();
                    break;
            case 3: right();
                    break;
            case 4: bottom();
                    break;
            case 5: up();
                    break;
            case 6: down();
                    break;
        }
    }
    else if( move == "facePrime" ){
        switch( side ){
            case 1: leftPrime();
                    break;
            case 2: facePrime();
                    break;
            case 3: rightPrime();
                    break;
            case 4: bottomPrime();
                    break;
            case 5: upPrime();
                    break;
            case 6: downPrime();
                    break;
        }
    }
    else if( move == "bottom" ){
        switch( side ){
            case 1: right();
                    break;
            case 2: bottom();
                    break;
            case 3: left();
                    break;
            case 4: face();
                    break;
            case 5: down();
                    break;
            case 6: up();
                    break;
        }
    }
    else if( move == "bottomPrime" ){
        switch( side ){
            case 1: rightPrime();
                    break;
            case 2: bottomPrime();
                    break;
            case 3: leftPrime();
                    break;
            case 4: facePrime();
                    break;
            case 5: downPrime();
                    break;
            case 6: upPrime();
                    break;
        }
    }
}

//  ------------- CUBE SOLVE -------------

var checkFirstCross = function(){
    if(
        side5[0][1] == side5[1][1] && side1[1][2] == side1[1][1]    &&
        side5[1][0] == side5[1][1] && side5[2][1] == side5[1][1]    &&
        side5[1][2] == side5[1][1] && side3[0][1] == side3[1][1]    &&
        side5[2][1] == side5[1][1] && side6[0][1] == side6[1][1]
    ){
        console.log( "First Cross Complete!" );
        return true;
    }
    else {
        return false;
    }
}

var buildFirstCross = function(){
    var y = 0;
    while( !checkFirstCross() && y < 10 )
    {
        console.log( "Move : ", y );
        y += 1;

        //  Check bottom edges


    }
}

var findEdgeInBottom = function(){
    val = side5[1][1];
    side = side6;

    while(  side[0][1] == val ||
            side[1][2] == val ||
            side[2][1] == val ||
            side[1][0] == val )
    {
        if( side[0][1] == val )
        {
            console.log( "orange found" );
            //  Calculate turns
            switch( side2[2][1] ){
                case 0:
                    calcMove( "facePrime", 6 );
                    calcMove( "left", 6 );
                    calcMove( "left", 6 );
                    break;
                case 1:
                    calcMove( "up", 6 );
                    calcMove( "up", 6 );
                    break;
                case 2:
                    calcMove( "face", 6 );
                    calcMove( "right", 6 );
                    calcMove( "right", 6 );
                    break;
                case 3:
                    calcMove( "face", 6 );
                    calcMove( "face", 6 );
                    calcMove( "down", 6 );
                    calcMove( "down", 6 );
                    break;
            }
        }

        if( side[1][0] == val )
        {
            console.log( "orange found" );
            //  Calculate turns
            switch( side1[2][1] ){
                case 3:
                    calcMove( "facePrime", 6 );
                    calcMove( "down", 6 );
                    calcMove( "down", 6 );
                    break;
                case 0:
                    calcMove( "left", 6 );
                    calcMove( "left", 6 );
                    break;
                case 1:
                    calcMove( "face", 6 );
                    calcMove( "up", 6 );
                    calcMove( "up", 6 );
                    break;
                case 2:
                    calcMove( "face", 6 );
                    calcMove( "face", 6 );
                    calcMove( "right", 6 );
                    calcMove( "right", 6 );
                    break;
            }
        }

        if( side[1][2] == val )
        {
            console.log( "orange found" );
            //  Calculate turns
            switch( side3[2][1] ){
                case 1:
                    calcMove( "facePrime", 6 );
                    calcMove( "up", 6 );
                    calcMove( "up", 6 );
                    break;
                case 2:
                    calcMove( "right", 6 );
                    calcMove( "right", 6 );
                    break;
                case 3:
                    calcMove( "face", 6 );
                    calcMove( "down", 6 );
                    calcMove( "down", 6 );
                    break;
                case 0:
                    calcMove( "face", 6 );
                    calcMove( "face", 6 );
                    calcMove( "left", 6 );
                    calcMove( "left", 6 );
                    break;
            }
        }

        if( side[2][1] == val )
        {
            console.log( "orange found" );
            //  Calculate turns
            switch( side4[2][1] ){
                case 2:
                    calcMove( "facePrime", 6 );
                    calcMove( "right", 6 );
                    calcMove( "right", 6 );
                    break;
                case 3:
                    calcMove( "down", 6 );
                    calcMove( "down", 6 );
                    break;
                case 0:
                    calcMove( "face", 6 );
                    calcMove( "left", 6 );
                    calcMove( "left", 6 );
                    break;
                case 1:
                    calcMove( "face", 6 );
                    calcMove( "face", 6 );
                    calcMove( "up", 6 );
                    calcMove( "up", 6 );
                    break;
            }
        }
    }
}

var findEdgeBlock = function( side, val, right, left, up, down ){
    x = -1;
    y = -1;

    if( side[0][1] == val )
    {
        x = 0;
        y = 1;
    }

    else if( side[1][2] == val )
    {
        x = 1;
        y = 2;
    }

    else if( side[2][1] == val )
    {
        x = 2;
        y = 1;
    }

    else if( side[1][0] == val )
    {
        x = 1;
        y = 0;
    }

    return {x:x,y:y};
}

var solveCube = function(){
    buildFirstCross()
}

//  ------------- INIT CUBE -------------

console.log( cube );
initCube();

//  ------------- CUBE MOVES -------------

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

var rotateFacePrime = function( side ){
    for( i = 0; i < 2; i++ )
    {
        temp = side[0][i];
        side[0][i] = side[i][2];
        side[i][2] = side[2][2-i];
        side[2][2-i] = side[2-i][0];
        side[2-i][0] = temp;
    }
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

var upPrime = function(){
    console.log("UPPrime");
    temp = side4[0];
    side4[0] = side3[0];
    side3[0] = side2[0];
    side2[0] = side1[0];
    side1[0] = temp;
    rotateFacePrime( side5 );
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

var downPrime = function(){
    console.log("DOWNPrime");
    temp = side4[2];
    side4[2] = side1[2];
    side1[2] = side2[2];
    side2[2] = side3[2];
    side3[2] = temp;
    rotateFacePrime( side6 );
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

var leftPrime = function(){
    console.log("LEFTPrime");
    temp = [side2[0][0], side2[1][0], side2[2][0]];

    side2[0][0] = side6[0][0];
    side2[1][0] = side6[1][0];
    side2[2][0] = side6[2][0];

    side6[0][0] = side4[2][2];
    side6[1][0] = side4[1][2];
    side6[2][0] = side4[0][2];

    side4[2][2] = side5[0][0];
    side4[1][2] = side5[1][0];
    side4[0][2] = side5[2][0];

    side5[0][0] = temp[0];
    side5[1][0] = temp[1];
    side5[2][0] = temp[2];
    rotateFacePrime( side1 );
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

var rightPrime = function(){
    console.log("RIGHTPrime");
    temp = [side2[0][2], side2[1][2], side2[2][2]];

    side2[0][2] = side5[0][2];
    side2[1][2] = side5[1][2];
    side2[2][2] = side5[2][2];

    side5[0][2] = side4[2][0];
    side5[1][2] = side4[1][0];
    side5[2][2] = side4[0][0];

    side4[2][0] = side6[0][2];
    side4[1][0] = side6[1][2];
    side4[0][0] = side6[2][2];

    side6[0][2] = temp[0];
    side6[1][2] = temp[1];
    side6[2][2] = temp[2];
    rotateFacePrime( side3 );
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

var facePrime = function(){
    console.log("FACEPrime");
    temp = side5[2];
    side5[2] = [side3[0][0], side3[1][0], side3[2][0]];

    side3[0][0] = side6[0][2];
    side3[1][0] = side6[0][1];
    side3[2][0] = side6[0][0];

    side6[0] = [side1[0][2],side1[1][2], side1[2][2]];

    side1[0][2] = temp[2];
    side1[1][2] = temp[1];
    side1[2][2] = temp[0];
    rotateFacePrime( side2 );
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

var bottomPrime = function(){
    console.log("BOTTOMPrime");
    temp = side5[0];
    side5[0] = [side1[2][0],side1[1][0], side1[0][0]];

    side1[0][0] = side6[2][2];
    side1[1][0] = side6[2][1];
    side1[2][0] = side6[2][0];

    side6[2] = [side3[2][2], side3[1][2], side3[0][2]];

    side3[0][2] = temp[2];
    side3[1][2] = temp[1];
    side3[2][2] = temp[0];
    rotateFacePrime( side4 );
    refreshCube();
}
