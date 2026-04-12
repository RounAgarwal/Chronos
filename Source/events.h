#ifndef EVENTS_H
#define EVENTS_H

#define MAX_EVENTS 100
#define DATA_FILE  "data.txt"

typedef struct {
    char title[50];
    char date[11];
    char time[6];
} Event;

extern Event events[];
extern int   eventCount;

void addEvent();
void viewAll();
void showCalendar();
void deleteEvent();
void saveToFile();
void loadFromFile();

#endif
