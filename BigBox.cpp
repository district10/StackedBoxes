#include "BigBox.h"
#include <QGraphicsSceneMouseEvent>

BigBox::BigBox( int width, int height, QColor color, QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , _width( width )
    , _height( height )
    , _color( color )
{
    setFlags( ItemIsMovable
            | ItemIsSelectable
            | ItemSendsGeometryChanges );
    setCacheMode( DeviceCoordinateCache );
    setAcceptsHoverEvents( true );
}

QRectF BigBox::boundingRect() const
{
    const static int padding = 8;
    return QRectF( -_width/2-padding, -_height/2-padding,
                   +_width  +padding, +_height  +padding );
}

QPainterPath BigBox::shape() const
{
    QPainterPath path;
    path.addRect( -_width/2, -_height/2, _width, _height );
    return path;
}

void BigBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( widget );

    QPointF s = mapToScene( pos() );
    sx = s.x();
    sy = s.y();

    QPointF p = mapToParent( pos() );
    px = p.x();
    py = p.y();

    painter->setBrush( _color );
    painter->drawRect( QRectF( -_width/2, -_height/2, _width, _height ) );
}

void BigBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}

void BigBox::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

void BigBox::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}
