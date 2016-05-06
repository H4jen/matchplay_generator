/***************************************************************
 * Name:      Matchplay_generatorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Fredrik Pudas (pudasremler@telia.com)
 * Created:   2016-05-04
 * Copyright: Fredrik Pudas ()
 * License:
 **************************************************************/

#ifndef MATCHPLAY_GENERATORMAIN_H
#define MATCHPLAY_GENERATORMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Matchplay_generatorApp.h"

#include <wx/menu.h>
#include <wx/button.h>
#include <wx/statline.h>




// Declare our main frame class
class MpFrame : public wxFrame
{
public:
// Constructor
MpFrame(const wxString& title);
// Event handlers
void OnQuit(wxCommandEvent& event);
void OnAbout(wxCommandEvent& event);
void AddCourse(wxCommandEvent& event);
void AddPlayer(wxCommandEvent& event);
private:
// This class handles events
DECLARE_EVENT_TABLE()
};



#endif // MATCHPLAY_GENERATORMAIN_H
