///-----------------------------------------------------------------
///
/// @file      paintFrm.h
/// @author    Momina,Sana and Ammar
/// Created:   08/05/2019 3:48:43 AM
/// @section   DESCRIPTION
///            paintFrm class declaration
///
///------------------------------------------------------------------
//MSA includes start here
#include "classes.h"
#include "formulas.h"
#include "string-conversions.h"
#include <wx/colordlg.h>
//MSA includes end here


#ifndef __PAINTFRM_H__
#define __PAINTFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/menu.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef paintFrm_STYLE
#define paintFrm_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class paintFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		paintFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("paint"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = paintFrm_STYLE);
		virtual ~paintFrm();
		void Mnudrawtriangle1004Click(wxCommandEvent& event);
		void Mnudrawrectangle1005Click(wxCommandEvent& event);
		void Mnudrawsquare1006Click(wxCommandEvent& event);
		void Mnudrawcircle1007Click(wxCommandEvent& event);
		void Mnudrawline1009Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxMenuBar *WxMenuBar1;
		wxPanel *WxPanel1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_MNU_SHAPES_1003 = 1003,
			ID_MNU_DRAWTRIANGLE_1004 = 1004,
			ID_MNU_DRAWRECTANGLE_1005 = 1005,
			ID_MNU_DRAWSQUARE_1006 = 1006,
			ID_MNU_DRAWCIRCLE_1007 = 1007,
			ID_MNU_LINE_1008 = 1008,
			ID_MNU_DRAWLINE_1009 = 1009,
			
			ID_WXPANEL1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
