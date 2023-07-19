#include <iconv.h>

#include <filesystem>
#include <iostream>

int main()
{
    // print this path
    std::cout << "current path: " << std::filesystem::current_path() << std::endl;

    // use string to change current path
    std::filesystem::current_path(std::filesystem::current_path().string() + "/../");

    // use iconv to change code format to utf-8 of the files
    iconv_t cd = iconv_open("utf-8", "gbk");

    for (auto& p : std::filesystem::directory_iterator(std::filesystem::current_path()))
    {
        std::cout << p.path().string() << std::endl;
        std::string path         = p.path().string();
        char*       inbuf        = const_cast<char*>(path.c_str());
        size_t      inbytesleft  = path.size();
        char        outbuf[1024] = {0};
        char*       outbufptr    = outbuf;
        size_t      outbytesleft = sizeof(outbuf);
        iconv(cd, &inbuf, &inbytesleft, &outbufptr, &outbytesleft);
        std::cout << outbuf << std::endl;
    }

    iconv_close(cd);

    return 0;
}