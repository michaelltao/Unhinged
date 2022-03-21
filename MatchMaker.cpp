//
//  MatchMaker.cpp
//  Project 4
//
//  Created by Michael Tao on 3/4/22.
//

#include "MatchMaker.h"
#include <functional>

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at): m_mbd(mdb), m_at(at) {}

MatchMaker::~MatchMaker() {
    
}

std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email, int threshold) const {
    const PersonProfile* pp = m_mbd.GetMemberByEmail(email);
    
    std::set<AttValPair> compPairs;
    for (int i = 0; i < pp->GetNumAttValPairs(); i++) {
        AttValPair newPair;
        pp->GetAttVal(i, newPair);
        std::vector<AttValPair> vPair = m_at.FindCompatibleAttValPairs(newPair);
        for (int j = 0; j<vPair.size(); j++) {
            compPairs.insert(vPair[j]);
        }
    }
    
    std::unordered_map<std::string, int> emailCounts;
    for (auto a: compPairs) {
        std::vector<std::string> mMembers = m_mbd.FindMatchingMembers(a);
        for (auto b: mMembers) {
            auto c = emailCounts.find(b);
            if (c != emailCounts.end()) {
                emailCounts[b]++;
            }
            else {
                emailCounts[b] = 1;
            }
        }
    }
    std::set<EmailCount> rMatches;
    for (auto it: emailCounts) {
        if (it.second >= threshold) {
            rMatches.insert(EmailCount(it.first, it.second));
        }
    }
    
    std::vector<EmailCount> rankedMatches;
    for (auto iter: rMatches) {
        rankedMatches.push_back(iter);
    }
    
    return rankedMatches;
    
}
