/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

// Define 512B Contiguous chunks
typedef struct
{
    uint8_t first_byte;
    uint8_t second_byte;
    uint8_t third_byte;
    uint8_t fourth_byte;
    uint32_t chunk32;
    uint64_t padding[63];
} __attribute__((__packed__)) 
JPEGBLOCK;

// Declare function to check if chunk is jpg
bool is_jpeg (JPEGBLOCK jpg);

int main(void)
{
    // Open input file
    FILE* card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Error: Could not open card.raw\n");
        return 1;
    }
    
    // Read first 512B chunk
    JPEGBLOCK jpg;
    fread(&jpg, sizeof(JPEGBLOCK), 1, card);

    // Format string to print to new file    
    int filecount= 0;
    char nameout[8];
    sprintf(nameout, "%03d.jpg", filecount);
    
    // Create first JPEG file
    FILE* outptr = fopen(nameout, "w");
    if (outptr == NULL)
    {
        fclose(card);
        fprintf(stderr, "Could not create %s.\n", nameout);
        return 2;
    }
    
    // Searches for first JPG header
    while (is_jpeg(jpg) == false)
    {
        fread(&jpg, sizeof(JPEGBLOCK), 1, card);
    }
    
    fwrite(&jpg, sizeof(JPEGBLOCK), 1, outptr);
    
    
    // Loops over card.raw and to write .jpg files
    while (fread(&jpg, sizeof(JPEGBLOCK), 1, card) == 1)
    {
        if (is_jpeg(jpg))
        {
            // Creates new JPG when appropriate header is found
            fclose(outptr);
            filecount++;
            sprintf(nameout, "%03d.jpg", filecount);
            outptr = fopen(nameout, "w");
        }
        fwrite(&jpg, sizeof(JPEGBLOCK), 1, outptr);
    }
    
    // Close last .jpg
    fclose(outptr);
    
    // Close card.raw
    fclose(card);

    return 0;
}

bool is_jpeg (JPEGBLOCK jpg)
{
    if (jpg.first_byte == 0xFF && 
            jpg.second_byte == 0xD8 && 
            jpg.third_byte == 0xFF && 
            jpg.fourth_byte >= 0xE0 && 
            jpg.fourth_byte <= 0xEF)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}