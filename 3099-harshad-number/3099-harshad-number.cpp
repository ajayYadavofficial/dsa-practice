class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        string s = to_string(x);
        int sum = 0;
        for(auto it : s){
            // cout<<it<<" <- this is it"<<endl;
            sum += it - '0';
        }
        // cout<<sum<<endl;
        return (x%sum == 0) ? sum:-1;
    }
};