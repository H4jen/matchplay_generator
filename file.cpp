#include "file.h"


void save_data_clubs(){
    // open a file in write mode.
    ofstream outfile;
    outfile.open("save_data_clubs.txt");
    outfile << "Writing this to a file.\n";

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
    outfile << "End file write\n";
    outfile.close();

    //save_data = courses->get_course_data_for_saving();
    //outfile << courses << endl;
}

void save_data_courses(){
    // open a file in write mode.
    ofstream outfile;
    outfile.open("save_data_courses.txt");
    outfile << "Writing this to a file.\n";

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
    outfile << "End file write\n";
    outfile.close();

    //save_data = courses->get_course_data_for_saving();
    //outfile << courses << endl;
}

void save_data(){

    save_data_clubs();
    save_data_courses();

}

void load_data(){
// open a file in write mode.

}

