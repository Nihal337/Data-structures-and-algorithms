    vector<int> stockSpanner(vector<int> &stocks){
	
	int n= stocks.size() ;
	vector<int>span(n,0) ;
	
	
	 stack<int>s  ; 
	                                                             // stack consist of stock prices of previous days.
  	                                                             //day1 price will always have span 1
  	 s.push(0) ;
  	 span[0] = 1 ;
  	 
  	                                                            //i will go to each day to find out span of stock of that day 
  	 for(int i=1 ;i<n ;i++) {
  	 	
  	 	int prev_price = stocks[s.top()] ;
  	 	 int current_price = stocks[i] ;
  	                                                           	//pop out those previous prices which are less than current price
  	                                                          	// as they are no use to find span hence
  	 	
  	 	while(!s.empty() && prev_price<=current_price ) {
  	 		s.pop() ;
  	 	}
  	 	
  	 	
  	 	if(!s.empty()) {
  	                                                                  //here my top of stack will consist of that stock price whose val is greater
  	                                                                  //than currrent stock price.
  	int prev_max_index = s.top() ;
  	int current_index = i ;
  	
  	span[i] = current_index - prev_max_index ;		
  	 	}
  	 	
  		else {
  			
  	 		span[i] = i+1 ;
  	 	}
  	 	
  	 	s.push(i) ;
  	 	
  	 }
  	 return span ;

	
}
