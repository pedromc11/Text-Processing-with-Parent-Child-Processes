# Text Processing with Parent-Child Processes 📚

This project is a C-based application designed to efficiently process text files using a **manager-worker** paradigm implemented with **parent-child processes**. It leverages inter-process communication to analyze text by counting words per line and finding specific patterns within a given file.

## 🎯 Project Goal

The primary objective of this project is to demonstrate the use of **process management** in C, specifically `fork()` and `exec()`, along with signal handling, to perform concurrent text analysis. The `manager` process orchestrates various `contador` (counter) and `procesador` (processor) child processes, distributing tasks and collecting results.

---

## 🚀 How It Works

The system comprises three main C programs:

### 1. `manager` (The Orchestrator) 🧑‍💼

The `manager.c` file contains the core logic for controlling the entire text processing workflow.

* **Argument Parsing**: It parses command-line arguments to get the main text file and a file containing patterns to search for.
* **Signal Handling**: It sets up a signal handler for `SIGINT` (Ctrl+C) to gracefully terminate all child processes and free resources upon interruption.
* **Process Creation**:
    * For each line in the input text file, it **forks** and **executes** a `contador` process.
    * For each pattern specified in the patterns file, it **forks** and **executes** a `procesador` process.
* **Process Management**: It maintains a table of all active child processes, tracking their PIDs and types.
* **Waiting for Children**: The manager waits for all child processes to complete their tasks before exiting.
* **Resource Cleanup**: It ensures that all dynamically allocated memory is freed upon successful completion or termination.

### 2. `contador` (The Word Counter) 🔢

The `contador.c` file is a child process responsible for counting words in a single line of text.

* It receives a **line of text** and its **line number** as command-line arguments.
* It then calculates and prints the total number of words in that line.

### 3. `procesador` (The Pattern Finder) 🔍

The `procesador.c` file is another type of child process, tasked with searching for a specific pattern within an entire text file.

* It receives the **filename** and the **pattern** to search for as command-line arguments.
* It reads the specified file line by line.
* For each line, it tokenizes the line and checks if the given pattern exists.
* If a match is found, it prints a message indicating the pattern, the process ID, and the line number where it was found.

### `lista.c` (Helper Linked List) 🔗

The `lista.c` file provides a simple **singly linked list** implementation. This is used by the `manager` to store and manage the list of patterns read from the `patrones.txt` file before launching the `procesador` child processes. It includes functions for creation, destruction, insertion (at beginning, end, and specific index), deletion (at beginning and specific index), retrieval of an element, printing, and getting the length of the list.

---

## 🛠️ Building the Project

This project uses a `Makefile` for easy compilation.

To build all executables, navigate to the root directory of the project in your terminal and run:

```bash
make all
