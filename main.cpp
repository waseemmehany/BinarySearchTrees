// Sample driver
// EE 312 Fall 2018
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for 
// output.
//

#include <iostream>
#include <fstream>
#include "BST312.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("test.txt");

    BST_312<string> bst;
   
    string s;
    inFile >> s;
    while (inFile) {;
        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }

//    int count = bst.countNodes();
    cout << "Count: " << bst.countNodes() << endl;


    // PRE: f a c b d e g i h j k
    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;

    // IN: a b c d e f g h i j k
    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    // POST: b e d c a h k j i g f
    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    s = "a";
    if (bst.isItemInTree(s)) {
        cout << "'a' is in tree" << endl;
    } else {
        cout << "'a' is NOT in tree" << endl;
    }


    cout << "Remove items " << endl;
    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    s = "a";
    bst.deleteItem(s);
    print(bst.postOrderTraversal());
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;


    cout << "EMPTY" << endl;
    bst.makeEmpty();
    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    cout << endl;

}

