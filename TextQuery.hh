#ifndef TEXT_QUERY_HH
#define TEXT_QUERY_HH

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>

class TextQuery {
public:
    using lineNo = std::vector<std::string>::size_type;

    class Result {
        friend std::ostream& operator<<(std::ostream& os, const TextQuery::Result& queryResult);

    public:
        Result(const std::string& word,
               const std::shared_ptr<std::set<lineNo>> lineNumbers,
               const std::shared_ptr<std::vector<std::string>> textLines) :
               word(word), lineNumbers(lineNumbers), textLines(textLines) {}
        std::set<lineNo>::iterator begin();
        std::set<lineNo>::const_iterator cbegin() const;
        std::set<lineNo>::iterator end();
        std::set<lineNo>::const_iterator cend() const;

        std::shared_ptr<std::vector<std::string>> getFile() const;

    private:
        const std::string word;
        const std::shared_ptr<std::set<lineNo>> lineNumbers;
        const std::shared_ptr<std::vector<std::string>> textLines;
    };

    TextQuery(std::ifstream& fileStream);
    Result query(const std::string& word) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<lineNo>>> wordMap;
};

std::ostream& operator<<(std::ostream& os, const TextQuery::Result& queryResult);

#endif