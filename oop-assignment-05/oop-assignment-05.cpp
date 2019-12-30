#include <iostream> 
#include <fstream>
using namespace std;

#define SIZE 4 

// stuff from Queue lecture goes here ... then apply template on it 
void pause(){
    getchar();
}

template <class T>
class Queue {
    private:
    T q[SIZE];
    int in, out;
    bool is_empty, is_full;

    int inc(int val_to_increase);   //circular increment

    public:
    Queue();
    void enqueue(T val);
    T dequeue();
    bool tell_is_empty();
    bool tell_is_full();

    void print_queue();
};

template <class T>
Queue<T>::Queue() {
    in = out = 0;
    is_empty = true;
    is_full = false;
}

template <class T>
int Queue<T>::inc(int val_to_increase) {
    if (val_to_increase + 1 == SIZE)
        val_to_increase = 0;
    else
        val_to_increase = val_to_increase + 1;
    return val_to_increase;
}

template <class T>
void Queue<T>::enqueue(T val) {
        //cout << "is_empty after enqueuing is : " << is_empty << endl;
    if (is_full){
        throw "Mr.Queueueue is fulll.He can't eat anymore";
    }

    q[in] = val;
    //cout << q[in] << endl;
    in = inc(in);

    if (in == out)
        is_full = true;
   
    is_empty = false;
}

template <class T>
T Queue<T>::dequeue() {
    if (is_empty){
        // cout << "is_empty : " << is_empty << endl;
        throw "Mr.Queueue is empty because he is hungry";
    }

    T returning_val = q[out];
    out = inc(out);

    if (out == in)
        is_empty = true;

    is_full = false;
    return returning_val;
}

template <class T>
bool Queue<T>::tell_is_empty(){
    return is_empty;
}

template <class T>
bool Queue<T>::tell_is_full(){
    return is_full;
}

template <class T>
void Queue<T>::print_queue() {
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


class Writer { 
    // fill stuff here 
    public:
    void process_file(string filename, Queue <string> * q);
}; 
// method definitions for Writer class here 
void Writer::process_file(string filename, Queue <string> * q) {
    string line;
    ifstream fin;
    //cout << "In the writer" << endl;

    fin.open(filename);
    while ( !fin.eof() ) {
        getline(fin,line);
        try{
            if ( q->tell_is_full() == true )
                break;
            //cout << line << endl;
            q->enqueue(line);
        }
        catch ( const char * message ) {
            cout << message << endl;
        }
    }
    fin.close();
    //cout<< "exiting the writer" << endl;
}


class Reader { 
    // fill stuff  here 
    public:
    void process_queue(Queue <string> * q);
};
//method definitions for Reader class here 
void Reader::process_queue(Queue <string> * q) {
    string line;
    //cout << "entering the reader" << endl;
    while( q->tell_is_empty() != true ) {
        try {
            line = q->dequeue();
            cout << "String: " << " [" << line << "] " << "has length:  " << line.length() << endl;
            pause();
        }
        catch (const char * message) {
            cout << message << endl;
        }
    }
    //cout << "exiting the reader" << endl;
}




int main() { 
    Queue<string> *que; 
    que = new Queue<string>; 

    string filename = "string-collection.txt"; 

    Writer first_writer; 
    Reader first_reader; 

    first_writer.process_file(filename, que); 
    first_reader.process_queue(que); 

    return 0; 
}



