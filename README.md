# Chronos — Smart Calendar & Event Tracker

A lightweight, console-based calendar and event tracker written in **C**. Built as a college project to demonstrate structured programming, file I/O, and modular code design using structs and functions.

---

## Live Demo

A web-based demo of the project interface is hosted via GitHub Pages:

**[https://rounagarwal.github.io/Chronos/](https://rounagarwal.github.io/Chronos/)**

---

## What It Does

- Add events with a title, date, and time
- View all events in a clean numbered list
- View a calendar grouped by date
- Delete events by number
- All events auto-save to `data.txt` on exit and reload on next run

---

## Running the Program

### Windows (pre-compiled)

A pre-compiled Windows executable is included in the root of this repository.

```
chronos.exe
```

Just double-click or run it from the terminal — no installation needed.

### Build from Source

If you want to compile it yourself, a `Build.bat` script is included in the `Source/` folder.

```
cd Source
Build.bat
```

Or compile manually using GCC:

```
gcc -o chronos main.c events.c
./chronos
```

---

## Project Structure

```
Chronos/
│
├── Source/
│   ├── main.c          # Menu loop and user input
│   ├── events.c        # All logic — add, view, delete, save, load
│   ├── events.h        # Event struct and function declarations
│   ├── data.txt        # Sample event data (CSV format)
│   └── Build.bat       # Windows build script
│
├── docs/
│   ├── index.html      # GitHub Pages demo page
│   ├── style.css       # Styles for the demo
│   └── script.js       # Scripts for the demo
│
├── chronos.exe         # Pre-compiled Windows executable
├── LICENSE             # License file
└── README.md           # You are here
```

---

## Data Storage

Events are stored in `data.txt` as plain CSV — one event per line:

```
Morning Standup,2025-04-14,09:00
Data Structures Exam,2025-04-17,10:00
Submit Project Report,2025-04-19,12:00
```

The file is loaded automatically when the program starts and saved when you exit.

---

## Sample Output

```
  =========================================
        C H R O N O S
        Smart Calendar & Event Tracker
  =========================================
   15 event(s) loaded.

  -----------------------------------------
   1.  Add Event
   2.  View All Events
   3.  Show Calendar
   4.  Delete Event
   5.  About
   6.  Save & Exit
  -----------------------------------------

  Date: 2025-04-17
  -----------------------------------------
  Title                           Time
  -----------------------------------------
  Final Exam Prep                 08:00
  Data Structures Exam            10:00
  Dinner with Family              19:00
```

---

## Made By

This project was built as part of a college programming assignment.

| Name | Registration Number |
|---|---|
| Rounak Agarwal | 25CBE2938 |
| Pragyan Gupta | 25BBS0052 |
| Abhivishrut Bishnoi | 25BDS0148 |

---

## License

This project is licensed under the terms in the [LICENSE](LICENSE) file.
