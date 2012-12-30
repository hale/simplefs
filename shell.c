#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesys.h"

extern char **environ;                   // environment array

/* Your shell.c program should do the following:
 *  - call format() to format the virtual disk
 *  - transfer the following text into block 0: “CS3008 Operating Systems Assessment 2012”
 *  - write the virtual disk to a file (you can call it “virtualdisk9_11”).
 *    Use the unix command “hexdump” to see what the file contains: hexdump –C virtualdisk9_11
 */

int main(int argc, char **argv) {
  /* this is an array of strings */
  char ** env = environ;

  // This while loop checks each *env
  // It loops, until *env points to null
  // while (*env) printf("%s\n",*env++);  // step through environment


  format();

  diskblock_t block;
  strcpy( block.data, "CS3008 Operating Systems Assessment 2012" );
  writeblock(&block, 0);

  printBlock(0);

  writedisk( "virtualdisk9_11" );

  exit(0);

}

