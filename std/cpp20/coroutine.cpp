#include <coroutine>
#include <filesystem>
#include <fstream>
#include <iostream>

class FileReader
{
private:
    std::string _filename;

public:
    FileReader(const std::string& filename) : _filename(filename) {}

    struct promise_type
    {
        FileReader         get_return_object() { return FileReader(""); }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void               return_void() {}
        void               unhandled_exception() {}
    };

    bool await_ready() { return false; }
    void await_suspend(std::coroutine_handle<> handle) { ReadFile(); }
    void await_resume() {}

private:
    std::string ReadFile()
    {
        // open file
        std::ifstream file(_filename);

        if (!file.is_open())
            return "";

        // read file
        std::string data;
        std::getline(file, data);

        // close file
        file.close();

        return data;
    }
};

// coroutine get data
std::coroutine_handle<> ProcessData(const std::string& filename)
{
    std::cout << "get data" << std::endl;
    auto&& data = co_await FileReader(filename);

    std::cout << "process data" << std::endl;

    // print data
    std::cout << data << std::endl;

    co_return;
}

int main()
{
    // get root path
    std::filesystem::path root_path = std::filesystem::current_path();

    std::string filename = "/std/cpp20/data.txt";

    // get data
    ProcessData(root_path.string() + filename);

    return 0;
}