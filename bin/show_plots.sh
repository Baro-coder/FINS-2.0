#!/bin/bash

# DIRECTORIES
DIR_PRG=/home/bszyk/Projects/FINS/fins-py/plots     # Programs dir
DIR_DATA=/home/bszyk/Projects/FINS/data             # Data dir
DIR_NORM="$DIR_DATA"/norm                           # Normalized data dir
DIR_PROC="$DIR_DATA"/proc                           # Processed  data dir

# PROGRAMS
plotGpsProgram="$DIR_PRG"/plot_gps.py
plotProgram="$DIR_PRG"/plot.py

# ARRAYS
gpsFiles=()
files=()

# COLLECT
printf " Collecting data..."

for entry in "$DIR_NORM"/*
do
    if [ ${entry##*.} == "csv" ]; then
        if [ ${entry##*/} == "gps.csv" ]; then
                gpsFiles+=("$entry")
        else
                files+=("$entry")
        fi
    fi
done

for entry in "$DIR_PROC"/*
do
    if [ ${entry##*.} == "csv" ]; then
        if [ ${entry##*/} == "gps.csv" ]; then
                gpsFiles+=("$entry")
        else
                files+=("$entry")
        fi
    fi
done

echo "  Done."
echo

# Collection summary
echo " Collection:"
echo "   Files:"
for var in "${files[@]}"
do
  echo "     * ${var}"
done

echo

echo "   GPS Files:"
for var in "${gpsFiles[@]}"
do
  echo "     * ${var}"
done

echo

# PROCESS
echo " Creating plots..."
for var in "${files[@]}"
do
    # echo "python $plotProgram $var > /dev/null 2> /dev/null &"
    python $plotProgram $var > /dev/null 2> /dev/null &
done

for var in "${gpsFiles[@]}"
do
    # echo "python $plotGpsProgram $var > /dev/null 2> /dev/null &"
    python $plotGpsProgram $var > /dev/null 2> /dev/null &
done

echo "  Done."

exit 0