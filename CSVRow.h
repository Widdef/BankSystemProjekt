#pragma once
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string>


class CSVRow
{
private:
    std::string         m_line;
    std::vector<int>    m_data;
public:
    std::string operator[](std::size_t index) const;
    std::size_t size() const;
    void readNextRow(std::istream&);
};

#if !defined(CSV_HANDLERS_OPERATORS)
#define CSV_HANDLERS_OPERATORS true
inline std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}
#endif
