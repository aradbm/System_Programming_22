#include <stdio.h>
#include <stddef.h>
#include "my_mat.h"

void floyd_warshall_algo(int arr[mat_len][mat_len]) {
    size_t k, i, j;
    for (k = 0; k < mat_len; k++) {
        for (i = 0; i < mat_len; i++) {
            for (j = 0; j < mat_len; j++) {
                if (arr[i][j] == 0 || (arr[i][k] + arr[k][j]) == 0) {
                    if (arr[i][j] < (arr[i][k] + arr[k][j]))
                        arr[i][j] = arr[i][k] + arr[k][j];
                } else {
                    if (arr[i][j] > arr[i][k] + arr[k][j]) {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    char to_exe;
    int i = 0, j = 0;
    int current_mat[mat_len][mat_len] = {0};
    to_exe = getchar();
    while (to_exe != 'D') {
        switch (to_exe) {
            case 'A':
                get_mat(current_mat);
                floyd_warshall_algo(current_mat);
                break;
            case 'B':
                scanf("%d%d", &i, &j);
                path_exist(i, j, current_mat);
                break;
            case 'C':
                scanf("%d%d", &i, &j);
                shortest_path(i, j, current_mat);
                break;
            default:
                printf("Il entry.");
                break;
        }
        to_exe = getchar();
    }
    return 0;
}