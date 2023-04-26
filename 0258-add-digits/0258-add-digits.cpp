class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        if((int)log10(num) + 1 == 1) return num;
        // cout<<log10(num)+1<<endl;
        int sum = 0;
        while( num !=0){
            int digi = num % 10;
            sum += digi;
            num = num/10;
        }
        return addDigits(sum);
        // return sum;
    }
};