#include "./headers/counter.hh"

std::string counter::print_order(std::string str_, int n_, int mode_)
{
    counter temp(str_, n_, mode_);
    std::string res_str;
    for (auto it = temp.words_weights.rbegin(); it != temp.words_weights.rend(); ++it)
        res_str.append(it->second), res_str.append(" ");

    return res_str;
}

void counter::count_words_weight()
{
    for (auto word_it = words.begin(); word_it != words.end(); ++word_it)
    {
        int weight = 0;
        auto it_pair = words.equal_range(word_it->first);

        for (auto it = it_pair.first; it != it_pair.second; ++it)
        {
            auto temp_weight = weight_cntr.find(it->second)->second;

            switch (mode)
            {
            case 0:
                if (weight == 0)
                    weight = temp_weight;
                else if (temp_weight < weight)
                {
                    weight = temp_weight;
                }
                break;

            case 1:
                weight += temp_weight;
                break;
            }
        }

        words_weights.emplace(weight, word_it->first);
        word_it = --it_pair.second;
    }
}

void counter::fill_maps()
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

void counter::add_nplet(std::string &sstr_)
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