#include "CSVRange.h"

CSVIterator CSVRange::begin() const { return CSVIterator{ stream }; }
CSVIterator CSVRange::end()   const { return CSVIterator{}; }
CSVRange::CSVRange(std::istream& str): stream(str){}