/**
 * @file terminal_size.h
 */

#ifndef _TERMINAL_SIZE_H_
#define _TERMINAL_SIZE_H_

struct terminal_size
{
    int row, col;
};

/**
 * @brief Get the terminal size object
 *
 * @return struct terminal_size
 */
struct terminal_size get_terminal_size(void);

#if __has_include(<windows.h>)
#include <windows.h>
struct terminal_size get_terminal_size(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;

    ret = GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE),
        &csbi);

    return (struct terminal_size){csbi.dwSize.Y, csbi.dwSize.X};
}
#elif __has_include(<sys/ioctl.h>)
#include <sys/ioctl.h>
#define STDOUT_FILENO 1 // from <unistd.h>
struct terminal_size get_terminal_size(void)
{
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return (struct terminal_size){w.ws_row, w.ws_col};
}
#else
#error[terminal_size.h] Platform not supported
#endif

#endif