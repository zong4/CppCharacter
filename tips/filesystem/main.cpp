#include <iconv.h>

#include <filesystem>
#include <iostream>

int main()
{
    // print this path
    std::cout << "current path: " << std::filesystem::current_path() << std::endl;

    std::cout << "do you want to change path(press 0 or 1)?" << std::endl;
    int change_path_flag = 0;
    std::cin >> change_path_flag;

    // use string to change current path
    if (change_path_flag)
    {
        std::cout << "input the path you want to change(example: input /../ to come back to parent path)" << std::endl;

        std::string str;
        std::cin >> str;

        std::filesystem::current_path(std::filesystem::current_path().string() + str);
        std::cout << "current path: " << std::filesystem::current_path() << std::endl;
    }

    std::cout << "input change from which code format and to which code format(example: input gbk utf-8 to change files from gbk to utf-8)"
              << std::endl;
    std::string from_code, to_code;
    std::cin >> from_code >> to_code;

    // use iconv to change code format to utf-8 of the files
    iconv_t cd = iconv_open(to_code.c_str(), from_code.c_str());

    std::cout << "do recursively(press 0 or 1)?" << std::endl;
    int recursive_flag = 0;
    std::cin >> recursive_flag;

    if (recursive_flag)
    {
        for (auto& p : std::filesystem::recursive_directory_iterator(std::filesystem::current_path()))
        {
            std::string path         = p.path().string();
            char*       inbuf        = const_cast<char*>(path.c_str());
            size_t      inbytesleft  = path.size();
            char        outbuf[1024] = {0};
            char*       outbufptr    = outbuf;
            size_t      outbytesleft = sizeof(outbuf);
            iconv(cd, &inbuf, &inbytesleft, &outbufptr, &outbytesleft);
            std::cout << outbuf << std::endl;
        }
    }
    else
    {
        for (auto& p : std::filesystem::directory_iterator(std::filesystem::current_path()))
        {
            std::string path         = p.path().string();
            char*       inbuf        = const_cast<char*>(path.c_str());
            size_t      inbytesleft  = path.size();
            char        outbuf[1024] = {0};
            char*       outbufptr    = outbuf;
            size_t      outbytesleft = sizeof(outbuf);
            iconv(cd, &inbuf, &inbytesleft, &outbufptr, &outbytesleft);
            std::cout << outbuf << std::endl;
        }
    }

    iconv_close(cd);

    return 0;
}