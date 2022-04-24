#include <stdio.h>
#include <string.h>
#include <ctype.h>

char message[100];
char choice[9];

int get_key()
{
    int number;
    printf("Enter key: \n");
    if (scanf("%d", &number) == 1 && (number > 0 && number < 26))
    {
        // while (getchar() != '\n')
        // { }
        // return number;

        if (getchar() == '\n')
        {
            return number;
        }
    }

    printf("Invalid input\n");
    return -1;
}

int encrypt_message()
{
    int key = get_key();
    if (key == -1)
    {
        return -1;
    }

    printf("Enter message:\n");
    fgets(message, sizeof(message), stdin);
    for (int i = 0; message[i] != '\n'; i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' + key ) % 26) + 'A';
        }
    

        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' + key ) % 26) + 'a';
        }

        else
        {

        }
    }

    printf("Encrypted message is: %s\n", message);
    return 0;
}

int decrypt_message()
{
    int key = get_key();

    if (key == -1)
    {
        return -1;
    }

    printf("Enter message:\n");
    fgets(message, sizeof(message), stdin);
    for (int i = 0; message[i] != '\n'; i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (((message[i] - 'A' + (26 - key)) % 26) + 'A');
        }
    

        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (((message[i] - 'a' + (26 - key)) % 26) + 'a');

        }


        else
        {

        }
    }

    printf("Decrypted message is: %s\n", message);
    return 0;
}


int user_choice()
{
    printf("Type 'encrypt' to encrypt a message or type 'decrypt' to decrypt a message\n");
    fgets(choice, sizeof(choice), stdin);

    // convert for the choice to not be case sensitive
    for (int i = 0; i < sizeof(choice); i++)
    {
        choice[i] = tolower(choice[i]);
    }

    int decrypt_choice = strcmp(choice, "decrypt\n");
    int encrypt_choice = strcmp(choice, "encrypt\n");

    if (decrypt_choice == 0)
    {
        return decrypt_message();
    }

    else if (encrypt_choice == 0)
    {
        return encrypt_message();
    }

    else
    {
        printf("Invalid choice!\n");
        return -1;
    }
}

int main()
{
    return user_choice();
}
