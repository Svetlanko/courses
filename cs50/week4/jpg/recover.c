/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE* input_file = fopen("card.raw", "r");
    
    if (input_file == NULL) {
        printf("Could not open %s file", "card.raw");
        return 1;
    }
    
    // JPEGs have "signatures":
    // the first 4 bytes of a JPEG can be either of
    // 0xff    0xd8    0xff    0xe0
    // 0xff    0xd8    0xff    0xe1
    
    char data[512] = {};
    char jpeg1[4] = { 0xff, 0xd8, 0xff, 0xe0 };
    char jpeg2[4] = { 0xff, 0xd8, 0xff, 0xe1 };
    char file_name[20];
    int file_number = 0;
    FILE* output_file = NULL;
    
    while ((fread(&data, sizeof(512), 1, input_file))) {
        if ((memcmp(data, jpeg1, 4) == 0) || (memcmp(data, jpeg2, 4) == 0)) {
            if (output_file != NULL) fclose(output_file);
            
            file_number++;
            sprintf(file_name, "%03d.jpg", file_number);
            output_file = fopen(file_name, "w");
            fwrite(data, sizeof(512), 1, output_file);
        } else if (output_file != NULL) {
            fwrite(data, sizeof(512), 1, output_file);
        }
    }
    
    fclose(input_file);
    printf("Recovery is completed");
    
    return 0;
}
