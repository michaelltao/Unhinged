//
//  MemberDatabase.h
//  Project 4
//
//  Created by Michael Tao on 3/4/22.
//

#ifndef MemberDatabase_h
#define MemberDatabase_h

#include "provided.h"
#include "PersonProfile.h"
#include "RadixTree.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class MemberDatabase {
public:
    MemberDatabase();
    ~MemberDatabase();
    bool LoadDatabase(std::string filename);
    std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
    const PersonProfile* GetMemberByEmail(std::string email) const;
    
private:
    RadixTree<std::vector<std::string>> attPairToEmail;
    RadixTree<PersonProfile> emailToProfile;
};

#endif /* MemberDatabase_hpp */
