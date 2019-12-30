Previously:
All the shapes are done now which include Circle, Square, Triangle, Rectangle and Line. All the shapes are forming. The code is fine up til now.
Made separate vectors and variables for different shapes.
Files included: classes.h(classes.cpp through linker),formulas.h(formulas.cpp through linker)
No menubar
In BasicDrawPane class's a vector of shapes pointer was declared in private.
In BasicDrawPane class's constructor square pointer was pushed into the vector.
In render iteration was used on the vector and then square was drawn after if-check using DrawLine function.

Update 9/5:
Files included: classes.h(classes.cpp through linker),formulas.h(formulas.cpp through linker),string-conversions.h(string-conversions.cpp through linker)
Menubar status:Shapes(draw rectangle,square,circle,triangle),Line(draw line).
Did coding in eventhandler of draw rectangle,square,circle,triangle.
Event handler of each shape:
Used a dialogbox for inputs of datatype of wxstring.
Converted the wxstring into string.
Converted the string into vector of integers.
Made points with the values used from the vector of integers.
Pushed the points in a vector of Point and and setted the vector of Point in the pointer of that shape.
Casted the address of parent(child's address) to child(child's address) and stored it in child's pointer      parent=WxPanel  child=BasicDrawPane.
Accessed the vector of all shapes pointer and pushed the pointer of that shape into the vector of all shapes pointer.
Now called the render through paintNow() of BasicDrawPane because the render is called in CreateGuiControls through BasicDrawPane at runtime so we need to use render again.
Next:Colours through menubar.
Removed everything from the BasicDrawPane's constructor.