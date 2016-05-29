#include "file.h"
#define CLUBFILE "save_data_clubs.txt"
#define COURSEFILE "save_data_courses.txt"



void save_data_clubs(){
    // open a file in write mode.
    ofstream outfile;
    outfile.open(CLUBFILE);

    // write inputted data into the file.
    std::string temp_data;
    std::string save_data;
    temp_data.empty();
    save_data.empty();


    for(std::vector<class club>::iterator it = clubs.begin(); it != clubs.end(); ++it) {
        temp_data=it->get_club_data_for_saving();
        outfile << temp_data.c_str();
        temp_data.empty();
    }
    outfile.close();

    //save_data = courses->get_course_data_for_saving();
    //outfile << courses << endl;
}

void save_data_courses(){
    // open a file in write mode.
    ofstream outfile;
    outfile.open(COURSEFILE);

    // write inputted data into the file.
    std::string temp_data;
    std::string save_data;
    temp_data.empty();
    save_data.empty();


    for(std::vector<class course>::iterator it = courses.begin(); it != courses.end(); ++it) {
        temp_data=it->get_course_data_for_saving();
        outfile << temp_data.c_str();
        temp_data.empty();
    }
    outfile.close();

    //save_data = courses->get_course_data_for_saving();
    //outfile << courses << endl;
}

void load_data_clubs(WINDOW *menu_win){
    // open a file in read mode.
    std::string line;

    ifstream infile (CLUBFILE);
    int step_i;

    if (infile.is_open())
    {
        while (getline (infile,line))
        {
            std::string club_name;
            int club_id = -1;
            wclear(menu_win);
            istringstream ss(line.c_str());
            step_i = 0;
            while (!ss.eof())         // See the WARNING above for WHY we're doing this!
            {
                std::string x;               // here's a nice, empty string


                getline(ss, x, ';');  // try to read the next field into it
                //mvwprintw(menu_win, step_i, 0, x.c_str());
                //mvwprintw(menu_win, step_i+10, 0, club_name.c_str());

                if(step_i==0){
                    club_name= x;
                }
                else if(step_i==1){
                    club_id = str_to_num(x);

                }

                step_i++;

            }
            Add_club_to_vector(club_name,club_id);
        }
        infile.close();
    }

  else cout << "Unable to open file";
}


void load_data(WINDOW *menu_win){

    load_data_clubs(menu_win);
    //load_data_courses();

}

void save_data(){

    save_data_clubs();
    save_data_courses();

}

