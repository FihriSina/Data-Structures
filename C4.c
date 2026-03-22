#include <stdio.h>


int findOdd(int sayi) {    
    if (sayi == 0) {
        return 0;
    }

    // Son basamağın tek olup olmadığını kontrol et
    int son_Bas = sayi % 10;
    int tekse = 0;

    if (son_Bas % 2 != 0) {
        // Son bas. tek ise tekseyi +1
        tekse = 1;  
    }

    // Son basamak tekse + 1 |
    return tekse + findOdd(sayi / 10);
}

int main() {
    int Sayi;

    scanf("%d", &Sayi);
    // Sonuç
    printf("%d\n", findOdd(Sayi));

    return 0;
}
