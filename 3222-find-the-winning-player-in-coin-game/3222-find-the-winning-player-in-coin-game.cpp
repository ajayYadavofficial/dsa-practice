class Solution {
public:
    string f(int x, int y, string curr){
        if(x <= 0 || y <= 3){
            return curr;
        }
        if(curr == "Alice") return f(x - 1, y - 4, "Bob");
        return f(x - 1, y - 4, "Alice");
    }
    string losingPlayer(int x, int y) {
        return f(x, y, "Bob");
    }
};