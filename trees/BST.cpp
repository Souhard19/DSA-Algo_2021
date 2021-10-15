#include<bits/stdc++.h>

using namespace std;

     //          20
     //         /  \
     //       17    30
     //      /     /  \
     //     14    27   40
     //    / \   / \    \
     //   12 15 22  29   50
     //  /        \
     // 1         23

struct node {
     int data;
     node* left = NULL;
     node* right = NULL;

     node(int data){
          this->data = data;
     }
};

void sortedPrint (node* head) {
     if (!head) return;
     sortedPrint(head->left);
     cout << head->data << "  ";
     sortedPrint(head->right);
}

// not complete
bool isBST (node* node_) {
     // if (node_) return 1;
     bool l=0, r=0;
     if (node_->left) {
          if (node_->left->data < node_->data) {
               l = isBST(node_->left);
          } else return false;
     } else l = true;

     if (!l) return false;

     if (node_->right) {
          if (node_->right->data > node_->data) {
               r = isBST(node_->right);
          } else return false;
     } else r = true;
     if (l&&r) return true;
     
     return false;
}

node* searchBST (node* currNode, int key) {
     if (!currNode) return currNode;

     if (key == currNode->data) {
          return currNode;
     } else if (key < currNode->data) {
          return searchBST(currNode->left, key);
     } else {
          return searchBST(currNode->right, key);
     }
}


void insert (node* currNode, int key) {
     if (key < currNode->data) {
          if (!(currNode->left)) {
               currNode->left = new node(key);
          } else {
               insert(currNode->left, key);
          }
     } else if (key > currNode->data) {
          if (!(currNode->right)) {
               currNode->right = new node(key);
          } else {
               insert(currNode->right, key);
          }
     } else return;
}

void deleteNode (node* currNode, int key) {
     node* ptr = searchBST(currNode, key);

}
          

int main() {

// Creating a Binary Search Tree;
     node* root = new node(20);
     node* one = new node(17);
     node* two = new node(30);
     node* three = new node(14);
     node* four = new node(27);
     node* five = new node(40);
     node* six = new node(12);
     node* seven = new node(15);
     node* eight = new node(22);
     node* nine = new node(29);
     node* ten = new node(50);
     node* eleven = new node(1);
     node* twelve = new node(23);

     root->left = one;
     root->right = two;

     one->left = three;

     two->left = four;
     two->right = five;

     three->left = six;
     three->right = seven;

     four->left = eight;
     four->right = nine;

     five->right = ten;

     six->left = eleven;

     eight->right = twelve;
     ///////////////////////////////////

     //inOrder(root);
     insert(root, 28);
     sortedPrint(root);
     // cout << "\n" << isBST(root);
     // cout << "\n" << (searchBST(root, 27))->data;

     return 0;
}