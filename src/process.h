#pragma once
#include <string>

class Process {
public:
    Process(int pid);
    float cpu_usage() const;
    float mem_usage() const;
    std::string user() const;
    std::string command() const;
    int pid() const;

private:
    int pid_;
    float cpu_, mem_;
    std::string user_, cmd_;
    void calculate_usage();
};
