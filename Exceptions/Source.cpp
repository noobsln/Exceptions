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