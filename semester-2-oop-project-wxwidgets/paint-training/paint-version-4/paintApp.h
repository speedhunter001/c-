//---------------------------------------------------------------------------
//
// Name:        paintApp.h
// Author:      Momina,Sana and Ammar
// Created:     08/05/2019 3:48:43 AM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __PAINTFRMApp_h__
#define __PAINTFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class paintFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
