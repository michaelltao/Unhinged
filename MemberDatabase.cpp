//
//  MemberDatabase.cpp
//  Project 4
//
//  Created by Michael Tao on 3/4/22.
//

#include "MemberDatabase.h"

MemberDatabase::MemberDatabase() {
    
}

MemberDatabase::~MemberDatabase() {
    
}

bool MemberDatabase::LoadDatabase(std::string filename) {
    std::ifstream infile(filename);
    
    if (!infile)
        return false;
    
    std::string m_name;
    while (getline(infile, m_name)) {
        if (m_name.empty())
            continue;
        
        std::string m_email;
        getline(infile, m_email);
        
        std::string attValNum;
        std::getline(infile, attValNum);
        
        int count = stoi(attValNum);
        PersonProfile npc = PersonProfile(m_name, m_email);
        for (int i = 0; i < count; i++) {
            std::string atPa;
            std::getline(infile, atPa);
            std::istringstream s(atPa);
            std::string m_at;
            getline(s, m_at, ',');
            std::string m_val;
            getline(s, m_val);
            AttValPair aP(m_at, m_val);
            
            std::vector<std::string>* test = attPairToEmail.search(atPa);
            if (test) {
                (*attPairToEmail.search(atPa)).push_back(m_email);
            }
            else {
                std::vector<std::string> newOne;
                newOne.push_back(m_email);
                attPairToEmail.insert(atPa, newOne);
            }
            
            npc.AddAttValPair(aP);
        }
       emailToProfile.insert(m_email, npc);
    }
    return true;
}

std::vector<std::string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const {
    std::string searchMe = input.attribute + ',' + input.value;
    std::vector<std::string>* foundIt = attPairToEmail.search(searchMe);
    std::vector<std::string> returnMe;
    // need to use searchme.second
    if (foundIt) {
        returnMe = *foundIt;
    }
    return returnMe;
}

const PersonProfile* MemberDatabase::GetMemberByEmail(std::string email) const {
    PersonProfile* searchMe = emailToProfile.search(email);
    if (emailToProfile.search(email)) {
        return searchMe;
    }
    return nullptr;
}

