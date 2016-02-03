#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstdlib>
#include <string>


using namespace std;
/*********************************************************************
***                                                                ***
***     NAME     :  Shaohu Zhang                                   ***
***     ASSIGN # :  1                                              ***
***     DUE DATE :  9/14/2015                                      ***
***     CLASS    :  CSc 354                                        ***
***                                                                ***
***                                                                ***
**********************************************************************
***                                                                ***
***     PROGRAM DESCRIPTION : Binary search tree header file       ***
***                                                                ***
*********************************************************************/


//Table data structure
struct S{
string label;
string value;
string rflag;
int iflag;
bool mflag=false;

};

class BinaryTree
{
    public:
        BinaryTree(){
            root= NULL;

        };
        ~BinaryTree(){};
    //void insertNode(string);
    //bool searchNode(string);
    void insertNode(S);
    bool searchNode(string);
    void displayInOrder() const{
    displayInOrder(root);
    };

    private:

        struct TreeNode{
       // string symbolLabel;
        S symbolTable;
        TreeNode *left;
        TreeNode *right;
        };
        TreeNode *root;
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void displayInOrder(TreeNode *) const;
};

#endif // BINARYTREE_H

