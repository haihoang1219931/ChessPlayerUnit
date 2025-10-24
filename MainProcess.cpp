#include "MainProcess.h"
#include "ChessController.h"
MainProcess::MainProcess(QThread *parent) :
    QThread(parent),
    m_stopped(false),
    m_thread(nullptr)

{
    memset(m_renderData,0,sizeof(m_renderData));
    m_mutex = new QMutex;
    m_pauseCond = new QWaitCondition;
    m_activeState = CPU_STATE_SHOW_FACE;
}

int MainProcess::activeState()
{
    return m_activeState;
}

void MainProcess::setActiveState(int activeState)
{
    if(m_activeState == activeState) return;
    m_activeState = activeState;
    Q_EMIT activeStateChanged();
}
MainProcess::~MainProcess()
{
    stopService();
    sleep(2);
}
void MainProcess::pause(bool pause){
    if(pause == true){
        m_mutex->lock();
        m_pause = true;
        m_mutex->unlock();
    }else{
        m_mutex->lock();
        m_pause = false;
        m_mutex->unlock();
        m_pauseCond->wakeAll();
    }
}
void MainProcess::setBlackSide(bool isBlack) {

}

void MainProcess::setOpponentMove(int startRow, int startCol, int stopRow, int stopCol, char promotePiece) {

}

void MainProcess::setNextMove(int startRow, int startCol, int stopRow, int stopCol, char promotePiece) {

}
void MainProcess::run() {
    while(!m_stopped) {
        m_mutex->lock();
        if(m_pause)
            m_pauseCond->wait(m_mutex); // in this place, your thread will stop to execute until someone calls resume
        m_mutex->unlock();
        switch (m_activeState) {
        case CPU_STATE_SHOW_FACE:{
            showFace();
        }
            break;
        case CPU_STATE_SELECT_LEVEL:{
            showLevel();
        }
            break;
        case CPU_STATE_PLAYING:{
            showPlaying();
        }
            break;
        }
    }
}
void MainProcess::showFace()
{
    //if receive button signal => switch to select level
}

void MainProcess::showLevel()
{
    //if receive button signal => switch to play
}

void MainProcess::showPlaying()
{
    // if playing finished => switch state to show face with result
}

void MainProcess::startService() {
    if(m_thread != nullptr)
        m_thread->start();
    else start();
}
void MainProcess::stopService() {
    m_stopped = true;
    m_thread->terminate();
}
void MainProcess::setRender(VideoRender* render)
{
    m_render = render;
}
void MainProcess::updateScreen() {

}

