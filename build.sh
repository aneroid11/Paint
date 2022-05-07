cd ./rectangle/
qmake .
make
mkdir ../build
mkdir ../build/shapes
cp *.so ../build/shapes/
cd ../build
qmake ../
make
