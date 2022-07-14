cmake_minimum_required(VERSION 3.0.2)
project(optimal_event)

set(CMAKE_BUILD_TYPE debug)



find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  dvs_msgs
  geometry_msgs
  roscpp
  rospy
  std_msgs
)
find_package(OpenCV REQUIRED)


catkin_package()

include_directories(
   include

  ${catkin_INCLUDE_DIRS}
  
)
include_directories( ${OpenCV_INCLUDE_DIRS})

 #add_executable(publish_node src/publish_node.cpp)
# add_executable (subscribe_node src/subscribe_node.cpp)

 #target_link_libraries(publish_node  
  # ${catkin_LIBRARIES}
# )
# target_link_libraries(subscribe_node  
  # ${catkin_LIBRARIES}
 #)


 add_executable(event_node src/event_node.cpp)
 target_link_libraries(event_node ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})  

 add_executable(event_test src/event_test.cpp)
 target_link_libraries(event_test ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

 add_executable(event_time src/event_time.cpp)
 target_link_libraries(event_time ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})  

 add_executable(event_txt src/event_txt.cpp)
 target_link_libraries(event_txt ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

 add_executable(event_process src/event_process.cpp)
 target_link_libraries(event_process ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

 add_executable(event_pub src/event_pub.cpp)
 target_link_libraries(event_pub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})