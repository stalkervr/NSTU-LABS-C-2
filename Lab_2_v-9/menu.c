
#include "header.h"

void info()
{
    printf("\n\t\t\t����������� � ���������������� �-2. ������������ ������ �2 ������� �9.\n\n");
    printf("  ������� : \n");
    printf("\t    ���������� ����������������� ���, ���������� ����� ������� ��� ������ � �������� ��������.\n");
    printf("\t  �  ����������������� ���������� ������������� ������ ������� �� ��� \n\t  �� ���������� ������ (�.�. ""������"").\n");
    printf("\t  ������� ������ �������� � �������� �������� ��� � ��������� ���������� ����� ���������,\n");
    printf("\t  � ����� ��� ������������� ���������� ��������� �� ���������. \n\n\t  � �������� ������� ������:\n\n");
    printf("\t  - �������� ����������������� ����������;\n");
    printf("\t  - ����� ��������� ����������������� ����������;\n");
    printf("\t  - ���� ��������� (�����) ��������� � ����������;\n");
    printf("\t  - ����� ��������� (�����) ��������� � ����������;\n");
    printf("\t  - ����� � ������� ��������� � ����������� ���������  ��������� ����;\n");
    printf("\t  - ���������� �������  �������� � ������� ����������� ��������� ����\n");
    printf("\t    (��� ���������� ����� ������������ ��� ����, ��� � ��++ �����������\n");
    printf("\t    ������������ ����������������� ����������);\n");
    printf("\t  - ����� � ������� �������� �������� � �������� ��������� ���� \n");
    printf("\t    ��� � �������� ������� � ���� �� ��������.\n");
    printf("\t  - �������� ��������� ��������;\n");
    printf("\t  - ��������� (��������������) ��������� ��������.\n");
    printf("\t  - ���������� � ��������� � �������������� ���� ��������� ������� �� ��������� �������\n");
    printf("\t    � ������� (��������, ����� ����� �� ���� ������) -  ������ �������������.\n\n");
    printf("\t  �������� ����� ����������������� ����������.\n\n");
    printf("\t  ������� � 9. ������� �.�., ���������� ������, ������, ������� ����.\n\n");
    printf("\t\t\t\t��� ����� � ��������� ������� | Enter |\n");
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

        case ENTER: // ��������� ������
            clear_screen();
            print_menu_header();
            print_table_header();
            print_all_items(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_L: // �������� �������� �������
            clear_screen();
            print_menu_header();
            print_table_header();
            items = add_test_data_to_array(items, _count_record, _last_id);
            print_all_items(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_A: // �������� ������
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            items = data_add_to_array(items, _count_record, _last_id, _count_free_items);
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_E: // ������������� ������
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_all_items(items, _count_record);
            print_line();
            items = edit_item(items, _count_record);
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_D: // ������� ������
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_all_items(items, _count_record);
            print_line();
            items = delete_item(items, _count_record);
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_C: // �������� ������
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_all_items(items, _count_record);
            print_line();
            items = clear_item(items, _count_record);
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_W: // ������ ���������� id
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

        case SHIFT_Q: // ������ ���������� surname
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

        case SHIFT_F: // ������ ������ ������� ���
            clear_screen();
            print_menu_header();
            print_table_header();
            //print_line();
            print_items_range_average(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_R: // ���� ��������� ��� �� ���
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_items_min(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_T: // ���� ��������� ���� �� ���
            clear_screen();
            print_menu_header();
            print_table_header();
            print_line();
            print_items_max(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_S: // ������ ������ surname
            clear_screen();
            print_menu_header();
            print_table_header();
            //print_line();
            search_by_name(items, _count_record);
            print_line();
            print_footer(_count_record, _count_free_items, items);
            break;

        case SHIFT_I: // �������� �������
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
    printf(" | ESC -> �����.         | Shift+A -> ��������.     | Shift+D -> �������.    | Shift+S -> ����� �� ������� |\n");
    printf(" | Enter -> ���������.   | Shift+E -> �������������.| Shift+C -> ��������.   | Shift+F -> ����� ��. ���    |\n");
    print_line();
    printf(" | Shift+Q -> ���������� �� �������.                | Shift+W -> ��������� �� id.                          |\n");
    print_line();
    printf(" | Shift+R -> ������ ��������� � ���. ������� ����� | Shift+T -> ������ ��������� � ���. ������� �����     |\n");
    print_line();
    printf("\n");
}

void print_table_header()
{
    //printf("\n");
    print_line();
    // body
    printf(" | Id | �������              | ���             | ��������                    | ���-�� ������ | ������� ��� |\n");
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
    printf(" | ����� �� ������������ �������� ����  ||  |\n");
    print_line();
    printf("\n");
}

void print_footer(int* _count_record, int* _count_free_items, student* items)
{
    *_count_free_items = count_free_items(items, _count_record);
    printf("\n");
    print_line();
    printf(" | <<   ������ %3d      ||     ����� ������� ->  %3d     ||  �������� ->  %3d    || ������� ��� %.2lf    >> |\n",
        all_items_count_marks(items, _count_record), *_count_record, *_count_free_items, all_items_average_marks(items, _count_record));
    print_line();
    printf(" | <<<<                  ��� �������� �������� ������ ������� ��������� ������ Shift + L              >>>> |\n");
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
        printf("  ����������� ������ � ���� !\n");
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
        printf("  �� ������� ������� � �������� ������� ����� !!!\n");
    }
}

double input_average_marks()
{
    double input_value;
    printf("  ������� �������� ��� ������ �������� ���� �������� - > ");
    scanf("%lf", &input_value);
    printf("  ���� �������� ������� ������ �� ��������� �������� ��� \n");
    printf("  c �������� ������� � ���� ���������... \n");
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
    printf("\n  �� ������� ������ � ��������� id = %d !!!\n", _item_id);
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