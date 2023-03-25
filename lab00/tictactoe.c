#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */
#define SIDE_SIZE 1
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

char get_winner(char board[SIDE_SIZE][SIDE_SIZE])
{
    char winner = '-';
    for (unsigned int row = 0; row < SIDE_SIZE; row++) {
        bool horizontal_winner = true;
        bool vertical_winner = true;
        for (int col = 0; col < SIDE_SIZE; col++) {
            horizontal_winner = horizontal_winner && board[row][col] == board[row][0];
            vertical_winner = vertical_winner && board[col][row] == board[0][row];
        }
        if (horizontal_winner) {
            winner = board[row][0];
            break;
        }
        if (vertical_winner) {
            winner = board[0][row];
            break;
        }
    }
    if (winner == '-') {
        bool diagonal_winner = true;
        bool diagonal_b_winner = true;
        for (int i = 0; i < SIDE_SIZE; i++) {
            diagonal_winner = diagonal_winner && board[i][i] == board[0][0];
            diagonal_b_winner = diagonal_winner && board[i][SIDE_SIZE - i - 1] == board[0][SIDE_SIZE - 1];
        }
        if (diagonal_winner) {
            winner = board[0][0];
        }
        if (diagonal_b_winner) {
            winner = board[0][SIDE_SIZE - 1];
        }
    }

    return winner;
}

bool has_free_cell(char board[SIDE_SIZE][SIDE_SIZE])
{
    bool free_cell=false;
    for (unsigned int i = 0; i <= CELL_MAX; ++i) {
        free_cell = free_cell || board[i/SIDE_SIZE][i%SIDE_SIZE] == '-';
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe\n");

    char board[SIDE_SIZE][SIDE_SIZE];

    for (int i = 0; i <= CELL_MAX; ++i) {
        board[i/SIDE_SIZE][i%SIDE_SIZE] = '-';
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
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
                winner = get_winner(board);
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
