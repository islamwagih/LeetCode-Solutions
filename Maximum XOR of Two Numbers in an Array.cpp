class Solution
{
    int maxLenOfBits;
    class TrieNode
    {
        public:
            char ch;
            TrieNode* children[2];
            TrieNode(char ch)
            {
                this->ch = ch;
                children[0] = children[1] = nullptr;
            }
    };
    
    string getBits(int number)
    {
        string bits = "";
        while(number > 0)
        {
            if(number%2 == 0) bits += "0";
            else bits += "1";
            number /= 2;
        }
        while(bits.size() < maxLenOfBits) bits += "0";
        reverse(bits.begin(), bits.end());
        return std::move(bits);
    }
public:

    int findMaximumXOR(vector<int>& nums)
    {
        if(nums.size() == 1) return 0;
        maxLenOfBits = log2(*max_element(nums.begin(), nums.end())) + 1;
        TrieNode* root = new TrieNode('\0');
        for(int num:nums)
        {
            string bits = getBits(num);
            TrieNode* curr = root;
            for(char bit:bits)
            {
                int val = bit - '0';
                if(curr->children[val] == nullptr)
                {
                    curr->children[val] = new TrieNode(bit);
                }
                curr = curr->children[val];
            }
        }

        int ans = 0;
        for(int num:nums)
        {
            string bits = getBits(num);
            TrieNode* curr = root;
            int bestMatch = 0, pos = maxLenOfBits - 1;
            for(char bit:bits)
            {
                int val = bit - '0';
                int comp = val ^ 1;
                if(curr->children[comp] != nullptr)
                {
                    curr = curr->children[comp];
                    int pw = 1;
                    for(int i=0;i<pos;i++) pw *= 2;
                    bestMatch += pw;
                }else
                {
                    curr = curr->children[val];
                }
                pos--;
            }
            ans = max(ans, bestMatch);
        }

        return ans;


    }
};
