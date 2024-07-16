FROM ros:jazzy

SHELL ["/bin/bash", "-c"]

# Install dependencies
RUN apt-get update && \
	apt install -y python3-colcon-common-extensions && \
    rm -rf /var/lib/apt/lists/*

# Create a workspace
RUN mkdir -p /ros2_ws
WORKDIR /ros2_ws

# Copy the package into the workspace
COPY . .

# Install Package
RUN source /opt/ros/$ROS_DISTRO/setup.bash && colcon build --symlink-install
