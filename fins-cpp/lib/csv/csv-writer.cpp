#include "csv-writer.hpp"

CSVWriter::CSVWriter(std::string filename, char delimiter)
{
    this->filename = filename;
    this->delimiter = delimiter;
    this->columns = 0;
    this->writtenRows = 0;
    this->headers.clear();
}

int CSVWriter::init(std::vector<std::string> headers)
{
    this->headers = headers;
    this->columns = headers.size();

    std::fstream file (this->filename, std::ios::out);
    if (file.is_open())
    {
        for (int i = 0; i < this->columns; i++)
        {
            file << this->headers[i];
            if (i < this->columns - 1)
                file << this->delimiter;
        }
        file << std::endl;
        return 0;
    }
    else
    {
        return 1;
    }
}

int CSVWriter::write(std::vector<std::string> row)
{
    if (row.size() != this->columns)
        return 1;

    std::fstream file (this->filename, std::ios::app);
    if (file.is_open())
    {
        for (int i = 0; i < this->columns; i++)
        {
            file << row[i];
            if(i < this->columns - 1)
                file << this->delimiter;
        }
        file << std::endl;

        this->writtenRows++;
        return 0;
    }
    else
        return 1;
}

int CSVWriter::getWrittenRowsCount()
{
    return this->writtenRows;
}