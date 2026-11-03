
//Link to this code: https://cses.fi/paste/01bdb762476bd29ec23f22/
#include <iostream>
#include <vector>
using namespace std;
 
class TrieNode {
public:
    TrieNode* children[2];
    
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
    
    ~TrieNode() {
        delete children[0];
        delete children[1];
    }
};
 
class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            
            node = node->children[bit];
        }
    }
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int complementBit = 1 - bit; 
            if (node->children[complementBit]) {
                maxXOR |= (1 << i);
                node = node->children[complementBit];
            } else {
                node = node->children[bit];
            }
        }
        
        return maxXOR;
    }
};
 
int maxSubarrayXOR(const vector<int>& arr, int n) {
    Trie trie;
    int maxXOR = 0;
    int prefixXOR = 0;
    
    trie.insert(0);
    for (int i = 0; i < n; i++) {
        prefixXOR ^= arr[i];
        int currentMaxXOR = trie.findMaxXOR(prefixXOR);
        maxXOR = max(maxXOR, currentMaxXOR);
        trie.insert(prefixXOR);
    }
    
    return maxXOR;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = maxSubarrayXOR(arr, n);
    cout << result << endl;
    
    return 0;
}
