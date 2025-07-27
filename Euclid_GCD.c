# include <stdio.h>

int gcd(int a,int b)
{
    int a_prime;
    if (b==0)
    {
        return a;
    }
    else
    {
        a_prime = a%b;
    }
    return gcd(b,a_prime);
}

int main()
{
    int a,b;
    printf("Enter a : ");
    scanf("%d",&a);
    printf("Enter b : ");
    scanf("%d",&b);
    printf("The GCD is : %d", gcd(a,b));
}


/*
RUNTIME :-

EACH STEP REDUCES THE SIZE OF THE NUMBERS BY A FACTOR OF 2.
TAKES ABOUT log(a*b) steps.
Each step a single division.
*/