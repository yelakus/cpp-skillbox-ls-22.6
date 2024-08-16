#include <iostream>
#include <string>
#include <map>

bool isAnagrams(std::string* firstWord, std::string* secondWord);

int main(){
    std::string firstWord, secondWord;
    std::cin >> firstWord >> secondWord;

    isAnagrams(&firstWord, &secondWord) ? std::cout << "true" : std::cout << "false";

}

bool isAnagrams(std::string* firstWord, std::string* secondWord){

    if (firstWord->length() != secondWord->length()) {
        return false;
    }

    std::map<char, int> firstWordChars, secondWordChars;

    for (char c : *firstWord) {
        firstWordChars[c]++;
    }

    for (char c : *secondWord) {
        secondWordChars[c]++;
    }

    return firstWordChars == secondWordChars;
}