#include <format>
#include <iostream>

int main()
{
    int         value = 42;
    std::string name  = "John";

    // 将格式化结果写入到输出流
    std::format_to(std::ostream_iterator<char>(std::cout), "Hello, {}! The answer is {}.", name, value);
    // 输出：Hello, John! The answer is 42.

    return 0;
}
