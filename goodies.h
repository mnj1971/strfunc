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

// установка цвета символа и цвета фона
void SetColor(int text, int bg);
// переход в заданную позицию экрана
void gotoxy(int x, int y);
// очистка заданной области экрана
void clrscr(int x1, int y1, int x2, int y2);
// Скрыть курсор - взято на киберфоруме
void Hide_Cursor();
// Показать курсор - взято на киберфоруме
void Show_Cursor();
// Возвращает псевдослучайное число из диапазона (min, max) - взято на киберфоруме
int Random(int min, int max);
// отрисовка рамки игрового поля
void DrawFrame(int w, int h, int color);
#endif
