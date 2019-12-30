// The code is writtern for small letter only for simplicity purpose
// on equivalent frequency it will return the first one in alphabatic order e.g 'ba' will return a

#include <iostream>
#include<string>
using namespace std;

// count number of repetition for each letter save the count for each letter in array
void count_frequency(char *, int *, int, int);

char max_freq(int *, int size);


int main() {
	int alpha_freq[26] = {};
	string word = "bccccccccccca";
	int len = word.length();

	// & is get the address of specific cell
	// word[0] meam first letter or first cell containing character
	// &word[0] mean get the address of the string first charater
	count_frequency(&word[0], alpha_freq, len, 26);
	cout << "The Max Freq Letter is:: " << max_freq(alpha_freq, 26) << endl;

}

void count_frequency(char *sent, int *alpha_freq, int lens, int lenf) {

	int count = 0;
	char *temp = 0;

	// first for loop check for each letter a-z in sent. Asci for a is 97 and 123 for z;
	for (char ch = 97; ch < 123; ch++) {
		
		temp = sent; // initialize temporary array with 'sent'array
		for (int i = 0; i < lens; i++) { // iterate over each letter in 'sent'
			if (ch == *temp) // check that e.g. if 'a' is there in sent 
				count++;
			temp++;
		}
		
		/*
		// calculate index e.g a = 97 so index = 97-97 = 0:e.g b = 98 so index = 98-97 = 1
		so a = 0,b = 1 , c = 2 index till z
		*/
		int index = ch - 97; 
		*(alpha_freq + index) = count; // is equivalent alpha_freq[index] = count;
		count = 0; // reset count for next character
	}
}

char max_freq(int *alpha_freq, int size) {

	// This part is easy peasy so no need to put army of comment over here.
	// simple calculae the indes of max character
	/*
		[2,3,4,21,0------] -> upto 26
		so max is 21 and 21 is at index 3
		so to get character we add 3 to 97 = 100 = d
	
	*/
	int max = *alpha_freq;
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (max < *alpha_freq) {
			max = *alpha_freq;
			index = i;
		}
		alpha_freq++;
	}

	return index + 97; // to retrieve character reverse the line 54 process e.g a is at 0 index so 0+97 = 97 = char(97) = 'a'
}
