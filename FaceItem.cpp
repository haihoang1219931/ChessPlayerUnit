#include "FaceItem.h"

FaceItem::FaceItem(QQuickItem* parent)
    : QQuickPaintedItem(parent), m_phase(0.0)
{
    // Enable continuous repaint from C++ side (vs using QQuickWindow::beforeRendering)
    setFlag(ItemHasContents, true);
    // Start timer to animate (60 FPS)
    QTimer* t = new QTimer(this);
    connect(t, &QTimer::timeout, this, [this](){
        // advance animation phase
        m_phase += 0.03;
        if (m_phase > 2*M_PI) m_phase -= 2*M_PI;
        update(); // schedule repaint
    });
    t->start(16);
}

void FaceItem::paint(QPainter* painter)
{
    // smooth rendering
    painter->setRenderHint(QPainter::Antialiasing, true);

    const QRectF r = boundingRect();
    const qreal w = r.width(), h = r.height();
    const qreal cx = r.center().x(), cy = r.center().y();
    const qreal radius = qMin(w, h) * 0.45;

    // background
    painter->fillRect(r, QColor("#f0f8ff"));

    // face circle
    painter->setBrush(QColor(255, 224, 128));
    painter->setPen(QPen(QColor(80, 50, 20), 2));
    painter->drawEllipse(QPointF(cx, cy), radius, radius);

    // eyes: animate vertical "blink" using phase
    qreal blink = (std::sin(m_phase * 2.0) + 1.0) / 2.0; // 0..1
    qreal eyeOpen = 0.4 + 0.6*blink; // 0.4..1.0

    qreal eyeOffsetX = radius * 0.4;
    qreal eyeOffsetY = -radius * 0.15;
    qreal eyeRY = radius * 0.15 * eyeOpen;
    qreal eyeRX = radius * 0.12;

    painter->setBrush(Qt::white);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(QPointF(cx - eyeOffsetX, cy + eyeOffsetY), eyeRX, eyeRY);
    painter->drawEllipse(QPointF(cx + eyeOffsetX, cy + eyeOffsetY), eyeRX, eyeRY);

    // pupils (follow a slow circular motion)
    qreal pupilRadius = radius * 0.05;
    qreal pupilMotion = 0.18 * radius;
    qreal px = std::cos(m_phase) * pupilMotion;
    qreal py = std::sin(m_phase*1.3) * pupilMotion * 0.5;
    painter->setBrush(Qt::black);
    painter->drawEllipse(QPointF(cx - eyeOffsetX + px, cy + eyeOffsetY + py), pupilRadius, pupilRadius);
    painter->drawEllipse(QPointF(cx + eyeOffsetX + px, cy + eyeOffsetY + py), pupilRadius, pupilRadius);

    // mouth: simple smiling arc that opens/closes
    qreal smile = 0.5 + 0.5*std::sin(m_phase*0.8);
    qreal mouthW = radius * 0.7;
    qreal mouthH = radius * 0.25 * (0.6 + smile*0.8);
    QRectF mouthRect(cx - mouthW/2, cy + radius*0.18, mouthW, mouthH);
    painter->setPen(QPen(QColor(80,40,20), 4, Qt::SolidLine, Qt::RoundCap));
    painter->setBrush(Qt::NoBrush);
    painter->drawArc(mouthRect, 0 * 16, 180 * 16); // semi-circle (smile)

    // small blush
    painter->setBrush(QColor(255, 120, 120, 120));
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(QPointF(cx - radius*0.6, cy + radius*0.05), radius*0.12, radius*0.07);
    painter->drawEllipse(QPointF(cx + radius*0.6, cy + radius*0.05), radius*0.12, radius*0.07);
}
