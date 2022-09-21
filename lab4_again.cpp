// lab4_again.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// Print out the menu of choices for the user to select from
void printMenu() {
	cout << "Please Select which operation to perform:" << endl;
	cout << "\t1. Factorial" << endl;
	cout << "\t2. Arithmetic Series" << endl;
	cout << "\t3. Geometric Series" << endl;
	cout << "\t4. Exit" << endl;
	cout << "Your Selection: ";
}

//the backbone of the magic [functions to call]
void factorial(int choice) { 
	cout << endl << "Enter a number: ";
	cin >> choice;
	if (choice < 0) {
		cout << "Nice try, please enter a POSITIVE number: ";
		factorial(choice);
	}
	if (choice > 0) {
		cout << choice << "! =";
		int ans = 1;
		for (int n = 1; n <= choice; n++) {
			ans = ans * n;
			cout << " " << n << " ";
			if (n == choice) {
				cout << "= " << ans << endl;
			}
			else if(n <= choice) {
				cout << "+";
			}
		}
	}
}

void arithmetic() {
	int A;
	int B;
	int C;
	cout << "Enter a number to start at: ";
	cin >> A;
	cout << "Enter a number to add each time: ";
	cin >> B;
	cout << "Enter the number of elements in the series: ";
	cin >> C;

	//this is the code that comes out if the audience is being a stink
	if (C < 0) {
		cout << "Nice try, please enter a POSITIVE number: ";
		arithmetic();
	}

	//the actual math
	if (C > 0) {
		int ans = 0;
		for (int n = 1; n <= C; n++) {
			cout << " " << A << " ";
			ans = ans + A;
			A = A + B;
			if (n == C) {
				cout << "= " << ans << endl;
			}
			else if (n <= C) {
				cout << "+";
			}
		}
	}
}

void geometric() {
	int A;
	int B;
	int C;
	cout << "Enter a number to start at: ";
	cin >> A;
	cout << "Enter a number to multiply each time: ";
	cin >> B;
	cout << "Enter the number of elements in the series: ";
	cin >> C;

	//if the player is being a stink, we tell them off!
	if (C < 0) {
		cout << "Nice try, please enter a POSITIVE number: ";
		arithmetic();
	}

	//the math
	if (C > 0) {
		int ans = 0;
		for (int n = 1; n <= C; n++) {
			cout << " " << A << " ";
			ans = ans + A;
			A = A * B;
			if (n == C) {
				cout << "= " << ans << endl;
			}
			else if (n <= C) {
				cout << "+";
			}
		}
	}
}

//where the magic is born [main function]
int main() {
	int choice;
	char again;


	do {
		printMenu();
		cin >> choice;

		if (choice > 3 || choice < 1) {
			return 0;
		}
		else if (choice == 1) {
			cout << "Factorial:";
			factorial(choice);
		}
		else if (choice == 2) {
			cout << "Arithmetic Series:" << endl;
			arithmetic();
		}
		else if (choice == 3) {
			cout << "Geometric Series:" << endl;
			geometric();
		}
		cout << "Go Again? [Y/N] ";
		cin >> again;
	} while (again == 'y' || again == 'Y');
}