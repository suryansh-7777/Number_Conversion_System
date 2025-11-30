#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/converter.h"

void decimaltobase(long long decimalnum, int base, char result[]) {
    if (decimalnum == 0) {
        strcpy(result, "0");
        return;
    }
    int i = 0;
    long long tempnum = decimalnum;
    while (tempnum != 0) {
        long long remainder = tempnum % base;
        char digit = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        result[i++] = digit;
        tempnum /= base;
    }
    result[i] = '\0';
    // Reverse string
    int len = strlen(result);
    for (int j = 0; j < len / 2; j++) {
        char temp = result[j];
        result[j] = result[len - 1 - j];
        result[len - 1 - j] = temp;
    }
}

long long basetodecimal(const char* numstr, int base) {
    long long decimalnum = 0;
    int len = strlen(numstr);
    int power = 0;
    for (int i = len - 1; i >= 0; i--) {
        char digit = numstr[i];
        int value;
        if (digit >= '0' && digit <= '9') value = digit - '0';
        else if (digit >= 'A' && digit <= 'F') value = digit - 'A' + 10;
        else if (digit >= 'a' && digit <= 'f') value = digit - 'a' + 10;
        else return -1; // Invalid character
        
        if (value >= base) return -2; // Invalid digit for base
        decimalnum += value * (long long)pow(base, power);
        power++;
    }
    return decimalnum;
}

void displaymenu() {
    printf("\n--- Number Conversion System Menu ---\n");
    printf("1. Convert Decimal (Base 10)\n");
    printf("2. Convert Binary (Base 2)\n");
    printf("3. Convert Octal (Base 8)\n");
    printf("4. Convert Hexadecimal (Base 16)\n");
    printf("5. Exit\n");
    printf("-------------------------------------\n");
}

void decimaltoall() {
    long long dec;
    printf("Enter Decimal Number (Base 10): ");
    if (scanf("%lld", &dec) != 1 || dec < 0) {
        dec = 0;
        printf("Invalid input. Please enter a positive integer.\n");
    }
    while (getchar() != '\n');
    
    char binaryres[64], octalres[64], hexres[64];
    decimaltobase(dec, 2, binaryres);
    decimaltobase(dec, 8, octalres);
    decimaltobase(dec, 16, hexres);
    
    printf("\nResults for %lld\n", dec);
    printf("---------------------------------\n");
    printf("Binary (Base 2): %s\n", binaryres);
    printf("Octal (Base 8): %s\n", octalres);
    printf("Hexadecimal (Base 16): %s\n", hexres);
    printf("---------------------------------\n");
}

void anybasetodecimal(int base) {
    char inputstr[64];
    printf("Enter Number in Base %d: ", base);
    scanf("%63s", inputstr);
    
    // Convert to uppercase
    for (int i = 0; inputstr[i]; i++) {
        if (inputstr[i] >= 'a' && inputstr[i] <= 'z') {
            inputstr[i] = inputstr[i] - 32;
        }
    }
    
    long long dec = basetodecimal(inputstr, base);
    printf("---------------------------------\n");
    if (dec == -1) {
        printf("ERROR: Invalid character detected in the input for Base %d.\n", base);
    } else if (dec == -2) {
        printf("ERROR: Invalid digit detected (e.g., 8 or 9 in Binary/Octal).\n");
    } else {
        printf("Input %s in Base %d = Decimal (Base 10): %lld\n", inputstr, base, dec);
    }
    printf("---------------------------------\n");
}
