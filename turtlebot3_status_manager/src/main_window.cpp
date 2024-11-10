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
}

void MainWindow::on_macro2_clicked()
{
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
