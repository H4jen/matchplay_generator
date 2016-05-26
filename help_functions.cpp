#include "help_functions.h"


bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

//Checks is number is between n and m n<=number <= m
bool is_number(const std::string& s,int n, int m)
{
    bool is_a_number;

    if (m < n) return false;

    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    is_a_number = ( !s.empty() && it == s.end());

    int value = atoi(s.c_str());
    if((value <= m && value >=n) && is_a_number) return true;
    else return false;



}

int str_to_num(const std::string& s)
{
    bool is_a_number;

    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    is_a_number = ( !s.empty() && it == s.end());
    if(!is_a_number) return 0;

    int value = atoi(s.c_str());
    return value;

}

