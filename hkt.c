#include <stdio.h>
#include <math.h>

int main() {
    int a[100];
    int n = 0;
    int choice;

    do {
        printf("\n========= MENU =========\n");
        printf("1. Nhap so luong va gia tri tung phan tu cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. In cac so la so chinh phuong co trong mang\n");
        printf("4. Tinh va in gia tri trung binh cua cac phan tu trong mang\n");
        printf("5. Them moi mot phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan (Bubble Sort)\n");
        printf("8. Tim kiem va hien thi vi tri cua 1 phan tu (Linear Search)\n");
        printf("9. In ra cac phan tu chi xuat hien 1 lan trong mang\n");
        printf("10. Sap xep mang theo thu tu nguoc lai (dao nguoc mang)\n");
        printf("0. Thoat chuong trinh\n");
        printf("========================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so luong phan tu (toi da 100): ");
                scanf("%d", &n);
                if (n <= 0 || n > 100) {
                    printf("So luong khong hop le! Mang se duoc dat ve rong.\n");
                    n = 0;
                    break;
                }
                for (int i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf("%d", &a[i]);
                }
                printf("Da nhap xong %d phan tu.\n", n);
                break;
            }

            case 2: {
                if (n == 0) {
                    printf("Mang rong! Khong co gi de in.\n");
                    break;
                }
                printf("Mang hien tai: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", a[i]);
                printf("\n");
                break;
            }

            case 3: {
                if (n == 0) {
                    printf("Mang rong! Khong co so chinh phuong.\n");
                    break;
                }
                int found = 0;
                printf("Cac so chinh phuong: ");
                for (int i = 0; i < n; i++) {
                    if (a[i] >= 0) {
                        int can = sqrt(a[i]);
                        if (can * can == a[i]) {
                            printf("%d ", a[i]);
                            found = 1;
                        }
                    }
                }
                if (!found) printf("Khong co so chinh phuong nao!");
                printf("\n");
                break;
            }

            case 4: {
                if (n == 0) {
                    printf("Mang rong! Khong the tinh trung binh.\n");
                    break;
                }
                float tong = 0;
                for (int i = 0; i < n; i++) tong += a[i];
                printf("Gia tri trung binh: %.2f\n", tong / n);
                break;
            }

            case 5: {
                if (n >= 100) {
                    printf("Mang da day! Khong the them phan tu moi.\n");
                    break;
                }
                int x;
                printf("Nhap phan tu can them: ");
                if (scanf("%d", &x) != 1) {
                    printf("Gia tri khong hop le!\n");
                    break;
                }
                a[n++] = x;
                printf("Da them thanh cong phan tu %d vao cuoi mang!\n", x);
                break;
            }

            case 6: {
                if (n == 0) {
                    printf("Mang rong! Khong the xoa.\n");
                    break;
                }
                int pos;
                printf("Nhap vi tri can xoa (0 - %d): ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (int i = pos; i < n - 1; i++)
                    a[i] = a[i + 1];
                n--;
                printf("Da xoa phan tu tai vi tri %d.\n", pos);
                break;
            }

            case 7: {
                if (n == 0) {
                    printf("Mang rong! Khong the sap xep.\n");
                    break;
                }
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (a[j] < a[j + 1]) {
                            int temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep giam dan!\n");
                break;
            }

            case 8: {
                if (n == 0) {
                    printf("Mang rong! Khong the tim kiem.\n");
                    break;
                }
                int x, found = 0;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &x);
                for (int i = 0; i < n; i++) {
                    if (a[i] == x) {
                        printf("Phan tu %d nam o vi tri %d\n", x, i);
                        found = 1;
                    }
                }
                if (!found) printf("Khong tim thay phan tu %d trong mang!\n", x);
                break;
            }

            case 9: {
                if (n == 0) {
                    printf("Mang rong! Khong co phan tu nao.\n");
                    break;
                }
                int found = 0;
                printf("Cac phan tu chi xuat hien 1 lan: ");
                for (int i = 0; i < n; i++) {
                    int count = 0;
                    for (int j = 0; j < n; j++) {
                        if (a[i] == a[j]) count++;
                    }
                    if (count == 1) {
                        printf("%d ", a[i]);
                        found = 1;
                    }
                }
                if (!found) printf("Khong co phan tu nao chi xuat hien 1 lan!");
                printf("\n");
                break;
            }

            case 10: {
                if (n == 0) {
                    printf("Mang rong! Khong the dao nguoc.\n");
                    break;
                }
                for (int i = 0; i < n / 2; i++) {
                    int temp = a[i];
                    a[i] = a[n - i - 1];
                    a[n - i - 1] = temp;
                }
                printf("Mang da duoc dao nguoc!\n");
                break;
            }

            case 0:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long nhap tu 0 - 10.\n");
        }

    } while (choice != 0);

    return 0;
}

