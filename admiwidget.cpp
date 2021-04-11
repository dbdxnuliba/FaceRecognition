#include "admiwidget.h"
#include "ui_admiwidget.h"
#include <QDebug>
#include <QPainter>

AdmiWidget::AdmiWidget(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::AdmiWidget)
{
    ui->setupUi(this);
    mSettingWidget = new SettingWidget(this);     //设置页面
    mRecordWidget = new RecordWidget(this);       //打卡记录页面
    mFaceTrainWidget = new FaceTrainWidget(this);  //训练页面

    //使用stackedWidget添加以上所有页面
    ui->stackedWidget->addWidget(mSettingWidget);
    ui->stackedWidget->addWidget(mRecordWidget);
    ui->stackedWidget->addWidget(mFaceTrainWidget);
    ui->stackedWidget->setCurrentWidget(mSettingWidget);
}

AdmiWidget::~AdmiWidget()
{
    delete ui;
}

void AdmiWidget::setSqlDatabase(QSqlDatabase db)
{
    //设置数据库句柄
    mRecordWidget->setSqlDatabase(db);
}

void AdmiWidget::on_pushButton_setting_clicked()
{
    qDebug()<<"切换设置页面";
    ui->stackedWidget->setCurrentWidget(mSettingWidget);
}

void AdmiWidget::on_pushButton_face_clicked()
{
     qDebug()<<"切换人脸录入界面";
     ui->stackedWidget->setCurrentWidget(mFaceTrainWidget);
}

void AdmiWidget::on_pushButton_record_clicked()
{
    qDebug()<<"切换打卡记录界面";
    ui->stackedWidget->setCurrentWidget(mRecordWidget);
}

void AdmiWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//    painter.drawPixmap(rect(), QPixmap(":/images/bg.jpg"), QRect());
}

void AdmiWidget::on_pushButton_exit_clicked()
{
    //退出系统
    this->close();
}
