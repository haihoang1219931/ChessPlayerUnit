#ifndef FACEANIMATOR_H
#define FACEANIMATOR_H


typedef enum {
    FACE_HELLO,
    FACE_WAIT_SETUP,
    FACE_ENDGAME_LOST,
    FACE_ENDGAME_WIN,
    FACE_ENDGAME_DRAW,
} FaceType;
class FaceAnimator
{
public:
    FaceAnimator();
    FaceType faceType();
    void setFaceType(FaceType faceType);
    void loop();
    void animateFaceHello();
    void animateFaceWaitSetup();
    void animateFaceWin();
    void animateFaceLost();
    void animateFaceDraw();
private:
    FaceType m_faceType;
};

#endif // FACEANIMATOR_H
