// however c++ round can't use for digits after decimal point

#include<iostream>
#include<cmath>
#include<string>
#include <iomanip>
#include<sstream>

template<typename value_type>
value_type round(value_type x, int n)
{
    long long len = pow(10, n);
    std::cout << "length: " << len << std::endl;
    
    return round(x * len) / len;
}

int main()
{
    double x = 11.23456789549;

    std::stringstream ss;
    ss << std::fixed << std::setprecision(9) << x;
    std::cout << "stringstream: " << ss.str() << std::endl;

    x = round(x, 9);

    std::cout << "to_string: " << std::to_string(x) << std::endl;
    std::cout << "setprecision: " << std::fixed << std::setprecision(9) << x << std::endl;

    return 0;
}