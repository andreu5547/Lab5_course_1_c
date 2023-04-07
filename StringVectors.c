#include <stdio.h>
#include <stdlib.h>

#define COEFF_UP_MEMORY 2

typedef struct CVector { // структура для CVector'а (интерпретация строки)
    char *values; // содержимое
    int size; // реальный размер
    int capacity; // ёмкость массива
} CVector;

void add_memory_cvector(CVector* ve) { // Функция расширения вместимости CVector'а
    if (ve->capacity < 10000) // Выбираем коэффициент в зависимости от вместимости
        ve->capacity = ve->capacity * COEFF_UP_MEMORY;
    else ve->capacity = (int) ve->capacity * COEFF_UP_MEMORY / 2; // Устанавливаем новое значение вместимости
    ve->values = (char *) realloc(ve->values, ve->capacity * sizeof(char)); // Выделяем новое количество памяти
    if (!ve->values) { // Проверяем выделилась ли память
        puts("Allocation error!");
        exit(1);
    }
}

void check_memory_cvector(CVector* ve) { // Функция проверки вместимости CVector'а
    if (ve->capacity - ve->size == 0) {
        add_memory_cvector(ve);
    }
}

CVector* init_cvector(int n) { // функция инициализации CVector'а -> создание, установка ёмкости, размера, выделение памяти
    CVector *vec = (CVector*) malloc(sizeof(CVector));

    vec->size = 0;
    if (n < 0) { // обработка ввода отрицательного размера
        vec->capacity = 0;
        puts("Error: The size of the set must be >= 0");
    } else vec->capacity = n;

    vec->values = malloc(sizeof(char) * n);
    if (!vec->values) { // Проверяем выделилась ли память
        puts("Allocation error!");
        exit(1);
    }

    return vec;
}

void input_cvector(CVector* ve){ // Функция ввода CVector'а из stdin
    char c; // Временная переменная
    int i = 0; // Счётчик длинны
    while ((c = getchar()) != '\n') { // Считываем посимвольно
        check_memory_cvector(ve);
        ve->values[i++] = c;
        ve->size++;
    }
    check_memory_cvector(ve);
    ve->values[i] = '\0';
    ve->size++;
}

void add_symbol_cvector(CVector* ve, char symbol) { // Функция добавление символа в конец CVector'а
    check_memory_cvector(ve);
    ve->values[ve->size - 1] = symbol;
    ve->size++;
    ve->values[ve->size - 1] = '\0';
}

char* give_string(CVector* ve) { // Функция возвращает указатель на массив с символами (стандартная строка)
    return (char *) ve->values;
}

void free_CV(CVector* ve) { // Функция очистки CVector'а
    free(ve->values);
    free(ve);
}

int find_pos_first_sym_ve1_in_ve2(CVector* ve1, CVector* ve2) { // Функция поиска позиции первого символа из ve1 в ve2 // num 1
    for (int i = 0; i < ve1->size - 2; ++i) {
        for (int j = 0; j < ve2->size - 2; ++j) {
            if (ve1->values[i] == ve2->values[j])
                return i;
        }
    }
    return -1;
}