/*  max_pairwise_product.c  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long MaxPairwiseProduct(const int *numbers, int n)
{
    long long result = 0;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            long long prod = (long long)numbers[i] * numbers[j];
            if (prod > result)
                result = prod;
        }
    return result;
}

long long MaxPairwiseProductFast(const int *numbers, int n)
{
    int max_index1 = -1;
    for (int i = 0; i < n; ++i)
        if (max_index1 == -1 || numbers[i] > numbers[max_index1])
            max_index1 = i;

    int max_index2 = -1;
    for (int i = 0; i < n; ++i)
        if (i != max_index1 &&
           (max_index2 == -1 || numbers[i] > numbers[max_index2]))
            max_index2 = i;

    return (long long)numbers[max_index1] * numbers[max_index2];
}

int main(void)
{
    // Seed the RNG so the stress test varies on every run
    srand((unsigned)time(NULL));

    // Stress-test loop
    while (1) {
        int n = rand() % 10 + 2;          // length 2 … 11 
        printf("%d\n", n);

        int *a = (int *)malloc(n * sizeof(int));
        if (!a) { fputs("Out of memory\n", stderr); return 1; }

        for (int i = 0; i < n; ++i) {
            a[i] = rand() % 100000;       // value 0 … 99 999
            printf("%d ", a[i]);
        }
        puts("");                         // newline after the array

        long long res1 = MaxPairwiseProduct(a, n);
        long long res2 = MaxPairwiseProductFast(a, n);

        if (res1 != res2) {               // mismatch – report and stop
            printf("Wrong answer: %lld %lld\n", res1, res2);
            free(a);
            break;
        } else {
            puts("OK");
        }
        free(a);
    }

    // Solve the actual test case
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *numbers = (int *)malloc(n * sizeof(int));
    if (!numbers) { fputs("Out of memory\n", stderr); return 1; }

    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);

    long long answer = MaxPairwiseProductFast(numbers, n);
    printf("%lld\n", answer);

    free(numbers);
    return 0;
}
