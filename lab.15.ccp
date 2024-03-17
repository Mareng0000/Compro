#include <stdio.h>

double f(double x);
double RootOfFunction(double xl, double xr, double epsilon);

int main() {
    double root;
    root = RootOfFunction(-1, 10, 0.1);
    printf("Root = %.1f", root);
    return 0;
}

double f(double x) {
    return 2 * x - 5;
}

double RootOfFunction(double xl, double xr, double epsilon) {
    double xm, fl, fr, fm;

    printf("%.1f %.1f %.1f\n", xl, xr, epsilon);

    fl = f(xl);
    fr = f(xr);

    while ((xr - xl) > epsilon || (xl - xr) > epsilon) {
        xm = (xl + xr) / 2.0;
        fm = f(xm);

        if (fl * fm < 0)
            xr = xm;
        else
            xl = xm;

        printf("%.1f %.1f %.1f\n", xl, xr, epsilon);
    }

    return (xl + xr) / 2.0;
}
