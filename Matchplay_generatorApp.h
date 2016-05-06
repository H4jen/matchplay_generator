/***************************************************************
 * Name:      Matchplay_generatorApp.h
 * Purpose:   Defines Application Class
 * Author:    Fredrik Pudas (pudasremler@telia.com)
 * Created:   2016-05-04
 * Copyright: Fredrik Pudas ()
 * License:
 **************************************************************/

#ifndef MATCHPLAY_GENERATORAPP_H
#define MATCHPLAY_GENERATORAPP_H

#include <wx/app.h>
#include <string>
#include <vector>




class player {
    float hcp;
    int age;
    std::string name;
    int golfid;
  public:
    player (std::string, float, int, int);
    //int area () {return (width*height);}
};

class tee {
    float CR;
    int course_par;
    int slope_value;
    float bogey_value;
    float scratch_value;
  public:
    tee (float, int, int, float,float);
};

class course {
    std::string name;
    std::vector<class tee> course_tees;
  public:
    course (std::string c_name){ name = c_name;}
    //int area () {return (width*height);}
};

class club {
    std::string name;
    std::vector<class player> club_players;
  public:
    club (std::string c_name){ name = c_name; }
    //int area () {return (width*height);}
};


class Matchplay_generatorApp : public wxApp
{
    public:
        virtual bool OnInit();
};





#endif // MATCHPLAY_GENERATORAPP_H
