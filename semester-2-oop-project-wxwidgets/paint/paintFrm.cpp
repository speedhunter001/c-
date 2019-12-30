///-----------------------------------------------------------------
///
/// @file      paintFrm.cpp
/// @author    Momina,Sana and Ammar
/// Created:   08/05/2019 3:48:43 AM
/// @section   DESCRIPTION
///            paintFrm class implementation
///
///------------------------------------------------------------------

#include "paintFrm.h"          //ALL INCLUDES BY MSA ARE IN paintFrm.h

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// paintFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(paintFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(paintFrm::OnClose)
	EVT_MENU(ID_MNU_DRAWTRIANGLE_1004, paintFrm::Mnudrawtriangle1004Click)
	EVT_MENU(ID_MNU_DRAWRECTANGLE_1005, paintFrm::Mnudrawrectangle1005Click)
	EVT_MENU(ID_MNU_DRAWSQUARE_1006, paintFrm::Mnudrawsquare1006Click)
	EVT_MENU(ID_MNU_DRAWCIRCLE_1007, paintFrm::Mnudrawcircle1007Click)
	EVT_MENU(ID_MNU_SKETCH_1011, paintFrm::Mnusketch1011Click)
	EVT_MENU(ID_MNU_DRAWLINE_1009, paintFrm::Mnudrawline1009Click)
END_EVENT_TABLE()
////Event Table End

paintFrm::paintFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

paintFrm::~paintFrm()
{
}

//MSA Drawing Starts from here
class BasicDrawPane : public wxPanel
{

public:
    BasicDrawPane(wxFrame* parent);

    //MSA CODE STARTS HERE
    vector<Shapes*> all_shapes; 
    
    bool draw_triangle, draw_rectangle, draw_square, draw_circle, draw_line, sketch;
    Shapes * triangle_sh, * rectangle_sh, * square_sh, * circle_sh, * line_sh;
    int down_count_triangle, down_count_rectangle, down_count_square, down_count_circle, down_count_line;
    vector<Point> points;
    
    wxColour pencil_colour;
    //MSA CODE ENDS HERE
    
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    
    void render(wxDC& dc);
    
    // some useful events
    
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
  /* void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
   */
    
    DECLARE_EVENT_TABLE()
};


class MyApp: public wxApp
{
    bool OnInit();
    
    wxFrame *frame;
    BasicDrawPane * drawPane;
public:
        
};

//IMPLEMENT_APP(MyApp)


bool MyApp::OnInit()
{
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Hello wxDC"), wxPoint(50,50), wxSize(800,600));
	
    drawPane = new BasicDrawPane( (wxFrame*) frame );
    sizer->Add(drawPane, 1, wxEXPAND);
	
    frame->SetSizer(sizer);
    frame->SetAutoLayout(true);
	
    frame->Show();
    return true;
} 

BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
// some useful events

 EVT_MOTION(BasicDrawPane::mouseMoved)
 EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
/* EVT_LEFT_UP(BasicDrawPane::mouseReleased)
 EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 EVT_KEY_UP(BasicDrawPane::keyReleased)
 EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
*/ 

// catch paint events
EVT_PAINT(BasicDrawPane::paintEvent)

END_EVENT_TABLE()


// some useful events

//Pencil 
void BasicDrawPane::mouseMoved(wxMouseEvent& event) {
    //MSA CODE STARTS HERE
    if ( sketch == true ) {
        if ( event.Dragging() ) {
            wxClientDC dc(this);
            /*wxPen pen(pencil_colour, 1); // red pen of width 100
            dc.SetPen(pen);   */ //  or
            dc.SetPen( wxPen(pencil_colour, 1) ); 
            dc.DrawPoint(event.GetPosition());                      //Drawing the point with the given colour of pencil
            dc.SetPen(wxNullPen);   
        }
    }        
    //MSA CODE ENDS HERE
}

//Mouse left button down eventhandler through which we pass required points to the specific shape
void BasicDrawPane::mouseDown(wxMouseEvent& event) {
     //MSA CODE STARTS HERE
     //We declare wxPoint to get any poisition from Panel
    wxPoint top_triangle_wxpoint, bottom_right_triangle_wxpoint, bottom_left_triangle_wxpoint, top_left_rect_wxpoint, bottom_right_rect_wxpoint,
            top_left_sq_wxpoint, bottom_right_sq_wxpoint, centre_wxpoint, point_on_circumference_wxpoint, start_wxpoint, end_wxpoint; 
     
     //We declare Point because we are using points of Point datatype in render and in shapes too
    Point top_triangle, bottom_right_triangle, bottom_left_triangle, top_left_rect, bottom_right_rect, 
          top_left_sq, bottom_right_sq, centre, point_on_circumference, start, end;
    
    //We will use x to get x of wxPoint and y to get y of wxPoint
    int x,y;
       
    if ( draw_triangle == true ) {                        
        if ( down_count_triangle == 0 ) {                //First click for top point of triangle
            top_triangle_wxpoint = event.GetPosition();      //Getting the wxPoint from panel
            x = top_triangle_wxpoint.x;
            y = top_triangle_wxpoint.y;
            top_triangle.set_coordinates(x, y);              //Converting it into point
            
            points.push_back(top_triangle);                  //Pushing the top point of triangle into vector of points
            down_count_triangle = 1;                         //Now the next click will be a second click for next point
        }
        else if ( down_count_triangle == 1 ) {          //Second click for bottom right point of triangle
            bottom_right_triangle_wxpoint = event.GetPosition();    //Getting the wxPoint from panel
            x = bottom_right_triangle_wxpoint.x;
            y = bottom_right_triangle_wxpoint.y;
            bottom_right_triangle.set_coordinates(x, y);            //Converting it into point
            
            points.push_back(bottom_right_triangle);                //Pushing the bottom right point of triangle into vector of points
            down_count_triangle = 2;                                //Now the next click will be a third click for next point
        }
        else if ( down_count_triangle == 2 ) {           //Third click for bottom left point of triangle
            vector<Point> empty;                                        //Declaring a vector with the name of empty
             
            bottom_left_triangle_wxpoint = event.GetPosition();         //Getting the wxPoint from panel
            x = bottom_left_triangle_wxpoint.x;
            y = bottom_left_triangle_wxpoint.y;
            bottom_left_triangle.set_coordinates(x, y);                 //Converting it into point
        
            points.push_back(bottom_left_triangle);                     //Pushing the bottom left point of triangle into vector of points
            
            triangle_sh->set_points(points);                            //Setting the vector of points declared in BasicDrawPane in shape pointer of triangle 
            all_shapes.push_back(triangle_sh);                          //Pushing the shape pointer of triangle in vector of all shapes vector
        
            paintNow();                                                  //Calling render because render by CreateGuiCOntrols is called at runtime
            down_count_triangle = 0;                                    //Now obviously there is no next point so number of clicks will be zero because no need of any other point    
            points = empty;                                              //Making the vector of points empty by putting an empty vector for the use of any next shape
            draw_triangle = false;                                       //Because drawing the triangle is finished
        }
    }
    else if ( draw_rectangle == true ) {
        if ( down_count_rectangle == 0 ) {             //First click for top left point of rectangle
            top_left_rect_wxpoint = event.GetPosition();            //Getting the wxPoint from panel
            x = top_left_rect_wxpoint.x;
            y = top_left_rect_wxpoint.y;
            top_left_rect.set_coordinates(x, y);                    //Converting it into point
            
            points.push_back(top_left_rect);                        //Pushing the top left point of rectangle into vector of points
            down_count_rectangle = 1;                               //Now the next click will be a second click for next point
        }
        else if ( down_count_rectangle == 1 ) {         //Second click for bottom right point of rectangle
            vector<Point> empty;                                    //Declaring a vector with the name of empty
             
            bottom_right_rect_wxpoint = event.GetPosition();        //Getting the wxPoint from panel
            x = bottom_right_rect_wxpoint.x;
            y = bottom_right_rect_wxpoint.y;
            bottom_right_rect.set_coordinates(x, y);                //Converting it into point
        
            points.push_back(bottom_right_rect);                    //Pushing the bottom right point of rectangle into vector of points
            
            rectangle_sh->set_points(points);                       //Setting the vector of points declared in BasicDrawPane in shape pointer of rectangle 
            all_shapes.push_back(rectangle_sh);                     //Pushing the shape pointer of rectangle in vector of all shapes vector
        
            paintNow();                                             //Calling render because render by CreateGuiCOntrols is called at runtime
            down_count_rectangle = 0;                               //Now obviously there is no next point so number of clicks will be zero because no need of any other point
            points = empty;                                         //Making the vector of points empty by putting an empty vector for the use of any next shape
            draw_rectangle = false;                                  //Because drawing the rectangle is finished
        }
    }
    else if ( draw_square == true ) {
        if ( down_count_square == 0 ) {                 //First click for top left point of square
            top_left_sq_wxpoint = event.GetPosition();              //Getting the wxPoint from panel
            x = top_left_sq_wxpoint.x;
            y = top_left_sq_wxpoint.y;
            top_left_sq.set_coordinates(x, y);                      //Converting it into point
            
            points.push_back(top_left_sq);                          //Pushing the top left point of square into vector of points
            down_count_square = 1;                                  //Now the next click will be a second click for next point
        }
        else if ( down_count_square == 1 ) {            //Second click for bottom right point of square
            vector<Point> empty;                                    //Declaring a vector with the name of empty
             
            bottom_right_sq_wxpoint = event.GetPosition();          //Getting the wxPoint from panel
            x = bottom_right_sq_wxpoint.x;
            y = bottom_right_sq_wxpoint.y;
            bottom_right_sq.set_coordinates(x, y);                  //Converting it into point
        
            points.push_back(bottom_right_sq);                      //Pushing the top left point of square into vector of points
            
            square_sh->set_points(points);                          //Setting the vector of points declared in BasicDrawPane in shape pointer of square
            all_shapes.push_back(square_sh);                        //Pushing the shape pointer of square in vector of all shapes vector
        
            paintNow();                                             //Calling render because render by CreateGuiCOntrols is called at runtime
            down_count_square = 0;                                  //Now obviously there is no next point so number of clicks will be zero because no need of any other point
            points = empty;                                         //Making the vector of points empty by putting an empty vector for the use of any next shape
            draw_square = false;                                    //Because drawing the square is finished
        }
    }
    else if ( draw_circle == true ) {
        if ( down_count_circle == 0 ) {                 //First click for centre of circle
            centre_wxpoint = event.GetPosition();                   //Getting the wxPoint from panel
            x = centre_wxpoint.x;
            y = centre_wxpoint.y;
            centre.set_coordinates(x, y);                           //Converting it into point
            
            points.push_back(centre);                               //Pushing the centre point of circle into vector of points
            down_count_circle = 1;                                  //Now the next click will be a second click for next point
        }
        else if ( down_count_circle == 1 ) {            //Second click for any point on circumference of circle
            vector<Point> empty;                                    //Declaring a vector with the name of empty
             
            point_on_circumference_wxpoint = event.GetPosition();    //Getting the wxPoint from panel
            x = point_on_circumference_wxpoint.x;
            y = point_on_circumference_wxpoint.y;
            point_on_circumference.set_coordinates(x, y);           //Converting it into point
        
            points.push_back(point_on_circumference);               //Pushing the point on circumference of circle into vector of points
            
            circle_sh->set_points(points);                          //Setting the vector of points declared in BasicDrawPane in shape pointer of circle
            all_shapes.push_back(circle_sh);                        //Pushing the shape pointer of circle in vector of all shapes vector
        
            paintNow();                                             //Calling render because render by CreateGuiCOntrols is called at runtime
            down_count_circle = 0;                                  //Now obviously there is no next point so number of clicks will be zero because no need of any other point
            points = empty;                                         //Making the vector of points empty by putting an empty vector for the use of any next shape
            draw_circle = false;                                    //Because drawing the circle is finished
        }
    }
    else if ( draw_line == true ) {                     
        if ( down_count_line == 0 ) {                   //First click for start point of line
            start_wxpoint = event.GetPosition();                    //Getting the wxPoint from panel
            x = start_wxpoint.x;
            y = start_wxpoint.y;
            start.set_coordinates(x, y);                            //Converting it into point
            
            points.push_back(start);                                //Pushing the start point into vector of points
            down_count_line = 1;                                    //Now the next click will be a second click for next point
        }
        else if ( down_count_line == 1 ) {              //Second click for end point of line
            vector<Point> empty;                                    //Declaring a vector with the name of empty
             
            end_wxpoint = event.GetPosition();                      //Getting the wxPoint from panel
            x = end_wxpoint.x;
            y = end_wxpoint.y;
            end.set_coordinates(x, y);                              //Converting it into point
        
            points.push_back(end);                                  //Pushing the end point of line into vector of points
            
            line_sh->set_points(points);                            //Setting the vector of points declared in BasicDrawPane in shape pointer of line
            all_shapes.push_back(line_sh);                          //Pushing the shape pointer of line in vector of all shapes vector
        
            paintNow();                                             //Calling render because render by CreateGuiCOntrols is called at runtime
            down_count_line = 0;                                    //Now obviously there is no next point so number of clicks will be zero because no need of any other point
            points = empty;                                         //Making the vector of points empty by putting an empty vector for the use of any next shape
            draw_line = false;                                      //Because drawing the line is finished
        }
    }
 }
/* void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
 void BasicDrawPane::mouseReleased(wxMouseEvent& event) {}
 void BasicDrawPane::rightClick(wxMouseEvent& event) {}
 void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
 void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
void BasicDrawPane::keyReleased(wxKeyEvent& event) {}
*/ 

BasicDrawPane::BasicDrawPane(wxFrame* parent) :
wxPanel(parent)
{ 
    //MSA CODE STARTS HERE
    draw_triangle, draw_rectangle, draw_square, draw_circle, draw_line, sketch = false;
    down_count_triangle, down_count_rectangle, down_count_square, down_count_circle, down_count_line = 0;
    pencil_colour = wxColour(0,0,0);
    //MSA CODE ENDS HERE
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void BasicDrawPane::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 *
 * In most cases, this will not be needed at all; simply handling
 * paint events and calling Refresh() when a refresh is needed
 * will do the job.
 */
void BasicDrawPane::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void BasicDrawPane::render(wxDC&  dc)
{
    //MSA CODE STARTS HERE   
    vector<Point> points;
    wxColour pen, brush;
    long pen_width;
    int width, height, radius;
    
    // drawing some text
   // dc.DrawText(wxT("team AMMAR , MOMINA AND SANA "), 40, 60); 
    
    // Look at the wxDC docs to learn how to draw other stuff
    

     for( Shapes * shape : all_shapes ){
        points = shape->get_points();
        pen = shape->get_pen();
        brush = shape->get_brush();
        pen_width = shape->get_pen_width();
        
        if ( shape->get_shape_type() == "SQUARE" ) {
            dc.SetPen( wxPen( pen, pen_width ) );    
            dc.SetBrush( brush ); 
            width = get_width( points[0].get_x(), points[1].get_x() );                      //Calculating width
            height = get_height( points[0].get_y(), points[1].get_y() );                    //Calculating height
            dc.DrawRectangle( points[0].get_x(), points[0].get_y(), width, height);         //Parameters are ( x, y, width, height )
        }
        else if ( shape->get_shape_type() == "RECTANGLE" ) {
            dc.SetPen( wxPen( pen, pen_width ) );     
            dc.SetBrush( brush ); 
            width = get_width( points[0].get_x(), points[1].get_x() );                      //Calculating width
            height = get_height( points[0].get_y(), points[1].get_y() );                    //Calculaating height
            //for square width and height must be same
            dc.DrawRectangle( points[0].get_x(), points[0].get_y(), width, height);         //Parameters are ( x, y, width, height )
        }
        else if ( shape->get_shape_type() == "CIRCLE" ) {
            dc.SetBrush( brush );                   
            dc.SetPen( wxPen( pen, pen_width ) );            
            radius = get_distance( points[0].get_x(), points[0].get_y(), points[1].get_x(), points[1].get_y() );    //Calculating distance between centre and any point on circumference gives us radius
            dc.DrawCircle( wxPoint( points[0].get_x(), points[0].get_y() ), radius );                               //Parameters are ( wxPoint(x, y), radius )
        }
        else if ( shape->get_shape_type() == "LINE" ) {
            dc.SetPen( wxPen( pen, pen_width ) ); 
            dc.DrawLine( points[0].get_x(), points[0].get_y(), points[1].get_x(), points[1].get_y() );     //For straight line y coordinates must be same and x should be different    //parameters are (x1, y1, x2, y2)
        }
        else if ( shape->get_shape_type() == "TRIANGLE" ) { 
            dc.SetPen( wxPen( pen, pen_width ) ); 
            dc.SetBrush( brush );
    
            wxPoint triangle[3];                                                //Creating an array of 3 indexes and in it giving 3 wxPoints
            triangle[0] = wxPoint( points[0].get_x(), points[0].get_y() );     
            triangle[1] = wxPoint( points[1].get_x(), points[1].get_y() );
            triangle[2] = wxPoint( points[2].get_x(), points[2].get_y() );            
            dc.DrawPolygon( 3, triangle );                                      //Parameters now using are (number_of_points, array)
        }
    }
    //MSA CODE ENDS HERE

}
//MSA Drawing Ends Here

void paintFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

    WxPanel1 = new BasicDrawPane(this);

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_SHAPES_1003_Mnu_Obj = new wxMenu();
	ID_MNU_SHAPES_1003_Mnu_Obj->Append(ID_MNU_DRAWTRIANGLE_1004, _("Draw Triangle"), _(""), wxITEM_NORMAL);
	ID_MNU_SHAPES_1003_Mnu_Obj->Append(ID_MNU_DRAWRECTANGLE_1005, _("Draw Rectangle"), _(""), wxITEM_NORMAL);
	ID_MNU_SHAPES_1003_Mnu_Obj->Append(ID_MNU_DRAWSQUARE_1006, _("Draw Square"), _(""), wxITEM_NORMAL);
	ID_MNU_SHAPES_1003_Mnu_Obj->Append(ID_MNU_DRAWCIRCLE_1007, _("Draw Circle"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_SHAPES_1003_Mnu_Obj, _("Shapes"));
	
	wxMenu *ID_MNU_PENCIL_1010_Mnu_Obj = new wxMenu();
	ID_MNU_PENCIL_1010_Mnu_Obj->Append(ID_MNU_SKETCH_1011, _("Sketch"), _(""), wxITEM_CHECK);
	ID_MNU_PENCIL_1010_Mnu_Obj->Check(ID_MNU_SKETCH_1011,false);
	WxMenuBar1->Append(ID_MNU_PENCIL_1010_Mnu_Obj, _("Pencil"));
	
	wxMenu *ID_MNU_LINE_1008_Mnu_Obj = new wxMenu();
	ID_MNU_LINE_1008_Mnu_Obj->Append(ID_MNU_DRAWLINE_1009, _("Draw Line"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_LINE_1008_Mnu_Obj, _("Line "));
	SetMenuBar(WxMenuBar1);

	SetTitle(_("Splash"));
	SetIcon(wxNullIcon);
	SetSize(1920, 1000);                     //Parameters are (x, y, width, height) but no use of x and y because of Centre() in next line
	Center();  
	
	////GUI Items Creation End
}

void paintFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * Mnudrawtriangle1004Click
 */
void paintFrm::Mnudrawtriangle1004Click(wxCommandEvent& event)
{
	// insert your code here
	BasicDrawPane * BDP;
	wxColourData retData;
	wxColour colour1, colour2;
	long colour1_width;
	
    //Colour stuff starts here
    //For pen
    wxMessageBox ( "After pressing OK choose colour of Pen and press OK", "Choose Pen colour");
    wxColourData data;                              //Doing some initialization kinda stuff
    data.SetChooseFull(true);
    for (int i = 0; i < 16; i++) {
        wxColour colour(i*16, i*16, i*16);
        data.SetCustomColour(i, colour);
    }                               
    wxColourDialog colour1_dialog(this, &data);             //Colour1 dialog
    if (colour1_dialog.ShowModal() == wxID_OK) {
        retData = colour1_dialog.GetColourData();
        colour1 = retData.GetColour();                 //Getting the colour1
        //Pen's witdh i.e pixel
        wxNumberEntryDialog	colour1_width_dialog(this, "Enter the Width", "Width:", "Enter the Width of Pen", 0, 0, 1000);  //Colour1's width dialog
        if ( colour1_width_dialog.ShowModal() == wxID_OK ) {
            colour1_width = colour1_width_dialog.GetValue();      //Getting colour1's width which is actually of long dataype                       

            //For brush
            wxMessageBox ( "After pressing OK choose colour of Brush and press OK", "Choose Brush colour");
            wxColourData data;                          //Doing some initialization kinda stuff 
            data.SetChooseFull(true);
            for (int i = 0; i < 16; i++) {
                wxColour colour(i*16, i*16, i*16);
                data.SetCustomColour(i, colour);
            }
            wxColourDialog colour2_dialog(this, &data);          //Colour2 dialog
            if (colour2_dialog.ShowModal() == wxID_OK) {
                retData = colour2_dialog.GetColourData();
                colour2 = retData.GetColour();             //Getting the colour2
                //Colour stuff ends here           
                
           	    BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
                BDP->draw_triangle = true;                          //Because now that the user has given all the required things so now we will let the user draw triangle
                BDP->triangle_sh = new Triangle;                    //Making a shape pointer that holds triangle's address
                
                BDP->triangle_sh->set_pen_brush(colour1, colour2);                   //Setting the colours of pen and brush
                BDP->triangle_sh->set_pen_width(colour1_width);                      //Setting the width of pen
            
                wxMessageBox ("First click on the the point which you want to be Top of triangle and then click on Bottom right point and then click on Bottom left point of triangle", "Click on points");
            }
        }
    }            
    //MSA CODE ENDS HERE
}

/*
 * Mnudrawrectangle1005Click
 */
void paintFrm::Mnudrawrectangle1005Click(wxCommandEvent& event)
{
	// insert your code here
	//MSA CODE STARTS HERE
	BasicDrawPane * BDP;
	wxColourData retData;
	wxColour colour1, colour2;
	long colour1_width;
	
    //Colour stuff starts here
    //For pen
    wxMessageBox ( "After pressing OK choose colour of Pen and press OK", "Choose Pen colour");
    wxColourData data;                              //Doing some initialization kinda stuff
    data.SetChooseFull(true);
    for (int i = 0; i < 16; i++) {
        wxColour colour(i*16, i*16, i*16);
        data.SetCustomColour(i, colour);
    }                               
    wxColourDialog colour1_dialog(this, &data);             //Colour1 dialog
    if (colour1_dialog.ShowModal() == wxID_OK) {
        retData = colour1_dialog.GetColourData();
        colour1 = retData.GetColour();                 //Getting the colour1
        //Pen's witdh i.e pixel
        wxNumberEntryDialog	colour1_width_dialog(this, "Enter the Width", "Width:", "Enter the Width of Pen", 0, 0, 1000);  //Colour1's width dialog
        if ( colour1_width_dialog.ShowModal() == wxID_OK ) {
            colour1_width = colour1_width_dialog.GetValue();      //Getting colour1's width which is actually of long dataype                       

            //For brush
            wxMessageBox ( "After pressing OK choose colour of Brush and press OK", "Choose Brush colour");
            wxColourData data;                          //Doing some initialization kinda stuff 
            data.SetChooseFull(true);
            for (int i = 0; i < 16; i++) {
                wxColour colour(i*16, i*16, i*16);
                data.SetCustomColour(i, colour);
            }
            wxColourDialog colour2_dialog(this, &data);          //Colour2 dialog
            if (colour2_dialog.ShowModal() == wxID_OK) {
                retData = colour2_dialog.GetColourData();
                colour2 = retData.GetColour();             //Getting the colour2
                //Colour stuff ends here           
                
            	BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
                BDP->draw_rectangle = true;                 //Because now that the user has given all the required things so now we will let the user draw rectangle
                BDP->rectangle_sh = new Rect;               //Making a shape pointer that holds rectangle's address
                
                BDP->rectangle_sh->set_pen_brush(colour1, colour2);                   //Setting the colours of pen and brush
                BDP->rectangle_sh->set_pen_width(colour1_width);                      //Setting the width of pen

                wxMessageBox ("First click on the the point which you want to be Top left of rectangle and then click on Bottom right point of rectangle", "Click on points");
            }
        }
    }            
    //MSA CODE ENDS HERE
}

/*
 * Mnudrawsquare1006Click
 */
void paintFrm::Mnudrawsquare1006Click(wxCommandEvent& event)
{
	// insert your code here
	//MSA CODE STARTS HERE
	BasicDrawPane * BDP;
	wxColourData retData;
	wxColour colour1, colour2;
	long colour1_width;
	
    //Colour stuff starts here
    //For pen
    wxMessageBox ( "After pressing OK choose colour of Pen and press OK", "Choose Pen colour");
    wxColourData data;                              //Doing some initialization kinda stuff
    data.SetChooseFull(true);
    for (int i = 0; i < 16; i++) {
        wxColour colour(i*16, i*16, i*16);
        data.SetCustomColour(i, colour);
    }                               
    wxColourDialog colour1_dialog(this, &data);             //Colour1 dialog
    if (colour1_dialog.ShowModal() == wxID_OK) {
        retData = colour1_dialog.GetColourData();
        colour1 = retData.GetColour();                 //Getting the colour1
        //Pen's witdh i.e pixel
        wxNumberEntryDialog	colour1_width_dialog(this, "Enter the Width", "Width:", "Enter the Width of Pen", 0, 0, 1000);  //Colour1's width dialog
        if ( colour1_width_dialog.ShowModal() == wxID_OK ) {
            colour1_width = colour1_width_dialog.GetValue();      //Getting colour1's width which is actually of long dataype                       

            //For brush
            wxMessageBox ( "After pressing OK choose colour of Brush and press OK", "Choose Brush colour");
            wxColourData data;                          //Doing some initialization kinda stuff 
            data.SetChooseFull(true);
            for (int i = 0; i < 16; i++) {
                wxColour colour(i*16, i*16, i*16);
                data.SetCustomColour(i, colour);
            }
            wxColourDialog colour2_dialog(this, &data);          //Colour2 dialog
            if (colour2_dialog.ShowModal() == wxID_OK) {
                retData = colour2_dialog.GetColourData();
                colour2 = retData.GetColour();             //Getting the colour2
                //Colour stuff ends here           
                
                BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
                BDP->draw_square = true;                    //Because now that the user has given all the required things so now we will let the user draw square
                BDP->square_sh = new Square;                //Making a shape pointer that holds square's address

                BDP->square_sh->set_pen_brush(colour1, colour2);                   //Setting the colours of pen and brush
                BDP->square_sh->set_pen_width(colour1_width);                      //Setting the width of pen

                wxMessageBox ("First click on the the point which you want to be Top left of square and then click on Bottom right point of square", "Click on points");
            }
        }
    }            
    //MSA CODE ENDS HERE
}

/*
 * Mnudrawcircle1007Click
 */
void paintFrm::Mnudrawcircle1007Click(wxCommandEvent& event)
{
	// insert your code here
	//MSA CODE STARTS HERE
	BasicDrawPane * BDP;
	wxColourData retData;
	wxColour colour1, colour2;
	long colour1_width;
	
    //Colour stuff starts here
    //For pen
    wxMessageBox ( "After pressing OK choose colour of Pen and press OK", "Choose Pen colour");
    wxColourData data;                              //Doing some initialization kinda stuff
    data.SetChooseFull(true);
    for (int i = 0; i < 16; i++) {
        wxColour colour(i*16, i*16, i*16);
        data.SetCustomColour(i, colour);
    }                               
    wxColourDialog colour1_dialog(this, &data);             //Colour1 dialog
    if (colour1_dialog.ShowModal() == wxID_OK) {
        retData = colour1_dialog.GetColourData();
        colour1 = retData.GetColour();                 //Getting the colour1
        //Pen's witdh i.e pixel
        wxNumberEntryDialog	colour1_width_dialog(this, "Enter the Width", "Width:", "Enter the Width of Pen", 0, 0, 1000);  //Colour1's width dialog
        if ( colour1_width_dialog.ShowModal() == wxID_OK ) {
            colour1_width = colour1_width_dialog.GetValue();      //Getting colour1's width which is actually of long dataype                       

            //For brush
            wxMessageBox ( "After pressing OK choose colour of Brush and press OK", "Choose Brush colour");
            wxColourData data;                          //Doing some initialization kinda stuff 
            data.SetChooseFull(true);
            for (int i = 0; i < 16; i++) {
                wxColour colour(i*16, i*16, i*16);
                data.SetCustomColour(i, colour);
            }
            wxColourDialog colour2_dialog(this, &data);          //Colour2 dialog
            if (colour2_dialog.ShowModal() == wxID_OK) {
                retData = colour2_dialog.GetColourData();
                colour2 = retData.GetColour();             //Getting the colour2
                //Colour stuff ends here           
                
            	BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
                BDP->draw_circle = true;                    //Because now that the user has given all the required things so now we will let the user draw circle
                BDP->circle_sh = new Circle;                //Making a shape pointer that holds circle's address
                
                BDP->circle_sh->set_pen_brush(colour1, colour2);                   //Setting the colours of pen and brush
                BDP->circle_sh->set_pen_width(colour1_width);                      //Setting the width of pen

                wxMessageBox ("First click on the the point which you want to be Centre of circle and then click on Any point of circumference of circle", "Click on points");
            }
        }
    }            
    //MSA CODE ENDS HERE
}


/*
 * Mnudrawline1009Click
 */
void paintFrm::Mnudrawline1009Click(wxCommandEvent& event)
{
	// insert your code here
	//MSA CODE STARTS HERE
	BasicDrawPane * BDP;
	wxColourData retData;
	wxColour colour1;
	long colour1_width;

    //Colour stuff starts here
    //For pen
    wxMessageBox ( "After pressing OK choose colour of Pen and press OK", "Choose Pen colour");
    wxColourData data;                              //Doing some initialization kinda stuff
    data.SetChooseFull(true);
    for (int i = 0; i < 16; i++) {
        wxColour colour(i*16, i*16, i*16);
        data.SetCustomColour(i, colour);
    }                               
    wxColourDialog colour1_dialog(this, &data);             //Colour1 dialog
    if (colour1_dialog.ShowModal() == wxID_OK) {
        retData = colour1_dialog.GetColourData();
        colour1 = retData.GetColour();                 //Getting the colour1
        //Pen's witdh i.e pixel
        wxNumberEntryDialog	colour1_width_dialog(this, "Enter the Width", "Width:", "Enter the Width of Pen", 0, 0, 1000);  //Colour1's width dialog
        if ( colour1_width_dialog.ShowModal() == wxID_OK ) {
            colour1_width = colour1_width_dialog.GetValue();      //Getting colour1's width which is actually of long dataype                       
        
            BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
            BDP->draw_line = true;                      //Because now that the user has given all the required things so now we will let the user draw line
            BDP->line_sh = new Line;                    //Making a shape pointer that holds line's address
            
            BDP->line_sh->set_pen_brush(colour1, colour1);                   //Setting the colours of pen and brush bur for line there is no brush so colour1 is also brush here
            BDP->line_sh->set_pen_width(colour1_width);                      //Setting the width of pen

            wxMessageBox ("First click on the the point which you want to be Start of line and then click on End point of line", "Click on points");
        }
    }            
    //MSA CODE ENDS HERE
}


/*
 * Mnusketch1011Click
 */
void paintFrm::Mnusketch1011Click(wxCommandEvent& event)
{
	// insert your code here
	//MSA CODE STARTS HERE
	BasicDrawPane * BDP;
	BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
	
    if ( WxMenuBar1->IsChecked(1011) ) { //As sketch in menu is a check item so it has a function named IsChecked,in its parameter is id of sketch item of menu,IsChecked return either true or false  
	    BDP->sketch = true;              //Putting true in the boolean variable named sketch of BasicDrawPane
        wxMessageBox ( "After pressing OK choose colour of Pencil and press OK", "Choose Pencil colour");
        wxColourData data;
        wxColourData retData;
        
        data.SetChooseFull(true);                        //Doing some kinda initialization
        for (int i = 0; i < 16; i++) {
           wxColour colour(i*16, i*16, i*16);
           data.SetCustomColour(i, colour);
        }
        wxColourDialog pencil_colour_dialog(this, &data);             //Pencil colour dialog
        if (pencil_colour_dialog.ShowModal() == wxID_OK) {
            retData = pencil_colour_dialog.GetColourData();
            BDP->pencil_colour = retData.GetColour();             //Getting the colour and putting in the pencil_colour variable of BasicDrawPane
        }
    }
    else
       BDP->sketch = false;                  //Putting false in sketch because if sketch in uncheked in menu then it means we should not allow the user to sketch
       //Now see the mousemoved event of BasicDrawPane
    //MSA CODE ENDS HERE
}
