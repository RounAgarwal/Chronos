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
    print("   1.  Add Event");
    print("   2.  View All Events");
    print("   3.  Show Calendar");
    print("   4.  Delete Event");
    print("   5.  About");
    print("   6.  Save & Exit");
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
    print("   Pragyan Gupta        25BDS0234");
    print("   Abhivishrut Bishnoi  25BDS0148");
    printLine();
}

// ---------- FEATURES ----------
function viewAll() {
    if (events.length === 0) {
        print("\n  No events found.");
        return;
    }

    print("");
    print("  No.   Title                          Date         Time");
    print("  -----------------------------------------");

    events.forEach((e, i) => {
        let num = String(i + 1).padEnd(4);
        let title = e.title.padEnd(30);
        let date = e.date.padEnd(12);
        print(`  ${num}  ${title}  ${date}  ${e.time}`);
    });

    print("");
}

function showCalendar() {
    if (events.length === 0) {
        print("\n  No events found.");
        return;
    }

    let seen = [];

    events.forEach(e => {
        if (!seen.includes(e.date)) seen.push(e.date);
    });

    seen.forEach(date => {
        print(`\n  Date: ${date}`);
        print("  -----------------------------------------");
        print("  Title                          Time");
        print("  -----------------------------------------");

        events.forEach(e => {
            if (e.date === date) {
                let title = e.title.padEnd(30);
                print(`  ${title}  ${e.time}`);
            }
        });
    });

    print("");
}

// ---------- MENU ----------
function handleMenu(choice) {
    if (choice === "1") {
        mode = "title";
        print("\n  -- Add Event --");
        setPrompt("  Title: ");
    }
    else if (choice === "2") {
        viewAll();
        showMenu();
    }
    else if (choice === "3") {
        showCalendar();
        showMenu();
    }
    else if (choice === "4") {
        if (events.length === 0) {
            print("\n  No events found.");
            showMenu();
            return;
        }
        viewAll();
        mode = "delete";
        setPrompt("  Enter number to delete: ");
    }
    else if (choice === "5") {
        showAbout();
        showMenu();
    }
    else if (choice === "6") {
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

// ---------- INPUT ----------
input.addEventListener("keydown", function(e) {
    if (e.key !== "Enter") return;

    let value = input.value.trim();
    print(`${promptEl.textContent}${value}`);
    input.value = "";

    if (mode === "menu") {
        handleMenu(value);
    }

    else if (mode === "title") {
        temp.title = value;
        mode = "date";
        setPrompt("  Date (YYYY-MM-DD): ");
    }

    else if (mode === "date") {
        temp.date = value;
        mode = "time";
        setPrompt("  Time (HH:MM): ");
    }

    else if (mode === "time") {
        temp.time = value;
        events.push(temp);
        temp = {};
        print("  Event added.");
        showMenu();
    }

    else if (mode === "delete") {
        let n = parseInt(value);

        if (n < 1 || n > events.length) {
            print("  Invalid number.");
        } else {
            print(`  Deleted: ${events[n - 1].title}`);
            events.splice(n - 1, 1);
        }

        showMenu();
    }
});

// ---------- START ----------
showBanner();
showMenu();