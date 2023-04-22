#include <stdio.h>
#include "LAB04_3.h"
int main()
{
    struct Stack stack;
    Clear(&stack);
    int temp;

    temp = 27;
    Push(&stack, &temp, TOP_B);
    temp = 49;
    Push(&stack, &temp, TOP_B);
    temp = 3;
    Push(&stack, &temp, TOP_B);
    temp = 7;
    Push(&stack, &temp, TOP_B);
    temp = 917;
    Push(&stack, &temp, TOP_B);

    temp = 7;
    Push(&stack, &temp, TOP_U);
    temp = 95;
    Push(&stack, &temp, TOP_U);
    temp = 32;
    Push(&stack, &temp, TOP_U);
    temp = 843;
    Push(&stack, &temp, TOP_U);
    temp = 84;
    Push(&stack, &temp, TOP_U);

    Display(&stack, TOP_B);
    Display(&stack, TOP_U);

    printf("\n ABHISHEK JHAWAR 200905144 \n");

    return 0;

}
