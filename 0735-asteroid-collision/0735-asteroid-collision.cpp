// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         vector<int> ans;
//         int n = asteroids.size() ;
//         int i = 0, j = 1;
//         // jo destroy ho jayega usse zero se replace krdo
//         while(i<j && j< n){
//             cout<<i<<" <== i j==> "<<j<<endl;
            
//             //4 cases 
//             //a. both adjacent asteroid in same direction
            
//             // direction 1 means moving right, -1 means moving left
//                 int d1 = ( asteroids[i] > 0 )?1:-1; // direction for ith
//                 int d2 = -1*d1; // direction for jth
            
//             if( asteroids[i]*asteroids[j] < 0 && d1 == 1 && d2 == -1 ){
//                 // this means both collide
//                 if( abs(asteroids[i]) > abs(asteroids[j]) ){
//                     //b. Right collide 
//                     asteroids[j] = 0;
//                     j++;

//                 }else if( abs(asteroids[i]) < abs(asteroids[j])){
//                     //c. Left collide
//                     asteroids[i] = 0;
//                     // move i forward until next non zero occurs if there is no asteroid in left 
                    
//                     if( i-1 >= 0 && asteroids[i-1] != 0 ){
//                         i--;
//                     } else{
//                         j++;
//                         while(asteroids[i] == 0) i++;
//                     }
                    
                    
//                 }else{
//                     //d. both collide
//                     asteroids[i] = 0;
//                     asteroids[j] = 0;
//                     j++;
                    
//                     if( i-1 >= 0 && asteroids[i-1] != 0 ){
//                         i--;
//                     } else{
//                         cout<<"ahbac  "<<asteroids[i]<<endl;
//                         j++;
//                         while(asteroids[i] == 0) i++;
//                     }
//                 }   
//             }
            
//             else{
//                 // no collision
//                 i++;
//                 j++;
//             }
             
            
//         }
        
//         for(auto it : asteroids){
//             if(it != 0) ans.push_back(it);
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> stack{};

        for (const int ast : asteroids)
        {
            bool check_stack = true;
            while (check_stack)
            {
                if (stack.size() == 0)
                {
                    stack.emplace_back(ast);
                    check_stack = false;
                    continue;
                }
                bool collision = stack.back() > 0 && ast < 0; 
                if (collision)
                {
                    if (abs(ast) == abs(stack.back()))
                    {
                        stack.pop_back();
                        check_stack = false;
                    }
                    else if (abs(ast) > abs(stack.back()))
                    {
                        stack.pop_back();
                    }
                    else if (abs(ast) < abs(stack.back()))
                    {
                        check_stack = false;
                    }
                }
                else
                {
                    stack.emplace_back(ast);
                    check_stack = false;
                }
            }
        }
        return vector<int>(stack.begin(), stack.end());
    }
};