class Solution {
    public int longestValidSubstring(String word, List<String> forbidden) {
        Set<String> invalid = new HashSet<>();
        for(String currWord: forbidden){
            invalid.add(currWord);
        }

        int ans = 0;
        int currRight = word.length()-1;

        for(int left = word.length()-1;left>=0;left--){
            for(int right = left; right<=Math.min(left+10, currRight);right++){
                String curr = word.substring(left, right+1);
                if(invalid.contains(curr)){
                    currRight = right-1;
                }
            }
            ans = Math.max(ans, currRight-left+1);
        }
        return ans;
    }
}