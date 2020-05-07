#include<stdio.h>

int main()
{
    int m, n, *ptr;
    //khoi tao ma tran.
    printf("nhập số hàng của ma trận: ");
    scanf("%d", &m);
    printf("nhập số cột của ma trận: ");
    scanf("%d", &n);
    //khoi tao mang dong
    ptr = (int*)malloc((m*n) * sizeof(int));
    //nhap vao ma tran tu ban phim
    for(int i=0; i<(m*n); i++) {
        printf("nhập giá trị hàng %d cột %d: ", i/n,i%n);
        scanf("%d",(ptr+i));
    }
    //in du lieu ra man hinh.
    for(int i=0; i<m*n; i++) {
        printf("phần tử thứ %d là: %d \n",i, (*(ptr+i)));
    }
    
    free(ptr);
}
