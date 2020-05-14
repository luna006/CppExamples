#include <iostream>
#include <string>
#include <memory>
#include <vector>

int main() {
    std::shared_ptr<std::string> pNico{new std::string("nico"), [](std::string* p) {
        std::cout << "Delete " << *p << std::endl;
        delete p;
    }};
    std::shared_ptr<std::string> pPeat = std::make_shared<std::string>("peat");

    (*pNico)[0] = 'N';
    pPeat->replace(0, 1, "P");

    std::vector<std::shared_ptr<std::string>> people;
    people.push_back(pNico);
    people.push_back(pNico);
    people.push_back(pPeat);
    people.push_back(pNico);
    people.push_back(pPeat);

    for (const auto& person : people) {
        std::cout << *person << " ";
    }
    std::cout << std::endl;

    *pNico = "Nicolai";
    pPeat.reset(new std::string("Dmitry"));
    for (const auto& person : people) {
        std::cout << *person << " ";
    }
    std::cout << std::endl;

    std::cout << "Count: " << people[0].use_count() << std::endl;
    return 0;
}

