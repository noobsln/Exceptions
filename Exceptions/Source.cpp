#include <iostream>
using namespace std;

class InvalidCharacterException : public runtime_error {
public:
	InvalidCharacterException() : runtime_error("[ERROR: Invalid character]") {}
};
class InvalidRangeException : public runtime_error {
public:
	InvalidRangeException() : runtime_error("[ERROR: Invalid range]") {}
};

char character(char start, int offset) {
	if (!isalpha(start))
		throw InvalidCharacterException();
	if (!isalpha(start + offset))
		throw InvalidRangeException();
	if (isupper(start) && islower(start + offset) || islower(start) && isupper(start+offset))
		throw InvalidRangeException();
	return (start + offset);
}

int main() {
	try {
		cout << "Passing a, 1... ";
		cout << character('a', 1) << '\n';

		cout << "Passing a, -1... ";
		cout << character('a', -1) << '\n';

		cout << "Passing Z, -1... ";
		cout << character('Z', -1) << '\n';

		cout << "Passing ?, 5... ";
		cout << character('?', 5) << '\n';

		cout << "Passing A, 32... ";
		cout << character('A', 32);
	}
	catch (const InvalidCharacterException& e) {
		cout << e.what();
	}
	catch (const InvalidRangeException& e) {
		cout << e.what();
	}
	return 0;
}