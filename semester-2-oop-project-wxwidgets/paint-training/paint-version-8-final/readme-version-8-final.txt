Previously:
We created boolean variables of draw_triangle.
We also created some more variables in the MousDown eventhandler and Mousereleased eventhandler or Mouseup.
We also created down_count_triangle of integer datatype.
We get the points of each specific shape from the eventhandler of mouseDown and mouseup.
There are conditions that if draw_triangle is true then depending on the down_count get the points.
For other shapes get the first point from mouseup eventhandler and the second point from the mousreleased or mousedown eventhandler.
All shapes are drawn by dragging the from the required point to the end required point except in triangle you have to click the three points.
In constructor boolean variables are initialized with true.

Update 13/5:
We made the pointer of shape holding specific shape's address now in the last condition in the menubar meaning if the user gives brush colour then he will be allowed to draw the shape.
Made down_count for each shape in BasicDrawPane.
Also made few changes in the variables,moved few variables to BasicDrawPane and rest to mouseDown eventhandler.
Finished the mouseup event or mousereleased eventhandler.
There are conditions in mouseDown eventthat if draw_triangle,.. is true then depending on the down_count get the points and push them in the shape in last click and reset all things then.
Initialized all the down_count_.. of each shape with 0,initialized pencil_colour with 0 although there was no need.
Now messageBoxes will also show to tell you which points we need to draw the shape so just click on the points.
Now for each shape we just need to click on the points.