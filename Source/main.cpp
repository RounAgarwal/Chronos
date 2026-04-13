#include "events.h"

void showMenu() {
    printf("\n");
    printThin();
    printf("   1.  Add Work Event\n");
    printf("   2.  Add Personal Event\n");
    printf("   3.  Show Calendar\n");
    printf("   4.  About\n");
    printf("   5.  Exit\n");
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
    printf("   Pragyan Gupta        25BBS0052\n");
    printf("   Abhivishrut Bishnoi  25BDS0148\n");
    printLine();
}

int main() {
    Calendar myCal;
    int choice;

    showBanner();

    while (true) {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 5) {
            std::cout << "\n  Goodbye.\n";
            break;
        }

        if (choice == 1 || choice == 2) {
            std::string d, t, tm, n;
            std::cout << "\n  -- Add Event --\n";
            std::cout << "  Date (YYYY-MM-DD): "; std::cin >> d;
            std::cout << "  Title            : "; std::cin.ignore(); std::getline(std::cin, t);
            std::cout << "  Time (HH:MM)     : "; std::cin >> tm;
            std::cout << "  Notes            : "; std::cin.ignore(); std::getline(std::cin, n);

            if (choice == 1)
                myCal.addEvent(d, std::make_unique<WorkEvent>(t, tm, n));
            else
                myCal.addEvent(d, std::make_unique<PersonalEvent>(t, tm, n));
            
            std::cout << "  Event added.\n";
        } 
        else if (choice == 3) {
            myCal.showAll();
        } 
        else if (choice == 4) {
            showAbout();
        }
        else {
            std::cout << "  Invalid choice.\n";
        }
    }

    return 0;
}
