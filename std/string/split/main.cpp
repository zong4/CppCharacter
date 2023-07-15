#include <filesystem>

#include "split.hpp"

int main(int argc, char **argv)
{
    // // print argv
    // for (int i = 0; i < argc; i++)
    //     std::cout << "argv[" << i << "]: " << argv[i] << std::endl;

    if (std::stoi(argv[1]))
    {
        // get workspace path
        std::string root_path = std::filesystem::current_path().string();

        TestByFile(root_path + "/" + "string/split/split_test.txt", ',');
    }
    else
    {
        uint32_t letterNum    = std::stoi(argv[2]);
        uint32_t delimiterNum = std::stoi(argv[3]);
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
    }

    return 0;
}
