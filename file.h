#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include <fstream>
#include <iostream>
#include <vector>

#include "course.h"

using namespace std;

extern vector<course> courses;
extern vector<club> clubs;

void save_data();
void load_data();



#endif // FILE_H_INCLUDED
