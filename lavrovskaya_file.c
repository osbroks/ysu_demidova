/*
В текстовом файле содержится ведомость экзамена группы студентов. Первая строка файла
содержит название предмета (30 позиций), вторая — название группы (6 позиций). Каждая следующая
строка файла содержит запись об одном студенте. Формат записи:
• фамилия и инициалы (30 позиций), фамилия должна начинаться с первой позиции;
• оценка (число от 2 до 5).
Требуется составить программу, которая формирует файл результата путем переписывания туда исходной
ведомости и добавления в конец информации о количестве студентов в группе, количестве студентов
получивших каждую оценку, а также средний балл в группе.
*/

#include<stdio.h>
#include<stdlib.h>

#define SUBJ_SIZE 30
#define GROUP 6
#define NAME 30

#pragma warning(disable: 4996)

int main(int argv, char *argc[]) {
    int i = 0,
        subject_count = 0,
        group_count = 0,
        name_count = 0,
        students = 0,
        mark = 0,
        mark_f = 0,
        mark_c = 0,
        mark_b = 0,
        mark_a = 0;
    float middle_mark = 0.0;
    int *placeholder = NULL;
    char ch = 0;
    char subject[SUBJ_SIZE],
        group[GROUP],
        name[NAME];
    char *f_name = "file.txt",
        *out_name = "out_file.txt";


    FILE *file = fopen(f_name, "rt");
    FILE *out_file = fopen(out_name, "wt");
    if (file == NULL) file = fopen(f_name, "wt");
    if (out_file == NULL) {
        printf("ERROR create out file");
        return;
    }

    for (i = 0; i < SUBJ_SIZE; i++) {
        if (subject[i - 1] != '\n') {
            fscanf(file, "%c", &subject[i]);
            subject_count++;
        }
        else {
            break;
        };
    }
    for (i = 0; i < subject_count; i++) {
        fprintf(out_file, "%c", subject[i]);
    }

    for (i = 0; i < GROUP; i++) {
        if (group[i - 1] != '\n') {
            fscanf(file, "%c", &group[i]);
            group_count++;
        }
        else {
            break;
        };
    }
    for (i = 0; i < group_count; i++) {
        fprintf(out_file, "%c", group[i]);
    }
    fprintf(out_file, "%c", '\n');

    while (ch = fgetc(file) != EOF) {
        name_count = 0;
        for (i = 0; i < NAME; i++) {
            if (name[i - 1] != ' ') {
                fscanf(file, "%c", &name[i]);
                name_count++;
            }
            else {
                ch = fgetc(file);
                switch (ch) {
                    case '2': {
                        mark_f++;
                        break;
                    }
                    case '3': {
                        mark_c++;
                        break;
                    }
                    case '4': {
                        mark_b++;
                        break;
                    }
                    case '5': {
                        mark_a++;
                        break;
                    }
                }
                students++;
                break;
            };
        }
        for (i = 0; i < name_count; i++) {
            fprintf(out_file, "%c", name[i]);
        }
        fprintf(out_file, "%c\n", ch);
    }

    middle_mark = (float)((mark_f * 2) + (mark_c * 3) + (mark_b * 4) + (mark_a * 5)) / students;

    fprintf(out_file, "\nCount of Students %d", students);
    fprintf(out_file,"\nMark 2 have %d students", mark_f);
    fprintf(out_file, "\nMark 3 have %d students", mark_c);
    fprintf(out_file, "\nMark 4 have %d students", mark_b);
    fprintf(out_file, "\nMark 5 have %d students", mark_a);
    fprintf(out_file, "\nMiddle mark %.3f ", middle_mark);

    fclose(file);
    fclose(out_file);
    return 0;
}
