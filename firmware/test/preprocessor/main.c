#include <stdio.h>

#define ABC(x) "BLUBB_x_HELLO"

#define GPIO_PORT(x)    GPIO_x_PORT
#define GPIO_1_PORT     27

int main()
{
    printf("Hello World!\n");
    puts(ABC(x));

    int i = GPIO_1_PORT;
    int a = GPIO_PORT(1);

    printf("port %i and %i\n", i, a);

    return 0;
}
