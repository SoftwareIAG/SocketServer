#bin/bash

cd /usr/src/googletest/googletest || exit 1
sudo cmake CMakeLists.txt
sudo cmake

cd /usr/src/googletest/googletest/lib || exit 1
sudo cp *.a /usr/lib