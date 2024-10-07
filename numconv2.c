#include <stdio.h>
#include <stdlib.h>

#include "numconv2.h"

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

    while (str[i] != '\0') {
        if (is_bin_digit(str[i])) {
            result = (result << 1) | (str[i] - '0');
        } else {
            printf("Invalid binary number\n");
            return -1;
        }
        i++;
    }
    return result;
}

int hex_to_int(char str[]) {
    int result = 0;
    int i = 0;

    while (str[i] != '\0') {
        result <<= 4; // Shift 4 bits to the left for hex digit
        if (str[i] >= '0' && str[i] <= '9') {
            result |= (str[i] - '0');
        } else if (str[i] >= 'A' && str[i] <= 'F') {
            result |= (str[i] - 'A' + 10);
        } else if (str[i] >= 'a' && str[i] <= 'f') {
            result |= (str[i] - 'a' + 10);
        } else {
            printf("Invalid hex number\n");
            return -1;
        }
        i++;
    }

    return result;
}

int oct_to_int(char str[]) {
    int result = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (is_oct_digit(str[i])) {
            result = (result << 3) | (str[i] - '0');
        } else {
            printf("Invalid octal number\n");
            return -1;
        }
        i++;
    }
    return result;
}

int dec_to_int(char str[]) {
    int result = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (is_digit(str[i])) {
            result = result * 10 + (str[i] - '0'); // Multiply result by 10 and add the new digit
        } else {
            printf("Invalid decimal number\n");
            return -1;
        }
        i++;
    }
    return result;
}

void int_to_bin(int num, char str[]) {
    for (int i = 31; i >= 0; i--) {
        str[31 - i] = (num & (1 << i)) ? '1' : '0';
    }
    str[32] = '\0';
}

void int_to_hex(int num, char str[]) {
    const char hex_chars[] = "0123456789ABCDEF";
    int i = 0;

    for (int shift = 28; shift >= 0; shift -= 4) {
        str[i++] = hex_chars[(num >> shift) & 0xF];
    }
    str[i] = '\0';
}

void int_to_oct(int num, char str[]) {
    int i = 0;
    int mask = 7; // Octal uses 3 bits

    while (num != 0) {
        str[i++] = (num & mask) + '0';
        num >>= 3;
    }
    str[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

void int_to_dec(int num, char str[]) {
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    char temp[12]; // Temporary storage for digits
    int i = 0;

    while (num > 0) {
        temp[i++] = (num % 10) + '0'; // Get the least significant digit
        num /= 10;
    }
    temp[i] = '\0';

    // Reverse the digits into the result string
    for (int j = 0; j < i; j++) {
        str[j] = temp[i - j - 1];
    }
    str[i] = '\0'; // Null-terminate
}
