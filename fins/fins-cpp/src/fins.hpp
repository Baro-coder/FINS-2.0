#ifndef FINSCPP_HNAME
#define FINSCPP_HNAME fins

/* *** Libraries *** */
// ** Built-in **
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// ** CUSTOM **
#include <csv/csv.hpp>              // CSV file handlers: reader, writer
#include <filters/filters.hpp>      // Filters: Kalman, Madgwick
#include <geo/geo.hpp>              // Geo calculation, Grids representation
#include <vel/vel.hpp>              // Velocity estimator

/* ============================================================================================================ */

/* *** Definitions *** */
#define GPS_START_LAT 48.5467007  // Starting point GPS lattitude
#define GPS_START_LON 35.1016993  // Starting point GPS longitude

/* ============================================================================================================ */

/* *** Constants *** */

//  ** CSV Files **
#define CSV_DELIMITER ','

//   * INPUT FILES *
//  Filenames
std::string normDataDir = "/home/bszyk/Projects/FINS/data/norm/";   // Normalized data directory
std::string filenameNormDataGyro = normDataDir + "gyro.csv";        // Normalized gyroscope data        - input filename
std::string filenameNormDataAcc  = normDataDir + "acc.csv";         // Normalized accelerometer data    - input filename
std::string filenameNormDataAlt  = normDataDir + "alt.csv";         // Normalized altitude data         - input filename
std::string filenameNormDataBearing  = normDataDir + "bearing.csv"; // Normalized bearing data          - input filename

//   * OUTPUT FILES *
//  Filenames
std::string procDataDir = "/home/bszyk/Projects/FINS/data/proc/";   // Processed data directory
std::string filenameProcDataAngles  = procDataDir + "angles.csv";   // Processed angles (pitch, roll) data          - output filename
std::string filenameProcDataAccFil  = procDataDir + "acc.csv";      // Processed filetered accelerometer data       - output filename
std::string filenameProcDataAccCmp  = procDataDir + "accCmp.csv";   // Processed compensated accelerometer data     - output filename
std::string filenameProcDataVel     = procDataDir + "vel.csv";      // Processed velocities data                    - output filename
std::string filenameProcDataVelCmp  = procDataDir + "velCmp.csv";   // Processed compansated velocity data          - output filename
std::string filenameProcDataGps     = procDataDir + "gps.csv";      // Processed GPS data                           - output filename

// Headers
std::vector<std::string> headersAngles  {"timestamp", "pitch", "roll", "yaw"};
std::vector<std::string> headersAccFil  {"timestamp", "accFilX", "accFilY", "accFilZ"};
std::vector<std::string> headersAccCmp  {"timestamp", "accCmpX", "accCmpY", "accCmpZ"};
std::vector<std::string> headersVel     {"timestamp", "velX", "velY", "velZ", "vel"};
std::vector<std::string> headersVelCmp  {"timestamp", "velCmpX", "velCmpY", "velCmpZ", "velCmp"};
std::vector<std::string> headersGps     {"timestamp", "lattitude", "longitude"};

/* ============================================================================================================ */

/* *** Structures *** */


/* ============================================================================================================ */

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

/* ============================================================================================================ */

/* *** Functions *** */

// Initialize CSV readers and writers
//  Returns `0` on success and `1` on errors
int initCSVHandlers();

// Initialize Kalman and Madgwick filters
//  Returns `0` on success and `1` on errors
int initFilters();

#endif