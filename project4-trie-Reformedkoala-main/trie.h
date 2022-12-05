/*
 * trie.h
 *
 * Declaration of the trie class.
 * 
 * Author: <your name here>
 */

#ifndef _TRIE_H
#define _TRIE_H

#include <string>
#include <vector>

using namespace std;

class trie {
private:
    class TrieNode {
    public:
        TrieNode(){
            isEndOfWord = false;
            for (int i = 0; i < 26; i++)
                this->children[i] = NULL;
        }
        bool isEndOfWord;
        TrieNode *children[26];
    };

    TrieNode root;
    int leafCount;

public:
    trie();
    void insert(const string &s);
    bool contains(const string &s);
    bool is_prefix(const string &s);
    void extend(const string &prefix, vector<string> &result);
    void preOrderTrieHelper(TrieNode* &root, string prefix, vector<string> &result);
    int count_nodes (TrieNode* &root);
    int call_count_nodes();
    int count_leaf_nodes(TrieNode* &root);
    int call_count_leaf_nodes();
};

#endif
