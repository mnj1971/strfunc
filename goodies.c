#include <windows.h>
#include <stdio.h>

const Black = 0;
const Blue = 1;
const Green = 2;
const Cyan = 3;
const Red = 4;
const Magenta = 5;
const Brown = 6;
const Lightgray = 7;
const Darkgray = 8;
const Lightblue = 9;
const Lightgreen = 10;
const Lightcyan = 11;
const Lightred = 12;
const Lightmagenta = 13;
const Yellow = 14;
const White = 15;

// ��������� ����� ������� � ����� ����
void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
// ������� � �������� ������� ������
void gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
// ������� �������� ������� ������
void clrscr(int x1, int y1, int x2, int y2) { // ������� ������� �������� ������� ������
	int i = 0;
	int j = 0;
	for (i = x1; i <= x2; i++) {
		for (j = y1; j <= y2; j++) {
			gotoxy(i, j);
			printf(" ");
		}
	}
}
// ������ ������ - ����� �� �����������
void Hide_Cursor() {
	int handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
// �������� ������ - ����� �� �����������
void Show_Cursor() {
	int handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
// ���������� ��������������� ����� �� ��������� (min, max) - ����� �� �����������
int Random(int min, int max) {
	return min + rand() % (max - min);
}
// ��������� ����� �������� ����
void DrawFrame(int w, int h, int color) {
	SetColor(color, 0);
	gotoxy(0, 0);
	printf("%c", 218);			// ascii 218 �.�. ������
	int i = 0;
	for (i = 1; i < w - 1; ++i) {
		gotoxy(i, 0);
		printf("%c", 196);		// ascii 196 ������� �������
	}
	printf("%c", 191);			// ascii 191 �.�. ������ 
	for (i = 1; i < h - 1; i++) {
		gotoxy(w - 1, i);
		printf("%c", 179);		// ascii 179 ������ ������� 
	}
	gotoxy(w - 1, h - 1);
	printf("%c", 217);			// ascii 217 �.�. ������ 
	for (i = w - 2; i > 0; i--) {
		gotoxy(i, h - 1);
		printf("%c", 196);		// ������ �������
	}
	gotoxy(0, h - 1);
	printf("%c", 192);			// ascii 192 �.�. ������ 
	for (i = h - 2; i > 0; i--) {
		gotoxy(0, i);
		printf("%c", 179);		// ����� �������
	}
	SetColor(White, 0);
}