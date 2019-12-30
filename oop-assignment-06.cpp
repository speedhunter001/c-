#include <iostream> 
using namespace std; 

struct node{
    int val;
    node * next;
};


class List { 
    private:
    int do_sum(node * current);

    public:
    node * head, * tail, * last;

    void push(int val);     
    void print_list();
    //void print_tail();
    void delete_after_node(node * current);
    int pop();

    int sum_list();

    List();
};

void List::push(int val) {
    node * temp = new node;
    temp->val = val;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        last = temp;
        tail = NULL;   //because there is nothing after the head here
      //  print_tail();
    }
    else if (head->next == NULL) {
        tail = temp;
        //print_tail();
        last->next = temp;
        last = last->next;
    }
    else {
        last->next = temp;
        last = last->next;
        //print_tail();
    }
}

void List::print_list() {
    node * current = head;

    cout << "[ ";
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << "]" << endl;
}

// void List::print_tail() {
//     node * current = tail;

//     cout << "tail is : [ ";
//     while (current != NULL) {
//         cout << current->val << " ";
//         current = current->next;
//     }
//     cout << "]" << endl;
// }

void List::delete_after_node(node * current) {
    node * temp = current->next;
    current->next = current->next->next;
    delete temp;
}

int List::pop() {
    node * current = head;
    int value_of_last;

    if (head->next == NULL) {
        value_of_last = head->val;
        head = NULL;
        last = NULL;
        delete current;
    }
    else { 
        value_of_last = last->val;

        while (current->next->next != NULL){
            current = current->next;
        }
        last = current;
        delete_after_node(current);
    }

    return value_of_last;
}

int List::do_sum(node * current) {
    int sum;

    if (current->next == NULL)
        return current->val;
    else { 
        sum = current->val + do_sum(current->next);
        return sum;
    }
}

int List::sum_list() {
    if (head == NULL)
        return 0;
    else
        return do_sum(head);
}

List::List() {
    head = NULL;
    last = NULL;
}

int main() { 
    List l; 

    l.push(5);          
    l.push(15);
    l.push(30);
    l.push(32);
    l.push(3);
    l.push(29);
    l.print_list(); 

    //l.push(5);          
    //l.push(5);
    // l.push(5);
    // l.push(5);
    // l.push(5);
    // l.push(5);
    // l.push(5);          
    // l.push(5);
    // l.push(5);
    // l.push(5);
    // l.push(5);
    // l.push(5);
    // l.push(5);          
    // l.push(5);
    // l.push(5);
    // l.push(5);
    // l.push(5);
    // l.push(5);
    //l.print_list();

    //l.print_list();   //for an empty list (must comment out above)

    cout << "Sum = " << l.sum_list() << endl; 

    return 0; 
}
