// class Solution {
// public:
//     int findValidSplit(vector<int>& nums) {
//         int prefixProd = 1;
//         int n = nums.size();
//         for(int i=0; i<n;i++){
//             prefixProd *= nums[i];
//         }
//         int currProd=1;
//         for(int i = 0; i<n;i++){
//             currProd *= nums[i];
//             prefixProd /= nums[i];
//            int g = __gcd(currProd,prefixProd);
//             cout<<"currProd = "<<currProd<<" prefixProd = "<<prefixProd<<endl;
//             if( g == 1 && i != n-1) return i;
//         }
//         return -1;
//     }
// };
class Solution {
public:

    set<int> primefactors(int n){
        set<int> mp;
        for(int i = 2; i * i <= n; i++){
            while(n % i == 0) {
                mp.insert(i);
                n /= i;
            }
        }
        if( n > 1 ) mp.insert(n);
        return mp;
    }
    
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        
        // storing prime factors for every index
        vector<set<int>> vec;
        for(int i = 0; i < n; i++){
            auto temp = primefactors(nums[i]);
            vec.push_back(temp);
            
        }

        // mapping last occurence of all prime factors
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            for(auto &j: vec[i]){
                mp[j] = i;
            }
        }
        
        // return index where last index for each prime factor <= index
        int longend = 1;
        for(int i = 0; i < n - 1; i++){
            for(auto &j: vec[i]){
                longend = max(longend, mp[j]);
                if(i == longend){
                    return i;
                }
            }
        }
        
        return -1;
        
    }
};