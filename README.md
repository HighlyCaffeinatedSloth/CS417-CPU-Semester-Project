
#CS417 Semester Project

The purpose of this project is to analyze raw CPU temperature data parsed from a log file and calculate the peicewise linear interpolation and global linear least squares formula of the trend.

**Table of Contents**

[TOCM]

[TOC]

## Prerequisites
The items below are required to compile and run the software.
###C++17
A c++17 complier is required. Both g++ and Clang++ are tested to work.
###Eigen 3
The Eigen library for c++ is used for precision matrix and vector mathematics. It can be found [here](http://eigen.tuxfamily.org/index.php?title=Main_Page "here") or alternatively installed using:


`$ apt-get install libeigen3-dev`


##Buliding
The included makefile assumes many things, specifically:
- Clang++ version 4 or lower is used.

	The CFLAG `-std=c++1z` and LDLIB `-lstdc++fs` are set because the program utilizes the C++17 experimental filesystem that was not finalized for Clang 4 and lower.

- You are compiling this on a *nix system

	The makefile uses `-I/usr/include/eigen3/Eigen` to find the required librarys not included.

With this in mind the program can be compiled by invoking:

`$ make -f makefile`

##Running the project
The program runs from the command line. It accepts arguments pointing to the text files containing the temperature data.

`./CS417SP file1.txt`

It can also accept multiple files at once:

`./CS417SP file1.txt file2.txt`

Basic file validation is done to ensure the given input actually exist.
###Input

The program assumes the input data takes the form of temperatures in a txt file as folows:

    +61.0°C +63.0°C +50.0°C +58.0°C
    +80.0°C +81.0°C +68.0°C +77.0°C
    +62.0°C +63.0°C +52.0°C +60.0°C
    +83.0°C +82.0°C +70.0°C +79.0°C
    +68.0°C +69.0°C +58.0°C +65.0°C

Characters not in the language {0-9;. } are removed as the file is parsed.

###Output

The software creates one output file per core per dataset that follow the following nomenclature:

TemperatureData{file number}_Core{core number}

The output is formatted as follows

`xk <= x < xk+1; yi = c0 + c1x ; type`

Where:
- xk and xk+1 are the domain in which yk is applicable
- yk is the kth function
- type is either least-squares or interpolation

##Authors
- Cody Nicolaou - April 2019

## Acknowlegements
- The [Eigen Project](http://eigen.tuxfamily.org/index.php?title=Main_Page "Eigen Project")
-  Thomas Kennedy Ph.D - Old Dominion University
