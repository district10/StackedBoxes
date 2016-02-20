#ifndef STACKEDBOXES_H
#define STACKEDBOXES_H

#include <QWidget>
#include <QGraphicsScene>

class BigBox;
class QTimer;

namespace Ui {
class StackedBoxes;
}

class StackedBoxes : public QWidget
{
    Q_OBJECT

public:
    explicit StackedBoxes(QWidget *parent = 0);
    ~StackedBoxes();


private slots:
    void on_action1_clicked();
    void on_action2_clicked();
    void on_Action3_clicked();
    void on_action4_clicked();
    void on_action5_clicked();
    void on_action6_clicked();
    void on_action7_clicked();
    void on_action8_clicked();

    void showPosition();

private:
    Ui::StackedBoxes *ui;
    QGraphicsScene *scene;

    BigBox *bbR;
    BigBox *bbG;
    BigBox *bbB;

    QTimer *timer;
};

#endif // STACKEDBOXES_H
