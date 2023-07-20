#include <iostream>

template <typename value_type>
concept numeric = std::is_arithmetic_v<value_type>;

template <numeric value_type>
constexpr value_type EPS = value_type(1e-6);

template <numeric value_type>
bool IsEqual(value_type a, value_type b)
{
    return std::abs(a - b) < EPS<value_type>;
}

int main()
{
    std::cout << IsEqual(1.0, 1.0) << std::endl;

    std::cout << IsEqual((float)1.0, (float)1.0) << std::endl;

    return 0;
}