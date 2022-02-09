


// i will the print the root node 
// then print the left subtree 
// then print the right subtree


 void PreoderPrint(Node* root) {      // root = address of the tree which you are printing
  
  //base case
  if(root==NULL) {
    return  ;
  }
  
  //print root node
  cout<<root->data<<" " ;
  
  //print the left subtree 
  PreorderPrint(root->left) ;
  
  //print the right subtree
  PreorderPrint(root->right) ;
   
   
 }
  
