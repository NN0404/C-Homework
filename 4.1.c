#include <stdio.h>

int max=0, min=0;

 
int main (){
	int m,n,i,j,a[50][50],c,d;
	puts("Your m arrow value: ");
	scanf("%d",&m);
	puts("Your n column value: ");
	scanf("%d",&n);
	
	
for( i = 0; i<m; i++){
	for(int j =0;j<n;j++){
		printf("Phan tu a[%d][%d]= ",i,j );
		scanf("%d", &a[i][j]);
	}
}
for( i = 0; i<m; i++){
	for(int j=0;j<n;j++){
if (a[i][j]>max){ max = a[i][j];
}
if (a[i][j]<min){ min = a[i][j];
}
}}

puts("Your matrix is: ");printf("%d %d \n", m,n);
for( i = 0; i<m; i++){
	for(int j=0;j<n;j++){
		
		printf("%d ",a[i][j] );
	}
	
	printf("\n");
}
 printf("Max value is %d \n", max);
 printf("Min value is %d", min);

    return 0;
	}

