#include<bits/stdc++.h>

using namespace std;

template <class T>
struct node{
	T value;
	node* next = NULL;
};

template <class T>
class linked_list{
	node<T> head;
	int counter = 0;

	public :
		int display(){
			node<T>* itr = &head;
			int i=0;
			while (itr){
				cout << itr->value << "  ";
				itr = itr->next;
				i++;
			}
			cout << "\n";
			return i;
		}

		int size () { return this->counter;}

		T get(const int& i){
			node<T>* itr = &head;
			int p = 0;
			while (p!=i){
				itr = itr->next;
				p++;
			}
			return itr->value;
		}
		
		void push(T var){

			if (!this->counter) {
				this->head.value = var;
				this->counter++;
				return;
			}

			node<T>* new_node = new node<T>;
			new_node->value = var;
			node<T>* itr = &this->head;

			while (itr->next) {
				itr = itr->next;
			}

			itr->next = new_node;
			this->counter++;
		}

		T pop () {
			node<T>* itr = &head;
			while (itr->next->next){
				itr = itr->next;
			}
			T temp = itr->next->value;
			delete itr->next;
			itr->next = NULL;
			this->counter--;
			return temp;
		}
};

int main(){

	linked_list<int> my_list;

	my_list.push(0);
	my_list.push(1);
	my_list.push(11);
	my_list.push(111);
	my_list.push(1111);

	my_list.display();
	cout << my_list.get(2);
	

	return 0;
}