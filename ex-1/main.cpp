#include <iostream>
#include <string>
#include <map>

std::string getCommand();
void add(std::map<std::string, std::string>* tDirectoryKeyNum, std::multimap<std::string, std::string>* tDirectoryKeyName);
void fName(std::map<std::string, std::string>* tDirectoryKeyNum);
void fNum(std::multimap<std::string, std::string>* tDirectoryKeyNum);

int main(){
std::map<std::string, std::string> tDirectoryKeyNum;
std::multimap<std::string, std::string> tDirectoryKeyName;
std::string command;

while (command != "exit"){
    command = getCommand();
    if (command == "add") add(&tDirectoryKeyNum, &tDirectoryKeyName);
    if (command == "fname") fName(&tDirectoryKeyNum);
    if (command == "fnum") fNum(&tDirectoryKeyName);
}

    std::cout << "Bye!" << std::endl;
}

std::string getCommand(){
    std::string command;
    while(true){
        std::cout << "Enter command add, fname, fnum or exit:" << std::endl; // fname - узнать фамилию по номеру телефона, fnum - узнать телефонпо фамилии 
        std::cin >> command;
        if (command == "add" || command == "fname" || command == "fnum" || command == "exit") break;
        std::cout << "Invalid command" << std::endl;
    }
    return command;
}

void add(std::map<std::string, std::string>* tDirectoryKeyNum, std::multimap<std::string, std::string>* tDirectoryKeyName){
    std::string num, name;
    std::cout << "Enter number and name:" << std::endl;
    std::cin >> num >> name;

    tDirectoryKeyNum->insert(std::make_pair(num, name));
    tDirectoryKeyName->insert(std::make_pair(name, num));
    std::cout << num << " " << name << " added!" << std::endl;
    std::cout << "-------------" << std::endl;
}

void fName(std::map<std::string, std::string>* tDirectoryKeyNum){
    std::string num;
    std::cin >> num;

    auto it = tDirectoryKeyNum->find(num);
    if (it != tDirectoryKeyNum->end()) {
        std::cout << it->second << std::endl;
    } else {
        std::cout << "Number not found" << std::endl;
    }
}

void fNum(std::multimap<std::string, std::string>* tDirectoryKeyName){
    std::string name;
    std::cin >> name;

    auto range = tDirectoryKeyName->equal_range(name);
    if (range.first != range.second) {
        std::cout << "All found numbers:" << std::endl;
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << it->second << " " << name << std::endl;
        }
    } else {
        std::cout << "Name not found" << std::endl;
    }
    std::cout << "-------------" << std::endl;
}