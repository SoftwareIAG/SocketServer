#bin/bash

# Run CMake
cmake .

# Run Make
make

# Copy config.cfg
cp config.cfg.example config.cfg
