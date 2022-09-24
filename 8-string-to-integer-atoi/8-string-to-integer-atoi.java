class Solution {
    public int myAtoi(String s) {
        
        long n = 0;
        boolean nInitialized = false;
        boolean sgnFound = false;
        int neg = 1;
        s = s.trim();
        for(int i = 0; i < s.length();i++)
        {
            char ch = s.charAt(i);
            if(ch < 58 && ch > 47)
            {
               if(!nInitialized)
                 nInitialized = true;
               
                n = n*10 + (ch - 48);
                
               if(n*neg > Integer.MAX_VALUE)
                   return Integer.MAX_VALUE;
                if(n*neg < Integer.MIN_VALUE)
                    return Integer.MIN_VALUE;
                   
            }
            else if(!nInitialized && ch == 45 && !sgnFound)
            {
                neg = -1;
                sgnFound = true;
            }
            else if(!nInitialized && ch == 43 && !sgnFound)
            {
                neg = 1;
                sgnFound = true;
            }
            else break;
        }
        return (int)n*neg;
        
    }
}