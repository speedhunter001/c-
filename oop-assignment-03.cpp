#include <iostream> 
using namespace std; 

// node structure here 
struct node{
    int val;
    node * next;
};




class List { 
    public:
    void push(int val); 
    node * head;
    node * last;
    void print_list();
    void delete_after_node(node * current);
    int pop();

    List();                    //constructor for NULL initializtion of head and last
};

void List::push(int val) { 
    node *temp = new node;      // create new node 
    temp->val = val;
    temp->next = NULL; 

    if (head == NULL) {         // for when list is empty
        head = temp; 
        last = temp; 
    } else {                    // for all other cases 
        last->next = temp;
        last = last->next; 
    } 
}

void List::print_list(){
    node * current = head;
   
    cout << "[ ";
    while ( current != NULL ){
        cout << current->val << " ";
        current = current->next;
    }
    cout << "]" << endl;
}

void List::delete_after_node(node * current){
    node * temp = current->next;
    current->next = current->next->next;
    delete temp;
}

int List::pop(){
    node * current = head;
    int value_of_last;
     if ( head->next == NULL ){
        value_of_last = head->val;
        //cout << "( head is : " << head->val <<"    last is : " << last->val <<  " )";
        head = NULL;
        last = NULL;
        //cout << "( head is : " << head <<"    last is : " << last <<  " )";
        delete current;
    }
    else{
        value_of_last = last->val;
        
        while ( current->next->next != NULL ){
            current = current->next;                     //now last means the new last
            }
        last = current;
        delete_after_node(current);
        }   
    return value_of_last;
}

    
    List::List(){                               //constructor for NULL initialization of head and last
        head = NULL;
        last = NULL;
}
    

int main() { 
    // Part - 1 Starts here ----------------------
    List l; 

    l.push(5);          
    l.print_list(); 

    l.push(15);
    l.push(30);
    l.print_list(); 

    // Part - 1 Ends here ----------------------



    // Part - 2 Starts here ----------------------

    cout << "Poppping: " << l.pop() << endl; 
    l.print_list(); 

    cout << "Poppping: " << l.pop() << endl; 
    l.print_list(); 

    cout << "Poppping: " << l.pop() << endl;         // this will give an error at first 
    l.print_list(); 

    // Part - 2 Ends here ----------------------

    return 0; 
}