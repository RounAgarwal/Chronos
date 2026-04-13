#include "events.h"
#include <iomanip>

void printLine() { std::cout << "  =========================================\n"; }
void printThin() { std::cout << "  -----------------------------------------\n"; }

void showBanner() {
    std::cout << "\n";
    printLine();
    std::cout << "     C H R O N O S\n";
    std::cout << "        Smart Calendar & Event Tracker\n";
    printLine();
}

BaseEvent::BaseEvent(std::string t, std::string tm, std::string nt) : title(t), time(tm) {
    notes = new char[nt.length() + 1];
    std::copy(nt.begin(), nt.end(), notes);
    notes[nt.length()] = '\0';
}

BaseEvent::~BaseEvent() {
    delete[] notes;
}

void BaseEvent::display() const {
    std::cout << "  " << std::left << std::setw(20) << title 
              << std::setw(10) << time 
              << "Note: " << notes;
}

void WorkEvent::triggerAlarm() const {
    std::cout << "  [URGENT WORK]";
}

void PersonalEvent::triggerAlarm() const {
    std::cout << "  [PERSONAL]";
}

void Calendar::addEvent(std::string date, std::unique_ptr<BaseEvent> ev) {
    schedule.insert(std::make_pair(date, std::move(ev)));
}

void Calendar::showAll() {
    if (schedule.empty()) {
        std::cout << "\n  No events found.\n";
        return;
    }

    std::string currentDate = "";
    for (auto const& [date, event] : schedule) {
        if (date != currentDate) {
            currentDate = date;
            std::cout << "\n  Date: " << currentDate << "\n";
            printThin();
            std::cout << "  " << std::left << std::setw(20) << "Title" 
                      << std::setw(10) << "Time" << "Details\n";
            printThin();
        }
        event->display();
        event->triggerAlarm();
        std::cout << "\n";
    }
}
