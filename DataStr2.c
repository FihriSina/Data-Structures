#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOYUT 50 // Maksimum ızgara boyutu
//Çıktıyı hocanın istediği gibi ayarlamayı unutma
int dizi[MAX_BOYUT][MAX_BOYUT];
int ziyaretEdildi[MAX_BOYUT][MAX_BOYUT];
int kumeBoyutlari[MAX_BOYUT * MAX_BOYUT];
int mevcutKumeBoyutu;
int satirlar, sutunlar;

int yonler[8][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},  // dikey ve yatay yön
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1} // çapraz yön
};

// Derinlik öncelikli arama
void dfs(int x, int y) {
    if (x < 0 || x >= satirlar || y < 0 || y >= sutunlar || dizi[x][y] == 0 || ziyaretEdildi[x][y])
        return;

    ziyaretEdildi[x][y] = 1;
    mevcutKumeBoyutu++;

    for (int i = 0; i < 8; i++) {
        int yeniX = x + yonler[i][0];
        int yeniY = y + yonler[i][1];
        dfs(yeniX, yeniY);
    }
}

int main() {
    // Dizi boyutlarını oku
    scanf("%d %d", &satirlar, &sutunlar);
    // Memset de kullanılabilir.
    // Diziyi ve ziyaret edilenleri başla
    for (int i = 0; i < MAX_BOYUT; i++) {
        
        for (int j = 0; j < MAX_BOYUT; j++) {
        dizi[i][j] = 0;
    }
}

    for (int i = 0; i < MAX_BOYUT; i++) {
        
        for (int j = 0; j < MAX_BOYUT; j++) {
        ziyaretEdildi[i][j] = 0;
    }
}

    for (int i = 0; i < MAX_BOYUT * MAX_BOYUT; i++) {
    kumeBoyutlari[i] = 0;
}

    // * ları oku
    while (1) {
        int x, y;
        scanf("%d", &x);
        if (x == -1)
            break;
        scanf("%d", &y);
        dizi[x][y] = 1;
    }

    // Küme ve boyutlarını bul
    int kumeSayisi = 0;
    
    for (int i = 0; i < satirlar; i++) {
        
        for (int j = 0; j < sutunlar; j++) {
            
            if (dizi[i][j] == 1 && !ziyaretEdildi[i][j]) {
                mevcutKumeBoyutu = 0;
                dfs(i, j);
                kumeBoyutlari[kumeSayisi++] = mevcutKumeBoyutu;
            }
        }
    }

    // Küme boyutunu artan şeklinde sıralama
    for (int i = 0; i < kumeSayisi - 1; i++) {
        
        for (int j = i + 1; j < kumeSayisi; j++) {
           
            if (kumeBoyutlari[i] > kumeBoyutlari[j]) {
                
                int temp = kumeBoyutlari[i];
                kumeBoyutlari[i] = kumeBoyutlari[j];
                kumeBoyutlari[j] = temp;
            }
        }
    }

    // Sonuç printle
    printf("%d ", kumeSayisi);
    
    for (int i = 0; i < kumeSayisi; i++) {
        printf("%d ", kumeBoyutlari[i]);
    }
    
    printf("\n");

    return 0;
}
