//---------------------------------------------------------------------------
//
// Name:        paintApp.cpp
// Author:      Momina,Sana and Ammar
// Created:     08/05/2019 3:48:43 AM
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
