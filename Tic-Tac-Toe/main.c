#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
//#include <MMsystem.h>

char square[10] = { '0','1','2','3','4','5','6','7','8','9' };
int get_user_selection_1_9(int,char);
int checkWin();
void drawBoard();
void is_square_empty_set_square(int,char);

int main() {
	system("color 4b");
	int player = 1, i, choice;
	char mark = 'X'; // X,O
	do {
		drawBoard();
		player = (player % 2) ? 1 : 2;
		mark = (player == 1) ? 'X' : 'O';
		choice = get_user_selection_1_9(player, mark,1);
		i = checkWin();
		player++;
	} while (i == -1);

	drawBoard();
	if (i == 1) {
		printf("\n==> Player %d won!!\n\n", --player);
		printf("\a");
	}
	else {
		printf("\n==> Game draw!!\n\n");
		printf("\a");
	}
	return 0;
}
int get_user_selection_1_9(int player, char mark){ 
	int is_first = 1;
	int input, ch, jump;
	do {
		jump = 1;
		if(!player)
		{
			is_first = 0;
			printf("\a");
			printf("Oops...this square has been selected before!!\n"
			"\tPlease select an empty square = > : ");
		}
		else if (is_first)
		{
			is_first = 0;
			printf("Player %d turn =>, Select a square in the table(1 - 9) to enter (%c): ", player, mark);
		}
		//Only after the first try 
		else
		{
			printf("\a");
			drawBoard();
			printf("\nInvalid option!!\n\t(player %d,(%c))Please select again => : ", player, mark);
		}
		input = getchar();
		if (input == '\n')
			jump = 0;
		if (jump)
		{
			ch = getchar();
			if (ch != '\n')
			{
				while (ch = getchar() != '\n');
				jump = 0;
			}
		}
	} while (input < '1' || input > '9' || !jump);
	is_square_empty_set_square(input - '0',mark) ;
}
void is_square_empty_set_square(int choice, char mark)
{
	if (square[choice] == choice + 48)
		square[choice] = mark;
	else
		get_user_selection_1_9(0,mark);
}
int checkWin() {
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	/*If we are in a state that all the squares are filled*/
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}

void drawBoard() {
	system("cls");
	printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player1 (X) - Player2 (%c) \n\n\n",79);
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", square[1], square[2], square[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", square[4], square[5], square[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", square[7], square[8], square[9]);
	printf("     |     |     \n");
}


	