#ifndef CSVREADER_HNAME 
#define CSVREADER_HNAME csv-reader

/* *** Required libraries *** */
#include_next <iostream>
#include_next <fstream>
#include_next <string>
#include_next <vector>
#include_next <sstream>

/* *** Class Definition *** */
// CSV Reader class
class CSVReader
{
private:
    std::string filename; // CSV filename
    char delimiter; // Delimiter character

    int columns;    // Columns count
    int rows;       // Row count

    std::vector<std::string> headers;               // CSV Headers
    std::vector<std::vector<std::string>> content;  // Content Matrix

public:
    CSVReader(std::string filename, char delimiter);

    // Read CSV file and store content into `headers`, `content`
    //  Returns `0` on success and `1` on errors
    int read();

    // Prints read CSV content to `STDOUT`
    void printContent();

    // Get headers
    std::vector<std::string> getHeaders();

    // Get content
    std::vector<std::vector<std::string>> getContent();

    // Get specified row with index `row`
    std::vector<std::string> getRow(int row);

    // Get specified column data with index `column`
    std::vector<std::string> getColumn(int column);
    // Get specified column data below header `header`
    std::vector<std::string> getColumn(std::string header);

    // Get Columns Count
    int getColumnsCount();
    // Get Rows Count (excluded headers row)
    int getRowsCount();
};

#endif