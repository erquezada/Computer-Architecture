
/* First name of the student: Eric
   Last name(s) of the student: Quezada
   Student ID: 80532860

*/

#include <stdio.h>
#include <stdlib.h>

/* Copies a string at src into a string at dst, including the end
   marker '\0'. Assumes enough space is available at dst.
*/
void string_copy(char *dst, const char *src) {
   if (!dst || !src) return; // if not a string then return nothing
   while (*src != '\0') { // iterate over source string until end of string
    *dst = *src; // destination string receives copy of source string
    dst++; // increment dst pointer
    src++; // increment src pointer
   }
   *dst = '\0'; // destination string is freed when destination pointer reaches end of string
}

/* Compares two strings a and b.

   If the string a orders in dictionary order before b, returns -1.
   If the strings a and b are equal returns 0.
   If the string a orders in dictionary order after b, returns 1.

   CAUTION: The strings may have different lengths.

   Characters order as they order in ASCII order. 

   If a is a prefix of b but strictly shorter than b, a orders before
   b.

   If b is a prefix of a but strictly shorter than a, a orders after
   b.

*/
int string_compare(const char *a, const char *b) {
    while (*a != '\0' && *b != '\0') { // while both pointers are not null
        if (*a < *b) return -1; // if a appears before b then return -1
        else if (*a > *b) return 1; // if a appears after b then return 1
        a++;
        b++;
    }

    if (*a == '\0' && *b == '\0') return 0; // if a  and b are equal then return 0
    else if (*a == '\0') return -1; // if pointer of a is equal to the null terminator then return -1
    else return 1; // else return 1
}

/* Returns the length of a string str */
size_t string_length(const char *str) {
  size_t count = 0; // counter 
  while (*str != '\0') { // iterate through string
    count++; // increment counter
    str++; // move to next character
  }
  return count; // return count
}

/* Displays an error message and stops the program 

   NOTHING NEEDS TO MODIFIED IN THIS FUNCTION.

*/
void error_no_memory_left() {
  fprintf(stderr, "No memory left.\n");
  exit(1);
}

/* Inputs a string of a maximum length n

   NOTHING NEEDS TO BE MODIFIED IN THIS FUNCTION.

*/
void input_string(char str[], size_t n) {
  char c;
  size_t i;
  int first;
  
  if (n < ((size_t) 1)) return;
  first = 1;
  for (i=(size_t) 0; i<(n-((size_t) 1)); i++) {
    scanf("%c", &c);
    if (c == '\n') {
      if (first) {
	first = 0;
	i = (size_t) 0;
	i--;
	continue;
      } else {
	break;
      }
    }
    str[i] = c;
    first = 0;
  } 
  str[i] = '\0';
}

/* Given a sorted array array_a of strings of length n_a and a sorted
   array array_b of strings of length n_b, "returns" a sorted array
   sorted_array (of length n_a + n_b).

   All arrays are sorted according to dictionary order, as expressed
   by the function string_compare().

   Calls string_compare() to achieve its job. Does not call any other
   function.

   The strings in the arrays are not copied, just the pointers to the
   beginnings of the strings are put into sorted_array.

*/
void merge_arrays(char const ** const sorted_array,
		  char const * const * const array_a, size_t n_a,
		  char const * const * const array_b, size_t n_b) {
 

  size_t i, j, k; // array indexes for each array (array 'a', array 'b', and 'sorted array') 
  
  if (n_a == (size_t) 0) { // if n_a == size_t 
    for (i = 0; i < n_b; i++) { // iterate over elements of the array
      sorted_array[i] = array_b[i]; // sorted array index receives elements of b
    }
    return;
  }
  if (n_b == (size_t) 0) { // if n_b == size_t
    for (i = 0; i < n_a; i++) { // iterate over elements of the array
      sorted_array[i] = array_a[i];// sorted array index receives elements of a
    }
    return;
  }

  // pointers to elements
  i = 0; // used for elements of array 'a'
  j = 0; // used for elements of array 'b'
  k = 0; // used for elements of 'sorted_array'

  // merge elements together
  while (i < n_a && j < n_b) { // while i and j are within bounds
    if (string_compare(array_a[i], array_b[j]) <= 0) { // compare elements by dictionary order
      sorted_array[k] = array_a[i]; // sorted array index receives elements of a
      i++; // move i pointer to next element
    } else {
        sorted_array[k] = array_b[j]; // else sorted array index receives elements of b
        j++; // move j pointer to next element
    }
    k++; // move k pointer to next element
  }

  // copy remaining elements of array 'a' into sorted_array
  while (i < n_a) { // loop over elements
    sorted_array[k] = array_a[i]; // sorted array receives copy of elements from array 'a'
    i++; // increment
    k++; 
  }
  // copy remaining elements of array 'b' into sorted_array
  while (j < n_b) { // loop over elements
    sorted_array[k] = array_b[j]; // sorted array receives copy of elements from array 'b'
    j++; // increment
    k++;
  }
}

/* Sorts an array of strings in dictionary order, as expressed by
   string_compare(). Puts the results into sorted_array.  The arrays
   are of length n. The strings are of different lengths. Does not
   actually copy any strings, just moves the pointers.

   Calls itself recursively and calls merge_arrays().

   NOTHING NEEDS TO BE MODIFIED HERE.

*/
void sort_strings_aux(char const ** const sorted_array,
		      char const * const * const array, size_t n) {
  size_t n_left, n_right;
  char const * const * array_left, * const * array_right;
  
  if (n < (size_t) 1) return;
  if (n == (size_t) 1) {
    sorted_array[0] = array[0];
    return;
  }
  n_left = n / ((size_t) 2);
  n_right = n - n_left;
  array_left = array;
  array_right = &array[n_left];

  char const *sorted_array_left[((n_left < ((size_t) 1)) ?
				 ((size_t) 1) : n_left)];
  char const *sorted_array_right[((n_right < ((size_t) 1)) ?
				  ((size_t) 1) : n_right)];
  
  sort_strings_aux(sorted_array_left, array_left, n_left);
  sort_strings_aux(sorted_array_right, array_right, n_right);

  merge_arrays(sorted_array,
	       sorted_array_left, n_left,
	       sorted_array_right, n_right);
}

/* Sorts an array of strings in dictionary order, as expressed by
   string_compare().  The array is of length n. The strings are of
   different lengths. Does not actually copy any strings, just moves
   the pointers.

   Uses the function sort_strings_aux(). Does not use any other
   function.

   NOTHING NEEDS TO BE MODIFIED HERE.

*/
void sort_strings(const char **array, size_t n) {
  if (n <= (size_t) 1) return;

  char const *sorted_array[n];

  sort_strings_aux(sorted_array, array, n);

  size_t i;
  for (i=(size_t) 0; i<n; i++) {
    array[i] = sorted_array[i];
  }
}

/* Main program.

   NOTHING NEEDS TO BE MODIFIED HERE.

   Example runs:

   Run 1:

   Please enter a string, enter 'quit' to stop entering strings:
   Hello
   Please enter a string, enter 'quit' to stop entering strings:
   World 
   Please enter a string, enter 'quit' to stop entering strings:
   Hell
   Please enter a string, enter 'quit' to stop entering strings:
   is
   Please enter a string, enter 'quit' to stop entering strings:
   this 
   Please enter a string, enter 'quit' to stop entering strings:
   quit
   You entered for line 1: "Hello"
   You entered for line 2: "World"
   You entered for line 3: "Hell"
   You entered for line 4: "is"
   You entered for line 5: "this"
   The array of strings sorted in alphabetical order is:
   "Hell"
   "Hello"
   "World"
   "is"
   "this"

   Run 2:

   Please enter a string, enter 'quit' to stop entering strings:
   Hello
   Please enter a string, enter 'quit' to stop entering strings:
   quit
   You entered for line 1: "Hello"
   The array of strings sorted in alphabetical order is:
   "Hello"

   Run 3:

   Please enter a string, enter 'quit' to stop entering strings:
   quit
   The array of strings sorted in alphabetical order is:

   Run 4:

   Please enter a string, enter 'quit' to stop entering strings:
   Z
   Please enter a string, enter 'quit' to stop entering strings:
   Y
   Please enter a string, enter 'quit' to stop entering strings:
   X
   Please enter a string, enter 'quit' to stop entering strings:
   W
   Please enter a string, enter 'quit' to stop entering strings:
   V
   Please enter a string, enter 'quit' to stop entering strings:
   U
   Please enter a string, enter 'quit' to stop entering strings:
   T
   Please enter a string, enter 'quit' to stop entering strings:
   S
   Please enter a string, enter 'quit' to stop entering strings:
   R
   Please enter a string, enter 'quit' to stop entering strings:
   Q
   Please enter a string, enter 'quit' to stop entering strings:
   P
   Please enter a string, enter 'quit' to stop entering strings:
   O
   Please enter a string, enter 'quit' to stop entering strings:
   N
   Please enter a string, enter 'quit' to stop entering strings:
   M
   Please enter a string, enter 'quit' to stop entering strings:
   L
   Please enter a string, enter 'quit' to stop entering strings:
   K
   Please enter a string, enter 'quit' to stop entering strings:
   J
   Please enter a string, enter 'quit' to stop entering strings:
   I
   Please enter a string, enter 'quit' to stop entering strings:
   H
   Please enter a string, enter 'quit' to stop entering strings:
   G
   Please enter a string, enter 'quit' to stop entering strings:
   F
   Please enter a string, enter 'quit' to stop entering strings:
   E
   Please enter a string, enter 'quit' to stop entering strings:
   D
   Please enter a string, enter 'quit' to stop entering strings:
   C
   Please enter a string, enter 'quit' to stop entering strings:
   B
   Please enter a string, enter 'quit' to stop entering strings:
   A
   Please enter a string, enter 'quit' to stop entering strings:
   quit
   You entered for line 1: "Z"
   You entered for line 2: "Y"
   You entered for line 3: "X"
   You entered for line 4: "W"
   You entered for line 5: "V"
   You entered for line 6: "U"
   You entered for line 7: "T"
   You entered for line 8: "S"
   You entered for line 9: "R"
   You entered for line 10: "Q"
   You entered for line 11: "P"
   You entered for line 12: "O"
   You entered for line 13: "N"
   You entered for line 14: "M"
   You entered for line 15: "L"
   You entered for line 16: "K"
   You entered for line 17: "J"
   You entered for line 18: "I"
   You entered for line 19: "H"
   You entered for line 20: "G"
   You entered for line 21: "F"
   You entered for line 22: "E"
   You entered for line 23: "D"
   You entered for line 24: "C"
   You entered for line 25: "B"
   You entered for line 26: "A"
   The array of strings sorted in alphabetical order is:
   "A"
   "B"
   "C"
   "D"
   "E"
   "F"
   "G"
   "H"
   "I"
   "J"
   "K"
   "L"
   "M"
   "N"
   "O"
   "P"
   "Q"
   "R"
   "S"
   "T"
   "U"
   "V"
   "W"
   "X"
   "Y"
   "Z"

*/
int main(int argc, char **argv) {
  const size_t BUF_LEN = (size_t) 2048;
  char buffer[BUF_LEN];
  char *str;
  const char ** inputs = NULL;
  const char ** temp;
  size_t n = (size_t) 0;
  size_t i;

  while (1) {
    printf("Please enter a string, enter 'quit' to stop entering strings:\n");
    input_string(buffer, BUF_LEN);
    if (string_compare(buffer, "quit") == 0) {
      break;
    }

    str = (char *) calloc(string_length(buffer)+((size_t) 1),sizeof(char));
    if (str == NULL) {
      error_no_memory_left();
      return 1;
    }
    string_copy(str, buffer); 
			 
    if (inputs == NULL) {
      inputs = (const char **) calloc(1, sizeof(char*));
      if (inputs == NULL) {
	error_no_memory_left();
	return 1;
      }
      n = (size_t) 1;
    } else {
      temp = (const char **) realloc(inputs, (n + ((size_t) 1)) * sizeof(char * const));
      if (temp == NULL) {
	error_no_memory_left();
	return 1;
      }
      inputs = temp;
      n++;
    }
    inputs[n-1] = str;
  }

  for (i=(size_t) 0; i<n; i++) {
    printf("You entered for line %zu: \"%s\"\n", (i+((size_t) 1)), inputs[i]);
  }

  sort_strings(inputs, n);

  printf("The array of strings sorted in alphabetical order is:\n");
  for (i=(size_t) 0; i<n; i++) {
    printf("\"%s\"\n", inputs[i]);
  }

  for (i=(size_t) 0; i<n; i++) {
    free((void  *) inputs[i]);
  }
  free(inputs);
  
  return 0;
}




