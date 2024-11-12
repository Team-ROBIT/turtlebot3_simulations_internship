/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date August 2024
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include "../include/turtlebot3_status_manager/main_window.hpp"

MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent), ui(new Ui::MainWindowDesign)
{
  ui->setupUi(this);

  QIcon icon("://ros-icon.png");
  this->setWindowIcon(icon);

  qnode = new QNode();

  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> dis(0, 99);
  int random_integer = dis(gen);

  if (random_integer % 2 == 0) {
    qnode->direction_str = "left";
    ui->direction->setText("Left");
  } else {
    qnode->direction_str = "right";
    ui->direction->setText("Right");
  }
  qnode->direction = true;

  std::random_device rd2;
  std::mt19937 gen2(rd2());

  std::uniform_int_distribution<int> dis2(0, 99);
  int random_integer2 = dis2(gen2);

  if (random_integer2 % 3 == 0) {
    qnode->number_int = 1;
    ui->number->setText("1");
  } else if (random_integer2 % 3 == 1) {
    qnode->number_int = 2;
    ui->number->setText("2");
  } else {
    qnode->number_int = 3;
    ui->number->setText("3");
  }
  qnode->number = true;

  QObject::connect(qnode, SIGNAL(rosShutDown()), this, SLOT(close()));
  QObject::connect(qnode, SIGNAL(updateLaserData()), this, SLOT(updateLaserData()));
  QObject::connect(qnode, SIGNAL(updateCmdVelData()), this, SLOT(updateCmdVelData()));
}

void MainWindow::closeEvent(QCloseEvent * event)
{
  QMainWindow::closeEvent(event);
}

void MainWindow::on_macro1_clicked()
{
  system("ros2 service call /reset_world std_srvs/srv/Empty");
}

void MainWindow::on_macro2_clicked()
{
}

void MainWindow::on_reload_clicked()
{
  qnode->direction = false;
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> dis(0, 99);
  int random_integer = dis(gen);

  if (random_integer % 2 == 0) {
    qnode->direction_str = "left";
    ui->direction->setText("Left");
  } else {
    qnode->direction_str = "right";
    ui->direction->setText("Right");
  }
  qnode->direction = true;
}

void MainWindow::on_reload2_clicked()
{
  qnode->number = false;
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> dis(0, 99);
  int random_integer = dis(gen);

  if (random_integer % 3 == 0) {
    qnode->number_int = 1;
    ui->number->setText("1");
  } else if (random_integer % 3 == 1) {
    qnode->number_int = 2;
    ui->number->setText("2");
  } else {
    qnode->number_int = 3;
    ui->number->setText("3");
  }
  qnode->number = true;
}

void MainWindow::updateLaserData()
{
  ui->scan->setText(QString::number(qnode->laser_data[ui->scan_num->value()]));
}

void MainWindow::updateCmdVelData()
{
  ui->linear_x->setText(QString::number(qnode->cmd_vel_data[0]));
  ui->linear_y->setText(QString::number(qnode->cmd_vel_data[1]));
  ui->linear_z->setText(QString::number(qnode->cmd_vel_data[2]));
  ui->angular_x->setText(QString::number(qnode->cmd_vel_data[3]));
  ui->angular_y->setText(QString::number(qnode->cmd_vel_data[4]));
  ui->angular_z->setText(QString::number(qnode->cmd_vel_data[5]));
}

MainWindow::~MainWindow()
{
  delete ui;
}
