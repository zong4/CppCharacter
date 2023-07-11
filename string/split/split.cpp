#include "split.hpp"

std::vector<std::string> SplitByStream(std::string const& str, char delimiter)
{
    std::vector<std::string> result;
    std::string              token;
    std::istringstream       tokenStream(str);

    while (std::getline(tokenStream, token, delimiter))
    {
        result.push_back(token);
    }

    return result;
}

std::vector<std::string> SplitByFind(std::string const& s, std::string const& delimiter)
{
    size_t                   pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string              token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
    {
        token     = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void TestByFile(std::string const& path)
{
    // read the split_test file to string
    std::ifstream file(path);

    // Check if the file was opened successfully
    if (file)
    {
        std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        TestByString(str);

        // close file
        file.close();
    }
    else
        std::cout << "Failed to open the file." << std::endl;
}

void TestByString(std::string const& str)
{
    std::cout << "Size of the string: " << str.size() << std::endl;

    time_unit                streamElapsed;
    std::vector<std::string> streamResult;
    {
        // count time of split by stream
        auto start   = std::chrono::steady_clock::now();
        streamResult = SplitByStream(str, ',');
        auto end     = std::chrono::steady_clock::now();

        // print time
        streamElapsed = std::chrono::duration_cast<time_unit>(end - start);
        std::cout << "Split by stream: " << streamElapsed.count() << " " + time_unit_name << std::endl;

        // // print size
        // std::cout << "Size: " << streamResult.size() << std::endl;
    }

    time_unit                findElapsed;
    std::vector<std::string> findResult;
    {
        // count time of split by find
        auto start = std::chrono::steady_clock::now();
        findResult = SplitByFind(str, ",");
        auto end   = std::chrono::steady_clock::now();

        // print time
        findElapsed = std::chrono::duration_cast<time_unit>(end - start);
        std::cout << "Split by find: " << findElapsed.count() << " " + time_unit_name << std::endl;

        // // print size
        // std::cout << "Size: " << findResult.size() << std::endl;
    }

    // compare two elapsed time
    if (streamElapsed < findElapsed)
        std::cout << "Split by stream is faster " + std::to_string((double)findElapsed.count() / (double)streamElapsed.count()) + " times."
                  << std::endl;
    else
        std::cout << "Split by find is faster " + std::to_string((double)streamElapsed.count() / (double)findElapsed.count()) + " times."
                  << std::endl;
}