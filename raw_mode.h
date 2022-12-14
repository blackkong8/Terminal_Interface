/**
 * @file raw_mode.h
 */
typedef enum
{
    Enable,
    Disable
} state;

/**
 * @brief Console raw mode Enable/Disable
 *
 * @param State enum{Enable, Disable}
 */
void raw_mode(state State);

#if __has_include(<windows.h>)

#include <windows.h>

DWORD orig_mode;

void raw_mode(state State)
{
    if (State == Enable)
    {
        DWORD raw = orig_mode;
        HANDLE console = GetStdHandle(STD_INPUT_HANDLE);

        GetConsoleMode(console, &raw);
        /**
         * @todo add ISIG, IEXTEN / IXON, ICRNL / OPOST
         *
         */
        raw &= ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
        SetConsoleMode(console, raw);
    }
    else if (State == Disable)
    {
        SetConsoleMode(console, orig_mode);
    }
}

#elif __has_include(<termios.h>) && __has_include(<unistd.h>)

#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

void raw_mode(state State)
{
    if (State == Enable)
    {
        struct termios raw = orig_termios;

        int i = tcgetattr(STDIN_FILENO, &raw);
        raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        raw.c_oflag &= ~(OPOST);
        raw.c_cflag |= (CS8);
        raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }
    else if (State == Disable)
    {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
    }
}
#else
#error[raw_mode.h] Platform not supported
#endif