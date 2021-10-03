#include<bits/stdc++.h>

using namespace std;


struct node{
	int value;
	node* next = NULL;
};

int display(node* head){
	int i=0;
	while (head){
		cout << head->value << "  ";
		head = head->next;
		i++;
 	}
	cout << "\n";
	return i;
}

int main(){

	node *first, *second, *third;

	first = new node;
	second = new node;
	third = new node;

	first->value = 11;
	first->next = second;

	second->value = 111; 
	second->next = third;

	third->value = 1111; 
	third->next = NULL;

	display(first);


// Adding an element at the beginning.
	node* zeroth = new node;

	zeroth->value = 1;
	zeroth->next = first;

	display(zeroth);


return 0;
}