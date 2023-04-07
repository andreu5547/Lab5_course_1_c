#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc_stack.h"

char operation() { // Обработка построчно входных данных и разбиение их на операнды и числа
    clear_stacks(); // Очистка стеков перед началом работы с новой строкой
    char c, buf[100]; // Буферы для символа и чисел
    int key = 0, i = 0; // Ключ на элементы числа и счётчик
    push_o('\n'); // Пушим служебный операнд, чтобы узнать, когда закончатся вводимые пользователям операнды
    while ((c = getchar()) != '\n') { // Считываем посимвольно до конца строки
        if ((c >= '0' && c <= '9') || c == '.') { // Символы чисел
            buf[i++] = c;
            key = 1;
        } else if (key) { // Если не символ числа, то проверим были ли символы чисел, если были, соберём число
            buf[i] = '\0';
            push(atof(buf));
            key = 0;
            i = 0;
        } else if (c == EOF) { // Проверка на конец потока
            return EOF;
        } else if (c != ' ') { // Если не пробел, то сохраним операнд
            push_o(c);
        }
    }
    return '0';
}

int calk_main() { // Main функция калькулятора
    char o;
    double op2;
    while (operation() != EOF) { // Проверка на конец ввода
        while ((o = pop_o()) != '\0') // Проверка на конец обработки строки
            switch (o) { // Кейсы входных операций
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '^':
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case '/' :
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else {
                        printf("error: zero divisor\n");
                        return -1;
                    }
                    break;
                case '%' : // целочисленное деление
                    op2 = pop();
                    if (op2 != 0.0)
                        push((int) (pop() / op2));
                    else {
                        printf("error: zero divisor\n");
                        return -1;
                    }
                    break;
                case 's': // sin
                    push(sin(pop()));
                    break;
                case 'c': // cos
                    push(cos(pop()));
                    break;
                case '\n' : // Обработка конца вычислений
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("error: unknown command %c\n", o);
                    return -1;
            }
    }
    return 0;
}
