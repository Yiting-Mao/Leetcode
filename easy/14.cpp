//without iterator 4ms
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        if(strs.empty())return result;
        int j=0;
        while(1){
            char tmp;
            for(int it=0;it<strs.size();it++){
                if(it==0){
                    if(j<strs[it].length())tmp=strs[it][j];
                    else return result;
                }
                else{
                    if(j==strs[it].length()||strs[it][j]!=tmp)return result;
                }
            }
            result+=tmp;
            j++;
        }
    }
};

//compare one character at a time, using iterator 8ms
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        if(strs.empty())return result;
        int j=0;
        vector<string>::iterator it;
        while(1){
            char tmp;
            for(it=strs.begin();it!=strs.end();it++){
                if(it==strs.begin()){
                    if(j<(*it).length())tmp=(*it)[j];
                    else return result;
                }
                else{
                    if(j==(*it).length()||(*it)[j]!=tmp)return result;
                }
            }
            result+=tmp;
            j++;
        }
    }
};
