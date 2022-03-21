//
//  MatchMaker.h
//  Project 4
//
//  Created by Michael Tao on 3/4/22.
//

#ifndef MatchMaker_h
#define MatchMaker_h

#include "provided.h"
#include "MemberDatabase.h"
#include "AttributeTranslator.h"
#include "utility.h"
#include <vector>
#include <unordered_map>
#include <set>

class MatchMaker {
public:
    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
    ~MatchMaker();
    std::vector<EmailCount> IdentifyRankedMatches(std::string email, int threshold) const;
private:
    MemberDatabase m_mbd;
    AttributeTranslator m_at;
};

#endif /* MatchMaker_hpp */
