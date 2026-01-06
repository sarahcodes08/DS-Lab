#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    Node* getroot() {
        return root;
    }

    // Helper to update root from main (if needed)
    void fixroot(Node* rt) {
        root = rt;
    }

    // Create a new node
    Node* getnode(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    // Insert a node into the BST
    Node* insert(Node* root, int d) {
        if (root == nullptr) {
            return getnode(d); // Create root if empty
        } 
        else if (d < root->data) {
            root->left = insert(root->left, d);
        } 
        else {
            root->right = insert(root->right, d);
        }
        return root;
    }

    // Search for a value
    bool search(Node* root, int key) {
        if (root == nullptr) {
            return false;
        } 
        else if (key < root->data) {
            return search(root->left, key);
        } 
        else if (key > root->data) {
            return search(root->right, key);
        } 
        else {
            return true; // Key found
        }
    }

    // In-order traversal (Left -> Root -> Right)
    // Produces sorted output
    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Pre-order traversal (Root -> Left -> Right)
    void preorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Post-order traversal (Left -> Right -> Root)
    void postorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // Find Minimum Value Node (used for deletion)
    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // Deletion in BST
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }

        // Navigate to the node to be deleted
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Node found. Handle the 3 cases:

            // Case 1: Leaf node (no children)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: One child (Right child only)
            else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            // Case 2: One child (Left child only)
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            // Find min value in right subtree (in-order successor)
            Node* temp = findMin(root->right);
            root->data = temp->data; // Copy successor's value
            // Delete the successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
};

int main() {
    BST bst;
    int choice;
    int input;

    cout << "--- Binary Search Tree ---" << endl;

    do {
        cout << "\n MENU " << endl;
        cout << "1. Insert " << endl;
        cout << "2. Delete " << endl;
        cout << "3. Search " << endl;
        cout << "4. Display (In-order) " << endl;
        cout << "5. Exit " << endl;
        cout << "Enter choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> input;
                // Update the root explicitly after insertion
                bst.fixroot(bst.insert(bst.getroot(), input));
                cout << "Inserted " << input << "." << endl;
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> input;
                bst.fixroot(bst.deleteNode(bst.getroot(), input));
                cout << "Deleted " << input << " (if it existed)." << endl;
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> input;
                if (bst.search(bst.getroot(), input))
                    cout << "Value FOUND." << endl;
                else
                    cout << "Value NOT FOUND." << endl;
                break;

            case 4:
                cout << "In-order Display: ";
                bst.inorder(bst.getroot());
                cout << endl;
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Try Again." << endl;
        }
    } while (choice != 5);

    return 0;
}
