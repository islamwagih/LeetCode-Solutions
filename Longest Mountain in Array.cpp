class Solution {
public:
    int longestMountain(vector<int>& array) {
    int maxPeak = 0;
    int i = 1, n = array.size();
    while(i < n-1)
    {
        bool isPeak = array[i] > array[i-1] && array[i] > array[i+1];
        if(isPeak)
        {
        //we found a peak lest's calc how many before and after i
        int beforeThePeak = 0;
        int j = i-1;
        while(j > -1 && array[j] < array[j+1])
        {
            beforeThePeak++;
            j--;
        }
        int afterThePeak = 0;
        j = i+1;
        while(j < n && array[j] < array[j-1])
        {
            afterThePeak++;
            j++;
        }
        maxPeak = max(maxPeak, beforeThePeak+1+afterThePeak);
        i = j;
        continue;
        }
        i++;
    }
    return maxPeak;
    }

};
