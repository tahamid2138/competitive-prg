#include <bits/stdc++.h>
using namespace std;

struct vertex {
  char alphabet;
  bool exist;
  vector<vertex*> child;
  // Size changed from 26 to 2 for binary words ('0' and '1')
  vertex(char a): alphabet(a), exist(false) { child.assign(2, NULL); }
};

class Trie {                                     // this is TRIE
private:                                         // NOT Suffix Trie
  vertex* root;
public:
  Trie() { root = new vertex('!'); }

  void insert(string word) {                     // insert a word into trie
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) { // O(n)
      int alphaNum = word[i]-'0';                // Map '0'->0 and '1'->1
      if (cur->child[alphaNum] == NULL)          // add new branch if NULL
        cur->child[alphaNum] = new vertex(word[i]);
      cur = cur->child[alphaNum];
    }
    cur->exist = true;
  }

  bool search(string word) {                     // true if word in trie
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) { // O(m)
      int alphaNum = word[i]-'0';                // Map '0'->0 and '1'->1
      if (cur->child[alphaNum] == NULL)          // not found
        return false;
      cur = cur->child[alphaNum];
    }
    return cur->exist;                           // check exist flag
  }

  bool startsWith(string prefix) {               // true if match prefix
    vertex* cur = root;
    for (int i = 0; i < (int)prefix.size(); ++i) {
      int alphaNum = prefix[i]-'0';              // Map '0'->0 and '1'->1
      if (cur->child[alphaNum] == NULL)          // not found
        return false;
      cur = cur->child[alphaNum];
    }
    return true;                                 // reach here, return true
  }
};

int main() {
  Trie T;
  set<string> S = {"010", "011", "111"};
  for (auto &str : S) {
    printf("Insert %s\n", str.c_str());
    T.insert(str);
  }
  printf("'010' exist? %d\n", T.search("010"));  // 1 (true)
  printf("'000' exist? %d\n", T.search("000"));  // 0 (false)
  printf("Starts with '01' exist? %d\n", T.startsWith("01")); // 1 (true)
  printf("Starts with '10' exist? %d\n", T.startsWith("10")); // 0 (false)
  return 0;
}
