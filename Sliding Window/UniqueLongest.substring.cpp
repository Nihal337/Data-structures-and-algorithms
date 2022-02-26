
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
