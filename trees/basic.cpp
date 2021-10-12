#include<bits/stdc++.h>

using namespace std;

     //          1
     //         / \
     //        2   3
     //       /   / \
     //      4   5   6
     //       \ / \
     //       7 8  9

struct node {
     int data;
     node* left = NULL;
     node* right = NULL;

     node(int data){
          this->data = data;
     }
};

void preOrder (node* head) {
     if (!head) return;
     cout << head->data << "  ";
     preOrder(head->left);
     preOrder(head->right);
}

void postOrder (node* head) {
     if (!head) return;
     postOrder(head->left);
     postOrder(head->right);
     cout << head->data << "  ";
}

void inOrder (node* head) {
     if (!head) return;
     inOrder(head->left);
     cout << head->data << "  ";
     inOrder(head->right);
}

int main() {

     node* root = new node(1);
     node* one = new node(2);
     node* two = new node(3);
     node* three = new node(4);
     node* four = new node(5);
     node* five = new node(6);
     node* six = new node(7);
     node* seven = new node(8);
     node* eight = new node(9);

     root->left = one;
     root->right = two;

     one->left = three;

     two->left = four;
     two->right = five;

     three->right = six;

     four->left = seven;
     four->right = eight;

     preOrder(root); cout << "\n";
     postOrder(root); cout << "\n";
     inOrder(root); cout << "\n";

     return 0;
}