#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("Thread %d: Series 2\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("Thread %d: Series 4\n", omp_get_thread_num());
        }
    }

    return 0;
}
