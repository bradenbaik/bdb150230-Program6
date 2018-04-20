// Braden Baikauskas
// email: bdb150230
// CS 3377.501
// 23221
// header file for program 6
#ifndef _PROGRAM6_H_
#define _PROGRAM6_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cdk.h>
#include <ncurses.h>
#include <cstdint>
#include <stdint.h> // so I can use uint32_t and the others

using namespace std;
//using namespace  std::uint32_t;

class BinaryFileHeader // holds the Binary file header information
{
 public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

const  int maxRecordStringLength = 25; // the max length a string can be is 24 the last spot has to be null term

class BinaryFileRecord // holds a string in the binary file and its length
{
 public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};


#endif /* _PROGRAM6_H_ */
