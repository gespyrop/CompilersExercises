#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <list>

using namespace std;

string currentStep(stack<char> s, int state, list<char> symbols){
	string details = "";

	while(!s.empty()){
		details = s.top() + details;
		s.pop();
	}

	details = "Stack: " + details;

	details += "\tState: k" + to_string(state) + "\tInput: ";

	if(symbols.empty()){
		details += "ε";
	}
	else{
		while(!symbols.empty()){
			details += symbols.front();
			symbols.pop_front();
		}
	}

	return details;

}

void printSteps(list<string> steps){
	cout << endl;
	while(!steps.empty()){
		cout << steps.front() << endl;
		steps.pop_front();
	}
	cout << endl;
}
 
int main(int argc, char** argv){	
	string filename, choice;
	char input, stackTop;
	int state = 1;

	cout << "\nM = (K, T, V, p, k1, $, {k2})\nK = {k1, k2}\nT = {\")\",\")\", ε}\nV = {A, $}\n";
	
	if(argc == 1){
		cout << "\nInsert filename: ";
		cin >> filename;
	}
	else{
		filename = argv[1];
	}
	
	ifstream file(filename);

	stack<char>* s = new stack<char>();
	list<char>* symbols = new list<char>();
	list<string>* steps = new list<string>();
	s->push('$');

	while(file >> input){
		if(input == '(' || input == ')') symbols->push_back(input);
	}

	steps->push_back(currentStep(*s, state, *symbols));

	while(!symbols->empty()){
		input = symbols->front();
		symbols->pop_front();
		if(input == '('){
			stackTop = s->top();
			s->pop();
			if(stackTop == '$'){			
				s->push('$');
				s->push('A');
			}
			else if(stackTop == 'A'){
				s->push('A');
				s->push('A');
			}
			steps->push_back(currentStep(*s, state, *symbols));
		}
		else if(input == ')'){
			stackTop = s->top();
			s->pop();
			if(stackTop == 'A'){
				steps->push_back(currentStep(*s, state, *symbols));
			}
			else if(stackTop == '$'){
				break;
			}
		}
	}

	if(s->size() == 1){
		state = 2;
		steps->push_back(currentStep(*s, state, *symbols));
		cout << "\nYES" << endl;
	}
	else{
		cout << "\nNO" << endl;
	}

	delete s;
	delete symbols;

	do{
		cout << "\nPrint steps? (y/n): ";
		cin >> choice;
		if(choice == "y" || choice == "Y"){
			printSteps(*steps);
			break;
		}

		if(choice != "n" && choice != "N") cout << "Invalid choice!\n";
	}while(choice != "n" && choice != "N");

	delete steps;

	return 0;
}
