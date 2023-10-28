#include <stdio.h>
#include <stddef.h>
typedef struct {
    long number;
    char *name;
    char *phone;
    double salary;
} Employee, *PtrToEmployee;

typedef const Employee *PtrToConstEmployee;

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number);
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char *name);
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char *phone);
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary);

