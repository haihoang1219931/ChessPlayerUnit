import QtQuick 2.0
import "qrc:/ChessSupport.js" as ChessSupport
Item {
    id: root
    property var chessClicked
    property bool isWhiteSide: true
    property var possibleMoves: []
    Grid {
        id: grid
        columns: 8
        rows: 8
        rotation: isWhiteSide?0:180
        Repeater {
            id: repeater
            delegate: Rectangle {
                width: root.width / grid.columns
                height: root.height / grid.rows
                color: (modelData.row+modelData.col)%2 !== 0? "#90652C" : "#DEB887"
                Rectangle {
                    anchors.fill: parent
                    color: typeof chessClicked !== 'undefined' &&
                           chessClicked.col === modelData.col &&
                           chessClicked.row === modelData.row &&
                           chessClicked.clicked?"green":"transparent"
                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            console.log("Clicked")
                            var chessModel = ChessSupport.createChessBoardModel();
//                            if(possibleMoves.length > 0)
//                            {
//                                possibleMoves.forEach((item)=> {
//                                    if(item.row === modelData.row &&
//                                       item.col === modelData.col) {
//                                        repeaterChessPiece.model =
//                                        ChessSupport.updateMove(repeaterChessPiece.model,
//                                                          chessClicked.row, chessClicked.col,
//                                                          modelData.row, modelData.col);
//                                    };
//                                });
//                                possibleMoves = []
//                            }
                            if(ChessSupport.isPiece(repeaterChessPiece.model[index])) {
                                chessClicked = {row:modelData.row,col:modelData.col,piece:repeaterChessPiece.model[index],clicked:true};
                                possibleMoves = ChessSupport.validMove(repeaterChessPiece.model,modelData.row,modelData.col);
                                possibleMoves.forEach((item)=> {
                                    chessModel[item.row*8+item.col] = item;
                                });
                                repeater.model = chessModel;
                            }
                        }
                    }
                }
                Rectangle {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: "transparent"
                    border.color: modelData.suggest?"gray":"transparent"
                    border.width: 10
                    width: typeof chessClicked !== 'undefined' &&
                            ChessSupport.isOppositeSide(repeaterChessPiece.model[index],chessClicked.piece)?parent.width:parent.width/4
                    height: typeof chessClicked !== 'undefined' &&
                            ChessSupport.isOppositeSide(repeaterChessPiece.model[index],chessClicked.piece)?parent.height:parent.width/4
                    radius: width/2
                }
            }
        }
    }
    Grid {
        id: gridChessPiece
        columns: 8
        rows: 8
        rotation: isWhiteSide?0:180
        Repeater {
            id: repeaterChessPiece
            delegate: Item {
                width: root.width / grid.columns
                height: root.height / grid.rows
                Text {
                    rotation: isWhiteSide?0:180
                    text: ChessSupport.charCode(modelData)
                    anchors.fill: parent
                    font.pointSize : root.width / grid.columns * 0.6
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }

    Component.onCompleted: {
        repeater.model = ChessSupport.createChessBoardModel();
        repeaterChessPiece.model = ChessSupport.createChessPiecesModel();
    }
}
