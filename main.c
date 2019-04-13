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
//tgasbdbjsabdjakgdyga
char task1(char* message, int key, int n);  //Function prototype for task1 function
char task2(char* message, int key, int n);  //Function prototype for task2 function
char task5(char* message, int n);           //Function prototype for task5 function
//FILE *checkWord;

int main()
{
    printf("Please select an option: \n");  //Ask the user which task they would like to run
    printf("a) Task 1\n");
    printf("b) Task 2\n");
    printf("c) Task 3\n");
    printf("e) Task 5\n");
    printf("Selection: ");
    
    char c = 'a';
   //scanf("%c", &c);
    
    do
    {
        switch(c)
        {
            case 'a':   //Encrypt a message with a rotation cipher
            {
                //char message[100];
                char message[] = "hello world!";
                int key, i, n;
                //printf("Enter a message to be encrypted: ");
                //scanf("%s", message);
                for (i=0; i<100; i++)   //Determine how many characters are in the array
                {
                    if (message[i] != '\0')
                    {
                        n++;
                    }
                    else
                    {
                        break;
                    }
                  
                }
                printf("Enter the key: ");
                scanf("%d", &key);
                while ((key<0) || (key>26))
                {
                    printf("Invalid key. Please try again.");
                    scanf("%d", &key);
                }
                task1(message, key, n);
                break;
            }
            case 'b':   //Decrypt an encrypted message with a rotation cipher
            {
                //char message[100];
                char message[] = "ifmmp xpsme!";
                //char message[] = "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB";
               
                int key, i, n;
                //printf("Enter a message to be decrypted: ");
                //scanf("%s", message);
                for (i=0; i<100; i++)   //Determine how many characters are in the array
                {
                    if (message[i] != '\0')
                    {
                        n++;
                    }
                    else
                    {
                        break;
                    }  
                }
                printf("Enter the key: ");
                scanf("%d", &key);
                while ((key<0) || (key>26))
                {
                    printf("Invalid key. Please try again.");
                    scanf("%d", &key);
                }
                task2(message, key, n);
                break;
            }
            //case 'e':
            //{
                //char message[100];
              //  char message[200] = "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB";
                //int i, n;
                //printf("Enter a message to be decrypted: ");
                //scanf("%s", message);
                //for (i=0; i<100; i++)   //Determine how many characters are in the array
                //{
                  //  if (message[i] != '\0')
                    //{
                      //  n++;
                    //}
                    //else
                    //{
                      //  break;
                    //}  
                //}
                //task5(message, n);
                //break;
            //}
            default: printf("Unknown option %c\n Please enter a, b, c or d\n", c);   
        }

    }
    while (c < 'a' || c > 'f');
    return 0;   
}

//Function which takes a message, key and number of characters in an array as input
//and returns the message encrypted
char task1(char* message, int key, int n)
{
    int i;
    
    for (i=0; i<n; i++)
    {
        if (message[i]>=97 && message[i]<=122)  //Test if character is lowercase
        {
            message[i] = message[i]-97;
            message[i] = (message[i] + key)%26;
            message[i] = message[i]+65;
        }
        else if (message[i]>=65 && message[i]<=90)
        {
            message[i] = message[i]-65;
            message[i] = (message[i] + key)%26;
            message[i] = message[i]+65;
        }
        //if ((message[i]>=32 && message[i]<=64) || (message[i]>=91 && message[i]<=96) || (message[i]>=123 && message[i]<=126))
        else
        {
            message[i] = message[i];
        }
    }
    printf("Encrypted message is: %s\n", message);
    return 0;
}

//Function which takes an encrypted message, key and number of characters in an array as input
//and returns the message decrypted
char task2(char* message, int key, int n)
{
    int i;
    
    for (i=0; i<n; i++)
    {
        if (message[i]>=97 && message[i]<=122)
        {
            message[i] = message[i]-97;
            message[i] = (message[i] - key)%26;
            message[i] = message[i]+65;
        }
        
        else if (message[i]>=65 && message[i]<=90)
        {
            message[i] = message[i]-65;
            message[i] = (message[i] - key)%26;
            message[i] = message[i]+65;
        }
        
        else
        //if ((message[i]>=32 && message[i]<=64) || (message[i]>=91 && message[i]<=96) || (message[i]>=123 && message[i]<=126))
        {
            message[i] = message[i];
        }
    }
    printf("Decrypted message is: %s\n", message);
    return 0;
}

//Function which takes an encrypted message and number of characters in an array as input
//and returns the message decrypted without knowledge of the key
//char task5(char* message, int n)
//{
    //checkWord = fopen("words.txt", "r");
    //if(checkWord == NULL) 
    //{
      //  perror("fopen()");
        //return 0;
    //}
  //  int i, key, k, compare;
    //const char c[10] = "the";
    //char *result;
    
    //for (k=0; k<1; k++)
    //{
      //  for (i=0; i<n; i++)
        //{
          //  if (message[i]>=97 && message[i]<=122)
            //{
              //  message[i] = message[i]-97;
                //message[i] = (message[i] - k)%26;
                //message[i] = message[i]+97;
            //}
            //else if (message[i]>=65 && message[i]<=90)
            //{
              //  message[i] = message[i]-65;
                //message[i] = (message[i] - k)%26;
                //message[i] = message[i]+97;
            //}
            //else
            //{
              //  message[i] = message[i];
            //}
        //}
        //result = strstr(message, c);
        //if (result != NULL)
        //{
          //  printf("%s", result);
        //}
//    }

        //printf("\nDecrypted message is: %s\n", message);
        //while(!feof(checkWord))
        //{
          //  fscanf(checkWord, "%c", c);
            //printf("%c", *c);
            //char str1[] = "arbor";
            //if(strstr(c, str1) != NULL)
            //
               // printf("yes");
            //}
            //if (strstr(message, c) != NULL)
            //{
                //printf("yes\n");
                //break;
            //}
            //else
            //{
              //  printf("yes");
                //break;
            //}
            
            
            //compare = strcmp(message, c);
            //printf("\nDecrypted message is: %s\n", message);
            //if (compare==0)
            //{
              //  key=k;
                //printf("%d\n", key);
                //printf("\nDecrypted message is: %s\n", message);
                //break;
            //}
            //else
            //{
              //  printf("error");
                //break;
            //}

            //printf("%d\n", compare);
            
            
        
        //{
          //  char c;
            //fscanf(checkWord, "%c", &c);
            //printf("%c", c);
        //}
        //fscanf(checkWord, "%s", strg);
        //printf("%s\n", strg);
        //printf("\nDecrypted message is: %s\n", message);
        
        
   // }
  //  return 0;
//}