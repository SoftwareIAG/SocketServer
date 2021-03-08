#bin/sh
echo Install MySQL connector ============================================================

sudo apt-get install libmysqlcppconn-dev libgtest-dev uuid-dev

echo Update gcc-9 =======================================================================

echo gcc version before
gcc --version
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
sudo apt-get update -y
sudo apt-get install ninja-build cmake gcc-9 g++-9 -y
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 90 --slave /usr/bin/g++ g++ /usr/bin/g++-9 --slave /usr/bin/gcov gcov /usr/bin/gcov-9
echo gcc version after
gcc --version

echo Update ninja =======================================================================

echo ninja version before
ninja --version
# wget https://github.com/ninja-build/ninja/releases/download/v1.10.0/ninja-linux.zip
wget https://github.com/ninja-build/ninja/releases/latest/download/ninja-linux.zip
sudo unzip ninja-linux.zip -d /usr/local/bin/
sudo update-alternatives --install /usr/bin/ninja ninja /usr/local/bin/ninja 1 --force
echo ninja version after
ninja --version

echo Update cmake =======================================================================

echo cmake version before
cmake --version
# curl --silent "https://api.github.com/repos/Kitware/CMake/releases/latest" | sed -n 's/.*tag_name":\s"\(.*\)".*/\1/p' | head -2
# wget https://github.com/Kitware/CMake/releases/latest/download/cmake-3.16.5-Linux-x86_64.sh
cmake_version=$(curl --silent "https://api.github.com/repos/Kitware/CMake/releases/latest" | sed -n 's/.*tag_name":\s"\(.*\)".*/\1/p' | head -2 | cut -c 2-)
echo cmake download latest v$cmake_version version
wget https://github.com/Kitware/CMake/releases/download/v$cmake_version/cmake-$cmake_version-Linux-x86_64.sh
chmod +x cmake-$cmake_version-Linux-x86_64.sh
sudo mkdir /opt/cmake
sudo ./cmake-$cmake_version-Linux-x86_64.sh --prefix=/opt/cmake --skip-license
sudo update-alternatives --install /usr/bin/cmake cmake /opt/cmake/bin/cmake 1 --force
echo cmake version after
cmake --version