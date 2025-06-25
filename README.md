# Game-Of-Life
A C++ implementation of Conway’s Game of Life, developed as part of my Programming Fundamentals semester project. This simulation explores the evolution of cellular automata while demonstrating concepts in algorithm design, grid-based logic, and terminal-based visualization.
📌 Features
Terminal-based grid visualization

User-defined initial live cells

Custom number of generations

Automatic update of grid across generations

Live and dead neighbor counting

Dynamic cell evolution based on classic rules

▶️ How It Works
You input:

The number of generations to simulate

The number of live cells to start with

The coordinates of each live cell

The program then:

Simulates the game over your specified generations

Applies rules to determine cell survival, death, or birth

Prints the updated grid for each generation

⚙️ Rules Implemented
The game follows Conway's rules:

A live cell:

Dies if it has fewer than 2 or more than 3 live neighbors.

Survives if it has 2 or 3 live neighbors.

A dead cell:

Becomes alive if it has exactly 3 live neighbors.

💻 Technologies Used
C++

File I/O (fstream)

2D arrays

Basic terminal output

(Optional) system("clear") for refreshing the screen between generations

🛠️ How to Run
Compile the code:

bash
Copy
Edit
g++ -o gameoflife main.cpp
Run the executable:

bash
Copy
Edit
./gameoflife
Follow the prompts to enter:

Number of generations

Number of starting cells

Coordinates for each cell
