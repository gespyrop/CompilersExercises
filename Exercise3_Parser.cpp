#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

void addToStack(stack<string>& stack,string production){
  string tempstr;
  if(production == "ε"){

  }else{
    for(int i = production.length()-1; i>=0 ;i--){
      tempstr = production[i];
      stack.push(tempstr);
    }
  }
}

void printStack(stack<string> stack){
  while(!stack.empty()){
    cout<<stack.top();
    stack.pop();
    }
    cout<<endl;
  }

int main(){

  //Leksika gia ta termatika kai ta mi termatika symbola

  map<string,int> non_terminal = {{"S",0},{"A",1},{"B",2},{"E",3}};
  map<string,int> terminal = {{"[",0},{"]",1},{":",2},{"+",3},{"x",4},{"y",5}};

  string M[4][6];
  for(int i = 0;i<4;i++){
    for(int j = 0;j<6;j++){
      M[i][j] = "fail";
    }
  }
  M[0][0] ="[A]"; M[1][0] ="BE"; M[1][4] ="BE"; M[1][5] ="BE"; M[2][0] ="S";
  M[2][4] ="x"; M[2][5] ="y"; M[3][1] ="ε"; M[3][2] =":A"; M[3][3] ="+A";

  //Dimiourgia tis stoivas

  stack<string> stack;
  stack.push("$");
  stack.push("S");

  //Anagnwsei leksis apo ton xrhsth

  cout<<"Give a word."<<endl;
  string word;
  cin>> word;
  string originalWord = word;
  word =word + "$";
  cout<<endl;

  //O syntaktikos elegxos

  string production;
  string firstLetter;
  while(stack.top() != "$"){
    firstLetter = word[0];

      //Elegxei an to symbolo einai termatiko
      if(terminal.count(stack.top())){
        if(stack.top() == firstLetter){
          stack.pop();
          word = word.substr(1);
        }else{break;}

      //An den einai termatiko tote
      }else{
        production = M[non_terminal[stack.top()]][terminal[firstLetter]];
        if(production == "fail"){
          break;
        }else{
          stack.pop();
          addToStack(stack,production);
        }
      }

    cout<<"STACK: ";
    printStack(stack);
    cout<<"WORD: "<<word<<endl;
    cout<<endl;
  }

  //To apotelesma

  if(stack.top() == word){
    cout<<"The word "<<originalWord<<" was parsed successfully."<<endl;
  }else{
    cout<<"Can't be parsed."<<endl;
  }

  return 0;}
