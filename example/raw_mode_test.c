#include "../raw_mode.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    raw_mode(Enable);
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q')
    {
        if (iscntrl(c))
        {
            printf("%d\r\n", c);
        }
        else
        {
            printf("%d ('%c')\r\n", c, c);
        }
    }
    raw_mode(Disable);
    return 0;
}