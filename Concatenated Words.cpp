class Solution
{
        
    class TrieNode
    {
        TrieNode* chars[26];
    public:
        bool endOfWord;
        TrieNode()
        {
            endOfWord = false;
            for(int i=0;i<26;i++) chars[i] = nullptr;
        }
        TrieNode* get(char c)
        {
            return chars[c-'a'];
        }
        void set(char c)
        {
            chars[c-'a'] = new TrieNode();
        }
    };

    class Trie
    {
        TrieNode* root;
    public:
        Trie()
        {
            root = new TrieNode();
        }

        void add(string& str)
        {
            TrieNode* curr = root;
            for(char& c:str)
            {
                if(curr->get(c) == nullptr)
                {
                    curr->set(c);
                }
                curr = curr->get(c);
            }
            curr->endOfWord = true;
        }

        bool dfs(string& str, int index, int count)
        {
            if (index >= str.size()) return count > 1;
            TrieNode* curr = root;
            for (int i = index; i < str.size(); i++)
            {
                if (curr->get(str[i]) == nullptr) return false;
                curr = curr->get(str[i]);
                if (curr->endOfWord)
                {
                    bool validPartition = dfs(str, i+1, count+1);
                    if(validPartition) return true;
                }
            }
            return false;
        }
    };
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
    {
        vector<string> targetWords;
        Trie trie;
        for(string& word:words)
        {
            trie.add(word);
        }
        for(string& word:words)
        {
            if(trie.dfs(word, 0, 0))
            {
                targetWords.push_back(word);
            }
        }
        return targetWords;
    }
};
