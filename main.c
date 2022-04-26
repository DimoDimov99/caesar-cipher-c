#include "ui.h"
#include "cipher.h"

int main()
{
    switch (user_choice())
    {
        case ENCRYPT_CHOSEN:
            encrypt_message();
            break;

        case DECRYPT_CHOSEN:
            decrypt_message();
            break;

        case INVALID_INPUT:
        default:
            break;
    }
}
