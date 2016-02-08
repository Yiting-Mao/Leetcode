class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int base=1,temp=x;
        temp/=10;
        while(temp){
            base*=10;
            temp/=10;
        }
        while(x&&base>1){
            if(x/base!=x%10)return false;
            x=(x-x/base*base)/10;
            base/=100;
        }
        return true;
    }
};
