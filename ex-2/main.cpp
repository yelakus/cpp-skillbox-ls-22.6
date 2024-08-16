#include <iostream>
#include <string>
#include <map>

void nextClient(std::map<std::string, std::string>* queue, std::string* input);
void addToQeue(std::map<std::string, std::string>* queue, int* counter, std::string* input);

int main(){
    std::map<std::string, std::string> queue;
    std::string input;
    int counter = 0;

    while(true){
        std::cout << "Enter name, \"next\" or \"exit\"" << std::endl;
        std::cin >> input;
        if(input == "exit") {
            std::cout << "Bye!" << std::endl;
            break;
        }
        else if(input == "next") {
            nextClient(&queue, &input);
        }
        else {
            addToQeue(&queue, &counter, &input);
            counter++;
        }
    }
}

void addToQeue(std::map<std::string, std::string>* queue, int* counter, std::string* input){
    std::string keyName = *input + std::to_string(*counter); // создаю уникальный ключ
    queue->insert(std::make_pair(keyName, *input));
}

void nextClient(std::map<std::string, std::string>* queue, std::string* input){

    auto next = queue->begin();
    //std::cout << next->first << " ";
    std::cout << next->second << std::endl;
    queue->erase(next);

}
