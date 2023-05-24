class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<ll,ll>>v;
        ll n=(long)nums1.size();
        for(ll i=0;i<n;i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end());
         priority_queue<ll, vector<ll>, greater<ll> > pq;
        ll sum=0;
        for(ll i=n-1;i>=n-k+1;i--){
            pq.push(v[i].second);
            sum+=v[i].second;
        }
        ll ans=-1;
        for(ll i=n-k;i>=0;i--){
            ll cu_sum=v[i].second+sum;
            //cout << cu_sum <<  " " <<  i <<  " " << v[i].second << endl;
            ans=max(ans,v[i].first*(cu_sum));
            //cout << pq.top() << " " << sum << endl;
            if(k>1 && v[i].second>pq.top()){
                
                sum-=pq.top();
                pq.pop();
                sum+=v[i].second;
                pq.push(v[i].second);
            }
            //cout << pq.top() <<  " " << sum << endl;
        }
        //cout << ans << endl;
        return ans;
    }
};