/*
 * trie.cpp
 *
 * Method definitions for the trie class.
 *
 * Author: <your name here>
 */

#include "trie.h"

trie::trie(){

}

void trie::insert(const string &s){
    TrieNode* tempNode = &root;
    for(unsigned int i = 0; i < s.size(); i++){
        int index = s[i]-97;
        if(!tempNode->children[index]){
            tempNode->children[index] = new TrieNode;
        }
        tempNode = tempNode->children[index];
    }
    tempNode->isEndOfWord = true;
}

bool trie::contains(const string &s){
    TrieNode* tempNode = &root;
    for(unsigned int i = 0; i < s.size(); i++){
        int index = s[i]-97;
        if(!tempNode->children[index]){
            return false;
        }
        tempNode = tempNode->children[index];
    }
    if(tempNode->isEndOfWord){
        return true;
    }else{
        return false;
    }
}

bool trie::is_prefix(const string &s){
    TrieNode* tempNode = &root;
    for(unsigned int i = 0; i < s.size(); i++){
        int index = s[i]-97;
        if(!tempNode->children[index]){
            return false;
        }
        tempNode = tempNode->children[index];
    }
    return true;
}

void trie::extend(const string &prefix, vector<string> &result){
    TrieNode* tempNode = &root;
    for(unsigned int i = 0; i < prefix.size(); i++){
        int index = prefix[i]-97;
        if(!tempNode->children[index]){
            return;
        }
        tempNode = tempNode->children[index];
    }
    if(tempNode->isEndOfWord){
        result.push_back(prefix);
    }
    preOrderTrieHelper(tempNode, prefix, result);
    return;
}

void trie::preOrderTrieHelper(TrieNode* &root, string prefix, vector<string> &result){
        if (root == nullptr) {
            return;
        }
        for (unsigned int i=0; i < 26; i++) {
            if (root->children[i]!=nullptr && root->children[i]->isEndOfWord) {
                result.push_back(prefix+char('a' + i));
            }
            // append the char to the prefix and continue recursively
            preOrderTrieHelper(root->children[i], prefix + char('a' + i), result);
        }
    }

int trie::count_nodes(TrieNode* &root){
    if (root == nullptr) {
        return 0;
    }else{
        int count = 1;
        for(unsigned int i=0; i < 26; i++) {
            if (root->children[i]!=nullptr) {
                count = count + count_nodes(root->children[i]);
            }
        }
        return count;
    }
}

int trie::count_leaf_nodes(TrieNode* &root){
    if (root == nullptr) {
        return 0;
    }else{
        int empty = 0;
        for(unsigned int i=0; i < 26; i++) {
            if (root->children[i]==nullptr) {
                empty++;
            }
        }
        if(empty == 26){
            leafCount++;
        }
        for(unsigned int i=0; i < 26; i++) {
            count_leaf_nodes(root->children[i]);
        }
        return leafCount;
    }
    
}

int trie::call_count_leaf_nodes() {
    TrieNode* tempNode = &root;
    leafCount = 0;
    return count_leaf_nodes(tempNode);
}

int trie::call_count_nodes() {
    TrieNode* tempNode = &root;
    return count_nodes(tempNode);
}