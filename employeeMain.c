// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c

// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main (void) {
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    // search for number
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;     // declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1011);
    if (matchPtr != NULL) {
        printf("Employee ID 1011 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee ID 1011 is NOT found in the record\n");
    }

    // Example found
    // search for name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Brian Height");
    if (matchPtr != NULL) {
        printf("Employee Brian Height is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee Brian Height is NOT found in the record\n");
    }

    // search for phone number
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if (matchPtr != NULL) {
        printf("Employee phone of 310-555-1215 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee phone number: 310-555-1215 is NOT found in the record\n");
    }

    // search for salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);
    if (matchPtr != NULL) {
        printf("Employee salary of 6.34 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee with salary of 6.34 is NOT found in the record\n");
    }

    return EXIT_SUCCESS;
}