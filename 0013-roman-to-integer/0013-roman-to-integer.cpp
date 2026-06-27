class Solution {
public:
     int char2num(char a) {
        switch (a) {
            case 'I': return 1;break;
            case 'V': return 5;break;
            case 'X': return 10;break;
            case 'L': return 50;break;
            case 'C': return 100;break;
            case 'D': return 500;break;
            case 'M': return 1000;break;
            default: return 0;break;
        }
    }
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++){
            if( i< s.length() && char2num(s[i]) < char2num(s[i+1])){
                result -= char2num(s[i]);

            }
            else{
                result += char2num(s[i]);

            }
        }
        return result;

    }
};