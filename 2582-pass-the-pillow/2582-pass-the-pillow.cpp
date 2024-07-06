class Solution {
public:
    int passThePillow(int n, int time) {
        int mod = time/(n-1);
        int st = 1;
        // cout<<mod<<" mod"<<endl;
        if( mod %2 != 0) st = n;
        // cout<<st<<" st"<<endl;
        int remPass = time - ((n-1)*mod);
        // cout<<remPass<<" remPass"<<endl;
        int ans = 0;
        if(st == 1) ans = st + remPass;
        else if(st == n) ans = st - remPass;
        return ans;
    }
};