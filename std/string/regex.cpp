#include <iostream>
#include <regex>

int main()
{
    std::string str1 = "{AA}";
    std::string str2 = "{A}{A}";
    std::string str3 = "{A}{12}";
    std::string str4 = "{1}{12}123";
    std::string str5 = "{\\}{12}123";

    // match only str3
    std::regex re("^(\\{.+\\})+.*");

    std::cout << std::boolalpha;
    std::cout << std::regex_match(str1, re) << std::endl;
    std::cout << std::regex_match(str2, re) << std::endl;
    std::cout << std::regex_match(str3, re) << std::endl;
    std::cout << std::regex_match(str4, re) << std::endl;
    std::cout << std::regex_match(str5, re) << std::endl;

    return 0;
}