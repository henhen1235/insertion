/*
Henry Xu
C++
11/13/24
dNode.h
*/
#ifndef DNODE_H
#define DNODE_H
#include <iostream>

using namespace std;

class dNode{
 public:
  dNode(int nstudent);//create a node with a char in it
  ~dNode();//destuctor
  int getint();//getting the char
  void setint(int nchar);//setting the char
  void setRight(dNode* newnode);//setting the right node
  void setLeft(dNode* newnode);//setting the left node
  dNode* getRight();//getting the right node
  dNode* getLeft();//getting the left node
  void setParent(dNode* newnode);//setting the left node
  dNode* getParent();//getting the right node
 private:
  int stored;//student pointer
  dNode* rightnode;//left pointer
  dNode* leftnode;//right node pointer
  dNode* parentnode;
};
#endif