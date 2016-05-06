/***************************************************************
 * Name:      Matchplay_generatorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Fredrik Pudas (pudasremler@telia.com)
 * Created:   2016-05-04
 * Copyright: Fredrik Pudas ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Matchplay_generatorApp.h"
#include "Matchplay_generatorMain.h"

//#include "menubar.h"

player::player (std::string p_name, float p_hcp, int p_age, int p_golfid)
{
    hcp=p_hcp;
    age=p_age;
    name = p_name;
    golfid = p_golfid;
}

tee::tee (float tCR, int tcourse_par, int tslope_value, float tbogey_value, float tscratch_value)
{
    CR=tCR;
    course_par = tcourse_par;
    slope_value = tslope_value;
    bogey_value = tbogey_value;
    scratch_value = tscratch_value;

}



IMPLEMENT_APP(Matchplay_generatorApp);

bool Matchplay_generatorApp::OnInit()
{
    // Create the main application window
MpFrame *frame = new MpFrame(wxT("Minimal wxWidgets App"));
// Show it
frame->Show(true);
// Start the event loop
return true;

}


