#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <map>

int main() {
    std::size_t numberOfVariables{};
    std::cin >> numberOfVariables;
    std::cin.ignore();
    std::string polishExpression;
    std::getline(std::cin, polishExpression);
    std::size_t numberOfTests{};
    std::cin >> numberOfTests;
    std::map<unsigned char, int> variablesMap;
    int variableValue{};
    int firstOperand{};
    int secondOperand{};
    unsigned char ch{};
    unsigned char nextCh{};
    int operand{};
    for (const char c : polishExpression) {
        if (std::isalpha(c)) {
            variablesMap.emplace(static_cast<unsigned char >(c), 0);
        }
    }
    for (std::size_t i = 0; i < numberOfTests; i++) {
        for (auto& entry : variablesMap) {
            std::cin >> variableValue;
            entry.second = variableValue;
        }
        std::stack<std::pair<bool, std::stack<int>>> stacks;
        stacks.push(std::make_pair(false, std::stack<int>()));
        std::istringstream iss(polishExpression);
        while (iss >> ch) {
            std::stack<int>& stack = stacks.top().second;
            switch (ch) {
                case '+': {
                    firstOperand = stack.top();
                    stack.pop();
                    secondOperand = stack.top();
                    stack.pop();
                    stack.push(firstOperand + secondOperand);
                    break;
                }
                case '-': {
                    if (iss >> nextCh) {
                        if (std::isdigit(nextCh)) {
                            iss.putback(nextCh);
                            iss.putback(ch);
                            iss >> operand;
                            stack.push(operand);
                            break;
                        } else if (std::isalpha(nextCh)) {
                            stack.push(-variablesMap[nextCh]);
                            break;
                        }
                    }
                    secondOperand = stack.top();
                    stack.pop();
                    firstOperand = stack.top();
                    stack.pop();
                    stack.push(firstOperand - secondOperand);
                    break;
                }
                case '*': {
                    firstOperand = stack.top();
                    stack.pop();
                    secondOperand = stack.top();
                    stack.pop();
                    stack.push(firstOperand * secondOperand);
                    break;
                }
                case '/': {
                    secondOperand = stack.top();
                    stack.pop();
                    firstOperand = stack.top();
                    stack.pop();
                    stack.push(firstOperand / secondOperand);
                    break;
                }
                case '=': {
                    firstOperand = stack.top();
                    stack.pop();
                    secondOperand = stack.top();
                    stack.pop();
                    stacks.push(std::make_pair(firstOperand == secondOperand, std::stack<int>()));
                    break;
                }
                case '<': {
                    secondOperand = stack.top();
                    stack.pop();
                    firstOperand = stack.top();
                    stack.pop();
                    stacks.push(std::make_pair(firstOperand < secondOperand, std::stack<int>()));
                    break;
                }
                case '?': {
                    bool result = stacks.top().first;
                    secondOperand = stack.top();
                    stack.pop();
                    firstOperand = stack.top();
                    stack.pop();
                    stacks.pop();
                    std::stack<int>& currentStack = stacks.top().second;
                    (result) ? currentStack.push(firstOperand) : currentStack.push(secondOperand);
                }
                default: {
                    if (std::isdigit(ch)) {
                        iss.putback(ch);
                        iss >> operand;
                        stack.push(operand);
                    } else if (std::isalpha(ch)) {
                        stack.push(variablesMap[ch]);
                    }
                }
            }
        }
        std::stack<int> stack = stacks.top().second;
        std::cout << stack.top() << std::endl;
    }
    return 0;
}