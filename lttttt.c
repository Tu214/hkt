#include <stdio.h>

int main() {
    int arr[100];
    int n;
    int choice, value, position, i, j, temp;

    do {
        printf("Nhap so phan tu ban dau cua mang (1 - 100): ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("So phan tu khong hop le! Vui long nhap lai.\n");
        }
    } while (n <= 0 || n > 100);


    for (i = 0; i < n; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n=============== Quan ly danh sach so nguyen ==============\n");
        printf("1. Them phan tu vao vi tri bat ky\n");
        printf("2. Xoa phan tu o vi tri bat ky\n");
        printf("3. Cap nhat gia tri tai vi tri bat ky\n");
        printf("4. Tim kiem phan tu trong mang(leaner seach / binary seach)\n");
        printf("5. Hien thi mang\n");
        printf("6. Sap xep mang tang dan (Bubble Sort / Selection Sort / Insertion Sort.)\n");
        printf("7. Thoat chuong trinh\n");
        printf("-----------------------------------------------------------------\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (n >= 100) {
                    printf("Mang da day, khong the them!\n");
                } else {
                    printf("Nhap vi tri muon them (0 - %d): ", n);
                    scanf("%d", &position);
                    if (position < 0 || position > n) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        printf("Nhap gia tri can them: ");
                        scanf("%d", &value);
                        for (i = n; i > position; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[position] = value;
                        n++;
                        printf("Da them thanh cong!\n");
                    }
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Mang rong, khong the xoa!\n");
                } else {
                    printf("Nhap vi tri muon xoa (0 - %d): ", n - 1);
                    scanf("%d", &position);
                    if (position < 0 || position >= n) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (i = position; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                        printf("Da xoa thanh cong!\n");
                    }
                }
                break;

            case 3:
                printf("Nhap vi tri muon cap nhat (0 - %d): ", n - 1);
                scanf("%d", &position);
                if (position < 0 || position >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    printf("Nhap gia tri moi: ");
                    scanf("%d", &value);
                    arr[position] = value;
                    printf("Da cap nhat thanh cong!\n");
                }
                break;

            case 4: // Tìm kim linear seach
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                int found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Gia tri %d duoc tim thay tai vi tri %d\n", value, i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay gia tri %d trong mang.\n", value);
                }
                break;
                
                
            case 4: { // Tìm kim Binary Search
                int left = 0, right = n - 1, mid;
                int found = 0;

                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);

                while (left <= right) {
                    mid = (left + right) / 2;
                    if (arr[mid] == value) {
                        printf("Tim thay gia tri %d tai vi tri %d\n", value, mid);
                        found = 1;
                        break;
                    } else if (arr[mid] < value) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                if (!found) {
                    printf("Khong tim thay gia tri %d trong mang!\n", value);
                }
                break;
            }
            
            
            case 5:
                printf("Mang hien tai:\n");
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;

            case 6:
                for (i = 0; i < n - 1; i++) {
                    for (j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep tang dan!\n");
                break;

            case 7:
                printf("Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long nhap lai!\n");
        }
    } while (choice != 7);

    return 0;
}

