//Name: Kirallie Hall
//Student ID: 3304030
//Title: ENGG1003 Project 1
//Date created: 02/04/2019
//Date last modified: 08/04/2019
//Program Description:  
//This program allows the user to encrypt and decrypt messages with both
//a rotation and substitution cipher. Messages can be decrypted with or 
//without the rotation amount or alphabet substitution. To select an encryption
//or decryption method, please choose from one of the given options when prompted.
       
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char task1(int key);  //Function prototype for task1 function
char task2(int key);  //Function prototype for task2 function
char task5(FILE *input_b, FILE *output_b);  //Function prototype for task5 function
FILE *input_a;
FILE *output_a;
FILE *input_b;
FILE *output_b;


int main()
{
    printf("Please select an option: \n");  //Ask the user which task they would like to run
    printf("a) Task 1\n");
    printf("b) Task 2\n");
    printf("c) Task 3\n");
    printf("e) Task 5\n");
    printf("Selection: ");
    
    char c = 'e';
   //scanf("%c", &c);
    
    do
    {
        switch(c)
        {
            case 'a':   //Encrypt a message with a rotation cipher
            {
                int key;
                printf("Enter the key: ");
                scanf("%d", &key);
                while ((key<0) || (key>26))
                {
                    printf("Invalid key. Please try again.");
                    scanf("%d", &key);
                }
                task1(key);
                break;
            }
            case 'b':   //Decrypt an encrypted message with a rotation cipher
            {
                int key;
                printf("Enter the key: ");
                scanf("%d", &key);
                while ((key<0) || (key>26))
                {
                    printf("Invalid key. Please try again.");
                    scanf("%d", &key);
                }
                task2(key);
                break;
            }
            case 'e':
            {
                task5(input_b, output_b);
                break;
            }
            default: printf("Unknown option %c\n Please enter a, b, c or d\n", c);   
        }

    }
    while (c < 'a' || c > 'f');
    return 0;   
}

//Function which takes a key as input, reads a message from a file to encrypt,
//prints that encrypted message to the console, and also writes the encrypted 
//message to a new file
char task1(int key)
{
    input_a = fopen("input_a.txt", "r");
    output_a = fopen("output_a.txt", "w");
    if(input_a == NULL) 
    {
        perror("fopen()");
        return 0;
    }
    char c;
    while(fscanf(input_a, "%c", &c) == 1)
    {
        if (c>=97 && c<=122)  //Test if character is lowercase
        {
            c = c-97;
            c = (c + key)%26;
            c = c+65;
        }
        else if (c>=65 && c<=90)
        {
            c = c-65;
            c = (c + key)%26;
            c = c+65;
        }
        else
        {
            c=c;
        }
        fprintf(output_a, "%c", c); //Write character to output file
        printf("%c", c);    //Print character to console
    }
    fclose(input_a);
    fclose(output_a);
    return 0;
}

//Function which takes a key as input, reads an encrypted message from a file to decrypt,
//prints that decrypted message to the console, and also writes the decrypted 
//message to a new file
char task2(int key)
{
    input_b = fopen("input_b.txt", "r");
    output_b = fopen("output_b.txt", "w");
    if(input_b == NULL) 
    {
        perror("fopen()");
        return 0;
    }
    char c;
    while(fscanf(input_b, "%c", &c) == 1)
    {
        if (c>=97 && c<=122)
        {
            c = c-97;
            if ((c-key)<0)
            {
                c = (c-key+26)%26;
            }
            else
            {
                c = (c - key)%26;   
            }
            c = c+65;
        }
        
        else if (c>=65 && c<=90)
        {
            c = c-65;
            if ((c-key)<0)
            {
                c = (c-key+26)%26;
            }
            else
            {
                c = (c - key)%26;   
            }
            c = c+65;
        }
        else
        {
            c = c;
        }
        fprintf(output_b, "%c", c); //Write character to output file
        printf("%c", c);    //Print character to console
    }
    fclose(input_b);
    fclose(output_b);
    return 0;
}

//Function which takes an input and output file, decrypts the encrypted message, without 
//knowledge of the key, present in the input file and writes the decrypted message to 
//both the console and the output file
char task5(FILE *input_b, FILE *output_b)
{
    char c;
    char word1[10] = "THE";
    char word2[10] = "IS";
    char message[600];
    char *result1, *result2;
    int k;
    
    for (k=0; k<27; k++)
    {
        input_b = fopen("input_b.txt", "r");
        output_b = fopen("output_b.txt", "w");
        if(input_b == NULL) 
        {
            perror("fopen()");
            return 0;
        }
        int count=0;
        while(fscanf(input_b, "%c", &c)==1)
        {
            if (c>=97 && c<=122)
            {
                c = c-97;
                if ((c-k)<0)
                {
                    c = (c-k+26)%26;
                }
                else
                {
                    c = (c - k)%26;   
                }
                c = c+65;
            }
            else if (c>=65 && c<=90)
            {
                c = c-65;
                if ((c-k)<0)
                {
                    c = (c-k+26)%26;
                }
                else
                {
                    c = (c - k)%26;   
            }
                c = c+65;
            }
            else
            {
                c = c;
            }
            message[count] = c;
            count++;
        }
        fclose(input_b);
        result1 = strstr(message, word1);
        if ((result1 != NULL))
        {
            fprintf(output_b, "%s", message); //Write character to output file
            fclose(output_b);
            printf("%s\n", message);    //Print character to console
            break;
        }
        //result2 = strstr(message, word2);
        //if ((result2 != NULL))
        //{
          //  fprintf(output_b, "%s", message); //Write character to output file
           // fclose(output_b);
            //printf("%s\n", message);    //Print character to console
            //break;
        //}
    }
    return 0;
}

