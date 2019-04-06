#include <stdio.h>

char task1(char* message, int key, int n);  //Function prototype for task1 function
char task2(char* message, int key, int n);  //Function prototype for task2 function

int main()
{
    printf("Please select an option: \n");  //Ask the user which task they would like to run
    printf("a) Task 1\n");
    printf("b) Task 2\n");
    printf("c) Task 3\n");
    printf("Selection: ");
    
    char c = 'a';
   //scanf("%c", &c);
    
    do
    {
        switch(c)
        {
            case 'a':   //Encrypt a message with a rotation cipher
            {
                char message[100];
                int key, i, n;
                printf("Enter a message to be encrypted: ");
                scanf("%s", message);
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
                task1(message, key, n);
                break;
            }
            case 'b':   //Decrypt an encrypted message with a rotation cipher
            {
                char message[100];
                int key, i, n;
                printf("Enter a message to be decrypted: ");
                scanf("%s", message);
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
                task2(message, key, n);
                break;
            }
              //case 'c': task3();
              //break;
              default: printf("Unknown option %c\n Please enter a, b, c or d\n", c);   
        }

    }
    while (c < 'a' || c > 'd');
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
            for (i=0; i<n; i++)
            {
                if (message[i]>=0 && message[i]<=25)
                {
                    message[i] = (message[i] + key)%26;
                    message[i] = message[i]+65;
                }       
            }
        }
        if (message[i]>=65 && message[i]<=90)  //Test if character is lowercase
        {
            message[i] = message[i]-65;
            for (i=0; i<n; i++)
            {
                if (message[i]>=0 && message[i]<=25)
                {
                    message[i] = (message[i] + key)%26;
                    message[i] = message[i]+65;
                }       
            }
        }
    }
    
    //for (i=0; i<n; i++)
    //{
      //  if (message[i]>=0 && message[i]<=25)
        //{
          //  message[i] = (message[i] + key)%26;
        //}
    //}
    
    //for (i=0; i<n; i++)
    //{
      //  if (message[i]>=0 && message[i]<=25)
        //{
          //  message[i] = message[i]+65;
        //}
    //}
    
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
            message[i] = message[i]-32;
        }
        message[i] = message[i]-65;
    }
    
    for (i=0; i<n; i++)
    {
        message[i] = (message[i] - key)%26;
    }
    
    for (i=0; i<n; i++)
    {
        message[i] = message[i]+65;
    }
    
    printf("Encrypted message is: %s\n", message);
    return 0;
}


