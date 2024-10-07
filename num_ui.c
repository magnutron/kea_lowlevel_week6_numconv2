#include <stdio.h>
#include <stdlib.h>

#include "numconv2.h"

// gcc -o numconv1 numconv1.c num_ui.c

void remove_newline(char *str) {
    char *p = str;
    while (*p != '\0') {
        if (*p == '\n') {
            *p = '\0';
            return;
        }
        p++;
    }
}

void read_line(char *str, int size) {
    if (fgets(str, size, stdin) != NULL) {
        remove_newline(str);
    }
}

void num_ui() {
    int choice;
    char input[256];
    char result[33];  // Buffer for the result (32 bits + null terminator)

    // Print menu
    printf("Select an option:\n");
    printf("1. Convert binary to integer\n");
    printf("2. Convert octal to integer\n");
    printf("3. Convert decimal to integer\n");
    printf("4. Convert hexadecimal to integer\n");
    printf("11. Convert integer to binary\n");
    printf("22. Convert integer to octal\n");
    printf("33. Convert integer to decimal\n");
    printf("44. Convert integer to hexadecimal\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-9): ");
    scanf("%d", &choice);
    getchar();  // Consume newline left by scanf

    switch (choice) {
        case 1: {
            printf("Enter binary string: ");
            read_line(input, sizeof(input));

            int bin_result = bin_to_int(input);
            if (bin_result != -1) {
                printf("----------------------\n");
                printf("The integer value of binary '%s' is %d\n", input, bin_result);
                printf("----------------------\n");
            }
            break;
        }
        case 2: {
            printf("Enter octal string: ");
            read_line(input, sizeof(input));

            int oct_result = oct_to_int(input);
            if (oct_result != -1) {
                printf("----------------------\n");
                printf("The integer value of octal '%s' is %d\n", input, oct_result);
                printf("----------------------\n");
            }
            break;
        }
                case 3: {
            printf("Enter decimal string: ");
            read_line(input, sizeof(input));

            int dec_result = dec_to_int(input);
            if (dec_result != -1) {
                printf("----------------------\n");
                printf("The integer value of decimal '%s' is %d\n", input, dec_result);
                printf("----------------------\n");
            }
            break;
        }
        case 4: {
            printf("Enter hexadecimal string: ");
            read_line(input, sizeof(input));

            int hex_result = hex_to_int(input);
            if (hex_result != -1) {
                printf("----------------------\n");
                printf("The integer value of hexadecimal '%s' is %d\n", input, hex_result);
                printf("----------------------\n");
            }
            break;
        }
        case 11: {
            int num;
            printf("Enter integer: ");
            scanf("%d", &num);
            getchar();  // Consume newline left by scanf

            int_to_bin(num, result);
            printf("----------------------\n");
            printf("The binary representation of %d is %s\n", num, result);
            printf("----------------------\n");
            break;
        }
        case 22: {
            int num;
            printf("Enter integer: ");
            scanf("%d", &num);
            getchar();  // Consume newline left by scanf

            int_to_oct(num, result);
            printf("----------------------\n");
            printf("The octal representation of %d is %s\n", num, result);
            printf("----------------------\n");
            break;
        }
        case 33: {
            int num;
            printf("Enter integer: ");
            scanf("%d", &num);
            getchar();  // Consume newline left by scanf

            int_to_dec(num, result);
            printf("----------------------\n");
            printf("The decimal representation of %d is %s\n", num, result);
            printf("----------------------\n");
            break;
        }
        case 44: {
            int num;
            printf("Enter integer: ");
            scanf("%d", &num);
            getchar();  // Consume newline left by scanf

            int_to_hex(num, result);
            printf("----------------------\n");
            printf("The hexadecimal representation of %d is %s\n", num, result);
            printf("----------------------\n");
            break;
        }
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice, please check the menu again (I know it may be confusing).\n");
    }
}

int main() {
    while (1) {
        num_ui();
    }
    return 0;
}