#pragma once
#include "CSVRow.h"

class CSVIterator
{
private:
    std::istream* m_str;
    CSVRow              m_row;

public:
    typedef std::input_iterator_tag     iterator_category;
    typedef CSVRow                      value_type;
    typedef std::size_t                 difference_type;
    typedef CSVRow* pointer;
    typedef CSVRow& reference;

    CSVIterator(std::istream& str);
    CSVIterator();

    // Pre Increment
    CSVIterator& operator++();
    // Post increment
    CSVIterator operator++(int);
    CSVRow const& operator*()   const;
    CSVRow const* operator->()  const;

    bool operator==(CSVIterator const& rhs);
    bool operator!=(CSVIterator const& rhs);
};

