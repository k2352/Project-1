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
char task3(char* key);  //Function prototype for task3 function
char task4(char* key);  //Function prototype for task4 function
char task5(FILE *input_e, FILE *output_e);  //Function prototype for task5 function
char task6(FILE *input_f, FILE *output_f);  //Function prototype for task6 function
FILE *input_a;
FILE *output_a;
FILE *input_b;
FILE *output_b;
FILE *input_c;
FILE *output_c;
FILE *input_d;
FILE *output_d;
FILE *input_e;
FILE *output_e;
FILE *input_f;
FILE *output_f;
FILE *words;

int main()
{
    printf("Please select an option: \n");  //Ask the user which task they would like to run
    printf("a) Task 1\n");
    printf("b) Task 2\n");
    printf("c) Task 3\n");
    printf("d) Task 4\n");
    printf("e) Task 5\n");
    printf("f) Task 6\n");
    printf("Selection: ");
    
    //char choice = 'c';
    char choice;
    scanf("%c", &choice);
    
    do
    {
        switch(choice)
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
            case 'c':
            {
                char key[26];
                printf("Enter the substitution key, 26 characters long: ");
                scanf("%s", key);
                for (int i=0; i<30; i++)
                {
                    if ((key[i]>=97) && (key[i]<=122))
                    {
                        key[i] = key[i]-32;
                    }
                }
                task3(key);
                break;
            }
            case 'd':
            {
                char key[26];
                printf("Enter the substitution key, 26 characters long: ");
                scanf("%s", key);
                for (int i=0; i<30; i++)
                {
                    if ((key[i]>=97) && (key[i]<=122))
                    {
                        key[i] = key[i]-32;
                    }
                }
                task4(key);
                break;
            }
            case 'e':
            {
                task5(input_e, output_e);
                break;
            }
            case 'f':
            {
                task6(input_f, output_f);
                break;
            }
            default: printf("Unknown option %c\n Please enter a, b, c, d, e or f\n", choice);   
        }

    }
    while (choice < 'a' || choice > 'g');
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

//Function which takes a substitution key as input, reads a message from a file to encrypt,
//prints that encrypted message to the console, and also writes the encrypted message to an output file
char task3(char* key)
{
    input_c = fopen("input_c.txt", "r");
    output_c = fopen("output_c.txt", "w");
    if(input_c == NULL) 
    {
        perror("fopen()");
        return 0;
    }
    char ch;
    char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(fscanf(input_c, "%c", &ch) == 1)
    {
        if (ch>=97 && ch<=122)  //Test if character is lowercase
        {
            ch = ch-32;
            for(int i=0; i<8; i++)
            {
                if (alpha[i]==ch)
                {
                    ch = key[i];
                    break;
                }
            }
            ch = ch+32;
        }
        else if (ch>=65 && ch<=90)
        {
            for(int i=0; i<26; i++)
            {
                if (alpha[i]==ch)
                {
                    ch = key[i];
                    break;
                }
            }
        }
        else
        {
            ch=ch;
        }
        if (ch>=97 && ch<=122)
        {
            ch = ch-32;
        }
        fprintf(output_c, "%c", ch); //Write character to output file
        printf("%c", ch);    //Print character to console
    }
    fclose(input_c);
    fclose(output_c);
    return 0;
}

//Function which takes a substitution key as input, reads a message from a file to decrypt,
//prints that decrypted message to the console, and also writes the decrypted message to an output file
char task4(char* key)
{
    input_d = fopen("input_d.txt", "r");
    output_d = fopen("output_d.txt", "w");
    if(input_d == NULL) 
    {
        perror("fopen()");
        return 0;
    }
    char ch;
    char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(fscanf(input_d, "%c", &ch) == 1)
    {
        if (ch>=97 && ch<=122)  //Test if character is lowercase
        {
            ch = ch-32;
            for(int i=0; i<8; i++)
            {
                if (key[i]==ch)
                {
                    ch = alpha[i];
                    break;
                }
            }
            ch = ch+32;
        }
        else if (ch>=65 && ch<=90)
        {
            for(int i=0; i<26; i++)
            {
                if (key[i]==ch)
                {
                    ch = alpha[i];
                    break;
                }
            }
        }
        else
        {
            ch=ch;
        }
        if (ch>=97 && ch<=122)
        {
            ch = ch-32;
        }
        fprintf(output_d, "%c", ch); //Write character to output file
        printf("%c", ch);    //Print character to console
    }
    fclose(input_d);
    fclose(output_d);
    return 0;
}

//Function which takes an input and output file, decrypts the encrypted message, without 
//knowledge of the key present in the input file and writes the decrypted message to 
//both the console and the output file
char task5(FILE *input_e, FILE *output_e)
{
    char c;
    char word1[10] = " THE ";
    char word2[10] = " IS ";
    char word3[10] = " OF ";
    char word4[10] = " TO ";
    char word5[10] = " AND ";
    char word6[10] = " IN ";
    char word7[10] = " IT ";
    char word8[10] = " YOU ";
    char word9[10] = " THAT ";
    char word10[10] = " A ";

    char message[600];
    char check[100000];
    char *result1, *result2, *result3, *result4, *result5, *result6, *result7, *result8, *result9, *result10;
    int k, number=0;
    
    words = fopen("words.txt", "r");
    if(words == NULL)
    {
        perror("fopen()");
        return 0;
    }
    while(fscanf(words, "%c", &c)==1)
    {
            if (c>=97 && c<=122)
            {
                c = c-32;
            }
            else if (c>=65 && c<=90)
            {
                c = c;   
            }
            else
            {
                c = c;
            }
            check[number] = c;
            number++;
    }
    //printf("%s", check);
    for (k=0; k<27; k++)
    {
        input_e = fopen("input_e.txt", "r");
        output_e = fopen("output_e.txt", "w");
        if(input_e == NULL) 
        {
            perror("fopen()");
            return 0;
        }
        int count=0;
        while(fscanf(input_e, "%c", &c)==1)
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
        fclose(input_e);
        result1 = strstr(message, word1);
        result2 = strstr(message, word2);
        result3 = strstr(message, word3);
        result4 = strstr(message, word4);
        result5 = strstr(message, word5);
        result6 = strstr(message, word6);
        result7 = strstr(message, word7);
        result8 = strstr(message, word8);
        result9 = strstr(message, word9);
        result10 = strstr(message, word10);
        if ((result1 != NULL) && (result2 == NULL) && (result3 == NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            //fclose(output_e);
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if((result2 != NULL) && (result1 == NULL) && (result3 == NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result3 != NULL) && (result1 == NULL) && (result2 == NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result4 != NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result5 != NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result6 != NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result7 != NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result8 != NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result9 != NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result10 != NULL))
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else
        {
            continue;
        }
    }
    fclose(words);
    return 0;
}

//Function which takes an input and output file, decrypts the encrypted message, without 
//knowledge of the key present in the input file and writes the decrypted message to 
//both the console and the output file
char task6(FILE *input_f, FILE *output_f)
{
    char c;
    char message[1000];
    int alpha[26];
    int count=0; //countA=0, countB=0, countC=0, countD=0, countE=0, countF=0, countG=0, countH=0, countI=0, countJ=0, countK=0, countL=0, countM=0, countN=0, countO=0, countP=0, countQ=0, countR=0, countS=0, countT=0, countU=0, countV=0, countW=0, countX=0, countY=0, countZ=0;
    input_f = fopen("input_f.txt", "r");
    output_f = fopen("output_f.txt", "w");
    if(input_f == NULL) 
    {
        perror("fopen()");
        return 0;
    }
    for (int i=0; i<26; i++)
    {
        alpha[i]=0;
    }
    while(fscanf(input_f, "%c", &c)==1)
    {
        if (c>=97 && c<=122)
        {
            c = c-32;
        }
        else
        {
            c = c;
        }
        message[count] = c;
        count++;
    }
    for(int i=0; i<count; i++)
    {
        if(message[i]==65)
        {
            alpha[0]++;
            //countA++;
        }
        if(message[i]==66)
        {
            alpha[1]++;
            //countB++;
        }
        if(message[i]==67)
        {
            alpha[2]++;
            //countC++;
        }
        if(message[i]==68)
        {
            alpha[3]++;
//            countD++;
        }
        if(message[i]==69)
        {
            alpha[4]++;
            //countE++;
        }
        if(message[i]==70)
        {
            alpha[5]++;
            //countF++;
        }
        if(message[i]==71)
        {
            alpha[6]++;
            //countG++;
        }
        if(message[i]==72)
        {
            alpha[7]++;
            //countH++;
        }
        if(message[i]==73)
        {
            alpha[8]++;
            //countI++;
        }
        if(message[i]==74)
        {
            alpha[9]++;
            //countJ++;
        }
        if(message[i]==75)
        {
            alpha[10]++;
            //countK++;
        }
        if(message[i]==76)
        {
            alpha[11]++;
            //countL++;
        }
        if(message[i]==77)
        {
            alpha[12]++;
            //countM++;
        }
        if(message[i]==78)
        {
            alpha[13]++;
            //countN++;
        }
        if(message[i]==79)
        {
            alpha[14]++;
            //countO++;
        }
        if(message[i]==80)
        {
            alpha[15]++;
            //countP++;
        }
        if(message[i]==81)
        {
            alpha[16]++;
            //countQ++;
        }
        if(message[i]==82)
        {
            alpha[17]++;
            //countR++;
        }
        if(message[i]==83)
        {
            alpha[18]++;
            //countS++;
        }
        if(message[i]==84)
        {
            alpha[19]++;
            //countT++;
        }
        if(message[i]==85)
        {
            alpha[20]++;
            //countU++;
        }
        if(message[i]==86)
        {
            alpha[21]++;
            //countV++;
        }
        if(message[i]==87)
        {
            alpha[22]++;
            //countW++;
        }
        if(message[i]==88)
        {
            alpha[23]++;
            //countX++;
        }
        if(message[i]==89)
        {
            alpha[24]++;
            //countY++;
        }
        if(message[i]==90)
        {
            alpha[25]++;
            //countZ++;
        }
    }
    int maxValue = alpha[0];
    for(int k=0; k<26; k++)
    {
        if(alpha[k]>maxValue)
        {
            maxValue=alpha[k];
        }
    }
    //need to find second biggest number in array
    printf("%d", maxValue);
    fclose(input_f);
    fclose(output_f);
    //fprintf(output_e, "%s", message); //Write character to output file
    //printf("%s\n", message);    //Print character to console
        
    return 0;
}
