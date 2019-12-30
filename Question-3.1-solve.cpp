#include <iostream>
using namespace std;

bool is_palindrome_with_pointer(char *, int);
bool is_palindrome_without_pointer(char[], int); // we can also use above funtion prototype paramter 
												 //e.g. is_palindrome_without_pointer(char *, int).
												 // int arr[] == int *arr both are equivalent when it come to parameter passing

int main() {

	char ch[4] = { 'A','n','n','A' };

	// 1 output mean palindrome and 0 mean not palindrome
	cout << "Using simple Array:: " << is_palindrome_without_pointer(ch, 4) << endl;
	cout << "Using array with Pointer:: " << is_palindrome_with_pointer(ch, 4) << endl;
}

bool is_palindrome_with_pointer(char *start, int size) {

	// ceil is basic operation which round off the number e.g = ceil(3/2) ->ceil(1.5) = 2
	// Assign one pointer to start of the array and one to the end
	// so for palindrome, word half letters should be quivalent to the other half e.g in abba  we just check first two letter with last

	// start is pointing to first letter and end is pointing to last
	// we compare start with last and increment the start with decrementing the end pointers
	/*
	string  = abbba or abbc
	start = a;
	end = a;

	loop:
	check equal:
	yes then: 
		inc start = b
		dec end = b
		continue:
	No then:
	   break the loop:
	
	
	*/
	char *end = 0;
	end = start + size - 1;

	// loop should be run for half as in palindrome we just need to check half letter with other half e.g 1221 we just need to check 12 with 21
	for (int i = 0; i < ceil(size / 2); i++) {

		// check first with last
		if (*start != *end)
			return false; // if any one character didn't match return false abbc so a!=c then return false
		start++;
		end--;
	}

	return true;
}

bool is_palindrome_without_pointer(char *start, int size) {

	// ceil is basic operation which round off the number e.g = ceil(3/2) ->ceil(1.5) = 2

	int endindex = size - 1;
	for (int i = 0; i < ceil(size / 2); i++) {
		if (start[i] != start[endindex - i]) 
			return false;
	}

	return true;
}