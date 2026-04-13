#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <algorithm>

template <typename T>
struct DateComparator {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

class BaseEvent {
protected:
    std::string title;
    std::string time;
    char* notes;

public:
    BaseEvent(std::string t, std::string tm, std::string nt);
    virtual ~BaseEvent();
    virtual void triggerAlarm() const = 0;
    virtual void display() const;
};

class WorkEvent : public BaseEvent {
public:
    using BaseEvent::BaseEvent;
    void triggerAlarm() const override;
};

class PersonalEvent : public BaseEvent {
public:
    using BaseEvent::BaseEvent;
    void triggerAlarm() const override;
};

class Calendar {
private:
    std::multimap<std::string, std::unique_ptr<BaseEvent>, DateComparator<std::string>> schedule;

public:
    void addEvent(std::string date, std::unique_ptr<BaseEvent> ev);
    void showAll();
};

void printLine();
void printThin();
void showBanner();

#endif
