#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "./headers/counter.hh"

int main(int argc, char ** argv)
{
    std::ifstream input_file;
    std::ofstream output_file;

    input_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    output_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        input_file.open("in_words.txt", std::ifstream::in);
        output_file.open("out_task.txt", std::ofstream::trunc);
    }
    catch(const std::ios_base::failure& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    

    std::string str;
    std::getline(input_file, str, (char)0);

    if (argc == 1)
        output_file << counter::print_order(str); 
    else
    {
        char opt = getopt(argc, argv, "n");
        switch(opt)
        {
            case 'n':
                output_file << counter::print_order(str, 3, 1);
                break;
            default:
                std::cerr << "Wrong args, exiting..." << std::endl;
        }
    }


    input_file.close();
    output_file.close();

    return 0;
}