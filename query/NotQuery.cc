#include "NotQuery.hh"

TextQuery::Result NotQuery::eval(const TextQuery& textQuery) const {
    TextQuery::Result queryResult = query.eval(textQuery);
    std::shared_ptr<std::set<lineNo>> result = std::make_shared<std::set<lineNo>>();
    auto numberLinesInFile = queryResult.getFile()->size();
    auto iter = queryResult.cbegin();
    for (std::size_t i = 0; i < numberLinesInFile; i++) {
        if (iter == queryResult.cend() || *iter != i) {
            result->insert(i);
        } else if (iter != queryResult.cend()) {
            ++iter;
        }
    }
    return TextQuery::Result(rep(), result, queryResult.getFile());
}