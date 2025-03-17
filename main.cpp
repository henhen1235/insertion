#include <iostream>
#include <fstream>
#include "dNode.h"
#include <cstring>
#include <cstdlib>

using namespace std;

void addfunc(dNode *& treehead);
void placenode(int newint, dNode *& headnode);
void displays(dNode* top);
void displayrunner(dNode* tempposition, int depth);
void removes(dNode*& headnode);
void checkers(dNode*& headnode);

int main(){
    dNode* treehead = NULL;
    while(true){
      char i2n[50]; // ask user for what they want to do
        char add[50] = "add";
	char find[50] = "find";
        char remove[50] = "remove";
        char display[50] = "display";
        cout << endl << "What would you like to do?: ";
        cin.getline(i2n, 50);
        if(strcmp(i2n, add) == 0){
            addfunc(treehead);
        }
        else if(strcmp(i2n, remove) == 0){
	  removes(treehead);
	}
	else if(strcmp(i2n, find) == 0){
	  checkers(treehead);
	}
        else if(strcmp(i2n, display) == 0){
	  displays(treehead);
	}
        else{
            cout << "Invalid input options are: add, remove, and display" << endl;
        }
    }
    return 0;
}

void checkers(dNode*& headnode){
  int in;
  cout << endl << "What do you want to check?: ";
  cin >> in;
  cout << headnode->getint() << endl;
  dNode* tempnode = headnode;
  while(true){
    if(tempnode->getint() < in){
      if(tempnode->getRight() == NULL){
	cout << "This number does not exist. right" << endl;
	return;
      }
      cout << "right once" << endl;
      tempnode = tempnode->getRight();      
    }
    else if(tempnode->getint() > in){
      if(tempnode->getLeft() == NULL){
	cout << "This number does not exist. left" << endl;
        return;
      }
      cout << "left once" << endl;
      tempnode = tempnode->getLeft();
    }
    else{
      cout << "This number does exist" << endl;
      return;
      }
    }
  }


void removes(dNode*& headnode){
  int in;
  cout << endl << "Would you rather read in from console or file?: ";
  cin >> in;
  dNode* tempnode = headnode;
  cout << tempnode->getint() <<  endl;
  while(true){
    if(tempnode->getint() < in){
      if(tempnode->getRight() != NULL){
	tempnode = tempnode->getRight();
      }
      cout << "This number does not exist." << endl;
      return;
    }
    if(tempnode->getint() > in){
      if(tempnode->getLeft() != NULL){
        tempnode = tempnode->getLeft();
      }
      cout << "This number does not exist." << endl;
      return;
    }
    else{
      if(tempnode->getLeft() == NULL && tempnode->getRight() == NULL){
      }
    }
  }
}

void addfunc(dNode *& treehead){
    char in[50];
    char con[50] = "console";
    char fil[50] = "file";
    cout << endl << "Would you rather read in from console or file?: ";
    cin.getline(in, 50);
    if(strcmp(in, con) == 0){
        char num[50];
        cout << "Enter the series of numbers you would like to add: ";
        cin.getline(num, 50);
	int spot = strlen(num);
	num[spot] = ' ';
	num[spot + 1] = '\0';
        int pos = 0;
        int tempnumpos = 0;
        int numarr[50];
        int numarrpos = 0;

        while(num[pos] != '\0'){
            char tempnum[10];
            if(num[pos] != ' ' && num[pos] != '\0'){
                tempnum[tempnumpos] = num[pos];
                tempnumpos++;
                pos++;
            }
            else if(num[pos] == ' ' || num[pos] == '\0'){
                tempnum[tempnumpos] = '\0';
                tempnumpos = 0;
                int finnum = atoi(tempnum);
                numarr[numarrpos] = finnum;
                numarrpos++;
                pos++;
            }
            else{
                break;
            }
        }
	
        for(int i = 0; i < numarrpos; i++){
	  placenode(numarr[i], treehead);
        }
    }
    else if(strcmp(in, fil) == 0){
      cout << "Please type file name" << endl;
      string name;
      getline(cin, name);
      string txt = ".txt";
      ifstream inputFile((name + txt));
      int num;
      while (inputFile >> num) {
        placenode(num, treehead);
      }
      inputFile.close();
    }
    else{
        cout << "Invalid input options are: console, and file" << endl;
    }

}

void placenode(int newint, dNode *& headnode){
  cout << "printed: " << newint << endl;
  if(headnode == NULL){
    dNode* newnode= new dNode(newint);
    headnode = newnode;
    return;
  }

  dNode* tempnode = headnode;
  while(true){
  if(tempnode->getint() > newint){
    if(tempnode->getLeft() == NULL){
      dNode* newnode = new dNode(newint);
      tempnode->setLeft(newnode);
      break;
    }
    tempnode = tempnode->getLeft();
  }
  else if(tempnode->getint() <= newint){
    if(tempnode->getRight() == NULL){
      dNode* newnode = new dNode(newint);
      tempnode->setRight(newnode);
      break;
    }
    tempnode = tempnode->getRight();
  }
  }
}

void displays(dNode* top){//diplay everything
  if (top == NULL) {
    return;
  }
  int depth = 0;
  displayrunner(top, depth); 
}

void displayrunner(dNode* tempposition, int depth){// display runner function
  if(tempposition->getLeft() != NULL){//go down the right nodes
    displayrunner(tempposition->getLeft(), depth + 1);
  }
  for(int x = 0; x < depth; x++){//orint
    cout << '\t';
  }
  cout << tempposition->getint() << endl;
  if(tempposition->getRight() != NULL){//go down the left nodes
    displayrunner(tempposition->getRight(), depth + 1);
  }
}
 
