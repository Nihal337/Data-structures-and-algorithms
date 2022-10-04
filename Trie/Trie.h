
#include<bits/stdc++.h>
using namespace std ;


// each node contains 3 things
// 1) what data it contains -> char
// 2) what are the addreses of its children -> maps
// 3) is it terminal or not -> boolean

 // first of all i need to create a node class

class Trie ;

class Node {

    char data ;
    unordered_map<char,Node*>m ;
    bool isTerminal ;

    public :

     Node(char d) {

        data = d ;
        isTerminal = false ;
     }
     friend class Trie ;
} ;


// for insertion , searching and deletion , we Need to create a trie class.
// it will have one attribute i.e a node containing a null character

// There will be 3 Methods : Insertion , Searching , Deletion

// Remember for moving in trie , we need a pointer , just like for linked list.(sometimes people forget thats why told)

 Insertion :

// In Trie we will insert each char of the string .
// for each char , we will check whether that char is already present or not
// if not , then we will create node of that  character and will map it to my curr node using hashmap
// if yes , we will simply move to this char
// as the loop end , we will mark last node as isTerminal as that is our last char of our string



 Searching :

// In Trie we will search for each char of the string
// for each char , we will ask curr node whether it contain this char or not
// if not, we will simply return false
// if yes, then we will move my curr node to that char
// as my loops ends , My curr node will be last char node , right
// so well check whether my curr node is Terminal or not
// if yes , return true else false



class Trie {

    Node* root ;

    public :

    Trie() {
        root = new Node('\0') ;
    }

    // Insertion
    void insert(string word) {

        Node* temp = root ;

        for(char ch : word)
        {

            // not present
            if(!temp ->m.count(ch))
            {
                Node* n = new Node(ch) ;
                temp->m[ch] = n ;
            }
            temp = temp->m[ch] ;
        }

       temp->isTerminal = true ;
    }

    // searching
    bool search(string word) {

         Node* temp  = root ;

         for(char ch : word) {

            if(!temp->m.count(ch)) {
                 return false ;
            }
            temp = temp->m[ch] ;
         }

         return temp->isTerminal ;

    }





} ;
