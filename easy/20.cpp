//use a stack
class Solution {
public:
    bool isValid(string s) {
        stack<char> leftPart;
        char tmp;
        for(int i=0;i<s.length();i++){
            tmp=s[i];
            if(tmp=='('||tmp=='['||tmp=='{'){
                leftPart.push(tmp);
            }
            else if(!leftPart.empty()){
                switch(leftPart.top()){
                    case '(':if(tmp!=')')return false;break;
                    case '{':if(tmp!='}')return false;break;
                    case '[':if(tmp!=']')return false;break;
                }
                leftPart.pop();
            }
            else return false;
        }
        if(!leftPart.empty())return false;
        return true;
    }
};
