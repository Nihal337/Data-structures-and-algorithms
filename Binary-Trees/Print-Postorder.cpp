




      void PrintPostorder(Node* root)            { // Postorder : Left subtree, Right subtree, Root node

    if(root==NULL) {
        return ;
    }
        
        
 
    // First Print the Left subtree recursively
    PrintPostorder(root->left) ;

    //then Print the Right subtree recursively
    PrintPostorder(root->right) ;

    // then Print the root node
    cout<<root->data<<" " ;
        
        
        

}
