#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size;
    char (*hashes)[HASH_LEN] = loadFile2D(argv[1], &size);
    //char **hashes = loadFile(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    
    // TODO
    // Open the password file for reading.
    FILE *in = fopen(argv[2], "r");
    if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}

    // initialize variables
    char * password = malloc(sizeof(char[PASS_LEN]));
    int passCount = 0;

    // TODO
    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.
    while(fgets(password, PASS_LEN, in) != NULL)
	{
        // Trim newline
        char *newline = strchr(password, '\n');
		if(newline) *newline = '\0';

        char * target = md5(password, strlen(password) );

        char * found = substringSearch2D(target, hashes, size);

        if(found)
        {
            // If you find it, display the password and the hash.
            printf("%20s | %s\n", password, found);
            // Keep track of how many hashes were found.
            passCount++;
            // CHALLENGE1: Use binary search instead of linear search.
        }
    }
    // TODO
    // When done with the file:
    //   Close the file
    fclose(in);
    //   Display the number of hashes found.
    printf("%d hashes found.\n", passCount);
    //   Free up memory.
    free(password);
    free2D(hashes);
}
