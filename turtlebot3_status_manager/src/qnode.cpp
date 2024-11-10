/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date August 2024
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include "../include/turtlebot3_status_manager/qnode.hpp"

QNode::QNode()
{
  int argc = 0;
  char ** argv = NULL;
  rclcpp::init(argc, argv);
  node = rclcpp::Node::make_shared("turtlebot3_status_manager");

  subscription_laser = node->create_subscription<sensor_msgs::msg::LaserScan>(
    "/scan", 10, std::bind(&QNode::laserCallback, this, std::placeholders::_1));
  subscription_cmd_vel = node->create_subscription<geometry_msgs::msg::Twist>(
    "/cmd_vel", 10, std::bind(&QNode::cmdVelCallback, this, std::placeholders::_1));

  this->start();
}

QNode::~QNode()
{
  if (rclcpp::ok()) {
    rclcpp::shutdown();
  }
}

void QNode::run()
{
  rclcpp::WallRate loop_rate(20);
  while (rclcpp::ok()) {
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  Q_EMIT rosShutDown();
}

void QNode::laserCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
  laser_data.clear();
  for (auto range : msg->ranges) {
    laser_data.push_back(range);
  }
  Q_EMIT updateLaserData();
}

void QNode::cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
  const double EPSILON = 1e-10;
  cmd_vel_data.clear();
  cmd_vel_data.push_back(msg->linear.x);
  cmd_vel_data.push_back(msg->linear.y);
  cmd_vel_data.push_back(msg->linear.z);
  cmd_vel_data.push_back(msg->angular.x);
  cmd_vel_data.push_back(msg->angular.y);
  cmd_vel_data.push_back(msg->angular.z);
  Q_EMIT updateCmdVelData();
}
