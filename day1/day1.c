#include <math.h>
#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

void merge(int arr[], int l, int r, int e, int sort[]) {
    int i = l, j = r;
    for (int k = l; k < e; k++) {
        if (i < r && (j >= e || arr[i] <= arr[j])) {
            sort[k] = arr[i++];
        } else {
            sort[k] = arr[j++];
        }
    }
}

void copy_arr(int sort[], int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = sort[i];
    }
}

void merge_sort(int arr[], int sort[], int n) {
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n; j += 2 * i) {
             merge(arr, j, min(j+i, n), min(j+2*i, n), sort);
        }
        copy_arr(sort, arr, n);
    }
}

void sort_then_count_total_distance(int inputs1[], int inputs2[], int size) {
    int sort_left[size], sort_right[size], total = 0;
    merge_sort(inputs1, sort_left, size);
    merge_sort(inputs2, sort_right, size);

    for (int j = 0; j < size; j++) {
        total += abs(inputs1[j] - inputs2[j]);
    }
    printf("%d", total);
}

int main() {
    FILE *file = fopen("../day1/inputday1.txt", "r");
    int left, right, size = 1000, inputs_left[size] = {}, inputs_right[size] = {}, i = 0;

    while (fscanf(file, "%d %d", &left, &right) != EOF) {
        inputs_left[i] = left;
        inputs_right[i] = right;
        i++;
    }

    fclose(file);

    sort_then_count_total_distance(inputs_left, inputs_right, size);
    return 0;
}
