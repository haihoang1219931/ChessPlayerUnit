#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include "VideoDisplay/VideoRender.h"

class MainProcess : public QThread
{
    Q_OBJECT
    Q_PROPERTY(int activeState READ activeState WRITE setActiveState NOTIFY activeStateChanged)
public:
    explicit MainProcess(QThread *parent = nullptr);
    ~MainProcess();
    int activeState();
    void setActiveState(int activeState);

Q_SIGNALS:
    void readyToUpdate();
    void activeStateChanged();

public Q_SLOTS:
    void run() override;
    void startService();
    void stopService();
    void setRender(VideoRender* render);
    void updateScreen();
    void pause(bool pause);
    void setBlackSide(bool isBlack);
    void setOpponentMove(int startRow, int startCol, int stopRow, int stopCol, char promotePiece);
    void setNextMove(int startRow, int startCol, int stopRow, int stopCol, char promotePiece);
    void showFace();
    void showLevel();
    void showPlaying();
private:
    unsigned char m_renderData[93110400]; // 1920x1080 I420
    bool m_stopped;
    QMutex *m_mutex;
    QWaitCondition* m_pauseCond;
    QThread* m_thread;
    bool m_pause = false;
    VideoRender* m_render = nullptr;
    int m_activeState;
};

#endif // MAINPROCESS_H
