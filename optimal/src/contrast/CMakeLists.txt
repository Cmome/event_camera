cmake_minimum_required(VERSION 3.0.2)
project(contrast)

find_package(catkin REQUIRED COMPONENTS
  dvs_msgs
  roscpp
  rospy
  cv_bridge
  image_transport
  cmake_modules
)
find_package(OpenCV REQUIRED)
find_package(Eigen REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES contrast
#  CATKIN_DEPENDS dvs_msgs roscpp rospy
#  DEPENDS system_lib
)


include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)
include_directories( ${OpenCV_INCLUDE_DIRS})
include_directories("/usr/local/include/eigen3")
#include_directories(${Eigen_INCLUDE_DIRS})


#add_executable(contrast_cvx src/contrast_cvx.cpp)
#target_link_libraries(contrast_cvx ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
#add_executable(eigen src/eigen.cpp)
#target_link_libraries(eigen ${catkin_LIBRARIES} )
#add_executable(contrast_y src/contrast_y.cpp)
#target_link_libraries(contrast_y ${catkin_LIBRARIES})

#add_executable(contrast_cvxy src/contrast_cvxy.cpp)
#target_link_libraries(contrast_cvxy ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

#add_executable(contrast_cvx1 src/contrast_cvx1.cpp)
#target_link_libraries(contrast_cvx1 ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


#add_executable(contrast_cvxyr src/contrast_cvxyr.cpp)
#target_link_libraries(contrast_cvxyr ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})