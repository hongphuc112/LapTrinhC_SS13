#include <stdio.h>
void taoMaTran(int n, int m, int arr[100][100]) {
    printf("Nhap gia tri cho ma tran (%d hang, %d cot):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap gia tri tai vi tri [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
void inMaTran(int n, int m, int arr[100][100]) {
    printf("Ma tran da nhap:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
	int arr[100][100];
    int n, m;
    printf("Nhap so hang: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);

    taoMaTran(n, m, arr);
    inMaTran(n, m, arr);

    return 0;
}

