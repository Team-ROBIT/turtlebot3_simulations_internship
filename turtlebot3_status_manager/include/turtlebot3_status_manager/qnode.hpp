/**
 * @file /include/turtlebot3_status_manager/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef turtlebot3_status_manager_QNODE_HPP_
#define turtlebot3_status_manager_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/
#ifndef Q_MOC_RUN
#include <rclcpp/rclcpp.hpp>
#endif
#include <geometry_msgs/msg/twist.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>

#include <QThread>

/*****************************************************************************
** Class
*****************************************************************************/
class QNode : public QThread
{
  Q_OBJECT
public:
  QNode();
  ~QNode();
  std::vector<float> laser_data;
  std::vector<float> cmd_vel_data;

  bool direction = false;
  std::string direction_str;

  bool number = false;
  int number_int = 0;

protected:
  void run();

private:
  std::shared_ptr<rclcpp::Node> node;

  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_laser;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_cmd_vel;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_direction;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_number;

  void laserCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
  void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);

Q_SIGNALS:
  void rosShutDown();
  void updateLaserData();
  void updateCmdVelData();
};

#endif /* turtlebot3_status_manager_QNODE_HPP_ */
