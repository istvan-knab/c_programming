#include <stdio.h>
#include <stdlib.h>

//
// Created by Knáb István Gellért on 27/04/2024.
//
int main(int argc, char* argv[])
{
    printf("Welcome to the decimal to hexadecimal Converter\n");
    printf("Please give a number in decimal format:");
    int number;
    scanf("%d", &number);
    printf("Decimal representation: %8d\n", number);
    printf("Hexadecimal representation: %8X\n", number);
    return 0;
}


