#include "system_monitor.h"
#include <ncurses.h>
#include <thread>
#include <chrono>

int main() {
    initscr();
    noecho();
    curs_set(FALSE);

    SystemMonitor monitor;

    while (true) {
        monitor.update();
        clear();

        mvprintw(0, 0, "C++ Linux Process Monitor");
        mvprintw(1, 0, "CPU Usage: %.1f%%   Memory Usage: %.1f%%", 
                 monitor.cpu_usage(), monitor.memory_usage());

        auto procs = monitor.processes();
        mvprintw(3, 0, "PID   USER     CPU%%   MEM%%   CMD");
        int line = 4;
        for (const auto& p : procs) {
            mvprintw(line++, 0, "%5d %-8s %5.1f   %5.1f   %-20s", 
                     p.pid(), p.user().c_str(), 
                     p.cpu_usage(), p.mem_usage(), 
                     p.command().c_str());
            if (line >= LINES - 1) break;
        }

        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    endwin();
    return 0;
}