
/* First name of the student: Eric
   Last name(s) of the student: Quezada
   Student ID: 80532860

   Transform the functions below in such a way that you can 
   translate them to Risc-V assembly. Then translate them 
   to Risc-V assembly. Put the result into a file convert.s

*/

#include <stdio.h>

/* Translate this function to RISC-V assembly */
unsigned char convert_nibble_to_hexadecimal_ascii(unsigned char nibble) {
    unsigned char temp;
    unsigned char res;

    // Break down the compound operation
    temp = nibble;
    temp = temp & 15;  // Clear all but the lower 4 bits

    if (temp <= 9) {
        goto convert_to_digit;
    } else {
        goto convert_to_letter;
    }

convert_to_digit:
    res = '0';
    res = res + temp;  // Add the temp value to '0' to get the correct ASCII code
    goto end;

convert_to_letter:
    res = 'A';
    res = res + (temp - 10);  // Add (temp - 10) to 'A' for values 10-15
    goto end;

end:
    return res;
}

/* Translate this function to Risc-V assembly */
void convert_byte_to_hexadecimal_ascii(unsigned char *hi_nibble_ascii,
				       unsigned char *lo_nibble_ascii,
				       unsigned char byte) {
    unsigned char hi_nibble;
    unsigned char lo_nibble;

    // Break down the compound operations
    hi_nibble = byte;
    hi_nibble = hi_nibble >> 4;  // Shift to get the high nibble

    lo_nibble = byte;
    lo_nibble = lo_nibble & 0x0F;  // Mask to get the low nibble

    goto convert_hi_nibble;

convert_hi_nibble:
    *hi_nibble_ascii = convert_nibble_to_hexadecimal_ascii(hi_nibble);
    goto convert_lo_nibble;

convert_lo_nibble:
    *lo_nibble_ascii = convert_nibble_to_hexadecimal_ascii(lo_nibble);
    goto end;

end:
    return;
}

/* Translate this function to RISC-V assembly */
void convert_string_to_hexadecimal_ascii(unsigned char *dst, unsigned char *src) {
    unsigned char *curr_src; // Pointer to the current character in the source string
    unsigned char *curr_dst; // Pointer to the current position in the destination string
    unsigned char th;        // High nibble ASCII representation
    unsigned char tl;        // Low nibble ASCII representation

    curr_src = src;
    curr_dst = dst;          // Initialize curr_dst to the start of dst, outside the loop

start_loop:
    if (*curr_src == '\0') {
        goto end_loop;       // If we've reached the end of the source string, exit the loop
    }

    // Convert the current byte to two ASCII hexadecimal characters
    convert_byte_to_hexadecimal_ascii(&th, &tl, *curr_src);

    // Store high nibble ASCII in destination
    *curr_dst = th;
    curr_dst = curr_dst + 1; // Move to next position

    // Store low nibble ASCII in destination
    *curr_dst = tl;
    curr_dst = curr_dst + 1; // Move to next position

    curr_src = curr_src + 1; // Move to the next source character
    goto start_loop;         // Repeat the loop

end_loop:
    *curr_dst = '\0';        // Null-terminate the destination string
}



/* Testing only - you do not need to translate this function to 
   Risc-V assembly 
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

/* Testing only - you do not need to translate this function to 
   Risc-V assembly 
*/
int main(int argc, char **argv) {
  unsigned char orig[4096];
  unsigned char hexa[8192];

  printf("Please enter a string:\n");
  input_string((char *) orig, sizeof(orig));

  convert_string_to_hexadecimal_ascii(hexa, orig);

  printf("You entered the string:\n"
	 "%s\n"
	 "The hexadecimal representation of the ASCII byte sequence is\n"
	 "%s\n",
	 orig, hexa);

  return 0;
}