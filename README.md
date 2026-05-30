# Assignment 3 – Kanban Board (C)

A terminal-based Kanban board application written in C, using a doubly linked list structure to manage lists and their elements.

**Repository:** https://csgitlab.ucd.ie/BenjaminKarioki/jiahongben-assignment3.git

## Authors

| Member | Contributions |
|--------|--------------|
| Jiahong Liu | Main structure, Display (Option 1), Load file (Option 2), Save file (Option 5), Free memory |
| Benjamin Karioki | Edit list (Option 3), Edit board (Option 4) |

---

## Data Structure

The board is represented as a **doubly linked list of lists**, where each list node holds its own doubly linked list of elements.

- `nextE` / `lastE` — forward/backward pointers for element nodes
- `nextL` / `lastL` — forward/backward pointers for list nodes

Two enumerations are used to report the status of load and save operations, aiding debugging.

---

## Features

The program launches with an ASCII art title and a menu driven by a `do-while` loop. The user enters a number (1–6) to select an option.

### Option 1 – Display Board
Renders the full board to the terminal using a nested `while` loop: the outer loop traverses each list node, and the inner loop traverses each element within it. Empty boards display a hint message.

### Option 2 – Load File
Reads a `.csv` file to populate the board.

- Prompts the user for a valid `.csv` filename (confirmed before loading)
- Reads each line, splitting it into a list name and an element name
- Handles lists with no elements
- Traverses existing list nodes — creates a new list node if it doesn't exist, or reuses one that does
- New list nodes are inserted at the head of the board

### Option 3 – Edit List
Modifies the elements inside a specific list. Uses `findList` to locate the target list and `findElement` to locate elements within it.

**Rename item** (`editList.c`, lines 36–60)
- Locates the element by name
- Replaces the old name with the new one using `strcpy`

**Add item** (`editList.c`, lines 63–81)
- Allocates a new element node with `malloc`
- Inserts it at the head of the element linked list
- Updates `nextE` and `lastE` pointers

**Delete item** (`editList.c`, lines 84–129)
- Handles two cases: head node deletion and mid-list deletion
- Reconnects neighbouring nodes and frees memory with `free()`

### Option 4 – Edit Board
Modifies the board structure (lists, not elements). Provides a submenu via `printBoardOptions`.

**Rename list** (`editList.c`, lines 131–146)
- Finds the list using `findList` and updates its name with `strcpy`

**Add new list** (`editList.c`, lines 148–167)
- Allocates a new list node with `malloc`
- Inserts at the head of the board linked list
- Updates `nextL` and `lastL` pointers

**Delete list** (`editList.c`, lines 169–186)
- Handles head-node and mid-list deletion
- Calls `freeElements` to release all element nodes before freeing the list node

### Option 5 – Save File
Saves the board to a `.csv` file.

- Prompts the user for a filename (confirmed before writing)
- Uses **recursion** to write lists in the correct order — since loading inserts at the head, saving must write from the tail first to preserve structure on reload
- Each line contains a list name and its corresponding element name

---

## Memory Management

Two functions handle cleanup:

- `freeElements` — frees all element nodes in a list, traversing from the head
- `freeBoard` (or equivalent) — frees all list nodes, traversing from the head

Memory is released before program exit to prevent leaks.

---

## File Format

The board is persisted as a `.csv` file where each row represents one element:

```
ListName,ElementName
```

Lists with no elements are also supported.
