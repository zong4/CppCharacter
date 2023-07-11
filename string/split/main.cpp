#include "split.hpp"

int main()
{
    // get the root directory
    std::string root_path = __FILE__;

    bool testByFile = false;
    // std::cin >> testByFile;

    if (testByFile)
    {
        TestByFile(root_path + "split_test.txt");
    }
    else
    {
        // create random long string by ascii char
        std::string long_string;
        for (int i = 0; i < 1000000; i++)
            long_string += ascii_char[rand() % ascii_char.size()];

        TestByString(long_string);
    }

    return 0;
}
