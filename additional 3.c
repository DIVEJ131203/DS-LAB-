#include <stdio.h>
#include <stdlib.h>

// Structure to represent a booking
struct Booking {
    int machineNumber;
    int timeDuration;
    struct Booking* next;
    struct Booking* prev;
};

typedef struct Booking Booking;

Booking* createBooking(int machineNumber, int timeDuration) {
    Booking* newBooking = (Booking*)malloc(sizeof(Booking));
    newBooking->machineNumber = machineNumber;
    newBooking->timeDuration = timeDuration;
    newBooking->next = NULL;
    newBooking->prev = NULL;
    return newBooking;
}

// Function to insert a booking into the queue
Booking* insertBooking(Booking* head, int machineNumber, int timeDuration) {
    Booking* newBooking = createBooking(machineNumber, timeDuration);

    if (head == NULL) {
        newBooking->next = newBooking;
        newBooking->prev = newBooking;
        return newBooking;
    }

    newBooking->next = head;
    newBooking->prev = head->prev;
    head->prev->next = newBooking;
    head->prev = newBooking;
    return newBooking;
}

// Function to process the washing machine queue
Booking* processQueue(Booking* head) {
    if (head == NULL) {
        printf("No bookings in the queue.\n");
        return head;
    }

    printf("Machine %d started for %d minutes.\n", head->machineNumber, head->timeDuration);

    Booking* temp = head;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    head = head->next;
    head->prev = temp->prev;
    temp->prev->next = head;

    free(temp);

    return head;
}

// Function to display the queue
void displayQueue(Booking* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Booking* current = head;
    do {
        printf("Machine %d (%d minutes) -> ", current->machineNumber, current->timeDuration);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

int main() {
    Booking* queue = NULL;
    int choice;
    int machineNumber, timeDuration;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Book a washing machine\n");
        printf("2. Process the next machine\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter machine number: ");
                scanf("%d", &machineNumber);
                printf("Enter booking time (minutes): ");
                scanf("%d", &timeDuration);
                queue = insertBooking(queue, machineNumber, timeDuration);
                break;

            case 2:
                queue = processQueue(queue);
                break;

            case 3:
                displayQueue(queue);
                break;

            case 4:
                // Free the memory to avoid memory leaks
                while (queue != NULL) {
                    Booking* temp = queue;
                    queue = queue->next;
                    if (temp->next == temp) {
                        free(temp);
                        break;
                    }
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                }
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
