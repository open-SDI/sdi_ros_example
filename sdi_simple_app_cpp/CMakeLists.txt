cmake_minimum_required(VERSION 3.8)
project(sdi_simple_app_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rcl REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rcl_interfaces REQUIRED)
find_package(rcpputils REQUIRED)
find_package(rcutils REQUIRED)
find_package(rmw REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()




# Include
include_directories(include)


# Build
add_executable(multiple_topics_talker src/multiple_topics/multiple_topics_talker.cpp)
ament_target_dependencies(multiple_topics_talker rclcpp std_msgs)

add_executable(listener1 src/multiple_topics/listener1.cpp)
ament_target_dependencies(listener1 rclcpp std_msgs)

add_executable(listener2 src/multiple_topics/listener2.cpp)
ament_target_dependencies(listener2 rclcpp std_msgs)


# Install
install(TARGETS
	multiple_topics_talker
	listener1
	listener2
	DESTINATION lib/${PROJECT_NAME})

ament_package()
