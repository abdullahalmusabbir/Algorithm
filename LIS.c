#include <stdio.h>

int lisEndingAtIdx(int arr[], int idx) {
    // Base case
    if (idx == 0)
        return 1;

    int mx = 1;
    for (int prev = 0; prev < idx; prev++) {
        if (arr[prev] < arr[idx]) {
            int candidate = lisEndingAtIdx(arr, prev) + 1;
            if (candidate > mx)
                mx = candidate;
        }
    }
    return mx;
}

int lis(int arr[], int n) {
    int res = 1;
    for (int i = 1; i < n; i++) {
        int candidate = lisEndingAtIdx(arr, i);
        if (candidate > res)
            res = candidate;
    }
    return res;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", lis(arr, n));

    return 0;
}
