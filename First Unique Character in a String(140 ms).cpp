class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hashMap;
        int size = s.size();
        for(int idx = 0;idx < size;idx++){
            if(hashMap.count(s[idx]) > 0){
                //element has dublicate
                hashMap[s[idx]] = size;
            }else{
                hashMap[s[idx]] = idx;
            }
        }
        unordered_map<char,int>::iterator it = hashMap.begin();
        int minIdx = size;
        while(it != hashMap.end()){
            if(it->second < minIdx)
                minIdx = it->second;
            it++;
        }
        if(minIdx == size)
            return -1;
        return minIdx;    
    }
};
