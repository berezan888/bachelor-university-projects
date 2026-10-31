#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

int compareTrees(Node* root1, Node* root2);
void freeTree(Node* root);

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int main() {
    int k;
    int n;
    scanf("%d %d", &n, &k);
    short j;
    short i;
    int** prototypes = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        prototypes[i] = (int*)malloc(k * sizeof(int));
        for (j = 0; j < k; j++) {
            scanf("%d", &prototypes[i][j]);
        }
    }
    int count = 0;
    for (i = 0; i < n; i++) {
        Node* root = NULL;
        for (j = 0; j < k; j++) {
            root = insert(root, prototypes[i][j]);
        }
        int unique = 1;
        for (j = 0; j < i; j++) {
            Node* tempRoot = NULL;
            for (int l = 0; l < k; l++) {
                tempRoot = insert(tempRoot, prototypes[j][l]);
            }
            if (compareTrees(root, tempRoot)) {
                unique = 0;
                break;
            }
            freeTree(tempRoot);
        }
        if (unique) {
            count++;
        }
        freeTree(root);
    }
    printf("%d\n", count);
    for (i = 0; i < n; i++) {
        free(prototypes[i]);
    }
    free(prototypes);
    return 0;
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int compareTrees(Node* root1, Node* root2){
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    if (root1 != NULL && root2 != NULL) {
        return compareTrees(root1->left, root2->left) && compareTrees(root1->right, root2->right);
    }
    return 0;
}