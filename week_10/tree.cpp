#include <iostream>
#include <queue>
using namespace std;

struct Node {
   char data;
   Node* left;
   Node* right;

   Node(char val) {
      data = val;
      left = right = NULL;
   }
};

void preorder(Node* root) {
   if (root == NULL) return;

   cout << root->data << " "; 
   preorder(root->left); 
   preorder(root->right); 
}

void inorder(Node* root) {
   if (root == NULL) return;

   inorder(root->left); 
   cout << root->data << " "; 
   inorder(root->right); 
}

void postorder(Node* root) {
   if (root == NULL) return;

   postorder(root->left); 
   postorder(root->right); 
   cout << root->data << " "; 
}
void levelOrder(Node* root) {
   if (root == NULL) return;

   queue<Node*> q;
   q.push(root);

   while (!q.empty()) {
      Node* current = q.front();
      q.pop();
      cout << current->data << " ";

      if (current->left != NULL)
         q.push(current->left);

      if (current->right != NULL)
         q.push(current->right);
      }
}

int main() {
   int n;
   char data;
   cin >> n;
   Node* root = NULL;
   queue<Node*> q;

   int i = 0;
   cout << "Values: ";

   while (n--) {
      cin >> data;

      Node* newNode = new Node(data);
        if (root == NULL) {
            root = newNode;
            q.push(root);
        } else {
            Node* current = q.front();

            if (current->left == NULL) {
                current->left = newNode;
                q.push(newNode);
            } 
            else if (current->right == NULL) {
                current->right = newNode;
                q.push(newNode);
                q.pop();
            }
        }
    }

    cout << "Preorder : ";
    preorder(root);

    cout << "\nInorder : ";
    inorder(root);

    cout << "\nPostorder : ";
    postorder(root);

    cout << "\nLevelOrder: ";
    levelOrder(root);

    return 0;
}
