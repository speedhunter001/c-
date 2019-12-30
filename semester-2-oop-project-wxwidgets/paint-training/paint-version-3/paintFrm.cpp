///-----------------------------------------------------------------
///
/// @file      paintFrm.cpp
/// @author    Momina,Sana and Ammar
/// Created:   14/04/2019 11:58:35 AM
/// @section   DESCRIPTION
///            paintFrm class implementation
///
///------------------------------------------------------------------

#include "paintFrm.h"

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
	
	EVT_UPDATE_UI(ID_WXPANEL1,paintFrm::WxPanel1UpdateUI)
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

//Drawing Starts from here
class BasicDrawPane : public wxPanel
{
//MSA CODE STARTS HERE
private:
    vector<Shapes*> all_shapes;
//MSA CODE ENDS HERE
public:
    BasicDrawPane(wxFrame* parent);
    
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    
    void render(wxDC& dc);
    
    // some useful events
    
     void mouseMoved(wxMouseEvent& event);
   /*  void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
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
/* EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
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

//pencil 
 void BasicDrawPane::mouseMoved(wxMouseEvent& event) {
    if ( event.Dragging() ) {
        wxClientDC dc(this);
        /*wxPen pen(*wxRED, 1); // red pen of width 100
        dc.SetPen(pen);   */ //  or
        dc.SetPen( wxPen(wxColor(230,0,0), 1) ); 
        dc.DrawPoint(event.GetPosition());
        dc.SetPen(wxNullPen);   
    }
}
/* void BasicDrawPane::mouseDown(wxMouseEvent& event) {}
 void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
 void BasicDrawPane::mouseReleased(wxMouseEvent& event) {}
 void BasicDrawPane::rightClick(wxMouseEvent& event) {}
 void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
 void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
 void BasicDrawPane::keyReleased(wxKeyEvent& event) {}
 */

BasicDrawPane::BasicDrawPane(wxFrame* parent) :
wxPanel(parent)
{ 
    Shapes * square_sh = new Square;
    Shapes * rect_sh = new Rect;
    Shapes * circle_sh = new Circle;
    Shapes * line_sh = new Line;
    Shapes * triangle_sh = new Triangle;
    
    vector<Point> v1, v2, v3, v4, v5;
    Point top_left_sq, bottom_right_sq, top_left_rect, bottom_right_rect, centre, circumference_point, starting, ending, top, bottom_left, bottom_right;
    //for square
    top_left_sq.set_coordinates(50,50);          
    bottom_right_sq.set_coordinates(300,300);
    v1.push_back(top_left_sq);
    v1.push_back(bottom_right_sq);
    //for rectangle
    top_left_rect.set_coordinates(400,50);          
    bottom_right_rect.set_coordinates(630,100);
    v2.push_back(top_left_rect);
    v2.push_back(bottom_right_rect);
    //for circle
    centre.set_coordinates(300,500);          
    circumference_point.set_coordinates(200,500);
    v3.push_back(centre);
    v3.push_back(circumference_point);
    //for line
    starting.set_coordinates(500,400);          
    ending.set_coordinates(700,400);
    v4.push_back(starting);
    v4.push_back(ending);
    //for triangle
    top.set_coordinates(800,100);
    bottom_left.set_coordinates(700,200);
    bottom_right.set_coordinates(900,200);
    v5.push_back(top);
    v5.push_back(bottom_left);
    v5.push_back(bottom_right);
    
    //now setting the vector of points inside each corresponding shape
    square_sh->set_points(v1);
    circle_sh->set_points(v3);
    rect_sh->set_points(v2);
    line_sh->set_points(v4);
    triangle_sh->set_points(v5);
    
    //now pushing all the shapes in the all_shapes vector
    all_shapes.push_back(square_sh);
    all_shapes.push_back(circle_sh);
    all_shapes.push_back(rect_sh);
    all_shapes.push_back(line_sh);
    all_shapes.push_back(triangle_sh);
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
    vector<Point> v;
    int width, height, radius;
    
    // drawing some text
   // dc.DrawText(wxT("team AMMAR , MOMINA AND SANA "), 40, 60); 
    
    // Look at the wxDC docs to learn how to draw other stuff
    
    //MSA CODE STARTS HERE
     for( Shapes * shape : all_shapes ){
        v = shape->get_points();
        if ( shape->get_shape_type() == "SQUARE" ) {
            dc.SetPen( wxPen( wxColor(230,0,0), 3 ) ); // black line, 3 pixels thick
            dc.SetBrush(*wxRED_BRUSH); // black filling
            width = get_width( v[0].get_x(), v[1].get_x() );
            height = get_height( v[0].get_y(), v[1].get_y() );
            dc.DrawRectangle( v[0].get_x(), v[0].get_y(), width, height);  //parameters are ( x, y, width, height )
        }
        else if ( shape->get_shape_type() == "RECTANGLE" ) {
            dc.SetPen( wxPen( wxColor(230,0,0), 3 ) ); // black line, 3 pixels thick
            dc.SetBrush(*wxGREEN_BRUSH); // black filling
            width = get_width( v[0].get_x(), v[1].get_x() );
            height = get_height( v[0].get_y(), v[1].get_y() );
            dc.DrawRectangle( v[0].get_x(), v[0].get_y(), width, height);      //parameters are ( x, y, width, height )
        }
        else if ( shape->get_shape_type() == "CIRCLE" ) {
            dc.SetBrush(*wxGREY_BRUSH);                     // grey filling
            dc.SetPen( wxPen( wxColor(255,0,0), 5 ) );            // 5-pixels-thick red outline          
            radius = get_distance( v[0].get_x(), v[0].get_y(), v[1].get_x(), v[1].get_y() );
            dc.DrawCircle( wxPoint( v[0].get_x(), v[0].get_y() ), radius );      //parameters are ( wxPoint(x, y), radius )
        }
        else if ( shape->get_shape_type() == "LINE" ) {
            // drawing a line
            dc.SetPen( wxPen( wxColor(0,0,0), 5 ) ); // black line, 5 pixels thick
            dc.DrawLine( v[0].get_x(), v[0].get_y(), v[1].get_x(), v[1].get_y() );       //for straigh line y coordinates must be same and x should be different    //parameters are (x1, y1, x2, y2)
        }
        else if ( shape->get_shape_type() == "TRIANGLE" ) { 
            dc.SetPen( wxPen( wxColor(102,0,51), 5 ) ); // black line, 5 pixels thick
            dc.SetBrush(*wxBLUE_BRUSH); // grey filling
    
            wxPoint triangle[3];
            triangle[0] = wxPoint( v[0].get_x(), v[0].get_y() );
            triangle[1] = wxPoint( v[1].get_x(), v[1].get_y() );
            triangle[2] = wxPoint( v[2].get_x(), v[2].get_y() );            
            dc.DrawPolygon( 3, triangle );
        }
    }
    //MSA CODE ENDS HERE

}
//Drawing Ends Here
void paintFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start0

	//WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(66, 15), wxSize(598, 347));
	WxPanel1 = new BasicDrawPane(this);

	SetTitle(_("Splash!"));
	SetIcon(wxNullIcon);
	SetSize(8,8,1200,700);
	Center();
	
	////GUI Items Creation End
}

void paintFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxPanel1UpdateUI
 */
void paintFrm::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
	// insert your code here
}
