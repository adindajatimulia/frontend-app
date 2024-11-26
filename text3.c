#include <stdio.h>
#include <math.h>
#define N 3      // Jumlah variabel (x1, x2, x3)
#define MAX_ITER 1000  // Batas jumlah iterasi
#define TOLERANCE 1e-6  // Toleransi untuk konvergensi

// Fungsi untuk menghitung solusi menggunakan metode Gauss-Seidel
void gaussSeidel(double a[N][N], double b[N], double x[N]) {
    int i, j, iter;
    double sum, temp;

    // Iterasi Gauss-Seidel
    for (iter = 0; iter < MAX_ITER; iter++) {
        // Menyimpan nilai sementara untuk perhitungan
        for (i = 0; i < N; i++) {
            sum = b[i];  // Mulai dengan konstanta dari persamaan
            for (j = 0; j < N; j++) {
                // Kurangkan kontribusi variabel lain
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            // Update nilai variabel x[i]
            temp = x[i];
            x[i] = sum / a[i][i];

            // Mengecek konvergensi (selisih antara nilai baru dan lama)
            if (fabs(x[i] - temp) < TOLERANCE) {
                break;
            }
        }

        // Mengecek apakah konvergensi sudah tercapai
        if (iter > 0) {
            int converged = 1;
            for (i = 0; i < N; i++) {
                if (fabs(x[i] - x[i]) > TOLERANCE) {
                    converged = 0;
                    break;
                }
            }
            if (converged) break;
        }
    }
}

int main() {
    // Matriks koefisien (A) dan konstanta (B) untuk sistem persamaan
    double a[N][N] = {
        {4, 1, 1},
        {0, 6, 2},
        {1, 2, 8}
    };
    double b[N] = {9, 18, 29};
    double x[N] = {0, 0, 0};  // Nilai awal untuk x1, x2, x3

    // Menampilkan matriks augmented awal
    printf("Matriks Augmented Sebelum Iterasi:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("| %.2f\n", b[i]);
    }

    // Memanggil fungsi Gauss-Seidel untuk menghitung solusi
    gaussSeidel(a, b, x);

    // Menampilkan hasil akhir solusi
    printf("\nSolusi setelah iterasi Gauss-Seidel:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }

    return 0;
}
