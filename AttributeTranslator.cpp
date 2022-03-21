//
//  AttributeTranslator.cpp
//  Project 4
//
//  Created by Michael Tao on 3/4/22.
//

#include "AttributeTranslator.h"

AttributeTranslator::AttributeTranslator() {}

AttributeTranslator::~AttributeTranslator() {}

bool AttributeTranslator::Load(std::string filename) {
    std::ifstream infile(filename);
    
    if (!infile)
        return false;
    
    std::string a;
    
    while (getline(infile, a)) {
        std::istringstream s(a);
        std::string sourceAtt;
        getline(s, sourceAtt, ',');
        std::string sourceVal;
        getline(s, sourceVal, ',');
        
        std::string compatibleAtt;
        getline(s, compatibleAtt, ',');
        std::string compatibleVal;
        getline(s, compatibleVal);
        
        std::string sourcePair = sourceAtt + ',' + sourceVal;
        AttValPair cPair(compatibleAtt, compatibleVal);
        
        std::vector<AttValPair>* attVec = mpairs.search(sourcePair);
        
        if (attVec) {
            attVec->push_back(cPair);
        }
        else {
            std::vector<AttValPair> newVec;
            newVec.push_back(cPair);
            mpairs.insert(sourcePair, newVec);
        }
    }
    return true;
}

std::vector<AttValPair> AttributeTranslator:: FindCompatibleAttValPairs(const AttValPair &source) const {
    std::string searchMe = source.attribute + ',' + source.value;
    std::vector<AttValPair>* attVec = mpairs.search(searchMe);

    return *attVec;
}
