#include <iostream>
#include <fstream>
#include "dNode.h"
#include <cstring>
#include <cstdlib>

using namespace std;

void addconosle(dNode *& treehead);
void placenode(int newint, dNode *& headnode);
void displays(dNode* top);
void displayrunner(dNode* tempposition, int depth);
void removes(dNode*& headnode);
void checkers(dNode*& headnode);
void deleter(dNode* tempposition);
void inserter(int num, dNode* & treehead);
dNode* uncle(dNode* current);
dNode* runner(dNode*& current, dNode*& treehead);

int main(){
    dNode* treehead = NULL;
    while(true){
      char i2n[50]; // ask user for what they want to do
      char add[50] = "file";
      char console[50] = "console";
      char display[50] = "display";
      char quit[50] = "quit";
      cout << endl << "What would you like to do? (file, console, display, quit): ";
      cin.getline(i2n, 50);
      if(strcmp(i2n, add) == 0){ // adding from file

      }
      else if(strcmp(i2n, console) == 0){ // adding from conosle
	addconosle(treehead);
      }
      else if(strcmp(i2n, display) == 0){
      }
      else if(strcmp(i2n, quit) == 0){
      }
      else{
        cout << "Invalid input options are: file, console, display, and quit" << endl;
      }
    }
    return 0;
}

void addconosle(dNode *& treehead){
    int num;
    cout << "Enter the number you would like to add: ";
    cin >> num;
    inserter(num, treehead);
}

void inserter(int num, dNode*& treehead){
  dNode* newnode = new dNode(num);
  if(treehead == NULL){
    newnode->setred(false);
    treehead = newnode;
  }
  else{
  dNode* tempnode = headnode;
  while(true){
    if(tempnode->getint() >= newint){
      if(tempnode->getLeft() == NULL){
	newnode->setParent(tempnode);
	tempnode->setLeft(newnode);
      break;
      }
      tempnode = tempnode->getLeft();
    }
    else if(tempnode->getint() < newint){
      if(tempnode->getRight() == NULL){
	newnode->setParent(tempnode);
	tempnode->setRight(newnode);
	break;
      }
      tempnode = tempnode->getRight();
    }
  }
  }
  runner(newnode, treehead)
}

dNode* runner(dNode*& current, dNode*& treehead){
  if(current->getParent() == treehead){
    return;
  }
  dNode* uncler = uncle(current);
  if(uncler->getred == true && current->getParent->getred == true && uncler->getParent->getred == false){
    uncler->setred == false;
    current->getParent->setred == false;
    uncle->getParent->setred == true;
    runner(uncler->getParent, treehead);
  }
  if()
}

dNode* uncle(dNode* current){
  if(grandparent->getRight == parent && grandparent->getLeft != NULL){
    return grandparent->getLeft;
  }
  else if(grandparent->getLeft == parent && grandparent->getRight != NULL){
    return grandparent->getRight;
  }
  else{
    return NULL;
  }
}


void placenode(int newint, dNode *& headnode){
  if(headnode == NULL){
    dNode* newnode= new dNode(newint);
    headnode = newnode;
    return;
  }

  dNode* tempnode = headnode;
  while(true){
  if(tempnode->getint() >= newint){
    if(tempnode->getLeft() == NULL){
      dNode* newnode = new dNode(newint);
      newnode->setParent(tempnode);
      tempnode->setLeft(newnode);
      break;
    }
    tempnode = tempnode->getLeft();
  }
  else if(tempnode->getint() < newint){
    if(tempnode->getRight() == NULL){
      dNode* newnode = new dNode(newint);
      newnode->setParent(tempnode);
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

void deleter(dNode* tempposition){// display runner function
  if(tempposition->getLeft() != NULL){//go down the right nodes
    deleter(tempposition->getLeft());
  }
  if(tempposition->getRight() != NULL){//go down the left nodes
    deleter(tempposition->getRight());
  }
  delete tempposition;
}
 
