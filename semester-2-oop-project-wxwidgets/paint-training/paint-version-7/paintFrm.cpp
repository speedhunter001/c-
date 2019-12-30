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
    
    Point top_triangle, bottom_right_triangle, bottom_left_triangle, top_left_rect, bottom_right_rect, top_left_sq, bottom_right_sq, centre, point_on_circumference, start, end;
    
    Shapes * triangle_sh, * rectangle_sh, * square_sh, * circle_sh, * line_sh;
    
    int down_count_triangle;
    vector<Point> triangle_points;
    
    wxColour line_colour, pencil_colour;
    //MSA CODE ENDS HERE
    
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    
    void render(wxDC& dc);
    
    // some useful events
    
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     //void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     //void rightClick(wxMouseEvent& event);
     //void mouseLeftWindow(wxMouseEvent& event);
     //void keyPressed(wxKeyEvent& event);
     //void keyReleased(wxKeyEvent& event);
     
    
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
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
// EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 //EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 //EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 //EVT_KEY_UP(BasicDrawPane::keyReleased)
 //EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
 

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
            dc.DrawPoint(event.GetPosition());
            dc.SetPen(wxNullPen);   
        }
    }        
    //MSA CODE ENDS HERE
}
 void BasicDrawPane::mouseDown(wxMouseEvent& event) {
     wxPoint top_triangle_wxpoint, bottom_right_triangle_wxpoint, bottom_left_triangle_wxpoint, top_left_rect_wxpoint, top_left_sq_wxpoint, centre_wxpoint, start_wxpoint;
     int x,y;
       
    if ( draw_triangle == true ) {
        if ( down_count_triangle == 0 ) { 
            top_triangle_wxpoint = event.GetPosition();
            x = top_triangle_wxpoint.x;
            y = top_triangle_wxpoint.y;
            top_triangle.set_coordinates(x, y);
            
            triangle_points.push_back(top_triangle);
            down_count_triangle = 1;
        }
        else if ( down_count_triangle == 1 ) { 
            bottom_right_triangle_wxpoint = event.GetPosition();
            x = bottom_right_triangle_wxpoint.x;
            y = bottom_right_triangle_wxpoint.y;
            bottom_right_triangle.set_coordinates(x, y);
            
            triangle_points.push_back(bottom_right_triangle);
            down_count_triangle = 2;
        }
        else if ( down_count_triangle == 2 ) {
            vector<Point> empty;
             
            bottom_left_triangle_wxpoint = event.GetPosition();
            x = bottom_left_triangle_wxpoint.x;
            y = bottom_left_triangle_wxpoint.y;
            bottom_left_triangle.set_coordinates(x, y);
        
            triangle_points.push_back(bottom_left_triangle);
            down_count_triangle = 0;
            
            triangle_sh->set_points(triangle_points);
            all_shapes.push_back(triangle_sh);
        
            paintNow();
            triangle_points = empty;
            draw_triangle = false;
        }
    }
    else if ( draw_rectangle == true ) {
        top_left_rect_wxpoint = event.GetPosition();
        x = top_left_rect_wxpoint.x;
        y = top_left_rect_wxpoint.y;
        top_left_rect.set_coordinates(x, y);
    }
    else if ( draw_square == true ) {
        top_left_sq_wxpoint = event.GetPosition();
        x = top_left_sq_wxpoint.x;
        y = top_left_sq_wxpoint.y;
        top_left_sq.set_coordinates(x, y);
    }
    else if ( draw_circle == true ) {
        centre_wxpoint = event.GetPosition();
        x = centre_wxpoint.x;
        y = centre_wxpoint.y;
        centre.set_coordinates(x, y);
    }
    else if ( draw_line == true ) {
        start_wxpoint = event.GetPosition();
        x = start_wxpoint.x;
        y = start_wxpoint.y;
        start.set_coordinates(x, y);
    }
 }
 //void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
 void BasicDrawPane::mouseReleased(wxMouseEvent& event) {
     wxPoint bottom_right_rect_wxpoint, bottom_right_sq_wxpoint, point_on_circumference_wxpoint, end_wxpoint;
     int x,y;
     vector<Point> points;
     
    if ( draw_rectangle == true ) {
        bottom_right_rect_wxpoint = event.GetPosition();
        x = bottom_right_rect_wxpoint.x;
        y = bottom_right_rect_wxpoint.y;
        bottom_right_rect.set_coordinates(x, y);
        
        points.push_back(top_left_rect);
        points.push_back(bottom_right_rect);
        
        rectangle_sh->set_points(points);
        all_shapes.push_back(rectangle_sh);
        
        paintNow();
        draw_rectangle = false;
    }
    else if ( draw_square == true ) {
        bottom_right_sq_wxpoint = event.GetPosition();
        x = bottom_right_sq_wxpoint.x;
        y = bottom_right_sq_wxpoint.y;
        bottom_right_sq.set_coordinates(x, y);
        
        points.push_back(top_left_sq);
        points.push_back(bottom_right_sq);
        
        square_sh->set_points(points);
        all_shapes.push_back(square_sh);
        
        paintNow();
        draw_square = false;
    }
    else if ( draw_circle == true ) {
        point_on_circumference_wxpoint = event.GetPosition();
        x = point_on_circumference_wxpoint.x;
        y = point_on_circumference_wxpoint.y;
        point_on_circumference.set_coordinates(x, y);
        
        points.push_back(centre);
        points.push_back(point_on_circumference);
        
        circle_sh->set_points(points);
        all_shapes.push_back(circle_sh);
        
        paintNow();
        draw_circle = false;
    }
    else if ( draw_line == true ) {
        end_wxpoint = event.GetPosition();
        x = end_wxpoint.x;
        y = end_wxpoint.y;
        end.set_coordinates(x, y);
        
        points.push_back(start);
        points.push_back(end);
        
        line_sh->set_points(points);
        all_shapes.push_back(line_sh);
        
        paintNow();
        draw_line = false;
    }  
 }
 //void BasicDrawPane::rightClick(wxMouseEvent& event) {}
 //void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
 //void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
 //void BasicDrawPane::keyReleased(wxKeyEvent& event) {}
 

BasicDrawPane::BasicDrawPane(wxFrame* parent) :
wxPanel(parent)
{ 
    //MSA CODE STARTS HERE
    draw_triangle, draw_rectangle, draw_square, draw_circle, draw_line, sketch = false;
    down_count_triangle = 0;
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
	SetSize(1920, 1000);                                         //Parameters are (x, y, width, height) but no use of x and y because of Centre() in next line
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
	
	BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
    BDP->draw_triangle = true;
    BDP->triangle_sh = new Triangle;
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
                
                BDP->triangle_sh->set_pen_brush(colour1, colour2);                   //Setting the colours of pen and brush
                BDP->triangle_sh->set_pen_width(colour1_width);                      //Setting the width of pen
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
	
	BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
    BDP->draw_rectangle = true;
    BDP->rectangle_sh = new Rect;
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
                
                BDP->rectangle_sh->set_pen_brush(colour1, colour2);                   //Setting the colours of pen and brush
                BDP->rectangle_sh->set_pen_width(colour1_width);                      //Setting the width of pen
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
	
	BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
    BDP->draw_square = true;
    BDP->square_sh = new Square;
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
                
                BDP->square_sh->set_pen_brush(colour1, colour2);                   //Setting the colours of pen and brush
                BDP->square_sh->set_pen_width(colour1_width);                      //Setting the width of pen
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
	
	BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
    BDP->draw_circle = true;
    BDP->circle_sh = new Circle;
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
                
                BDP->circle_sh->set_pen_brush(colour1, colour2);                   //Setting the colours of pen and brush
                BDP->circle_sh->set_pen_width(colour1_width);                      //Setting the width of pen
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
	
    BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
    BDP->draw_line = true;
    BDP->line_sh = new Line;
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
        
            BDP->line_sh->set_pen_brush(colour1, colour1);                   //Setting the colours of pen and brush bur for line there is no brush so colour1 is also brush here
            BDP->line_sh->set_pen_width(colour1_width);                      //Setting the width of pen
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
