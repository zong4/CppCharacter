#include <iostream>
#include <numeric>
#include <regex>
#include <string>

bool IsNumber(char ch);

void UpperString(std::string& str);

std::string getBackNumber(std::string& str);

std::string ProcessNumber(std::string const& str);

int main()
{
    {
        // test upper string
        std::string str = "abc";
        UpperString(str);
        std::cout << str << std::endl;
    }

    {
        // test get back number
        std::string str = "abc123";
        std::cout << getBackNumber(str) << std::endl;
    }

    {
        std::string str = "";
        int         num = stoi(str);
        std::cout << num << std::endl;
    }

    return 0;
}

bool IsNumber(char ch)
{
    return ch >= '0' && ch <= '9';
}

void UpperString(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

std::string getBackNumber(std::string& str)
{
    std::string result;

    while (IsNumber(str.back()))
    {
        result += str.back();
        str.pop_back();
    }

    std::reverse(result.begin(), result.end());

    return result;
}

std::string ProcessNumber(std::string const& str)
{
    std::string result = str;

    // if str end with ? then remove it
    if (result.back() == '?')
        result.pop_back();

    // get the last number part
    std::smatch match;
    std::regex  re("\\d+$");
    std::regex_search(result, match, re);

    return result;
}
