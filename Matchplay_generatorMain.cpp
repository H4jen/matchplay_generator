/***************************************************************
 * Name:      Matchplay_generatorMain.cpp
 * Purpose:   Code for Application Frame
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

#include "Matchplay_generatorMain.h"
#include "mondian.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

// this is a definition so can't be in a header
wxDEFINE_EVENT(wxID_ADDCOURSE, wxCommandEvent);
wxDEFINE_EVENT(wxID_ADDPLAYER, wxCommandEvent);

// Event table for MyFrame
BEGIN_EVENT_TABLE(MpFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MpFrame::OnAbout)
    EVT_MENU(wxID_EXIT, MpFrame::OnQuit)
    EVT_MENU(wxID_ADDCOURSE, MpFrame::AddCourse)
    EVT_MENU(wxID_ADDPLAYER, MpFrame::AddPlayer)
END_EVENT_TABLE()

void MpFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("Hello and welcome to %s"),wxVERSION_STRING);
    wxMessageBox(msg, wxT("About Minimal"),wxOK | wxICON_INFORMATION, this);
}

void MpFrame::OnQuit(wxCommandEvent& event)
{
// Destroy the frame
Close();
}

void MpFrame::AddCourse(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("wfwef%s"),wxVERSION_STRING);
    wxMessageBox(msg, wxT("Add course"),wxOK | wxICON_INFORMATION, this);
}

void MpFrame::AddPlayer(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("Add a player%s"),wxVERSION_STRING);
    wxMessageBox(msg, wxT("Add player"),wxOK | wxICON_INFORMATION, this);
}



MpFrame::MpFrame(const wxString& title): wxFrame(NULL, wxID_ANY, title)
{
// Set the frame icon
SetIcon(wxIcon(mondrian_xpm));
// Create a menu bar
wxMenu *fileMenu = new wxMenu;
// The “About” item should be in the help menu
wxMenu *helpMenu = new wxMenu;
// The “add” item should be in the help menu
wxMenu *addMenu = new wxMenu;

helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"),wxT("Show about dialog"));
fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"),wxT("Quit this program"));
addMenu->Append(wxID_ADDCOURSE, wxT("Add course"),wxT("Add course"));
addMenu->Append(wxID_ADDPLAYER, wxT("Add player"),wxT("Add player"));
// Now append the freshly created menu to the menu bar...
wxMenuBar *menuBar = new wxMenuBar();
menuBar->Append(fileMenu, wxT("&File"));
menuBar->Append(helpMenu, wxT("&Help"));
menuBar->Append(addMenu, wxT("&Add"));

// ... and attach this menu bar to the frame
SetMenuBar(menuBar);
// Create a status bar just for fun
CreateStatusBar(2);
SetStatusText(wxT("Welcome to wxWidgets!"));
}








