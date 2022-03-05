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
#include "areSortedWords.h"
#include "reverseWordsInString.h"
#include "countPolindroms.h"
#include "getMixString.h"
#include "getLastWordInString1ContainedString2.h"
#include "isContainingSameWords.h"
#include "containPairWordsFromSameLits.h"
#include "getStringFromWordsDifferentByLast.h"
#include "getWordBeforeFirstWordS1ContainedInS2.h"
#include "deleteAllPalindros.h"
#include "fillingSmallStringByReverseBigString.h"

void allTests(){
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToEnd();
    test_replaceAllDigitAsSpaces();
    test_replace();
    test_areSortedWords();
    test_reverseWordsInString();
    test_countOfPolindroms();
    test_getMixString();
    test_getLastWordInString1ContainedString2();
    test_isContainingSameWords();
    test_containPairWordsFromSameLits();
    test_getStringFromWordsDifferentByLast();
    test_getWordBeforeFirstWordS1ContainedInS2();
    test_deleteAllPalindros();
    test_fillingSmallStringByReverseBigString();
}

#endif //COURSE_ALLTESTS_H
