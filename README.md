# image-tools
This repository has some interesting image tools from opencv. The web console is built using Drogon C++ Web Framework

## Building The Repo

* Install Drogon, follow the instructions here [Install Drogon](https://github.com/an-tao/drogon/wiki/02-Installation)
* Install OpenCV follow the instructions here [Install OpenCV](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html)  
* Install gtk library libcanberra by running the following command
```shell script
sudo apt install libcanberra-gtk-module libcanberra-gtk3-module
```
* Follow the steps shown below to build
```shell script
git clone https://github.com/selvakumarjawahar/image-tools.git
cd image-tools
mkdir build
cd build
cmake ..
make 
./image-tools 
```
 
