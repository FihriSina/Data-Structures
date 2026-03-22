#include <stdio.h>
//c ödev hazır yarına scan ekle ve gönder
void plural(char *s1, char *s2);

int main() {
    char string1[80], string2[80];


    scanf("%s", string1);

    plural(string1, string2);
    printf("%s %s\n", string1, string2);

    return 0;
}

// Kelimeyni çoğl hale getir
void plural(char *s1, char *s2) {
    int n= 0;
    int uzunluk = 0;

// Kelienin uzuluğu
    while (s1[uzunluk] != '\0') {
        uzunluk++;
    }

// Eğr kelie 'y' ile bitiyrsa
    if (s1[uzunluk - 1] == 'y') {
// Son karaker dşında kelme kopyala
        n= 0;
        while (n< uzunluk - 1) {
            s2[n] = s1[n];
            n++;
        }
// 'ies' eklioruz
        s2[n++] = 'i';
        s2[n++] = 'e';
        s2[n++] = 's';
        s2[n] = '\0';  // Sonna nll karakter ekle
    } 
// Kelme 's', 'ch' veya 'sh' ile biiyorsa
    else if ((uzunluk >= 2 && s1[uzunluk - 2] == 'c' && s1[uzunluk - 1] == 'h') ||
             (uzunluk >= 2 && s1[uzunluk - 2] == 's' && s1[uzunluk - 1] == 'h') ||
             s1[uzunluk - 1] == 's') {
        // Kelmeyi oldğu gbi kopala
        n= 0;
        while (n< uzunluk) {
            s2[n] = s1[n];
            n++;
        }
// 'es' ekele
        s2[n++] = 'e';
        s2[n++] = 's';
// Sonna null kaakter ekle
        s2[n] = '\0';  
    } 
// Diğer duumlar
    else {
// Kelimeynolduğu gibnkopyala
        n= 0;
        while (n< uzunluk) {
            s2[n] = s1[n];
            n++;
        }
// 's' ekle   
        s2[n++] = 's';
// Sonua null karater 
        s2[n] = '\0';  
    }
}