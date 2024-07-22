## ROS On SDI Project
This sub-repository of open-SDI aims to provide various ROS sample applications and Dockerfile/YAML for deployment on k8s.


### Prerequisites
-  k8s
-  docker or podman


### Workspace structure
```
📦sdi_ros_example                           # top level workspace
 ┣ 📂sdi_simple_app_cpp                     # packages will be located at this level
 ┃ ┣ 📂src
 ┃ ┃ ┗ 📂multiple_topics                    # node Level directory
 ┃ ┃ ┃ ┣ 📜listener1.cpp                    # nodes will be located at this level
 ┃ ┃ ┃ ┣ 📜listener2.cpp
 ┃ ┃ ┃ ┗ 📜multiple_topics_talker.cpp
 ┃ ┣ 📂yaml                                 # for k8s Deployment
 ┃ ┃ ┗ 📜dds-test.yaml
 ┃ ┣ 📜CMakeLists.txt
 ┃ ┣ 📜Dockerfile                           # for creating ROS container
 ┃ ┗ 📜package.xml
 ┣ 📜.gitignore
 ┗ 📜README.md
```


### Usage

##### Build as a container
```
# go to the ROS package directory
cd <path/to/package>

# build
podman build -t <repo:tag> .
```
##### Deploy to the k8s
- on k8s CP
```
# go to the ROS package directory
kubectl apply -f yaml/<deployment.yaml>
```


### Verify deployment & operation
- on k8s CP
```
# verify pod deployment
kubectl -nsdi-ros-system get pod -A

# check pod logs
kubectl -nsdi-ros-system logs -f <pod-name>
```
