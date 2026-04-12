#include <stdio.h>
#include "events.h"

void printLine()  { printf("  =========================================\n"); }
void printThin()  { printf("  -----------------------------------------\n"); }

void showBanner() {
    printf("\n");
    printLine();
    printf("     C H R O N O S\n");
    printf("        Smart Calendar & Event Tracker\n");
    printLine();
}

void showMenu() {
    printf("\n");
    printThin();
    printf("   1.  Add Event\n");
    printf("   2.  View All Events\n");
    printf("   3.  Show Calendar\n");
    printf("   4.  Delete Event\n");
    printf("   5.  About\n");
    printf("   6.  Save & Exit\n");
    printThin();
    printf("\n   Choose: ");
}

void showAbout() {
    printf("\n");
    printLine();
    printf("   CHRONOS  -  Smart Calendar & Event Tracker\n");
    printThin();
    printf("   A console-based event management system\n");
    printf("   built in C. Add, view, and manage your\n");
    printf("   events with persistent CSV file storage.\n");
    printThin();
    printf("   Made by:\n\n");
    printf("   Rounak Agarwal       25CBE2938\n");
    printf("   Pragyan Gupta        25BDS0234\n");
    printf("   Abhivishrut Bishnoi  25BDS0148\n");
    printLine();
}

int main() {
    loadFromFile();
    showBanner();
    printf("   %d event(s) loaded.\n", eventCount);

    int choice;
    while (1) {
        showMenu();
        scanf("%d", &choice);
        if      (choice == 1) addEvent();
        else if (choice == 2) viewAll();
        else if (choice == 3) showCalendar();
        else if (choice == 4) deleteEvent();
        else if (choice == 5) showAbout();
        else if (choice == 6) {
            saveToFile();
            printf("\n  Saved. Goodbye.\n\n");
            break;
        }
        else printf("  Invalid choice.\n");
    }
    return 0;
}
