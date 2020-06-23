
# CS417 Semester Project

The purpose of this project is to analyze raw CPU temperature data parsed from a log file and calculate the peicewise linear interpolation and global linear least squares formula of the trend.

**Table of Contents**

[TOCM]

[TOC]

## Prerequisites
The items below are required to compile and run the software.
### C++17 (g++ preferred)
A C++17 complier is required. Both g++ and Clang++ are tested to work however, the makefile utilizes g++-8.

`$ apt-get install g++-8`

### Eigen 3.3.7
The Eigen library for c++ is used for precision matrix and vector mathematics. More information on the library can be found [here](http://eigen.tuxfamily.org/index.php?title=Main_Page "here")

The necessary libraries are included in this tar file

### Cmake

`$ apt-get install cmake`

## Buliding
The included makefile assumes:
- g++-8 or higher is used.

	Although filesystem is no longer experimental in GCC 8 it still needs `LFLAGS = -lstdc++fs` set to build correctly.

- You are compiling this on a *nix system

	The makefile targets the included lib folder containing the necessary Eigen dependancies.

With this in mind the program can be compiled by invoking:

`$ make -f makefile`

## Running the project
The program runs from the command line. It accepts arguments pointing to the text files containing the temperature data.

`./CS417SP file1.txt`

It can also accept multiple files at once:

`./CS417SP file1.txt file2.txt`

Basic validation is done to ensure the given input file actually exist.

It is assumed if the file exists it is formatted correctly

### Input

The program assumes the input data takes the form of temperatures in a txt file as folows:

    +61.0°C +63.0°C +50.0°C +58.0°C
    +80.0°C +81.0°C +68.0°C +77.0°C
    +62.0°C +63.0°C +52.0°C +60.0°C
    +83.0°C +82.0°C +70.0°C +79.0°C
    +68.0°C +69.0°C +58.0°C +65.0°C

Characters not in the language {0-9;. } are removed as the file is parsed.

### Output

The software creates one output file per core per dataset that follow the following nomenclature:

{epoch_time}-Temperature-Data-{file number}-Core-{core number}

The output is formatted as follows

`xk <= x < xk+1; yi = c0 + c1x ; type`

Where:
- xk and xk+1 are the domain in which yk is applicable
- yk is the kth function
- type is either least-squares or interpolation

## Authors
- Cody Nicolaou - June 22 2020

## Acknowlegements
- The [Eigen Project](http://eigen.tuxfamily.org/index.php?title=Main_Page "Eigen Project")
-  Thomas Kennedy Ph.D - Old Dominion University
