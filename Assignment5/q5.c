#include <stdio.h>
#include <stdlib.h>  // Include this header for malloc and free
#include <omp.h>

int main() {
    int n = 1000; // Adjust the size as needed
    int *arr;
    int sum = 0;

    // Allocate memory for the array
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the array with some values
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // Example initialization
    }

    // Calculate the sum of array elements in parallel
    #pragma omp parallel
    {
        int local_sum = 0;
        
        #pragma omp for reduction(+:local_sum)
        for (int i = 0; i < n; i++) {
            local_sum += arr[i];
        }

        #pragma omp atomic
        sum += local_sum;
    }

    printf("Sum of array elements = %d\n", sum);

    // Free the allocated memory
    free(arr);

    return 0;
}
