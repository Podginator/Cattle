# This is less than ideal, but just provides a quick way to compile
# note that all paths are relative to build, so ./test is actually build/test. Use ../ for files in the same folder as this.
# This file will print both 

mkdir ./build
cd ./build
cmake ..
make
rm -rf ./output
rm -rf ./output.cpp
./Rattle_CPP $1 
gcc -std=c++14 ./output.cpp -o ./output -lstdc++
./output