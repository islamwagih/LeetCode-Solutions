class Trie
{
    class TrieNode
    {
        TrieNode* links[26];
        bool eow = false;
    public:
        bool hasLink(char c)
        {
            return links[c - 'a'] != nullptr;
        }
        void addLink(char c)
        {
            links[c - 'a'] = new TrieNode();
        }
        TrieNode* getLink(char c)
        {
            return links[c-'a'];
        }
        void makeEndOfWord()
        {
            eow = true;
        }
        bool isEndOfWord()
        {
            return eow;
        }
    };

    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* curr = root;
        for(char& c:word)
        {
            if(!curr->hasLink(c))
            {
                curr->addLink(c);
            }
            curr = curr->getLink(c);
        }
        curr->makeEndOfWord();
    }
    
    bool search(string word)
    {
        TrieNode* curr = root;
        for(char& c:word)
        {
            if(curr->hasLink(c))
            {
                curr = curr->getLink(c);
            }else
            {
                return false;
            }
        }
        return curr->isEndOfWord();
    }
    
    bool startsWith(string prefix)
    {
        TrieNode* curr = root;
        for(char& c:prefix)
        {
            if(curr->hasLink(c))
            {
                curr = curr->getLink(c);
            }else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
