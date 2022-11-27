#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[2];
    fgets(s, sizeof(s), stdin);
    printf("%s\n", s);
    return 0;
}