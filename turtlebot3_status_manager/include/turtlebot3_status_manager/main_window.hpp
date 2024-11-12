/**
 * @file /include/turtlebot3_status_manager/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date August 2024
 **/

#ifndef turtlebot3_status_manager_MAIN_WINDOW_H
#define turtlebot3_status_manager_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include "QIcon"
#include "qnode.hpp"
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <random>

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget * parent = nullptr);
  ~MainWindow();
  QNode * qnode;

public Q_SLOTS:
  void on_macro1_clicked();
  void on_macro2_clicked();
  void on_reload_clicked();
  void on_reload2_clicked();

  void updateLaserData();
  void updateCmdVelData();

private:
  Ui::MainWindowDesign * ui;
  void closeEvent(QCloseEvent * event);
};

#endif  // turtlebot3_status_manager_MAIN_WINDOW_H
