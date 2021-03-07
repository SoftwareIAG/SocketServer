#bin/bash

cd /usr/src/gtest || exit 1
sudo cmake CMakeLists.txt
sudo make
sudo ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a
sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a