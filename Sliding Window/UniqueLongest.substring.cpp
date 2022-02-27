
//   Brute Force 

string Unique_Longest_Substring() {
  
  
  string s ;
     cin>>s ;
     string ans ;
     string maxans ="";
     int n= s.size() ;
     map<char,int>mp ;
     mp[s[0]]++ ;
     
     int j ;
     
     for(int i=0 ;i<n ;) {
           ans ="" ;
     	for( j=i ;j<n ;j++) {
     		
     		mp[s[j]]++ ;
     		if(mp[s[j]]==1) {
     	      ans += s[j] ;
     	      // cout<<ans<<endl ;
     	     
     		}
     		else {
     			i=j+i ;
     			mp.clear() ;
     			break ;
     		}
     		
     		
     	}
     	 if(ans.size()>maxans.size())
     	          maxans = ans ;
     }
     
     cout<<maxans<<endl ;
  
  
  
  
  --------------------------------------------------------------------------------
    // mY apporoach 2 : using sliding window
    
    void LongestUnique_Substring(string s) {
		int n= s.size() ;
		
		  int i=0 ,j=0 ;
		  int ans_i =0 ,ans_j =0 ;
		  map<char,int>mp ;
		    int diff = 0 ;
		  
		  while(j<n-1) {
		  	
		  		//  expand the Window 
		  	mp[s[j]]++ ;
		  	j++ ;
		  	
		  	
		  	
		  	// what if curr char is already present in my window
		  	// create new Window 
		  	if(mp[s[j]] == 1) {
		  		mp.clear() ;
		  		i=j;
		  	}
		  	
		  	// update the ans at the given time
		  	   if((j-i+1)>diff) {
		  	   	ans_i = i ;
		  	   	ans_j = j ;
		  	   	diff = j-i+1 ;
		  	   
		  	   }	
		  	
		  }
		 
		
		  while(ans_i<=ans_j) {
		  	cout<<s[ans_i] ;
		  	ans_i++ ;
		  }
	}
	-----------------------------------------------------------------------------------
