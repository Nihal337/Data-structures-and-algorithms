#include <bits/stdc++.h>
#include "Trie.h"

// ctrl+B
using namespace std ;




 int main() {

     vector<string>arr = {"apple","hello","man","cake"} ;

     Trie t ;

     for(auto x : arr) t.insert(x) ;

      string s = "cke" ;
      cout<<t.search(s)<<endl ;
 }
