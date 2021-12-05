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

// установка цвета символа и цвета фона
void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
// переход в заданную позицию экрана
void gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
// очистка заданной области экрана
void clrscr(int x1, int y1, int x2, int y2) { // функция очистки заданной области экрана
	int i = 0;
	int j = 0;
	for (i = x1; i <= x2; i++) {
		for (j = y1; j <= y2; j++) {
			gotoxy(i, j);
			printf(" ");
		}
	}
}
// Скрыть курсор - взято на киберфоруме
void Hide_Cursor() {
	int handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
// Показать курсор - взято на киберфоруме
void Show_Cursor() {
	int handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
// Возвращает псевдослучайное число из диапазона (min, max) - взято на киберфоруме
int Random(int min, int max) {
	return min + rand() % (max - min);
}
// отрисовка рамки игрового поля
void DrawFrame(int w, int h, int color) {
	SetColor(color, 0);
	gotoxy(0, 0);
	printf("%c", 218);			// ascii 218 л.в. уголок
	int i = 0;
	for (i = 1; i < w - 1; ++i) {
		gotoxy(i, 0);
		printf("%c", 196);		// ascii 196 верхняя граница
	}
	printf("%c", 191);			// ascii 191 п.в. уголок 
	for (i = 1; i < h - 1; i++) {
		gotoxy(w - 1, i);
		printf("%c", 179);		// ascii 179 правая граница 
	}
	gotoxy(w - 1, h - 1);
	printf("%c", 217);			// ascii 217 п.н. уголок 
	for (i = w - 2; i > 0; i--) {
		gotoxy(i, h - 1);
		printf("%c", 196);		// нижняя граница
	}
	gotoxy(0, h - 1);
	printf("%c", 192);			// ascii 192 л.н. уголок 
	for (i = h - 2; i > 0; i--) {
		gotoxy(0, i);
		printf("%c", 179);		// левая граница
	}
	SetColor(White, 0);
}