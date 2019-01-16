#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//Παράγοντας
string factor(int tabs){
	for(int i = 0; i < tabs; i++){
		cout << "\t";
	}

	int r = rand() % 3;

	switch(r){
		//Ο παράγοντας γίνεται a
		case 0:
			cout << "<factor> --> a" << endl;
			return "a";
		//Ο παράγοντας γίνεται b
		case 1:
			cout << "<factor> --> b" << endl;
			return "b";
		//Ο παράγοντας γίνεται c
		default:
			cout << "<factor> -->c" << endl;
			return "c";
	}
}

//Όρος
string term(int tabs){
	for(int i = 0; i < tabs; i++){
		cout << "\t";
	}

	//Ο όρος γίνεται παράγοντας
	if(rand() % 2 == 0){
		cout << "<term> --> <factor>" << endl;
		return factor(tabs + 1);
	}
	//Ο όρος γίνεται όρος * παράγοντας
	else{
		cout << "<term> --> <term> * <factor>" << endl;
		return term(tabs + 1) + " * " + factor(tabs + 1);
	}
}

//Έκφραση
string expression(int tabs){
	for(int i = 0; i < tabs; i++){
		cout << "\t";
	}

	//Η έκφραση γίνεται όρος
	if(rand() % 2 == 0){
		cout << "<expression> --> <term>" << endl;
		return term(tabs + 1);
	}
	//Η έκφραση γίνεται έκφραση + όρος
	else{
		cout << "<expression> --> <expression> + <term>" << endl;
		return expression(tabs + 1) + " + " + term(tabs + 1);
	}
}

int main(){
	srand(time(0));

	cout << endl << expression(0) << endl;	//Παραγωγή τυχαίας συμβολοσειράς απο την γραμματική

	return 0;
}
