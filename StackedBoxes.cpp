#include "StackedBoxes.h"
#include "ui_StackedBoxes.h"
#include "BigBox.h"

#include <QTimer>
#include <QDebug>

StackedBoxes::StackedBoxes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StackedBoxes)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene( scene );
    ui->graphicsView->setSceneRect( -100, -100, 200, 200 );

    bbR = new BigBox( 100, 100, QColor( 255,   0,   0, 128 ) );
    bbG = new BigBox(  50,  50, QColor(   0, 255,   0, 128 ) );
    bbB = new BigBox(  25,  25, QColor(   0,   0, 255, 128 ), bbG );

    scene->addItem( bbR );
    scene->addItem( bbG );
    scene->addItem( bbB );

    timer = new QTimer;
    timer->start( 20 );
    connect( timer, SIGNAL(timeout()),
             this, SLOT(showPosition()) );
}

StackedBoxes::~StackedBoxes()
{
    delete ui;
}

void StackedBoxes::on_action1_clicked()
{
    bbB->setParentItem( bbR );
}

void StackedBoxes::on_action2_clicked()
{
    bbB->setParentItem( bbG );
}

void StackedBoxes::on_Action3_clicked()
{
    bbB->setParentItem( 0 );
}

void StackedBoxes::on_action4_clicked()
{
    bbG->setParentItem( bbR );
}

void StackedBoxes::on_action5_clicked()
{
    bbG->setParentItem( 0 );
}

void StackedBoxes::on_action6_clicked()
{
    bbR->setPos( 0, 0 );
}

void StackedBoxes::on_action7_clicked()
{
    bbG->setPos( 0, 0 );
}

void StackedBoxes::on_action8_clicked()
{
    bbB->setPos( 0, 0 );
}

void StackedBoxes::showPosition()
{
    ui->posp->setText( QString().sprintf(
        "%20s"
        "R: %+5.1f, %+5.1f, "
        "G: %+5.1f, %+5.1f, "
        "B: %+5.1f, %+5.1f.",
        "(@Parent)--",
        bbR->px, bbR->py,
        bbG->px, bbG->py,
        bbB->px, bbB->py ) );
    ui->poss->setText( QString().sprintf(
        "%20s"
        "R: %+5.1f, %+5.1f, "
        "G: %+5.1f, %+5.1f, "
        "B: %+5.1f, %+5.1f.",
        "(@Scene)--",
        bbR->sx, bbR->sy,
        bbG->sx, bbG->sy,
        bbB->sx, bbB->sy ) );
}
