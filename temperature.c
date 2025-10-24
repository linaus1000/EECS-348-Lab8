// EECS 348 Lab 8
// Boolean Properties and Truth Tables
// Input: User inputed NFL Score
// Output: All of the possible combinations of scoring plays for a score
// ChatGPT helped with <ctype.h> and the use of toupper
// Austin Lin
// Creation date: 10/23/2025

#include <stdio.h>
#include <ctype.h> 

int main() {
    double temp, converted, celsius;
    char from, to;

    // Asks for the temp
    printf("Enter the temperature value: ");
    if (scanf("%lf", &temp) != 1) {
        printf("Invalid temperature value.\n");
        return 1;
    }

    // Asks for the original scale
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &from);
    from = toupper(from); // handle lowercase inputs

    // Asks for the target scale
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &to);
    to = toupper(to);

    // Checks if the scales are valid
    if ((from != 'C' && from != 'F' && from != 'K') ||
        (to != 'C' && to != 'F' && to != 'K')) {
        printf("Invalid scale entered. Please use C, F, or K.\n");
        return 1;
    }

    // Converts the input to Celsius first to catagorize temps later
    if (from == 'C')
        celsius = temp;
    else if (from == 'F')
        celsius = (temp - 32) * 5.0 / 9.0;
    else
        celsius = temp - 273.15;

    // Checks if Kelvin input is greater than or equal to 0
    if (from == 'K' && temp < 0) {
        printf("Invalid input: Kelvin cannot be negative.\n");
        return 1;
    }

    // Converts Celsius to target scale
    if (to == 'C')
        converted = celsius;
    else if (to == 'F')
        converted = (celsius * 9.0 / 5.0) + 32;
    else
        converted = celsius + 273.15;

    // Display results
    printf("\nConverted temperature: %.2lf %c\n", converted, to);

    // Categorize temp based on Celsius
    printf("Temperature category: ");
    if (celsius < 0) {
        printf("Freezing\nWeather advisory: Stay indoors and wear heavy jackets.\n");
    } else if (celsius < 10) {
        printf("Cold\nWeather advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Comfortable\nWeather advisory: Its nice outside.\n");
    } else if (celsius < 35) {
        printf("Hot\nWeather advisory: Drink lots of water!\n");
    } else {
        printf("Extreme Heat\nWeather advisory: Stay indoors and drink lots of water!\n");
    }

    return 0;
}
