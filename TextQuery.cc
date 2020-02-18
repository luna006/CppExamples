#include <sstream>
#include "TextQuery.hh"

static std::string makePlural(const std::size_t count, const std::string& word, const std::string ending);

TextQuery::TextQuery(std::ifstream& fileStream) : file(new std::vector<std::string>) {
    std::string textLine;
    while (std::getline(fileStream, textLine)) {
        file->push_back(textLine);
        lineNo n = file->size() - 1;
        std::istringstream strStream(textLine);
        std::string word;
        while (strStream >> word) {
            auto& lineNumbers = wordMap[word];
            if (!lineNumbers) {
                lineNumbers.reset(new std::set<lineNo>);
            }
            lineNumbers->insert(n);
        }
    }
}

TextQuery::Result TextQuery::query(const std::string& word) const {
    static const std::shared_ptr<std::set<lineNo>> noData {new std::set<lineNo>};
    auto foundLines = wordMap.find(word);
    if (foundLines == wordMap.cend()) {
        return Result(word, noData, file);
    } else {
        return Result(word, foundLines->second, file);
    }
}

std::set<TextQuery::lineNo>::iterator TextQuery::Result::begin() {
    return lineNumbers->begin();
}

std::set<TextQuery::lineNo>::const_iterator TextQuery::Result::cbegin() const {
    return lineNumbers->cbegin();
}

std::set<TextQuery::lineNo>::iterator TextQuery::Result::end() {
    return lineNumbers->end();
}

std::set<TextQuery::lineNo>::const_iterator TextQuery::Result::cend() const {
    return lineNumbers->cend();
}

std::shared_ptr<std::vector<std::string>> TextQuery::Result::getFile() const {
    return textLines;
}

std::ostream& operator<<(std::ostream& os, const TextQuery::Result& queryResult) {
    os << queryResult.word << " occurs " << queryResult.lineNumbers->size() << " "
       << makePlural(queryResult.lineNumbers->size(), "time", "s") << std::endl;
    for (auto number : *(queryResult.lineNumbers)) {
        os << "\t(line " << number + 1 << ") "
           << *(queryResult.textLines->cbegin() + number) << std::endl;
    }
    return os;
}

static std::string makePlural(const std::size_t count, const std::string& word, const std::string ending) {
    return (count > 1) ? word + ending : word;
}