#include <stdio.h>
#include <string.h>
#include "events.h"

Event events[MAX_EVENTS];
int   eventCount = 0;

void addEvent() {
    if (eventCount >= MAX_EVENTS) {
        printf("  Event list full.\n");
        return;
    }
    Event e;
    printf("\n  -- Add Event --\n");
    printf("  Title            : "); scanf(" %[^\n]", e.title);
    printf("  Date (YYYY-MM-DD): "); scanf(" %[^\n]", e.date);
    printf("  Time (HH:MM)     : "); scanf(" %[^\n]", e.time);
    events[eventCount++] = e;
    printf("  Event added.\n");
}

void viewAll() {
    if (eventCount == 0) { printf("\n  No events found.\n"); return; }
    printf("\n  %-4s  %-30s  %-12s  %s\n", "No.", "Title", "Date", "Time");
    printf("  -----------------------------------------\n");
    for (int i = 0; i < eventCount; i++) {
        printf("  %-4d  %-30s  %-12s  %s\n",
            i + 1,
            events[i].title,
            events[i].date,
            events[i].time);
    }
    printf("\n");
}

void showCalendar() {
    if (eventCount == 0) { printf("\n  No events found.\n"); return; }

    char seen[MAX_EVENTS][11];
    int  seenCount = 0;

    for (int i = 0; i < eventCount; i++) {
        int found = 0;
        for (int j = 0; j < seenCount; j++)
            if (strcmp(seen[j], events[i].date) == 0) { found = 1; break; }
        if (!found) strcpy(seen[seenCount++], events[i].date);
    }

    for (int i = 0; i < seenCount; i++) {
        printf("\n  Date: %s\n", seen[i]);
        printf("  -----------------------------------------\n");
        printf("  %-30s  %s\n", "Title", "Time");
        printf("  -----------------------------------------\n");
        for (int j = 0; j < eventCount; j++)
            if (strcmp(events[j].date, seen[i]) == 0)
                printf("  %-30s  %s\n", events[j].title, events[j].time);
    }
    printf("\n");
}

void deleteEvent() {
    viewAll();
    if (eventCount == 0) return;
    int n;
    printf("  Enter number to delete: ");
    scanf("%d", &n);
    if (n < 1 || n > eventCount) { printf("  Invalid number.\n"); return; }
    printf("  Deleted: %s\n", events[n-1].title);
    for (int i = n - 1; i < eventCount - 1; i++)
        events[i] = events[i + 1];
    eventCount--;
}

void saveToFile() {
    FILE* f = fopen(DATA_FILE, "w");
    if (!f) { printf("  Could not save.\n"); return; }
    for (int i = 0; i < eventCount; i++)
        fprintf(f, "%s,%s,%s\n", events[i].title, events[i].date, events[i].time);
    fclose(f);
}

void loadFromFile() {
    FILE* f = fopen(DATA_FILE, "r");
    if (!f) return;
    while (eventCount < MAX_EVENTS &&
           fscanf(f, " %49[^,],%10[^,],%5[^\n]",
                  events[eventCount].title,
                  events[eventCount].date,
                  events[eventCount].time) == 3)
        eventCount++;
    fclose(f);
}
