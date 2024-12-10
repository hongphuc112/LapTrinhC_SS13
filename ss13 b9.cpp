#include <stdio.h>
void menu(){
	printf("\n--------------------MENU---------------------\n");
    printf("1. Nhap gia tri cac phan tu cua mang\n");
    printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
    printf("3. In ra cac phan tu o goc theo ma tran\n");
    printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
    printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
    printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
    printf("7. Thoat\n");
        
}
//case 1
void addItem(int arr[100][100], int *n, int *m) {
	int i;
	int j;
    printf("Nhap so dong: ");
    scanf("%d", n);
    printf("Nhap so cot: ");
    scanf("%d", m);
    printf("Nhap cac phan tu cua mang:\n");
    for ( i = 0; i < *n; i++) {
        for (j = 0; j < *m; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
//case 2
void showItem(int arr[100][100], int n, int m) {
	int i;
	int j;
    printf("Ma tran hien tai:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
//case 3
void corner(int arr[100][100], int n, int m) {
    printf("Cac phan tu o goc ma tran:\n");
    printf("%d %d\n", arr[0][0], arr[0][m - 1]);
    printf("%d %d\n", arr[n - 1][0], arr[n - 1][m - 1]);
}
//case 4
void borderLine(int arr[100][100], int n, int m) {
	int i;
	int j;
	if (n == 0 || m == 0) {
        printf("Ma tran rong\n");
        return;
    }
    printf("Cac phan tu tren duong bien:\n");

    for ( j = 0; j < m; j++){
    	printf("%d ", arr[0][j]);
	} 
    printf("\n");
   
    for ( i = 1; i < n - 1; i++) {
        printf("%d ", arr[i][0]);
        for ( j = 1; j < m - 1; j++){
        	printf("0 "); 
		}  
        printf("%d\n", arr[i][m - 1]);
    }

    for ( j = 0; j < m; j++){
    	printf("%d ", arr[n - 1][j]);
	} 
    printf("\n");
}
//case 5
void diagonal(int arr[100][100], int n, int m) {
	int i, j;
    printf("Cac phan tu tren duong cheo chinh va cheo phu:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < m; j++) {
            if (i == j || i + j == m - 1){
            	printf("%d ", arr[i][j]);
			} 
            else{
            	printf("0 ");
			} 
        }
        printf("\n");
    }
}
//case 6
void showPrime(int arr[100][100], int n, int m) {
	int i, j;
	int x;
    printf("Cac so nguyen to trong mang la:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < m; j++) {
            int is_prime = 1;
            if (arr[i][j] <= 1) {
                is_prime = 0;
            } else {
                for ( x = 2; x * x <= arr[i][j]; x++) {
                    if (arr[i][j] % x == 0) {
                        is_prime = 0;
                        break;
                    }
                }
            }
            if (is_prime) {
                printf("%d ", arr[i][j]);
            }
        }
    }
}

int main() {
    int arr[100][100];
    int n, m;
    int choose;
    do {
    	menu();
        printf("Lua chon cua ban la: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                addItem(arr, &n, &m);
                break;
            case 2:
                showItem(arr, n, m);
                break;
            case 3:
                corner(arr, n, m);
                break;
            case 4:
                borderLine(arr, n, m);
                break;
            case 5:
                diagonal(arr, n, m);
                break;
            case 6:
                showPrime(arr, n, m);
                break;
            case 7:
                printf("Thoat chuong trinh \n");
                break;
            default:
                printf("Khong hop le! Vui long chon lai. \n");
        }
    } while (choose != 7);

    return 0;
}

