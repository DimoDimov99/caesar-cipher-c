#ifndef CAESAR_CIPHER_UI_INCLUDE_GUARD
#define CAESAR_CIPHER_UI_INCLUDE_GUARD

#define INVALID_INPUT -1
#define ENCRYPT_CHOSEN 1
#define DECRYPT_CHOSEN 2

int get_key();
int user_choice();
int get_message(char message[], int size);

void display_result(char message[], int action);

#endif // CAESAR_CIPHER_UI_INCLUDE_GUARD