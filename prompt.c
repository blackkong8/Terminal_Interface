#include <stdio.h>

typedef enum
{
    false,
    true
} bool;

void *prompt(char *str, bool (*f)(char *str))
{
    if (f(str))
    {
        printf("\x1b[34m");
    }
    else
    {
        printf("\x1b[31m");
    }
    printf("%s", str);
    printf("\x1b[0m\n");
}

bool isNum(char *str)
{
    while (*str != '\0')
    {
        if (!('0' <= *str && *str <= '9'))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main()
{
    char string[10] = "132";
    prompt(string, isNum);
}