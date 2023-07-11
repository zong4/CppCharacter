
#include <boost/tokenizer.hpp>
#include <iostream>

#include "../../string/split/split.hpp"

std::vector<std::string> SplitByToken(std::string const& str, std::string const& delimiter)
{
    std::vector<std::string>                      result;
    boost::char_separator<char>                   sep(delimiter.c_str());
    boost::tokenizer<boost::char_separator<char>> tokens(str, sep);

    for (auto const& t : tokens)
        result.push_back(t);

    return result;
}

std::vector<std::string> SplitByToken(std::string const& str, char delimiter)
{
    return SplitByToken(str, delimiter + "");
}

int main(int argc, char** argv)
{
    uint32_t letterNum    = 100000;
    uint32_t delimiterNum = 1000;
    uint32_t elpasedNum   = letterNum / delimiterNum;

    // create random long string by ascii char
    std::string long_string;
    for (int i = 0; i < letterNum; i++)
    {
        long_string += ascii_char[rand() % (ascii_char.size() - 1)];

        if (i % elpasedNum == 0)
            long_string += ascii_char[127];
    }

    TestByString(long_string, 127);

    time_unit                tokenElapsed;
    std::vector<std::string> tokenResult;
    {
        // count time of split by stream
        auto start  = std::chrono::steady_clock::now();
        tokenResult = SplitByToken(long_string, ',');
        auto end    = std::chrono::steady_clock::now();

        // print time
        tokenElapsed = std::chrono::duration_cast<time_unit>(end - start);
        std::cout << "Split by token: " << tokenElapsed.count() << " " + time_unit_name << std::endl;
    }

    return 0;
}