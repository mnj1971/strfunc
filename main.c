#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "goodies.h"

int Lenght_Word(char *Word);

void Input_Word(int N, char* Word) {		// ������� ����� �����. �������� - ����� �����
	bool Process = true;
	int Ch = 0;
	int i = 0;
	if (Lenght_Word(Word) > 0)
		i = Lenght_Word(Word);
	else
		i = 0;
	gotoxy(2, N + 10);
	Show_Cursor();
	printf_s("������� %d-� ������: ", N);
	gotoxy(22 + i, N + 10);
	while (Process) {
		Ch = _getch();
		if ((Ch != 0) || (Ch != 224)) {		// ���� ��� �� ������-������������������, ��������
			if (((Ch >= 32) && (Ch <= 126)) && (i < 10)) {	// 
				Word[i] = Ch;
				gotoxy(22 + i, N + 10);
				printf_s("%c", Ch);
				++i;
			}
		}
		if (Ch == 0 || Ch == 224) {		//  ���� ��� ������-������������������, �������� ��������� ������ �� ������
			Ch = _getch();
		}
		if (Ch == 27) {
			if (Lenght_Word(Word) > 0) {
				gotoxy(22, N + 10);
				printf_s("%s", Word);
			}
			Process = false;
		}
		if (Ch == 13) {					// ������ �����
			Hide_Cursor();
			Word[i] = '\0';				// ����� ���� ��������� ������ - 0
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
// ����� ������
int Lenght_Word(const char *Word) {
	int i, count;
	bool Check = false;	// �� ������ ���������� 0 � ����� ������
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
// ��������� �����
int CompareStrs(char* Str1, char* Str2) {
	int i = 0;
	int j = 0;
	int count = 0;
	if ((Lenght_Word(Str1) == 0 && (Lenght_Word(Str2) == 0))) // ���� ������ �� ������
		return 2;
	if ((Lenght_Word(Str1)) != (Lenght_Word(Str2)))
		return 0;
	else {
		j = Lenght_Word(Str1);
		for (i = 0; i < j; i++) {
			if (Str1[i] != Str2[i])
				++count;
		}
		if (count == 0)	// ���� ��� ���������, �� 
			return 1;
		else
			return 0;
	}
}
// ���������� �����
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
// ����������� ������ ������ � ������
void CopyStr(char* Str1, char* Str2) {
	int i, j, k;
	i = Lenght_Word(Str1);		// ����� 1 ������
	j = Lenght_Word(Str2);		// ����� 2 ������
	if (i == 0 || j == 0)
		return;
	if (i == j) {		// ���� ����� ����������, ������ �������� ���� � ������
		for (i = 0; i < j; i++) {
			Str1[i] = Str2[i];
		}
	}
	else if (i > j) {		// ���� ������� ������ ������, ����� �� � ������� �������
		for (k = 0; k < j; ++k) {
			Str1[k] = Str2[k];
		}
	}
	else {				// ���� ������ ������ ������, �� ��� ����������� �� � ���������� '\0'
		for (k = 0; k < j; ++k) {
			Str1[k] = Str2[k];
		}
		Str1[j] = '\0';
	}
	gotoxy(22, 11);		// �������� ������ ������ ����� ������ �������
	printf_s("%s", Str1);
}

// ���������� ���� � �������� � ���
void Menu() {			
	bool Process = true;
	int Key = 0;	// ������� �������
	int i = 0;		// ����� ������ ����
	int j = 0;		
	char *A = malloc(sizeof(char)*11); // ������ ������
	char *B = malloc(sizeof(char)*11); // ������ ������
	char *C = malloc(sizeof(char)*21); // ��������� ������
	Hide_Cursor();
	printf_s(" 1. ������ ������ ������\n");
	printf_s(" 2. ������ ������ ������\n");
	printf_s(" 3. ����� ������\n");
	printf_s(" 4. ���������� ������ ������ � ������\n");
	printf_s(" 5. �������� ������\n");
	printf_s(" 6. ��������� ������\n");
	printf_s(" 7. �����\n");
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
		case 13:		// ���� �����
			switch (i) {
			case 0:
				Input_Word(1, A);	// ������ ������
				break;
			case 1:
				Input_Word(2, B);	// ������ ������
				break;
			case 2:					// ����� �������� �����
				clrscr(2, 13, 80, 13);
				gotoxy(2, 13);
				printf_s("����� ������ 1: %d, ������ 2 : %d", Lenght_Word(A), Lenght_Word(B));
				break;
			case 3:					// ���������� ������ ������ � ������
				if (Lenght_Word(A) == 0 || Lenght_Word(B) == 0)
					break;
				clrscr(2, 14, 80, 14);
				CopyStr(A, B);
				gotoxy(2, 14);
				printf_s("����������� ������ ������ � ������: %s", A);
				break;
			case 4:					// �������� ������
				clrscr(2, 15, 80, 15);
				gotoxy(2, 15);
				j = CompareStrs(A, B);
				if (j == 1)
					printf_s("��������� �����: ������ �����");
				else if (j == 2)
					printf_s("������ �� ������");
				else
					printf_s("��������� �����: ������ �� �����");
				break;
			case 5:					// ��������� ������
				clrscr(2, 16, 80, 16);
				gotoxy(2, 16);
				ConcatStrs(A, B, C);
				printf_s("������������ �����: %s", C);
				break;
			case 6:
				Process = false;
				break;
			}
			break;
		case 49:			// ������ 1 - ������ �. 1 - ���� 1 ������
			gotoxy(0, i);	
			printf_s(" ");
			gotoxy(0, 0);
			printf_s(">");
			i = 0;
			Input_Word(1, A);
			break;
		case 50:			// ������ 2 - ������ �. 2 - ���� 2 ������
			gotoxy(0, i);
			printf_s(" ");
			gotoxy(0, 1);
			printf_s(">");
			i = 1;
			Input_Word(2, B);
			break;
		case 51:			// ������ 3 - ����� �������� �����
			gotoxy(0, i);
			printf_s(" ");
			gotoxy(0, 2);
			printf_s(">");
			clrscr(2, 13, 80, 13);
			gotoxy(2, 13);
			i = 2;
			printf_s("����� ������ 1: %d, ������ 2 : %d", Lenght_Word(A), Lenght_Word(B));
			break;
		case 52:			// ������ 4 - ���������� ������ ������ � ������
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
			printf_s("����������� ������ ������ � ������: %s", A);
			break;
		case 53:			// ������ 5 - �������� ������
			gotoxy(0, i);
			printf_s(" ");
			gotoxy(0, 4);
			printf_s(">");
			clrscr(2, 15, 80, 15);
			gotoxy(2, 15);
			i = 4;
			j = CompareStrs(A, B);
			if (j == 1) 
				printf_s("��������� �����: ������ �����");
			else if (j == 2)
				printf_s("������ �� ������");
			else 
				printf_s("��������� �����: ������ �� �����");
			break;
		case 54:			// ������ 6 - ��������� ������
			gotoxy(0, i);
			printf_s(" ");
			gotoxy(0, 5);
			printf_s(">");
			i = 5;
			clrscr(2, 16, 80, 16);
			gotoxy(2, 16);
			ConcatStrs(A, B, C);
			printf_s("������������ �����: %s", C);
			break;
		case 55:			// ������ 7 - ������ �. 7 - �����
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