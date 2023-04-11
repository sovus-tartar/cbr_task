#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <iterator>
#include <sstream>

class counter
{
public:
    static std::string print_order(std::string str_, int n_ = 3, int mode_ = 0);

private:
    int n, mode;
    std::string str;
    std::map<std::string, int> weight_cntr;
    std::multimap<std::string, std::string> words;
    std::multimap<int, std::string> words_weights;

    counter(std::string str_, int n_ = 3, int mode_ = 0) : n(n_), mode(mode_), str(str_)
    {
        fill_maps();
        count_words_weight();
    };
    void count_words_weight();
    void fill_maps();
    void add_nplet(std::string &sstr_);
};