#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include <fstream>
#include <iostream>
#include <vector>

#include "course.h"
#include "club.h"

using namespace std;

extern vector<course> courses;
extern vector<club> clubs;
extern vector<tee> tees;

void save_data();
void load_data(WINDOW *menu_win);



#endif // FILE_H_INCLUDED
