#include<stdio.h>
#include<string.h>
char name[1000][100]= {"vu thi diep","vu thu ha","vu thi ngoc", "vu thi truc","vu thu cuc"};
int id[1000]= {1,2,3,45};
float mean[1000]= {5.5,6.7,8.3,9.0,3.8};
int n;
int numdata;
int choose=0;
void action(int chose);
void showall();
void addstudent();
void deletename(char nam2[100]);
void deleteid(int sbd);
void findname(char nam3[100]);
void findid(int sbd);
int main()
{
l1:
    printf("nhập vào số lượng sinh viên tối đa của lớp:\n");
    scanf("%d",&n);
    if(n<=0) {
        printf("số lượng sinh viên phải nguyên dương, vui lòng nhập lại!");
        goto l1;
    }
    printf("\n***********\n");
    printf("1: hiển thị danh sách sinh viên.\n");
    printf("2: thêm sinh viên mới.\n");
    printf("3: xoá sinh viên theo tên.\n");
    printf("4: xoá sinh viên theo id.\n");
    printf("5: tìm sinh viên theo tên.\n");
    printf("6: tìm sinh viên theo id.\n");
    printf("7: nhập lại số lượng sinh viên:\n");
    printf("***********\n");
    while(1) {
        printf("\n");
        printf("nhập vào thao tác muốn thực hiện:\n");
        while((choose==0)||(choose>7)) {
            scanf("%d",&choose);
        }
        if(choose==7) {
            choose=0;
            break;
        }
        action(choose);
    }
    goto l1;
}
void showall() {
    for(int i=0; i<n; i++) {
        if(id[i]==0) {
            numdata=i;
            break;
        }
        printf("%12s",name[i]);
        printf("|SBD:%3d|",id[i]);
        printf("Điểm tb: %.2f;\n",mean[i]);
    }
}
void addstudent() {
    int position;
    char nam[100];
    for(int i=0; i<n; i++) {
        if(id[i]==0) {
            numdata=i;
            i=n;
        }
    }
    printf("nhập vào vị trí cần thêm:\n");
    scanf("%d", &position);
    if(position>numdata)position=numdata;
    for(int m=numdata; m>position; m--) {
        strcpy(name[m],name[m-1]);
        id[m]=id[m-1];
        mean[m]=mean[m-1];
    }   
    printf("nhập họ & tên sinh viên:\n");
    getchar();
    fgets(name[position], sizeof name[position], stdin);
    name[position][strlen(name[position])-1] ='\0';    
    printf("nhập vào SBD: ");
    scanf("%d",&id[position]);
    printf("nhập vào điểm TB:\n");
    scanf("%f", &mean[position]);
}
void deletename(char nam2[100]) {
    int ktra=0;
    int sbd;
    int g;
    int p=0;
    for(p=0; p<n; p++) {
        g =strcmp(name[p],nam2);       
        if(g==0) {
            ktra=1;
            sbd=id[p];            
        }
        if(ktra==1) {
            strcpy(name[p],name[p+1]);
            id[p]=id[p+1];
            mean[p]=mean[p+1];
        }
    }
    if(ktra==0) {
        printf("không tìm thấy tên %s trong danh sách!",nam2);
    }
    else {
        printf("đã xoá thông tin sinh viên: ");
        printf("%s có SBD: %d\n",nam2,sbd);
    }
}
void deleteid(int sbd) {
    int ktra=0;
    int g;
    int p=0;
    char tam[100]="";
    for(p=0; p<n; p++) {
        if(id[p]==sbd) {
            ktra=1;
            strcpy(tam,name[p]);
        }
        if((ktra==1)&&(tam!="")) {
            strcpy(name[p],name[p+1]);
            id[p]=id[p+1];
            mean[p]=mean[p+1];
        }
    }
    if(ktra==0) {
        printf("không tìm thấy SBD %d trong danh sách!\n",sbd);
    }
    else {
        printf("đã xoá thông tin sinh viên: ");
        printf("%s | SBD:  %d\n",tam, sbd);
    }
}
void findname(char nam[100]){
    int g;
    int p=0;
    for(p=0; p<n; p++) {
        g =strcmp(name[p],nam);
        if(g==0) {
            break;
        }
    }
    if(p>=n) {
        printf("không tìm thấy tên %s trong danh sách!\n",nam);
    }
    else {
        printf("sinh viên %s có SBD là: %d, điểm TB là: %.2f\n",nam,id[p],mean[p]);
    }
}
void findid(int sbd){
 int ktra=0;
    int g;
    int p=0;
    char tam[100]="";
    for(p=0; p<n; p++) {
        if(id[p]==sbd) {
           break; 
        }
    }
    if(p>=n) {
        printf("không tìm thấy SBD %d trong danh sách!\n",sbd);
    }
    else {
        printf("SBD: %d là của sinh viên %s, điểm TB là: %.2f\n",sbd, name[p],mean[p]);
    }
}
void action(int chose) {
    switch(chose) {
    case 1: {
        printf("hiển thị danh sách sinh viên:\n");
        showall();
        choose=0;
        break;
    }
    case 2: {
        printf("thêm sinh viên mới:\n");
        addstudent();
        choose=0;
        break;
    }
    case 3: {
        char nam1[100];
        printf("xoá sinh viên theo tên:\n");
        printf("nhập vào họ tên cần xoá:");
        getchar();
        fgets(nam1, sizeof nam1, stdin);
        nam1[strlen(nam1)-1] ='\0';
        deletename(nam1);
        choose=0;
        break;
    }
    case 4: {
        printf("xoá sinh viên theo SBD:\n");
        int inputsbd=0;
        printf("nhập vào số báo danh cần xoá:");
        scanf("%d",&inputsbd);
        deleteid(inputsbd);
        choose=0;
        break;
    }
    case 5: {
    char nam[100];
        printf("tìm sinh viên theo tên:\n");
        printf("nhập vào họ tên cần tìm:");
        getchar();
        fgets(nam, sizeof nam, stdin);
        nam[strlen(nam)-1] ='\0';
        findname(nam);
        choose=0;
        break;
    }
    case 6: {
        printf("tìm sinh viên theo id:\n");
        int inputsbd=0;
        printf("nhập vào số báo danh cần tìm:");
        scanf("%d",&inputsbd);
        findid(inputsbd);
        choose=0;
        break;
    }
  }
}
    