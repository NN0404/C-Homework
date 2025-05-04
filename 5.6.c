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

 puts("Enter the elements");
 for (i=1;i<=m;i++) {
  for (j=1;j<=n;j++) {
   printf("matrix[%d][%d] = ", i, j);
   scanf("%d", (matrix + (i-1)*n + (j-1)));
  }
 }

int sum=0;
 for (i=1;i<= (m<n ? m:n); i++) {
  sum+= *(matrix + (i-1)*n + (i-1));
 }
 printf("Sum of duong cheo matrix: %d", sum);

 free(matrix);
 return 0;
}
