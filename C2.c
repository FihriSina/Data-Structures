#include <stdio.h>


//* daha anlaşılabilir yaz *
//* yorum satrıları ekle   *

void printPattern(int n) {
    /*
    
    a = satir numara
    b = # sayisi
    k = bosluk sayisi
    orta = sayi hesap, karakter hesap
    
    */
    int a, b, k, orta;
   
    // Üst Taraf
    for (a =1; a <= n; a++) {
        
        // 1. sütun
        printf("%d", a);
        
        for (b =1; b <= a; b++) {
            printf("#");
        }
        printf("%d", a);

        // Dikey boşluk
        for (k =1; k <= (2 * (n - a)); k++) { // 1 eksilt
            printf(" ");
        }

        // 2. sütun
        orta = 2 * a - 1;
        
        if (orta>= 10) {
            printf("1");

        } else {
            printf("%d", orta);
        }
        
        for (b =1; b <= 2 * a - 1; b++) {
            printf("#");
        }
        
        if (orta >= 10) {
            printf("1");

        } else {
            printf("%d", orta);
        }

        // Dikey boşluk
        for (k =1; k <= (2 * (n - a)); k++) { // 1 eksilt
            printf(" ");
        }

        // 3. sütun
        printf("%d", a);
        
        for (b =1; b <= a; b++) {
            printf("#");
        }
        printf("%d", a);

        printf("\n");
    }

    // Alt kısım
    for (a =n - 1; a >= 1; a--) {
        
        // 1. dikey
        printf("%d", a);
        
        for (b =1; b <= a; b++) {
            printf("#");
        }
        printf("%d", a);

        // dikeyler arasındaki boşluk
        for (k =1; k <= (2 * (n - a)); k++) { // 1 eksilt
            printf(" ");
        }

        // Orta sütun
        orta =2 * a - 1;
        
        if (orta >= 10) {
            printf("1");

        } else {
            printf("%d", orta);
        }
        
        for (b =1; b <= 2 * a - 1; b++) {
            printf("#");
        }
        
        if (orta >= 10) {
            printf("1");
            
        } else {
            printf("%d", orta);
        }

        // Dikeyler arasındaki boşluk
        for (k =1; k <= (2 * (n - a)); k++) { // 1 eksilt
            printf(" ");
        }

        // 3. sütun
        printf("%d", a);
        
        for (b =1; b <= a; b++) {
            printf("#");
        }
        printf("%d", a);

        printf("\n");
    }
}
    /*
    
    a = satir numara
    b = # sayisi
    k = bosluk sayisi
    orta = sayi hesap, karakter hesap

    */
//* daha anlaşılabilir yaz *
//* yorum satrıları ekle   * 
    
    

int main() {
    int n;


    scanf("%d", &n);

    printPattern(n);

    return 0;
}

