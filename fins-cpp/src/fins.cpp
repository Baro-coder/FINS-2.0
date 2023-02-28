#include "fins.hpp"


int main(int argc, char **argv)
{
    // CSV Handlers
    CSVReader *normGeoReader = new CSVReader(filenameNormDataAcc, ',');
    CSVWriter *procGeoWriter = new CSVWriter(filenameProcDataAccFil, ',');

    // Headers and content
    std::vector<std::string> geoHeaders; 
    std::vector<std::vector<std::string>> normGeoContent;

    // Reading input file
    std::cout << "Input file reading..." << std::endl;
    if (normGeoReader->read() != 0) {
        std::cout << "Could not open the file!" << std::endl;
        return 1;
    }
    std::cout << "Done." << std::endl << std::endl;
    std::cout << "  Summary:" << std::endl;
    std::cout << "    Columns:  " << normGeoReader->getColumnsCount() << std::endl;
    std::cout << "    Rows:     " << normGeoReader->getRowsCount() << std::endl << std::endl;

    geoHeaders = normGeoReader->getHeaders();
    normGeoContent = normGeoReader->getContent();

    // Output file init
    std::cout << "Output file init..." << std::endl;
    if (procGeoWriter->init(geoHeaders) != 0){
        std::cout << "Output file init : Error!" << std::endl;
        return 1;
    }
    std::cout << "Done." << std::endl << std::endl;

    // Data processing and storing into output file
    std::cout << "Data processing..." << std::endl;
    for (int i = 0; i < normGeoContent.size(); i++)
    {
        if (i % 3 == 0)
        {
            procGeoWriter->write(normGeoContent[i]);
        }
    }
    std::cout << "Done." << std::endl << std::endl;
    std::cout << "  Summary:" << std::endl;
    std::cout << "    Written rows:  " << procGeoWriter->getWrittenRowsCount() << std::endl;

    return 0;
}