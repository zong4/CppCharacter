#include <dirent.h>

#include <cstring>
#include <fstream>
#include <iostream>

int main()
{
    DIR* procDir = opendir("/proc");
    if (!procDir)
    {
        std::cerr << "Failed to open /proc directory." << std::endl;
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(procDir)) != nullptr)
    {
        if (entry->d_type == DT_DIR && std::isdigit(entry->d_name[0]))
        {
            std::string pidStr         = entry->d_name;
            std::string statusFilePath = "/proc/" + pidStr + "/status";

            std::ifstream statusFile(statusFilePath);
            std::string   line;
            while (std::getline(statusFile, line))
            {
                if (line.find("Name:") == 0)
                {
                    std::string processName = line.substr(6);
                    std::cout << "Process ID: " << pidStr << std::endl;
                    std::cout << "Process Name: " << processName << std::endl;

                    // You can parse and display more information as needed
                }
            }
        }
    }

    closedir(procDir);
    return 0;
}
