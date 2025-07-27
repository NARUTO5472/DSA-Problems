# include<stdio.h>

long long fib(int n)
{
    long long F[n + 1];
    F[0] = 0;
    if(n >= 1)
    {
        F[1] = 1;
    }
    for(int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}


int main()
{
    int n;
    printf("Enter the value of n : ");
    scanf("%lld",&n);
    printf("Answer : %lld",fib(n));
}