#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "goodies.h"

int Lenght_Word(char *Word);

void Input_Word(int N, char* Word) {		// функция ввода слова. аргумент - номер слова
	bool Process = true;
	int Ch = 0;
	int i = 0;
	if (Lenght_Word(Word) > 0)
		i = Lenght_Word(Word);
	else
		i = 0;
	gotoxy(2, N + 10);
	Show_Cursor();
	printf_s("Введите %d-ю строку: ", N);
	gotoxy(22 + i, N + 10);
	while (Process) {
		Ch = _getch();
		if ((Ch != 0) || (Ch != 224)) {		// если это НЕ ескейп-последовательность, работаем
			if (((Ch >= 32) && (Ch <= 126)) && (i < 10)) {	// 
				Word[i] = Ch;
				gotoxy(22 + i, N + 10);
				printf_s("%c", Ch);
				++i;
			}
		}
		if (Ch == 0 || Ch == 224) {		//  если это ескейп-последовательность, выбираем следующий символ из буфера
			Ch = _getch();
		}
		if (Ch == 27) {
			if (Lenght_Word(Word) > 0) {
				gotoxy(22, N + 10);
				printf_s("%s", Word);
			}
			Process = false;
		}
		if (Ch == 13) {					// нажали ентер
			Hide_Cursor();
			Word[i] = '\0';				// пишем знак окончания строки - 0
			return;	
		}
		if (Ch == 8) {
			if (i > 0) {
				//Word[i] = '\0';
				--i;
				gotoxy(22 + i, N + 10);
				printf_s(" ");
				gotoxy(22 + i, N + 10);
			}
		}
	}
	Hide_Cursor();
	return;
	
}
// длина строки
int Lenght_Word(const char *Word) {
	int i, count;
	bool Check = false;	// на случай отсутствия 0 в конце строки
	count = 0;
	for (i = 0; i <= 10; i++) {
		if (Word[i] == '\0') {
			Check = true;
			break;
		}
		++count;
	}
	if (!Check) count = 0;
	return count;
}
// сравнение строк
int CompareStrs(char* Str1, char* Str2) {
	int i = 0;
	int j = 0;
	int count = 0;
	if ((Lenght_Word(Str1) == 0 && (Lenght_Word(Str2) == 0))) // если строки не заданы
		return 2;
	if ((Lenght_Word(Str1)) != (Lenght_Word(Str2)))
		return 0;
	else {
		j = Lenght_Word(Str1);
		for (i = 0; i < j; i++) {
			if (Str1[i] != Str2[i])
				++count;
		}
		if (count == 0)	// если все совпадает, вы 
			return 1;
		else
			return 0;
	}
}
// склеивание строк
void ConcatStrs(char* Str1, char* Str2, char* S) {
	int i, j, k, l;
	i = Lenght_Word(Str1);
	j = Lenght_Word(Str2);
	for (k = 0; k < i; ++k) {
		S[k] = Str1[k];
	}
	for (l = i; l < i+j; ++l) {
		S[l] = Str2[l - i];
	}
	S[i + j] = '\0';
	return;
}
// копирование второй строки в первую
void CopyStr(char* Str1, char* Str2) {
	int i, j, k;
	i = Lenght_Word(Str1);		// длина 1 строки
	j = Lenght_Word(Str2);		// длина 2 строки
	if (i == 0 || j == 0)
		return;
	if (i == j) {		// если длина одинаковая, просто копируем один к одному
		for (i = 0; i < j; i++) {
			Str1[i] = Str2[i];
		}
	}
	else if (i > j) {		// если первыая больше второй, пишем ее с первого символа
		for (k = 0; k < j; ++k) {
			Str1[k] = Str2[k];
		}
	}
	else {				// если вторая больше первой, то она перекрывает ее и дописывает '\0'
		for (k = 0; k < j; ++k) {
			Str1[k] = Str2[k];
		}
		Str1[j] = '\0';
	}
	gotoxy(22, 11);		// заменяем первую строку новой первой строкой
	printf_s("%s", Str1);
}

// построение меню и операции с ним
void Menu() {			
	bool Process = true;
	int Key = 0;	// нажатая клавиша
	int i = 0;		// номер строки меню
	int j = 0;		
	char *A = malloc(sizeof(char)*11); // первая строка
	char *B = malloc(sizeof(char)*11); // вторая строка
	char *C = malloc(sizeof(char)*21); // суммарная строка
	Hide_Cursor();
	printf_s(" 1. Ввести первую строку\n");
	printf_s(" 2. Ввести вторую строку\n");
	printf_s(" 3. Длина строки\n");
	printf_s(" 4. Копировать вторую строку в первую\n");
	printf_s(" 5. Сравнить строки\n");
	printf_s(" 6. Соединить строки\n");
	printf_s(" 7. Выход\n");
	gotoxy(0, 0);
	printf_s(">");
	while (Process) {
		Key = _getch();
		switch (Key)
		{
		case 27:
			Process = false;
			break;
		case 80:
			if (i < 6) {
				gotoxy(0, i);
				printf_s(" ");
				++i;
				gotoxy(0, i);
				printf_s(">");
			}
			else {
				gotoxy(0, i);
				printf_s(" ");
				i = 0;
				gotoxy(0, i);
				printf_s(">");
			}
			break;
		case 72:
			if (i > 0) {
				gotoxy(0, i);
				printf_s(" ");
				--i;
				gotoxy(0, i);
				printf_s(">");
			}
			else {
				gotoxy(0, i);
				printf_s(" ");
				i = 6;
				gotoxy(0, i);
				printf_s(">");
			}
			break;
		case 13:		// ввод строк
			switch (i) {
			case 0:
				Input_Word(1, A);	// первая строка
				break;
			case 1:
				Input_Word(2, B);	// вторая строка
				break;
			case 2:					// длина заданных строк
				clrscr(2, 13, 80, 13);
				gotoxy(2, 13);
				printf_s("Длина строки 1: %d, строки 2 : %d", Lenght_Word(A), Lenght_Word(B));
				break;
			case 3:					// Копировать вторую строку в первую
				if (Lenght_Word(A) == 0 || Lenght_Word(B) == 0)
					break;
				clrscr(2, 14, 80, 14);
				CopyStr(A, B);
				gotoxy(2, 14);
				printf_s("Копирование второй строки в первую: %s", A);
				break;
			case 4:					// Сравнить строки
				clrscr(2, 15, 80, 15);
				gotoxy(2, 15);
				j = CompareStrs(A, B);
				if (j == 1)
					printf_s("Сравнение строк: строки равны");
				else if (j == 2)
					printf_s("Строки не заданы");
				else
					printf_s("Сравнение строк: строки не равны");
				break;
			case 5:					// Соединить строки
				clrscr(2, 16, 80, 16);
				gotoxy(2, 16);
				ConcatStrs(A, B, C);
				printf_s("Конкатенация строк: %s", C);
				break;
			case 6:
				Process = false;
				break;
			}
			break;
		case 49:			// нажата 1 - выбран п. 1 - ввод 1 строки
			gotoxy(0, i);	
			printf_s(" ");
			gotoxy(0, 0);
			printf_s(">");
			i = 0;
			Input_Word(1, A);
			break;
		case 50:			// нажата 2 - выбран п. 2 - ввод 2 строки
			gotoxy(0, i);
			printf_s(" ");
			gotoxy(0, 1);
			printf_s(">");
			i = 1;
			Input_Word(2, B);
			break;
		case 51:			// нажата 3 - длина заданных строк
			gotoxy(0, i);
			printf_s(" ");
			gotoxy(0, 2);
			printf_s(">");
			clrscr(2, 13, 80, 13);
			gotoxy(2, 13);
			i = 2;
			printf_s("Длина строки 1: %d, строки 2 : %d", Lenght_Word(A), Lenght_Word(B));
			break;
		case 52:			// нажата 4 - Копировать вторую строку в первую
			gotoxy(0, i);
			printf_s(" ");
			gotoxy(0, 3);
			printf_s(">");
			i = 3;
			if (Lenght_Word(A) == 0 || Lenght_Word(B) == 0)
				break;
			clrscr(2, 14, 80, 14);
			CopyStr(A, B);
			gotoxy(2, 14);
			printf_s("Копирование второй строки в первую: %s", A);
			break;
		case 53:			// нажата 5 - Сравнить строки
			gotoxy(0, i);
			printf_s(" ");
			gotoxy(0, 4);
			printf_s(">");
			clrscr(2, 15, 80, 15);
			gotoxy(2, 15);
			i = 4;
			j = CompareStrs(A, B);
			if (j == 1) 
				printf_s("Сравнение строк: строки равны");
			else if (j == 2)
				printf_s("Строки не заданы");
			else 
				printf_s("Сравнение строк: строки не равны");
			break;
		case 54:			// нажата 6 - Соединить строки
			gotoxy(0, i);
			printf_s(" ");
			gotoxy(0, 5);
			printf_s(">");
			i = 5;
			clrscr(2, 16, 80, 16);
			gotoxy(2, 16);
			ConcatStrs(A, B, C);
			printf_s("Конкатенация строк: %s", C);
			break;
		case 55:			// нажата 7 - выбран п. 7 - выход
			Process = false;
			break;
		default:
			//Hide_Cursor();
			break;
		}	
	}
}
int main() {
	SetConsoleOutputCP(1251);
	Menu();
	return 0;
}