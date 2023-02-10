#include <stdio.h>
#include <string.h>

#define MAX_CHILDREN 5
#define MAX_NAME_LENGTH 20

struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    float salary;
    char childrenNames[MAX_CHILDREN][MAX_NAME_LENGTH];
    int childrenCounter;
};

void printChildren(struct Employee *array, int id) {
    int i;
    int found = 0;
    for (i = 0; i < 3; i++) {
        if (array[i].id == id) {
            if (array[i].childrenCounter == 0) {
                printf("The employee has no kids.\n");
                return;
            }
            int j;
            for (j = 0; j < array[i].childrenCounter; j++) {
                if (array[i].childrenNames[j][0] == 'S') {
                    printf("%s %s\n", array[i].childrenNames[j], array[i].name);
                    found = 1;
                }
            }
            if (!found) {
                printf("No children names starting with S\n");
            }
            return;
        }
    }
    printf("No employee with the specified id\n");
}

int main() {
    struct Employee employees[3];
    int i;
    for (i = 0; i < 3; i++) {
        printf("Enter employee #%d id: ", i + 1);
        char name [MAX_NAME_LENGTH];
        scanf("%d", &employees[i].id);
        printf("Enter employee name: ");
        getchar();
        gets(name);
        strcpy(employees[i].name,name);
        printf("Enter employee salary: ");
        scanf("%f", &employees[i].salary);
        printf("How many kids? ");
        scanf("%d", &employees[i].childrenCounter);
        if (employees[i].childrenCounter > MAX_CHILDREN) {
            printf("Can not store more than %d children\n", MAX_CHILDREN);
            employees[i].childrenCounter = MAX_CHILDREN;
        }
        int j;
        for (j = 0; j < employees[i].childrenCounter; j++) {
            printf("Enter child #%d name: ", j + 1);
            scanf("%s", employees[i].childrenNames[j]);
        }
    }
    int id;
    printf("Enter the id of the employee you would like to view his child’s name starting with letter S: ");
    scanf("%d", &id);
    printChildren(employees, id);

    return 0;
}
