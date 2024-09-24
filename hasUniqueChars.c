/*
 * hasUniqueChars.c
 * 
 * TODO: replace this line with lines containing a description
 * 
 * Author: Quinn Tange
 */

#include <stdio.h>  // fprintf, printf
#include <stdlib.h> // exit() defined here
#include <string.h> // useful string operations
#include <ctype.h>  //useful character operations
#include <stdbool.h>  // to define a boolean type and true, false
                      // see https://en.wikibooks.org/wiki/C_Programming/stdbool.h

#include "binary_convert.h"


/*
 * This function is for debugging by printing out the value
 * of an input insigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text) {
  
  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
  
}

/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char * inputStr) {
  char nextChar;
  int i;
  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ascii char code), then bail out
    if ((nextChar <= 31 ) || (nextChar == 127)) {
      fprintf(stderr, "invalid character in string. It is: %c and input is: %s\n", nextChar,inputStr);
      exit(EXIT_FAILURE);
    }
  }
}


/*
 * This function takes in an input string and checks if all the characters are both unique and a-z | A-Z | a couple other special chars.
 *returns true if conditions are satisfied, otherwise exits with failure.
 * If there is a character with ascii char code <=21 or == 127, it will exit with failure.
 * This line: checkBitsA_z = (checkBitsA_z & ~mask) | (1 << nextChar); found with help of https://www.geeksforgeeks.org/modify-bit-given-position/
 */
bool hasUniqueChars(char * inputStr) {
  // bail out quickly if any invalid characters
  checkInvalid(inputStr);
  
  int i;   // loop counter
  
  // unsigned long can handle 64 different chars in a string
  // if a bit at a position is 1, then we have seen that character
  unsigned long checkBitsA_z = 0;   // for checking A through z and {|}~
  unsigned long checkBitsexcl_amp =0;  // for checking ! though @ 
  unsigned long empty_except_idx =0;

  char nextChar;         // next character in string to check

  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];
    if(nextChar >= 65){
      //Creating a new int with a 1 at index given by the value of nextChar and 0s elsewhere
      int mask = 1 << nextChar;
      //If both the checkBitsA_z and our new int have a 1 at the same place, this boolean is true, and therefore we have found a duplicate
      if(checkBitsA_z & mask){
        fprintf(stderr, "There is a duplicate character! It is: %c and input is: %s\n", nextChar,inputStr);
        return false;
        exit(EXIT_FAILURE);
      }
      checkBitsA_z = (checkBitsA_z & ~mask) | (1 << nextChar);
      char char_str[2] = "\0";
      char_str[0] = nextChar;
    }
    else{
      int mask = 1 << nextChar;
      checkBitsexcl_amp = (checkBitsexcl_amp & ~mask) | (1 << nextChar);
    }
  }

  // if through all the characters, then no duplicates found
  return true;
  
}