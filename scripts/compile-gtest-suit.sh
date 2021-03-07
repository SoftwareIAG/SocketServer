#bin/bash

cd /usr/src/gtest || exit
sudo cmake CMakeLists.txt
sudo cmake
sudo cp lib/*.a /usr/lib