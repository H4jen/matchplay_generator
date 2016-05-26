#ifndef CLUB_H_INCLUDED
#define CLUB_H_INCLUDED
using namespace std;
#include <curses.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "course.h"

extern vector<course> courses;
extern vector<club> clubs;

void Add_club_to_data(WINDOW *menu_win);
void Add_club_to_vector(std::string club_name);
void List_clubs_in_data(WINDOW *menu_win);

#endif // CLUB_H_INCLUDED
