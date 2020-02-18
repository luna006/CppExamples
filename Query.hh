#ifndef QUERY_HH
#define QUERY_HH

#include "QueryBase.hh"

class Query {
    friend Query operator~(const Query& query);
    friend Query operator|(const Query& firstQuery, const Query& secondQuery);
    friend Query operator&(const Query& firstQuery, const Query& secondQuery);
public:
    Query(const std::string& word);
    TextQuery::Result eval(const TextQuery& textQuery) const {
        return query->eval(textQuery);
    }
    std::string rep() const {
        return query->rep();
    }
private:
    Query(std::shared_ptr<QueryBase> query) : query(query) {}
    std::shared_ptr<QueryBase> query;
};

std::ostream& operator<<(std::ostream& os, const Query& query);

#endif