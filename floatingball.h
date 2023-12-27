#ifndef FLOATINGBALL_H
#define FLOATINGBALL_H

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class FloatingBall;
}
QT_END_NAMESPACE

class FloatingBall : public QWidget
{
    Q_OBJECT

public:
    FloatingBall(QWidget *parent = nullptr);
    ~FloatingBall();

// protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::FloatingBall *ui;

    // 圆形控件
    QLabel *circleLabel;
};
#endif // FLOATINGBALL_H
