#include <stdio.h>
#define N 3 // Ukuran matriks (3x3 untuk 3 variabel)

void gaussJordan(double a[N][N+1]) {
    int i, j, k;
    double factor;

    // Proses eliminasi Gauss-Jordan
    for (i = 0; i < N; i++) {
        // Membuat elemen diagonal menjadi 1 dengan pembagian
        if (a[i][i] == 0) {
            printf("Error: Pivot element is zero. Cannot continue.\n");
            return;
        }

        // Membagi seluruh baris dengan elemen pivot untuk membuat pivot menjadi 1
        factor = a[i][i];
        for (j = 0; j <= N; j++) {
            a[i][j] /= factor;
        }

        // Mengeliminasi elemen di kolom yang sama pada baris lainnya
        for (j = 0; j < N; j++) {
            if (j != i) { // Jangan lakukan pada baris yang sama
                factor = a[j][i];
                for (k = 0; k <= N; k++) {
                    a[j][k] -= a[i][k] * factor;
                }
            }
        }
    }
}



int main() {
    // Matriks augmented [A|B]
    double a[N][N+1] = {
        {2, 8, 6, 20},
        {4, 2, -2, -2},
        {3, -2, 1, 12}
    };

    // Menampilkan matriks augmented sebelum eliminasi
    printf("Matriks Augmented Sebelum Eliminasi Gauss-Jordan:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }

    // Panggil fungsi Gauss-Jordan untuk menyelesaikan SPL
    gaussJordan(a);

    // Menampilkan matriks setelah Gauss-Jordan (seharusnya matriks identitas)
    printf("\nMatriks setelah Eliminasi Gauss-Jordan (Identitas):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
    
    // Menampilkan solusi variabel
    printf("\nSolusi:\n");
    for (int i = 0; i < N; i++) {
        printf("X%d = %.2f\n", i + 1, a[i][N]); // Solusi ada di kolom terakhir
    }

    return 0;
}
