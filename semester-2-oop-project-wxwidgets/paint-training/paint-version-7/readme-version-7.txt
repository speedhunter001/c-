Previously:
Now before asking for colour of pen and brush a message will show that now enter pen's colour and in case of brush now enter brush's colour,We did this by wxMessageDialog
We also changed few variables names and also changed the name of classes.h and classes.cpp to shapes.h and shapes.cpp
We created a long datatype variable in shapes.h and shapes.cpp named pen_width and created its setter and getter.
We added a wxNumberEntryDialog to take input for pen's width and simply using getter of Dialog saved the width in a variable and setted it into shape(triangle,line..).
In iteration of render replaced the hardcoded pen's width with by getting the pen's width of that shape(triangle,line,..).
In every eventhandler of every shape now the all the process of converting wxString into string and then integer and then setting the points,colours,pen's width in each shape and pushing it in vector of all shapes pointer of BasicDrawPane is done in the last condition i.e when the user press's OK after giving colour for brush.
We did this because now the shape won't draw unless user gives all the required things.
Due to this few bugs which were before are now also fixed.

Update 12/5:
We created boolean variables of draw_triangle.
We also created some more variables in the MousDown eventhandler and Mousereleased eventhandler or Mouseup.
We also created down_count_triangle of integer datatype.
We get the points of each specific shape from the eventhandler of mouseDown and mouseup.
There are conditions that if draw_triangle is true then depending on the down_count get the points in the mouseDown eventhandler.
For other shapes get the first point from mouseup eventhandler and the second point from the mousreleased or mousedown eventhandler.
All shapes are drawn by dragging the from the required point to the end required point except in triangle you have to click the three points.
In constructor boolean variables are initialized with true.
Next:Final with some changes in clicking points,in menu events and in mousup event.
