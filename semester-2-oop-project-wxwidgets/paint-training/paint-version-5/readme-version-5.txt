Previously:
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
All shapes are now forming but we cannot choose colours on choice
Next:Allowing user to do colours and pencil through menubar

Update 10/5:
Added pen and brush of datatype wxColour in classes.h and class.cpp and coded their getter and setters.
Used wxcolourdlg for showing colours options for both pen and bush in every eventhandler of draw rectangle,triangle,circle,square,line.
After the user chooses a colour of any shape we set the inputted colour of pen and brush in that shape.
In render's iteration on vector of all shapes pointer we now used getters for pen and brush and stored them in variables of wxColour datatype and in every condition we simply replaced the hardcoded colours now with variables.
For line there is no brush so we have setted both the pen and brush with same colour of pen just becuase our logic of polymorphism works in this way.
It does not make a difference because we have used only the variable of pen in line's condition in render's iteration.
We also added Pencil in the menubar and created its submenu sketch of check type and created its eventhandler.
We have created two new variables in BasicDrawPane:
First one of wxColour datatype for colour of pencil 
Second one is a boolean variable which will tell us that whether sketch is checked or not
In the evenhandler of the check item sketch of Pencil of menubar we have coded that if sketch is checked then show the colour dialog and save the colour and put true in BasicDrawPane's boolean variable sketch else put false.
In the eventhandler of BasicDrawPane which actually does the pencil work we have coded that if boolean variable sketch is true then use the variable of colour in BascicDrawPane for the colour of pencil and do sketching.
Next:Pen's width