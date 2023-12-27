#include "floatingball.h"
#include "./ui_floatingball.h"

#include <QPainter>
#include <QBitmap>

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

    // setWindowOpacity(0.2);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint);

    // this->setAttribute(Qt::WA_TranslucentBackground, true);

    // 创建圆形控件
    circleLabel = new QLabel(this);
    // 设置圆形控件的大小
    circleLabel->resize(100, 100);
    // 设置圆形控件的位置为窗口的中心
    circleLabel->move(width() / 2 - circleLabel->width() / 2, height() / 2 - circleLabel->height() / 2);
    // 设置圆形控件的背景颜色为红色
    circleLabel->setStyleSheet("background-color: red;");
    // 设置圆形控件的遮罩为圆形
    circleLabel->setMask(QRegion(0, 0, 100, 100, QRegion::Ellipse));
}

FloatingBall::~FloatingBall()
{
    delete ui;
}

// FloatingBall::paintEvent(QPaintEvent *event)
// {
//     // 创建一个画家对象
//     QPainter painter(this);
//     // 设置抗锯齿
//     painter.setRenderHint(QPainter::Antialiasing, true);
//     // 设置画笔颜色为黑色
//     painter.setPen(Qt::black);
//     // 绘制一个圆形边框
//     painter.drawEllipse(circleLabel->geometry());
// }
