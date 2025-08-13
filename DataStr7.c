#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int uzunluk;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->uzunluk = 1;
    return node;
}

int nodeUzunluk(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->uzunluk;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return nodeUzunluk(node->left) - nodeUzunluk(node->right);
}

// Sağ rotasyon
struct Node* rotaSag(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Yükseklik güncel
    y->uzunluk = max(nodeUzunluk(y->left), nodeUzunluk(y->right)) + 1;
    x->uzunluk = max(nodeUzunluk(x->left), nodeUzunluk(x->right)) + 1;

    return x;
}

// Sol rotasyon 
struct Node* rotaSol(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Yükseklik güncell
    x->uzunluk = max(nodeUzunluk(x->left), nodeUzunluk(x->right)) + 1;
    y->uzunluk = max(nodeUzunluk(y->left), nodeUzunluk(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // Yükseklik güncell
    node->uzunluk = 1 + max(nodeUzunluk(node->left), nodeUzunluk(node->right));

    int balance = getBalance(node);

    // Sol ağır durumda sağ rotasyon
    if (balance > 1 && key < node->left->key)
        return rotaSag(node);

    // Sağ ağır durumda sol rotasyon
    if (balance < -1 && key > node->right->key)
        return rotaSol(node);

    // Sol-Right rotasyon durumu
    if (balance > 1 && key > node->left->key) {
        node->left = rotaSol(node->left);
        return rotaSag(node);
    }

    // Sağ-Left rotasyon durumu
    if (balance < -1 && key < node->right->key) {
        node->right = rotaSag(node->right);
        return rotaSol(node);
    }

    return node;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d \n", root->key);
        inorderTraversal(root->right);
    }
}

void printGivenLevel(struct Node* root, struct Node* parent, int level) {
    if (root == NULL)
        return;

    if (level == 1) {
        int parentKey = (parent == NULL) ? -1 : parent->key;
        char position = 'B';  // Varsayılan 'B'
        
        if (parent != NULL) {
            if (root == parent->left) position = 'L';  // Sol child
            else if (root == parent->right) position = 'R';  // Sağ child
        }
        
        int balance = getBalance(root);  // Node'un denge faktörü

        if (parent == NULL) {
            printf("%d (-1 B) ", root->key);  // Root node için
        } else {
            printf("%d (%d %c) (%d B) ", root->key, parentKey, position, balance);
        }
    } else if (level > 1) {
        printGivenLevel(root->left, root, level-1);
        printGivenLevel(root->right, root, level-1);
    }
}

int treeUzunluk(struct Node* node) {
    if (node == NULL)
        return 0;
    return 1 + max(treeUzunluk(node->left), treeUzunluk(node->right));
}

void printTreeStructure(struct Node* root) {
    int h = treeUzunluk(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, NULL, i);
        printf("\n");
    }
}

int main() {
    struct Node* root = NULL;
    int key;

    // Kullanıcıdan scanle
    while (1) {
        scanf("%d", &key);
        if (key == -1)
            break;
        root = insert(root, key);
    }

    // In-order traversal çıktısı
    inorderTraversal(root);
    printf("\n");

    // AVL ağacının yapısı
    printTreeStructure(root);

    return 0;
}
