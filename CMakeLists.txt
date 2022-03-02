cmake_minimum_required(VERSION 3.16)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(course main.c libs/string/string_.c libs/string/string_.h libs/string/tasks/allTests.h libs/string/tasks/removeNonLetters.h libs/string/tasks/removeExtraSpaces.h libs/string/tasks/digitToEnd.h libs/string/tasks/replaceAllDigitAsSpaces.h libs/string/tasks/replace.h libs/string/tasks/areSortedWords.h libs/string/tasks/reverseWordsInString.h libs/string/tasks/countPolindroms.h)

add_subdirectory(libs)
target_link_libraries(course data_structures)
target_link_libraries(course algorithms)