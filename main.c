#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

// Function to display the menu.
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Print all patient records.\n");
    printf("2. Summary of the patient records.\n");
    printf("3. Search for all patients by Family Name.\n");
    printf("4. Size of the structure.\n");
    printf("5. Quit.\n\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) { // Check if the number of arguments is correct.
        fprintf(stderr, "Usage: %s <number_of_records>\n", argv[0]);
        return 1;
    }

    int numRecords = atoi(argv[1]); // Convert argument to integer.
    if (numRecords < 6 || numRecords > 19) { // Validate the number of records.
        fprintf(stderr, "Error: Number of records must be between 6 and 19.\n");
        return 1;
    }

    Patient *patients = malloc(numRecords * sizeof(Patient)); // Allocate memory for patient records.
    if (!patients) {
        perror("Failed to allocate memory");
        return 1;
    }

    populatePatientRecords(patients, numRecords); // Populate the patient records.

    int option;
    do {
        displayMenu(); // Display the menu.
        printf("Enter your choice: ");
        scanf("%d", &option);
        printf("\n\n");

        switch (option) {
            case 1:
                printAllPatients(patients, numRecords);
                break;
            case 2:
                summarizePatientRecords(patients, numRecords);
                break;
            case 3:
                searchPatientsByFamilyName(patients, numRecords);
                break;
            case 4:
                printf("Size of the structure: %lu bytes\n", sizeof(Patient));
                break;
            case 5:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);

    freePatientRecords(patients); // Free the allocated memory.
    return 0;
}
