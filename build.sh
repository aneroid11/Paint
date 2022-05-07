cd ./rectangle/
qmake .
make
cp *.so ../build/shapes/
cd ../build/
qmake ../
make
