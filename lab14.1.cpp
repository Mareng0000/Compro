#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printSolution(int *x, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);
    printf("\n");
}

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    if (i == n || wx == 0) {
        for (int j = i; j < n; j++) {
            x[j] = 0; 
        }
        return 0;
    }

    if (w[i] > wx) {
        return KnapsackBT(w, v, n, wx, i + 1, x);
    }

    int *includeX = new int[n];
    int *excludeX = new int[n];

    x[i] = 1;
    int includeValue = v[i] + KnapsackBT(w, v, n, wx - w[i], i + 1, x);

    x[i] = 0;
    int excludeValue = KnapsackBT(w, v, n, wx, i + 1, x);

    if (includeValue > excludeValue) {
        for (int j = 0; j < n; j++) {
            x[j] = includeX[j];
        }
        x[i] = 1;
        delete[] includeX;
        delete[] excludeX;
        return includeValue;
    } else {
        for (int j = 0; j < n; j++) {
            x[j] = excludeX[j];
        }
        x[i] = 0;
        delete[] includeX;
        delete[] excludeX;
        return excludeValue;
    }
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x = new int[n];
    int vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Output:\nValue = %d\n", vx);
    printSolution(x, n);

    delete[] x;

    return 0;
}
