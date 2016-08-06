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

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    int factor = atoi(argv[1]);
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    
    if (factor > 100 || factor < 1) 
    {
        printf("n should be in range 1..100");
        return 1;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // declare and initialize resized infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf_resized;
    bf_resized = bf;
    
    // declare and update resized infile's BITMAPINFOHEADER by factor
    BITMAPINFOHEADER bi_resized;
    bi_resized = bi;
    bi_resized.biWidth = bi.biWidth * factor;
    bi_resized.biHeight = bi.biHeight * factor;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine resized padding for scanlines
    int padding_resized = (4 - (bi_resized.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi_resized.biSizeImage = (bi_resized.biWidth * 3 + padding_resized) * abs(bi_resized.biHeight);
    bf_resized.bfSize = bi_resized.biSizeImage + bf.bfOffBits;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_resized, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_resized, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // resize vertically
        for (int f = 0; f < factor; f++) {
            // iterate over pixels in scanline
            for (int j = 0; j < (bi.biWidth); j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int h=0; h < factor; h++) {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
    
            // padding
            for (int k = 0; k < padding_resized; k++)
                fputc(0x00, outptr);
            
            // free memory
            if (f < factor-1) {
                long offset = bi.biWidth * sizeof(RGBTRIPLE);
                fseek(inptr, -offset, SEEK_CUR);
            }
        }
        
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
