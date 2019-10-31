#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int cost;
  vector<Node *> children;
  Node *parent;
};

int getCheapestCost( Node *rootNode )
{
   // your code goes here
  if ((rootNode->children).size() == 0) {
    return rootNode->cost;
  }
  
  int minCost = INT_MAX;
  
  for (Node* np : rootNode->children) {
    int currCost = rootNode->cost + getCheapestCost(np);
    if (currCost < minCost) minCost = currCost;
  }
  
  return minCost;
}

int main() {
  Node* n1 = new Node();
  Node* n21 = new Node();
  Node* n22 = new Node(); 
  Node* n23 = new Node(); 
  Node* n31 = new Node(); 
  Node* n32 = new Node(); 
  Node* n33 = new Node(); 
  Node* n34 = new Node(); 
  Node* n35 = new Node(); 
  Node* n41 = new Node(); 
  Node* n42 = new Node(); 
  Node* n51 = new Node();;
  n1->cost = 0;
  n21->cost = 5;
  n22->cost = 3;
  n23->cost = 6;
  n31->cost = 4;
  n32->cost = 2;
  n33->cost = 0;
  n34->cost = 1;
  n35->cost = 5;
  n41->cost = 1;
  n42->cost = 10;
  n51->cost = 1;
  (n1->children).push_back(n21); (n1->children).push_back(n22); (n1->children).push_back(n23);
  (n21->children).push_back(n31);
  (n22->children).push_back(n32); (n22->children).push_back(n33);
  (n23->children).push_back(n34); (n23->children).push_back(n35);
  (n32->children).push_back(n41);
  (n33->children).push_back(n42);
  (n41->children).push_back(n51);
  
  cout << (getCheapestCost(n1)) << endl;
  
  return 0;
}