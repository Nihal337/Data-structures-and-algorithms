



 // we will make a ds to store data which we can see from top 
    // by picturing the question , we can see if we traverse through the tree and store the 
    // 1st element of each column then that will be our answer.
    
    // we will make col as key bcz  in each col we want only one val , we dont want to print 
    // another val from the same column thats why we used map<col,node*> as ds as we want only the 
    // 1st val of each col .

 vector<int> topView(Node *root) { 
        
    vector<int>ans  ;
    
    if(root==NULL) return ans ;
    
    // ds as per our need we wanted our values as per col in ascending 
    map<int,Node*>mp ;
    queue<pair<Node*,int>>q ;
    q.push({root,0}) ;
    
    while(!q.empty()) {
    	
    	auto  p = q.front() ;
    	Node* node = p.first ;
    	int x = p.second ;
    	q.pop() ;
    	
    	mp.insert({p.second,p.first}) ;
    	
    	// if left child exists
    	if(node->left)
    	q.push({node->left,x-1}) ;
    	
    	if(node->right) 
    	q.push({node->right,x+1}) ;
    }
    for(auto x : mp) {
    	ans.push_back(x.second->data) ;
    	
    }
    return ans ;
    
    }
