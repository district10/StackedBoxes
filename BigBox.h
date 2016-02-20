#ifndef BIGBOX_H
#define BIGBOX_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;
QT_END_NAMESPACE

class BigBox : public QGraphicsItem
{
public:
    BigBox( int width, int height, QColor color, QGraphicsItem *parent = 0 );
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    qreal _height;
    qreal _width;
    QColor _color;

public:
    qreal px, py;
    qreal sx, sy;
};

#endif // BIGBOX_H
