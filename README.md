# Number Conversion System

A modular C program that converts between Decimal (Base 10), Binary (Base 2), Octal (Base 8), and Hexadecimal (Base 16) number systems.

## Features
- Decimal → Binary/Octal/Hex conversion
- Binary/Octal/Hex → Decimal conversion
- Input validation & error handling
- Case-insensitive hex input (a-f/A-F)
- Clean menu-driven interface

## Project Structure
a)src/
- main.c # Main program entry
- converter.c # Conversion logic
b)include/
- converter.h # Function declarations
c)docs/
- ProjectReport.pdf # Full documentation
d)README.md

## Algorithms Used

1. **Decimal to Base**: Repeated division by base, remainders give digits (reversed)
2. **Base to Decimal**: Positional notation with powers (right-to-left evaluation)

## Error Handling
- Invalid characters: Returns -1
- Invalid digits for base: Returns -2 (e.g., '8' in binary)
- Negative decimal input rejected

## Team Members
- [suryansh raghuwanshi] - @suryansh-7777
- [vinay rewar ] - @vinayrewar23-hub

## Technologies
- C99 Standard
- GCC Compiler
- Modular design (header/source separation)

---
**University of Petroleum and Energy Studies | CSEG1032 Major Project**

