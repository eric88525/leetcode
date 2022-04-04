# 208. Implement Trie (Prefix Tree)

用 TrieNode 來記錄字母，還有用 isEnd 來記錄這單字是否為 end

```c++
class Trie {
public:


    class TrieNode{
        public:
        TrieNode():isEnd(false),childs(vector<TrieNode*>(26,NULL)){} ;
        vector<TrieNode*> childs;
        bool isEnd;

    };

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode*p = root;
        for(auto &c:word){
            if( p->childs[ c-'a' ] ==NULL ) {
                p->childs[c-'a'] = new TrieNode();
                p = p->childs[c-'a'];
            }else{
                p = p->childs[c-'a'];
            }
        }
        p->isEnd=true;
    }

    bool search(string word) {

        TrieNode*p = root;

        for(auto &c:word){
            if( p->childs[ c-'a' ]!=NULL ) p = p->childs[c-'a'];
            else return false;
        }
        return p->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode*p = root;

        for(auto &c:prefix){
            if( p->childs[ c-'a' ]!=NULL ) p = p->childs[c-'a'];
            else return false;
        }
        return true;
    }
};
```
