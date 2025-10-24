#include "FaceAnimator.h"

FaceAnimator::FaceAnimator()
{

}

FaceType FaceAnimator::faceType()
{
    return m_faceType;
}

void FaceAnimator::setFaceType(FaceType faceType)
{
    m_faceType = faceType;
}
void FaceAnimator::loop(){
    switch (m_faceType) {
    case FACE_HELLO:{
        animateFaceHello();
    }
        break;
    case FACE_WAIT_SETUP:{
        animateFaceWaitSetup();
    }
        break;
    case FACE_ENDGAME_WIN:{
        animateFaceWin();
    }
        break;
    case FACE_ENDGAME_LOST:{
        animateFaceLost();
    }
        break;
    case FACE_ENDGAME_DRAW:{
        animateFaceDraw();
    }
        break;
    }
}

void FaceAnimator::animateFaceHello()
{

}

void FaceAnimator::animateFaceWaitSetup()
{

}

void FaceAnimator::animateFaceWin()
{

}

void FaceAnimator::animateFaceLost()
{

}

void FaceAnimator::animateFaceDraw()
{

}
