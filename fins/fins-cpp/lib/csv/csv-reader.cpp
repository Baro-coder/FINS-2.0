#include "csv-reader.hpp"

CSVReader::CSVReader(std::string filename, char delimiter)
{
    this->filename = filename;
    this->delimiter = delimiter;
    this->columns = 0;
    this->rows = 0;
    this->headers.clear();
    this->content.clear();
}

int CSVReader::read()
{    
    std::vector<std::string> row;
    std::string line, word;

    std::fstream file (this->filename, std::ios::in);

    if(file.is_open())
    {
        this->headers.clear();

        getline(file, line);
        std::stringstream str(line);
        while(getline(str, word, this->delimiter))
            this->headers.push_back(word);
        
        this->columns = this->headers.size();

        this->content.clear();

        while(getline(file, line))
        {
            row.clear();

            std::stringstream str(line);

            while(getline(str, word, this->delimiter))
                row.push_back(word);
            
            content.push_back(row);
        }
        this->rows = this->content.size();

        return 0;
    }
    else
    {
        return 1;
    }
}

void CSVReader::printContent()
{
    int i, j;

    std::cout << "File:     " << this->filename << std::endl;
    std::cout << "Rows:     " << this->rows << std::endl;
    std::cout << "Columns:  " << this->columns << std::endl << std::endl;

    // Headers
    for (i = 0; i < this->columns; i++)
    {
        std::cout << this->headers[i] << "\t";
    }
    std::cout << std::endl;

    std::cout << "---------------------------------------------------" << std::endl;

    // Content
    for (i = 0; i < this->rows; i++)
    {
        for(j = 0; j < this->columns; j++)
        {
            std::cout << this->content[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> CSVReader::getHeaders()
{
    return this->headers;
}

std::vector<std::vector<std::string>> CSVReader::getContent()
{
    return this->content;
}

std::vector<std::string> CSVReader::getRow(int row)
{
    std::vector<std::string> data;
    data.clear();

    if (row >= 0 && row < this->rows && this->rows != 0)
    {
        data = this->content[row];
    }
    
    return data;
}

std::vector<std::string> CSVReader::getColumn(int column)
{
    std::vector<std::string> data;
    data.clear();

    if (column >= 0 && column < this->columns && this->columns != 0)
    {
        for (int i = 0; i < this->rows; i++)
        {
            data.push_back(this->content[i][column]);
        }
    }

    return data;
}

std::vector<std::string> CSVReader::getColumn(std::string header)
{
    int column = -1;
    for(int i = 0; i < this->columns; i++)
    {
        if (header == this->headers[i]){
            column = i;
            break;
        }
    }

    return this->getColumn(column);
}


int CSVReader::getColumnsCount()
{
    return this->columns;
}

int CSVReader::getRowsCount()
{
    return this->rows;
}