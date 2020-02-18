#ifndef WORD_QUERY_HH
#define WORD_QUERY_HH

#include "QueryBase.hh"

class WordQuery : public QueryBase {
    friend class Query;
private:
    WordQuery(const std::string& queryString) : queryString(queryString) {}
    TextQuery::Result eval(const TextQuery& textQuery) const override {
        return textQuery.query(queryString);
    }
    std::string rep() const override {
        return queryString;
    }


    const std::string queryString;
};

#endif // !WORD_QUERY_HH