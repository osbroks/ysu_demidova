//B4.2 Двусвязный список содержит в качестве информационного поля одно данное типа int.Требуется
//организовать процедуру, которая осуществляет «склеивание» двух таких списков, адресуемых указателя -
//ми First1 и First2, в следующем порядке : сначала идет первый элемент первого списка, затем первый
//элемент второго списка, затем второй элемент первого списка, второй элемент второго списка и так далее.
//При этом, если один из списков окажется длиннее, то требуется :
//3) выбросить остаток списка, освободив при этом занимаемую им память.Итоговый(объединенный)
//список вывести на печать.

#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

#include"LIST.H"

#pragma warning(disable: 4996)

int main(void) {
    unsigned int i = 0;
    unsigned int rand1 = 0, rand2 = 0;
    int count = 0;
    int length_list1 = 0,
        length_list2 = 0;
    List *First1 = NULL;
    List *First2 = NULL;
    List *Result = NULL;
    
    printf("insert length of list 1: ");
    scanf("%d", &length_list1);
    printf("\ninsert length of list 2: ");
    scanf("%d", &length_list2);

    for (i = 0; i < length_list1; i++) {
        addElem(&First1, &i);
    }
    for (i = 0; i < length_list2; i++) {
        addElem(&First2, &i);
    }
    doIt(&First1, &First2);
    printf("result:\n");
    printList(&First1);
    free(First2);
    free(First1);
    system("PAUSE");
    return 0;
}
