// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"
int main(void) {
  // defined in employeeSearchOne.c
  PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
  PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
  PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
  PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

  // defined in employeeTable.c
  extern Employee EmployeeTable[];
  extern const int EmployeeTableEntries;

  PtrToEmployee matchPtr;   // declaration
  
  matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 5045);
  // Example not found
  if (matchPtr != NULL) 
    printf("Employee ID 5045 is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Employee ID is NOT found in the record\n");

  // Example found
  matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Daphne Borromeo");
  if (matchPtr != NULL) 
    printf("Employee Daphne Borromeo is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Employee Daphne Borromeo is NOT found in the record\n");

  // search for phone number
  matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
  if (matchPtr != NULL)
    printf("Employee number: 714-555-2749 is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Employee number: 714-555-2749 is NOT found in the record\n");
  
  // search for salary
  matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
  if (matchPtr != NULL)
    printf("Employee salary of 7.80 is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Employee salary of 7.80 is NOT found in the record\n");

  return EXIT_SUCCESS;
}
