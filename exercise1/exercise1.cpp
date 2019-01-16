#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <list>

using namespace std;

//Η στοίβα και η λίστα με τα σύμβολα εισόδου περνάνε κατα τιμή ώστε να μην αλλάξουν στην main
string currentStep(stack<char> s, int state, list<char> symbols){
	string details = "";

	while(!s.empty()){	//μέχρι να αδειάσει η στοίβα
		details = s.top() + details; //προστείθεται στην αρχή του details κάθε στοιχείο της στοίβας απο πάνω προς τα κάτω
		s.pop();
	}

	details = "Stack: " + details

	details += "\tState: k" + to_string(state) + "\tInput: "; //προστείθεται η τρέχουσα κατάσταση

	if(symbols.empty()){
		details += "ε"; //αν δεν υπάρχουν σύμβολα εισόδου προστείθεται το 'ε'
	}
	else{
		while(!symbols.empty()){
			details += symbols.front(); //αλλίως προστίθονται στο details όλα τα σύμβολα εισόδου
			symbols.pop_front();
		}
	}

	return details; //επιστρέφεται το details

}

//εκτύπωση των βημάτων
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
	int state = 1;	//Κατάσταση

	//Κανόνες αυτόματου στοίβας
	cout << "\nM = (K, T, V, p, k1, $, {k2})\nK = {k1, k2}\nT = {\")\",\")\", ε}\nV = {A, $}\n";
	
	if(argc == 1){	//Αν ο χρήστης δεν έχει δώσει κανένα όρισμα
		cout << "\nInsert filename: ";	//του ζητείται να πληκτρολογίσει το όνομα του αρχείου
		cin >> filename;
	}
	else{
		filename = argv[1];	//αλλιώς δέχεται το πρώτο όρισμα για όνομα αρχείου
	}
	
	ifstream file(filename);

	stack<char>* s = new stack<char>();	//Στοίβα
	list<char>* symbols = new list<char>();	//Σύμβολα εισόδου
	list<string>* steps = new list<string>(); //Λίστα για την αποθήκευση των βημάτων
	s->push('$');	//Τοποθετείται το $ στην στοίβα

	while(file >> input){
		if(input == '(' || input == ')') symbols->push_back(input); //Αν ο χαρακτήρας είναι '(' ή ')' τον βάζει στην λίστα με τα σύμβολα εισόδου
	}

	steps->push_back(currentStep(*s, state, *symbols));

	while(!symbols->empty()){ 		//μέχρι να διαβαστούν όλα τα σύμβολα εισόδου
		input = symbols->front();  //διβάζεται ένα σύμβολο
		symbols->pop_front();
		if(input == '('){			//Αν είναι '('
			stackTop = s->top();   //Διαβάζεται και αφαιρείται το πρώτο στοιχείο της στοίβας
			s->pop();
			if(stackTop == '$'){	//Αν είναι το '$' τότε προστείθεται το '$' και το 'Α'
				s->push('$');		
				s->push('A');
			}
			else if(stackTop == 'A'){	//Αλλιώς αν είναι 'Α' προστείθεται το 'Α' και το 'Α'
				s->push('A');
				s->push('A');
			}
			steps->push_back(currentStep(*s, state, *symbols)); //Αποθηκεύεται το τρέχον βήμα
		}
		else if(input == ')'){		//Αλλιώς αν το σύμβολο εισόδου είναι ')'
			stackTop = s->top();   //Διαβάζεται και αφαιρείται το πρώτο στοιχείο της στοίβας
			s->pop();
			if(stackTop == 'A'){	//Αν είναι 'Α' αποθηκεύεται το τρέχον βήμα
				steps->push_back(currentStep(*s, state, *symbols));
			}
			else if(stackTop == '$'){	//Αλλιώς σημαίνει ότι έχουν διαβαστεί περισσότερες ')' και η ανάγνωση της εισόδου σταμτάει
				break;
			}
		}
	}

	if(s->size() == 1){	//Αν η στοίβα έχει μόνο ένα στοιχείο (το '$')
		state = 2;		//Το αυτόματο μεταβαίνει στην κατάσταση 2
		steps->push_back(currentStep(*s, state, *symbols));
		cout << "\nYES" << endl;	//και εκτυπώνεται η ένδειξη 'YES'
	}
	else{
		cout << "\nNO" << endl;	//Διαφορετικά εκτυπώνεται η ένδειξη 'NO'
	}

	//Αποδέσμευση της μνήμης που δεσμεύτηκε για την στοίβα και την λίστα με τα σύμβολα εισόδου
	delete s;	
	delete symbols;

	do{
		cout << "\nPrint steps? (y/n): "; //Δίνεται η επιλογή εκτύπωσης της αλληλουχίας βημάτων του ΝΑΣ
		cin >> choice;
		if(choice == "y" || choice == "Y"){
			printSteps(*steps);
			break;
		}

		if(choice != "n" && choice != "N") cout << "Invalid choice!\n";
	}while(choice != "n" && choice != "N");

	//Αποδέσμευση της μνήμης που δεσμεύτηκε για την λίστα με τα βήματα
	delete steps;

	return 0;
}
