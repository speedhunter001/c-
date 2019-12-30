///-----------------------------------------------------------------
///
/// @file      paintFrm.cpp
/// @author    Momina,Sana and Ammar
/// Created:   08/05/2019 3:48:43 AM
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
	EVT_MENU(ID_MNU_DRAWTRIANGLE_1004, paintFrm::Mnudrawtriangle1004Click)
	EVT_MENU(ID_MNU_DRAWRECTANGLE_1005, paintFrm::Mnudrawrectangle1005Click)
	EVT_MENU(ID_MNU_DRAWSQUARE_1006, paintFrm::Mnudrawsquare1006Click)
	EVT_MENU(ID_MNU_DRAWCIRCLE_1007, paintFrm::Mnudrawcircle1007Click)
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
    //MSA CODE ENDS HERE
    
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
	
	wxMenu *ID_MNU_LINE_1008_Mnu_Obj = new wxMenu();
	ID_MNU_LINE_1008_Mnu_Obj->Append(ID_MNU_DRAWLINE_1009, _("Draw Line"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_LINE_1008_Mnu_Obj, _("Line "));
	SetMenuBar(WxMenuBar1);

	SetTitle(_("paint"));
	SetIcon(wxNullIcon);
	SetSize(8,8,1500,900);
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
	vector<int> points_int;
	Point top, bottom_left, bottom_right;
	vector<Point> points;
	Shapes * triangle_sh = new Triangle;
	BasicDrawPane * BDP;
	
    wxTextEntryDialog dlg(this, "Write Top,Bottom left and Bottom right points", "Enter points", "x1,y1,x2,y2,x3,y3");
    //dlg.SetTextValidator(wxFILTER_ALPHA);
    if ( dlg.ShowModal() == wxID_OK ){
        wxString points_wxstr = dlg.GetValue();                         //Getting the wxstring from the dialog box which the user entered
        const char * no_idea = points_wxstr.mb_str();                   //Conveting the wxstring into string     
        string points_str = no_idea;
        points_int = string_to_int(points_str);                         //Converting the string into integers(this function returns a vector of integers)

        top.set_coordinates( points_int[0], points_int[1] );           //Setting the points
        bottom_left.set_coordinates( points_int[2], points_int[3] );
        bottom_right.set_coordinates( points_int[4], points_int[5] );
        points.push_back(top);                                          //Pushing the points in the vetor of Points
        points.push_back(bottom_left);
        points.push_back(bottom_right);
        
        triangle_sh->set_points(points);                                //Setting the points of triangle by pushing the vector of Points
        
        BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
        BDP->all_shapes.push_back(triangle_sh);         //now acessing the vector of all shapes pointer and pushing in it the shape pointer which holds triangle's address
        BDP->paintNow();                                                //now calling the render() through paintNow() because the CreateGuiControls calls render at runtime  
    }
}

/*
 * Mnudrawrectangle1005Click
 */
void paintFrm::Mnudrawrectangle1005Click(wxCommandEvent& event)
{
	// insert your code here
	vector<int> points_int;
	Point top_left, bottom_right;
	vector<Point> points;
	Shapes * rectangle_sh = new Rect;
	BasicDrawPane * BDP;
	
    wxTextEntryDialog dlg(this, "Write Top left and Bottom right points", "Enter points", "x1,y1,x3,y3");
    //dlg.SetTextValidator(wxFILTER_ALPHA);
    if ( dlg.ShowModal() == wxID_OK ){
        wxString points_wxstr = dlg.GetValue();                         //Getting the wxstring from the dialog box which the user entered
        const char * no_idea = points_wxstr.mb_str();                   //Conveting the wxstring into string
        string points_str = no_idea;    
        points_int = string_to_int(points_str);                         //Converting the string into integers(this function returns a vector of integers)
    
        top_left.set_coordinates( points_int[0], points_int[1] );           //Setting the points          
        bottom_right.set_coordinates( points_int[2], points_int[3] );
        points.push_back(top_left);                                          //Pushing the points in the vetor of Points
        points.push_back(bottom_right);
    
        rectangle_sh->set_points(points);                                //Setting the points of rectangle by pushing the vector of Points
        
        BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
        BDP->all_shapes.push_back(rectangle_sh);//now acessing the vector of all shapes pointer and pushing in it the shape pointer which holds rectangle's address
        BDP->paintNow();                             //now calling the render() through paintNow() because the CreateGuiControls calls render at runtime  

    }
}

/*
 * Mnudrawsquare1006Click
 */
void paintFrm::Mnudrawsquare1006Click(wxCommandEvent& event)
{
	// insert your code here
	vector<int> points_int;
	Point top_left, bottom_right;
	vector<Point> points;
	Shapes * square_sh = new Square;
	BasicDrawPane * BDP;
	
    wxTextEntryDialog dlg(this, "Write Top left and Bottom right points", "Enter points", "x1,y1,x3,y3");
    //dlg.SetTextValidator(wxFILTER_ALPHA);
    if ( dlg.ShowModal() == wxID_OK ){
        wxString points_wxstr = dlg.GetValue();                         //Getting the wxstring from the dialog box which the user entered
        const char * no_idea = points_wxstr.mb_str();                   //Conveting the wxstring into string
        string points_str = no_idea;    
        points_int = string_to_int(points_str);                         //Converting the string into integers(this function returns a vector of integers)
    
        top_left.set_coordinates( points_int[0], points_int[1] );           //Setting the points          
        bottom_right.set_coordinates( points_int[2], points_int[3] );
        points.push_back(top_left);                                          //Pushing the points in the vetor of Points
        points.push_back(bottom_right);
    
        square_sh->set_points(points);                                //Setting the points of square by pushing the vector of Points
        
        BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
        BDP->all_shapes.push_back(square_sh);//now acessing the vector of all shapes pointer and pushing in it the shape pointer which holds square's address
        BDP->paintNow();                             //now calling the render() through paintNow() because the CreateGuiControls calls render at runtime  
    }    
}

/*
 * Mnudrawcircle1007Click
 */
void paintFrm::Mnudrawcircle1007Click(wxCommandEvent& event)
{
	// insert your code here
	vector<int> points_int;
	Point centre, point_on_circumference;
	vector<Point> points;
	Shapes * circle_sh = new Circle;
	BasicDrawPane * BDP;
	
    wxTextEntryDialog dlg(this, "Write Centre point and any point on circumference", "Enter points", "x1,y1,x2,y2");
    //dlg.SetTextValidator(wxFILTER_ALPHA);
    if ( dlg.ShowModal() == wxID_OK ){
        wxString points_wxstr = dlg.GetValue();                         //Getting the wxstring from the dialog box which the user entered
        const char * no_idea = points_wxstr.mb_str();                   //Conveting the wxstring into string
        string points_str = no_idea;    
        points_int = string_to_int(points_str);                         //Converting the string into integers(this function returns a vector of integers)
    
        centre.set_coordinates( points_int[0], points_int[1] );                 //Setting the points          
        point_on_circumference.set_coordinates( points_int[2], points_int[3] );
        points.push_back(centre);                                             //Pushing the points in the vetor of Points
        points.push_back(point_on_circumference);
    
        circle_sh->set_points(points);                                //Setting the points of circle by pushing the vector of Points
        
        BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
        BDP->all_shapes.push_back(circle_sh);//now acessing the vector of all shapes pointer and pushing in it the shape pointer which holds circle's address
        BDP->paintNow();                             //now calling the render() through paintNow() because the CreateGuiControls calls render at runtime  
    }
}


/*
 * Mnudrawline1009Click
 */
void paintFrm::Mnudrawline1009Click(wxCommandEvent& event)
{
	// insert your code here
	vector<int> points_int;
	Point start, end;
	vector<Point> points;
	Shapes * line_sh = new Line;
	BasicDrawPane * BDP;
	
    wxTextEntryDialog dlg(this, "Write starting and ending points", "Enter points", "x1,y1,x2,y2");
    //dlg.SetTextValidator(wxFILTER_ALPHA);
    if ( dlg.ShowModal() == wxID_OK ){
        wxString points_wxstr = dlg.GetValue();                         //Getting the wxstring from the dialog box which the user entered
        const char * no_idea = points_wxstr.mb_str();                   //Conveting the wxstring into string
        string points_str = no_idea;    
        points_int = string_to_int(points_str);                         //Converting the string into integers(this function returns a vector of integers)
    
        start.set_coordinates( points_int[0], points_int[1] );                 //Setting the points          
        end.set_coordinates( points_int[2], points_int[3] );
        points.push_back(start);                                             //Pushing the points in the vetor of Points
        points.push_back(end);
    
        line_sh->set_points(points);                                //Setting the points of line by pushing the vector of Points
        
        BDP = static_cast<BasicDrawPane*>(WxPanel1);//Casting the address of parent(child's address) to child(child's address)  parent=WxPanel  child=BasicDrawPane
        BDP->all_shapes.push_back(line_sh);//now acessing the vector of all shapes pointer and pushing in it the shape pointer which holds line's address
        BDP->paintNow();                             //now calling the render() through paintNow() because the CreateGuiControls calls render at runtime  
    }
}
