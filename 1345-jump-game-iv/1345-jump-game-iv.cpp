class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) 
            return 0;
        
        //After doing below three statements our unordered_map looks like this
        //it will store value and vector<int> will store indices of that value    
            //-23: [1, 2],
            //3: [8],
            //23: [5, 6, 7],
            //100: [0, 4],
            //404: [3, 9] 

        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; i++) {
            indices[arr[i]].push_back(i);
        }
        //queue will store index of adjacent element
        queue<int> storeIndex;
        //visited will take care wheather the particular index is visited or not
        vector<bool> visited(n);
        storeIndex.push(0);
        visited[0] = true;
        int steps = 0;
        while (!storeIndex.empty()) {
            int size = storeIndex.size();
            while (size--) {
                int currIndex = storeIndex.front();
                storeIndex.pop();
                //if currIndex == lastIndex of the array, it means we got the answer and we return the number of steps required to reach at the last index
                if (currIndex == n - 1) 
                    return steps;
                //below statement will store vector<int> from unordered_map, it means our it will take care of arr[i] == arr[j] && i != j condition
                vector<int>& jumpNextIndices = indices[arr[currIndex]];
                //below two statement take care of wheather next jump be i + 1 or i - 1
                jumpNextIndices.push_back(currIndex - 1);
                jumpNextIndices.push_back(currIndex + 1);
                for (int jumpNextIndex : jumpNextIndices) {
                    if (jumpNextIndex >= 0 && jumpNextIndex < n && !visited[jumpNextIndex]) {
                        storeIndex.push(jumpNextIndex);
                        visited[jumpNextIndex] = true;
                    }
                }
                //In the given code, jumpNextIndices is used to store the indices of the same value as the current index, and also the indices to which we can jump from the current index (i.e. currIndex + 1 and currIndex - 1).
                //If we do not clear jumpNextIndices at the end of each iteration of the while loop, it will keep storing the indices for the same value and also the indices to which we can jump from the previous iterations as well, leading to incorrect results or time limit exceeded.
                //So, including the statement jumpNextIndices.clear(); at the end of each iteration of the while loop is important to make sure that the jumpNextIndices vector only contains the valid indices for the current iteration.
                jumpNextIndices.clear();
            }
            steps++;
        }
        return -1; // unreachable
    }
};