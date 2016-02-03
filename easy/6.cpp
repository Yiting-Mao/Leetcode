//more advanced version, add characters directly
class Solution {
public:

    string convert(string s, int numRows) {
        int length=s.length();
        if(length<=numRows||numRows==1)return s;
        int step=2*(numRows-1);
        string result;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<length+step;j=j+step){
                if(j-i>=0&&j-i<length){
                    result+=s[j-i];
                }
                if(i==0||i==numRows-1)continue;
                if(j+i<length)result+=s[j+i];
            }
        }
        return result;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        int length=s.length();
        if (length<=numRows||numRows==1)return s;
        int col=length/(numRows-1);
        if(length%(numRows-1)!=0)col++;
        char temp[numRows][col]={'1'};
        for(int k=0;k<length;k++){ //put characters into a 2-D array
            int i=k/(numRows-1);
            int j=k%(numRows-1);
            if(i%2==0){
                temp[j][i]=s.at(k);
            }
            else{
                temp[numRows-1-j][i]=s.at(k);
            }
        }
        char result[length+1];
        int k=0;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<col;j++){
              if(i==0&&j%2==1||i==numRows-1&&j%2==0||j==col-1&&col%2==1&&(col-1)*(numRows-1)+i+1>length||j==col-1&&col%2==0&&(col-1)*(numRows-1)+numRows-i>length)
                    continue;
                else{
                    result[k]=temp[i][j];
                    k++;
                }
            }
        }
        result[length]='\0';
        string eventual(result);
        return eventual;
    }
};
