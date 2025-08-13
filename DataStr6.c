#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    struct TreeNode *leftChild;
    int studentID;
    int grade;
    struct TreeNode *rightChild;
} TreeNode;

TreeNode* create_node(int grade, int id);
void insert(TreeNode **, int, int);
void inorder_traversal(TreeNode *);
void level_order_print(TreeNode *);
void free_memory(TreeNode *);
int get_max_depth(TreeNode *);
void print_nodes_at_depth(TreeNode *, int, TreeNode *, char);

int main() {
    TreeNode *root = NULL;
    int id, grade;

    while (1) {
        if (scanf("%d", &id) != 1 || id == -1) {
            break;
        }
        if (scanf("%d", &grade) != 1) {
            break;
        }

        insert(&root, grade, id);
    }

    inorder_traversal(root);

    printf("\n");
    level_order_print(root);

    free_memory(root);
    return 0;
}

TreeNode* create_node(int grade, int id) {
    TreeNode *new_node = malloc(sizeof(TreeNode));
    new_node->leftChild = new_node->rightChild = NULL;
    new_node->studentID = id;
    new_node->grade = grade;
    return new_node;
}

void insert(TreeNode **root, int grade, int id) {
    if (*root == NULL) {
        *root = create_node(grade, id);
    } else {
        if (grade < (*root)->grade) {
            insert(&((*root)->leftChild), grade, id);
        } else {
            insert(&((*root)->rightChild), grade, id);
        }
    }
}

void inorder_traversal(TreeNode *node) {
    if (node) {
        inorder_traversal(node->leftChild);
        printf("%d %d\n", node->studentID, node->grade);
        inorder_traversal(node->rightChild);
    }
}

int get_max_depth(TreeNode *node) {
    if (node == NULL) return 0;

    int left_depth = get_max_depth(node->leftChild);
    int right_depth = get_max_depth(node->rightChild);

    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

void level_order_print(TreeNode *root) {
    int depth = get_max_depth(root);
    for (int i = 0; i < depth; i++) {
        print_nodes_at_depth(root, i, NULL, ' ');
        printf("\n");
    }
}

void print_nodes_at_depth(TreeNode *node, int level, TreeNode *parent, char childType) {
    if (node == NULL) return;
    if (level == 0) {
        if (parent != NULL) {
            printf("%d %d (%d %c) ", node->studentID, node->grade, parent->grade, childType);
        } else {
            printf("%d %d ", node->studentID, node->grade);
        }
    } else {
        print_nodes_at_depth(node->leftChild, level - 1, node, 'L');
        print_nodes_at_depth(node->rightChild, level - 1, node, 'R');
    }
}

void free_memory(TreeNode *node) {
    if (node != NULL) {
        free_memory(node->leftChild);
        free_memory(node->rightChild);
        free(node);
    }
}
