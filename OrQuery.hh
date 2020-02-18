#ifndef OR_QUERY_HH
#define OR_QUERY_HH

#include "BinaryQuery.hh"

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query& left, const Query& right);
    OrQuery(const Query& leftQuery, const Query& rightQuery) : BinaryQuery(leftQuery, rightQuery, "|") {}
    TextQuery::Result eval(const TextQuery& textQuery) const override;
};

inline Query operator|(const Query& left, const Query& right) {
    return std::shared_ptr<QueryBase>(new OrQuery(left, right));
}

#endif // !OR_QUERY_HH