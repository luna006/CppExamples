#ifndef AND_QUERY_HH
#define AND_QUERY_HH

#include "BinaryQuery.hh"

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query& left, const Query& right);

    AndQuery(const Query& leftQuery, const Query& rightQuery) : BinaryQuery(leftQuery, rightQuery, "&") {}
    TextQuery::Result eval(const TextQuery& textQuery) const override;
};

inline Query operator&(const Query& left, const Query& right) {
    return std::shared_ptr<QueryBase>(new AndQuery(left, right));
}

#endif // !AND_QUERY_HH