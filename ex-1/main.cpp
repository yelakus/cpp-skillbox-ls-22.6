#include <iostream>
#include <string>
#include <map>

std::string getCommand();
void add(std::map<std::string, std::string>* tDirectory);
void fName(std::map<std::string, std::string>* tDirectory);
void fNum(std::map<std::string, std::string>* tDirectory);

int main(){
std::map<std::string, std::string> tDirectory;
std::string command;

while (command != "exit"){
    command = getCommand();
    if (command == "add") add(&tDirectory);
    if (command == "fname") fName(&tDirectory);
    if (command == "fnum") fNum(&tDirectory);
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

void add(std::map<std::string, std::string>* tDirectory){
    std::string num, name;
    std::cout << "Enter number and name:" << std::endl;
    std::cin >> num >> name;

    tDirectory->insert(std::make_pair(num, name));
    std::cout << num << " " << name << " added!" << std::endl;
    std::cout << "-------------" << std::endl;
}

void fName(std::map<std::string, std::string>* tDirectory){
    std::string num;
    std::cin >> num;

    auto it = tDirectory->find(num);
    if (it != tDirectory->end()) {
        std::cout << it->second << std::endl;
    } else {
        std::cout << "Number not found" << std::endl;
    }
}

void fNum(std::map<std::string, std::string>* tDirectory){
    std::string name;
    std::cin >> name;

    std::cout << "All found numbers:" << std::endl;
    for(std::map<std::string, std::string>::iterator it = tDirectory->begin(); it != tDirectory->end(); ++it){
        if(it->second == name){
            std::cout << it->first << " " << name << std::endl;
        }
    }
    std::cout << "-------------" << std::endl;
}