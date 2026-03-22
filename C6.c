#include <stdio.h>
#include <stdbool.h>

void topBul(int dizi[10], int top);

int main() {
    int dizi[10];
    int top;

    for(int i = 0; i < 10; i++) {
        scanf("%d", &dizi[i]);
    }

    scanf("%d", &top);
    topBul(dizi, top);

    return 0;
}

void topBul(int dizi[10], int top) {
    bool bul = false;
    for(int i = 0; i < 10; i++) {
        for(int j = i + 1; j < 10; j++) {
            if(dizi[i] + dizi[j] == top) {
                printf("%d %d\n", i, j);
                bul = true;
            }
        }
    }
    if(bul == false) {
        printf("-1");
    }
}