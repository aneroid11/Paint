# Paint
A simple drawing program for Linux.  
  
To build, execute __build.sh__.  
To run, execute __run.sh__. 

Use Esc to finish the drawing of polygons and polylines.  
  
Use Ctrl+Z/Ctrl+Y to undo/redo your actions.  

Each shape is a dynamically loaded plugin (.so library). You can create your own shapes and add it to the program without recompiling. To do this, create a subclass for the abstract Shape class and add the createShape() function to the .cpp file. Then, compile the subclass to a .so library and place it into build/shapes/ directory.  

![Screenshot from 2023-03-07 00-04-39](https://user-images.githubusercontent.com/73517902/223246186-01700ad4-dbf7-4c7c-8194-1c09d1021f03.png)
![Screenshot from 2023-03-07 00-11-03](https://user-images.githubusercontent.com/73517902/223246196-f3628f8e-da61-411f-98f8-4a8454da8432.png)
![Screenshot from 2023-03-07 01-04-53](https://user-images.githubusercontent.com/73517902/223246200-65cf0cae-5928-4090-8a85-a8794bbab0c8.png)
