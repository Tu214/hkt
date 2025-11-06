#include <stdio.h>

int main() {
    int arr[100];
    int n = 0;
    int choice, i, j, value, index;
    int sum, found, pos;
    int sorted = 0; 

    do {
        printf("\n================= MENU CHUC NANG ===================\n");
        printf("1. Nhap gia tri n phan tu (n <= 100)\n");
        printf("2. In gia tri cac phan tu\n");
        printf("3. Tinh tong va trung binh cong cac phan tu\n");
        printf("4. Sap xep mang tang dan (Bubble Sort)\n");
        printf("5. Tim kiem phan tu theo gia tri (Linear Search)\n");
        printf("6. Xoa phan tu theo chi so\n");
        printf("7. Chen 1 phan tu vao vi tri bat ky\n");
        printf("8. Xoa tat ca phan tu co gia tri nhap vao\n");
        printf("9. Thoat\n");
        printf("=======================================================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so luong phan tu n: ");
            scanf("%d", &n);
            while(n<0||n>100){
            	printf("loi vui long nhap lai!!!");
            	break;
			}
            for (i = 0; i < n; i++) {
                printf("Nhap phan tu arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }
            sorted = 0;
            break;

        case 2:
            if (n == 0) {
                printf("Mang rong!\n");
            } else {
                printf("Mang hien tai: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
            break;

        case 3:
            if (n == 0) {
                printf("Mang rong!\n");
            } else {
                sum = 0;
                for (i = 0; i < n; i++)
                    sum += arr[i];
                printf("Tong cac phan tu: %d\n", sum);
                printf("Trung binh cong: %.2f\n", (float)sum / n);
            }
            break;

        case 4:
            if (n == 0) {
                printf("Mang rong!\n");
            } else {
                for (i = 0; i < n - 1; i++) {
                    for (j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                sorted = 1;
                printf("Mang da duoc sap xep tang dan!\n");
            }
            break;

        case 5:
            if (n == 0) {
                printf("Mang rong!\n");
            } else {
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Tim thay %d tai vi tri %d\n", value, i);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Khong tim thay phan tu!\n");
            }
            break;

        case 6:
            if (n == 0) {
                printf("Mang rong!\n");
            } else {
                printf("Nhap chi so phan tu can xoa (0 -> %d): ", n - 1);
                scanf("%d", &index);
                if (index < 0 || index >= n) {
                    printf("Chi so khong hop le!\n");
                } else {
                    for (i = index; i < n - 1; i++)
                        arr[i] = arr[i + 1];
                    n--;
                    printf("Da xoa phan tu tai vi tri %d\n", index);
                }
            }
            break;

        case 7:
            if (n >= 100) {
                printf("Mang da day, khong the chen!\n");
            } else {
                printf("Nhap vi tri can chen (0 -> %d): ", n);
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    printf("Nhap gia tri can chen: ");
                    scanf("%d", &value);
                    for (i = n; i > pos; i--)
                        arr[i] = arr[i - 1];
                    arr[pos] = value;
                    n++;
                    printf("Da chen %d vao vi tri %d\n", value, pos);
                    sorted = 0;
                }
            }
            break;

        case 8:
            if (n == 0) {
                printf("Mang rong!\n");
            } else {
                printf("Nhap gia tri can xoa: ");
                scanf("%d", &value);
                int count = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        for (j = i; j < n - 1; j++)
                            arr[j] = arr[j + 1];
                        n--;
                        i--;
                        count++;
                    }
                }
                if (count == 0)
                    printf("Khong co phan tu nao bang %d!\n", value);
                else
                    printf("Da xoa %d phan tu co gia tri %d\n", count, value);
            }
            break;

        case 9:
            printf("Thoat chuong trinh...\n");
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }

    } while (choice != 9);

    return 0;
}

