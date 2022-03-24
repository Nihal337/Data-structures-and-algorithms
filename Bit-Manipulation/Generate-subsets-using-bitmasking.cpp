

  void printsubset(string &s,int no) {
  	
  	int i=0;
  	while(no>0) {
  		
  	(no&1)?cout<<s[i]:cout<<"" ;
  	i++ ;
  	no = no>>1 ;	// each bit of no shift right by 1
  	}
  	cout<<endl ;
  	
  	
  }
  
  
  
  void  subsets() {
  	string s ;
  	cin>>s ;
  	int n = s.size()  ;
  	// tot subsets = 2^n i.e from 0 to 2^n-1
  	int range =(1<<n) - 1 ;
  	// generate all numbers from 0 to 2^n-1
  	// for each no , print the corresponding char(from start) whenever
  	// met the corresponding set bit 
  	
  	for(int i=0  ;i<=range ; i++) {
  		printsubset(s,i) ;
  		
  		
  	}
  }
