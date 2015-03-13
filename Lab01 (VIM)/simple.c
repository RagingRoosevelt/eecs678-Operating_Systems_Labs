#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "simple.h"

void display_onto_stdout(const char *str)
{
	printf("%s\n", str);
}

/*
 * It's good to keep descriptive comments in your code, but manually
 * formatting long comments is tedious. You can fix this comment by entering
 * command mode and moving your cursor somewhere over the comment. Now type
 * 'gq', followed by one of the commands to move your cursor (e.g. 'j')
 */

double find_cosine(double value)
{
	return cos(value);
}

/*
 * The way this code is formatted makes it difficult to read. Use 10== to format
 * this block of code
 */

void useless_loop(int iterations)
{
  int i;
  for (i=0; i < iterations; i++) {
    long long t1, t2; 
    t1 = random();
    t2 = random();
  }
}

/*
 * The mark can be used to automate tasks between marks.. Mark the line above
 * this function with the letter 'a' (In command mode, place the cursor on the
 * line where the function starts type 'ma'). Mark the line where the function
 * ends with 'mb'. Make sure the cursor is placed on the line where the function
 * ends. Now, press ':', and type 'b, 'a s /^\/\///.
 * 
 * This means, "From mark b to mark a replace the string ^\/\/ (^ stands for the
 * start of a line, and the backslashes are used to escape the forward slash.
 * The other forward slashes delimit the arguments to the replace command),
 * with an empty string. This might be a good command to map in your
 * .vimrc file.
 *
 * Of course, you could now automatically comment out this piece of code with
 * :'b, 'a s /^/\/\//. To get rid of search highlighting do :set hlsearch! This
 * is mapped to th in the .vimrc.
 *
 * Now, uncomment the print_this_many line in the main function and recompile.
 */

void print_this_many(int size)
{
	char *bigbuf = malloc(size * sizeof(char));
	int i;

	for (i=0; i<size; i++) {
		bigbuf[i] = 'a' + (i % 26);
	}

	printf("%s\n", bigbuf);
}

int main(int argc, char **argv)
{
  double x;

  display_onto_stdout("Simple Program");

  x = find_cosine(COSINE_ONE);
  printf("cosine of 45 is %f\n", x); 

  x = find_cosine(COSINE_TWO);
  printf("cosine of 0 is %f\n", x); 

  useless_loop(LOOP_NUM);

  //print_this_many(PRINT_NUM);

  display_onto_stdout("Done Executing this Simple Program");
  return 0;
}
