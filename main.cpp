#include <iostream>
#include <fstream>
#include "dNode.h"
#include <cstring>
#include <cstdlib>

using namespace std;

void addconosle(dNode *& treehead);
void files(dNode *& treehead);
void displays(dNode* top);
void displayrunner(dNode* tempposition, int depth);
void deleter(dNode* tempposition);
void inserter(int num, dNode* & treehead);
dNode* uncle(dNode* current);
void runner(dNode*& current, dNode*& treehead);

int main(){
    dNode* treehead = NULL;
    while(true){
      char i2n[50]; // ask user for what they want to do
      char add[50] = "file";
      char console[50] = "console";
      char display[50] = "display";
      char quit[50] = "quit";
      cout << endl << "What would you like to do? (file, console, display, quit): ";
      cin >> i2n;
      if(strcmp(i2n, add) == 0){ // adding from file
        files(treehead);
      }
      else if(strcmp(i2n, console) == 0){ // adding from conosle
	      addconosle(treehead);
      }
      else if(strcmp(i2n, display) == 0){
        displays(treehead);
      }
      else if(strcmp(i2n, quit) == 0){
        deleter(treehead);
        break;
      }
      else{
        cout << "Invalid input options are: file, console, display, and quit" << endl;
      }
    }
    return 0;
}

void files(dNode *& treehead){
  cout << "Please type file name" << endl;
      string name;
      cin >> name;
      string txt = ".txt";
      ifstream inputFile((name + txt));
      int num;
      while (inputFile >> num) {
        inserter(num, treehead);
      }
      inputFile.close();
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
  dNode* tempnode = treehead;
  
  while(true){
    if(tempnode->getint() >= num){
      if(tempnode->getLeft() == NULL){
	      newnode->setParent(tempnode);
	      tempnode->setLeft(newnode);
      break;
      }
      tempnode = tempnode->getLeft();
    }
    else if(tempnode->getint() < num){
      if(tempnode->getRight() == NULL){
	      newnode->setParent(tempnode);
	      tempnode->setRight(newnode);
	      break;
      }
      tempnode = tempnode->getRight();
    }
  }

  
  }
  runner(newnode, treehead);
}

void runner(dNode*& current, dNode*& treehead){
  if(current == treehead){
    if(current->getred() == true){
      current->setred(false);
    }
    return;
  }
  if(current->getParent() == treehead){
    return;
  }

  dNode* uncler = uncle(current);
  if(uncler != NULL){
    if(uncler->getred() == true && current->getParent()->getred() == true && uncler->getParent()->getred() == false){//recolor WORKS
      uncler->setred(false);
      current->getParent()->setred(false);
      uncler->getParent()->setred(true);
      dNode* tempgrandparent = uncler->getParent();
      runner(tempgrandparent, treehead);
    }
    else if(uncler->getred() == false && current->getParent()->getred() == true){//left side cases
      if(current->getParent()->getParent()->getLeft() == current->getParent()){
        if(current->getParent()->getRight() == current){ //case1 left triange
          dNode* tempparent = current->getParent();
          dNode* templeft = current->getLeft();

          tempparent->getParent()->setLeft(current);
          current->setParent(tempparent->getParent());
          current->setLeft(tempparent);
          tempparent->setParent(current);

          tempparent->setRight(templeft);
          if(templeft != NULL){
            templeft->setParent(tempparent);
          }
          runner(tempparent, treehead);
        }
        else if(current->getParent()->getLeft() == current){//case2 left line yes uncle WORKS
            dNode* tempparent = current->getParent();
            dNode* tempgrandparent = current->getParent()->getParent();
            dNode* tempright = tempparent->getRight();
            dNode* tempgreatgrandparent = tempgrandparent->getParent();

            tempparent->setRight(tempgrandparent);
            tempgrandparent->setParent(tempparent);


            tempgrandparent->setLeft(tempright);
            if(tempright != NULL){
              tempright->setParent(tempgrandparent);
            }
            tempparent->setred(false);
            tempgrandparent->setred(true);

          tempparent->setParent(tempgreatgrandparent);

          if(tempgreatgrandparent != NULL){
            if(tempgreatgrandparent->getLeft() == tempgrandparent){
              tempgreatgrandparent->setLeft(tempparent);
            }
            else{
              tempgreatgrandparent->setRight(tempparent);
            }
        }
        else{
          treehead = tempparent;
        }
        runner(tempparent, treehead);
        }
      }
      else if(current->getParent()->getParent()->getRight() == current->getParent()){//right side cases
        if(current->getParent()->getLeft() == current){//case 3 right triangle
          dNode* tempparent = current->getParent();
          dNode* templeft = current->getRight();

          tempparent->getParent()->setRight(current);
          current->setParent(tempparent->getParent());
          current->setRight(tempparent);
          tempparent->setParent(current);

          tempparent->setLeft(templeft);
          if(templeft != NULL){
            templeft->setParent(tempparent);
          }
          runner(tempparent, treehead);
        }
          else if(current->getParent()->getRight() == current){// case 4 left triangle
            dNode* tempparent = current->getParent();
            dNode* tempgrandparent = current->getParent()->getParent();
            dNode* tempright = tempparent->getLeft();
            dNode* tempgreatgrandparent = tempgrandparent->getParent();

            tempparent->setLeft(tempgrandparent);
            tempgrandparent->setParent(tempparent);


            tempgrandparent->setRight(tempright);
            if(tempright != NULL){
              tempright->setParent(tempgrandparent);
            }
            tempparent->setred(false);
            tempgrandparent->setred(true);

          tempparent->setParent(tempgreatgrandparent);

          if(tempgreatgrandparent != NULL){
            if(tempgreatgrandparent->getLeft() == tempgrandparent){
              tempgreatgrandparent->setLeft(tempparent);
            }
            else{
              tempgreatgrandparent->setRight(tempparent);
            }
        }
        else{
          treehead = tempparent;
        }
        runner(tempparent, treehead);
        }
      }
    }
  }
  else{
    if(current->getParent()->getred() == true){
      if(current->getParent()->getParent()->getLeft() == current->getParent()){//left side cases
        if(current->getParent()->getRight() == current){ //case1 left triange
          dNode* tempparent = current->getParent();
          dNode* templeft = current->getLeft();

          tempparent->getParent()->setLeft(current);
          current->setParent(tempparent->getParent());
          current->setLeft(tempparent);
          tempparent->setParent(current);

          tempparent->setRight(templeft);
          if(templeft != NULL){
            templeft->setParent(tempparent);
          }
          runner(tempparent, treehead);
        }
        else if(current->getParent()->getLeft() == current){//case2 left line No uncle WOKRS
            dNode* tempparent = current->getParent();
            dNode* tempgrandparent = current->getParent()->getParent();
            dNode* tempright = tempparent->getRight();
            dNode* tempgreatgrandparent = tempgrandparent->getParent();

            tempparent->setRight(tempgrandparent);
            tempgrandparent->setParent(tempparent);


            tempgrandparent->setLeft(tempright);
            if(tempright != NULL){
              tempright->setParent(tempgrandparent);
            }
            tempparent->setred(false);
            tempgrandparent->setred(true);

          tempparent->setParent(tempgreatgrandparent);

          if(tempgreatgrandparent != NULL){
            if(tempgreatgrandparent->getLeft() == tempgrandparent){
              tempgreatgrandparent->setLeft(tempparent);
            }
            else{
              tempgreatgrandparent->setRight(tempparent);
            }
        }
        else{
          treehead = tempparent;
        }
        runner(tempparent, treehead);
        }
      }
      else if(current->getParent()->getParent()->getRight() == current->getParent()){//right side cases
        if(current->getParent()->getLeft() == current){//case 3 right triangle
          dNode* tempparent = current->getParent();
          dNode* templeft = current->getRight();

          tempparent->getParent()->setRight(current);
          current->setParent(tempparent->getParent());
          current->setRight(tempparent);
          tempparent->setParent(current);

          tempparent->setLeft(templeft);
          if(templeft != NULL){
            templeft->setParent(tempparent);
          }
          runner(tempparent, treehead);
        }
        else if(current->getParent()->getRight() == current){// case 4 right line no UNCLE WORKS
            dNode* tempparent = current->getParent();
            dNode* tempgrandparent = current->getParent()->getParent();
            dNode* tempright = tempparent->getLeft();
            dNode* tempgreatgrandparent = tempgrandparent->getParent();

            tempparent->setLeft(tempgrandparent);
            tempgrandparent->setParent(tempparent);


            tempgrandparent->setRight(tempright);
            if(tempright != NULL){
              tempright->setParent(tempgrandparent);
            }
            tempparent->setred(false);
            tempgrandparent->setred(true);

          tempparent->setParent(tempgreatgrandparent);

          if(tempgreatgrandparent != NULL){
            if(tempgreatgrandparent->getLeft() == tempgrandparent){
              tempgreatgrandparent->setLeft(tempparent);
            }
            else{
              tempgreatgrandparent->setRight(tempparent);
            }
        }
        else{
          treehead = tempparent;
        }
        runner(tempparent, treehead);

        }
      }
    }
  }
}

dNode* uncle(dNode* current){
  dNode* grandparent = current->getParent()->getParent();
  dNode* parent = current->getParent();
  if(grandparent->getRight() == parent && grandparent->getLeft() != NULL){
    return grandparent->getLeft();
  }
  else if(grandparent->getLeft() == parent && grandparent->getRight() != NULL){
    return grandparent->getRight();
  }
  else{
    return NULL;
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
  if(tempposition->getred() == false){
    cout << tempposition->getint()<< "b" << endl;
  }
  else{
    cout << tempposition->getint()<< "r" << endl;
  }
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
 
