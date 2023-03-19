class WordDictionary
{
    class TrieNode
    {
        TrieNode* links[26];
        bool eow = false;
    public:
        bool hasLink(char c)
        {
            return links[c-'a'] != nullptr;
        }
        TrieNode* getLink(char c)
        {
            return links[c-'a'];
        }
        void addLink(char c)
        {
            links[c-'a'] = new TrieNode();
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
    class Trie
    {
        TrieNode* root;
    public:
        Trie()
        {
            root = new TrieNode();
        }

        void addWord(string word)
        {
            TrieNode* curr = root;
            for(char& c:word)
            {
                if(!curr->hasLink(c)) curr->addLink(c);
                curr = curr->getLink(c);
            }
            curr->makeEndOfWord();
        }

        bool hasWord(string word)
        {
            TrieNode* curr = root;
            for(char& c:word)
            {
                if(!(curr->hasLink(c))) return false;
                curr = curr->getLink(c);
            }
            return curr->isEndOfWord();
        }

        bool dfs(TrieNode* curr, string& word, int ind)
        {
            if(ind >= word.size())
            {
                return curr->isEndOfWord();
            }
            char& c = word[ind];
            if(c  == '.')
            {
                for(char i='a';i<='z';i++)
                {
                    if(curr->hasLink(i))
                    {
                        if(dfs(curr->getLink(i), word, ind+1))
                        {
                            return true;
                        }
                    } 
                }
                return false;
            }else
            {
                if(!(curr->hasLink(c)))
                {
                    return false;
                }
                return dfs(curr->getLink(c), word, ind+1);
            }
           return curr->isEndOfWord();
        }

        bool dfs(string& word)
        {
            return dfs(root, word, 0);
        }
    };

    Trie* root;
public:
    WordDictionary()
    {
        root = new Trie();
    }
    
    void addWord(string word)
    {
        root->addWord(word);
    }
    
    bool search(string word)
    {
        return root->dfs(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
