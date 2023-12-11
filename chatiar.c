#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void typeAndEnter(const char* message)
{
    size_t messageLength = strlen(message);

    for (size_t i = 0; i < messageLength; i++)
    {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = 0;
        input.ki.wScan = message[i];
        input.ki.dwFlags = KEYEVENTF_UNICODE;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;

        SendInput(1, &input, sizeof(INPUT));
    }

    // Simulate pressing and releasing the Enter key
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
}

int main()
{
    char limitInput[256];
    char message[256];

    printf("Enter limit: ");
    fgets(limitInput, sizeof(limitInput), stdin);
    int limit = atoi(limitInput);

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    int i = 0;

    printf("Delaying for 5 second...\n");
    Sleep(5000);

    while (i < limit)
    {
        typeAndEnter(message);
        i++;

        printf("%d\n", i);
        Sleep(1000); // Delay between sending each message
    }

    return 0;
}