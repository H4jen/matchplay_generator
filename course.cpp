#include "course.h"

player::player (std::string p_name, float p_hcp, int p_age, int p_golfid)
{
    hcp=p_hcp;
    age=p_age;
    name = p_name;
    golfid = p_golfid;
}

tee::tee (std::string name, float tCR, int tslope_value)
{
    tee_name = name;
    CR=tCR;
    slope_value = tslope_value;
}

std::string course::get_course_data_for_saving() {
    std::string out_data, temp_data;
    out_data.empty();
    temp_data.empty();

    out_data = name + ";" + IntToString(course_par) + ";" + IntToString(course_id) + ";" + IntToString(course_par) + "\n";
    for(std::vector<class tee>::iterator it = course_tees.begin(); it != course_tees.end(); ++it) {
        temp_data=it->get_tee_data_for_saving();
        out_data = out_data + temp_data.c_str() + "\n";
        temp_data.empty();
    }

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

    out_data = tee_name + ";" + FloatToString(CR) + ";" + IntToString(slope_value) + "\n";
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
            char c = wgetch(menu_win);
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
            char c = wgetch(menu_win);
        }
        wclear(menu_win);
        wrefresh(menu_win);
    }

    bool check_save_entry_choice = false;
    while(!check_save_entry_choice){
        mvwprintw(menu_win, 0, 0, "Save the following course?");
        mvwprintw(menu_win, 2, 0, "Course Name: %s",course_name.c_str());
        mvwprintw(menu_win, 3, 0, "Course Par: %s",course_par.c_str());
        mvwprintw(menu_win, 5, 0, "[Y]: ");
        char c = wgetch(menu_win);
        if( c == 'y' || c == 'Y' ){

            check_save_entry_choice = true;

        }
        else if( c == 'n' || c == 'N') {
            check_save_entry_choice = true;
        }
    }

}


