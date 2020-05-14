#ifndef NOT_QUERY_HH
#define NOT_QUERY_HH

#include "Query.hh"
#include <iostream>

class NotQuery : public QueryBase {
    friend Query operator~(const Query& query);
private:
    NotQuery(const Query& query) : query(query) {}
    TextQuery::Result eval(const TextQuery& textQuery) const override;
    std::string rep() const override {
        return "~(" + query.rep() + ")";
    }

    const Query query;
};

inline Query operator~(const Query& query) {
    return std::shared_ptr<QueryBase>(new NotQuery(query));
}

#endif // !NOT_QUERY_HH