#include <iostream>
using namespace std;

bool is_palindrome(string word) {
	string word_straight,word_reverse;
	if (word == "" || word == " ")
		return 1;
	else if (word.length() < 2)
		return 1;
	else {
		word_straight = word;
		word_reverse = word.reverse();
		for (int i = 0; i < word.length(); i++) {
			if (word_straight[i] == word_reverse[i])
				continue;
			else
				return 0;
		}
		return 1;
	}

}

int main() {
	cout << is_palindrome("mom") << endl;
	return 0;
}