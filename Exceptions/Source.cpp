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