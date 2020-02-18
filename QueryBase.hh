#ifndef QUERY_BASE_HH
#define QUERY_BASE_HH

#include "TextQuery.hh"

class QueryBase {
    friend class Query;
protected:
    using lineNo = TextQuery::lineNo;
    virtual ~QueryBase() = default;
private:
    virtual TextQuery::Result eval(const TextQuery& textQuery) const = 0;
    virtual std::string rep() const = 0;
};

#endif