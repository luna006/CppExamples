#include <algorithm>
#include <iterator>
#include "AndQuery.hh"

TextQuery::Result AndQuery::eval(const TextQuery& textQuery) const {
    TextQuery::Result leftResult = leftQuery.eval(textQuery);
    TextQuery::Result rightResult = rightQuery.eval(textQuery);
    std::shared_ptr<std::set<lineNo>> result = std::make_shared<std::set<lineNo>>();
    std::set_intersection(leftResult.cbegin(), leftResult.cend(),
                          rightResult.cbegin(), rightResult.cend(),
                          std::inserter(*result, result->begin()));
    return TextQuery::Result(rep(), result, leftResult.getFile());
}