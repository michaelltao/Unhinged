//
//  utility.cpp
//  Project 4
//
//  Created by Michael Tao on 3/13/22.
//

#include "utility.h"

bool operator< (const EmailCount &a, const EmailCount &b) {
    if (a.count > b.count)
        return true;
    if (a.count < b.count)
        return false;
    return a.email < b.email;
}

bool operator< (const AttValPair &a, const AttValPair &b) {
    if (a.attribute > b.attribute)
        return true;
    if (a.attribute < b.attribute)
        return false;
    return a.value > b.value;
}
