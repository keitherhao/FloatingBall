#include "floatingball.h"
#include "./ui_floatingball.h"

#include <QPainter>
#include <QBitmap>
#include <QVector>

#include <QMouseEvent>
#include <QWheelEvent>
#include <QWheelEvent>
#include <QMessageBox>

#include <QGestureEvent>
#include <QMouseEvent>

FloatingBall::FloatingBall(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint)
    , ui(new Ui::FloatingBall)
{
    ui->setupUi(this);
    // 设置窗口的标志
    // 使用Qt::CustomizeWindowHint标志来启用自定义窗口，这会去掉所有的默认按钮。
    // 使用Qt::WindowTitleHint标志来显示窗口的标题栏，这会显示窗口的标题和图标。
    // 使用Qt::WindowCloseButtonHint标志来显示窗口的关闭按钮，这会显示一个可以关闭窗口的按钮
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setFixedSize(200, 200); // 设置窗口的大小

    // 全透明
    // setWindowOpacity(0.2);
    // 窗体透明
    setAttribute(Qt::WA_TranslucentBackground, true);
    // 隐去窗体边框
    setWindowFlags(Qt::FramelessWindowHint);

    // this->setAttribute(Qt::WA_TranslucentBackground, true);

    // 创建圆形控件
    circleLabel[0] = new QLabel(this);
    // 设置圆形控件的大小
    circleLabel[0]->resize(100, 100);
    // 设置圆形控件的位置为窗口的中心
    circleLabel[0]->move(width() / 2 - circleLabel[0]->width() / 2, height() / 2 - circleLabel[0]->height() / 2);
    // 设置圆形控件的背景颜色为X色
    circleLabel[0]->setStyleSheet("background-color: blue;");
    // 设置圆形控件的遮罩为圆形
    circleLabel[0]->setMask(QRegion(0, 0, 100, 100, QRegion::Ellipse));


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
    // // 创建一个画家对象
    // QPainter painter(this);
    // // 设置抗锯齿
    // painter.setRenderHint(QPainter::Antialiasing, true);
    // // 设置画笔颜色为黑色
    // painter.setPen(Qt::black);
    // // 绘制一个圆形边框
    // painter.drawEllipse(circleLabel[0]->geometry());

    // for (auto ball : balls) {
    //     // 获取悬浮球的中心点和半径
    //     QPointF center = ball.first;
    //     qreal radius = ball.second;

    //     // 绘制一个椭圆，作为悬浮球
    //     painter.drawEllipse(center, radius, radius);
    // }


    for (int i = 0; i < Balls.size(); i++) {
        // // 设置圆形控件的大小
        // circleLabel[0]->resize(100, 100);
        // // 设置圆形控件的位置为窗口的中心
        // circleLabel[0]->move(i * 10, i * 10);
        // // 设置圆形控件的背景颜色为X色
        // Balls.takeAt(i).setStyleSheet("background-color: blue;");
        // // 设置圆形控件的遮罩为圆形
        // Balls.takeAt(i).setMask(QRegion(0, 0, 100, 100, QRegion::Ellipse));
    }
}


// 重写鼠标进入事件
void FloatingBall::enterEvent(QEnterEvent *event)
{
    // 您可以在这里添加您想要的功能，例如改变按钮的颜色
    FloatingBall::circleLabel[0]->setStyleSheet("background-color: yellow");
    qDebug() << "enterEvent";
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::enterEvent(event);
}

// 重写鼠标离开事件
void FloatingBall::leaveEvent(QEvent *event)
{
    // 您可以在这里添加您想要的功能，例如恢复按钮的颜色
    this->circleLabel[0]->setStyleSheet("background-color: green");
    qDebug() << "leaveEvent";
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::leaveEvent(event);
}

static FloatingBall *newBall;
// 重写鼠标按下事件
void FloatingBall::mousePressEvent(QMouseEvent *event)
{
    // 您可以在这里添加您想要的功能，例如判断鼠标的按钮和位置
    if (event->button() == Qt::LeftButton) // 如果是左键按下
    {
        qDebug() << "Left button pressed at" << event->pos();
        // FloatingBall _sub;
        // _sub.show();
        // 创建一个新的悬浮球的对象，并设置其父窗口为主窗口
        // newBall = new FloatingBall();
        // // 设置新的悬浮球的位置和大小，使其中心与鼠标点击的位置重合
        // newBall->setGeometry(pos().x() + 100, pos().y() + 100, 200, 200);
        // // 显示新的悬浮球
        // newBall->show();

        // 创建圆形控件
        // FloatingBall::circleLabel[1] = new QLabel(this);
        // // 设置圆形控件的大小
        // FloatingBall::circleLabel[1]->resize(100, 100);
        // // 设置圆形控件的位置为窗口的中心
        // FloatingBall::circleLabel[1]->move(0, 0);
        // // 设置圆形控件的背景颜色为X色
        // FloatingBall::circleLabel[1]->setStyleSheet("background-color: blue;");
        // // 设置圆形控件的遮罩为圆形
        // FloatingBall::circleLabel[1]->setMask(QRegion(0, 0, 100, 100, QRegion::Ellipse));


        // 获取鼠标的位置
        QPointF pos = event->pos();
        // 生成一个随机的半径，范围为10到50
        qreal radius = rand() % 41 + 10;
        // 将鼠标的位置和半径作为一个对添加到悬浮球的向量中
        balls.append(qMakePair(pos, radius));
        // QLabel tmp = new QLabel(this);
        // Balls.append(tmp);
        // 更新窗口的绘图
        this->update();

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
    //
    qDebug() << "Mouse released";
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::mouseReleaseEvent(event);
}

// 重写鼠标移动事件
void FloatingBall::mouseMoveEvent(QMouseEvent *event)
{
    // 拖动鼠标可以移动小球
    if (event->buttons() & Qt::LeftButton) {
        // qDebug() << "event->pos() = " << event->globalPosition().toPoint();
        this->move(event->globalPosition().toPoint() - QPoint(100,100));
        event->accept();
    }
}

// 重写鼠标双击事件
void FloatingBall::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 您可以在这里添加您想要的功能，例如弹出一个对话框
    // QMessageBox::information(this, "Double Click", "You double clicked the button");
    // 调用基类的函数，以保留默认的行为
    // FloatingBall::mouseDoubleClickEvent(event);
    static bool IsShow = false;
    if (IsShow == false) {
        IsShow = true;
        // 创建8个新的悬浮窗口
        for (int i = 0; i < 8; ++i) {
            FloatingBall *aBall = new FloatingBall;
            aBall->move(event->globalPosition().toPoint() + QPoint(100 * cos(i * M_PI / 4), 100 * sin(i * M_PI / 4)) - QPoint(100,100));
            BallsList.append(aBall);
            aBall->show();
        }
    } else if (IsShow == true) {
        // 清除8个悬浮窗口
        IsShow = false;
        for (FloatingBall *aBall : BallsList) {
            aBall->close();
        }
        BallsList.clear(); // 清空列表
    }
}

// 重写鼠标滚轮事件
void FloatingBall::wheelEvent(QWheelEvent *event)
{
    // 通过滚轮上下滚动调整浮球大小
    QSize BallSzie = circleLabel[0]->size();

    if (event->angleDelta().y() > 0) // 如果滚轮向上滚动
    {
        qDebug() << "向上滚动";
        BallSzie = BallSzie + QSize(10,10);
    }
    else // 如果滚轮向下滚动
    {
        qDebug() << "向下滚动";
        BallSzie = BallSzie - QSize(10,10);
    }
    // qDebug() << circleLabel[0]->pos();
    // qDebug() << event->globalPosition().toPoint();
    // qDebug() << FloatingBall::pos();
    // qDebug() << QPoint(BallSzie.width(), BallSzie.height());
    // 设置圆形控件的位置 使圆心和鼠标点重合
    // QPoint BallPoint = event->globalPosition().toPoint() - FloatingBall::pos() - QPoint(BallSzie.width()/2, BallSzie.height()/2);
    // 设置圆形控件的位置 保持在窗口的正中心，也就是位置不改变
    QPoint BallPoint = QPoint(width() / 2 - BallSzie.width() / 2, height() / 2 - BallSzie.height() / 2);
    // qDebug() << BallPoint;
    circleLabel[0]->move(BallPoint);
    // 重新调整大小
    circleLabel[0]->resize(BallSzie);
    // 设置圆形控件的遮罩为圆形
    circleLabel[0]->setMask(QRegion(0, 0, BallSzie.width(), BallSzie.height(), QRegion::Ellipse));
    update();
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
