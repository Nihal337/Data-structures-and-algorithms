
// Approach : 
// 1) make a frequency array to keep count of each char.
 
//2) also keep a visited array to keep count of char present in ans string 

// 3) traverse the string , each time reduce the count of index(that char) u are in


//4) if current char is already present in ans string then skip it

// 5) use a while loop to check whether my curr char is lexicographcally 
// smaller than my char present in ans string. This is done so that
// in my string char which are lexicographically smaller are before the char which
// are larger.

//6)  if yes then remove that char from string and make it unvisited and
// put it later on

// 7) now add that char in ans string and make it visited 


// hint  : jab take mere man ka hora hai tb tk thik hai
         // jaise kuch gadbab dikha nikalo salo ko mere ans se.










class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "" ;
        // step 1)
        vector<int>freq(256,0) ;
        for(auto x:s) freq[x]++ ;
        
        // step 2) 
        vector<bool>visited(256,false)  ; // means not visited any char until now
        
        // step 3) traverse and reduce count
        for(char c : s) {
            freq[c]-- ;
            
            // step 4)
            if(visited[c]==true) continue ;
            
            // step 5)
            while(!ans.empty() && c<ans.back() and freq[ans.back()]>0) {
                cout<<freq[ans.back()]<<" "<<ans.back()<<endl ;
                // step 6 )
                visited[ans.back()] = false ; // absent in ans string
                ans.pop_back() ; // remove for now and baad me add krlena
                
                
            }
            
            // step 7 )
            // add the char
            ans += c ;
            visited[c] = true ; // made it present in ans string.
        }
       return ans ; 
    }
};
