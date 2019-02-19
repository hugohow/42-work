
#include <stdio.h>

int main()
{
    int one, two, sum;
    
    printf("Enter two integers: ");

    // Two integers entered by user is stored using scanf() function
    scanf("%d %d", &one, &two);

    // sum of two numbers in stored in variable sum
sum = one + two;

    // Displays sum      
    printf("%d + %d = %d", one, two, sum);

    return 0;
}
