class Solution {
public:
    string reorganizeString(string s)
    {
       priority_queue<pair<int, char>> heap;
       int frq[26] = {0};
       for(char c:s) frq[c-'a']++;
       for(int i=0;i<26;i++)
       {
           if(frq[i] > 0) heap.push({frq[i], char(i+'a')});
       }
          
       string reorg = "";
       while(heap.size())
       {
           pair<int, char> mostFrq = heap.top(); heap.pop();
           reorg += mostFrq.second;
           mostFrq.first--;
           if(heap.size())
           {
               pair<int, char> secFrq = heap.top(); heap.pop();
               reorg += secFrq.second;
               secFrq.first--;
               if(secFrq.first) heap.push(secFrq);
           }else if(mostFrq.first > 0)
           {
                return "";
           }
           if(mostFrq.first) heap.push(mostFrq);
       }
       return reorg;
    }
};
