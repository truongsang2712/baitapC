#include<stdio.h>

int main()
{
    int m, n, *ptr;

    printf("nhập số hàng của ma trận: ");
    scanf("%d", &m);
    printf("nhập số cột của ma trận: ");
    scanf("%d", &n);
    ptr = (int*)malloc((m*n) * sizeof(int));

    for(int i=0; i<(m*n); i++) {
        printf("nhập giá trị hàng %d cột %d: ", i/m,i%n);
        scanf("%d",(ptr+i));

    }
    for(int i=0; i<m*n; i++) {
        printf("phần tử thứ %d là: %d \n",i, (*(ptr+i)));
    }
}