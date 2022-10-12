class Solution {
public:
    
    bool isTriangle(int a,int b, int c){
        return (a < b+c && b < a+c && c<a+b) ;
    }
    
    int largestPerimeter(vector<int>& nums) {
        int a,b,c, n = nums.size();
        int maxPeri = 0;
        sort(nums.begin(), nums.end());
        for(int i = n-1; i>=2; i--){
            a = nums[i];
            b = nums[i-1];
            c = nums[i-2];
            // if(isTriangle(a,b,c)) cout<<"YES"<<endl;
            if(isTriangle(a,b,c) && a+b+c > maxPeri) {
                maxPeri = a+b+c;
            }
        }
        return maxPeri;
    }
};