//Sau khi thử rất rất nhiều thì phát hiện ngôn ngữ C không cho phép truyền theo tham chiếu
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct Sinhvien {
	char ten[30];
	int mssv;
	float dtb;
};

void timsv(struct Sinhvien a[], int n);


void main() {
	int key;
	int n=0;
	int daNhap = 0;
	char name[30];
	while (n <= 0){
		printf("\nNhap so luong SV: "); scanf("%d", &n);
	} 
	//khởi tạo struct động
	struct Sinhvien *SV;
	SV = (struct Sinhvien*) malloc(n * sizeof(SV));
	//Menu
	while (1) {
		system("cls");
		printf("******************************************\n");
		printf("**    CHUONG TRINH QUAN LY SINH VIEN    **\n");
		printf("**      1. Nhap du lieu                 **\n");
		printf("**      2. In danh sach sinh vien       **\n");
		printf("**      3. Tim thong tin sinh vien   **\n");
		printf("**      0. Thoat                        **\n");
		printf("******************************************\n");
		printf("**       Nhap lua chon cua ban          **\n");
		scanf("%d", &key);
		//thực thi chương trình được chọn
		switch (key) {
		case 1:
			printf("\nBan da chon nhap DS sinh vien!");
			printf("\n____________________________________\n");
			for (int i = 0; i< n; ++i) {
				printf("\nNhap SV thu %d:", i + 1);
				getchar();
				fgets(name, sizeof name, stdin);
				name[strlen(name) - 1] = '\0';
				strcpy(SV[i].ten, name);
				printf("\nNhap MSSV: "); 
				scanf("%d", &SV[i].mssv);
				printf("\nNhap diem TB: "); 
				getchar();
				scanf("%f", &SV[i].dtb);
			}
			printf("\n____________________________________\n");
			printf("\nBan da nhap thanh cong!");
			daNhap = 1;
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case 2:
			if (daNhap) {
				printf("\nBan da chon xuat DS sinh vien!");
				printf("\n____________________________________\n");
				for (int i = 0; i < n; ++i) {
					printf("\nThong tin SV thu %d:", i + 1);
					printf("\nHo ten SV: %s", SV[i].ten);
					printf("\nMSSV  : %d", SV[i].mssv);
					printf("\nDiem TB: %.2f \n", SV[i].dtb);
				}
				printf("\n____________________________________\n");
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case 3:
			if (daNhap) {
				printf("\nBan da chon xuat DS sinh vien!");				
				timsv(SV, n);
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case 0:
			printf("\nBan da chon thoat chuong trinh!");
			getch();
			return 0;
		default:
			printf("\nKhong co chuc nang nay!");
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		}
		
	}
	free(SV);
}

void timsv(struct Sinhvien a[], int n) {
	int MSSV;
	int i;
	printf("\nBan da chon tim sinh vien!");
	printf("\n____________________________________\n");
	printf("Nhap vao ma so sinh vien can tim: \n");
	scanf("%d", &MSSV);
	for (i = 0; i < n; i++) {
		if (a[i].mssv == MSSV ) {
			printf("\nHo ten SV: %s", a[i].ten);
			printf("\nMSSV  : %d", a[i].mssv);
			printf("\nDiem TB: %.2f \n", a[i].dtb);
			break;
		}
	}
	if (i >= n) {
		printf("Khong tim thay sinh vien co MSSV: %d!", MSSV);
	}
	printf("\n____________________________________\n");

}
