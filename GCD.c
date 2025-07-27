# include <stdio.h>

int GCD(int a,int b)
{
    int best = 0;
    for (int i =1;i<= a+b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            best = i;
        }
    }
    return best;
}

int main()
{
    int a,b;
    printf("Enter value of a : ");
    scanf("%d",&a);
    printf("Enter value of b : ");
    scanf("%d",&b);
    printf("The GCD af a and b is : %d",GCD(a,b));
}