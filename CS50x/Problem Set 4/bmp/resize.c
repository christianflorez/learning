/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

/** 
  * First we need to modify the header files so that they create resize with the appropriate information
  * Then, we need to determine what impact the new pixel width + height has on the padding
  * Finally, we need to iterate 'resize' times first horizontally, then vertically
  *     Can this be done recursively? (I think so!)
  **/

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    if (atoi(argv[1]) < 1 || atoi(argv[1]) > 100)
    {
        printf("Resize factor must be between 1 and 100\n");
        return 2;
    }
    
    // remember command line arguments
    int resize = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    
    // store old height, width, and padding
    LONG oldHeight = bi.biHeight;
    LONG oldWidth = bi.biWidth;
    int old_padding =  (4 - (oldWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // set new height, width, and padding
    bi.biHeight *= resize;
    bi.biWidth *= resize;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // rewrite bfSize
    int pixels = bi.biHeight * bi.biHeight;
    bf.bfSize = (pixels * sizeof(RGBTRIPLE)) + (padding * abs(bi.biHeight)) + sizeof(bf) + sizeof(bi);
    
    // rewrite headers
    bi.biSizeImage = bf.bfSize - bf.bfOffBits;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < abs(oldHeight); i++)
    {
        // Repeat height for resize
        for (int j = 0; j < resize; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < oldWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;
                
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // Will write RGBTRIPLE 'resize' amount of times
                for (int l = 1; l <= resize; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            // Skip over old padding
            fseek(inptr, old_padding, SEEK_CUR);
            
            // Add new amount of padding
            for (int m = 0; m < padding; m++)
            {
                fputc(0x00, outptr);
            }
            
            // Rewind for vertical resizing
            if (j < resize - 1)
            {
                fseek(inptr, (oldWidth * (int) sizeof(RGBTRIPLE) + old_padding) * -1, SEEK_CUR);  
            }
        }
    }    
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
