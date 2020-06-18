
#include "header.h"

void info()
{
    printf("\n\t\t\tИнформатика и программирование Ч-2. Лабораторная работа №2 вариант №9.\n\n");
    printf("  Задание : \n");
    printf("\t    Определить структурированный тип, определить набор функций для работы с массивом структур.\n");
    printf("\t  В  структурированной переменной предусмотреть способ отметки ее как \n\t  не содержащей данных (т.е. ""пустой"").\n");
    printf("\t  Функции должны работать с массивом структур или с отдельной структурой через указатели,\n");
    printf("\t  а также при необходимости возвращать указатель на структуру. \n\n\t  В перечень функций входят:\n\n");
    printf("\t  - «очистка» структурированных переменных;\n");
    printf("\t  - поиск свободной структурированной переменной;\n");
    printf("\t  - ввод элементов (полей) структуры с клавиатуры;\n");
    printf("\t  - вывод элементов (полей) структуры с клавиатуры;\n");
    printf("\t  - поиск в массиве структуры и минимальным значением  заданного поля;\n");
    printf("\t  - сортировка массива  структур в порядке возрастания заданного поля\n");
    printf("\t    (при сортировке можно использовать тот факт, что в Си++ разрешается\n");
    printf("\t    присваивание структурированных переменных);\n");
    printf("\t  - поиск в массиве структур элемента с заданным значением поля \n");
    printf("\t    или с наиболее близким к нему по значению.\n");
    printf("\t  - удаление заданного элемента;\n");
    printf("\t  - изменение (редактирование) заданного элемента.\n");
    printf("\t  - вычисление с проверкой и использованием всех элементов массива по заданному условию\n");
    printf("\t    и формуле (например, общая сумма на всех счетах) -  дается индивидуально.\n\n");
    printf("\t  Перечень полей структурированной переменной.\n\n");
    printf("\t  Вариант № 9. Фамилия И.О., количество оценок, оценки, средний балл.\n\n");
    printf("\t\t\t\tДля входа в программу нажмите | Enter |\n");
}

void start(student* items, int* _count_record, int* _last_id, int* _count_free_items)
{
    clear_screen();
    info();
    while (true)
    {
        switch (_getch())
        {
        case ESC:
            free(items);
            exit(0);

        case ENTER: // загрузить записи
            clear_screen();
            print_menu_header();
            print_table_header();
            print_all_items(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_L: // загрузка тестовых записей
            clear_screen();
            print_menu_header();
            print_table_header();
            items = add_test_data_to_array(items, _count_record, _last_id);
            print_all_items(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_A: // добавить запись
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            items = data_add_to_array(items, _count_record, _last_id, _count_free_items);
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_E: // редактировать запись
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_all_items(items, _count_record);
            print_line();
            items = edit_item(items, _count_record);
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_D: // удалить запись
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_all_items(items, _count_record);
            print_line();
            items = delete_item(items, _count_record);
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_C: // очистить запись
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_all_items(items, _count_record);
            print_line();
            items = clear_item(items, _count_record);
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_W: // запуск сортировки id
            clear_screen();
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            sort_by_id(items, _count_record);
            print_all_items(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_Q: // запуск сортировки surname
            clear_screen();
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            sort_by_surname(items, _count_record);
            print_all_items(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_F: // запуск поиска средний бал
            clear_screen();
            print_menu_header();
            print_table_header();
            //print_line();
            print_items_range_average(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_R: // спис студентов мин ср бал
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_items_min(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_T: // спис студентов макс ср бал
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_items_max(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_S: // запуск поиска surname
            clear_screen();
            print_menu_header();
            print_table_header();
            //print_line();
            search_by_name(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_I: // показать задание
            clear_screen();
            info();
            break;
        }
    }
}

void clear_screen()
{
    system("cls");
}

void print_menu_header()
{
    printf("\n");
    print_line();
    printf(" | ESC -> Выход.         | Shift+A -> Добавить.     | Shift+D -> Удалить.    | Shift+S -> Поиск по фимилии |\n");
    printf(" | Enter -> Загрузить.   | Shift+E -> Редактировать.| Shift+C -> Очистить.   | Shift+F -> Поиск ср. бал    |\n");
    print_line();
    printf(" | Shift+Q -> Сортировка по фамилии.                | Shift+W -> Сртировка по id.                          |\n");
    print_line();
    printf(" | Shift+R -> Список студентов с мин. средним балом | Shift+T -> Список студентов с мак. средним балом     |\n");
    print_line();
    printf("\n");
}

void print_table_header()
{
    //printf("\n");
    print_line();
    // body
    printf(" | Id | Фамилия              | Имя             | Отчество                    | Кол-во оценок | Средний бал |\n");
    print_line();
    //printf("\n");
}

void print_one_record(student* item)
{
    printf(" |%3d | %20s | %15s | %27s | %13d | %11f |\n",
        item->id, item->surname, item->name, item->second_name, item->marks_count, item->marks_average);
}

void print_search_header()
{
    printf("\n");
    print_line();
    // body
    printf(" | Поиск по минимальному среднему балу  ||  |\n");
    print_line();
    printf("\n");
}

void print_footer(int* _count_record, int* _count_free_items, student* items)
{
    *_count_free_items = count_free_items(items, _count_record);
    printf("\n");
    print_line();
    printf(" | <<   Оценок %3d      ||     Всего записей ->  %3d     ||  Свободно ->  %3d    || Средний бал %.2lf    >> |\n",
        all_items_count_marks(items, _count_record), *_count_record, *_count_free_items, all_items_average_marks(items, _count_record));
    print_line();
    printf(" | <<<<                  Для загрузки тестовых данных нажмите сочетание клавиш Shift + L              >>>> |\n");
    print_line();
    printf("\n");
}

void print_line()
{
    printf(" ");
    for (int i = 0; i < 107; i++) {
        printf("-");
    }
    printf("\n");
}

int count_free_items(student* items, const int* _count_record) {
    int count = 0;
    int _is_free;
    if (items != NULL) {
        for (student* item = items; item < items + *_count_record; item++) {
            _is_free = item->is_free;
            if (_is_free == 1) {
                count++;
            }
        }
    }
    return count;
}

void print_all_items(student* items, const int* _count_record)
{
    if (items != NULL) {
        for (student* item = items; item < items + *_count_record; item++)
        {
            if (item->is_free == 0)
            {
                print_one_record(item);
            }
        }
    }
    else {
        printf("  Отсутствуют записи в базе !\n");
    }
}

void print_items_min(student* items, const int* _count_record)
{
    double _min = search_min_average_marks(items, _count_record);
    if (_min > 0)
    {
        for (student* item = items; item < items + *_count_record; item++)
        {
            if (item->marks_average == _min)
            {
                print_one_record(item);
            }
        }
    }
}

void print_items_max(student* items, const int* _count_record)
{
    double _max = search_max_average_marks(items, _count_record);
    if (_max > 0)
    {
        for (student* item = items; item < items + *_count_record; item++)
        {
            if (item->marks_average == _max)
            {
                print_one_record(item);
            }
        }
    }
}

void print_items_range_average(student* items, const int* _count_record)
{
    double input_value = input_average_marks();
    double _avr;
    int flag = 0;
    if (items) {
        for (student* item = items; item < items + *_count_record; item++)
        {
            _avr = item->marks_average;
            if (_avr >= input_value - 0.3 &&
                _avr <= input_value + 0.3)
            {
                print_one_record(item);
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        printf("  Не найдено записей с заданным средним балом !!!\n");
    }
}

double input_average_marks()
{
    double input_value;
    printf("  Введите значение для поиска среднего бала студента - > ");
    scanf("%lf", &input_value);
    printf("  Была запущена функция поиска по заданному значению или \n");
    printf("  c наиболее близким к нему значением... \n");
    print_line();
    print_line();
    //_getch();
    return input_value;
}

double all_items_average_marks(student* items, const int* _count_record)
{
    double _all = 0;
    if (items != NULL) {
        for (student* item = items; item < items + *_count_record; item++)
        {
            if (item->is_free == 0)
            {
                _all = _all + item->marks_average;
            }
        }
        return _all / *_count_record;
    }
    return 0;
}

int all_items_count_marks(student* items, const int* _count_record)
{
    int _all = 0;
    if (items != NULL) {
        for (student* item = items; item < items + *_count_record; item++)
        {
            if (item->is_free == 0)
            {
                _all = _all + item->marks_count;
            }
        }
        return _all;
    }
    return 0;
}

void print_not_found_error(int _item_id)
{
    printf("\n  Не найдено записи с введенным id = %d !!!\n", _item_id);
}

//int mygetch() {
//    struct termios termios, newt;
//    int ch;
//    tcgetattr(STDIN_FILENO, &termios);
//    newt = termios;
//    newt.c_lflag &= ~(ICANON | ECHO);
//    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
//    ch = getchar();
//    tcsetattr(STDIN_FILENO, TCSANOW, &termios);
//    return ch;
//}