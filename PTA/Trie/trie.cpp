/*
 * @Author: your name
 * @Date: 2020-11-30 17:31:57
 * @LastEditTime: 2020-11-30 17:46:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /undefined/Users/alex/.leetcode/208.实现-trie-前缀树.cpp
 */
/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {

    struct TrieNode {
        map<char, TrieNode*> child_table;
        int end;
        TrieNode():end(0) {}
    };
public:
    /** Initialize your data structure here. */
    Trie() {
        // private
        root = new TrieNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0;i < word.size(); i++) {
            if(curr->child_table.count(word[i]) == 0)
                curr->child_table[word[i]] = new TrieNode();
            
            curr = curr -> child_table[word[i]];
        }
        curr->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, 1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }
private:
    /* int exact_match: 
        param 0: prefix match the word
        param 1: need the word exactly match the branch
    */
    TrieNode* root;

    bool find(string s , int exact_match) {
        TrieNode* curr = root;
        for(int i =0;i<s.size(); i++) {
            if(!curr->child_table.count(s[i])) 
                return false;
            else
                curr = curr->child_table[s[i]];
        }
        if(exact_match)
            return (curr->end)?true:false;
        else
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
// @lc code=end

