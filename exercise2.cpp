#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string factor(int tabs){
	for(int i = 0; i < tabs; i++){
		cout << "\t";
	}

	int r = rand() % 3;

	switch(r){
		case 0:
			cout << "<factor> --> a" << endl;// << endl;
			return "a";
		case 1:
			cout << "<factor> --> b" << endl;// << endl;
			return "b";
		default:
			cout << "<factor> -->c" << endl;// << endl;
			return "c";
	}
}

string term(int tabs){
	for(int i = 0; i < tabs; i++){
		cout << "\t";
	}

	if(rand() % 2 == 0){
		cout << "<term> --> <factor>" << endl;
		return factor(tabs + 1);
	}
	else{
		cout << "<term> --> <term> * <factor>" << endl;
		return term(tabs + 1) + " * " + factor(tabs + 1);
	}
}

string expression(int tabs){
	for(int i = 0; i < tabs; i++){
		cout << "\t";
	}

	if(rand() % 2 == 0){
		cout << "<expression> --> <term>" << endl;
		return term(tabs + 1);
	}
	else{
		cout << "<expression> --> <expression> + <term>" << endl;
		return expression(tabs + 1) + " + " + term(tabs + 1);
	}
}

int main(){
	srand(time(0));

	cout << endl << expression(0) << endl;

	return 0;
}
