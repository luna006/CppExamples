#include "OrQuery.hh"

TextQuery::Result OrQuery::eval(const TextQuery& textQuery) const {
    TextQuery::Result leftResult = leftQuery.eval(textQuery);
    TextQuery::Result rightResult = rightQuery.eval(textQuery);
    std::shared_ptr<std::set<lineNo>> result = std::make_shared<std::set<lineNo>>(leftResult.cbegin(), leftResult.cend());
    result->insert(rightResult.cbegin(), rightResult.cend());
    return TextQuery::Result(rep(), result, leftResult.getFile());
}