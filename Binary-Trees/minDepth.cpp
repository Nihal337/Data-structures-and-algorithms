





        int minDepth(TreeNode* root) {
            //base case
        if(root==NULL) return 0 ;
        if(root->left==NULL && root->right==NULL) return 1 ;
        
        
             // rec case
        int d1=100005,d2=100005 ;
        
        if(root->left)
         d1 = minDepth(root->left) ;
        
        if(root->right)
         d2 = minDepth(root->right) ;
        
             // self work
        return 1+min(d1,d2) ;
        
    }
     
