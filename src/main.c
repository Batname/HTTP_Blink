#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>

char *menu =
"========================\n"
"Supplied with electricity: 1\n"
"Turn off electricity: 0\n"
"Exit: 9\n"
"========================\n"; 


void cleanMenu(char *message)
{
    fputs("\033c", stdout);
    printf("%s\n", message);
    printf("Enter new value\n");
}

int main(void)
{
    int input, int_result;
    char message[50];

    fputs("\033c", stdout);
    printf("Enter a value \n");
   
    // program loop
    while(1)
    {

        printf("%s", menu);
        printf("> ");
        int_result = scanf(" %d", &input);    

        if (!int_result) break;

        if (input == 0)
        {
            strcpy(message, "now electrisity is 0");
        }
        else if (input == 1)
        {
            strcpy(message, "now electrisity is 1");
        }
        else if (input == 9)
        {
            printf("exiting program\n");
            exit(0);
        }
        else
        {
            strcpy(message, "incurrect");
        }
    

        cleanMenu(message);
    }

    return 0;
}
