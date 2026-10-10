
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, new_n, i;

    printf("Enter the initial number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the new size of the array: ");
    scanf("%d", &new_n);

    if (new_n <= n) {
        printf("New size must be greater than %d.\n", n);
        free(arr);
        return 1;
    }

    int *temp = (int *)realloc(arr, new_n * sizeof(int));

    if (temp == NULL) {
        printf("Memory reallocation failed.\n");
        free(arr);
        return 1;
    }

    arr = temp;

    printf("Enter %d new elements:\n", new_n - n);
    for (i = n; i < new_n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("All array elements:\n");
    for (i = 0; i < new_n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}
