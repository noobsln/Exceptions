#include <iostream>
using namespace std;

class InvalidCharacterException : public runtime_error {
public:
	InvalidCharacterException() : runtime_error("ERR:Invalid character") {}
};
class InvalidRangeException : public runtime_error {
public:
	InvalidRangeException() : runtime_error("ERR:Invalid range") {}
};

char character(char start, int offset) {
	if (!isalpha(start) || isupper(start))
		throw InvalidCharacterException();
	if (!isdigit(offset) || (start + offset) < 'a' || (start + offset) > 'z')
		throw InvalidRangeException();
	return (start + offset);
}

int main() {
	try {
		cout << "Passing a, 1... ";
		cout << character('a', 1);

		cout << "Passing a, -1: ";
		cout << character('a', -1);

		cout << "Passing Z, -1: ";
		cout << character('Z', -1);

		cout << "Passing ?, 5: ";
		cout << character('?', 5);
	}
	catch (const InvalidCharacterException& e) {
		cout << e.what();
	}
	catch (const InvalidRangeException& e) {
		cout << e.what();
	}
	return 0;
}