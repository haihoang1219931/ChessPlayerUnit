#ifndef FACEITEM_H
#define FACEITEM_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QTimer>
#include <QDateTime>
#include <QQmlContext>
#include <QDebug>
#include <math.h>

class FaceItem : public QQuickPaintedItem
{
    Q_OBJECT
public:
    FaceItem(QQuickItem* parent = nullptr);
    void paint(QPainter* painter) override;

private:
    double m_phase;
};

#endif // FACEITEM_H
