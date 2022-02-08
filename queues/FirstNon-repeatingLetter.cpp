vector<char> firstnonrepeating(vector<char>& str){
	
	  vector<char>ans  ;
	  queue<char>q ;
	//q contains options that may or may not be first non repeating letter.
	
	//maintain a freq array to check whether the queue contains valid ans or not
	int freq[27] = {0} ;
	
	//Go through each index of str to find out ans of each idx.
	for(auto ch :str) {
		
		 q.push(ch) ;
		freq[ch-'a']++ ;
		
		//Go through the queue to find out & print valid ans of my current index.
		
		while(!q.empty()) {
			
			int idx = ch -'a' ;
			
			//check If q.front() a valid answer or not
			// here answer= first non repeating letter
			
		//if not a valid answer remove it from my options.
		if(freq[idx]>1) { // not a valid answer
			q.pop() ;
		}
		
		//if got ans print it
		else { // valid answer
           ans.push_back(q.front()) ;
           break ;			
		}
				
	}
	//gone through queue but not found my answer
	if(q.empty()) { //not found valid answer
		
		ans.push_back('0') ;
	}
		
	}
	return ans ;
	
    
}
