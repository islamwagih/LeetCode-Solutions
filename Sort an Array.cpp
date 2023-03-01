class Solution {
public:
    int partition(vector<int>& array, int& left, int& right)
    {
        //random pivot and swap it with last elem
        int randInd = (rand()%(right-left))+left; 
        swap(array[randInd], array[right]);
        int low = left-1, pivot = array[right];
        for(int i=left;i<right;i++)
        {
            if(array[i] < pivot)
            {
                low++;
                swap(array[i], array[low]);
            }
        }
        swap(array[low+1], array[right]);
        return low+1;

    }
    //quick sort to partition on three sets {<, ==, >}
    void quickSort(vector<int>& array, int left, int right)
    {
        if(right <= left) return;
        int pivot = partition(array, left, right);
        int lw = pivot-1;
        while(lw > 0 && array[lw] == array[pivot]) lw--;
        int rw = pivot+1;
        while(rw < array.size()-1 && array[rw] == array[pivot]) rw++;
        quickSort(array, left, lw);
        quickSort(array, rw, right);
    }

    vector<int> sortArray(vector<int>& nums)
    {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
