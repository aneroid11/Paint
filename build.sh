mkdir ../build
mkdir ../build/shapes

cd ./rectangle/
qmake .
make
cp *.so ../build/shapes/

cd ../line/
qmake .
make
cp *.so ../build/shapes/

cd ../build
qmake ../
make
