#include "fins.hpp"

/* *** Globals *** */

//  ** CSV Handlers
CSVReader *readerGyro, *readerAcc, *readerAlt, *readerBearing;
CSVWriter *writerAngles, *writerAccFil, *writerAccCmp, *writerVel, *writerVelCmp, *writerGps;

// ** Filters
KalmanFilter *kalman;       // Kalman Filter Handler   
MadgwickFilter *madgwick;   // Madgwick Filter Handler

/* ============================================================================================================ */

/* *** Functions *** */

int initCSVHandlers()
{
    // CSV Readers init
    std::cout << "  * CSV Readers init:" << std::endl;
    std::cout << "    - Gyro:       ";
    readerGyro      = new CSVReader(filenameNormDataGyro, CSV_DELIMITER);
    std::cout << "OK" << std::endl;

    std::cout << "    - Acc:        ";
    readerAcc       = new CSVReader(filenameNormDataAcc, CSV_DELIMITER);
    std::cout << "OK" << std::endl;

    std::cout << "    - Alt:        ";
    readerAlt       = new CSVReader(filenameNormDataAlt, CSV_DELIMITER);
    std::cout << "OK" << std::endl;
    
    std::cout << "    - Bearing:    ";
    readerBearing   = new CSVReader(filenameNormDataBearing, CSV_DELIMITER);
    std::cout << "OK" << std::endl << std::endl;

    // CSV Writers init
    std::cout << "  * CSV Writers init:" << std::endl;
    std::cout << "    - Angles:     ";
    writerAngles    = new CSVWriter(filenameProcDataAngles, CSV_DELIMITER);
    if (writerAngles->init(headersAngles) != 0) {
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    std::cout << "OK" << std::endl;

    std::cout << "    - AccFil:     ";
    writerAccFil    = new CSVWriter(filenameProcDataAccFil, CSV_DELIMITER);
    if (writerAccFil->init(headersAccFil) != 0){
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    std::cout << "OK" << std::endl;

    std::cout << "    - AccCmp:     ";
    writerAccCmp    = new CSVWriter(filenameProcDataAccCmp, CSV_DELIMITER);
    if (writerAccCmp->init(headersAccCmp) != 0){
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    std::cout << "OK" << std::endl;

    std::cout << "    - Vel:        ";
    writerVel       = new CSVWriter(filenameProcDataVel, CSV_DELIMITER);
    if (writerVel->init(headersVel) != 0){
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    std::cout << "OK" << std::endl;

    std::cout << "    - VelCmp:     ";
    writerVelCmp    = new CSVWriter(filenameProcDataVelCmp, CSV_DELIMITER);
    if (writerVelCmp->init(headersVelCmp) != 0){
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    std::cout << "OK" << std::endl;

    std::cout << "    - GPS:        ";
    writerGps       = new CSVWriter(filenameProcDataGps, CSV_DELIMITER);
    if (writerGps->init(headersGps) != 0){
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    std::cout << "OK" << std::endl;

    return 0;
}

int initFilters()
{
    std::cout << "  * Kalman:       ";
    kalman = new KalmanFilter();
    if(kalman->init() != 0) {
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    std::cout << "OK" << std::endl;

    std::cout << "  * Madgwick:     ";
    madgwick = new MadgwickFilter();
    if(madgwick->init() != 0) {
        std::cout << "FAIL" << std::endl;
        return 1;
    }
    std::cout << "OK" << std::endl;

    return 0;
}

/* ============================================================================================================ */

/* *** Main Drive *** */

int main(int argc, char **argv)
{
    /* *** INIT ****/
    //  ** CSV Handlers
    std::cout << "CSV Handlers init..." << std::endl;
    if(initCSVHandlers() != 0) {
        std::cout << std::endl << "CSV Handlers Init Fail!" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "  Done." << std::endl << std::endl;

    //  ** Filters
    std::cout << "Filters init..." << std::endl;
    if (initFilters() != 0) {
        std::cout << std::endl << "Filters Init Fail!" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "  Done." << std::endl << std::endl;

    /* *** READING *** */
    std::cout << "Data reading..." << std::endl;

    std::cout << "  Done." << std::endl << std::endl;

    /* *** PROCESSING *** */
    std::cout << "Data processing..." << std::endl;

    std::cout << "  Done." << std::endl << std::endl;

    /* *** STORING *** */
    std::cout << "Data storing..." << std::endl;

    std::cout << "  Done." << std::endl << std::endl;

    return EXIT_SUCCESS;
}