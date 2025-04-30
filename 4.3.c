#include <stdio.h>
#include <math.h>
void main(){
	int a[50][50],n;
	puts("Nhap so phan tu ma tran nxn: ");
	scanf("%d",&n);
	
	 
	int i,j;
	for(i=1;i<=n;i++){
		for (j=1;j<=n;j++){
			printf("Gia tri a[%d][%d]: ", i,j);
			scanf("%d", &a[i][j]);
		}
	}
	
	//duong cheo chinh= cac phan tu nxn
	//n11,n22,n33,...
	
	int sum=0;
	for(i=1;i<=n;i++){
		sum+= a[i][i];
	}
	printf("Tong duong cheo chinh is: %d", sum);
}
