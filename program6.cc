/*
 * Braden Baikauskas
 * email: bdb150230
 * CS 3377.501
 * 23221
 * 
 */

//#include <iostream>
//#include <cdk.h>
//#include <ncurses.h>
#include "program6.h"
//#include <cdk/draw.h>
//#include <cdk/matrix.h>
#define MATRIX_WIDTH 3 // number of columns
#define MATRIX_HEIGHT 5 // number of rows
#define BOX_WIDTH 20 // size of box
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;


int main()
{
  char bufferMagicNum[32]; // buffer for the magic number
  char bufferVersion[32]; // buffer for the version number
  char bufferNumRecord[64]; // buffer for the number of records

  WINDOW*window;
  CDKSCREEN*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char *rowTitles[MATRIX_HEIGHT+1] = {"R0", "a", "b", "c", "d", "e"};
  const char *columnTitles[MATRIX_WIDTH+1] = {"C0", "a", "b", "c"};
  int boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
   */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths, boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay info from binary file
   */
  
  string fileName = "cs3377.bin"; // name of the binary file
  ifstream binInfile(fileName, ios::in|ios::binary); // opens binary  file
  BinaryFileHeader *myHeader = new BinaryFileHeader();
  BinaryFileRecord *myRecord = new BinaryFileRecord();
  binInfile.read((char *) myHeader, sizeof(BinaryFileHeader)); /* reads in the binary header file */
  
  snprintf(bufferMagicNum, 32, "Magic: 0x%X", myHeader->magicNumber); /* puts magic number in buffer as hexadecimal */
  snprintf(bufferVersion, 32, "Version: %u", myHeader->versionNumber); /* puts version number into buffer */
  snprintf(bufferNumRecord, 64, "NumRecords: %lu", myHeader->numRecords); /* puts the number of records into the buffer */
  
  // setCDKMatrixCell(myMatrix, 2, 2, "Test Message"); 
  setCDKMatrixCell(myMatrix, 1, 1,bufferMagicNum); /* displays magic number in matrix */
  setCDKMatrixCell(myMatrix, 1, 2, bufferVersion);
  setCDKMatrixCell(myMatrix, 1, 3, bufferNumRecord);
  char bufferStringLen[32];
  // char bufferString[maxRecordStringLength];
  int j = 2; // the row number
  for(unsigned int i = 0; i < myHeader->numRecords && j <= 5; i++){ /* for as long as there are records */
    binInfile.read((char *) myRecord, sizeof(BinaryFileRecord)); /* reads in the record from the binary file */
    snprintf(bufferStringLen, 32, "strlen: %u", myRecord->strLength); /* puts the string length in its buffer */
    setCDKMatrixCell(myMatrix, j, 1, bufferStringLen); // displays string length in jth row 1st column
    setCDKMatrixCell(myMatrix, j, 2, myRecord->stringBuffer); // displays string in jth row 2nd column
    j++; // increments the  row
  }
 
   drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
   cin.get(); // pauses until user presses a key

   // cout << std::hex << myHeader->magicNumber << endl;
  // initscr();
  // getch();
  // endwin();
  // string userInput;
  // cin >> userInput;
  // sleep (10);


  // Cleanup screen
  endCDK();
}
