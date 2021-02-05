#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


char g_chess_board[3][3] = { 0 };

void Init() {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			g_chess_board[row][col] = ' ';
		}
	}
}

void PrintBoard() {
	printf("���������������Щ������������Щ�������������\n");
	for (int count = 0; count < 3; count++) {
		printf("��      ��      ��      ��\n");
		printf("��  %c   ��   %c  ��   %c  ��\n", g_chess_board[count][0],
			g_chess_board[count][1], g_chess_board[count][2]);
		printf("��      ��      ��      ��\n");
		if (count != 2)
			printf("���������������੤�����������੤������������\n");
	}
	printf("���������������ة������������ة�������������\n");
}

void UserPlay() {
	while (1) {
		int row = -1;
		int col = -1;
		printf("����������λ��!\n");
		fflush(stdin);
		scanf_s("%d %d", &row, &col);
		if (row < 0 || row > 2 || col < 0 || col > 2) {
			printf("���������������������\n");
			continue;
		}
		else if (g_chess_board[row][col] != ' ') {
			printf("��λ���Ѿ������ӣ�����������!\n");
			continue;
		}
		else {
			g_chess_board[row][col] = 'X';
			break;
		}
	}
}

void ComputerPlay() {
	int row, col;
	printf("����������...\n");
	sleep(2);
	while (1) {
		srand((unsigned int)time(NULL));
		row = rand() % 3;
		col = rand() % 3;
		if (g_chess_board[row][col] == ' ') {
			g_chess_board[row][col] = 'O';
			break;
		}
	}
}

int IsFull() {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++)
			if (g_chess_board[row][col] == ' ') {
				//printf("δ��������0\n");
				//sleep(1);
				return 0;
			}
	}
	//printf("���ˣ�����1\n");
	return 1;
}

char CheckWinner() {
	char return_char;

	//1.������Ƿ�һ��
	for (int row = 0; row <= 2; row++) {
		if (g_chess_board[row][0] == g_chess_board[row][1]
			&& g_chess_board[row][0] == g_chess_board[row][2]
			&& g_chess_board[row][0] != ' ') {
			return g_chess_board[row][0];
		}
	}
	//2.������Ƿ�һ��
	for (int col = 0; col <= 2; col++) {
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]
			&& g_chess_board[0][col] != ' ') {
			return g_chess_board[0][col];
		}
	}
	//3.��������Խ����Ƿ�һ��
	//3.1���Խ���
	if (g_chess_board[1][1] == g_chess_board[0][0]
		&& g_chess_board[1][1] == g_chess_board[2][2]
		&& g_chess_board[1][1] != ' ') {
		return g_chess_board[1][1];
	}
	//3.2���Խ���
	if (g_chess_board[1][1] == g_chess_board[0][2]
		&& g_chess_board[1][1] == g_chess_board[2][0]
		&& g_chess_board[1][1] != ' ') {
		return g_chess_board[1][1];
	}

	//4.����Ƿ����
	if (IsFull()) {
		return 'H';
	}
	//5��û�������������N
	return 'N';
}

void RefreshSrceen() {
	system("clear");
	PrintBoard();
	sleep(2);
}

int main() {
	system("clear");
	//1.��ʼ��
	Init();
	while (1) {
		char winner_tags;
		// 2 .��ӡ����
		PrintBoard();
		// 3. �û�����
		UserPlay();
		RefreshSrceen();
		// ����Ƿ���Ӯ�һ��ߺ���
		winner_tags = CheckWinner();
		//printf("winner_tags = %c\n", winner_tags);
		//sleep(2);
		if (winner_tags == 'X') {
			printf("Congratulation!\n���Ӯ��\n");
			break;
		}
		else if (winner_tags == 'O') {
			printf("Congratulation!\n����Ӯ��\n");
			break;
		}
		else if (winner_tags == 'H') {
			printf("Equal in influence and power!\n���壡\n");
			break;
		}
		// 4. ��������
		ComputerPlay();
		RefreshSrceen();
		winner_tags = CheckWinner();
		//printf("winner_tags = %c\n", winner_tags);
		//sleep(2);
		if (winner_tags == 'X') {
			printf("Congratulation!\n���Ӯ��\n");
			break;
		}
		else if (winner_tags == 'O') {
			printf("Congratulation!\n����Ӯ��\n");
			break;
		}
		else if (winner_tags == 'H') {
			printf("Equal in influence and power!\n���壡\n");
			break;
		}
		system("clear");
	}
	exit(0);
}