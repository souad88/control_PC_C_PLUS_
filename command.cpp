#include <cstdlib>
#include <iostream>
#include "command.hpp"
using namespace std;
comm_is_::comm_is_(){}
void comm_is_::open_firefox()
{
    system("firefox");
}
void comm_is_::open_terminal()
{
    system("gnome-terminal");
}
void comm_is_::open_calculator()
{
    system("gnome-calculator");
}
comm_is_::~comm_is_(){}
