#ifndef DATABASE_PROG_IDATA_H
#define DATABASE_PROG_IDATA_H

#include <string>
#include <vector>

enum WHERE_USE {
    CAFE,
    DINING_ROOM
};

enum TYPE_BUILDING {
    GZ,
    ULK,
    SK,
};

struct IDataManager {
    virtual std::vector<std::pair<std::string, std::string>> get_cols_sql() = 0;
    virtual std::vector<std::string> get_cols() = 0;
};

#endif //DATABASE_PROG_IDATA_H
