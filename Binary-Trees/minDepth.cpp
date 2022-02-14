





           int minDepth(Node *root) {
     	
             //base case
        if(root->left==NULL && root->right==NULL) return 1 ;
        
        
             // rec case
        int d1=INT_MAX,d2=INT_MAX ;
        
        if(root->left)
         d1 = minDepth(root->left) ;
        
        if(root->right)
        int d2 = minDepth(root->right) ;
        
             // self work
        return 1+min(d1,d2) ;
        
}
     
