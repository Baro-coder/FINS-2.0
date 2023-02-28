#!/bin/bash

# DIRECTORIES
#   Getting script directory
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )     
#   Getting FINS root directory
WORKDIR=${SCRIPT_DIR%/*}

DIR_TOOLS="$WORKDIR"/fins-py/tools/graphs    # Programs dir
DIR_DATA="$WORKDIR"/data                     # Data dir

DIR_NORM="$DIR_DATA"/norm   # Normalized data dir
DIR_PROC="$DIR_DATA"/proc   # Processed  data dir

# PROGRAMS
graphDefPrg="$DIR_TOOLS"/graph_def.py
graphCmpPrg="$DIR_TOOLS"/graph_cmp.py
graphGpsPrg="$DIR_TOOLS"/graph_gps.py

# EXECUTING
#   Default:
#       Norm:   acc, alt, bearing, gyro, speed
#       Proc:   acc, accCmp, angles, vel, velCmp
#   
#   GPS:
#       Norm:   gps
#       Proc:   gps

# ARRAYS
filesDef=()     # CSV files to generate default graph
filesCmp=()     # CSV files to generate graph of compare
filesGps=()     # CSV files to generate graph of GPS

# COLLECT
printf " Collecting data..."

for entry in "$DIR_NORM"/*
do
    if [ ${entry##*.} == "csv" ]; then
        if [ ${entry##*/} == "gps.csv" ]; then
                filesGps+=("$entry")
        else
                filesDef+=("$entry")
        fi
    fi
done

for entry in "$DIR_PROC"/*
do
    if [ ${entry##*.} == "csv" ]; then
        if [ ${entry##*/} == "gps.csv" ]; then
                filesGps+=("$entry")
        else
                filesDef+=("$entry")
        fi
    fi
done

echo "  Done."
echo

# Collection summary
echo " Collection:"
echo "   Default Graphs:"
for var in "${filesDef[@]}"
do
  echo "     * ${var}"
done

echo

echo "   GPS Graphs:"
for var in "${filesGps[@]}"
do
  echo "     * ${var}"
done

echo

# PROCESS
echo " Generating graphs..."
printf "   Defaults :       "
for var in "${filesDef[@]}"
do
    python $graphDefPrg $var > /dev/null 2> /dev/null &
done
echo " Done"

# printf "   Comparisons :    "
#   TODO: ...
# echo "Done"

printf "   GPS :            "
for var in "${filesGps[@]}"
do
    # echo "python $plotGpsProgram $var > /dev/null 2> /dev/null &"
    python $graphGpsPrg $var > /dev/null 2> /dev/null &
done
echo " Done"

printf "   GPS Comparison:  "
# echo "python $graphGpsPrg ${filesGps[0]} ${filesGps[1]} > /dev/null 2> /dev/null &"
python $graphGpsPrg ${filesGps[0]} ${filesGps[1]} > /dev/null 2> /dev/null &
echo " Done"

exit 0