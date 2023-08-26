

#pragma once
#include <string>
#define ubyte unsigned char

struct student
{
    int age;
    ubyte name[32];
    std::string gender;
    std::size_t score[2][3][4];
};
