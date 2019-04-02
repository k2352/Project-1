#include <stdio.h>

char task1(char* message, int key);

int main()
{
    printf("Please select an option: \n");
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
              case 'a':
              {
                  char message[100];
                  int key;
                  printf("Enter a message to be encrypted: ");
                  scanf("%s", message);
                  printf("Enter the key: ");
                  scanf("%d", &key);
                  task1(message, key);
                  break;
              }
             
              //break;
              //case 'b': task2();
              //break;
              //case 'c': task3();
              //break;
              default: printf("Unknown option %c\n Please enter a, b, c or d\n", c);   
        }

    }
    while (c < 'a' || c > 'd');
    return 0;   
}

char task1(char* message, int key)
{
    //char encrypt[];
    int i;
   // && message[i] != '\0'
    for (i=0; i<100 ; i++)
    {
        message[i] = message[i] + key;
    }
    
    //for (i=0; message[i] != '\0'; i++)
    //{
      //  encrypt = message[i];
        
        //if (encrypt >= 'a' && encrypt <= 'z')
        //{
          //  encrypt = encrypt + key;
        //}  
    //}
    printf("Encrypted message is: %s", message);

    return 0;
}

