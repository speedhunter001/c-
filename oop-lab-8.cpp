#include <iostream>
using namespace std;

#define SIZE 5

template <class X>
class List{
	
	private:
	struct node{
		X info;
		node * next;
	};
	node * head,* last;

	public:
	List();
	void insert_node( X value );
	void delete_after_node( node * current );
	X delete_last_node();
	void print_list();
};

template <class X>
List<X>::List(){
	head = NULL;
	last = NULL;
}

template <class X>
void List<X>::insert_node( X value ){
	node * temp = new node;
	temp->info = value;
	temp->next = NULL;

	if ( head == NULL ) {
		head = temp;
		last = temp;
	}
	else {
		last->next = temp;
		last = last->next;	
	}
}

template <class X>
void List<X>::delete_after_node(node * current){
    node * temp = current->next;
    current->next = current->next->next;
    delete temp;
}

template <class X>
X List<X>::delete_last_node(){
    node * current = head;
    X value_of_last;
     if ( head->next == NULL ){
        value_of_last = head->info;
        head = NULL;
        last = NULL;
        delete current;
    }
    else{
        value_of_last = last->info;
        
        while ( current->next->next != NULL ){
            current = current->next;                     //now last means the new last
            }
        last = current;
        delete_after_node(current);
        }   
    return value_of_last;
}

template <class X>
void List<X>::print_list(){
    node * current = head;
   
    cout << "[ ";
    while ( current != NULL ){
        cout << current->info << " ";
        current = current->next;
    }
    cout << "]" << endl;
}



#include <iostream> 
using namespace std; 

#define SIZE 5

void pause(); 

class Queue { 
    private: 
    int q[SIZE]; 
    int in, out; 
    bool is_empty, is_full; 

    // circular increment 
    int inc(int val);

    public: 
    Queue(); 
    void enqueue(int val);  // spell that as ... enq-ue-ue
    int dequeue();          // deq-ue-ue 

    void print_queue(); 
};

Queue::Queue() { 
    for (int i = 0; i < SIZE; i++) { 
        q[i] = 0; 
    }
    in = out = 0; 
    is_empty = true; 
    is_full = false; 
}

int Queue::inc(int val) { 
    if (val + 1 == SIZE)         // loop around 
        val = 0; 
    else 
        val += 1; 
    return val; 
}

void Queue::enqueue(int val) { 
    if (is_full) {
        throw "Queue full. Cannot enqueue ... "; 
        // cout << "Nahi kerta!" ; 
        // return; 
    } 

    // put where in is and increment in 
    q[in] = val; 
    in = inc(in); 

    // check if we are now full 
    if (in == out) 
        is_full = true; 
    
    // definitely not empty any more 
    is_empty = false;       
}

int Queue::dequeue() { 
    if (is_empty) {
        throw "Queue empty. Cannot dequeue ... "; 
    } 

    // get from where out is and inc out 
    int ret = q[out]; 
    out = inc(out); 

    // see if we are now empty 
    if (in == out) 
        is_empty = true; 

    // definitely not full any more 
    is_full = false;       

    return ret; 
}


void Queue::print_queue() { 
    cout << "[\t"; 
    for (int i = 0; i < SIZE; i++)
        cout << q[i] << "\t"; 
    cout << "]" << endl; 

    cout << " \t"; 
    for (int i = 0; i < SIZE; i++) 
        cout << i << "\t"; 
    cout << " " << endl; 

    cout << " "; 
    for (int i = 0; i <= in; i++) 
        cout << "\t"; 
    cout << "^in" << endl;

    cout << " "; 
    for (int i = 0; i <= out; i++) 
        cout << "\t"; 
    cout << "^out" << endl;

    pause(); 
}


int main(){
	// List<int> l;
	
	// l.insert_node(1);
	// l.insert_node(2);
	// l.insert_node(3);
	// l.print_list();

	// l.delete_last_node();
	// l.print_list();

	// l.delete_last_node();
	// l.print_list();

	// l.delete_last_node();
	// l.print_list();

	// List<string> s;
	// s.insert_node("hi");
	// s.insert_node("hello");
	// s.insert_node("hey");

	// Queue que; 
    
 //    que.print_queue();  

 //    que.enqueue(5); 
 //    que.print_queue();  

 //    que.enqueue(11); 
 //    que.print_queue();  

 //    que.enqueue(22); 
 //    que.print_queue();    

 //    que.enqueue(33); 
 //    que.print_queue();    
    
 //    que.enqueue(44); 
 //    que.print_queue();    

 //    // que.enqueue(55);          // uncomment and then change is_full 
 //    que.print_queue();    


    // return 0; 


    try { 


        // // let's dequeue a few 
        // cout << endl << "Now dequeue ... " << endl; 
        // cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 
        // cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 
        // cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 
        // cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 

        // cout << "Got val: " << que.dequeue() << endl;    que.print_queue(); 
        // cout << "Got val: " << que.dequeue() << endl;    que.print_queue();      // doesn't work 

    	if(true)
    		throw "begharat insaaan";

    } catch (const char *msg) { 
        cout << msg << endl; ; 
    }

	return 0;
}





void pause() {
    getchar(); 
    }