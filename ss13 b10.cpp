#include <stdio.h>

void menu(){
	printf("\n--Menu--\n");
	printf("1.Them so luong phan tu va nhap gia tri \n");
	printf("2.In ra gia tri dang quan li \n");
	printf("3.Them moi phan tu vao vi tri chi dinh \n");
	printf("4.Sua mot phan tu o vi tri chi dinh \n");
	printf("5.Xoa mot phan tu tai vi tri chi dinh \n");
	printf("6.Sap xep cac phan tu \n");
	printf("7.Tim kiem phan tu nhap vao \n");
	printf("8.Thoat \n");
}

void addAllitem(int arr[], int size){
	int i;
	for(i = 0; i<size; i++){
		printf("phan tu thu arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
}

void showItem(int arr[], int size){
	int i;
	for(i = 0; i<size; i++){
		printf("Phan tu thu arr[%d] co gia tri: %d \n", i, arr[i]);
	}
}

void addItem(int arr[], int size){
	int i;
	int index;
	int valueItem;
	printf("Nhap gia tri muon them: ");
	scanf("%d", &valueItem);
	printf("Nhap vi tri muon them:");
	scanf("%d",&index);
	for( i = size; i > index; i-- ){
		arr[i]= arr[i-1];
		}
	arr[index]= valueItem;
	size++;
	printf("Mang sau khi them:");
	for( i = 0; i<size ;i++){
		printf("%d ", arr[i]);
	}
}

void fixItem(int arr[], int size){
	int i;
	int index;
	int valueItem;
	printf("Nhap vi tri muon sua:");
	scanf("%d",&index);
	printf("Nhap gia tri muon sua: ");
	scanf("%d", &valueItem);
	for(i = 0; i < size; i++){
		if(i==index){
			arr[i]=valueItem;
		}
	}
	printf("Mang sau khi da sua:");
	for( i= 0; i<size ;i++){
		printf("%d ", arr[i]);
	}
	
}

void deleteItem(int arr[], int size){
	int i;
	int index;
	printf("Nhap vi tri phan tu muon xoa: ");
	scanf("%d", &index);
	if(index<0 || index>=size){
		printf("Vi tri khong hop le\n");
		}else{
			for( i = index ; i< size-1; i++){
					arr[i]=arr[i+1];
				}
				size--;
				printf("Mang sau khi xoa:");
				for( i=0; i<size; i++){
					printf("%d ", arr[i]);
				}
		}
}

void descending(int arr[], int size){
	int i;
	int j;
	for ( i = 0; i < size - 1; i++) {
        for ( j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep:");
	for( i=0; i<size; i++){
		printf("%d ", arr[i]);
		}
}

void ascending(int arr[], int size){
	int i;
	int j;
	for ( i = 0; i < size - 1; i++) {
        for ( j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep:");
	for( i=0; i<size; i++){
		printf("%d ", arr[i]);
		}
}

void linearSearch(int arr[], int size, int x) {
	int i;
    int found = 0;
    for ( i = 0; i < size; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d duoc tim thay tai %d.\n", x, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Phan tu %d khong ton tai.\n", x);
    }
}

void binarySearch(int arr[], int size, int x) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            printf("Phan tu %d duoc tim thay tai %d.\n", x, mid);
            return;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Phan tu %d khong ton tai.\n", x);
}

int main(){
	int arr[100];
	int choose;
	int size;
	do{

		menu();
		printf("Moi ban nhap case: ");
		scanf("%d", &choose);
		switch(choose){
			case 1:
				//Nhap so luong phan tu va gia tri
				printf("Moi ban nhap so luong phan tu ");
				scanf("%d", &size);
				addAllitem(arr, size);
				break;
				
			case 2:
				showItem(arr, size);
				break;
				
			case 3:
				addItem(arr, size);
				break;
				
			case 4:
				fixItem(arr, size);
				break;
				
			case 5:
				deleteItem(arr, size);
				break;
				
			case 6:
				printf("1. Giam dan\n");
				printf("2. Tang dan\n");
				int select;
				printf("Moi ban chon phuong thuc sap xep: ");
				scanf("%d", &select);
				if(select==1){
					descending(arr,size);
				}else{
					ascending(arr,size);
				}
				break;
				
			case 7:
				printf("1. Tim kiem tuyen tinh\n");
				printf("2. Tim kiem nhi phan\n");
				int pick;
				printf("Moi ban chon phuong thuc sap xep: ");
				scanf("%d", &pick);
				int x;
				printf("Nhap so can tim kiem: ");
				scanf("%d",&x);
				if(select==1){
					linearSearch(arr,size,x);
				}else{
					binarySearch(arr,size,x);
				}
				break;
				
			case 8:
				printf("Thoat chuong trinh\n");
				break;
				
			default:
				break;
		}
		
	}while(choose != 8);
	
	return 0;
}

