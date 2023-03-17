// class Solution {
// public:
//     long long countExcellentPairs(vector<int>& nums, int k) {
//         set<int> st;
//         vector<int> bitCount;
//         for(auto it : nums){
//             st.insert(it);
//         }
//         long long cnt= 0;
//         for(auto it : st){
//            bitCount.push_back(__builtin_popcount(it));
//         }
        
//         sort(bitCount.begin(), bitCount.end());
        
//         int n = bitCount.size();
//         for(int i=0;i<n; i++){
//             // cout<<v[i]<<" ";
//             if(bitCount[i]>=k){ 
//                 cnt+=i*2+1;
//             }
//             else{
//             int index = search(bitCount,i,k-bitCount[i]);
//             if(index!=-1) cnt= cnt+(i-index)*2+1;
//             }
//         }
        
        
        
//         return cnt;
//     }
// };



typedef long long ll;
class Solution {
public:
    long long countExcellentPairs(vector<int>& v, int k) {
        ll ans=0;
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        int n=v.size();
        vector<ll> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=__builtin_popcount(v[i]);
        }
        sort(dp.begin(),dp.end());
        for(int i=0;i<n;i++){
            ans+=n-(lower_bound(dp.begin(),dp.end(),k-dp[i])-dp.begin());
        }
        return ans;
    }
};