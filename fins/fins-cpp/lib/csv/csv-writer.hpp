#ifndef CSVWRITER_HNAME 
#define CSVWRITER_HNAME csv-writer

/* *** Required libraries *** */
#include_next <iostream>
#include_next <fstream>
#include_next <string>
#include_next <vector>


/* *** Class Definition *** */
// CSV Writer class
class CSVWriter
{
private:
    std::string filename; // CSV filename
    char delimiter; // Delimiter character

    int columns;        // Columns count
    int writtenRows;    // Written rows counter

    std::vector<std::string> headers;  // CSV Headers

public:
    CSVWriter(std::string filename, char delimiter);

    // Initialize output file
    //  Return `0` on success or `1` on errors
    int init(std::vector<std::string> headers);

    // Write `row` into csv file
    //  Return `0` on success or `1` on errors
    int write(std::vector<std::string> row);

    // Get written rows count
    int getWrittenRowsCount();
};

#endif