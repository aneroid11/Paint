mkdir build
mkdir build/shapes

cd build/

declare -a shapes_names
shapes_names=(rectangle line lines polygon)

for shape_name in "${shapes_names[@]}"
do
    cd "../$shape_name/"
    qmake .
	make
	cp *.so ../build/shapes/
done

cd ../build
qmake ../
make
