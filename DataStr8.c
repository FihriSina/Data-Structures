#include <stdio.h>
#include <stdlib.h>


typedef enum { RED, BLACK } Colour;


typedef struct Node {
    int data;            
    Colour color;        
    struct Node *sol;    
    struct Node *sag;    
    struct Node *parent; 
} Node;

Node *kok = NULL; 

// Sol rotasyon
void RotaSol(Node **kok, Node *x) {
    Node *y = x->sag; // y düğümünü belirle
    x->sag = y->sol;  // y'nin sol çocuğunu x'in sağ çocuğu 
    if (y->sol != NULL) y->sol->parent = x;
    y->parent = x->parent; // y'nin ebeveynini güncelle
    if (x->parent == NULL) *kok = y; // x kökse, y kök olur
    else if (x == x->parent->sol) x->parent->sol = y; // x, ebeveyninin sol çocuğuysa
    else x->parent->sag = y; // x, ebeveyninin sağ çocuğuysa
    y->sol = x; // x'i y'nin sol çocuğu 
    x->parent = y; // x'in ebeveynini y 
}

// Sağ rotasyon 
void RotaSag(Node **kok, Node *y) {
    Node *x = y->sol; // x düğümünü belirle
    y->sol = x->sag;  // x'in sağ çocuğunu y'nin sol çocuğu 
    if (x->sag != NULL) x->sag->parent = y;
    x->parent = y->parent; // x'in parentenini güncelle
    if (y->parent == NULL) *kok = x; // y kökse, x kök olur
    else if (y == y->parent->sol) y->parent->sol = x; // y, parentenin sol çocuğuysa
    else y->parent->sag = x; // y, parenti sağ çocuğuysa
    x->sag = y; // y'yi x'in sağ çocuğu 
    y->parent = x; // y'nin parenti x 
}

// Yeni düğüm oluştur
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data; // Veriyi ata
    newNode->color = RED; // Yeni düğümün rengi kırmızı
    newNode->sol = newNode->sag = newNode->parent = NULL; // Çocukları ve Parenti NULL
    return newNode;
}

// Ağacın renk ihlallerini düzeltme
void fixViolation(Node **kok, Node *z) {
    while (z != *kok && z->parent->color == RED) {
        Node *y = (z->parent == z->parent->parent->sol) ? z->parent->parent->sag : z->parent->parent->sol;

        if (y != NULL && y->color == RED) {
            z->parent->color = BLACK; // Parntini siyah 
            y->color = BLACK; 
            z->parent->parent->color = RED; 
            z = z->parent->parent; // ykarı çık
        } else {
            if (z->parent == z->parent->parent->sol) {
                if (z == z->parent->sag) {
                    z = z->parent; // z sağ cocuks, rotasyon yapmdn önce z'yi parent 
                    RotaSol(kok, z); // Sol rotasny 
                }
                z->parent->color = BLACK; // Parentini siyah 
                z->parent->parent->color = RED; // byük paretnini kırmızı 
                RotaSag(kok, z->parent->parent); // Sağ rotasyon 
            } else {
                if (z == z->parent->sol) {
                    z = z->parent; // Z sol cocuks, rotasyon yapmdn önce z'yi parenti 
                    RotaSag(kok, z); // Sağ rotasyon 
                }
                z->parent->color = BLACK; // prteniti siyah 
                z->parent->parent->color = RED; // Büyük parenteni kırmızı 
                RotaSol(kok, z->parent->parent); // Sol rotasyon 
            }
        }
    }
    (*kok)->color = BLACK; // Kök dugumu her zaman siyah 
}

// Yeni düğümü ağaca ekle
void insert(Node **kok, Node *z) {
    Node *y = NULL;
    Node *x = *kok;

    while (x) {
        y = x;
        x = (z->data < x->data) ? x->sol : x->sag; // datayı karılastırrak uygun pozisyonu searchle
    }

    z->parent = y; // z'nin prantini y yap
    if (!y) *kok = z; // y NULL ise, z kök olur
    else if (z->data < y->data) y->sol = z; // z, y'den kcuukse, y'nin sol çocuğu olur
    else y->sag = z; // z, y'den buyukuse, y'nin sağ çocuğu olur

    fixViolation(kok, z); // Renk ihllalerini düzelt
}

// belli bir sevydeki dugmleri yazdır
void printGivenLevel(Node* kok, Node* parent, int level) {
    if (kok == NULL)
        return;

    if (level == 1) {
        int parentKey = (parent == NULL) ? -1 : parent->data;
        char position = 'B';  // vasylan 'B'
        
        if (parent != NULL) {
            if (kok == parent->sol) position = 'L';  // Sol çocuk
            else if (kok == parent->sag) position = 'R';  // Sağ çocuk =cihld
        }

        if (parent == NULL) {
            printf("%d %c", kok->data, kok->color == RED ? 'R' : 'B');  // Kök düğüm için
        } else {
            printf("%d %c (%d %c) ", kok->data, kok->color == RED ? 'R' : 'B', parentKey, position);
        }
    } else if (level > 1) {
        printGivenLevel(kok->sol, kok, level-1); // Sol cock
        printGivenLevel(kok->sag, kok, level-1); // Sağ çocuk
    }
}

// ikli ağacın inorder dolaşmı
void inorder(Node *kok) {
    if (kok == NULL) return;
    inorder(kok->sol); // Sol alt ağaç
    printf("%d\n", kok->data); // dugumu yazdr
    inorder(kok->sag); // Sağ alt ağaç
}

// Ağacın yukseklığbı bulma
int uzunluk(Node *node) {
    if (!node) return 0;
    int luzunluk = uzunluk(node->sol);
    int ruzunluk = uzunluk(node->sag);
    return (luzunluk > ruzunluk ? luzunluk : ruzunluk) + 1;
}

// ağacı seviylere göre yazdıran 
void yazAgacYapı(Node* kok) {
    int h = uzunluk(kok); // ağcın yüksekliğini bul
    for (int i = 1; i <= h; i++) {
        printGivenLevel(kok, NULL, i); // ehr seviyedeki düğümleri yazdır
        printf("\n");
    }
}

int main() {
    int girdi;

    while (1) {
        scanf("%d", &girdi);
        if (girdi == -1)
            break; // -1 le çık
        Node *newNode = createNode(girdi); // Yeni düğüm oluş
        insert(&kok, newNode); // Ağaca ekle
    }
    inorder(kok); // İnorder yap
    printf("\n");
    yazAgacYapı(kok); // Ağacı seviyelere göre yazdır
    return 0;
}
