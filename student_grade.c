
#include <stdio.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[100];
    float marks[3];
    float total;
    float average;
    char grade;
};

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice, roll, i, j, found;

    do {
        printf("\n--- STUDENT GRADE MANAGEMENT SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Results\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX) {
                    printf("Student storage is full!\n");
                    break;
                }

                printf("Enter Roll Number: ");
                scanf("%d", &roll);

                found = 0;
                for (i = 0; i < count; i++) {
                    if (students[i].rollNo == roll) {
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Roll number already exists!\n");
                    break;
                }

                students[count].rollNo = roll;

                printf("Enter Student Name: ");
                scanf(" %99[^\n]", students[count].name);

                students[count].total = 0;

                for (j = 0; j < 3; j++) {
                    do {
                        printf("Enter marks for Subject %d (0-100): ",
                               j + 1);
                        scanf("%f", &students[count].marks[j]);

                        if (students[count].marks[j] < 0 ||
                            students[count].marks[j] > 100) {
                            printf("Invalid marks! Try again.\n");
                        }
                    } while (students[count].marks[j] < 0 ||
                             students[count].marks[j] > 100);

                    students[count].total +=
                        students[count].marks[j];
                }

                students[count].average =
                    students[count].total / 3.0;

                if (students[count].average >= 90)
                    students[count].grade = 'A';
                else if (students[count].average >= 75)
                    students[count].grade = 'B';
                else if (students[count].average >= 60)
                    students[count].grade = 'C';
                else if (students[count].average >= 40)
                    students[count].grade = 'D';
                else
                    students[count].grade = 'F';

                count++;
                printf("Student record added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No student records available.\n");
                    break;
                }

                printf("\n--- STUDENT RESULTS ---\n");

                for (i = 0; i < count; i++) {
                    printf("\nRoll Number: %d\n",
                           students[i].rollNo);
                    printf("Name: %s\n", students[i].name);
                    printf("Subject 1: %.2f\n",
                           students[i].marks[0]);
                    printf("Subject 2: %.2f\n",
                           students[i].marks[1]);
                    printf("Subject 3: %.2f\n",
                           students[i].marks[2]);
                    printf("Total: %.2f / 300\n",
                           students[i].total);
                    printf("Average: %.2f\n",
                           students[i].average);
                    printf("Grade: %c\n",
                           students[i].grade);
                }
                break;

            case 3:
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll);

                found = 0;
                for (i = 0; i < count; i++) {
                    if (students[i].rollNo == roll) {
                        printf("\nStudent Found!\n");
                        printf("Name: %s\n", students[i].name);
                        printf("Total: %.2f / 300\n",
                               students[i].total);
                        printf("Average: %.2f\n",
                               students[i].average);
                        printf("Grade: %c\n",
                               students[i].grade);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");
                break;

            case 4:
                printf("Exiting Student Grade System. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
