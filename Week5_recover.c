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
 
int main(int argc, char* argv[])
{
    // open the memory card file
    FILE* file = fopen("card.raw", "r");
     
    // check for successful open
    if (file == NULL) {
         
        printf("Could not open a file");
        return 2;    
    }
     
    int i = 0;
    int newFile = 0;
    int j = 0;
     
    unsigned char buffer[512] = {0};
    char newImage[8];
    FILE* img = NULL;
     
    //repeat until end of card
    while(fread(buffer, sizeof(512), 1, file) == 1) {
     
             
            //find the beginning of a jpg file
            if (
            buffer[0] == 0xff && 
            buffer[1] == 0xd8 && 
            buffer[2] == 0xff && 
            (buffer[3] == 0xe0 || buffer[3] == 0xe1)
            ) {
             
                // end the file and start a new one    
                if (newFile == 1) {
                    // close the previous file and start a new one
                    fclose(img);
                    newFile = 0;
                }
                        
                    // to indicate that we found the beginning of the file
                    j = 1; 
                    newFile = 1;
                     
                    if (i <= 9){
                        sprintf(newImage, "00%d.jpg", i);
                    }
                     
                    else {
                        sprintf(newImage, "0%d.jpg", i);
                    }
                    img = fopen(newImage, "w");
                    fwrite (buffer, sizeof(512), 1, img);
                    i++;
        }  
        // if we found the start of the file, we want to continue writing into it
        else if (j == 1) {
            fwrite (buffer, sizeof(512), 1, img);
        }
         
    }
     
    fclose(img);
    fclose(file);
}