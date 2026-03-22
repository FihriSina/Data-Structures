#include <stdio.h>

int main() {
    // L = ALT | U = ÜST
    int L, U;
    
    
    scanf("%d %d", &L, &U);

    int asalTane = 0, mukemmelTane = 0;

    for (int i = L; i <= U; i++) {
        int toplam = 0;
        for (int j = 1; j < i; j++)
            toplam += (i % j == 0) ? j : 0; 
        mukemmelTane += (toplam == i) ? 1 : 0; 
    }

    for (int i = L; i <= U; i++) {
        if (i <= 1) continue;
        int asal_mi = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                asal_mi = 0;
                break;
            }
        }
        asalTane += asal_mi;
    }

    // Sonuçları yazdır
    printf("Prime: %d\n", asalTane);
    printf("Perfect: %d\n", mukemmelTane);

    return 0;
}
