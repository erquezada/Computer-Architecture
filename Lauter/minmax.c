#include <stdio.h>

void minmax(int *min, int *max, int *arr, int n){
    int i;
    *max = arr[0];
    *min = arr[0];
    if (n < 1) return;
    for(i = 0; i < n; i++){
        if(arr[i] > *max)
            *max = arr[i];
        if(arr[i] < *min)
            *min = arr[i];
    }
    printf("Using minmax:\n");
    printf("Maximum value is: %d\n", *max);
    printf("Minimum value is: %d\n", *min);
    return;
}

void minmax_goto_c(int *min, int *max, int *values, int n) {
    int i;
    int t;
    int *ptr;

    if (n < 1) goto out_here;

    t = *(values);
    *min = t;
    *max = t;
    i = 0;

loop:
    if (i >= n) goto out_here;

    ptr = values + i;
    t = *ptr;

    if (t < *min) goto first_if;
    goto after_first_if;

first_if:
    *min = t;
after_first_if:
    if (t > *max) goto second_if;
    goto after_second_if;

second_if:
    *max = t;
after_second_if:
    i = i + 1;
    goto loop;

out_here:
    return;
}

int main() {
    int min, max;
    int arr[5] = {10, 20, 30, 40, 50};

    // Using the standard minmax function
    minmax(&min, &max, arr, 5);

    // Using the minmax_goto_c function
    minmax_goto_c(&min, &max, arr, 5);
    printf("Using minmax_goto_c:\n");
    printf("Maximum value is: %d\n", max);
    printf("Minimum value is: %d\n", min);

    return 0;
}
