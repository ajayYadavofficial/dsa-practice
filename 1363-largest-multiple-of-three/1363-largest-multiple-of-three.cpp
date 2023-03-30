class Solution {
public:
    
//     // int sumSofar = 0;
//     // unordered_map<string,bool> mp;
    
//     string f(int ind, vector<int>& digits, int sum){
//         int n = digits.size();
//         if(ind == n-1) {
//             sum += digits[ind];
            
//             if( sum  %3 == 0) {return to_string(digits[ind]);}
//             // else
//             return "";
//         }
        
//         string np =  f(ind+1, digits, sum);  
//         string p = "";
//         if( sum + digits[ind] % 3 >= 0)
//          p += to_string(digits[ind]) + f(ind+1, digits, sum + digits[ind]);
//         cout<<"p= "<<p<<" np= "<<np<<endl;
//         return max(np,p);
//     }
    
//     string largestMultipleOfThree(vector<int>& digits) {
//         sort(digits.begin(), digits.end(), greater<int>());
//         return f(0,digits, 0);
//         // return "";
//     }
   string largestMultipleOfThree(vector<int>& digits) {
       int n = digits.size();
       string  res="";
       int m1[] = {1, 4, 7, 2, 5, 8}, m2[] = {2, 5, 8, 1, 4, 7};
          int sum = 0, ds[10] = {};  
          for (auto d : digits) {
              ++ds[d];
              sum += d;
          }
          while (sum % 3 != 0) {
            for (auto i : sum % 3 == 1 ? m1 : m2) {
              if (ds[i]) {
                --ds[i];
                sum -= i;
                break;
              }
            }
          }
          for (int i = 9; i >= 0; --i)
            res += string(ds[i], '0' + i);
       
          return res.size() && res[0] == '0' ? "0" : res;
        
        
    }
    
};