
#include <stdio.h>

int func_suma(int A, int B) {
    return A + B;
}

void proc_02(int A, int *B, int C) {
    A = func_suma(A, *B) * C;
    printf("%d %d %d\n", A, *B, C);
}

void proc_01(int *A, int B, int D) {
    int C;

    C = *A;
    *A = B;
    B = C;
    printf("%d %d %d\n", *A, B, C);
    proc_02(B, &C, D);
    printf("%d %d %d\n", *A, B, C);
}

int main() {
    int A, B, C;

    A = 1;
    B = 2;
    C = 3;
    printf("%d %d %d\n", A, B, C);
    proc_01(&A, B, C);
    printf("%d %d %d\n", A, B, C);
    proc_02(A, &B, C);
    printf("%d %d %d\n", A, B, C);
    return 0;
}