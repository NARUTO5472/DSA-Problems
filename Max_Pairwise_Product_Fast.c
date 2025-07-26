#include <stdio.h>

long long MaxPairwiseProductFast(const int numbers[], int n) 
{
    int max_index1 = -1;
    for (int i = 0; i < n; i++) 
    {
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1])) 
        {
            max_index1 = i;
        }
    }
    
    int max_index2 = -1;
    for (int j = 0; j < n; j++) 
    {
        if ((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))) 
        {
            max_index2 = j;
        }
    }
    
    return ((long long)numbers[max_index1]) * numbers[max_index2];
}

int main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d", &numbers[i]);
    }
    
    long long result = MaxPairwiseProductFast(numbers, n);
    printf("Maximum pairwise product: %lld\n", result);
    
    return 0;
}
