#include "course.h"

player::player (std::string p_name, int p_hcp, int p_age, int p_golfid)
{
    hcp=p_hcp;
    name = p_name;
    golfid = p_golfid;
}

tee::tee (std::string teename, int ttee_id,int tCR, int tslope_value,int tCR_w, int tslope_value_w, int tcourseid)
{
    tee_id = ttee_id;
    name = teename;
    CR=tCR;
    slope_value = tslope_value;
    CR_w=tCR_w;
    slope_value_w = tslope_value_w;
    course_id = tcourseid;

}

std::string course::get_course_data_for_saving() {
    std::string out_data, temp_data;
    out_data.empty();
    temp_data.empty();

    out_data = name + ";" + IntToString(course_par) + ";" + IntToString(course_id) + ";"+ "\n";
    return out_data;

}


std::string player::get_player_data_for_saving() {
    std::string out_data, temp_data;
    out_data.empty();
    temp_data.empty();

    out_data = name + ";" + IntToString(golfid) + ";" + IntToString(hcp) + ";"+ IntToString(club_id) + "\n";
    return out_data;

}

std::string club::get_club_data_for_saving() {
    std::string out_data, temp_data;
    out_data.empty();
    temp_data.empty();

    out_data = name + ";" + IntToString(club_id) + ";"+"\n";
    return out_data;

}

std::string tee::get_tee_data_for_saving() {
    std::string out_data;
    out_data.empty();
    out_data = name + ";" + FloatToString(CR) + ";" + IntToString(slope_value) + ";" + FloatToString(CR_w) + ";" + IntToString(slope_value_w) + ";" +IntToString(tee_id) + ";" + IntToString(course_id) + ";\n";
    return out_data;
}


std::string IntToString ( int number)
  {
    stringstream ss;
    ss << number;
    string str = ss.str();

    return str;
  }

std::string FloatToString ( float number)
  {
    stringstream ss;
    ss << number;
    string str = ss.str();

    return str;
  }

//This function helps user add a course to the databank.
void Add_course_to_data(WINDOW *menu_win)
{
    char course_name_cstr[80],course_par_cstr[80];
    string course_par, course_name;

    //clear mainscreen and window screen
    clear();
    refresh();
    wclear(menu_win);
    wrefresh(menu_win);

    //Get user inputs
    // This is for course name
    bool correct_course_entry = false;
    while(!correct_course_entry){
        mvwprintw(menu_win, 0, 0, "Enter course name:");
        wgetnstr(menu_win, course_name_cstr, 79);
        course_name.assign(course_name_cstr);

        if(!course_name.empty()) {
            correct_course_entry = true;
        }
        else{
            mvwprintw(menu_win, 1, 0, "Course name cannot be empty");
            wgetch(menu_win);
        }

        wclear(menu_win);
        wrefresh(menu_win);
    }

    //Check inputs and print for OK screen
    bool correct_par_entry = false;
    while(!correct_par_entry){
        mvwprintw(menu_win, 0, 0, "Enter course par:");
        wgetnstr(menu_win, course_par_cstr, 79);
        course_par.assign(course_par_cstr);

        //Check that the entry is a number and that the number is between 65 and 75.
        if(is_number(course_par,65,75)) {
            correct_par_entry = true;
        }
        else{
            mvwprintw(menu_win, 1, 0, "Course par needs to be a number between 65 and 75");
            wgetch(menu_win);
        }
        wclear(menu_win);
        wrefresh(menu_win);
    }

    bool check_save_entry_choice = false;
    while(!check_save_entry_choice){
        mvwprintw(menu_win, 0, 0, "Save the following course?");
        mvwprintw(menu_win, 2, 0, "Course Name: %s",course_name.c_str());
        mvwprintw(menu_win, 3, 0, "Course Par: %s",course_par.c_str());
        mvwprintw(menu_win, 5, 0, "[N] or [Y]: ");
        char c = wgetch(menu_win);
        if( c == 'y' || c == 'Y' ){
            Add_course_to_vector(course_name,str_to_num(course_par));
            check_save_entry_choice = true;

        }
        else if( c == 'n' || c == 'N') {
            check_save_entry_choice = true;
        }
    }

}

void Add_course_to_vector(std::string course_name, int course_id, int par)
{
    int id = 1;
    //Get next larger ID.
    for(std::vector<class course>::iterator it = courses.begin(); it != courses.end(); ++it) {
        if(it->get_courseid() >= id) id++;
    }

    //Store data in vector
    class course new_course(course_name,id,par);
    courses.push_back(new_course);
}

void Add_course_to_vector(std::string course_name, int par)
{
    int id = 1;
    //Get next larger ID.
    for(std::vector<class course>::iterator it = courses.begin(); it != courses.end(); ++it) {
        if(it->get_courseid() >= id) id++;
    }

    //Store data in vector
    class course new_course(course_name,id,par);
    courses.push_back(new_course);
}


void List_course_in_data(WINDOW *menu_win)
{
    //clear mainscreen and window screen
    clear();
    refresh();
    wclear(menu_win);
    wrefresh(menu_win);
    int i = 1;
    for(std::vector<class course>::iterator it = courses.begin(); it != courses.end(); ++it) {
        i++;
        mvwprintw(menu_win, 0, 0, "The following courses are in the data:");
        mvwprintw(menu_win, i, 0, "Course Name: %s", it->get_coursename().c_str());
        mvwprintw(menu_win, i, 35, "ID: %i",it->get_courseid());
    }
    wgetch(menu_win);

}



std::string find_course_name(int id_wanted)
{
    std::string course_name;

    for(std::vector<class course>::iterator it = courses.begin(); it != courses.end(); ++it) {
        int id = it->get_courseid();
        if (id_wanted == id) course_name=it->get_coursename();
    }
    return course_name;
}

int select_course(WINDOW *menu_win)
{
    //clear mainscreen and window screen
    clear();
    refresh();
    wclear(menu_win);
    wrefresh(menu_win);
    int i = 0;

    for(std::vector<class course>::iterator it = courses.begin(); it != courses.end(); ++it) {
        i++;
        mvwprintw(menu_win, 0, 0, "The following courses are in the data:");
        mvwprintw(menu_win, i, 0, "Course Name: %s", it->get_coursename().c_str());
        mvwprintw(menu_win, i, 35, "ID: %i",it->get_courseid());
    }

    mvwprintw(menu_win, i+2, 0, "Enter ID to select course:");
    char c = wgetch(menu_win);
    std::string temp_string;
    temp_string = c;
    int entered_id = str_to_num(temp_string);
    int selected_id = -1;
    if (entered_id <= 0) return -1;
    for(std::vector<class course>::iterator it = courses.begin(); it != courses.end(); ++it) {
        int id = it->get_courseid();
        if (entered_id == id) selected_id = id;
    }
    return selected_id;
}

void List_tee_in_data(WINDOW *menu_win)
{
    //clear mainscreen and window screen
    clear();
    refresh();
    wclear(menu_win);
    wrefresh(menu_win);
    int i = 1;

    //Select the course to add tee to.
    int sel_id = select_course(menu_win);
    if (sel_id == -1) return;

    std::string course_name = find_course_name(sel_id);
    clear();

    wclear(menu_win);
    wrefresh(menu_win);
    mvprintw(0, 0, "Selected course with id %i is: %s",sel_id,course_name.c_str());
    refresh();
    for(std::vector<class tee>::iterator it = tees.begin(); it != tees.end(); ++it) {
        if(sel_id == it->get_courseid()){
            i++;i++;

            mvwprintw(menu_win, 0, 0, "Tee's for course %s:",course_name.c_str());
            mvwprintw(menu_win, i, 0, "ID: %i Name: %s slope %i slope_w: %i cr %i cr_w: %i", it->get_teeid(),it->get_teename().c_str(),it->get_slope(),it->get_slope_women(),it->get_cr(),it->get_cr_women() );

        }
    }
    wgetch(menu_win);
}

void Add_tee_to_vector(std::string tee_name, int cr, int slope,int cr_w, int slope_w, int course_id)
{
    int id = 1;
    //Get next larger ID.
    for(std::vector<class tee>::iterator it = tees.begin(); it != tees.end(); ++it) {
        if(it->get_teeid() >= id) id++;
    }

    //Store data in vector
    class tee new_tee(tee_name,id,cr,slope,cr_w,slope_w,course_id);
    tees.push_back(new_tee);

}

void Add_tee_to_vector(std::string tee_name, int cr, int slope,int cr_w, int slope_w, int tee_id,int course_id)
{
    int id = 1;
    //Get next larger ID.
    for(std::vector<class tee>::iterator it = tees.begin(); it != tees.end(); ++it) {
        if(it->get_teeid() >= id) id++;
    }

    //Store data in vector
    class tee new_tee(tee_name,id,cr,slope,cr_w,slope_w,course_id);
    tees.push_back(new_tee);

}

void Add_tee_to_data(WINDOW *menu_win)
{
    char tee_name_cstr[80];
    char tee_slope_cstr[80];
    char tee_slope_w_cstr[80];
    char tee_cr_cstr[80];
    char tee_cr_w_cstr[80];
    std::string tee_name,course_par;
    std::string tee_slope,tee_cr;
    std::string tee_slope_w,tee_cr_w;


    //clear mainscreen and window screen
    clear();
    refresh();
    wclear(menu_win);
    wrefresh(menu_win);

    //Select the course to add tee to.
    int sel_id = select_course(menu_win);
    if (sel_id == -1) return;

    std::string course_name = find_course_name(sel_id);

    clear();

    wclear(menu_win);
    wrefresh(menu_win);
    mvprintw(0, 0, "Selected course with id %i is: %s",sel_id,course_name.c_str());
    refresh();

    //Get user inputs
    // This is for course name
    bool correct_tee_entry = false;
    while(!correct_tee_entry){
        mvwprintw(menu_win, 0, 0, "Enter tee name:");
        wgetnstr(menu_win, tee_name_cstr, 79);
        tee_name.assign(tee_name_cstr);

        if(!tee_name.empty()) {
            correct_tee_entry = true;
        }
        else{
            mvwprintw(menu_win, 1, 0, "Tee name cannot be empty");
            wgetch(menu_win);
        }

        wclear(menu_win);
        wrefresh(menu_win);
    }

    //Check inputs and print for OK screen
    bool correct_tee_cr_entry = false;
    bool correct_tee_slope_entry = false;
    while(!correct_tee_slope_entry){
        mvwprintw(menu_win, 0, 0, "Enter male tee slope rating:");
        wgetnstr(menu_win, tee_slope_cstr, 79);
        tee_slope.assign(tee_slope_cstr);

        //Check that the entry is a number and that the number is between 65 and 75.
        if(is_number(tee_slope_cstr,50,200)) {
            correct_tee_slope_entry = true;
        }
        else{
            mvwprintw(menu_win, 1, 0, "Tee slope needs to be a number between 50 and 200");
            wgetch(menu_win);
        }
        wclear(menu_win);
        wrefresh(menu_win);
    }
    correct_tee_slope_entry = false;
    wclear(menu_win);
    wrefresh(menu_win);
    while(!correct_tee_slope_entry){
        mvwprintw(menu_win, 0, 0, "Enter female tee slope rating:");
        wgetnstr(menu_win, tee_slope_w_cstr, 79);
        tee_slope_w.assign(tee_slope_w_cstr);

        //Check that the entry is a number and that the number is between 65 and 75.
        if(is_number(tee_slope_w_cstr,50,200)) {
            correct_tee_slope_entry = true;
        }
        else{
            mvwprintw(menu_win, 1, 0, "Tee slope needs to be a number between 50 and 200");
            wgetch(menu_win);
        }
        wclear(menu_win);
        wrefresh(menu_win);
    }
    wclear(menu_win);
    wrefresh(menu_win);
    while(!correct_tee_cr_entry ){
        mvwprintw(menu_win, 0, 0, "Enter male tee CR in 0.1 resol (ex. 67.4 = 674):");
        wgetnstr(menu_win, tee_cr_cstr, 79);
        tee_cr.assign(tee_cr_cstr);

        //Check that the entry is a number and that the number is between 65 and 75.
        if(is_number(tee_cr_cstr,500,900)) {
            correct_tee_cr_entry = true;
        }
        else{
            mvwprintw(menu_win, 1, 0, "Tee CR needs to be a number between 500 and 900");
            wgetch(menu_win);
        }
        wclear(menu_win);
        wrefresh(menu_win);
    }
    wclear(menu_win);
    wrefresh(menu_win);
    correct_tee_cr_entry = false;
    while(!correct_tee_cr_entry ){
        mvwprintw(menu_win, 0, 0, "Enter female tee CR in 0.1 resol (ex. 67.4 = 674):");
        wgetnstr(menu_win, tee_cr_w_cstr, 79);
        tee_cr_w.assign(tee_cr_w_cstr);

        //Check that the entry is a number and that the number is between 65 and 75.
        if(is_number(tee_cr_w_cstr,500,900)) {
            correct_tee_cr_entry = true;
        }
        else{
            mvwprintw(menu_win, 1, 0, "Tee CR needs to be a number between 500 and 900");
            wgetch(menu_win);
        }
        wclear(menu_win);
        wrefresh(menu_win);
    }

    bool check_save_entry_choice = false;
    while(!check_save_entry_choice){
        mvwprintw(menu_win, 0, 0, "Save the following tee?");
        mvwprintw(menu_win, 2, 0, "Tee Name: %s",tee_name.c_str());
        mvwprintw(menu_win, 3, 0, "Tee rating male(CR): %s",tee_cr.c_str());
        mvwprintw(menu_win, 4, 0, "Tee rating female(CR): %s",tee_cr_w.c_str());
        mvwprintw(menu_win, 5, 0, "Tee slope male: %s",tee_slope.c_str());
        mvwprintw(menu_win, 6, 0, "Tee slope female: %s",tee_slope_w.c_str());
        mvwprintw(menu_win, 7, 0, "Course id: %i",sel_id);
        mvwprintw(menu_win, 9, 0, "[N] or [Y]: ");
        char c = wgetch(menu_win);
        if( c == 'y' || c == 'Y' ){
            Add_tee_to_vector(tee_name,str_to_num(tee_cr),str_to_num(tee_slope),str_to_num(tee_cr_w),str_to_num(tee_slope_w),sel_id);
            check_save_entry_choice = true;

        }
        else if( c == 'n' || c == 'N') {
            check_save_entry_choice = true;
        }
    }

}


