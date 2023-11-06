#include <stdio.h>
#include <string.h>

struct process_Struct {
    char process_name[20];
    int arrival_time, burst_time, completion_time, remaining;
} temp_Struct;

void faculty_Queue(int no_of_process, int quantum_time) {
    int count;
    struct process_Struct faculty_Process[no_of_process];

    for (count = 0; count < no_of_process; count++) {
        printf("Enter the details of Process[%d]\n", count + 1);
        printf("Process Name : ");
        scanf("%s", faculty_Process[count].process_name);

        printf("Arrival Time : ");
        scanf("%d", &faculty_Process[count].arrival_time);

        printf("Burst Time : ");
        scanf("%d", &faculty_Process[count].burst_time);
        faculty_Process[count].remaining = faculty_Process[count].burst_time;
    }

    
    int time = 0;
    int remaining_processes = no_of_process;
    int current_process = 0;

    while (remaining_processes > 0) {
        if (faculty_Process[current_process].remaining > 0) {
            if (faculty_Process[current_process].remaining <= quantum_time) {
                time += faculty_Process[current_process].remaining;
                faculty_Process[current_process].remaining = 0;
                faculty_Process[current_process].completion_time = time;
                remaining_processes--;
            } else {
                time += quantum_time;
                faculty_Process[current_process].remaining -= quantum_time;
            }
        }
        current_process = (current_process + 1) % no_of_process;
    }

    
    printf("\nFaculty Queue Output:\n");
    printf("Process Name\tArrival Time\tBurst Time\tCompletion Time\n");
    for (count = 0; count < no_of_process; count++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", faculty_Process[count].process_name,
               faculty_Process[count].arrival_time, faculty_Process[count].burst_time, faculty_Process[count].completion_time);
    }
}

void student_Queue(int no_of_process, int quantum_time) {
    int count;
    struct process_Struct student_Process[no_of_process];

    for (count = 0; count < no_of_process; count++) {
        printf("Enter the details of Process[%d]\n", count + 1);
        printf("Process Name : ");
        scanf("%s", student_Process[count].process_name);

        printf("Arrival Time : ");
        scanf("%d", &student_Process[count].arrival_time);

        printf("Burst Time : ");
        scanf("%d", &student_Process[count].burst_time);
        student_Process[count].remaining = student_Process[count].burst_time;
    }

    int time = 0;
    int remaining_processes = no_of_process;
    int current_process = 0;

    while (remaining_processes > 0) {
        if (student_Process[current_process].remaining > 0) {
            if (student_Process[current_process].remaining <= quantum_time) {
                time += student_Process[current_process].remaining;
                student_Process[current_process].remaining = 0;
                student_Process[current_process].completion_time = time;
                remaining_processes--;
            } else {
                time += quantum_time;
                student_Process[current_process].remaining -= quantum_time;
            }
        }
        current_process = (current_process + 1) % no_of_process;
    }

    printf("\nStudent Queue Output:\n");
    printf("Process Name\tArrival Time\tBurst Time\tCompletion Time\n");
    for (count = 0; count < no_of_process; count++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", student_Process[count].process_name,
               student_Process[count].arrival_time, student_Process[count].burst_time, student_Process[count].completion_time);
    }
}

int main(int argc, char const *argv[]) {
    int select_queue, no_of_process, quantum_time;

    puts("Please choose a queue to post your query : ");
    puts("1. FACULTY queue.");
    puts("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &select_queue);

    switch (select_queue) {
        case 1:
            printf("Enter number of processes for FACULTY queue : ");
            scanf("%d", &no_of_process);
            printf("Enter the quantum time for FACULTY queue: ");
            scanf("%d", &quantum_time);

            faculty_Queue(no_of_process, quantum_time);

            break;

        case 2:
            printf("Enter number of processes for STUDENT queue : ");
            scanf("%d", &no_of_process);
            printf("Enter the quantum time for STUDENT queue: ");
            scanf("%d", &quantum_time);

            student_Queue(no_of_process, quantum_time);

            break;

        default:
            printf("Please select the correct option by running the program again.\n");
    }

    return 0;
}
