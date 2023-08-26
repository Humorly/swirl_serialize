
#include "cmdline.h"

#define __release_mode

#include "data_declaration.h"
#include "data_serialize.h"
#include "swirl_serialize.hpp"

#include <iostream>

void test()
{
    student s1 { 20, "chen", "man", { 1, 2, 3, 4, 5, 6 } };
    std::string str = wstd::serialize(s1);

    std::cout << "str -> " << str << std::endl;

    student s2;
    wstd::deserialize(s2, nlohmann::json::parse(str));
}

int main(int argc, char* argv[])
{
    test();

#ifdef __release_mode

    std::cout << "start parse stucture data." << std::endl;
    cmdline::parser cmd;
    cmd.add<std::string>("source_path", 's', "source file path", true, "");
    cmd.add<std::string>("dest_path", 'd', "dest file path", true, "");
    cmd.parse_check(argc, argv);

    std::string source_path = cmd.get<std::string>("source_path");
    std::string dest_path = cmd.get<std::string>("dest_path");

#else
    std::string source_path = "data_declaration.h";
    std::string dest_path = "data_serialize.h";
#endif

    wstd::swirl_serialize(source_path, dest_path);

    return 0;
}
