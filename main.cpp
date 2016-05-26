#include <stdio.h>
#include <curses.h>
#include "course.h"
#include "club.h"
#include "help_functions.h"

#define WIDTH 45
#define HEIGHT 15


int startx = 0;
int starty = 0;

//Main vectors to hold data of course players teams eg.
vector<course> courses;
vector<club> clubs;


const char *mainmenu_choices[] = {
			"Club Menu",
			"Course Menu",
			"Team Menu",
			"Player Menu",
			"Exit",
		  };

const char *clubmenu_choices[] = {
			"Add club",
			"List clubs",
			"Delete club",
			"Exit",
		  };

const char *coursemenu_choices[] = {
			"Add course",
			"List course",
			"Delete course",
			"Exit",
		  };


const char *teammenu_choices[] = {
			"Add team",
			"List teams",
			"Delete team",
			"Exit",
		  };

const char *playermenu_choices[] = {
			"Add player",
			"List player",
			"Delete player",
			"Exit",
		  };

int mainmenu_n_choices = sizeof(mainmenu_choices) / sizeof(const char *);
int clubmenu_n_choices = sizeof(clubmenu_choices) / sizeof(const char *);
int coursemenu_n_choices = sizeof(coursemenu_choices) / sizeof(const char *);
int teammenu_n_choices = sizeof(teammenu_choices) / sizeof(const char *);
int playermenu_n_choices = sizeof(playermenu_choices) / sizeof(const char *);

void print_mainmenu(WINDOW *menu_win, int highlight);
void print_clubmenu(WINDOW *menu_win, int highlight);
void print_coursemenu(WINDOW *menu_win, int highlight);
void print_teammenu(WINDOW *menu_win, int highlight);
void print_playermenu(WINDOW *menu_win, int highlight);

void main_menu(WINDOW *menu_win);
void club_menu(WINDOW *menu_win);
void course_menu(WINDOW *menu_win);
void team_menu(WINDOW *menu_win);
void player_menu(WINDOW *menu_win);

void Add_course_to_club(WINDOW *menu_win);



enum Menu_states {
    Main_menu = 0,
    Club_menu = 1,
    Course_menu = 2,
    Team_menu = 3,
    Player_menu = 4,
    Exit_program = 5
    };

enum Mainmenu_choices {
    No_choice = 0,
    Club = 1,
    Course = 2,
    Team = 3,
    Player = 4,
    Exit = 5,
    };

enum Clubmenu_choices {
    No_club_choice = 0,
    Add_club = 1,
    List_clubs= 2,
    Delete_club = 3,
    Exit_to_main_club = 4
    };

enum Coursemenu_choices {
    No_course_choice = 0,
    Add_course = 1,
    List_course= 2,
    Delete_course = 3,
    Exit_to_main_course = 4
    };

enum Teammenu_choices {
    No_team_choice = 0,
    Add_team = 1,
    List_teams = 2,
    Delete_team = 3,
    Exit_to_main_team = 4
    };

enum Playermenu_choices {
    No_player_choice = 0,
    Add_player = 1,
    List_players = 2,
    Delete_player = 3,
    Exit_to_main_player = 4
    };


//Global state to keep track of which menu that is selected
enum Menu_states Menu_state = Main_menu;


int main()
{	WINDOW *menu_win;
	initscr();
	clear();
	echo();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	bool go_main_loop = true;

    //Start state-machine
    while(go_main_loop == true){
        switch(Menu_state){
            case Main_menu:
                main_menu(menu_win);
                break;
            case Club_menu:
                club_menu(menu_win);
                break;
            case Course_menu:
                course_menu(menu_win);
                break;
            case Team_menu:
                team_menu(menu_win);
                break;
            case Player_menu:
                player_menu(menu_win);
                break;
            case Exit_program:
                go_main_loop = false;
                break;
            default:
                Menu_state = Main_menu;
                break;
        }
    }

	//Wrap-up when finished
	clrtoeol();
	refresh();
	endwin();
	return 0;
}


void main_menu(WINDOW *menu_win)
{
    int highlight = 1;
    int c;
    enum Mainmenu_choices choice = No_choice;


	print_mainmenu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = mainmenu_n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == mainmenu_n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case 10:
				choice = (enum Mainmenu_choices) highlight;
				break;
			default:
				mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_mainmenu(menu_win, highlight);
        refresh();
		if (choice != No_choice){
            switch(choice){
                case Club:
                    Menu_state = Club_menu;
                    return;
                case Course:
                    Menu_state = Course_menu;
                    return;
                case Team:
                    Menu_state = Team_menu;
                    return;
                case Player:
                    Menu_state = Player_menu;
                    return;
                case Exit:
                    Menu_state = Exit_program;
                    return;
                default:
                    Menu_state = Main_menu;
                    return;
                }
		}
	}
}

void club_menu(WINDOW *menu_win)
{
    int highlight = 1;
    int c;
    enum Clubmenu_choices choice = No_club_choice;


	print_clubmenu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = clubmenu_n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == clubmenu_n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case 10:
				choice = (enum Clubmenu_choices) highlight;
				break;
			default:
				mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_clubmenu(menu_win, highlight);
		if (choice != No_club_choice){
            switch(choice){
                case Add_club:
                    Add_club_to_data(menu_win);
                    Menu_state = Club_menu;
                    return;
                case List_clubs:
                    List_clubs_in_data(menu_win);
                    Menu_state = Club_menu;
                    return;
                case Delete_club:
                    Menu_state = Club_menu;
                    return;
                case Exit_to_main_club:
                    Menu_state = Main_menu;
                    return;
                default:
                    break;
                }
		}
	}
}

void course_menu(WINDOW *menu_win)
{
    int highlight = 1;
    int c;
    enum Coursemenu_choices choice = No_course_choice;


	print_coursemenu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = coursemenu_n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == coursemenu_n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case 10:
				choice = (enum Coursemenu_choices) highlight;
				break;
			default:
				mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_coursemenu(menu_win, highlight);
		if (choice != No_course_choice){
            switch(choice){
                case Add_course:
                    Add_course_to_club(menu_win);
                    Menu_state = Course_menu;
                    return;
                case List_course:
                    Menu_state = Course_menu;
                    return;
                case Delete_course:
                    Menu_state = Course_menu;
                    return;
                case Exit_to_main_course:
                    Menu_state = Main_menu;
                    return;
                default:
                    break;
                }
		}
	}
}



void team_menu(WINDOW *menu_win)
{
    int highlight = 1;
    int c;
    enum Teammenu_choices choice = No_team_choice;


	print_teammenu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = teammenu_n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == teammenu_n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case 10:
				choice = (enum Teammenu_choices) highlight;
				break;
			default:
				mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_teammenu(menu_win, highlight);
		if (choice != No_team_choice){
            switch(choice){
                case Add_team:
                    Menu_state = Team_menu;
                    return;
                case Delete_team:
                    Menu_state = Team_menu;
                    return;
                case List_teams:
                    Menu_state = Team_menu;
                    return;
                case Exit_to_main_team:
                    Menu_state = Main_menu;
                    return;
                default:
                    break;
                }
		}
	}
}

void player_menu(WINDOW *menu_win)
{
    int highlight = 1;
    int c;
    enum Playermenu_choices choice = No_player_choice;


	print_playermenu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = playermenu_n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == playermenu_n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case 10:
				choice = (enum Playermenu_choices) highlight;
				break;
			default:
				mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_playermenu(menu_win, highlight);
		if (choice != No_player_choice){
            switch(choice){
                case Add_player:
                    Menu_state = Player_menu;
                    return;
                case Delete_player:
                    Menu_state = Player_menu;
                    return;
                case List_players:
                    Menu_state = Player_menu;
                    return;
                case Exit_to_main_player:
                    Menu_state = Main_menu;
                    return;
                default:
                    break;
                }
		}
	}
}


void print_mainmenu(WINDOW *menu_win, int highlight)
{
	int x, y, i;
    wclear(menu_win);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();
	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < mainmenu_n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", mainmenu_choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", mainmenu_choices[i]);
        ++y;
	}
	wrefresh(menu_win);
}

void print_coursemenu(WINDOW *menu_win, int highlight)
{
	int x, y, i;
    wclear(menu_win);
    refresh();

    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < coursemenu_n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", coursemenu_choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", coursemenu_choices[i]);
        ++y;
	}
	wrefresh(menu_win);
}

void print_clubmenu(WINDOW *menu_win, int highlight)
{
	int x, y, i;
    wclear(menu_win);
    refresh();

    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < clubmenu_n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", clubmenu_choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", clubmenu_choices[i]);
        ++y;
	}
	wrefresh(menu_win);
}

void print_teammenu(WINDOW *menu_win, int highlight)
{

	int x, y, i;
    wclear(menu_win);
    refresh();

    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < teammenu_n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", teammenu_choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", teammenu_choices[i]);
        ++y;
	}
	wrefresh(menu_win);
}

void print_playermenu(WINDOW *menu_win, int highlight)
{
	int x, y, i;
    wclear(menu_win);
    refresh();

    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < playermenu_n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", playermenu_choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", playermenu_choices[i]);
        ++y;
	}
	wrefresh(menu_win);

}

//This function helps user add a course to the databank.
void Add_course_to_club(WINDOW *menu_win)
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
            mvwprintw(menu_win, 1, 0, "Wohoo we wanna save");
            char c = wgetch(menu_win);
        }
        else if( c == 'n' || c == 'N') {
            check_save_entry_choice = true;
        }
    }

}


