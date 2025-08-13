#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Şarkı düğümü yapısı
struct SongNode {
    // Şarkı ismi
    char data[50];   
    // Şarkı numarası 
    int id;           
    // Önceki düğüm
    struct SongNode* previous; 
    // Sonraki düğüm 
    struct SongNode* next;     
};

// Yeni düğüm
struct SongNode* createSongNode(char* data, int id) {
    struct SongNode* newSongNode = (struct SongNode*)malloc(sizeof(struct SongNode));
    strcpy(newSongNode->data, data);
    newSongNode->id = id;
    newSongNode->previous = NULL;
    newSongNode->next = NULL;
    return newSongNode;
}

int main() {
    // Liste başı
    struct SongNode* head = NULL;  
    // Liste sonu
    struct SongNode* tail = NULL;  
    struct SongNode* current;
    char input[50];
    int songCount = 0;  // Şarkı sayısı

    // Şarkı ekleme
    while (1) {
        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = 0; 
        
        if (strcmp(input, "-1") == 0)
            break;

        songCount++;
        struct SongNode* newSongNode = createSongNode(input, songCount);

        if (head == NULL) {
            head = newSongNode;
            tail = head;
        } else {
            tail->next = newSongNode;
            newSongNode->previous = tail;
            tail = newSongNode;
        }
    }

    char direction;
    int jumpStep;
    scanf(" %c %d", &direction, &jumpStep);

    // Zıpla ve yazdır
    current = (direction == 'F') ? head : tail;
    while (current != NULL) {
        printf("%s\n", current->data);

        // İleri geri zıpla
        for (int i = 0; i < jumpStep; i++) {
            if (direction == 'F')
                current = current->next;
            else
                current = current->previous;

            // Çıkış 
            if (current == NULL)
                break;
        }
    }

    return 0;
}
