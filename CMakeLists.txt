cmake_minimum_required(VERSION 2.8.3)
project(rawfie_interface)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  actionlib
  move_base_msgs
  tf
  nav_msgs
  message_generation
  std_msgs
  std_srvs
  diagnostic_msgs
  diagnostic_updater
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

## Generate services in the 'srv' folder
add_service_files(DIRECTORY srv
   FILES
    goto_test.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   nav_msgs robotnik_msgs sensor_msgs rawfie_interface std_msgs
 )


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
    INCLUDE_DIRS include
#  LIBRARIES rcomponent
#  CATKIN_DEPENDS roscpp std_msgs
  DEPENDS rdkafka++ rdkafka avrocpp
)

###########
## Build ##
###########


include_directories(
   include
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp executable
#add_executable(rcomponent_node src/rcomponent.cpp)

add_executable(RwfInterface src/rdkafka_producer.cpp)
add_executable(RwfConsumerInterface src/rdkafka_consumer.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
#add_dependencies(rcomponent_node robotnik_msgs_generate_messages_cpp)


## Specify libraries to link a library or executable target against
#target_link_libraries(rcomponent_node
#   ${catkin_LIBRARIES}
#)

target_link_libraries(RwfInterface
  rdkafka++
  rdkafka
  avrocpp
  ${catkin_LIBRARIES} 
)
target_link_libraries(RwfConsumerInterface
  rdkafka++
  rdkafka
  avrocpp
  ${catkin_LIBRARIES} 
)
