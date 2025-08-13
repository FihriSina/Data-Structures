#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structı seviyorum
typedef struct {
    char isim[20]; 
    int oncelik;  
} Arayan;

// Arayanın adına göre öncelikleyen fonks.
typedef enum {
    ANNE = 1, BABAM, KARDESIM,
    AMCAM, TEYZEM, DAYIM, HALAM,
    ISYERI, OKUL,
    ARKADASIM,
    BANKA, KARGO,
    REKLAM,
    BILINMEYEN
} Oncelik;

int oncelik_belirle(char *isim) {
    if (strcmp(isim, "Annem") == 0 || strcmp(isim, "Babam") == 0 || strcmp(isim, "Kardesim") == 0)
        return ANNE;
    if (strcmp(isim, "Amcam") == 0 || strcmp(isim, "Teyzem") == 0 || strcmp(isim, "Dayim") == 0 || strcmp(isim, "Halam") == 0)
        return AMCAM;
    if (strcmp(isim, "Isyeri") == 0 || strcmp(isim, "Okul") == 0)
        return ISYERI;
    if (strstr(isim, "Arkadasim") != NULL)
        return ARKADASIM;
    if (strcmp(isim, "Banka") == 0 || strcmp(isim, "Kargo") == 0)
        return BANKA;
    if (strcmp(isim, "Reklam") == 0)
        return REKLAM;
    return BILINMEYEN;
}


// Öncelik ve alfabetik için karşılaştırma fonk.
int cagri_karsilastir(const void *a, const void *b) {
    Arayan *arayanA = (Arayan *)a;
    Arayan *arayanB = (Arayan *)b;

    // Öncelik farkı
    int oncelikFarki = arayanA->oncelik - arayanB->oncelik;
    if (oncelikFarki != 0) {
        return oncelikFarki;
    }

    // if(Öncelikler eşit) {alfabetik sırala}
    return strcmp(arayanA->isim, arayanB->isim);
}


// Girdiyi oku - öncelik verme - sıralama - çağrı kaydını yazdırma
void cagri_kayit_isle() {
    int kapasite = 10;
    Arayan *arayanlar = malloc(kapasite * sizeof(Arayan)); 
    if (arayanlar == NULL) {
        //printf("Bellek tahsisi hatası!\n");
        return;
    }

    // lenght
    int arayan_sayisi = 0; 
    char girdi[20];

    do {
        if (fgets(girdi, sizeof(girdi), stdin) == NULL) {
            //printf("Girdi hatası!\n");
            goto temizle;
        }

        
        girdi[strcspn(girdi, "\n")] = '\0';

        if (strcmp(girdi, "-1") == 0) break;

        if (strlen(girdi) >= sizeof(arayanlar[arayan_sayisi].isim)) {
            //printf("Girdi çok uzun!\n");
            continue;
        }

        if (arayan_sayisi >= kapasite) {
            kapasite *= 2;
            Arayan *temp = realloc(arayanlar, kapasite * sizeof(Arayan)); //bellek++
            if (temp == NULL) {
                //printf("Bellek tahsisi hatası!\n");
                goto temizle;
            }
            arayanlar = temp;
        }

        strcpy(arayanlar[arayan_sayisi].isim, girdi);
        arayanlar[arayan_sayisi].oncelik = oncelik_belirle(girdi);
        arayan_sayisi++;
    } while (1);


    qsort(arayanlar, arayan_sayisi, sizeof(Arayan), cagri_karsilastir);

    // sıralı çağrı yazdırma
    for (int i = 0; i < arayan_sayisi; i++) {
        printf("%s\n", arayanlar[i].isim);
    }

temizle:
    // Eller havada
    free(arayanlar); 
}


int main() {
    
    cagri_kayit_isle();

    return 0;
}
