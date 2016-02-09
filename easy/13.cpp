//start from the tail, if the letter ahead is bigger, add, else, minus
class Solution {
public:
    int romanToInt(string s) {
        std::map<char,int>roman;
        roman['I']=1;
        roman['V']=5;
        roman['X']=10;
        roman['L']=50;
        roman['C']=100;
        roman['D']=500;
        roman['M']=1000;
        int length=s.length();
        int result=roman.find(s.at(length-1))->second;
        int before,after;
        after=result;
        for(int i=length-2;i>=0;i--){
            before=roman.find(s.at(i))->second;
            if(before<after)result-=before;
            else result+=before;
            after=before;
        }
        return result;
    }
};
