#bin/bash

sudo apt-get update
sudo apt-get install ninja-build cmake libmysqlcppconn-dev libgtest-dev uuid-dev
ninja --version
cmake --version
gcc --version