#include <stdio.h>
#include <string.h>

// Function to add two long positive integer numbers
void addLongIntegers(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int maxLen = len1 > len2 ? len1 : len2;
    int carry = 0;

    // Initialize the result with zeros
    for (int i = 0; i < maxLen + 1; i++) {
        result[i] = '0';
    }
    result[maxLen + 1] = '\0';

    // Perform addition from right to left
    for (int i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? (num1[len1 - 1 - i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[len2 - 1 - i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[maxLen - i] = (sum % 10) + '0';
    }

    result[0] = carry + '0';
}

int main() {
    char num1[100], num2[100], result[101];

    printf("Enter the first long positive integer: ");
    scanf("%s", num1);
    printf("Enter the second long positive integer: ");
    scanf("%s", num2);

    addLongIntegers(num1, num2, result);

    printf("Sum: %s\n", result);

    return 0;
}
