/*
Description: The purpose of this code is to reveal the secret message 
of a binary number sequence by converting those numbers to characters.
The technique I used was to copy the first 8 bits of the binary sequence
to a another string, then apply the binary to decimal function on it, then repeat this process
until we reach the null character.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bintodec(char *str);

int main()
{

    char *binaryMsg = "0101100101101111011101010010000001100110011011110111010101101110011001000010000001110100011010000110010100100000011100110110010101100011011100100110010101110100001000000110110101100101011100110111001101100001011001110110010100101110";
    // we use binaryRep to copy the first 8 bits of the binary sequence
    char binaryRep[9];
    int decRep = 0;
    int i = 0;
    

    // we copy the first 8 bits, apply the "binary to decimal" function and print its character values
    while(binaryMsg[i*8])
    {
        strncpy(binaryRep, binaryMsg + (i*8), 8);
        decRep = bintodec(binaryRep);
        printf("%c", decRep);
        i++;
        
    }

    printf("\b\n");
    printf("\n");

    int row;
    char *binaryMsg1[3] ={"0100110101100001011101000110100000110010001100110011000000100000011010010111001100100000011001100111010101101110001000010010000100100001",
                          "010000110110111101101110011001110111001001100001011101000111010101101100011000010111010001101001011011110110111001110011001000010010000100100001",    
                          "010000010110111001101111011101000110100001100101011100100010000001110000011100100110111101101010011001010110001101110100001000000110100101110011001000000110010001101111011011100110010100101110"
                         };

    char binarySub[9];
    int dec = 0;

    for(row = 0; row < 3; row++)
    {
        i = 0;
        while(binaryMsg1[row][i*8])
        {
            strncpy(binarySub, binaryMsg1[row] + (i*8), 8);
            dec = bintodec(binarySub);
            printf("%c", dec);
            i++;
        }
        
    }

    

    return 0;
}
int bintodec(char *str)
{
    int x = 0;
    int i = 0;

    // while the index is not NULL, keep looping
    while(str[i] != '\0')
    {   
        // algorithm for converting binary to decimal
        x = (str[i] - '0') + x * 2;
        i++;
    }

    // return x since it is an integer 
    return x;
}
