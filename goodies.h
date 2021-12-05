#ifndef GOODIES
#define GOODIES

extern const Black;
extern const Blue;
extern const Green;
extern const Cyan;
extern const Red;
extern const Magenta;
extern const Brown;
extern const Lightgray;
extern const Darkgray;
extern const Lightblue;
extern const Lightgreen;
extern const Lightcyan;
extern const Lightred;
extern const Lightmagenta;
extern const Yellow;
extern const White;

// ��������� ����� ������� � ����� ����
void SetColor(int text, int bg);
// ������� � �������� ������� ������
void gotoxy(int x, int y);
// ������� �������� ������� ������
void clrscr(int x1, int y1, int x2, int y2);
// ������ ������ - ����� �� �����������
void Hide_Cursor();
// �������� ������ - ����� �� �����������
void Show_Cursor();
// ���������� ��������������� ����� �� ��������� (min, max) - ����� �� �����������
int Random(int min, int max);
// ��������� ����� �������� ����
void DrawFrame(int w, int h, int color);
#endif
