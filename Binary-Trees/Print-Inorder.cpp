

// Print inorder 
                   
      void PrintInorder(Node* root) {// Inorder : left,root,right
        
        
    if(root==NULL)  {
      return ;
    }

     //First i will print the left recursively
     PrintInorder(root->left) ;

     //then print the root
     cout<<root->data<<" " ;

     //then print the right recursively
     PrintInorder(root->right) ;
        

}
