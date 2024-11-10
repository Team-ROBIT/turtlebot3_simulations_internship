# turtlebot3_simulations_internship

## Installation

1. Install the dependencies
```bash
$ sudo apt-get install -y ros-humble-gazebo-*
```

2. Clone the repository
```bash
$ cd ~/{Your ROS 2 Workspace}/src
$ git clone https://github.com/Team-ROBIT/turtlebot3_simulations_internship.git
$ cd turtlebot3_simulations_internship
$ git submodule update --init --recursive # Not necessary if you already have the submodules
```

3. Build the workspace
```bash
$ cd ~/{Your ROS 2 Workspace}
$ colcon build --symlink-install
$ source install/setup.bash
```

## Vision Turtlebot3 Launch
```bash
$ ros2 launch turtlebot3_simulations_internship internship_vision_turtlebot3.launch.py
```
![vision_turtlebot3](./docs/vision_turtlebot.png)    
