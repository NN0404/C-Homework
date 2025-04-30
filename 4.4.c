#include <stdio.h>
#include <math.h>
int main(void) {
    int j,k,r,t,m,n,p,q;
    int a[50][50],b[50][50],c[50][50];
 
    //nhap ma tran A
    puts("Ma tran A");
    puts("Nhap so hang m: ");
    scanf("%d",&m);
    puts("Nhap so cot n: ");
    scanf("%d",&n);

        for (j=1;j<=m;j++) {
            for (k=1;k<=n;k++) {
                printf("Phan tu a[%d][%d] la: ",j,k);
                scanf("%d",&a[j][k]);
            }
        } 
printf("\n");
    //nhap ma tran B
    puts("Ma tran B");
    puts("Nhap so hang p: ");
    scanf("%d",&p);
    puts("Nhap so cot q: ");
    scanf("%d",&q);

    for (j=1;j<=p;j++) {
        for (k=1;k<=q;k++) {
            printf("Phan tu b[%d][%d] la: ",j,k);
            scanf("%d",&b[j][k]);
        }
    }
 
    if (n==q && m==p) {
        puts("Phep cong ma tran A + B la: \n");
        for (j=1;j<=m;j++) {
            for (k=1;k<=n;k++) {
                        c[j][k]= a[j][k]+b[j][k];
                        printf("%d ",c[j][k]);
            } printf("\n");
        }
    }
else {
    puts("INVALID ");
}
}
