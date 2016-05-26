#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
using namespace std;

#include <iostream>
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
    int slope_value;
    float bogey_value;
    float scratch_value;
public:
    tee (float, int, float,float);
};

class course {
    std::string name;
    std::vector<class tee> course_tees;
    int course_par;
    int course_id;
public:
    course (std::string c_name, int par){ name = c_name;course_par = par;}

    //int area () {return (width*height);}
};

class club {
    std::string name;
    vector<course> courses;
    int club_id;
  public:
    club (std::string c_name, int id){ name = c_name;club_id = id; }
    int get_clubid(){return club_id;}
    std::string get_clubname(){return name;}
    //int area () {return (width*height);}
};




#endif // COURSE_H_INCLUDED
