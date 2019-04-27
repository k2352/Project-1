//Name: Kirallie Hall
//Student ID: 3304030
//Title: ENGG1003 Project 1
//Date created: 02/04/2019
//Date last modified: 27/04/2019

//Program Description:  
//This program allows the user to encrypt and decrypt messages with both
//a rotation and substitution cipher. Messages can be decrypted with or 
//without the rotation amount or alphabet substitution. To select an encryption
//or decryption method, please choose from one of the given options when prompted.
//The options are as follows: 'a' for task1, which will encrypt a given message with
//a rotation cipher given the rotation amount; 'b' for task2, which will decrypt a 
//given message with a rotation cipher given the rotation amount; 'c' for task3, which 
//will encrypt a given message with a substitution cipher given the substitution key; 
//'d' for task4, which will decrypt a given message with a substitution cipher given the
//substitution key; 'e' for task5, which will decrypt a given encrypted message with a 
//rotation cipher without the rotation amount;'f' for task6, which will decrypt a given
//decrypted message with a substituion cipher without the substitution key, and 'g' for task7,
//which will decrypted day-1 cipher text with a rotation cipher
       
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char task1(int key);  //Function prototype for task1 function
char task2(int key);  //Function prototype for task2 function
char task3(char* key);  //Function prototype for task3 function
char task4(char* key);  //Function prototype for task4 function
char task5(FILE *input_e, FILE *output_e);  //Function prototype for task5 function
char task6(FILE *input_f, FILE *output_f);  //Function prototype for task6 function
char task7(FILE *input_g, FILE *output_g);  //Function prototype for task7 function
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
FILE *input_g;
FILE *output_g;
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
    printf("g) Task 7\n");
    printf("Selection: ");
    
    char choice;
    scanf("%c", &choice);
    
    
    //Switch statement, which runs for each case from 'a' to 'g'
    switch(choice)
    {
        case 'a':   //Encrypt a message with a rotation cipher
        {
            int key;
            printf("Enter the key: ");  //Ask the user the rotation key
            scanf("%d", &key);
            while ((key<0) || (key>26)) //Check that the key is valid, if not, ask again
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
            printf("Enter the key: ");  //Ask the user for the rotation key
            scanf("%d", &key);
            while ((key<0) || (key>26)) //Check if key is valid
            {
                printf("Invalid key. Please try again.");
                scanf("%d", &key);
            }
            task2(key);
            break;
        }
        case 'c':   //Encrypt a message with a substitution cipher
        {
            char key[26];
            printf("Enter the substitution key, 26 characters long: ");
            scanf("%s", key);
            //for loop to check if any characters in key array are lowercase, if so, change to uppercase
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
        case 'd':   //Decrypt an encrypted message with a substitution cipher
        {
            char key[26];
            printf("Enter the substitution key, 26 characters long: ");
            scanf("%s", key);
            //for loop to check if any characters in key array are lowercase, if so, change to uppercase
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
        case 'e':   //Decrypt a given encrypted message, without knowledge of the rotation key, with a rotation cipher
        {
            task5(input_e, output_e);
            break;
        }
        case 'f':   //Decrypt a given encrypted message, without knowledge of the substitution key, with a substitution cipher
        {
            task6(input_f, output_f);
            break;
        }
        case 'g':   //Decrypt day-1 encrypted message, without knowledge of the substitution key, with a substitution cipher
        {
            task7(input_g, output_g);
            break;
        }
        default: printf("Unknown option %c\n Please enter a, b, c, d, e, f, g\n", choice);   
    }
    return 0;   
}

//Function which takes a key as input, reads a message from a file to encrypt
//with a rotation cipher,prints that encrypted message to the console, and
//also writes the encrypted message to a new file
char task1(int key)
{
    input_a = fopen("input_a.txt", "r");    //Open input_a.txt file
    output_a = fopen("output_a.txt", "w");  //Open output_a.txt file
    if(input_a == NULL) //Check if file is empty
    {
        perror("fopen()");
        return 0;
    }
    char c;
    while(fscanf(input_a, "%c", &c) == 1)   //Scan characters from file input_a.txt
    {
        if (c>=97 && c<=122)  //Test if character is lowercase
        {
            c = c-97;
            c = (c + key)%26;   //Apply rotation cipher
            c = c+65;
        }
        else if (c>=65 && c<=90)    //Test if character is uppercase
        {
            c = c-65;
            c = (c + key)%26;   //Apply rotation cipher
            c = c+65;
        }
        else
        {
            c=c;
        }
        fprintf(output_a, "%c", c); //Write character to output file
        printf("%c", c);    //Print character to console
    }
    fclose(input_a);    //Close input file
    fclose(output_a);   //Close output file
    return 0;
}

//Function which takes a key as input, reads an encrypted message from a file to decrypt with a rotation cipher,
//prints that decrypted message to the console, and also writes the decrypted 
//message to a new file
char task2(int key)
{
    input_b = fopen("input_b.txt", "r");    //Open input_b.txt file
    output_b = fopen("output_b.txt", "w");  //Open output_b.txt file
    if(input_b == NULL) //Check if file is empty
    {
        perror("fopen()");
        return 0;
    }
    char c;
    while(fscanf(input_b, "%c", &c) == 1)   //Scan characters from file input_b.txt
    {
        if (c>=97 && c<=122)    //Check if character is lowercase
        {
            c = c-97;
            if ((c-key)<0)  
            {
                c = (c-key+26)%26;  //Apply rotation cipher
            }
            else
            {
                c = (c - key)%26;  //Apply rotation cipher 
            }
            c = c+65;
        }
        
        else if (c>=65 && c<=90)    //Check if character is lowercase
        {
            c = c-65;
            if ((c-key)<0)  
            {
                c = (c-key+26)%26;  //Apply rotation cipher
            }
            else
            {
                c = (c - key)%26;   //Apply rotation cipher
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
    fclose(input_b);    //Close input_b.txt
    fclose(output_b);   //Close output_b.txt
    return 0;
}

//Function which takes a substitution key as input, reads a message from a file to encrypt with a substitution cipher,
//prints that encrypted message to the console, and also writes the encrypted message to an output file
char task3(char* key)
{
    input_c = fopen("input_c.txt", "r");    //Open input_c.txt
    output_c = fopen("output_c.txt", "w");  //Open output_c.txt
    if(input_c == NULL) //Check if file is empty
    {
        perror("fopen()");
        return 0;
    }
    char ch;
    char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(fscanf(input_c, "%c", &ch) == 1)  //Scan characters from file input_c.txt
    {
        if (ch>=97 && ch<=122)  //Test if character is lowercase
        {
            ch = ch-32;
            for(int i=0; i<26; i++) //Apply substitution cipher key
            {
                if (alpha[i]==ch)
                {
                    ch = key[i];
                    break;
                }
            }
            ch = ch+32;
        }
        else if (ch>=65 && ch<=90)  //Test if character is uppercase
        {
            for(int i=0; i<26; i++) //Apply substitution cipher key
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
    fclose(input_c);    //Close input_c.txt file
    fclose(output_c);   //Close output_c.txt file
    return 0;
}

//Function which takes a substitution key as input, reads a message from a file to decrypt with the substitution cipher,
//prints that decrypted message to the console, and also writes the decrypted message to an output file
char task4(char* key)
{
    input_d = fopen("input_d.txt", "r");    //Open input_d.txt file
    output_d = fopen("output_d.txt", "w");  //Open output_d.txt file
    if(input_d == NULL) //Check if file is empty
    {
        perror("fopen()");
        return 0;
    }
    char ch;
    char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(fscanf(input_d, "%c", &ch) == 1)  //Scan characters from file input_d.txt
    {
        if (ch>=97 && ch<=122)  //Test if character is lowercase
        {
            ch = ch-32;
            for(int i=0; i<26; i++) //Apply substitution cipher key
            {
                if (key[i]==ch)
                {
                    ch = alpha[i];
                    break;
                }
            }
            ch = ch+32;
        }
        else if (ch>=65 && ch<=90)  //Test if character is uppercase
        {
            for(int i=0; i<26; i++) //Apply substitution cipher key
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
    fclose(input_d);    //Close input_d.txt file
    fclose(output_d);   //Close output_d.txt file
    return 0;
}

//Function which takes an input and output file, decrypts the encrypted message with a rotation cipher, without 
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
    char word11[10] = " I ";
    char word12[10] = " HE ";
    char word13[10] = " WAS ";
    char word14[10] = " FOR ";
    char word15[10] = " ON ";
    char word16[10] = " ARE ";
    char word17[10] = " AS ";
    char word18[10] = " WITH ";
    char word19[10] = " HIS ";
    char word20[10] = " THEY ";

    char message[1000];  //Array containing characters present in the message
    char *result1, *result2, *result3, *result4, *result5, *result6, *result7, *result8, *result9, *result10, *result11, *result12, *result13, *result14, *result15, *result16, *result17, *result18, *result19, *result20;
    int number=0;
    for (int k=0; k<27; k++)    //Loop through possible values of k, to find the rotation key value
    {
        input_e = fopen("input_e.txt", "r");    //Open input_e.txt file  
        output_e = fopen("output_e.txt", "w");  //Open output_e.txt file
        if(input_e == NULL) //Check if file is empty
        {
            perror("fopen()");
            return 0;
        }
        int count=0;
        while(fscanf(input_e, "%c", &c)==1) //Scan characters from input_e.txt file
        {
            if (c>=97 && c<=122)    //Check if character is lowercase
            {
                c = c-97;
                if ((c-k)<0)
                {
                    c = (c-k+26)%26;    //Apply rotation key 
                }
                else
                {
                    c = (c - k)%26;     //Apply rotation key
                }
                c = c+65;
            }
            else if (c>=65 && c<=90)    //Check if character is uppercase
            {
                c = c-65;
                if ((c-k)<0)
                {
                    c = (c-k+26)%26;    //Apply rotation key
                }
                else
                {
                    c = (c - k)%26;     //Apply rotation key
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
        fclose(input_e);    //Close input_e.txt file
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
        result11 = strstr(message, word11);
        result12 = strstr(message, word11);
        result13 = strstr(message, word11);
        result14 = strstr(message, word11);
        result15 = strstr(message, word11);
        result16 = strstr(message, word11);
        result17 = strstr(message, word11);
        result18 = strstr(message, word11);
        result19 = strstr(message, word11);
        result20 = strstr(message, word11);
        if ((result1 != NULL) && (result2 == NULL) && (result3 == NULL))    //Check if word1 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if((result2 != NULL) && (result1 == NULL) && (result3 == NULL))    //Check if word2 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result3 != NULL) && (result1 == NULL) && (result2 == NULL))   //Check if word3 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result4 != NULL)) //Check if word4 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result5 != NULL)) //Check if word5 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result6 != NULL)) //Check if word6 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result7 != NULL)) //Check if word7 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result8 != NULL)) //Check if word8 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result9 != NULL)) //Check if word9 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result10 != NULL))    //Check if word10 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result11 != NULL))    //Check if word11 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result12 != NULL))    //Check if word12 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result13 != NULL))    //Check if word13 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result14 != NULL))    //Check if word14 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result15 != NULL))    //Check if word15 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result16 != NULL))    //Check if word16 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result17 != NULL))    //Check if word17 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result18 != NULL))    //Check if word18 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result19 != NULL))    //Check if word19 is present in message
        {
            fprintf(output_e, "%s", message); //Write character to output file
            printf("%s\n", message);    //Print character to console
            break;
        }
        else if ((result20 != NULL))    //Check if word20 is present in message
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
    return 0;
}

//Function which takes an input and output file, decrypts the encrypted message with a substitution cipher, without 
//knowledge of the key present in the input file and writes the decrypted message to 
//both the console and the output file
char task6(FILE *input_f, FILE *output_f)
{
    char c;
    char message[1000]; //Array containing characters present in message
    int alpha[26];  //Array containing number of times each letter occurs
    int count=0;  
    input_f = fopen("input_f.txt", "r");    //Open input_f.txt file
    output_f = fopen("output_f.txt", "w");  //Open output_f.txt file
    if(input_f == NULL) //Check if file is empty
    {
        perror("fopen()");
        return 0;
    }
    for (int i=0; i<26; i++)    //Initialise array 'alpha' to zero
    {
        alpha[i]=0;
    }
    while(fscanf(input_f, "%c", &c)==1) //Scan characters from input_f.txt file
    {
        if (c>=97 && c<=122)    //Check if character is lowercase
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
    for(int i=0; i<count; i++)  //Count how many times each letter occurs in encrypted message 
    {
        if(message[i]==65)
        {
            alpha[0]++;
        }
        if(message[i]==66)
        {
            alpha[1]++;
        }
        if(message[i]==67)
        {
            alpha[2]++;
        }
        if(message[i]==68)
        {
            alpha[3]++;
        }
        if(message[i]==69)
        {
            alpha[4]++;
        }
        if(message[i]==70)
        {
            alpha[5]++;
        }
        if(message[i]==71)
        {
            alpha[6]++;
        }
        if(message[i]==72)
        {
            alpha[7]++;
        }
        if(message[i]==73)
        {
            alpha[8]++;
        }
        if(message[i]==74)
        {
            alpha[9]++;
        }
        if(message[i]==75)
        {
            alpha[10]++;
        }
        if(message[i]==76)
        {
            alpha[11]++;
        }
        if(message[i]==77)
        {
            alpha[12]++;
        }
        if(message[i]==78)
        {
            alpha[13]++;
        }
        if(message[i]==79)
        {
            alpha[14]++;
        }
        if(message[i]==80)
        {
            alpha[15]++;
        }
        if(message[i]==81)
        {
            alpha[16]++;
        }
        if(message[i]==82)
        {
            alpha[17]++;
        }
        if(message[i]==83)
        {
            alpha[18]++;
        }
        if(message[i]==84)
        {
            alpha[19]++;
        }
        if(message[i]==85)
        {
            alpha[20]++;
        }
        if(message[i]==86)
        {
            alpha[21]++;
        }
        if(message[i]==87)
        {
            alpha[22]++;
        }
        if(message[i]==88)
        {
            alpha[23]++;
        }
        if(message[i]==89)
        {
            alpha[24]++;
        }
        if(message[i]==90)
        {
            alpha[25]++;
        }
    }
    int maxValue1 = alpha[0];
    int maxValue2 = alpha[0];
    int maxValue3 = alpha[0];
    int maxValue4 = alpha[0];
    int maxValue5 = alpha[0];
    int maxValue6 = alpha[0];
    int maxValue7 = alpha[0];
    int maxValue8 = alpha[0];
    int maxValue9 = alpha[0];
    int maxValue10 = alpha[0];
    int maxValue11 = alpha[0];
    int maxValue12 = alpha[0];
    int maxValue13 = alpha[0];
    int maxValue14 = alpha[0];
    int maxValue15 = alpha[0];
    int maxValue16 = alpha[0];
    int maxValue17 = alpha[0];
    int maxValue18 = alpha[0];
    int maxValue19 = alpha[0];
    int maxValue20 = alpha[0];
    int maxValue21 = alpha[0];
    int maxValue22 = alpha[0];
    int maxValue23 = alpha[0];
    int maxValue24 = alpha[0];
    int maxValue25 = alpha[0];
    int maxValue26 = alpha[0];
    int index1, index2, index3, index4, index5, index6, index7, index8, index9, index10, index11, index12, index13, index14, index15, index16, index17, index18, index19, index20, index21, index22, index23, index24, index25, index26;
    char alpha1[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[26];
    //Determine order in which letters occur, from most frequent to least frequent, and assign corresponding ciper[] values
    for(int k=0; k<26; k++)
    {
        if(alpha[k]>maxValue1)
        {
            maxValue1=alpha[k];
            index1=k+65;
            cipher[4] = index1;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue2) && (alpha[k]<maxValue1))
        {
            maxValue2=alpha[k];
            index2=k+65;
            cipher[19] = index2;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue3) && (alpha[k]<maxValue2))// && (alpha[k]<maxValue1))
        {
            maxValue3=alpha[k];
            index3=k+65;
            cipher[0] = index3;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue4) && (alpha[k]<maxValue3)) 
        {
            maxValue4=alpha[k];
            index4=k+65;
            cipher[8] = index4;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue5) && (alpha[k]<maxValue4))
        {
            maxValue5=alpha[k];
            index5=k+65;
            cipher[13] = index5;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue6) && (alpha[k]<maxValue5))
        {
            maxValue6=alpha[k];
            index6=k+65;
            cipher[14] = index6;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue7) && (alpha[k]<maxValue6))
        {
            maxValue7=alpha[k];
            index7=k+65;
            cipher[18] = index7;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue8) && (alpha[k]<maxValue7))
        {
            maxValue8=alpha[k];
            index8=k+65;
            cipher[7] = index8;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue9) && (alpha[k]<maxValue8))
        {
            maxValue9=alpha[k];
            index9=k+65;
            cipher[17] = index9;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue10) && (alpha[k]<maxValue9))
        {
            maxValue10=alpha[k];
            index10=k+65;
            cipher[3] = index10;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue11) && (alpha[k]<maxValue10))
        {
            maxValue11=alpha[k];
            index11=k+65;
            cipher[11] = index11;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue12) && (alpha[k]<maxValue11)) 
        {
            maxValue12=alpha[k];
            index12=k+65;
            cipher[20] = index12;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue13) && (alpha[k]<maxValue12)) 
        {
            maxValue13=alpha[k];
            index13=k+65;
            cipher[2] = index13;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue14) && (alpha[k]<maxValue13)) 
        {
            maxValue14=alpha[k];
            index14=k+65;
            cipher[12] = index14;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue15) && (alpha[k]<maxValue14)) 
        {
            maxValue15=alpha[k];
            index15=k+65;
            cipher[5] = index15;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue16) && (alpha[k]<maxValue15)) 
        {
            maxValue16=alpha[k];
            index16=k+65;
            cipher[22] = index16;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue17) && (alpha[k]<maxValue16)) 
        {
            maxValue17=alpha[k];
            index17=k+65;
            cipher[24] = index17;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue18) && (alpha[k]<maxValue17)) 
        {
            maxValue18=alpha[k];
            index18=k+65;
            cipher[6] = index18;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue19) && (alpha[k]<maxValue18)) 
        {
            maxValue19=alpha[k];
            index19=k+65;
            cipher[15] = index19;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue20) && (alpha[k]<maxValue19)) 
        {
            maxValue20=alpha[k];
            index20=k+65;
            cipher[1] = index20;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue21) && (alpha[k]<maxValue20)) 
        {
            maxValue21=alpha[k];
            index21=k+65;
            cipher[21] = index21;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue22) && (alpha[k]<maxValue21)) 
        {
            maxValue22=alpha[k];
            index22=k+65;
            cipher[10] = index22;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue23) && (alpha[k]<maxValue22)) 
        {
            maxValue23=alpha[k];
            index23=k+65;
            cipher[16] = index23;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue24) && (alpha[k]<maxValue23)) 
        {
            maxValue24=alpha[k];
            index24=k+65;
            cipher[9] = index24;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue25) && (alpha[k]<maxValue24)) 
        {
            maxValue25=alpha[k];
            index25=k+65;
            cipher[23] = index25;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue26) && (alpha[k]<maxValue25)) 
        {
            maxValue26=alpha[k];
            index26=k+65;
            cipher[25] = index26;
        }
    }
    for(int i=0; i<count; i++)  //For each character in array 'message', assign corresponing alpha[] values
    {
        if((message[i]>=65) && message[i]<=90)
        {
            for(int k=0; k<26; k++)
            {
                if(cipher[k]==message[i])
                {
                    message[i] = alpha1[k];
                    break;
                }
            }
        }
        else
        {
            message[i]=message[i];
        }
    }
    printf("%s\n", message);    //Print message to console
    fprintf(output_f, "%s", message);   //Write message to output file
    fclose(input_f);    //Close input_f.txt file
    fclose(output_f);   //Close output_f.txt file
    return 0;
}

//Function which takes an input and output file, decrypts day-1 encrypted message with a substitution cipher, without 
//knowledge of the key present in the input file and writes the decrypted message to 
//both the console and the output file
char task7(FILE *input_g, FILE *output_g)
{
    char c;
    char message[1000]; //Array containing characters present in message
    int alpha[26];  //Array containing number of times each letter occurs in encrypted message
    int count=0; 
    input_g = fopen("input_g.txt", "r");    //Open input_g.txt file
    output_g = fopen("output_g.txt", "w");  //Open output_g.txt file
    if(input_g == NULL) //Check if file is empty
    {
        perror("fopen()");
        return 0;
    }
    for (int i=0; i<26; i++)    //Initialise alpha array to zero
    {
        alpha[i]=0;
    }
    while(fscanf(input_g, "%c", &c)==1) //Scan characters from file input_g.txt
    {
        if (c>=97 && c<=122)    //Check if charcter is lower case
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
    for(int i=0; i<count; i++)  //Count how many times each letter occurs in the encrypted message
    {
        if(message[i]==65)
        {
            alpha[0]++;
        }
        if(message[i]==66)
        {
            alpha[1]++;
        }
        if(message[i]==67)
        {
            alpha[2]++;
        }
        if(message[i]==68)
        {
            alpha[3]++;
        }
        if(message[i]==69)
        {
            alpha[4]++;
        }
        if(message[i]==70)
        {
            alpha[5]++;
        }
        if(message[i]==71)
        {
            alpha[6]++;
        }
        if(message[i]==72)
        {
            alpha[7]++;
        }
        if(message[i]==73)
        {
            alpha[8]++;
        }
        if(message[i]==74)
        {
            alpha[9]++;
        }
        if(message[i]==75)
        {
            alpha[10]++;
        }
        if(message[i]==76)
        {
            alpha[11]++;
        }
        if(message[i]==77)
        {
            alpha[12]++;
        }
        if(message[i]==78)
        {
            alpha[13]++;
        }
        if(message[i]==79)
        {
            alpha[14]++;
        }
        if(message[i]==80)
        {
            alpha[15]++;
        }
        if(message[i]==81)
        {
            alpha[16]++;
        }
        if(message[i]==82)
        {
            alpha[17]++;
        }
        if(message[i]==83)
        {
            alpha[18]++;
        }
        if(message[i]==84)
        {
            alpha[19]++;
        }
        if(message[i]==85)
        {
            alpha[20]++;
        }
        if(message[i]==86)
        {
            alpha[21]++;
        }
        if(message[i]==87)
        {
            alpha[22]++;
        }
        if(message[i]==88)
        {
            alpha[23]++;
        }
        if(message[i]==89)
        {
            alpha[24]++;
        }
        if(message[i]==90)
        {
            alpha[25]++;
        }
    }
    int maxValue1 = alpha[0];
    int maxValue2 = alpha[0];
    int maxValue3 = alpha[0];
    int maxValue4 = alpha[0];
    int maxValue5 = alpha[0];
    int maxValue6 = alpha[0];
    int maxValue7 = alpha[0];
    int maxValue8 = alpha[0];
    int maxValue9 = alpha[0];
    int maxValue10 = alpha[0];
    int maxValue11 = alpha[0];
    int maxValue12 = alpha[0];
    int maxValue13 = alpha[0];
    int maxValue14 = alpha[0];
    int maxValue15 = alpha[0];
    int maxValue16 = alpha[0];
    int maxValue17 = alpha[0];
    int maxValue18 = alpha[0];
    int maxValue19 = alpha[0];
    int maxValue20 = alpha[0];
    int maxValue21 = alpha[0];
    int maxValue22 = alpha[0];
    int maxValue23 = alpha[0];
    int maxValue24 = alpha[0];
    int maxValue25 = alpha[0];
    int maxValue26 = alpha[0];
    int index1, index2, index3, index4, index5, index6, index7, index8, index9, index10, index11, index12, index13, index14, index15, index16, index17, index18, index19, index20, index21, index22, index23, index24, index25, index26;
    char alpha1[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[26];
    //Determine order in which letters occur, from most frequent to least frequent, and assign corresponding ciper[] values
    for(int k=0; k<26; k++)
    {
        if(alpha[k]>maxValue1)
        {
            maxValue1=alpha[k];
            index1=k+65;
            cipher[4] = index1;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue2) && (alpha[k]<maxValue1))
        {
            maxValue2=alpha[k];
            index2=k+65;
            cipher[19] = index2;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue3) && (alpha[k]<maxValue2))// && (alpha[k]<maxValue1))
        {
            maxValue3=alpha[k];
            index3=k+65;
            cipher[7] = index3;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue4) && (alpha[k]<maxValue3)) //&& (alpha[k]<maxValue2) && (alpha[k]<maxValue1))
        {
            maxValue4=alpha[k];
            index4=k+65;
            cipher[14] = index4;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue5) && (alpha[k]<maxValue4))// && (alpha[k]<maxValue3) && (alpha[k]<maxValue2) && (alpha[k]<maxValue1))
        {
            maxValue5=alpha[k];
            index5=k+65;
            cipher[8] = index5;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue6) && (alpha[k]<maxValue5))// && (alpha[k]<maxValue4) && (alpha[k]<maxValue3) && (alpha[k]<maxValue2) && (alpha[k]<maxValue1))
        {
            maxValue6=alpha[k];
            index6=k+65;
            cipher[0] = index6;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue7) && (alpha[k]<maxValue6))// && (alpha[k]<maxValue5) && (alpha[k]<maxValue4) && (alpha[k]<maxValue3) && (alpha[k]<maxValue2) && (alpha[k]<maxValue1))
        {
            maxValue7=alpha[k];
            index7=k+65;
            cipher[18] = index7;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue8) && (alpha[k]<maxValue7))// && (alpha[k]<maxValue6) && (alpha[k]<maxValue5) && (alpha[k]<maxValue4) && (alpha[k]<maxValue3) && (alpha[k]<maxValue2) && (alpha[k]<maxValue1))
        {
            maxValue8=alpha[k];
            index8=k+65;
            cipher[17] = index8;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue9) && (alpha[k]<maxValue8))// && (alpha[k]<=maxValue7) && (alpha[k]<=maxValue6) && (alpha[k]<=maxValue5) && (alpha[k]<=maxValue4) && (alpha[k]<=maxValue3) && (alpha[k]<=maxValue2) && (alpha[k]<=maxValue1))
        {
            maxValue9=alpha[k];
            index9=k+65;
            cipher[3] = index9;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue10) && (alpha[k]<maxValue9))// && (alpha[k]<=maxValue8) && (alpha[k]<=maxValue7) && (alpha[k]<=maxValue6) && (alpha[k]<=maxValue5) && (alpha[k]<=maxValue4) && (alpha[k]<=maxValue3) && (alpha[k]<=maxValue2) && (alpha[k]<=maxValue1))
        {
            maxValue10=alpha[k];
            index10=k+65;
            cipher[13] = index10;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue11) && (alpha[k]<maxValue10))// && (alpha[k]<=maxValue9) && (alpha[k]<=maxValue8) && (alpha[k]<=maxValue7) && (alpha[k]<=maxValue6) && (alpha[k]<=maxValue5) && (alpha[k]<=maxValue4) && (alpha[k]<=maxValue3) && (alpha[k]<=maxValue2) && (alpha[k]<=maxValue1))
        {
            maxValue11=alpha[k];
            index11=k+65;
            cipher[11] = index11;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue12) && (alpha[k]<maxValue11)) 
        {
            maxValue12=alpha[k];
            index12=k+65;
            cipher[20] = index12;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue13) && (alpha[k]<maxValue12)) 
        {
            maxValue13=alpha[k];
            index13=k+65;
            cipher[2] = index13;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue14) && (alpha[k]<maxValue13)) 
        {
            maxValue14=alpha[k];
            index14=k+65;
            cipher[5] = index14;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue15) && (alpha[k]<maxValue14)) 
        {
            maxValue15=alpha[k];
            index15=k+65;
            cipher[22] = index15;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue16) && (alpha[k]<maxValue15)) 
        {
            maxValue16=alpha[k];
            index16=k+65;
            cipher[15] = index16;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue17) && (alpha[k]<maxValue16)) 
        {
            maxValue17=alpha[k];
            index17=k+65;
            cipher[6] = index17;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue18) && (alpha[k]<maxValue17)) 
        {
            maxValue18=alpha[k];
            index18=k+65;
            cipher[24] = index18;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue19) && (alpha[k]<maxValue18)) 
        {
            maxValue19=alpha[k];
            index19=k+65;
            cipher[12] = index19;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue20) && (alpha[k]<maxValue19)) 
        {
            maxValue20=alpha[k];
            index20=k+65;
            cipher[10] = index20;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue21) && (alpha[k]<maxValue20)) 
        {
            maxValue21=alpha[k];
            index21=k+65;
            cipher[1] = index21;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue22) && (alpha[k]<maxValue21)) 
        {
            maxValue22=alpha[k];
            index22=k+65;
            cipher[22] = index22;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue23) && (alpha[k]<maxValue22)) 
        {
            maxValue23=alpha[k];
            index23=k+65;
            cipher[9] = index23;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue24) && (alpha[k]<maxValue23)) 
        {
            maxValue24=alpha[k];
            index24=k+65;
            cipher[16] = index24;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue25) && (alpha[k]<maxValue24)) 
        {
            maxValue25=alpha[k];
            index25=k+65;
            cipher[23] = index25;
        }
    }
    for(int k=0; k<26; k++)
    {
        if((alpha[k]>maxValue26) && (alpha[k]<maxValue25)) 
        {
            maxValue26=alpha[k];
            index26=k+65;
            cipher[25] = index26;
        }
    }
    for(int i=0; i<count; i++)  //For each character in array 'message', assign corresponing alpha[] values
    {
        if((message[i]>=65) && message[i]<=90)
        {
            for(int k=0; k<26; k++)
            {
                if(cipher[k]==message[i])
                {
                    message[i] = alpha1[k];
                    break;
                }
            }
        }
        else
        {
            message[i]=message[i];
        }
    }
    printf("%s\n", message);    //Print message to console
    fprintf(output_g, "%s", message);   //Write message to output file
    fclose(input_g);    //Close input_g.txt file
    fclose(output_g);   //Close output_g.txt file
    return 0;
}
