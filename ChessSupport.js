var NOPIECE = 0;
var WHITE = 1;
var BLACK = 2;

var W_KING = 3;
var W_QUEEN = 4;
var W_ROOK = 5;
var W_BISHOP = 6;
var W_KNIGHT = 7;
var W_PAWN = 8;

var B_KING = 9;
var B_QUEEN = 10;
var B_ROOK = 11;
var B_BISHOP = 12;
var B_KNIGHT = 13;
var B_PAWN = 14;

function createChessBoardModel() {
    var chessBoardModel = [];
    for(var row =0; row <8; row ++) {
        for(var col =0; col <8; col ++){
            chessBoardModel[row*8+col] = {row:row,col:col,suggest:false}
        }
    }
    return chessBoardModel;
}
function createChessPiecesModel(){
    var chessPieceModel = [
        B_ROOK,  B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK,
        B_PAWN,  B_PAWN,   B_PAWN,   B_PAWN,  B_PAWN,  B_PAWN,   B_PAWN,   B_PAWN,
        NOPIECE, NOPIECE,  NOPIECE,  NOPIECE, NOPIECE, NOPIECE,  NOPIECE,  NOPIECE,
        NOPIECE, NOPIECE,  NOPIECE,  NOPIECE, NOPIECE, NOPIECE,  NOPIECE,  NOPIECE,
        NOPIECE, NOPIECE,  NOPIECE,  NOPIECE, NOPIECE, NOPIECE,  NOPIECE,  NOPIECE,
        NOPIECE, NOPIECE,  NOPIECE,  NOPIECE, NOPIECE, NOPIECE,  NOPIECE,  NOPIECE,
        W_PAWN,  W_PAWN,   W_PAWN,   W_PAWN,  W_PAWN,  W_PAWN,   W_PAWN,   W_PAWN,
        W_ROOK,  W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK,
    ];
    chessPieceModel[4*8+2] = B_ROOK;
    chessPieceModel[4*8+3] = B_ROOK;
    chessPieceModel[5*8+4] = B_ROOK;
    chessPieceModel[5*8+5] = W_ROOK;
    return chessPieceModel;
}
function chessSide(chessPiece) {
    if(chessPiece >= W_KING && chessPiece <= W_PAWN) {
        return WHITE;
    } else if(chessPiece >= B_KING && chessPiece <= B_PAWN) {
        return BLACK;
    } else {
        return NOPIECE;
    }
}
function isPiece(chessPiece) {
    return chessSide(chessPiece) !== NOPIECE;
}

function charCode(chessPiece) {
    if(chessPiece >= W_KING && chessPiece <= W_PAWN) {
        return String.fromCharCode(9811 + 0 * 6 + chessPiece-W_KING+1);
    } else if(chessPiece >= B_KING && chessPiece <= B_PAWN) {
        return String.fromCharCode(9811 + 1 * 6 + chessPiece-B_KING+1);
    } else {
        return "";
    }
}
function isOppositeSide(firstPiece,secondPiece) {
    var firtSide = chessSide(firstPiece);
    var secondSide = chessSide(secondPiece);
    if(firtSide === NOPIECE || secondSide === NOPIECE) {
        return false;
    } else return firtSide !== secondSide;
}
function validMove(chessPieceModel,_row,_col) {
    var possibleMoves=[];
    var chessPiece = chessPieceModel[_row*8+_col]
    switch(chessPiece) {
    case W_PAWN: {
        if(chessSide(chessPieceModel[(_row-1)*8+_col])=== NOPIECE)
            possibleMoves.push({row:_row-1,col:_col,suggest:true});
        if(_row === 6 &&
            chessSide(chessPieceModel[(_row-1)*8+_col])=== NOPIECE &&
            chessSide(chessPieceModel[(_row-2)*8+_col])=== NOPIECE)
            possibleMoves.push({row:_row-2,col:_col,suggest:true});
        if(_col+1 < 8 &&
            chessSide(chessPieceModel[(_row-1)*8+_col+1])=== BLACK)
            possibleMoves.push({row:_row-1,col:_col+1,suggest:true});
        if(_col-1 >= 0 &&
            chessSide(chessPieceModel[(_row-1)*8+_col-1])=== BLACK)
            possibleMoves.push({row:_row-1,col:_col-1,suggest:true});
        break;
    }
    case B_PAWN: {
        break;
    }
    }
    return possibleMoves;
}
function updateMove(chessPieceModel, startRow, startCol, stopRow, stopCol) {
    chessPieceModel[stopRow * 8 + stopCol] = chessPieceModel[startRow * 8 + startCol];
    chessPieceModel[startRow * 8 + startCol] = NOPIECE;
    return chessPieceModel;
}
