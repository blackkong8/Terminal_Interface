#include <stdio.h>

void color(char *s)
{
    printf("\x1b[31m%s\x1b[0m", s);
}

int main(void)
{
    color("hello");
    return 0;
}