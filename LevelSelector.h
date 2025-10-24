#ifndef LEVELSELECTOR_H
#define LEVELSELECTOR_H

typedef enum {
    LEVEL_SHOW,
    LEVEL_SWITCH,
} LevelSelectorState;
class LevelSelector
{
public:
    LevelSelector();
    int chessLevel();
    void setChessLevel(int chessLevel);
    void loop();
    void animateLevelShow();
    void animateLevelSwitch();
private:
    int m_chessLevel;
    int m_state;
};

#endif // LEVELSELECTOR_H
