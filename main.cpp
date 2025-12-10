#include <stdio.h>
#include <stdlib.h>

void allocate_array(int num_elements) {
    // DANGEROUS: If num_elements is large, the multiplication can overflow
    // wrapping around to a small number.
    int size = num_elements * sizeof(int);

    printf("Requesting %d elements. Calculated size: %d bytes.\n", num_elements, size);

    int *arr = (int *)malloc(size);
    if (arr) {
        // We might write past the allocated buffer because 'size' was small
        // but 'num_elements' is large.
        for (int i = 0; i < num_elements; i++) {
            arr[i] = 0; // Heap buffer overflow
        }
        free(arr);
    }
}

int main() {
    int num_elements;
    printf("Enter number of elements to allocate: ");
    scanf("%d", &num_elements);

    // Bad Input: A value that causes overflow when multiplied by sizeof(int) (usually 4).
    // On a 32-bit system, SIZE_MAX is roughly 4 billion.
    // Try input: 1073741825
    // 1073741825 * 4 = 4294967300.
    // 4294967300 modulo 2^32 = 4.
    // So malloc(4) is called, but the loop runs 1073741825 times.
    allocate_array(num_elements);
    return 0;
}