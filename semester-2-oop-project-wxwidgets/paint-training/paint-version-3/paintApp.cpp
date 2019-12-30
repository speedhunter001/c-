//---------------------------------------------------------------------------
//
// Name:        paintApp.cpp
// Author:      Momina,Sana and Ammar
// Created:     14/04/2019 11:58:34 AM
// Description: 
//
//---------------------------------------------------------------------------

#include "paintApp.h"
#include "paintFrm.h"

IMPLEMENT_APP(paintFrmApp)

bool paintFrmApp::OnInit()
{
    paintFrm* frame = new paintFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int paintFrmApp::OnExit()
{
	return 0;
}
