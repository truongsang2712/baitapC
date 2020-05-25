#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct SinhVien {
	char ten[20];
	char MSSV[10];
	int dtb;
};
typedef struct SinhVien SV;

void nhap(SV sv);
void nhapN(SV a[], int n);
void xuat(SV sv);
void xuatN(SV a[], int n);
void tinhDTB(SV sv);
void sapxep(SV a[], int n);
void xeploai(SV a);
void xeploaiN(SV a[], int n);
void xuatFile(SV a[], int n, char fileName1[]);
char fileName[] = "D:\\datasinhvien.txt";

int main() {
	char key;
	int n;
	bool daNhap = false;
	do {
		printf("\nNhap vao so luong sinh vien: "); scanf("%d", &n);
	} while (n <= 0);
	SV a[100];
	while (1) {
		system("cls");
		printf("1. Nhap du lieu\n");
		printf("2. In danh sach sinh vien\n");
		printf("3. Sap xep sinh vien theo DTB\n");
		printf("4. Xep loai sinh vien\n");
		printf("5. Xuat DS sinh vien\n");
		printf("**\n");
		printf(" Nhap lua chon cua ban          **\n");
		key = getch();
		switch (key) {
		case '1':
			printf("\nBan da chon nhap DS sinh vien!");
			nhapN(a, n);
			printf("\nBan da nhap thanh cong!");
			daNhap = true;
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
		
			break;
		case '2':
			if (daNhap) {
				printf("\nBan da chon xuat DS sinh vien!");
				xuatN(a, n);
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case '3':
			if (daNhap) {
				printf("\nBan da chon sap xep SV theo STB!");
				sapxep(a, n);
				xuatN(a, n);
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case '4':
			if (daNhap) {
				printf("\nBan da chon thoat xep loai SV!");
				xeploaiN(a, n);
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case '5':
			if (daNhap) {
				printf("\nBan da chon xuat DS SV!");
				xuatFile(a, n, fileName);
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nXuat DSSV thanh cong vao file %s!", fileName);
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case '0':
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
}


void nhap(SV sv) {
	char a[10];
	printf("\nNhap MSSV: ");  fflush(stdin);  gets_s(a); fflush(stdin); gets_s(sv.MSSV);
	printf("\nNhap ten: ");  fflush(stdin);  gets_s(sv.ten);
	printf("\nNhap dtb: "); scanf("%d", &sv.dtb);
}

void nhapN(SV a[], int n) {
	printf("\n____________________________________\n");
	for (int i = 0; i< n; ++i) {
		printf("\nNhap SV thu %d:", i + 1);
		nhap(a[i]);
	}
	printf("\n____________________________________\n");
}

void xuat(SV sv) {
	printf("\nHo ten SV: %s", sv.ten);
	printf("\nMa so SV: %s", sv.MSSV);
	printf("\nDiem TB: %.2f", sv.dtb);
}

void xuatN(SV a[], int n) {
	printf("\n____________________________________\n");
	for (int i = 0; i < n; ++i) {
		printf("\nThong tin SV thu %d:", i + 1);
		xuat(a[i]);
	}
	printf("\n____________________________________\n");
}

void sapxep(SV a[], int n) {
	//Sap xep theo DTB tang dan
	SV tmp;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i].dtb > a[j].dtb) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void xeploai(SV sv) {
	if (sv.dtb >= 8) printf("Gioi");
	else if (sv.dtb >= 6.5) printf("Kha");
	else if (sv.dtb >= 4) printf("Trung binh");
	else printf("Yeu");
}

void xeploaiN(SV a[], int n) {
	printf("\n____________________________________\n");
	for (int i = 0; i < n; ++i) {
		printf("\nXep loai cua SV thu %d la: ", i + 1);
		xeploai(a[i]);
	}
	printf("\n____________________________________\n");
}

void xuatFile(SV a[], int n, char fileName1[]) {
	FILE * fp;
	fp = fopen(fileName1, "w");
	fprintf(fp, "%20s%5s%10s\n", "Ho Ten", "GT", "DTB");
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%20s%5s%10f\n", a[i].ten, a[i].MSSV,  a[i].dtb);
	}
	fclose(fp);
}