//  Yuya Oguchi
//  COEN11L     Lab8
//  11/14/2014
//  Reverse line
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *buffer)
{
    int i;
    int length;
    length = strlen(buffer) -1;
    char temp;

    for (i = 0; i < length/2; i++)
    {
        temp = buffer [i];
        buffer[i] = buffer[length - i];
        buffer[length -i] = temp;
    }

}

int main(int argc, char * argv[])
{
    FILE* input;
    FILE *out;
    char buffer[15];
    printf("Welcome to Lab8\n");

    if ((input = fopen(argv[1], "r")) == NULL){
        printf ("cannot open the file in\n");
        return 1;
    }
    //printf("First file opened\n");
    //FILE *out;
    if ((out = fopen(argv[2], "w")) == NULL){
        printf ("cannot open the file out\n");
        return 1;
    }
    //printf("Second file opened\n");

    while(fgets(buffer, 15, input) != NULL){
        //printf("file opened\n");
        reverse(buffer);
        printf("%s\n", buffer);
        fprintf(out,"%s\n", buffer);
    }

    fclose(input);
    fclose(out);



    return 0;
}
