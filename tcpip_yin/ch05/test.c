#include <stdio.h>
#include <stdlib.h>
void fun(int a[])
{
    printf("%d\n", a[0]);
}
int main()
{
    char c[4];
    scanf("%d", (int*)&c[0]);
    //printf("%d\n", c[0]);
    fun((int*)c);
    return 0;
}
