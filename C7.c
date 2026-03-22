#include <stdio.h>
#include <stdlib.h>

void spiralPrint(int satir, int sutn, int **dizi) {
    // Sınırlar
    int top = 0, alt = satir - 1, sol = 0, sag = sutn - 1;
    int i;

    // Spiral
    while (top <= alt && sol <= sag) {
        // Üst satır - sağa doğru yaz
        i = sol;
        while (i <= sag) {
            printf("%d ", dizi[top][i]);
            i++;
        }
        // Üst sınırı bir satır aşağı kaydır
        top++;

        // Sağ sütun - aşağı doğru yaz
        i = top;
        while (i <= alt) {
            printf("%d ", dizi[i][sag]);
            i++;
        }
        // Sağ sınırı bir sütun sola kaydır
        sag--;

        // Alt satır - sola doğru yaz
        if (top <= alt) { // Eğer hala alt satır varsa
            i = sag;
            while (i >= sol) {
                printf("%d ", dizi[alt][i]);
                i--;
            }
            // Alt sınırı bir satır yukarı kaydır
            alt--;
        }

        // Sol sütundan yukarı doğru yazdır
        if (sol <= sag) { // Eğer hala sol sütun varsa
            i = alt;
            while (i >= top) {
                printf("%d ", dizi[i][sol]);
                i--;
            }
            // Sol sınırı - bir sütun sağa kaydır
            sol++;
        }
    }
}

int main() {
    int satir, sutn;

    scanf("%d %d", &satir, &sutn);

    // Dinamik bellek tahsis -- matris için hafıza ayır
    int **dizi = (int **)malloc(satir * sizeof(int *));
    for (int i = 0; i < satir; i++) {
        dizi[i] = (int *)malloc(sutn * sizeof(int));
    }


    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutn; j++) {
            scanf("%d", &dizi[i][j]);
        }
    }

    // Yaz yada print işte
    spiralPrint(satir, sutn, dizi);
    printf("\n");

    // belleği freele
    for (int i = 0; i < satir; i++) {
        free(dizi[i]);
    }
    free(dizi);

    return 0;
}
