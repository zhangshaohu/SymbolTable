#include "BinaryTree.h"
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

/*********************************************************************
***                                                                ***
***     NAME     :  Shaohu Zhang                                   ***
***     ASSIGN # :  1                                              ***
***     DUE DATE :  9/14/2015                                      ***
***     CLASS    :  CSc 354                                        ***
***     INSTR    :  Dr.HAMER                                       ***
***                                                                ***
**********************************************************************
***                                                                ***
***     PROGRAM DESCRIPTION : Binary search tree cpp file          ***
***                                                                ***
*********************************************************************/

/*********************************************************************
***                                                                ***
*** FUNCTION: <insert>                                             ***
***                                                                ***
**********************************************************************
***                                                                ***
***     DESCRIPTION :<Insert node into the tree pointed to by      ***
***                  the treeNode pointer>                         ***
***     INPUT ARGS  :<nodePtr; newNode>                            ***
***     OUTPUT ARGS :<True/False >                                 ***
***     IN/OUT ARGS :<Na>                                          ***
***                                                                ***
*********************************************************************/


void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == NULL)
      nodePtr = newNode;                  // Insert the node.
   else if ((newNode->symbolTable.label) < (nodePtr->symbolTable.label))
      insert(nodePtr->left, newNode);     // Search the left branch
   else
      insert(nodePtr->right, newNode);    // Search the right branch
}

/*********************************************************************
***                                                                ***
*** FUNCTION: <insertNode>                                         ***
***                                                                ***
**********************************************************************
***                                                                ***
***     DESCRIPTION :<Create a new node to hold  newSymbol>        ***
***                                                                ***
***     INPUT ARGS  :<newSymbol>                                   ***
***     OUTPUT ARGS :<Na >                                         ***
***     IN/OUT ARGS :<Na>                                          ***
***                                                                ***
*********************************************************************/

void BinaryTree::insertNode(S newSymbol)
{
   TreeNode *newNode =NULL;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->symbolTable = newSymbol;
   newNode->left = newNode->right =NULL;

   // Insert the node.
   insert(root, newNode);
}

/*********************************************************************
***                                                                ***
*** FUNCTION: <searchNode>                                         ***
***                                                                ***
**********************************************************************
***                                                                ***
***     DESCRIPTION :<search a label in tree node>                 ***
***                                                                ***
***     INPUT ARGS  :<label>                                       ***
***     OUTPUT ARGS :<true/false >                                 ***
***     IN/OUT ARGS :<Na>                                          ***
***                                                                ***
*********************************************************************/


bool BinaryTree::searchNode(string label)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      string str = nodePtr->symbolTable.label;

      if (str.substr(0,6) == label.substr(0,6)){
       // cout<<label.substr(0,6) <<" compared with " <<str.substr(0,6)<<endl;
       cout<<label<<" found in the table: "<<nodePtr->symbolTable.value<<" "<<str<<" "<<nodePtr->symbolTable.rflag<<endl;
         return true;}
      else if (label < str)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

/*********************************************************************
***                                                                ***
*** FUNCTION: <dispalyInOrder>                                     ***
***                                                                ***
**********************************************************************
***                                                                ***
***     DESCRIPTION :<dispaly tree node in order by the label>     ***
***                                                                ***
***     INPUT ARGS  :<nodePtr>                                     ***
***     OUTPUT ARGS :<print out the variables of nodePtr >         ***
***     IN/OUT ARGS :<Na>                                          ***
***                                                                ***
*********************************************************************/

void BinaryTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->symbolTable.value <<" "<<nodePtr->symbolTable.label<<" "<<nodePtr->symbolTable.rflag<<" "<<nodePtr->symbolTable.mflag<<endl;
      displayInOrder(nodePtr->right);
   }
}
