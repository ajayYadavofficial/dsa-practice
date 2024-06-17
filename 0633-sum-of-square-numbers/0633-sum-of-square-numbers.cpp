// class Solution {
// public:
    
//     bool solve(int ind, int c, int cnt){
//         cout<<ind<<" "<<c<<" "<<cnt<<endl;
//          if(c == 0){
//             if (cnt == 2)return true;
//             return false;
//         }
//         if(ind*ind > c){
//             return false;
//         }
       
        
//         bool pick;
//         if(ind*ind <= c){
//             pick = solve(ind+1, c-(ind*ind), cnt+1);
//         }
        
//         bool notPick = solve(ind+1, c, cnt);
        
//         return pick || notPick;
        
//     }
    
//     bool judgeSquareSum(int c) {
        
//         return solve(1,c,0);
        
//     }
// };


class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c >=0 && c <=2) return 1;
        map<long long ,bool> mp;
        for(long long i = 1; i*i <= c; i++){
            if((mp.find(c- (i*i)) != mp.end()) || i*i == c || 2*i*i == c){
                return true;
            }
             mp.insert({i*i, true });
        }
        return false;
    }
};

