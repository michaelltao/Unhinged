//
//  AttributeTranslator.h
//  Project 4
//
//  Created by Michael Tao on 3/4/22.
//

#ifndef AttributeTranslator_h
#define AttributeTranslator_h

#include "provided.h"
#include "RadixTree.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class AttributeTranslator {
public:
    AttributeTranslator();
    ~AttributeTranslator();
    bool Load(std::string filename);
    std::vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
    
private:
    RadixTree<std::vector<AttValPair>> mpairs;

};

#endif /* AttributeTranslator_hpp */
