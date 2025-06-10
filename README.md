# Linux Process Monitor (htop-lite) in C++

This is a lightweight system monitor written in modern C++17 using `ncurses`, providing real-time CPU, memory, and process stats via the `/proc` filesystem.

## 💡 Features

- CPU & memory usage calculation
- Per-process stats: PID, USER, CPU%, MEM%, COMMAND
- Real-time TUI with `ncurses`
- Clean modular C++17 code

## 🧪 How to Run

1. **Install ncurses**
   ```bash
   sudo apt install libncurses5-dev
