//
//  RadixTree.h
//  Project 4
//
//  Created by Michael Tao on 3/4/22.
//

#ifndef RadixTree_h
#define RadixTree_h


#include "provided.h"
#include <string>


// only leaf nodes have values apparently
template <typename ValueType>
class RadixTree {
public:
    RadixTree() {
        root = new RadixNode();
    }
    ~RadixTree() {
        
    }
    
    void insert(std::string key, const ValueType& value) {
        int firstLetter = key[0];
        RadixNode* prevNode = root;
        RadixNode* currNode = root;
        if (currNode->edges[firstLetter]) {
            currNode = currNode->edges[firstLetter];
            for (int i = 0; i < key.length(); i++) {
                if (currNode->myPrefix[i] == key[i])
                    continue;
                else if (i >= currNode->myPrefix.length()) {
                    if (currNode->edges[key[i]]) {
                        prevNode = currNode;
                        currNode = currNode->edges[key[i]];
                        key = key.substr(i);
                        i = -1;
                        continue;
                    }
                    else {
                        RadixNode* insertMe = new RadixNode();
                        insertMe->myPrefix = key.substr(i);
                        currNode->edges[key[i]] = insertMe;
                        insertMe->endWord = true;
                        insertMe->val = value;
                        return;
                    }
                }
                else {
                    // currNode = currNode->edges[key[i] - 'a'];
                    std::string newKey = key.substr(0,i);
                    std::string secondHalf = key.substr(i);
                    
                    RadixNode* newNode = new RadixNode();
                    newNode->myPrefix = newKey;
                    prevNode->edges[newKey[0]] = newNode;
                    std::string sHalfOfCurr = currNode->myPrefix.substr(i);
                    newNode->edges[sHalfOfCurr[0]] = currNode;
                    
                    RadixNode* secondHalfOfKey = new RadixNode();
                    secondHalfOfKey->myPrefix = secondHalf;
                    newNode->edges[secondHalf[0]] = secondHalfOfKey;
                    currNode->myPrefix = sHalfOfCurr;
                    secondHalfOfKey->val = value;
                    secondHalfOfKey->endWord = true;
                    return;
                }
            }
        }
        else {
            RadixNode* newNode = new RadixNode();
            newNode->val = value;
            newNode->myPrefix = key;
            newNode->endWord = true;
            currNode->edges[firstLetter] = newNode;
            return;
        }
    }
    
    ValueType* search(std::string key) const {
        RadixNode* currNode = root;
        int firstLetter = key[0];
        std::string currkey = key;
        
        while (!currkey.empty()) {
            if (currNode && currNode->edges[firstLetter]) {
                currNode = currNode->edges[firstLetter];
                for (int i = 0; currNode; i++) {
                    i = lastCommon(currkey, currNode->myPrefix);
                    if (currNode->myPrefix.length() == i) {
                        if (currNode->edges[currkey[i]]) {
                            currNode = currNode->edges[currkey[i]];
                            currkey = currkey.substr(i);
                            firstLetter = currkey[0];
                        }
                        else {
                            currkey = currkey.substr(i);
                            firstLetter = currkey[0];
                            break;
                        }
                    }
                    else
                        break;
                }
            }
            else {
                return nullptr;
            }
        }
        if (currNode->endWord)
            return &currNode->val;
        else
            return nullptr;
    }
private:
    struct RadixNode {
        ValueType val;
        std::string myPrefix;
        bool endWord = false;
        RadixNode* edges[256] = {nullptr};
        
        ~RadixNode() {
            for (int i = 0; i<256; i++) {
                delete [] edges[i];
                edges[i] = nullptr;
            }
        }
    };
    
    RadixNode* root;
    
    int lastCommon (std::string a1, std::string a2) const{
        int i = 0;
        while (i<a1.length() && i<a2.length() && a1[i]==a2[i]) {
            i++;
        }
        return i;
    }
};


//#include <map>
//template <typename ValueType>
//class RadixTree {
//public:
//    RadixTree() { m_map.clear(); }
//    ~RadixTree() {
//        m_map.clear();
//    }
//    void insert(std::string key, const ValueType& value) {
//        m_map[key] = value;
//    }
//    ValueType* search(std::string key) const {
//        typename std::map<std::string, ValueType>::const_iterator it = m_map.find(key);
//        if (it == m_map.end())
//            return nullptr;
//        return const_cast<ValueType*>(&(it->second));
//    }
//private:
//    std::map<std::string, ValueType> m_map;
//};

#endif /* RadixTree_h */
