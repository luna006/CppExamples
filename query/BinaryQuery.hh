#ifndef BINARY_QUERY_HH
#define BINARY_QUERY_HH

#include "Query.hh"

class BinaryQuery : public QueryBase {
protected:
    BinaryQuery(const Query& leftQuery, const Query& rightQuery, const std::string& operatorName) :
                leftQuery(leftQuery), rightQuery(rightQuery), operatorName(operatorName) {}

    std::string rep() const override {
        return "(" + leftQuery.rep() + " " + operatorName + " " + rightQuery.rep() + ")";
    }

    const Query leftQuery;
    const Query rightQuery;
    const std::string operatorName;
};

#endif // !BINARY_QUERY_HH