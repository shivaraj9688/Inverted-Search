# Inverted-Search
A robust, high-performance console application built in Advanced C designed to index and search words across multiple text files efficiently. It implements an optimized Hash Table mapped with nested Linked Lists to track unique words, their frequencies, and file distributions.

The Inverted Search System provides a comprehensive command-line menu interface to manage and query text databases. Key functionalities include:

* **File Validation & Management**: Automatically screens command-line arguments to verify file availability, detect empty files (`FILE_EMPTY`), and filter out duplicate entries (`REPEATATION`).

* **Hash-Based Indexing**: Uses a 27-bucket hash table mapped alphabetically (`a-z` and special characters) via a custom hash function for fast lookups.

* **Database Creation**: Parses data text files and builds the primary word nodes (`Wlist`) and nested link tables (`Ltable`)[cite: 26, 32, 33].
* **Search Functionality**: Quickly queries the database to locate specific words and displays the exact file count and individual word frequencies per file.
* **Database Updates**: Dynamically adds new text files to an existing active database during runtime[cite: 23].
* **Database Backup & Persistence**: Serializes the in-memory database hierarchy into a structured backup text file using custom write routines (`write_databasefile`).
  
## 🛠️ Technologies Used

* **Advanced C Programming**: Complex pointer manipulations, dynamic memory allocation (`malloc`, `free`), string handling (`string.h`), and modular multi-file compilation.
  
* **Data Structures & Algorithms**: 
  * 27-bucket Hash Table.
  * Primary Singly Linked Lists for unique words (`Wlist`).
  * Secondary Nested Linked Lists for document tracking and local word counts (`Ltable`).
* **Linux System Programming & File I/O**: Stream-based file operations (`fopen`, `fscanf`, `fprintf`, `fseek`, `ftell`, `fclose`).
  
## 📂 Project File Structure

├── main_2.c                # Program entry point, argument parsing, and interactive menu loop[cite: 35]
├── inverted_Search.h       # Central header file containing structure definitions and error codes[cite: 33]
├── file_validation.c       # Handles file availability checks, emptiness, and file linked list population[cite: 30]
├── hash.c                  # Computes hash index mapping based on the first letter of each word[cite: 31]
├── create_database.c       # Reads text files and builds the inverted search database[cite: 26]
├── word_list.c             # Handles insertion of new word nodes into hash buckets[cite: 25]
├── insert_last.c           # Inserts new entries into the word list[cite: 32]
├── link_table.c            # Manages nested link table nodes for tracking file names and word frequencies[cite: 34]
├── update_word_count.c     # Increments local word counts for repeating words within the same file[cite: 24]
├── display_database.c      # Formats and prints the complete inverted search hash table[cite: 27]
├── search.c                # Searches for specific keywords within the database[cite: 22]
├── update_database.c       # Adds new source files dynamically and updates the database[cite: 23]
├── save_database.c         # Serializes and saves the database into a backup file[cite: 21]
└── makefile                # Automated build script for compiling all modules

# Key Challenges & Learnings
Managing Multi-Tiered Pointers: Designing and maintaining multi-level linked lists—where hash indices point to word nodes (Wlist), which subsequently point to file link tables (Ltable)—deepened proficiency in pointer management and memory leak prevention.

Robust File Validation: Implementing rigorous pre-checks to handle missing files, empty inputs, and duplicate command-line parameters effectively increased program resilience[cite: 30].

Database Serialization: Writing custom serialization algorithms (write_databasefile) to map complex pointer structures cleanly into formatted plain-text files for backup and restoration[cite: 21].

Modular Software Design: Separating core features across distinct C source files managed via a customized makefile greatly improved code readability, testability, and scalability.

# Getting Started & Compilation
Prerequisites
A C compiler compatible with POSIX standards (e.g., gcc on Linux/macOS or MinGW on Windows).

# Compilation & Execution
Compile the project using the provided makefile[cite: 20]:

# Bash
make
Run the application by passing one or more valid text files as command-line arguments[cite: 35]:

# Bash
./invsearch file1.txt file2.txt
