#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string factor(){
	int r = rand() % 3;

	switch(r){
		case 0:
			return "a";
		case 1:
			return "b";
		default:
			return "c";
	}
}

string term(){
	if(rand() % 2 == 0) return factor();
	else return term() + "*" + factor();
}

string expression(){
	if(rand() % 2 == 0) return term();
	else return expression() + "+" + term();
}

int main(){
	srand(time(0));

	cout << expression() << endl;

	//TODO print steps

	return 0;
}
