//---------------------------------------------------------------------------
//
// Name:        paintApp.h
// Author:      Momina,Sana and Ammar
// Created:     14/04/2019 11:58:34 AM
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
