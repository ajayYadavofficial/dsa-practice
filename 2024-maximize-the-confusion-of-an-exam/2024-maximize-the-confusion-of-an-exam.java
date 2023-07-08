class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        int countF = 0; int countT=0;
        int i = 0; int j = 0;
        int ans = 0;
        while(j<answerKey.length()){
            if(answerKey.charAt(j)=='F')countF++;
            else countT++;
            while (Math.min(countF,countT)>k){
                if(answerKey.charAt(i)=='F')countF--;
                else countT--;
                i++;
            }
            ans = Math.max(ans,countF+countT);
            j++;
        }
        return ans;
    }
}