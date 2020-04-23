#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts user for name and prints
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}
