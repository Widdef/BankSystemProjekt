#pragma once
#include "CSVIterator.h"


class CSVRange
{
private:
    std::istream& stream;
public:
    CSVRange(std::istream&);
    CSVIterator begin() const;
    CSVIterator end()   const;
};


