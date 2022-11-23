#include <stdio.h>
#include "my_mat.h"

void get_mat(int arr[mat_len][mat_len]) {
    for (int i = 0; i < mat_len; ++i) {
        for (int j = 0; j < mat_len; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void path_exist(int i, int j, int arr[mat_len][mat_len]) {
    if (arr[i][j] != 0 && arr[i][j] != INT_MAX) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void shortest_path(int i, int j, int arr[mat_len][mat_len]) {
    if (arr[i][j] == 0 || arr[i][j] == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", arr[i][j]);
    }
}