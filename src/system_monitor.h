#pragma once
#include "process.h"
#include <vector>

class SystemMonitor {
public:
    void update();
    float cpu_usage() const;
    float memory_usage() const;
    std::vector<Process> processes() const;

private:
    float total_cpu_, total_mem_;
    std::vector<Process> procs_;
    void fetch_processes();
    void update_cpu_memory();
};
