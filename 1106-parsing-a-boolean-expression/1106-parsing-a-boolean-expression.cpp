class Solution {
public:
    bool parseBoolExpr(string expression) {
        char ansSofar;
        stack <char> st;
        for (auto it : expression){
            if(it == ','){
                continue;
            }
            if(it == ')'){
                // printStack(st);
                ansSofar = evaluate(st, it);
                // cout<<"ansSofar === > "<<ansSofar<<endl;
                st.push(ansSofar);
                continue;
            }
            st.push(it);
        }
        // cout<<"at last the stack is "<<endl;
        // printStack(st);
        return st.top() == 't'?true:false;
    }
    
    char evaluate(stack <char> &st, char c){
        bool isTpresent = false;
        bool isFpresent = false;
        while(!st.empty() && st.top() != '('){
            char curr = st.top();
            if(curr == 't'){
                isTpresent = true;
            }
            else if (curr == 'f'){
                isFpresent = true;
            }
            st.pop();
        }
        st.pop();
        // cout<<"isTpresent === > "<<isTpresent << "isFpresent == >"<<isFpresent<<endl;
        char ans;
        
        if (st.top() == '&') {
            // do and
            if(!isFpresent && isTpresent ){
                ans = 't';
            }else ans = 'f';
        }
        else if (st.top() == '|'){
            // do or
            if (isFpresent && !isTpresent){
                ans = 'f';
            }else ans = 't';
        }
        else if (st.top() == '!'){
            // do not
            if (isTpresent){
                ans = 'f';
            } else if(isFpresent){
                ans = 't';
            }
        }
        st.pop();
        return ans;
    }
    
    void printStack (stack <char> st){
         while (!st.empty()){
            cout<<st.top()<<"  ";
            st.pop();
        }
        cout<<endl;
    }
};