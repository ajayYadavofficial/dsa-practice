class Solution {
public:
	vector<int>v;
    bool equalFrequency(string word) 
    {   
        //getting the mapping of all the char of the string's
        v.resize(26,0);
	    for(int i=0;i<word.length();i++)
		{
		    v[word[i] - 'a']++;	
        }
        //checking for the the every possible char if the removeal of that can meke freq equal
        for(int i=0;i<word.length();i++)
		{	
	        v[word[i] - 'a']--;
		    if(fun()  ==  true)
			{
 		         return true;
			}	
			v[word[i] - 'a']++;
		}        
		return false;
    }
    bool fun()
    {
    	//checking if all the alive freq are equal or not
  	    set<int>st;
    	for(int i=0;i<26;i++)
    	{
    		if(v[i] == 0)
    		continue;
    		
    		if(v[i] > 0)
    		st.insert(v[i]);
    		
    		if(st.size() > 1)
    		return false;
    		
		}
		return true;
	}
};