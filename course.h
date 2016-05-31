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
    string tee_name;
    float CR;
    int slope_value;
public:
    std::string get_tee_data_for_saving();
    tee (std::string,float, int);
};

class course {
    std::string name;
    std::vector<class tee> course_tees;
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
    std::string get_course_data_for_saving();
    //int area () {return (width*height);}
};

extern vector<club> clubs;
extern vector<course> courses;



#endif // COURSE_H_INCLUDED
