#ifndef FINSCPP_HNAME
#define FINSCPP_HNAME fins

/* *** Libraries *** */
// ** CUSTOM **
#include <csv/csv.hpp>              // CSV file handlers
#include <filters/filters.hpp>      // Filters: Kalman, Madgwick
#include <geo/geo.hpp>              // Geo calculation, Grids representation
#include <vel/vel.hpp>              // Velocity estimator


/* *** Definitions *** */

// ** INPUT FILES **
const char *filenameRawDataGyro = "/home/bszyk/Projects/FINS/data/raw/gyro.csv";    // Raw gyroscope data - filename
const char *filenameRawDataAcc = "/home/bszyk/Projects/FINS/data/raw/acc.csv";      // Raw accelerometer data - filename
const char *filenameRawDataAlt = "/home/bszyk/Projects/FINS/data/raw/alt.csv";      // Raw altitude data - filename

// ** OUTPUT FILES **
const char *filenameProcDataGyro = "/home/bszyk/Projects/FINS/data/proc/gyro.csv";      // Processed gyroscope data - filename
const char *filenameProcDataAcc = "/home/bszyk/Projects/FINS/data/proc/acc.csv";        // Processed accelerometer data - filename
const char *filenameProcDataAccCmp = "/home/bszyk/Projects/FINS/data/proc/accCmp.csv";  // Compensated accelerometer data - filename
const char *filenameProcDataGeo = "/home/bszyk/Projects/FINS/data/proc/geo.csv";        // Calculated Geo Localization data - filename


/* *** Structures *** */



/* *** Functions *** */


#endif