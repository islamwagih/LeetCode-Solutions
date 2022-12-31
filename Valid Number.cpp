//base on DFA 
class Solution {
    bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }
public:
    bool isNumber(string s) {
        //consune optional + or -
        bool parseAtLeastOneDigit = false;
        int parseInd = 0, limit = s.size();
        if(s[parseInd] == '+' || s[parseInd] == '-') parseInd++;
        if(parseInd == limit) return false;
        //either a digit or a dot
        if(!(s[parseInd] == '.' || isDigit(s[parseInd]))) return false;
        while(parseInd < limit && isDigit(s[parseInd])) {parseInd++; parseAtLeastOneDigit = true;}
        if(parseInd == limit) return true;
        //we must see a dot here or e or E
        if(!(s[parseInd] == '.' || s[parseInd] == 'e' || s[parseInd] == 'E')) return false;
        parseInd++;
        if((s[parseInd-1] == 'e' || s[parseInd-1] == 'E' ) && parseInd == limit) return false;
        if((s[parseInd-1] == 'e' || s[parseInd-1] == 'E' ) && !parseAtLeastOneDigit) return false;
        //we can see sequence of digits 
        if((s[parseInd-1] == 'e' || s[parseInd-1] == 'E' ))
        {
            //parse optional - or + after e 
            if(s[parseInd] == '+' || s[parseInd] == '-') parseInd++;
            if(parseInd == limit) return false;
            //we should match one or more digits or error
            if(!isDigit(s[parseInd])) return false;
            while(parseInd < limit && isDigit(s[parseInd])) {parseInd++; parseAtLeastOneDigit = true;}
            //we must reach end or error
            if(parseInd == limit && parseAtLeastOneDigit) return true;
            return false;
        }else
        {
            //we should match zero or more digits or error
            while(parseInd < limit && isDigit(s[parseInd])) {parseInd++; parseAtLeastOneDigit = true;}
            //we must reach end or error
            if(parseInd == limit && parseAtLeastOneDigit) return true;
        }
        //if controls reaches here then we must find e or E followed my one or more digits
        if(!(s[parseInd] == 'e' || s[parseInd] == 'E')) return false;
        if(!parseAtLeastOneDigit) return false;
        parseInd++;
        //parse optional - or + after e 
        if(s[parseInd] == '+' || s[parseInd] == '-') parseInd++;
        if(parseInd == limit) return false;
        //we can see sequence of one or more digits 
        parseAtLeastOneDigit = false;
        while(parseInd < limit && isDigit(s[parseInd])){ parseInd++; parseAtLeastOneDigit = true;}
        if(parseInd == limit && parseAtLeastOneDigit) return true;
        return false;
    }
};
