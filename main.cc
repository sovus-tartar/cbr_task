#include <iostream>
#include <fstream>
#include <string>
#include "./headers/counter.hh"

int main()
{
    std::ifstream input_file;
    std::ofstream output_file;
    try
    {
        input_file.open("in_words.txt", std::ifstream::in);
        output_file.open("out_task.txt", std::ofstream::trunc);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    

    std::string str;
    std::getline(input_file, str);

    output_file << counter::print_order(str, 2); 

    input_file.close();
    output_file.close();
    
    return 0;
}