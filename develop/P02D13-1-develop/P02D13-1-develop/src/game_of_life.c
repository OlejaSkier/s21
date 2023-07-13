#include <fcntl.h>
#include <stdio.h>
#include <string.h>  // for memcpy
#include <termios.h>
#include <unistd.h>  // for usleep function

#define WIDTH 80
#define HEIGHT 25

const char live_cell = '#';
const char dead_cell = ' ';

const int sleep_time_step = 25000;  // each arrow key press will change sleep time by 0.1 sec

void fill_matrix_from_file(int game[HEIGHT][WIDTH]);
int is_alive(int game[HEIGHT][WIDTH], int x, int y);
void print_game(int game[HEIGHT][WIDTH]);
void calculate_cell_state(int game[HEIGHT][WIDTH]);
void change_speed(int *sleep_time);
void play(int game[HEIGHT][WIDTH]);

int main() {
    int game[HEIGHT][WIDTH];

    fill_matrix_from_file(game);

    // modify terminal settings for input to enable non-blocking input
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);  // get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);         // disable canonical mode and echo input
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // set new terminal settings for stdin

    //  modify file status flags for stdin
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);       // get current flags
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);  // enable non-blocking input

    play(game);

    // print_game(game);

    // restore to the original terminal settings for stdin
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}

void play(int game[HEIGHT][WIDTH]) {
    int sleep_time = 250000;  // initial sleep time is 0.25 sec

    while (1) {
        printf("\033[2J");  // Clear screen
        printf("\033[H");   // Move cursor to the top left corner

        // print current cell's state
        print_game(game);

        // calculate and update cell's state for the next step
        calculate_cell_state(game);

        // read in user input every 0.01 second
        for (int i = 0; i < sleep_time / sleep_time_step; ++i) {
            change_speed(&sleep_time);  // check if user wants to adjust speed

            usleep(sleep_time_step);  // and put program to sleep
        }
        // printf("sleep_time = %d\n", sleep_time);
    }
}

void calculate_cell_state(int game[HEIGHT][WIDTH]) {
    // temporary buffer matrix to keep cell's state at the next step
    int buff[HEIGHT][WIDTH];

    // calculate state of each cell at the next step
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            buff[y][x] = is_alive(game, x, y);
        }
    }

    // now copy new state, kept in buff matrix, to the original game matrix
    memcpy(game, buff, sizeof(buff));
}

void print_game(int game[HEIGHT][WIDTH]) {
    printf("+--------------------------------------------------------------------------------+\n");
    printf("|              For adjusting the speed of the game use W/S buttons               |\n");
    printf("+--------------------------------------------------------------------------------+\n");

    for (int row = 0; row < HEIGHT; ++row) {
        printf("|");
        for (int col = 0; col < WIDTH; ++col) {
            printf("%c", (game[row][col] ? live_cell : dead_cell));
            // if (col != HEIGHT - 1)
            //     printf(" ");
        }
        printf("|\n");
    }
    printf("+--------------------------------------------------------------------------------+\n");
}

// return 1 if cell at x, y) coordinates should be alive at the next step
// return 0 if it should be dead
int is_alive(int game[HEIGHT][WIDTH], int x, int y) {
    // check if there are alive neightbours and count them
    int alive = 0;
    for (int row = y - 1; row <= y + 1; ++row) {
        for (int col = x - 1; col <= x + 1; ++col) {
            if (row == y && col == x) continue;

            // handle wrapping for x and y axis
            int ncol = (col + WIDTH) % WIDTH;    // we have to add WIDTH to col because otherwise
            int nrow = (row + HEIGHT) % HEIGHT;  // result could be negative

            if (game[nrow][ncol]) ++alive;
        }
    }

    // check if cell at (x, y) coordinates should live or not

    // if cell is alive and there are two or three live neighbours
    if (game[y][x] && (alive == 2 || alive == 3)) return 1;
    // if cell is dead and there are three living neightbours
    if (!game[y][x] && alive == 3) return 1;
    // in any other case -- it should be dead

    return 0;  // if no cases were true, then this cell should be dead
}

void change_speed(int *sleep_time) {
    char ch;
    // read in user input and check that it is in range of 0.05 to 0.5 seconds
    if (read(STDIN_FILENO, &ch, 1) == 1) {
        if ((ch == 'W' || ch == 'w') && *sleep_time > 2 * sleep_time_step) *sleep_time -= sleep_time_step;
        if ((ch == 'S' || ch == 's') && *sleep_time < 500000) *sleep_time += sleep_time_step;
    }
}

void fill_matrix_from_file(int game[HEIGHT][WIDTH]) {
    FILE *file;
    char filepath[100];
    printf("Enter the filepath: ");
    scanf("%99s", filepath);
    file = fopen(filepath, "r");
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            fscanf(file, "%i", &game[row][col]);
        }
    }
    fclose(file);
}
