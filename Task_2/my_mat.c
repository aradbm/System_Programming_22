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
    if (arr[i][j] != 0) {
        printf("True");
    } else {
        printf("False");
    }
}

void shortest_path(int i, int j, int arr[mat_len][mat_len]) {
    if (arr[i][j]==0) {
        printf("-1");
    } else {
        printf("%d",arr[i][j]);
    }
}
/*
int main() {
    printf("%d\n", mat_len);
    int arr[][10] = {
            {0, 3, 1, 0, 0, 2, 0, 0, 0, 0},
            {3, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 4, 1, 1},
            {2, 0, 0, 0, 0, 0, 2, 0, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
            {0, 0, 0, 5, 4, 0, 0, 0, 0, 2},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}};
    //get_mat(arr);
    printf("%d", arr[2][2]);
    return 0;
}
 */