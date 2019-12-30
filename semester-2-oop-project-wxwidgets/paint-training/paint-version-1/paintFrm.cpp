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
    
    int x_move = 100 ;
    int y_move = 500 ;

    // drawing some text
    dc.DrawText(wxT("team AMMAR , MOMINA AND SANA "), 40, 60); 
    
    // drawing a circle
    dc.SetBrush(*wxGREY_BRUSH); // green filling
    dc.SetPen( wxPen( wxColor(255,0,0), 5 ) ); // 5-pixels-thick red outline
    dc.DrawCircle( wxPoint(200,200), 100 /* radius */ );
    
    // drawing a rectangle
    dc.SetBrush(*wxBLUE_BRUSH); // blue filling
    dc.SetPen( wxPen( wxColor(255,175,175), 10 ) ); // 10-pixels-thick pink outline
    dc.DrawRectangle( 500, 100, 400, 200 );
    
    // drawing a triangle  no color filling because these are just lines
    dc.SetPen( wxPen( wxColor(230,0,0), 3 ) ); // black line, 3 pixels thick
    dc.DrawLine( 50+x_move, 50+y_move, 200+x_move, 200+y_move );
    //dc.SetPen( wxPen( wxColor(0,250,255), 3 ) );           //for changing the colour of this llne specifically
    dc.DrawLine( 50+x_move, 50+y_move, 0+x_move, 200+y_move );
   // dc.SetPen( wxPen( wxColor(0,255,255), 3 ) );           //for changing the colour of this llne specifically
    dc.DrawLine( 0+x_move, 200+y_move, 200+x_move, 200+y_move );
    
    // drawing a line
    dc.SetPen( wxPen( wxColor(0,0,0), 5 ) ); // black line, 5 pixels thick
    dc.DrawLine( 150, 500, 500, 500 );       //for straigh line y coordinates must be same and x should be different    //parameters are (x1, y1, x2, y2)
    
    // drawing a square using rectangle
    dc.SetBrush(*wxBLACK_BRUSH); // blue filling
    dc.SetPen( wxPen( wxColor(255,0,175), 10 ) ); // 10-pixels-thick pink outline
    dc.DrawRectangle( 600, 400, 150, 150 );       //parameters are (x, y, width, height)
    
    // Look at the wxDC docs to learn how to draw other stuff
}
//Drawing Ends Here
void paintFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	//WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(66, 15), wxSize(598, 347));
	WxPanel1 = new BasicDrawPane(this);

	SetTitle(_("paint"));
	SetIcon(wxNullIcon);
	SetSize(8,8,1200,900);
	Center();
	
	////GUI Items Creation End
	
	//MSA code starts here
	//MSA code ends here
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
