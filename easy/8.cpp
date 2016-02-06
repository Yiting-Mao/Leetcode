//stop when result overflows
  int myAtoi(string str) {
    if (str.empty()) return 0;
    int i = 0, sign = 1;
    while (i + 1 < str.size() && isspace(str[i])) ++i;
    long res = 0;
    if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
    while (i < str.size()) {
        if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
        else return res * sign;
        if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
    }
    return res * sign;
}
//label start &end first
class Solution{
    public:
    int myAtoi(string str){
        long result=0;
        int length=str.length();
        int start=0;
        while(start<length&&str[start]==' '||str[start]=='   '||str[start]=='\n')start++;
        int symbol=1;
        if(str[start]=='+')start++;
        else if(str[start]=='-'){
            symbol=-1;
            start++;
        }
        if(start==length)return 0;
        int end=start;
        while(end<length&&str[end]>='0'&&str[end]<='9')end++;
        if(end-start>10&&symbol==1)return INT_MAX;
        if(end-start>10&&symbol==-1)return INT_MIN;
        for(int i=start;i<end;i++){
            result=result*10+str[i]-'0';
        }
        result*=symbol;
        if(result>INT_MAX)return INT_MAX;
        if(result<INT_MIN)return INT_MIN;
        return (int)result;
    }
};
