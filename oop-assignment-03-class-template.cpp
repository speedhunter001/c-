#include <iostream> 
using namespace std; 

// node structure here 

template<class T>
class List { 
    struct node{
    T val;
    node * next;
    };

    public:
    void push(T val); 
    node * head;
    node * last;
    void print_list();
    void delete_after_node(node * current);
    T pop();

    List();                    //constructor for NULL initializtion of head and last
};

template <class T>
void List<T>::push(T val) { 
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

template <class T>
void List<T>::print_list(){
    node * current = head;
   
    cout << "[ ";
    while ( current != NULL ){
        cout << current->val << " ";
        current = current->next;
    }
    cout << "]" << endl;
}

template <class T>
void List<T>::delete_after_node(node * current){
    node * temp = current->next;
    current->next = current->next->next;
    delete temp;
}

template <class T>
T List<T>::pop(){
    node * current = head;
    T value_of_last;
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

template <class T>
    List<T>::List(){                               //constructor for NULL initialization of head and last
        head = NULL;
        last = NULL;
}
    
struct student{
    string name;
    //int roll_no;         error error need to solve
};

int main() { 
    // Part - 1 Starts here ----------------------
    List<int> l; 

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
    cout << endl;

    // Part - 2 Ends here ----------------------

    List<string> l_s;
    l_s.push("hi");
    l_s.push("hello");
    l_s.print_list();

    cout << "Poppping: " << l_s.pop() << endl; 
    l_s.print_list(); 

    cout << "Poppping: " << l_s.pop() << endl; 
    l_s.print_list(); 
    cout << endl;

   
     student s1,s2;
    
     s1.name = "Ammar";
    // s1.roll_no = 16;

     s2.name = "unnamed";
    // s2.roll_no = 0;

     // cout << "s1 is : " << s1 << endl;
     // cout << "s2 is : " << s2 << endl;
    List<student> l_stud;
    l_s.push(s1.name);
    l_s.push(s2.name);
    l_s.print_list();

    cout << "Poppping: " << l_s.pop() << endl; 
    l_s.print_list(); 

    cout << "Poppping: " << l_s.pop() << endl; 
    l_s.print_list(); 


    return 0; 
}