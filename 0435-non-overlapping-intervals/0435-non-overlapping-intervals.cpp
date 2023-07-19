class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int cnt = 0;
        
        int i = 0, j = 1;
        
        // for(auto it : intervals){
        //     for(auto it1 : it){
        //         cout<<it1<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        while( i < j && j < intervals.size()){
            // cout<<i<< " <= i || j ==> "<<j<<endl;
            int currEnd = intervals[i][1];
            int nextStart = intervals[j][0];
            int nextEnd = intervals[j][1];
            
            // no overlapping
            if( currEnd <= nextStart ){
                i = j;
                j++;
            }
            else{
                // cout<<"overlap"<<endl;
                // there is a overlapping
                
                // check ki konsa end bada hai usse remove karo
                
                // ith wale ka endbada hai
                if( currEnd >= nextEnd ){
                    
                    i = j;
                    cnt++;
                    j++;
                    
                }else if ( currEnd < nextEnd ){
                    j++;
                    cnt++;
                }
                
            }
            
        }
        return cnt;
    }
};