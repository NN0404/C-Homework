#include <stdio.h>
#include <math.h>

double p0(double x) {
    return 1;
}

double p1(double x) {
    return x;
}

double PL(double x, int L) {
    if (L == 0) {
        return p0(x);
    } else if (L == 1) {
        return p1(x);
    } else {
        return (double)((2*L-1)*x*PL(x, L-1)-(L-1)*PL(x, L-2))/L;
    }
}

int main() {
    int L;
    double x;

    puts("Your n: ");
    scanf("%d",&L);
    puts("Your x: ");
    scanf("%lf",&x);
    printf("P(%d, %lf) = %.5lf\n", L, x, PL(x, L));
//write first 5 values
   /* for (x=-1;x<=1;x=x+0.01) {
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",x,PL(x,0),PL(x,1),PL(x,2));
    } */
}
