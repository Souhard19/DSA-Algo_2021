
// Incomplete

#include <bits/stdc++.h>

using namespace std;

template <class T>
struct node
{
     T value;
     node* prev = NULL;
     node* next = NULL;
};

template <class T>
class circularLL
{
     node<T>* head = NULL;
     int counter = 0;

public:
     void display() {
          node<T> *itr = this->head;
          while (itr->next != this->head) {
               cout << itr->value << "  ";
               itr = itr->next;
          } cout << itr->value << "\n";
     }

     void displayRev () {
          node<T> *itr = this->tail;
          while (itr) {
               cout << itr->value << " ";
               itr = itr->prev;
          }
          cout << "\n";
     }

     int size () { return this->counter;}

     T get(const int &i) {
          node<T> *itr = head;
          int p = 0;
          while (p == i)
          {
               itr = itr->next;
               p++;
          }
          return itr->value;
     }

     void push(T var) {

          if (!this->counter)
          {
               node<T>* new_node = new node<T>;
               new_node->value = var;
               head = new_node;
               this->counter++;
               return;
          }

          node<T> *new_node = new node<T>;
          new_node->value = var;
          new_node->prev = this->tail;

          this->tail->next = new_node;
          this->tail = new_node;
          this->counter++;
     }

     T pop() {

          T temp = this->tail->value;

          node<T>* toDel = this->tail;
          
          this->tail = this->tail->prev;
          this->tail->next = NULL;

          delete toDel;
          this->counter--;
          return temp;
     }
};

int main()
{

     circularLL<int> my_list;

     my_list.push(0);
     my_list.push(1);
     my_list.push(11);
     my_list.push(111);
     my_list.push(1111);

     my_list.size();
     my_list.display();
     my_list.displayRev();
     cout << my_list.pop() << "\n";
     my_list.size();
     my_list.display();
     my_list.displayRev();

     return 0;
}