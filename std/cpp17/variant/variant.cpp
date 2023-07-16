// variant

#include <variant>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    std::variant<int, std::string> var = 1;
    
    // std::cout<<var<<std::endl; // error, can't cout << variant
    // std::cout<<std::get<1>(var)<<std::endl // error, string is not initialize

    var = "123";
    // std::cout<<std::get<0>(var)<<std::endl; // error, int is delete
    std::cout<<std::get<1>(var)<<std::endl; 

    var = std::variant<int, std::string>("123"); 
    // std::cout<<std::get<1>(var)<<std::endl; 

    // type variant size
    // to record the class information, it will use 4bit more
    {
        std::cout << "sizeof string: " 
            << sizeof(std::string) << "\n";

        std::cout << "sizeof variant<int, string>: " 
            << sizeof(std::variant<int, std::string>) << "\n";

        std::cout << "sizeof vector<string>(0): " << sizeof(std::vector<std::string>(0)) << "\n";
        std::cout << "sizeof vector<string>(1): " << sizeof(std::vector<std::string>(1)) << "\n";

        std::cout << "sizeof variant<double, string>: " << sizeof(std::variant<double, std::string>) << "\n";
    
        std::cout << "sizeof variant<int, float>: " 
            << sizeof(std::variant<int, float>) << "\n";

        std::cout << "sizeof variant<int, double>: " 
            << sizeof(std::variant<int, double>) << "\n";
    }

    return 0;
}