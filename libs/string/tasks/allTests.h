//
// Created by HP on 28.02.2022.
//

#ifndef COURSE_ALLTESTS_H
#define COURSE_ALLTESTS_H

#include "removeNonLetters.h"
#include "removeExtraSpaces.h"
#include "digitToEnd.h"
#include "replaceAllDigitAsSpaces.h"
#include "replace.h"

void allTests(){
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToEnd();
    test_replaceAllDigitAsSpaces();
    test_replace();
}

#endif //COURSE_ALLTESTS_H
