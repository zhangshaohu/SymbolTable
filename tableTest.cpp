#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstring>
#include "BinaryTree.h"

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
***     PROGRAM DESCRIPTION :Insert,Lookup and Traverse symbol     ***
***     table using binary search tree.                            ***
*********************************************************************/


using namespace std;

bool validLabel(string);

int main()
{
S insertSymbol;
BinaryTree tree;
ifstream tableFile;
string line,word1,word2,word3;
int space,nextSpace;
// Open the file in input mode.
tableFile.open("symbols.dat", ios::in|ios::binary);
cout<<"-----Step one: Insert valid table-------"<<endl;
cout<<"-----Open symbols.dat......-------------"<<endl<<endl;

//cout<<"Value"<<"  "<< "Label"<<"   "<<"Rflag"<<endl<<endl;
          // While the last read operation was successful, continue.
while(getline(tableFile, line)){
        //cout<<line<<endl<<endl;
         space = line.find(" ");
         // get value
		word1 = line.substr(0,space);
		//cout<<word1<<"  ";
		nextSpace = line.find(" ",space+1);
		//get label
		word2 = line.substr(space+1,nextSpace-space-1);
		space=nextSpace;
		nextSpace = line.find(" ",space+1);

		//get rflag
		word3 = line.substr(space+1,nextSpace-space-1);
		//cout<<word2<<" "<<endl;
		if(validLabel(word2)){
            insertSymbol.label=word2;
            insertSymbol.value=word1;
            insertSymbol.rflag=word3;
            //cout<<"word2 "<<word2<<endl;
		tree.insertNode(insertSymbol);}
		}


    ifstream testFile;
    cout<<"-----Step two: Lookup------"<<endl<<endl;
    // Open the file in input mode.
    testFile.open("test.dat", ios::in|ios::binary);
    string testLine;
while (getline(testFile, testLine)){
         if(tree.searchNode(testLine)){
           cout<<endl;
         }else{
         cout <<testLine<<" Not Found"<<endl;
         };
         }

         cout<<"----Step Three: Inorder traversal of the symbol table with associated fields----"<<endl;
         cout<<"Value"<<"  "<< "Label"<<"   "<<"Rflag"<<" "<<"mflag"<<endl;
		 tree.displayInOrder();
          // Close the file.
         tableFile.close();
         cout<<"-----Program ended-----"<<endl;
    return 0;
}
/*********************************************************************
***                                                                ***
*** FUNCTION: <validlabel>                                         ***
***                                                                ***
**********************************************************************
***                                                                ***
***     DESCRIPTION :<to valid the label var as letters and digits ***
***     INPUT ARGS  :<label>                                       ***
***     OUTPUT ARGS :<True/False >                                 ***
***     IN/OUT ARGS :<Na>                                          ***
***                                                                ***
*********************************************************************/

bool validLabel(string label){

    for(int i=1; i<label.length();i++){
        if(!isalnum(label[i])){
          cout<<label[i]<<"  Invalid symbol(label): Label should be letters, digits, and/or the underscore (a..z, A..Z, 0..9 ,_)!!"<<endl;
         return false;
          break;
        }
    }

if(label.length()>21){
        cout<<label<<"  Invalid symbol(label): Label should be less than 22 characters long!!"<<endl;
    return false;
}else if(!isalpha(label[0])){

cout<<label<<"  Invalid symbol(label): Label should start with letter!!"<<endl;

    return false;
}else{
return true;}

}
