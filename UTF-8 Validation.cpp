class Solution {
public:
    void reverse(bool bin[])
    {
        int left=0, right = 7;
        while(left < right) swap(bin[left++], bin[right--]);
    }

    void convert(int decimal, bool bin[])
    {
        int i = 0;
        while(decimal)
        {
            bin[i++] = decimal & 1;
            decimal >>= 1;
        }
    }
    bool validUtf8(vector<int>& data) 
    {
        vector<bool[8]> binData(data.size());
        int i=0;
        for(int& number:data)
        {
            convert(number, binData[i]);
            reverse(binData[i]);
            i++;
        }
        int number = 0;
        while(number < binData.size())
        {
            int bytes = 0;
            for(int i=0;i<8;i++)
            {
                if(binData[number][i] == 0 || bytes >= 4) break;
                bytes++;
            }
            if(bytes == 1 || binData[number][bytes] == 1) return false;
            if(bytes == 0) bytes++;
            for(int step=1;step<bytes;step++)
            {
                if(
                   number+step >= binData.size() || 
                   !(binData[number+step][0] == 1 && 
                   binData[number+step][1] == 0)
                  )  return false;
    
            }
            number += bytes;
        }
        return true;
    }
};
