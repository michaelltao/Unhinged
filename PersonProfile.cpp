//
//  PersonProfile.cpp
//  Project 4
//
//  Created by Michael Tao on 3/4/22.
//

#include "PersonProfile.h"

PersonProfile::PersonProfile(std::string name, std::string email) {
    m_name = name;
    m_email = email;
}

PersonProfile::~PersonProfile() {
    
}

std::string PersonProfile::GetName() const {
    return m_name;
}

std::string PersonProfile::GetEmail() const {
    return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair &attval) {
    m_attVals.push_back(attval);
}

int PersonProfile::GetNumAttValPairs() const {
    return static_cast<int>(m_attVals.size());
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair &attval) const {
    if (m_attVals.size() > attribute_num) {
        attval = m_attVals[attribute_num];
        return true;
    }
    return false;
}
