class Solution {
public:
    char sumChars(char a, char b)
    {
        if( a == '1' && b == '1' ) return '2';
        else if(a == '1' || b == '1') return '1';
        else return '0';
    }
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        vector<char> sum;
        if(b.size() > a.size()) swap(a, b); //to enforce that "a" will always be bigger
        int asize = a.size(), bsize = b.size();
        for(int i=0;i<bsize;i++)
        {
            char csum = sumChars(a[i], b[i]);
            sum.push_back(csum);
        }
        for(int i=bsize;i<asize;i++)
        {
            sum.push_back(a[i]);
        }
        int sumSize = sum.size();
        for(int i=0;i<sumSize-1;i++)
        {
            //to handle carry at position i
            if(sum[i] == '2') //make it zero and ++1 to the next i
            {
                sum[i] = '0';
                sum[i+1]++;
            }else if(sum[i] == '3') //make it one and ++1 to the next i
            {
                sum[i] = '1';
                sum[i+1]++;
            }
        }
        //handle carry at last position
        int last = sumSize-1;
        if(sum[last] == '2') //make it zero and push 1 to the end 
        {
            sum[last] = '0';
            sum.push_back('1');
        }else if(sum[last] == '3') //make it one and push 1 to the end
        {
            sum[last] = '1';
            sum.push_back('1');
        }
        string ans = "";
        int n = sum.size();
        for(int i=n-1;i>=0;i--) ans += sum[i];
        return ans;
    }
};
