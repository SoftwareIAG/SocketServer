#/bin/bash

# Move main to tmp
mv main.cpp tmp.cpp

# Move test to main
mv test.cpp main.cpp

# Move tmp to test
mv tmp.cpp test.cpp

echo "Runnable swapped successfully."