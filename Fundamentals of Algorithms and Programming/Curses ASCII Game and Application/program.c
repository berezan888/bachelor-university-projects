#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define JUMP_HEIGHT 5
#define DAY_NIGHT_SWITCH_SCORE 2

typedef enum { DAY, NIGHT } GameTime;
struct timespec ticks = {
        .tv_sec = 0,                    // nr of secs
        .tv_nsec = 0.02 * 1000000000L  // nr of nanosecs
};


// Глобальные переменные
int dinoX, dinoY;      // Координаты динозавра
int obstacleX, obstacleY;  // Координаты препятствия
GameTime gameTime;      // Время суток (день или ночь)

// Функция для отображения динозавра
void displayDino() {
    mvprintw(dinoY, dinoX, "@");
}

// Функция для отображения препятствия (кактуса или птеродактиля)
void displayObstacle() {
    mvprintw(obstacleY, obstacleX, "X");
}
//void displayObstacle2() {
//    mvprintw(obstacleY, obstacleX, "L");
//}

// Функция для отображения игрового поля
void displayGameField() {
    if (gameTime == DAY) {
        attron(COLOR_PAIR(1)); // Белый фон для дня
    } else {
        attron(COLOR_PAIR(2)); // Черный фон для ночи
    }

    for (int i = 0; i < LINES; ++i) {
        for (int j = 0; j < COLS; ++j) {
            mvaddch(i, j, ' ');
        }
    }

    attroff(COLOR_PAIR(6));
    attroff(COLOR_PAIR(2));
}

// Функция для отображения экрана завершения игры
void displayGameOverScreen() {
    clear();
    mvprintw(LINES / 2 - 1, COLS / 2 - 7, "Game Over!");
    mvprintw(LINES / 2, COLS / 2 - 15, "Press 'r' to restart the game.");
    refresh();
}

// Функция для обработки пользовательского ввода
void processInput(int key) {

}

// Функция для создания нового случайного препятствия
void spawnObstacle() {
    obstacleX = COLS - 1;
    obstacleY = LINES / 2;
}

// Функция для обновления времени суток в зависимости от счета
void updateGameTime(const int sw) {
    if (sw) {
        gameTime = (gameTime == DAY) ? NIGHT : DAY;
    }
}
void drawFrame() {
    attron(COLOR_PAIR(3));  // Цвет рамки (например, желтый)

    // Верхняя горизонтальная линия
    mvhline(0, 0, '#', COLS);

    // Нижняя горизонтальная линия
    mvhline(LINES - 1, 0, '#', COLS);

    // Левая вертикальная линия
    mvvline(0, 0, '#', LINES);

    // Правая вертикальная линия
    mvvline(0, COLS - 1, '#', LINES);

    attroff(COLOR_PAIR(3));
}

void displayFloor() {
    attron(COLOR_PAIR(1));
    // mvvline(LINES / 2 + 1, 0, '#', LINES);

    for (int i = 0; i < COLS; ++i) {
        mvprintw(LINES / 2 + 1, i, "#");
    }
    attroff(COLOR_PAIR(1));
}

int main() {
    // Инициализация ncurses
    initscr();
    keypad(stdscr, TRUE);  // Включение обработки специальных клавиш
    timeout(0);            // Неблокирующий ввод
    curs_set(0);           // Скрыть курсор
    start_color();         // Включение цветового режима

    // Определение цветов
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // День
    init_pair(2, COLOR_WHITE, COLOR_BLACK); // Ночь
    drawFrame();
    // Инициализация переменных
    dinoX = COLS / 4;
    dinoY = LINES / 2;
    obstacleX = COLS - 1;
    obstacleY = LINES / 2;
    int score = 0;
    gameTime = DAY;

    int jump_ticks = 0;
    int is_falling;

    int obstacle_ticks = 0;

    // Основной цикл игры
    while (1) {
        int key = getch();

        if (key != ERR) {
            switch (key) {
                case KEY_UP:
                    if (jump_ticks == 0) {
                        jump_ticks = 1;
                    }
                    break;
            }
        }

        // Обновление координат препятствия
        obstacleX--;

        // Проверка на выход за границы экрана
        if (obstacleX < 0) {
            obstacleX = COLS - 1;
            score++;

            if (score % DAY_NIGHT_SWITCH_SCORE == 0) {
                updateGameTime(score);
            }
        }

        if (jump_ticks > 0) {
            if (is_falling) {
                if (dinoY < LINES/2) {
                    dinoY++;
                }
                jump_ticks--;
            }
            else {
                dinoY--;
                jump_ticks++;
            }

            if (jump_ticks == JUMP_HEIGHT) is_falling = 1;
            if (jump_ticks == 0) is_falling = 0;
        }

        // Очистка экрана и отображение игрового поля
        clear();
        displayGameField();


        // Отображение динозавра и препятствия
        displayDino();

       // if (obstacle_ticks == 5) {
            // Action
         //   obstacle_ticks = 0;
       // }

        displayObstacle();
        displayFloor();


        // Отображение счета и времени суток
        mvprintw(0, 0, "Score: %d", score);
        mvprintw(0, COLS - 15, "Time: %s", (gameTime == DAY) ? "Day" : "Night");

        // Обновление экрана
        refresh();

        // Задержка для контроля скорости игры
//        usleep(DELAY);
        nanosleep(&ticks, NULL);

        // Проверка на столкновение с препятствием
        if (dinoY == obstacleY && dinoX == obstacleX) {
            displayGameOverScreen();

            while (1) {
                int key = getch();
                if (key == 'r') {
                    // Перезапуск игры
                    dinoY = LINES / 2;
                    obstacleX = COLS - 1;
                    score = 0;
                    break;
                }
            }
        }

        obstacle_ticks++;
    }

    // Завершение ncurses
    endwin();

    return 0;
}
