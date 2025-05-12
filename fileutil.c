#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	// Read the file line by line.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array of strings.
	return NULL;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// initialize stuff
	int capacity = 20;
	*size = 0;
	
	// Allocate memory for an 2D array, using COLS as the width.
	char (*arr)[COLS] = malloc(capacity * sizeof(char[COLS]));
	
	// Read the file line by line into a buffer.
	char * buffer = malloc(1000);
	
	while(fgets(buffer, COLS, in) != NULL)
	{
    	//   Trim newline.
		char *newline = strchr(buffer, '\n');
		if(newline) *newline = '\0';

		//   Expand array if necessary (realloc).
		if(*size >= capacity)
		{
			capacity *= 1.5;
			arr = realloc(arr, capacity * sizeof(char[COLS]));
		}
		
		//   Copy each line from the buffer into the array (use strcpy).
		strcpy(arr[*size], buffer);

		// Loop stuff
		*size += 1;
	}

    // Close the file.
	fclose(in);
	free(buffer);
	
	// The size should be the number of entries in the array.
	
	// Return pointer to the array.
	return arr;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{

	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
	int index = 0;
    do
	{
		if(strcmp(target, lines[index]) == 0) return lines[index];
		index++;
	}
	while(index < size);

    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{

}

void free2D(char (*arr)[COLS])
{
	free(arr);
}