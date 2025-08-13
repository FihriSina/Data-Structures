#include <stdio.h>
#include <string.h>
//26.07.2024 bitiş ve lab2 başlangıç
#define BOYUT 15 // MATRİS BOYUT
/*
MATRİS YAZDIR
KELİME BUL
    DİKEY YATAY ÇAPRAZ
*/
// MATRİS'i yazdıran fonksiyon
void matrisiYazdir(char matris[BOYUT][BOYUT], char *kelime, int xBasla, int yBasla, int xYon, int yYon) {
    
    int uzunluk = strlen(kelime);
    
    for (int i = 0; i < BOYUT; i++) {
        
        for (int j = 0; j < BOYUT; j++) {
            int x, y, bulundu = 0;
            
            for (int k = 0; k < uzunluk; k++) {
                x = xBasla + xYon * k;
                y = yBasla + yYon * k;
                if (i == x && j == y) {
                    printf("%c", matris[i][j]);
                    bulundu = 1;
                    break;
                }
            }
            
            if (!bulundu) {
                printf("*"); // Kelimeyi yoksa = YILDIZ
            }
        }
        printf("\n");
    }
}

// MATRİS içinde kelimeyi arayan fonksiyon
int kelimeyiBul(char matris[BOYUT][BOYUT], char *kelime) {
    int uzunluk = strlen(kelime);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Yatay (soldan sağa)  SEARCH
    for (int i = 0; i < BOYUT; i++) {
        
        for (int j = 0; j <= BOYUT - uzunluk; j++) {
            int k;
            
            for (k = 0; k < uzunluk; k++) {
                if (matris[i][j + k] != kelime[k]) break;
            }
            
            if (k == uzunluk) {
                matrisiYazdir(matris, kelime, i, j, 0, 1);
                return 1;
            }
        }
    }

    // Yatay arama (sağdan sola)
    for (int i = 0; i < BOYUT; i++) {
        
        for (int j = uzunluk - 1; j < BOYUT; j++) {
            int k;
            
            for (k = 0; k < uzunluk; k++) {
                if (matris[i][j - k] != kelime[k]) break;
            }
            if (k == uzunluk) {
                matrisiYazdir(matris, kelime, i, j, 0, -1);
                return 1;
            }
        }
    }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Dikey arama (yukarıdan aşağıya)
    for (int i = 0; i <= BOYUT - uzunluk; i++) {
        
        for (int j = 0; j < BOYUT; j++) {
            int k;
            
            for (k = 0; k < uzunluk; k++) {
                if (matris[i + k][j] != kelime[k]) break;
            }
            if (k == uzunluk) {
                matrisiYazdir(matris, kelime, i, j, 1, 0);
                return 1;
            }
        }
    }

    // Dikey arama (aşağıdan yukarıya)
    for (int i = uzunluk - 1; i < BOYUT; i++) {
        
        for (int j = 0; j < BOYUT; j++) {
            int k;
            
            for (k = 0; k < uzunluk; k++) {
                if (matris[i - k][j] != kelime[k]) break;
            }
            if (k == uzunluk) {
                matrisiYazdir(matris, kelime, i, j, -1, 0);
                return 1;
            }
        }
    }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
    // ÇAPRAZ arama (sol üstten sağ alta)
    for (int i = 0; i <= BOYUT - uzunluk; i++) {
        
        for (int j = 0; j <= BOYUT - uzunluk; j++) {
            int k;
            
            for (k = 0; k < uzunluk; k++) {
                if (matris[i + k][j + k] != kelime[k]) break;
            }
            if (k == uzunluk) {
                matrisiYazdir(matris, kelime, i, j, 1, 1);
                return 1;
            }
        }
    }

    // ÇAPRAZ arama (sağ alttan sol üste)
    for (int i = uzunluk - 1; i < BOYUT; i++) {
        
        for (int j = uzunluk - 1; j < BOYUT; j++) {
            int k;
            
            for (k = 0; k < uzunluk; k++) {
                if (matris[i - k][j - k] != kelime[k]) break;
            }
            if (k == uzunluk) {
                matrisiYazdir(matris, kelime, i, j, -1, -1);
                return 1;
            }
        }
    }

    // ÇAPRAZ arama (sağ üstten sol alta)
    for (int i = 0; i <= BOYUT - uzunluk; i++) {
        
        for (int j = uzunluk - 1; j < BOYUT; j++) {
            int k;
            
            for (k = 0; k < uzunluk; k++) {
                if (matris[i + k][j - k] != kelime[k]) break;
            }
            if (k == uzunluk) {
                matrisiYazdir(matris, kelime, i, j, 1, -1);
                return 1;
            }
        }
    }

    // ÇAPRAZ arama (sol alttan sağ üste)
    for (int i = uzunluk - 1; i < BOYUT; i++) {
        
        for (int j = 0; j <= BOYUT - uzunluk; j++) {
            int k;
            
            for (k = 0; k < uzunluk; k++) {
                if (matris[i - k][j + k] != kelime[k]) break;
            }
            if (k == uzunluk) {
                matrisiYazdir(matris, kelime, i, j, -1, 1);
                return 1;
            }
        }
    }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
    return 0; // Kelime blunamazsa
}

int main() {
    char matris[BOYUT][BOYUT];
    char kelime[BOYUT];
    
    // 15x15 MATRİS'i oku
    for (int i = 0; i < BOYUT; i++) {
        
        for (int j = 0; j < BOYUT; j++) {
            scanf(" %c", &matris[i][j]);
        }
    }
    
    // Aranacak kelimeyi scanla
    scanf("%s", kelime);
    
    // Kelime bulunamazsa MATRİS =  yıldızla
    if (!kelimeyiBul(matris, kelime)) {
        
        for (int i = 0; i < BOYUT; i++) {
            
            for (int j = 0; j < BOYUT; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    
    return 0;
}
