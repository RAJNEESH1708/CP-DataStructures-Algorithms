class Solution {
 
public:   
    class TrieNode{
 public:
    TrieNode *child[2];
    bool isEnd; 
    TrieNode(){
        child[0]=NULL;
        child[1]=NULL;
        isEnd = false;
    }
};

class Trie{
    public:
     TrieNode* root;
     Trie(){
         root = new TrieNode();
     } 
    // insert()
    void insert(int x){
       TrieNode* node = root;
       for(int i=31;i>=0;i--){
           int bit = (x>>i)&1;
           if(!node->child[bit])
             node->child[bit] = new TrieNode();
           node = node->child[bit];  
       }
       node->isEnd = true; 
    }

    // query() :  max xor with q
    int query(int q){
        TrieNode *node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (q>>i) & 1;
            if (!node->child[bit^1]){
                  node = node->child[bit];
                  // here also we should take the value but will make 
                      no changes
                  }
            else{
                maxXor |= (1<<i); //this will turn on the bit which 
                    was 0 
                node = node->child[bit^1];
            }
        }

        return maxXor;
    }
};

int findMaximumXOR(vector<int>& arr) {
    Trie* root = new Trie();
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        int y = arr[i];
        root->insert(arr[i]);
        int mxXor = root->query(y);
        ans = max(ans,mxXor);
    }
    return ans;
    }
};
