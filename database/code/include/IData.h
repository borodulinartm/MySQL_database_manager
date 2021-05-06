#ifndef DATABASE_PROG_IDATA_H
#define DATABASE_PROG_IDATA_H

#include <string>
#include <vector>

struct wrapper {
    virtual std::vector<std::pair<std::string, std::string>> get_cols_sql() = 0;
    virtual std::vector<std::string> get_cols() = 0;
};

#endif //DATABASE_PROG_IDATA_H
