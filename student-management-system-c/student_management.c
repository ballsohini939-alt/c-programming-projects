#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
struct Student {
    int id;
    char name[50];
    int age;
    char course[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveStudents();
void loadStudents();
int isDuplicateID(int id);
int main() {
    int choice;
    loadStudents();
    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                saveStudents();
                printf("\nThank you for using Student Management System!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

void addStudent() {
    int id;
    int age;
    float marks;
    if (studentCount >= MAX_STUDENTS) {
        printf("\nStudent limit reached.\n");
        return;
    }
    printf("\n===== ADD STUDENT =====\n");
    printf("Enter Student ID: ");
    scanf("%d", &id);
    if (isDuplicateID(id)) {
        printf("\nError: Student ID already exists.\n");
        return;
    }
    if (id <= 0) {
        printf("\nError: Student ID must be positive.\n");
        return;
    }
    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[studentCount].name);
    printf("Enter Age: ");
    scanf("%d", &age);

    if (age < 1 || age > 100) {
        printf("\nError: Age must be between 1 and 100.\n");
        return;
    }
    printf("Enter Course: ");
    scanf(" %[^\n]", students[studentCount].course);
    printf("Enter Marks: ");
    scanf("%f", &marks);

    if (marks < 0 || marks > 100) {
        printf("\nError: Marks must be between 0 and 100.\n");
        return;
    }
    students[studentCount].id = id;
    students[studentCount].age = age;
    students[studentCount].marks = marks;
    studentCount++;
    saveStudents();
    printf("\nStudent added successfully!\n");
}

void displayStudents() {
    int i;
    if (studentCount == 0) {
        printf("\nNo students found.\n");
        return;
    }
    printf("\n===== ALL STUDENTS =====\n");
    for (i = 0; i < studentCount; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("-------------------------\n");
        printf("ID     : %d\n", students[i].id);
        printf("Name   : %s\n", students[i].name);
        printf("Age    : %d\n", students[i].age);
        printf("Course : %s\n", students[i].course);
        printf("Marks  : %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int id;
    int i;
    int found = 0;
    printf("\n===== SEARCH STUDENT =====\n");
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\nStudent found!\n");
            printf("-------------------------\n");
            printf("ID     : %d\n", students[i].id);
            printf("Name   : %s\n", students[i].name);
            printf("Age    : %d\n", students[i].age);
            printf("Course : %s\n", students[i].course);
            printf("Marks  : %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nStudent with ID %d not found.\n", id);
    }
}

void updateStudent() {
    int id;
    int i;
    int found = 0;
    int age;
    float marks;
    printf("\n===== UPDATE STUDENT =====\n");
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\nStudent found!\n");
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &age);
            if (age < 1 || age > 100) {
                printf("\nError: Age must be between 1 and 100.\n");
                return;
            }
            printf("Enter new course: ");
            scanf(" %[^\n]", students[i].course);
            printf("Enter new marks: ");
            scanf("%f", &marks);

            if (marks < 0 || marks > 100) {
                printf("\nError: Marks must be between 0 and 100.\n");
                return;
            }
            students[i].age = age;
            students[i].marks = marks;
            saveStudents();
            printf("\nStudent updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with ID %d not found.\n", id);
    }
}

void deleteStudent() {
    int id;
    int i;
    int found = 0;
    int j;
    printf("\n===== DELETE STUDENT =====\n");
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < studentCount; i++) {

        if (students[i].id == id) {
            for (j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }

            studentCount--;
            saveStudents();
            printf("\nStudent deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with ID %d not found.\n", id);
    }
}

int isDuplicateID(int id) {
    int i;
    for (i = 0; i < studentCount; i++) {

        if (students[i].id == id) {
            return 1;
        }
    }

    return 0;
}

void saveStudents() {
    FILE *file;
    file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("\nError: Unable to save student data.\n");
        return;
    }
    fwrite(
        students,
        sizeof(struct Student),
        studentCount,
        file
    );
    fclose(file);
}

void loadStudents() {
    FILE *file;
    file = fopen("students.dat", "rb");
    if (file == NULL) {
        return;
    }
    studentCount = fread(
        students,
        sizeof(struct Student),
        MAX_STUDENTS,
        file
    );
    fclose(file);
}

