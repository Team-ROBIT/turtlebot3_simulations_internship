#include <QApplication>
#include <iostream>

#include "../include/turtlebot3_status_manager/main_window.hpp"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
