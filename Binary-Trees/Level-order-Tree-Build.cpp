              

// Build Tree in Level Order

      Node* Buiild_Level_orderTree() {
     	 
     	 int d ;
     	 cin>>d ;
     	 queue<Node*>q ;
     	 
    // First Create Root Node
    Node*root = new Node(d)  ;
    
    // push root to the queue
    q.push(root) ;
    
    // Then For all the other nodes,
    // read two data from the input ,the first data will be the left child of current node
    // and second data will be the right child of currrent data
    
     while(!q.empty()) {
     	
     	//Current Node
     	Node* Current = q.front() ;
     	q.pop() ;
     	
     	//read two data from input
     	int c1,c2  ;// child1,child2
     	cin>>c1>>c2 ;
     	
     	if(c1 != -1) {
     		// will be left child of current node
     		current->left = new Node(c1) ;
     		q.push(current->left) ;
     	}
     	if(c2 != -1) {
     		// will be right child of current node 
     		current->right = new Node(c2) ;
     		q.push(current->right) ;
     	}
     }
     return root ;
     }



 
