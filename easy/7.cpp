//directly reverse
class Solution {
public:
    int reverse(int x) {
        long result=0;
        int flag=(x<0)?1:0;
        int max=0;
        max=~max;
        max=(unsigned int)max>>1;
        if(x==-max-1) return 0;
        x=abs(x);
        while(x&&x%10==0)x=x/10;
        while(x){
            result=result*10+x%10;
            x=x/10;
        }
        if(result>max)return 0;
        else if(flag)result=-result;
        return result;
    }
};

//using string reverse, performance beats 6.91%
class Solution {
public:
    int reverse(int x) {
        int flag=(x<0)?1:0;
        int max=0;
        max=~max;
        max=(unsigned int)max>>1;
        string str;
        if(x==-max-1) return 0;
        else{
            string maxString=to_string(max);
            x=abs(x);
            str=to_string(x);
            int pos=str.length()-1;
            while(str[pos]==0)pos--;
            str=str.substr(0,pos+1);
            std::reverse(str.begin(), str.end());
            if(str.length()==maxString.length()&&str.compare(maxString)>0)return 0;
        }

        int result=std::stoi(str,nullptr);
        if(flag)result=0-result;
        return result;
    }
};
