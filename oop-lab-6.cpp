#include <iostream>
using namespace std;

struct node{
	int val;
	node * next;
};

node * head = NULL;

void insert(int x){
	node * temp = new node;
	temp->val = x;
	temp->next = NULL;

	if ( head == NULL )
		head = temp;
	else {
		node * current = head;
		while ( current->next != NULL ){
			current = current->next;
		}
		current->next = temp;
	}
}

void print_node(){
	node * current = head;
	cout << "[  ";
	while ( current != NULL ){
		cout << current->val << " ";
		current = current->next;
	}
	cout << " ]" << endl;
}

void delete_node(int x){
	node * temp = head;
	
	if ( head->val == x ){
		head = head->next;
		delete temp;
	}
	else{
		node * current = head;
		while( current->next != NULL ){
		
			if ( current->next->val == x ){
				temp = current->next;
				
				if ( current->next->next == NULL ){
					current->next = NULL;
					break;
				}

				else
				current->next = current->next->next;
				
				delete temp;
			}
				current = current->next;
		}
	}
}

int main(){

	// int temp[8];
	// int x;
	// int * straight;
	// int * reverse;

	// for ( int i = 0; i < 8; i++ ){
	// 	cout << "Enter the element at index : " << i << " : ";     //initialization
	// 	cin >> x;
	// 	temp[i] = x;
	// }

	// straight = temp;
	// reverse = temp;

	// cout << "From first index to last index" << endl;
	// for ( int i = 0; i < 8; i++ ){                                //printing from first to last
	// 	cout << *straight << endl;
	// 	straight = straight + 1;
	// }
	// reverse = straight - 1;
	// cout << endl;

	// cout << "From last index to first index" << endl;
	// for ( int i = 0; i < 8; i++ ){								  //printing from last to first
	// 	cout << *reverse << endl;
	// 	reverse = reverse - 1;
	// }

	


	insert(1);
	insert(2);
	insert(3);
	print_node();

	// delete_node(1);
	// print_node();

	delete_node(3);
	print_node();
	
	return 0;
}