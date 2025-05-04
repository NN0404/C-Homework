#include <stdio.h>
#include <stdlib.h>

int main() {
 int m,n,i,j;


 puts("Enter the number of rows: ");
 scanf("%d", &m);
 puts("Enter the number of columns: ");
 scanf("%d", &n);

int *matrix = (int *)malloc(m * n * sizeof(int));
if (matrix == NULL) {
 puts("Memory allocation failed");
 return EXIT_FAILURE;
}

 int *matT = (int *)malloc(n * m * sizeof(int));
 if (matT == NULL) {
  puts("Memory allocation failed");
  return EXIT_FAILURE;
 }

 puts("Enter the elements");
 for (i=1;i<=m;i++) {
  for (j=1;j<=n;j++) {
   printf("matrix[%d][%d] = ", i, j);
   scanf("%d", (matrix + (i-1)*n + (j-1)));
  }

 }

for (i=1;i<=m;i++) {
 for (j=1;j<=n;j++) {
   *(matT + (j-1)*m + (i-1)) = *(matrix + (i-1)*n + (j-1));
 }
}


puts("Ma tran chuyen vi: ");
 for (i=1;i<=n;i++) {
  //reverse m rows and n column
  for (j=1;j<=m;j++) {

    printf("%d ", *(matT + (i-1)*m + (j-1)) );
  }
  printf("\n");
 }


 free(matrix);
 free(matT);
 return 0;
}
