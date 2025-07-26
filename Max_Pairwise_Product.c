#include <stdio.h>

long long MaxPairwiseProduct(const int numbers[], int n) {
    long long result = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (((long long) numbers[i]) * numbers[j] > result) {
                result = ((long long)numbers[i]) * numbers[j];
            }
        }
    }
    return result;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int numbers[n];
    
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }
    
    long long result = MaxPairwiseProduct(numbers, n);
    printf("Maximum pairwise product: %lld\n", result);
    
    return 0;
}
