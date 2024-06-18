#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "patient.h"

// Function to populate patient records with random data.
void populatePatientRecords(Patient *patients, int numRecords) {
    const char *firstNames[] = {"Emily", "Liam", "Sophia", "Noah", "Olivia", "Ethan", "Ava", "Lucas"};
    const char *familyNames[] = {"Smith", "Patel", "Tremblay", "Nguyen", "MacDonald"};

    srand((unsigned int)time(NULL)); // Seed for random number generation.

    for (int i = 0; i < numRecords; ++i) {
        // Randomly assign first name and family name.
        strcpy(patients[i].firstName, firstNames[rand() % 8]);
        strcpy(patients[i].familyName, familyNames[rand() % 5]);
        // Assign random values for department, daily cost, number of days, and severity.
        patients[i].department = (rand() % 6) + 1;
        patients[i].dailyCost = (rand() % 50) + 1;
        patients[i].numberOfDays = rand() % 31;
        patients[i].severity = rand() % 4;
    }
}

// Function to print all patient records.
void printAllPatients(Patient *patients, int numRecords) {
    // Print table headers.
    printf("%-4s %-7s %-11s %-11s %-10s %-10s %-8s\n", "No", "First", "Family", "Dept", "Cost", "Days", "Severity");
    // Print each patient's details.
    for (int i = 0; i < numRecords; ++i) {
        printf("%-4d %-7s %-11s %-11d %-10d %-10d %-8d\n",
               i+1, patients[i].firstName, patients[i].familyName,
               patients[i].department, patients[i].dailyCost,
               patients[i].numberOfDays, patients[i].severity);
    }
}

// Function to summarize patient records.
void summarizePatientRecords(Patient *patients, int numRecords) {
    int deptCount[6] = {0};  // Count of patients in each department.
    int totalCost = 0;       // Total daily cost of all patients.
    int totalDays = 0;       // Total number of days for all patients.
    int severityCount[4] = {0}; // Count of patients at each severity level.

    for (int i = 0; i < numRecords; ++i) {
        deptCount[patients[i].department - 1]++;
        totalCost += patients[i].dailyCost;
        totalDays += patients[i].numberOfDays;
        severityCount[patients[i].severity]++;
    }

    // Determine the severity level with the highest patient count.
    int maxSeverity = 0;
    for (int i = 1; i < 4; ++i) {
        if (severityCount[i] > severityCount[maxSeverity]) {
            maxSeverity = i;
        }
    }

    // Print the summary information.
    printf("Total number of patients: %d\n", numRecords);
    for (int i = 0; i < 6; ++i) {
        printf("Number of patients in department %d: %d\n", i+1, deptCount[i]);
    }
    printf("Average daily cost: %.2f\n", (float)totalCost / numRecords);
    printf("Average number of days: %.2f\n", (float)totalDays / numRecords);
    printf("Severity level with highest patient count: %d\n", maxSeverity);
}

// Function to search patients by family name.
void searchPatientsByFamilyName(Patient *patients, int numRecords) {
    char familyName[11];
    printf("Enter family name to search: ");
    scanf("%s", familyName); // Get the family name from the user.

    int found = 0; // Flag to check if any patient is found.
    // Print table headers.
    printf("%-4s %-7s %-11s %-11s %-10s %-10s %-8s\n", "No", "First", "Family", "Dept", "Cost", "Days", "Severity");
    for (int i = 0; i < numRecords; ++i) {
        if (strcmp(patients[i].familyName, familyName) == 0) { // Check if family name matches.
            found = 1;
            // Print patient details.
            printf("%-4d %-7s %-11s %-11d %-10d %-10d %-8d\n",
                   i+1, patients[i].firstName, patients[i].familyName,
                   patients[i].department, patients[i].dailyCost,
                   patients[i].numberOfDays, patients[i].severity);
        }
    }

    if (!found) {
        printf("No patient records found with family name: %s\n", familyName);
    }
}

// Function to free allocated memory for patient records.
void freePatientRecords(Patient *patients) {
    free(patients);
}
