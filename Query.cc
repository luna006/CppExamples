#include "Query.hh"
#include "WordQuery.hh"

Query::Query(const std::string& word) : query(new WordQuery(word)) {}

std::ostream& operator<<(std::ostream& os, const Query& query) {
    os << query.rep();
    return os;
}