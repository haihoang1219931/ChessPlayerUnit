#ifndef PROJECTTYPES_H
#define PROJECTTYPES_H

#define CHESS_ROW 8
#define CHESS_COL 8
typedef enum {
    CPU_STATE_SHOW_FACE,
    CPU_STATE_SELECT_LEVEL,
    CPU_STATE_PLAYING,
} CPUActiveState;

typedef struct {
    int startRow;
    int startCol;
    int stopRow;
    int stopCol;
    bool castles;
    bool enpassant;
    char promotePiece;
} ChessMove;
#endif // PROJECTTYPES_H
