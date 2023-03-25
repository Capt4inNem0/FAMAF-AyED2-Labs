#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */
#define SIDE_SIZE 3
#define CELL_MAX (SIDE_SIZE * SIDE_SIZE - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[SIDE_SIZE][SIDE_SIZE])
{
    int cell = 0;

    print_sep(SIDE_SIZE);
    for (int row = 0; row < SIDE_SIZE; ++row) {
        for (int column = 0; column < SIDE_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(SIDE_SIZE);
    }
}

// BIG O = O(SIDE_SIZE)
char get_winner(char board[SIDE_SIZE][SIDE_SIZE], unsigned int last_row, unsigned int last_col)
{
    char winner = '-';
    bool horizontal_winner = true;
    bool vertical_winner = true;
    bool diagonal_winner = true;
    bool diagonal_b_winner = true;
    for (unsigned int i = 1; i < SIDE_SIZE; i++) {
        horizontal_winner = horizontal_winner && board[last_row][last_col] == board[last_row][(last_col+i)%SIDE_SIZE];
        vertical_winner = vertical_winner && board[last_row][last_col] == board[(last_row+i)%SIDE_SIZE][last_col];
        diagonal_winner = diagonal_winner && board[i][i] == board[0][0];
        diagonal_b_winner = diagonal_b_winner && board[i][SIDE_SIZE - 1 - i] == board[0][SIDE_SIZE - 1];
    }
    if (horizontal_winner || vertical_winner) {
        winner = board[last_row][last_col];
    } else if (diagonal_winner) {
        winner = board[0][0];
    } else if (diagonal_b_winner) {
        winner = board[0][SIDE_SIZE - 1];
    }

    return winner;
}

int main(void)
{
    printf("TicTacToe\n");

    char board[SIDE_SIZE][SIDE_SIZE];

    for (int i = 0; i <= CELL_MAX; ++i) {
        board[i/SIDE_SIZE][i%SIDE_SIZE] = '-';
    }

    unsigned int has_free_cell = 0;
    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell != CELL_MAX+1) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / SIDE_SIZE;
            int colum = cell % SIDE_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                has_free_cell++;
                winner = get_winner(board, row, colum);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
