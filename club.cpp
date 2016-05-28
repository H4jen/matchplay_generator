//This function helps user add a course to the databank.
#include "club.h"

void Add_club_to_data(WINDOW *menu_win)
{
    char club_name_cstr[80];
    string club_name;

    //clear mainscreen and window screen
    clear();
    refresh();
    wclear(menu_win);
    wrefresh(menu_win);

    //Get user inputs
    // This is for course name
    bool correct_club_entry = false;
    while(!correct_club_entry){
        mvwprintw(menu_win, 0, 0, "Enter club name:");
        wgetnstr(menu_win, club_name_cstr, 79);
        club_name.assign(club_name_cstr);

        if(!club_name.empty()) {
            correct_club_entry = true;
        }
        else{
            mvwprintw(menu_win, 1, 0, "Club name cannot be empty");
            char c = wgetch(menu_win);
        }

        wclear(menu_win);
        wrefresh(menu_win);
    }


    bool check_save_entry_choice = false;
    while(!check_save_entry_choice){
        mvwprintw(menu_win, 0, 0, "Save the following club?");
        mvwprintw(menu_win, 2, 0, "Club Name: %s",club_name.c_str());
        mvwprintw(menu_win, 4, 0, "[N] or [Y]: ");
        char c = wgetch(menu_win);

        if( c == 'y' || c == 'Y' ){
            check_save_entry_choice = true;
            Add_club_to_vector(club_name);
        }
        else if( c == 'n' || c == 'N') {
            check_save_entry_choice = true;
        }
    }

}

void Add_club_to_vector(string club_name)
{
    int id = 1;
    //Get next larger ID.
    for(std::vector<class club>::iterator it = clubs.begin(); it != clubs.end(); ++it) {
        if(it->get_clubid() >= id) id++;
    }

    //Store data in vector
    class club new_club(club_name,id);
    clubs.push_back(new_club);
}

void List_clubs_in_data(WINDOW *menu_win)
{
    //clear mainscreen and window screen
    clear();
    refresh();
    wclear(menu_win);
    wrefresh(menu_win);
    int i = 1;
    for(std::vector<class club>::iterator it = clubs.begin(); it != clubs.end(); ++it) {
        i++;
        mvwprintw(menu_win, 0, 0, "The following clubs are inte the data:");
        mvwprintw(menu_win, i, 0, "Club Name: %s", it->get_clubname().c_str());
        mvwprintw(menu_win, i, 35, "ID: %i",it->get_clubid());
    }
    char c = wgetch(menu_win);

}
