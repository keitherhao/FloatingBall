#include "floatingball.h"
#include "./ui_floatingball.h"

#include <QPainter>
#include <QBitmap>

#include <QMouseEvent>
#include <QWheelEvent>
#include <QWheelEvent>
#include <QMessageBox>

#include <QGestureEvent>

FloatingBall::FloatingBall(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FloatingBall)
{
    ui->setupUi(this);
    // 设置窗口的标志
    // 使用Qt::CustomizeWindowHint标志来启用自定义窗口，这会去掉所有的默认按钮。
    // 使用Qt::WindowTitleHint标志来显示窗口的标题栏，这会显示窗口的标题和图标。
    // 使用Qt::WindowCloseButtonHint标志来显示窗口的关闭按钮，这会显示一个可以关闭窗口的按钮
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    // 全透明
    // setWindowOpacity(0.2);
    // 窗体透明
    setAttribute(Qt::WA_TranslucentBackground, true);
    // 隐去窗体边框
    setWindowFlags(Qt::FramelessWindowHint);

    // this->setAttribute(Qt::WA_TranslucentBackground, true);

    // 创建圆形控件
    circleLabel = new QLabel(this);
    // 设置圆形控件的大小
    circleLabel->resize(100, 100);
    // 设置圆形控件的位置为窗口的中心
    circleLabel->move(width() / 2 - circleLabel->width() / 2, height() / 2 - circleLabel->height() / 2);
    // 设置圆形控件的背景颜色为X色
    circleLabel->setStyleSheet("background-color: blue;");
    // 设置圆形控件的遮罩为圆形
    circleLabel->setMask(QRegion(0, 0, 100, 100, QRegion::Ellipse));

    // 注册需要识别的手势类型
    this->grabGesture(Qt::PinchGesture);
    this->grabGesture(Qt::PanGesture);
    this->grabGesture(Qt::SwipeGesture);
}

FloatingBall::~FloatingBall()
{
    delete ui;
}

void FloatingBall::paintEvent(QPaintEvent *event)
{
    // 创建一个画家对象
    QPainter painter(this);
    // 设置抗锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 设置画笔颜色为黑色
    painter.setPen(Qt::black);
    // 绘制一个圆形边框
    painter.drawEllipse(circleLabel->geometry());
}


// 重写鼠标进入事件
void FloatingBall::enterEvent(QEnterEvent *event)
{
    // 您可以在这里添加您想要的功能，例如改变按钮的颜色
    FloatingBall::circleLabel->setStyleSheet("background-color: yellow");
    qDebug() << "enterEvent";
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::enterEvent(event);
}

// 重写鼠标离开事件
void FloatingBall::leaveEvent(QEvent *event)
{
    // 您可以在这里添加您想要的功能，例如恢复按钮的颜色
    this->circleLabel->setStyleSheet("background-color: green");
    qDebug() << "leaveEvent";
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::leaveEvent(event);
}

// 重写鼠标按下事件
void FloatingBall::mousePressEvent(QMouseEvent *event)
{
    // 您可以在这里添加您想要的功能，例如判断鼠标的按钮和位置
    if (event->button() == Qt::LeftButton) // 如果是左键按下
    {
        qDebug() << "Left button pressed at" << event->pos();
    }
    else if (event->button() == Qt::RightButton) // 如果是右键按下
    {
        qDebug() << "Right button pressed at" << event->pos();
    }
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::mousePressEvent(event);
}

// 重写鼠标释放事件
void FloatingBall::mouseReleaseEvent(QMouseEvent *event)
{
    // 您可以在这里添加您想要的功能，例如打印一条信息
    qDebug() << "Mouse released";
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::mouseReleaseEvent(event);
}

// 重写鼠标移动事件
void FloatingBall::mouseMoveEvent(QMouseEvent *event)
{
    // 您可以在这里添加您想要的功能，例如跟随鼠标移动
    // this->move(event->globalPosition() - QPoint(this->width() / 2, this->height() / 2));
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::mouseMoveEvent(event);
}

// 重写鼠标双击事件
void FloatingBall::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 您可以在这里添加您想要的功能，例如弹出一个对话框
    QMessageBox::information(this, "Double Click", "You double clicked the button");
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::mouseDoubleClickEvent(event);
}

// 重写鼠标滚轮事件
void FloatingBall::wheelEvent(QWheelEvent *event)
{
    // 您可以在这里添加您想要的功能，例如改变按钮的大小
    // if (event->delta() > 0) // 如果滚轮向上滚动
    // {
    //     this->resize(this->width() + 10, this->height() + 10);
    // }
    // else // 如果滚轮向下滚动
    // {
    //     this->resize(this->width() - 10, this->height() - 10);
    // }
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::wheelEvent(event);
}


// 重写手势事件函数
bool FloatingBall::gestureEvent(QGestureEvent *event)
{
    // 您可以在这里添加您想要的功能，例如判断手势的类型，并调用相应的处理函数
    if (QGesture *pinch = event->gesture(Qt::PinchGesture))
        pinchTriggered(static_cast<QPinchGesture *>(pinch));
    if (QGesture *pan = event->gesture(Qt::PanGesture))
        panTriggered(static_cast<QPanGesture *>(pan));
    if (QGesture *swipe = event->gesture(Qt::SwipeGesture))
        swipeTriggered(static_cast<QSwipeGesture *>(swipe));
    return true;
}

// 处理缩放手势
void FloatingBall::pinchTriggered(QPinchGesture *gesture)
{
    // 您可以在这里添加您想要的功能，例如根据手势的状态和缩放比例，改变标签的大小
    QPinchGesture::ChangeFlags changeFlags = gesture->changeFlags();
    if (changeFlags & QPinchGesture::ScaleFactorChanged) {
        qreal value = gesture->totalScaleFactor();
        this->resize(this->width() * value, this->height() * value);
    }
}

// 处理移动手势
void FloatingBall::panTriggered(QPanGesture *gesture)
{
    // 您可以在这里添加您想要的功能，例如根据手势的状态和偏移量，改变标签的位置
    Qt::GestureState state = gesture->state();
    QPoint m_lastPoint;
    if (state == Qt::GestureStarted) {
        // 记录手势开始时的位置
        m_lastPoint = gesture->hotSpot().toPoint();
    } else if (state == Qt::GestureUpdated) {
        // 计算手势的偏移量
        QPoint delta = gesture->hotSpot().toPoint() - m_lastPoint;
        // 更新标签的位置
        this->move(this->pos() + delta);
        // 更新上次的位置
        m_lastPoint = gesture->hotSpot().toPoint();
    }
}

// 处理滑动手势
void FloatingBall::swipeTriggered(QSwipeGesture *gesture)
{
    // 您可以在这里添加您想要的功能，例如根据手势的方向，改变标签的颜色
    if (gesture->state() == Qt::GestureFinished) {
        // 获取手势的方向
        QSwipeGesture::SwipeDirection direction = gesture->horizontalDirection();
        // 根据方向设置标签的颜色
        if (direction == QSwipeGesture::Left)
            this->setStyleSheet("background-color: red");
        else if (direction == QSwipeGesture::Right)
            this->setStyleSheet("background-color: green");
    }
}
