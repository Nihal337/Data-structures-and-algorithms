/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
// method1 : using min heap 
// method2 : using sorting and Two pointers 
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        vector<int>start,ends ;
        for(auto interval : intervals) {
            start.push_back(interval.start) ;
            ends.push_back(interval.end) ; 
        }
         sort(begin(start),end(start)) ;// current starting time 
         sort(begin(ends),end(ends)) ;  // earliest ending time 
      
         int n = start.size() , m = ends.size() ;
         int rooms = 0 ;
         int ans = 0 ;

         int i = 0 , j = 0 ; // i pointing to current start time of a meeting , j is pointing to earliest ending time of a meeting visited so far , 
         while(i<n) {
            if(start[i] < ends[j]) { // if(current start time <  previous earliest ending time)
                rooms++ ;
            } else {
                j++ ;
            }
            i++ ;
         }
         return rooms ;
          
    }
};
