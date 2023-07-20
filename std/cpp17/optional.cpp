#include <iostream>
#include <optional>

std::optional<double> divide(double a, double b)
{
    if (b == 0.0)
        return std::nullopt;

    return a / b;
}

int main()
{
    // test 1
    {
        auto result = divide(5.0, 3.0);
        if (result)
            std::cout << result.value() << '\n';
        else
            std::cout << "error\n";
    }

    // test 2
    {
        auto result = divide(5.0, 0.0);
        if (result)
            std::cout << result.value() << '\n';
        else
            std::cout << "error\n";
    }
}