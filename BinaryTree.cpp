#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class BinaryTree {
    

public:
	TreeNode* root;
    BinaryTree() : root(NULL) {}

    void insert(int val) {
        root = insertUtil(root, val);
    }

    TreeNode* insertUtil(TreeNode* node, int val) {
        if (node == NULL) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insertUtil(node->left, val);
        } else {
            node->right = insertUtil(node->right, val);
        }
        return node;
    }

    bool search(int val) {
        return searchUtil(root, val);
    }

    bool searchUtil(TreeNode* node, int val) {
        if (node == NULL) {
            return false;
        }
        if (node->data == val) {
            return true;
        } else if (val < node->data) {
            return searchUtil(node->left, val);
        } else {
            return searchUtil(node->right, val);
        }
    }

    void remove(int val) {
        root = removeUtil(root, val);
    }

    TreeNode* removeUtil(TreeNode* node, int val) {
        if (node == NULL) {
            return NULL;
        }
        if (val < node->data) {
            node->left = removeUtil(node->left, val);
        } else if (val > node->data) {
            node->right = removeUtil(node->right, val);
        } else {
            if (node->left == NULL) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = removeUtil(node->right, temp->data);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    void pOr(TreeNode* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        pOr(node->left);
        pOr(node->right);
    }

    void iOr(TreeNode* node) {
        if (node == NULL) return;
        iOr(node->left);
        cout << node->data << " ";
        iOr(node->right);
    }

    void oOr(TreeNode* node) {
        if (node == NULL) return;
        oOr(node->left);
        oOr(node->right);
        cout << node->data << " ";
    }

    void pOnR() {
        if (root == NULL) return;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            cout << node->data << " ";
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
    }

    void iOnR() {
        if (root == NULL) return;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        while (current != NULL || !stk.empty()) {
            while (current != NULL) {
                stk.push(current);
                current = current->left;
            }
            current = stk.top();
            stk.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    void oOnR() {
        if (root == NULL) return;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        TreeNode* lastVisited = NULL;
        while (current != NULL || !stk.empty()) {
            while (current != NULL) {
                stk.push(current);
                current = current->left;
            }
            current = stk.top();
            if (current->right == NULL || current->right == lastVisited) {
                cout << current->data << " ";
                stk.pop();
                lastVisited = current;
                current = NULL;
            } else {
                current = current->right;
            }
        }
    }
};

int main() {
    BinaryTree tree;
    int choice, val;

    do {
        cout << "\nBinary Tree Operations:";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Search";
        cout << "\n4. Preorder Recursive Traversal";
        cout << "\n5. Inorder Recursive Traversal";
        cout << "\n6. Postorder Recursive Traversal";
        cout << "\n7. Preorder Non-Recursive Traversal";
        cout << "\n8. Inorder Non-Recursive Traversal";
        cout << "\n9. Postorder Non-Recursive Traversal";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.remove(val);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                if (tree.search(val)) {
                    cout << "Value found in the tree.\n";
                } else {
                    cout << "Value not found in the tree.\n";
                }
                break;
            case 4:
                cout << "Preorder Recursive Traversal: ";
                tree.pOr(tree.root);
                cout << endl;
                break;
            case 5:
                cout << "Inorder Recursive Traversal: ";
                tree.iOr(tree.root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder Recursive Traversal: ";
                tree.oOr(tree.root);
                cout << endl;
                break;
            case 7:
                cout << "Preorder Non-Recursive Traversal: ";
                tree.pOnR();
                cout << endl;
                break;
            case 8:
                cout << "Inorder Non-Recursive Traversal: ";
                tree.iOnR();
                cout << endl;
                break;
            case 9:
                cout << "Postorder Non-Recursive Traversal: ";
                tree.oOnR();
                cout << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

/*Output:
Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 1
Enter value to insert: 23

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 1
Enter value to insert: 56

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 1
Enter value to insert: 24

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 1
Enter value to insert: 6

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 1
Enter value to insert: 98

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 1
Enter value to insert: 65

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 1
Enter value to insert: 72

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 1
Enter value to insert: 36

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 4
Preorder Recursive Traversal: 23 6 56 24 36 98 65 72

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 5
Inorder Recursive Traversal: 6 23 24 36 56 65 72 98

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 6
Postorder Recursive Traversal: 6 36 24 72 65 98 56 23

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 7
Preorder Non-Recursive Traversal: 23 6 56 24 36 98 65 72

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 8
Inorder Non-Recursive Traversal: 6 23 24 36 56 65 72 98

Binary Tree Operations:
1. Insert
2. Delete
3. Search
4. Preorder Recursive Traversal
5. Inorder Recursive Traversal
6. Postorder Recursive Traversal
7. Preorder Non-Recursive Traversal
8. Inorder Non-Recursive Traversal
9. Postorder Non-Recursive Traversal
0. Exit
Enter your choice: 9
Postorder Non-Recursive Traversal: 6 36 24 72 65 98 56 23
*/
