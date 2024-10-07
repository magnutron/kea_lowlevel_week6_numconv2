#include <stdio.h>
#include <stdlib.h>

#include "numconv1.h"

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_bin_digit(char c) {
    return (c == '0' || c == '1');
}

int is_oct_digit(char c) {
    return (c >= '0' && c <= '7');
}

int is_hex_digit(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

int bin_to_int(char str[]) {
    int result = 0;
    int i = 0;

    // Loop through the string until the null terminator '\0'
    while (str[i] != '\0') {
        // Check if the current character is a valid binary digit
        if (is_bin_digit(str[i])) {
            // Shift the result left by 1 (equivalent to multiplying by 2)
            result <<= 1;
            
            // If the character is '1', add 1 to the result
            if (str[i] == '1') {
                result += 1;
            }
        } else {
            // If an invalid character is found, print error message
            printf("----------------------\n");
            printf("Invalid binary number\n");
            printf("----------------------\n");
            return -1;
        }
        
        // Move to the next character
        i++;
    }
    
    return result;
}

int dec_to_int(char str[]) {
    int result = 0;
    int i = 0;

    // Loop through the string until the null terminator '\0'
    while (str[i] != '\0') {
        // Check if the current character is a valid decimal digit
        if (is_digit(str[i])) {
            // Shift the result to the left (equivalent to multiplying by 10)
            result = result * 10;
            
            // Convert the character to its numeric value and add it to the result
            result = result + (str[i] - '0');
        } else {
            // If an invalid character is found, print error message
            printf("----------------------\n");
            printf("Invalid decimal number\n");
            printf("----------------------\n");
            return -1;
        }
        
        // Move to the next character
        i++;
    }
    
    return result;
}

int oct_to_int(char str[]) {
    int result = 0;
    int i = 0;

    // Loop through the string until the null terminator '\0'
    while (str[i] != '\0') {
        // Check if the current character is a valid octal digit
        if (is_oct_digit(str[i])) {
            // Multiply result by 8 to shift to the next octal place
            result = result * 8;
            
            // Convert the character to its numeric value and add it to the result
            result = result + (str[i] - '0');
        } else {
            // If an invalid character is found, print error message
            printf("----------------------\n");
            printf("Invalid octal number\n");
            printf("----------------------\n");
            return -1;
        }
        
        // Move to the next character
        i++;
    }
    
    return result;
}


int hex_to_int(char str[]) {
    int result = 0;
    int i = 0;

    // Loop through the string until the null terminator '\0'
    while (str[i] != '\0') {
        // Check if the current character is a valid hexadecimal digit
        if (is_hex_digit(str[i])) {
            // Multiply result by 16 to shift to the next hexadecimal place
            result = result * 16;

            // Convert the character to its numeric value and add it to the result
            if (str[i] >= '0' && str[i] <= '9') {
                result += (str[i] - '0');
            } else if (str[i] >= 'A' && str[i] <= 'F') {
                result += (str[i] - 'A' + 10);
            } else if (str[i] >= 'a' && str[i] <= 'f') {
                result += (str[i] - 'a' + 10);
            }
        } else {
            // If an invalid character is found, print error message
            printf("----------------------\n");
            printf("Invalid hexadecimal number\n");
            printf("----------------------\n");
            return -1;
        }

        // Move to the next character
        i++;
    }

    return result;
}

void int_to_bin(int num, char str[]) {
    // Special case for zero
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0'; // Null-terminate the string
        return;
    }

    // Array to hold binary digits (temporary storage)
    char temp[33]; // 32 bits + null terminator

    int i = 0;
    while (num > 0) {
        // Get the least significant bit and convert to character
        temp[i] = (num % 2) + '0'; // Convert remainder to '0' or '1'
        num /= 2; // Divide by 2 to move to the next bit
        i++;
    }

    // Null-terminate the string
    temp[i] = '\0';

    // Reverse the temporary array and copy to the result string
    int j;
    for (j = 0; j < i; j++) {
        str[j] = temp[i - j - 1];
    }
    str[j] = '\0'; // Null-terminate the result string
}

void int_to_oct(int num, char str[]) {
    // Special case for zero
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0'; // Null-terminate the string
        return;
    }

    // Array to hold octal digits (temporary storage)
    char temp[12]; // 11 octal digits plus null terminator

    int i = 0;
    while (num > 0) {
        // Get the least significant octal digit and convert to character
        temp[i] = (num % 8) + '0'; // Convert remainder to '0'-'7'
        num /= 8; // Divide by 8 to move to the next octal place
        i++;
    }

    // Null-terminate the string
    temp[i] = '\0';

    // Reverse the temporary array and copy to the result string
    int j;
    for (j = 0; j < i; j++) {
        str[j] = temp[i - j - 1];
    }
    str[j] = '\0'; // Null-terminate the result string
}

void int_to_dec(int num, char str[]) {
    // Special case for zero
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0'; // Null-terminate the string
        return;
    }

    // Array to hold decimal digits (temporary storage)
    char temp[12]; // Enough for 10 digits plus null terminator for int (32-bit integer)

    int i = 0;
    while (num > 0) {
        // Get the least significant decimal digit and convert to character
        temp[i] = (num % 10) + '0'; // Convert remainder to '0'-'9'
        num /= 10; // Divide by 10 to move to the next decimal place
        i++;
    }

    // Null-terminate the string
    temp[i] = '\0';

    // Reverse the temporary array and copy to the result string
    int j;
    for (j = 0; j < i; j++) {
        str[j] = temp[i - j - 1];
    }
    str[j] = '\0'; // Null-terminate the result string
}


void int_to_hex(int num, char str[]) {
    // Special case for zero
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0'; // Null-terminate the string
        return;
    }

    // Array to hold hexadecimal digits (temporary storage)
    char temp[9]; // 8 hex digits plus null terminator

    int i = 0;
    while (num > 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            temp[i] = remainder + '0'; // Convert 0-9 to '0'-'9'
        } else {
            temp[i] = (remainder - 10) + 'A'; // Convert 10-15 to 'A'-'F'
        }
        num /= 16; // Divide by 16 to move to the next hexadecimal place
        i++;
    }

    // Null-terminate the string
    temp[i] = '\0';

    // Reverse the temporary array and copy to the result string
    int j;
    for (j = 0; j < i; j++) {
        str[j] = temp[i - j - 1];
    }
    str[j] = '\0'; // Null-terminate the result string
}


