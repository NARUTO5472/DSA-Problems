# include<stdio.h>

int fib(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}

int main()
{
    int n;
    printf("Enter the fibonacci term to be printed out : ");
    scanf("%d",&n);
    printf("Term %d is : ",n);
    printf("%d",fib(n));
}