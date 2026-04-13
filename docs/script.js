let events = JSON.parse(localStorage.getItem("events")) || [];

const terminal = document.getElementById("terminal");
const input = document.getElementById("input");
const promptEl = document.getElementById("prompt");

let mode = "menu";
let temp = {};

// ---------- PRINT ----------
function print(text = "") {
    terminal.textContent += text + "\n";
    terminal.scrollTop = terminal.scrollHeight;
}

function printLine() {
    print("  =========================================");
}

function printThin() {
    print("  -----------------------------------------");
}

function setPrompt(text) {
    promptEl.textContent = text;
}

// ---------- STORAGE ----------
function save() {
    localStorage.setItem("events", JSON.stringify(events));
}

// ---------- UI ----------
function showBanner() {
    print("");
    printLine();
    print("     C H R O N O S");
    print("        Smart Calendar & Event Tracker");
    printLine();
    print(`   ${events.length} event(s) loaded.`);
}

function showMenu() {
    mode = "menu";
    print("");
    printThin();
    print("   1.  Add Work Event");
    print("   2.  Add Personal Event");
    print("   3.  Show Calendar");
    print("   4.  About");
    print("   5.  Save & Exit");
    printThin();
    print("");
    setPrompt("   Choose: ");
}

function showAbout() {
    print("");
    printLine();
    print("   CHRONOS  -  Smart Calendar & Event Tracker");
    printThin();
    print("   A console-based event management system");
    print("   built in C. Add, view, and manage your");
    print("   events with persistent CSV file storage.");
    printThin();
    print("   Made by:");
    print("");
    print("   Rounak Agarwal       25CBE2938");
    print("   Pragyan Gupta        25BBS0052");
    print("   Abhivishrut Bishnoi  25BDS0148");
    printLine();
}


// ---------- LOGIC (POLYMORPHISM SIMULATION) ----------
function triggerAlarm(type, title) {
    if (type === "Work") {
        return `  >>> [URGENT] Professional Meeting Alert: ${title} <<<`;
    } else {
        return `  >>> [REMINDER] Personal Activity: ${title} <<<`;
    }
}

function showCalendar() {
    if (events.length === 0) {
        print("\n  No events found.");
        return;
    }

    // Sort by Date (Simulating STL Multimap behavior)
    let sortedEvents = [...events].sort((a, b) => a.date.localeCompare(b.date));

    let currentDate = "";

    sortedEvents.forEach(e => {
        if (e.date !== currentDate) {
            currentDate = e.date;
            print(`\n  Date: ${currentDate}`);
            printThin();
            print("  Title                Time      Details");
            printThin();
        }
        
        print(triggerAlarm(e.type, e.title));
        let title = e.title.padEnd(20);
        let time = e.time.padEnd(10);
        print(`  ${title} ${time} Note: ${e.notes}`);
    });

    print("");
}

// ---------- MENU HANDLER ----------
function handleMenu(choice) {
    if (choice === "1" || choice === "2") {
        temp.type = (choice === "1") ? "Work" : "Personal";
        mode = "date";
        print(`\n  -- Add ${temp.type} Event --`);
        setPrompt("  Date (YYYY-MM-DD): ");
    }
    else if (choice === "3") {
        showCalendar();
        showMenu();
    }
    else if (choice === "4") {
        showAbout();
        showMenu();
    }
    else if (choice === "5") {
        save();
        print("\n  Saved. Goodbye.\n");
        setPrompt("");
        input.disabled = true;
    }
    else {
        print("  Invalid choice.");
        showMenu();
    }
}

// ---------- INPUT LOOP ----------
input.addEventListener("keydown", function(e) {
    if (e.key !== "Enter") return;

    let value = input.value.trim();
    print(`${promptEl.textContent}${value}`);
    input.value = "";

    if (mode === "menu") {
        handleMenu(value);
    }
    else if (mode === "date") {
        temp.date = value;
        mode = "title";
        setPrompt("  Title: ");
    }
    else if (mode === "title") {
        temp.title = value;
        mode = "time";
        setPrompt("  Time (HH:MM): ");
    }
    else if (mode === "time") {
        temp.time = value;
        mode = "notes";
        setPrompt("  Notes: ");
    }
    else if (mode === "notes") {
        temp.notes = value;
        events.push(temp);
        temp = {};
        print("  Event added.");
        showMenu();
    }
});

showBanner();
showMenu();
