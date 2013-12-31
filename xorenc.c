/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 512
//max key length
 
void xorenc(char *inname, char *outname, char *key);
 
int main(int argc, char **argv)
{
    char input[MAX], *key;
 
    if(argc != 3) // check the arguments
    {
        printf("ERROR: invalid arguments\n\n");
        printf("Usage:\n");
        printf("%s [input] [output]\n", argv[0]);
        return EXIT_FAILURE;
    }
     
    /* get the key */
    printf("Key please: ");
    fgets(input, MAX, stdin);
    key = malloc(strlen(input) + 1);
    strcpy(key, input);
     
    xorenc(argv[1], argv[2], key);
     
    free(key);
    return 0;
}
 
void xorenc(char *inname, char *outname, char *key)
{
    FILE *input, *output;
    char c[1];
    int i, k;
     
    input = fopen(inname, "rb");
    output = fopen(outname, "wb");
     
    k = strlen(key);
    i = 0;
    while((fread(c, 1, 1, input)) != 0)
    {
        c[0] ^= key[i++]; // xor the input file's char with key's char
        fwrite(c, 1, 1, output); // write the (en/de)crypted char to output
        if(i == k) i = 0; // rewind the key if input is longer than it
    }
     
    fclose(input);
    fclose(output);
}
