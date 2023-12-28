#ifndef FLOATINGBALL_H
#define FLOATINGBALL_H

#include <QWidget>
#include <QLabel>

#include <QGestureEvent>

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

protected:
    void paintEvent(QPaintEvent *event) override;
    // 重写鼠标进入事件
    void enterEvent(QEnterEvent *event) override;
    // 重写鼠标离开事件
    void leaveEvent(QEvent *event) override;
    // 重写鼠标按下事件
    void mousePressEvent(QMouseEvent *event) override;
    // 重写鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event) override;
    // 重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event) override;
    // 重写鼠标双击事件
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    // 重写鼠标滚轮事件
    void wheelEvent(QWheelEvent *event) override;


    // 重写手势事件函数
    bool gestureEvent(QGestureEvent *event);
    // 处理缩放手势
    void pinchTriggered(QPinchGesture *gesture);
    // 处理移动手势
    void panTriggered(QPanGesture *gesture);
    // 处理滑动手势
    void swipeTriggered(QSwipeGesture *gesture);
private:
    Ui::FloatingBall *ui;

    // 圆形控件
    QLabel *circleLabel[16];
    QVector<QLabel>Balls;

    // 声明一个成员变量，用于存储悬浮球的位置和半径
    QVector<QPair<QPointF, qreal>> balls;

    QPoint m_dragPosition;

    QList<FloatingBall *> BallsList; // 用于保存悬浮窗口的列表
};
#endif // FLOATINGBALL_H
