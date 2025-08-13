## # 8-Puzzle Solver - Hill Climbing (Misplaced Tiles Heuristic)
### Overview
This C++ program solves the 8-puzzle problem using the **Hill Climbing** search algorithm, guided by the **Misplaced Tiles heuristic**. The goal is to rearrange a 3x3 grid of numbered tiles into a specific target configuration by sliding the blank tile (represented by `0`).

The goal configuration is:
1 2 3
4 5 6
7 8 0

Here, `0` represents the blank tile.

### Features
* **User Input**: Accepts a user-defined starting puzzle configuration.
* **Hill Climbing Algorithm**: Implements the Hill Climbing search strategy.
* **Misplaced Tiles Heuristic**: Uses `h(n)` to count the number of tiles out of their correct position (excluding the blank tile) to evaluate states.
* **Step-by-Step Output**: Displays the current puzzle state and its heuristic value at each step of the search.
* **Local Optimum Detection**: Recognizes when it can no longer improve the current state and stops.
* **Goal Detection**: Identifies when the goal state is reached.

### How the Algorithm Works

1.  **Heuristic Function (`misplaced_tiles`)**:
    * Calculates the number of tiles that are not in their correct position when compared to the `goal` state. The blank tile (`0`) is ignored in this count.
    * The lower the `misplaced_tiles` value, the "closer" the state is to the goal.

2.  **Hill Climbing Search (`hill_climbing`)**:
    * Starts with an initial puzzle state.
    * At each step, it generates all possible valid "neighbor" states by sliding the blank tile.
    * It evaluates the heuristic value (`misplaced_tiles`) for each neighbor.
    * It moves to the neighbor that has the **lowest (best)** heuristic value, provided it's strictly better than the current state.
    * If no neighbor has a strictly better heuristic value than the current state, the algorithm stops, indicating it has either reached the goal or a **local optimum**. Hill Climbing does not backtrack or explore other paths, making it susceptible to getting stuck in local optima.

3.  **Move Generation (`generate_moves`)**:
    * Identifies the position of the blank tile.
    * Generates up to four possible next states by swapping the blank tile with an adjacent tile (up, down, left, right), if the move is within the grid boundaries.

4.  **Termination**:
    * **Success**: The search stops when the `current` state matches the `goal` state.
    * **Local Optimum**: The search stops if no neighboring state has a *strictly better* (lower) heuristic value than the current state. This means the algorithm is stuck and cannot find a path to the global optimum (the goal) from its current position.

### Usage

1.  **Compile the program**:
    ```bash
    g++ your_program_name.cpp -o puzzle_hill_climbing
    ```
    (Replace `your_program_name.cpp` with the actual filename of your C++ code.)

2.  **Run the program**:
    ```bash
    ./puzzle_hill_climbing
    ```
3.  **Enter the puzzle configuration**: You will be prompted to enter the 9 numbers of your starting puzzle state, row by row. Use `0` for the blank space.

### Use Case
This program is useful for:
* Demonstrating the **Hill Climbing** search algorithm in Artificial Intelligence.
* Understanding the concept of **heuristics** and their role in guiding search.
* Illustrating the potential limitations of greedy search algorithms, such as getting stuck in **local optima**.
* Teaching and learning about state-space search problems.
