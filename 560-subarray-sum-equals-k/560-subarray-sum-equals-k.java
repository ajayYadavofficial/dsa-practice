class Solution {
    public int subarraySum(int[] nums, int k) {
        int ans = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int sum =0;
        for(int i=0; i<nums.length; i++){
            sum += nums[i];
            int rsum = sum - k; // remaining sum i.e. sum till current - k if it is occured before then store in //ans
            if(map.containsKey(rsum)){
                ans += map.get(rsum);
            }
            
//             increase the value of the sum in the map if it is present if not put 1
//             direct way of doing it
            map.put(sum, map.getOrDefault(sum,0) + 1);
        }
        return ans;
    }
}