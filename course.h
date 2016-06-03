#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
using namespace std;

#include <iostream>
#include <vector>
#include <sstream>
#include <curses.h>
#include "help_functions.h"

std::string IntToString ( int number);
std::string FloatToString ( float number);

void Add_course_to_data(WINDOW *menu_win);
void Add_course_to_vector(std::string club_name,int par);
void Add_course_to_vector(std::string club_name,int course_id, int par);
void List_course_in_data(WINDOW *menu_win);

void Add_tee_to_data(WINDOW *menu_win);
void Add_tee_to_vector(std::string tee_name, int cr, int slope,int cr_w, int slope_w,int course_id);
void Add_tee_to_vector(std::string tee_name, int cr, int slope,int cr_w, int slope_w, int tee_id,int course_id);
void List_tee_in_data(WINDOW *menu_win);


class player {
    int hcp;
    std::string name;
    int golfid;
    int club_id;
public:
    player (std::string, int, int, int);
    std::string get_player_data_for_saving();
    //int area () {return (width*height);}
};

class tee {
    string name;
    int CR,CR_w;
    int slope_value,slope_value_w;
    int tee_id;
    int course_id; //Contains the course this tee belongs to
public:
    tee (std::string,int,int,int,int,int,int);
    std::string get_tee_data_for_saving();
    std::string get_teename(){return name;}
    int get_teeid() {return tee_id;}
    int get_slope() {return slope_value;}
    int get_slope_women() {return slope_value_w;}
    int get_cr() {return CR;}
    int get_cr_women() {return CR_w;}
    int get_courseid() {return course_id;}
};

class course {
    std::string name;
    int course_par;
    int course_id;
public:
    std::string get_course_data_for_saving();
    int get_courseid() {return course_id;}
    std::string get_coursename(){return name;}
    course (std::string c_name, int id, int par){ name = c_name;course_par = par;course_id=id;}

    //int area () {return (width*height);}
};

class club {
    std::string name;
    int club_id;
  public:
    club (std::string c_name, int id){ name = c_name;club_id = id; }
    std::string get_club_data_for_saving();
    int get_clubid(){return club_id;}
    std::string get_clubname(){return name;}
    //int area () {return (width*height);}
};

extern vector<club> clubs;
extern vector<course> courses;
extern vector<tee> tees;
extern vector<player> players;



#endif // COURSE_H_INCLUDED
