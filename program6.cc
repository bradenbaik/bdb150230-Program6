/*
 * Braden Baikauskas
 * email: bdb150230
 * CS 3377.501
 * 23221
 * 
 */

#include <iostream>
#include <cdk.h>
#include <ncurses.h>
//#include <cdk/draw.h>
//#include <cdk/matrix.h>
#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 15
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;


int main()
{

  WINDOW*window;
  CDKSCREEN*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char *rowTitles[MATRIX_HEIGHT+1] = {"R0", "R1", "R2", "R3", "R4", "R5"};
  const char *columnTitles[MATRIX_WIDTH+1] = {"C0", "C1", "C2", "C3"};
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
   * Dipslay a message
   */
  setCDKMatrixCell(myMatrix, 2, 2, "Test Message");
  drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
  cin.get();
  // initscr();
  // getch();
  // endwin();
  // string userInput;
  // cin >> userInput;
  // sleep (10);


  // Cleanup screen
  endCDK();
}