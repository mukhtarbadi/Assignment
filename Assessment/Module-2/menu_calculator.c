#include<stdio.h>
#include<conio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

float divide(int a, int b)
{
    return (float)a / b;
}

int main()
{
    int choice, a, b;
    char cont;

    do
    {
        printf("\n--- Menu Driven Calculator ---\n");
        printf("1. Addition\n2. Substraction\n3. Multiplication\n4. Division\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);

        if(choice == 1)
        
            printf("\n Addition = %d", add(a,b));
        
        else if(choice == 2)
            
            printf("\n Substraction = %d", sub(a,b));
        
        else if(choice == 3)
            
            printf("\n Multiplication = %d", mul(a,b));
        
        else if(choice == 4)
            
            printf("\n Division = %.2f", divide(a,b));
        
        else
            
            printf("Invalid choice\n");

        printf("\n Do you want to continue? (y/n): ");
        scanf(" %c", &cont);

    } while(cont == 'y' || cont == 'Y');

    printf("Calculator closed.\n");
    return 0;
}
