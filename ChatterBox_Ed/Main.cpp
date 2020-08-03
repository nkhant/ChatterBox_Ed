#include <iostream>
#include "Learner.h"
#include <string>

using namespace std;

int main() {
	Learner AI; // Createa learner Object

	/*
		The follow is the main loop. It will continue until the applicaion is closed.
		The user enters their input, and then the Learner will respond.
	*/

	for (;;) {
		cout << "\nYOU:"; // User prompt
		string phrase;
		getline(cin, phrase); // Using getline for multi word input, then store in phrase.

		cout << "ED: ";
		AI.respond(phrase); // Pass the user input to the Learner and see if he can respond.
	}
	return 0;
}