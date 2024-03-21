#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

// Function to calculate maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate height of a node
int height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// Function to create a new node
Node *newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Function to perform a right rotation
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to insert a new node into the AVL tree
Node *insert(Node *root, int key) {
    // Step 1: Perform standard BST insertion
    if (root == nullptr)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else // Duplicate keys are not allowed
        return root;

    // Step 2: Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Step 3: Get the balance factor
    int balance = height(root->left) - height(root->right);

    // Step 4: Perform rotations if needed
    // Left-Left case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right-Right case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left-Right case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Left case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform in-order traversal
void inorderTraversal(Node *root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

// Function to perform post-order traversal
void postorderTraversal(Node *root) {
    if (root == nullptr)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->key << " ";
}

int main() {
    Node *root = nullptr;
    int k;
    char choice;
    do{
        cout<<"Enter the key: "<<endl;
        cin>>k;
        root = insert(root, k);
        
        cout<<"Do you want to continue? (Y/N) "<<endl;
        cin>>choice;
    }while(choice=='Y' || choice=='y');
    
    cout << "In-order traversal of the AVL tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Post-order traversal of the AVL tree: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
