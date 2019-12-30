Previously:
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

Update 11/5:
Now before asking for colour of pen and brush a message will show that now enter pen's colour and in case of brush now enter brush's colour,We did this by wxMessageDialog
We also changed few variables names and also changed the name of classes.h and classes.cpp to shapes.h and shapes.cpp
We created a long datatype variable in shapes.h and shapes.cpp named pen_width and created its setter and getter.
We added a wxNumberEntryDialog to take input for pen's width and simply using getter of Dialog saved the width in a variable and setted it into shape(triangle,line..).
In iteration of render replaced the hardcoded pen's width with by getting the pen's width of that shape(triangle,line,..).
In every eventhandler of every shape now the all the process of converting wxString into string and then integer and then setting the points,colours,pen's width in each shape and pushing it in vector of all shapes pointer of BasicDrawPane is done in the last condition i.e when the user press's OK after giving colour for brush.
We did this because now the shape won't draw unless user gives all the required things.
Due to this few bugs which were before are now also fixed.
Next:Drawing shapes through events