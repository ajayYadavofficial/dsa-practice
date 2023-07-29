// class Solution {
// public:
    
    
    
//     double soupServings(int n) {
//         if(n == 0) return 0.5;
//         int A = n, B = n;
        
//         // BFS
//         double resProb = 0.0;
        
//         queue<pair<double, pair<int,int>>> q;
        
//         // {probablity_so_far , { A_quantity, B_quantity }}
        
//         q.push({1.0,{n,n}});
        
//         while(!q.empty()){
//             auto it = q.front();
//             double prob = it.first;
//             int A = it.second.first;
//             int B = it.second.second;
//             q.pop();
//             // loop through all ways
            
//             for(int i=0; i<=100; i += 25){
//                 int serve_A = 100 - i;
//                 int serve_B = i;
                
//                 int nA = A - serve_A;
//                 int nB = B - serve_B;
                
//                 if(nA <= 0 && nB > 0){
//                     // A empty first
//                     // we do not push after wards
//                     resProb += 0.25*prob;
//                     cout<<"A zero only = "<<0.25*prob<<endl;
//                     continue;
//                 }
//                 else if( (A > 0 && B > 0) && (nA <= 0 && nB <= 0)){
//                     // A and B empty at same Time
//                     // we do not push after wards
//                     resProb += 0.25*prob*0.5;
//                     cout<<"A & B zero = "<<0.25*prob*0.5<<endl;
//                     continue;
//                 }
//                 else if(nB <= 0){
//                     // B alone empty First we dont do anything continue
//                     continue;
//                 }
                
//                 q.push({ 0.25*prob , {nA, nB}});
                
//             }
            
            
//         }
        
//         return resProb;
        
//     }
// };


class Solution {
public:
    double soupServings(int N) {
        if (N > 4800) {
            return 1.0;
        }
        N = (N + 24) / 25;
        std::unordered_map<int, double> memo;

        return dp(N, N, memo);
    }

private:
    double dp(int a, int b, std::unordered_map<int, double>& memo) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1.0;
        }
        if (b <= 0) {
            return 0.0;
        }
        int key = a * 5000 + b;
        if (memo.count(key)) {
            return memo[key];
        }
        memo[key] = 0.25 * (dp(a-4, b, memo) + dp(a-3, b-1, memo) + dp(a-2, b-2, memo) + dp(a-1, b-3, memo));
        return memo[key];
    }
};