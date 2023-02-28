#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "fins.hpp"

/* *** PROCEDURE ***

    1. Get input data from CSV files.

    2. Process data row by row:

        2.1. Filter Gyro, Accel data.

        2.2. Calculate roll, pitch angles.

        2.3. Compensate gravity from accel data.

        2.4. ??? Compensate wind ???

        2.5. Calculate component velocities X, Y, Z

        2.6. Integrate it into linear velocity.

        2.7. Calculate displacement vector.

        2.8. Calculate current Geo Localization.

    3. Store every step calculation into certain CSV file.
*/


int main(int argc, char **argv)
{
    // Filenames
    std::string normGeoFilename = "/home/bszyk/Projects/FINS/data/norm/geo.csv";
    std::string procGeoFilename = "/home/bszyk/Projects/FINS/data/proc/geo.csv";

    // CSV Handlers
    CSVReader *normGeoReader = new CSVReader(normGeoFilename, ',');
    CSVWriter *procGeoWriter = new CSVWriter(procGeoFilename, ',');

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