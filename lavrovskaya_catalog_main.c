//B6.11 Каталог файлов организован в виде линейного списка.Для каждого файла содержатся следу -
//ющие сведения :
//• имя файла;
//• дата и время создания;
//• размер в байтах.
//Написать программу, которая обеспечивает :
//• начальное формирование каталога файлов;
//• вывод каталога файлов, упорядоченного по заданному параметру;
//• удаление файлов, дата создания которых меньше заданной.
#include"CATALOG.H"

#pragma warning(disable: 4996)
#pragma optimize("[optimization-list]", off)

int menu() {
    int choice = 0;
    while (1) {
        system("CLS");
        printf("======MENU======\n");
        printf("1 - Add file\n");
        printf("2 - Print catalog\n");
        printf("3 - Del\n");
        printf("4 - Exit\n");
        printf("you choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        default: break;
        }
    }
    return choice;
}

int main(void) {
    int choice = 0;
    Catalog *catalog = NULL;
    while (choice != 4) {
        choice = menu();
        switch (choice)
        {
        case 1: addFile(&catalog); break;
        case 2: printList(&catalog); system("pause"); break;
        case 3: delFiles(&catalog); system("pause"); break;
        case 4: return 0;
        default:
            break;
        }
    }
    free(catalog);
    system("PAUSE");
    return 0;
}
