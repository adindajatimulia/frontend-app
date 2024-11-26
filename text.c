#include <stdio.h>
#define N 3 // Ukuran matriks (3x3 untuk 3 variabel)

void gaussElimination(double a[N][N+1], double x[N]) {
    int i, j, k;
    double factor;

    // Proses eliminasi maju
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (a[i][i] == 0) {
                printf("Eliminasi tidak dapat dilakukan (divisi oleh nol).\n");
                return;
            }
            factor = a[j][i] / a[i][i];
            for (k = i; k <= N; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    // Proses substitusi balik
    for (i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

int main() {
    // Matriks augmented [A|B]
    double a[N][N+1] = {
        {1, 1,  2,  9},
        {2, 4, -3,  1},
        {3, 6, -5,  0}
    };

    double x[N]; // Array untuk menyimpan solusi

    gaussElimination(a, x);

    // Menampilkan solusi
    printf("Solusi:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, x[i]);
    }

    return 0;
}


