mkdir build
mkdir build/shapes

cd ./rectangle/
qmake .
make
cp *.so ../build/shapes/

cd ../line/
qmake .
make
cp *.so ../build/shapes/

cd ../lines/
qmake .
make
cp *.so ../build/shapes/

cd ../polygon/
qmake .
make
cp *.so ../build/shapes/

cd ../build
qmake ../
make
