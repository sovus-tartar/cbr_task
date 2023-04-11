#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <iterator>
#include <sstream>

class counter
{
public:
    static std::string print_order(std::string str_, int n_ = 3)
    {
        counter temp(str_, n_);
        std::string res_str;
        for (auto it = temp.words_weights.rbegin(); it != temp.words_weights.rend(); ++it)
            res_str.append(it->second), res_str.append(" ");

        return res_str;
    };

private:
    int n;
    std::string str;
    std::map<std::string, int> weight_cntr;
    std::multimap<std::string, std::string> words;
    std::multimap<int, std::string> words_weights;

    counter(std::string str_, int n_ = 3) : n(n_), str(str_)
    {
        fill_maps();
        count_words_weight();
    };

    void count_words_weight()
    {
        for (auto word_it = words.begin(); word_it != words.end(); ++word_it)
        {
            int weight = 0;
            auto it_pair = words.equal_range(word_it->first);

            for (auto it = it_pair.first; it != it_pair.second; ++it)
            {
                auto weight_it = weight_cntr.find(it->second);

                if (weight == 0)
                    weight = weight_it->second;
                else if (weight_it->second < weight)
                {
                    weight = weight_it->second;
                }
            }

            words_weights.emplace(weight, word_it->first);
            word_it = --it_pair.second;
        }
    }

    void fill_maps()
    {
        std::istringstream iss(str);
        std::string temp_str;

        while (iss >> temp_str)
        {
            size_t word_len = temp_str.size();

            if (word_len >= n)
            {
                for (size_t i = 0; i <= (word_len - n); ++i)
                {
                    std::string nplet(temp_str.substr(i, n));
                    add_nplet(nplet);

                    words.emplace(temp_str, nplet);
                }
            }
        }
    }

    void add_nplet(std::string &sstr_)
    {
        auto it = weight_cntr.find(sstr_);

        if (it == weight_cntr.end())
        {
            weight_cntr.emplace(sstr_, 1);
        }
        else
        {
            it->second += 1;
        }
    }
};