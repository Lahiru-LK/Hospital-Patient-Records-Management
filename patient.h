#ifndef PATIENT_H
#define PATIENT_H

// Definition of the Patient struct with various patient details.
typedef struct {
    char firstName[7];    // First name with a maximum length of 6 characters plus null terminator.
    char familyName[11];  // Family name with a maximum length of 10 characters plus null terminator.
    int department;       // Department number (1 to 6).
    int dailyCost;        // Daily cost in the hospital.
    int numberOfDays;     // Number of days in the hospital.
    int severity;         // Severity level (0 to 3).
} Patient;

// Function prototypes for handling patient records.
void populatePatientRecords(Patient *patients, int numRecords);
void printAllPatients(Patient *patients, int numRecords);
void summarizePatientRecords(Patient *patients, int numRecords);
void searchPatientsByFamilyName(Patient *patients, int numRecords);
void freePatientRecords(Patient *patients);

#endif
