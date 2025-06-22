#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;

// Maze dimensions (odd numbers work best for proper wall structure)
const int ROWS = 21;  // Should be odd
const int COLS = 21;  // Should be odd

// Direction arrays for movement (up, right, down, left)
// For solving the maze, we only move to adjacent cells
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Function to initialize maze with all walls (1)
void initializeMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;  // Set all cells to walls
        }
    }
}

// Function to print the maze
void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if cell is within bounds and is a wall
bool isValid(int maze[ROWS][COLS], int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 1);
}

// Generate maze using Prim's algorithm
void generateMaze(int maze[ROWS][COLS]) {
    // Initialize maze with walls
    initializeMaze(maze);
    
    // Starting point (must be odd to maintain wall structure)
    int startRow = 1;
    int startCol = 1;
    maze[startRow][startCol] = 0;
    
    // Arrays to store frontier cells
    int frontierRows[ROWS * COLS];
    int frontierCols[ROWS * COLS];
    int frontierCount = 0;
    
    // Directions for adjacent cells (up, right, down, left)
    int primDx[] = {-2, 0, 2, 0};
    int primDy[] = {0, 2, 0, -2};
    
    // Add initial frontier cells (2 steps away from start)
    for (int i = 0; i < 4; i++) {
        int newRow = startRow + primDx[i];
        int newCol = startCol + primDy[i];
        if (isValid(maze, newRow, newCol)) {
            frontierRows[frontierCount] = newRow;
            frontierCols[frontierCount] = newCol;
            frontierCount++;
        }
    }
    
    // Main Prim's algorithm loop
    while (frontierCount > 0) {
        // Pick a random frontier cell
        int randIdx = rand() % frontierCount;
        int row = frontierRows[randIdx];
        int col = frontierCols[randIdx];
        
        // Remove the selected cell from frontier
        frontierRows[randIdx] = frontierRows[frontierCount - 1];
        frontierCols[randIdx] = frontierCols[frontierCount - 1];
        frontierCount--;
        
        // Check adjacent cells (2 steps away) that are already in maze
        for (int i = 0; i < 4; i++) {
            int adjRow = row + primDx[i];
            int adjCol = col + primDy[i];
            
            if (adjRow >= 0 && adjRow < ROWS && adjCol >= 0 && adjCol < COLS && 
                maze[adjRow][adjCol] == 0) {
                // Connect the frontier cell to the maze
                maze[row][col] = 0;
                maze[(row + adjRow) / 2][(col + adjCol) / 2] = 0;  // Open the wall between
                
                // Add new frontier cells
                for (int j = 0; j < 4; j++) {
                    int newRow = row + primDx[j];
                    int newCol = col + primDy[j];
                    if (isValid(maze, newRow, newCol)) {
                        frontierRows[frontierCount] = newRow;
                        frontierCols[frontierCount] = newCol;
                        frontierCount++;
                    }
                }
                break;  // Only connect to one existing cell
            }
        }
    }
    
    // Ensure entrance and exit
    maze[0][1] = 0;              // Entrance at top
    maze[ROWS-1][COLS-2] = 0;    // Exit at bottom
}

// Function to print the solved maze with path
void printSolveMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1)
                cout << "| ";
            else if (maze[i][j] == 2)
                cout << "* ";
            else
                cout << "! ";  // Changed to "0 " (no space before 0)
        }
        cout << endl;
    }
}

// Function to solve maze using DFS algorithm
bool solveMazeDFS(int maze[ROWS][COLS], int startRow, int startCol, int endRow, int endCol) {
    stack<pair<int, int>> s;
    bool visited[ROWS][COLS] = {false};  // Initialize all to false
    int parentRow[ROWS][COLS] = {0};    // Initialize all to 0
    int parentCol[ROWS][COLS] = {0};    // Initialize all to 0

    s.push({startRow, startCol});
    visited[startRow][startCol] = true;

    bool found = false;

    while (!s.empty() && !found) {
        // Get the current cell but don't pop yet
        pair<int, int> current = s.top();
        s.pop();  // Now pop the stack
        
        int row = current.first;
        int col = current.second;

        // Check if reached the exit
        if (row == endRow && col == endCol) {
            found = true;
            break;
        }

        // Try all four directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            // Check if valid and not visited and is a path (0)
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS &&
                maze[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                // Mark as visited and record the parent
                s.push({newRow, newCol});
                visited[newRow][newCol] = true;
                parentRow[newRow][newCol] = row;
                parentCol[newRow][newCol] = col;
            }
        }
    }

    if (found) {
        // Trace back path and count steps
        int r = endRow, c = endCol;
        int steps = 0;

        while (!(r == startRow && c == startCol)) {
            maze[r][c] = 2;  // Mark path
            int tempR = parentRow[r][c];
            int tempC = parentCol[r][c];
            r = tempR;
            c = tempC;
            steps++;
        }
        maze[startRow][startCol] = 2;  // Mark start
        steps++; // include start point

        cout << "\nPath found using DFS!" << endl;
        cout << "Steps taken: " << steps << endl;
        return true;
    } else {
        cout << "No path found using DFS.\n";
        return false;
    }
}

// Function to solve maze using BFS algorithm
bool solveMazeBFS(int maze[ROWS][COLS], int startRow, int startCol, int endRow, int endCol) {
    queue<pair<int, int>> q;
    bool visited[ROWS][COLS] = {false};  // Initialize all to false
    int parentRow[ROWS][COLS] = {0};    // Initialize all to 0
    int parentCol[ROWS][COLS] = {0};    // Initialize all to 0

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    bool found = false;

    while (!q.empty() && !found) {
        pair<int, int> current = q.front();
        q.pop();
        
        int row = current.first;
        int col = current.second;

        // Check if reached the exit
        if (row == endRow && col == endCol) {
            found = true;
            break;
        }

        // Try all four directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            // Check if valid and not visited and is a path (0)
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS &&
                maze[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                // Mark as visited and record the parent
                q.push({newRow, newCol});
                visited[newRow][newCol] = true;
                parentRow[newRow][newCol] = row;
                parentCol[newRow][newCol] = col;
            }
        }
    }

    if (found) {
        // Trace back path and count steps
        int r = endRow, c = endCol;
        int steps = 0;

        while (!(r == startRow && c == startCol)) {
            maze[r][c] = 2;  // Mark path
            int tempR = parentRow[r][c];
            int tempC = parentCol[r][c];
            r = tempR;
            c = tempC;
            steps++;
        }
        maze[startRow][startCol] = 2;  // Mark start
        steps++; // include start point

        cout << "\nPath found using BFS!" << endl;
        cout << "Steps taken: " << steps << endl;
        return true;
    } else {
        cout << "No path found using BFS.\n";
        return false;
    }
}

// Function to create a copy of the maze
void copyMaze(int source[ROWS][COLS], int destination[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

int main() {
    int maze[ROWS][COLS];
    int tempMaze[ROWS][COLS]; // For storing a working copy
    bool mazeGenerated = false;
    
    // Seed random number generator with current time - do this only once
    srand(time(0));
    int choice;
    char ch;
    
    // Main program loop
    do {
        cout << "\n=== Maze Generator and Solver ===\n";
        cout << "1. Generate maze\n";
        cout << "2. Solve maze using DFS\n";
        cout << "3. Solve maze using BFS\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Generating new maze...\n";
                generateMaze(maze);
                cout << "The generated maze is:\n";
                printMaze(maze);
                mazeGenerated = true;
                break;
                
            case 2:
                if (!mazeGenerated) {
                    cout << "No maze has been generated yet. Generate a maze first.\n";
                    break;
                }
                
                int dfsChoice;
                cout << "1. Solve the previously generated maze\n";
                cout << "2. Generate a new maze and solve it\n";
                cout << "Enter your choice: ";
                cin >> dfsChoice;
                
                switch(dfsChoice) {
                    case 1:
                        // Create a working copy
                        copyMaze(maze, tempMaze);
                        if (solveMazeDFS(tempMaze, 0, 1, ROWS-1, COLS-2)) {
                            printSolveMaze(tempMaze);
                        }
                        break;
                        
                    case 2:
                        cout << "Generating new maze...\n";
                        generateMaze(maze);
                        cout << "The generated maze is:\n";
                        printMaze(maze);
                        
                        // Create a working copy
                        copyMaze(maze, tempMaze);
                        if (solveMazeDFS(tempMaze, 0, 1, ROWS-1, COLS-2)) {
                            printSolveMaze(tempMaze);
                        }
                        break;
                        
                    default:
                        cout << "Invalid choice\n";
                }
                break;
                
            case 3:
                if (!mazeGenerated) {
                    cout << "No maze has been generated yet. Generate a maze first.\n";
                    break;
                }
                
                int bfsChoice;
                cout << "1. Solve the previously generated maze\n";
                cout << "2. Generate a new maze and solve it\n";
                cout << "Enter your choice: ";
                cin >> bfsChoice;
                
                switch(bfsChoice) {
                    case 1:
                        // Create a working copy
                        copyMaze(maze, tempMaze);
                        if (solveMazeBFS(tempMaze, 0, 1, ROWS-1, COLS-2)) {
                            printSolveMaze(tempMaze);
                        }
                        break;
                        
                    case 2:
                        cout << "Generating new maze...\n";
                        generateMaze(maze);
                        cout << "The generated maze is:\n";
                        printMaze(maze);
                        
                        // Create a working copy
                        copyMaze(maze, tempMaze);
                        if (solveMazeBFS(tempMaze, 0, 1, ROWS-1, COLS-2)) {
                            printSolveMaze(tempMaze);
                        }
                        break;
                        
                    default:
                        cout << "Invalid choice\n";
                }
                break;
                
            case 4:
                cout << "Exiting program...\n";
                exit(0);
                
            default:
                cout << "Invalid choice\n";
        }
        
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    
    return 0;
}