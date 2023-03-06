# Paint
A simple drawing program for Linux.  
  
To build, execute __build.sh__.  
To run, execute __run.sh__. 

Use Esc to finish drawing of polygons and polylines.  
  
Use Ctrl+Z/Ctrl+Y to undo/redo your actions.  

Each shape is a dynamically loaded plugin (.so library). You can create your own shapes and add it to the program without recompiling. To do this, create a subclass for the abstract Shape class and add the createShape() function to the .cpp file. Then, compile the subclass to a .so library and place it into build/shapes/ directory.  
