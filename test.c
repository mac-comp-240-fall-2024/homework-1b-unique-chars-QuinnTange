/*
 * By Quinn Tange
 *A test file containing various tests for HasUniqueChars correctly identying if a string is:
 *made up of letters a-z, A-Z, or various special characters between ASCII 32-127.
 * Known Error: in the starter code for Test 1. assert(!(ok)) is used to identify if the testcase should fail, but 
 * in copying this code, I am not able to see all the other test cases in the terminal because the code exits. I 
 * followed the template, but I'm not sure what the difference is. I am confident my hasUniqueChars method is working
 * correctly but the test cases are not necessarily showing that all at once, you may have to comment some at a time unfortunately.
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  // Test 3: Tests special characters. They are all in the ASCII range 32-127 and none are duplicates of each other, 
  //so if any character fails the test, something is wrong.
  strcpy(string3, "{}!@|~'&$#?><=;;/.,*()");
  ok = hasUniqueChars(string3);
  assert(ok);

  //Test 4: Arbitrary string which should pass.
  strcpy(string3, "a s hdfm,~");
  ok = hasUniqueChars(string3);
  assert(ok);

  //Test 5: repeating character 'a'
  strcpy(string3, "a !@#$a");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  //Test 6: testing more non-ASCII characters
  strcpy(string3, "こんにちわ");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  //Test 7: testing \0
  strcpy(string3, "\0  ");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  //Test 8: testing \r
  strcpy(string3, "\r");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  //Test 9: testing multiple spaces
  strcpy(string3, "a b s c d ");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  //Final Test given by instructor
  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);


  return 0;
}