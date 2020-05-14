#include <iostream>
#include <fstream>
#include <string>
#include "Query.hh"
#include "NotQuery.hh"

void runQueries(std::ifstream& infile);

int main(int argc, char const *argv[])
{
    std::ifstream istream("./text", std::ios::in);
    if (!istream.is_open()) {
        std::exit(1);
    } else {
        runQueries(istream);
    }
    return 0;
}

void runQueries(std::ifstream& infile) {
    TextQuery textQuery(infile);
    Query query1("Jenkins");
    Query query2("job");
    Query query = (~query1) & query2;
    std::cout << query.eval(textQuery) << std::endl;
    /*while (true) {
        std::cout << "Enter word to look for, or 'q' to quit: ";
        std::string word;
        if (!(std::cin >> word) || word == "q") {
            break;
        }
        Query query(word);
        std::cout << query.eval(textQuery) << std::endl;
    }*/
}
