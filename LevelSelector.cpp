#include "LevelSelector.h"

LevelSelector::LevelSelector()
{

}

int LevelSelector::chessLevel()
{
    return m_chessLevel;
}

void LevelSelector::setChessLevel(int chessLevel)
{
    m_chessLevel = chessLevel;
}

void LevelSelector::loop()
{
    switch (m_state) {
    case LEVEL_SHOW:{
        animateLevelShow();
    }
        break;
    case LEVEL_SWITCH:{
        animateLevelSwitch();
    }
        break;
    }
}

void LevelSelector::animateLevelShow()
{

}

void LevelSelector::animateLevelSwitch()
{

}
