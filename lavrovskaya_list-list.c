#include"LIST.H"

#pragma warning(disable: 4669)

List *preEndOfList(List **list) {
    List *pre_end = NULL;
    pre_end = *list;
    while (pre_end->Next->Next != NULL) {
        pre_end = pre_end->Next;
    }

    return pre_end;
}

void addElem(List **list, int *count) {
    List *head = NULL,
        *current = NULL,
        *node = NULL,
        *prev = NULL,
        *end = NULL;

    node = (List *)malloc(sizeof(List));
    node->Data = *count;
    node->Next = NULL;
    node->Prev = NULL;

    if (*list == NULL) {
        *list = node;
    }
    else {
        head = current = *list;
        if (current->Next == NULL) {
            current->Next = node;
            prev = current;
            current = node;
            current->Prev = prev;
        }
        else
        {
            prev = preEndOfList(list);
            end = prev->Next;
            end->Next = node;
            current = node;
            current->Prev = end;
        }
    }
}

void doIt(List **first1, List **first2) {
    List *cur_list1 = NULL,
        *cur_list2 = NULL,
        *tmp = NULL,
        *tmp2 = NULL;

    cur_list1 = *first1;
    cur_list2 = *first2;

    if (cur_list1->Next == NULL || cur_list2->Next == NULL) {
        if (cur_list1->Next == NULL) {
            cur_list1->Next = cur_list2;
            cur_list2->Prev = cur_list1;
            tmp = cur_list2->Next;
            cur_list2->Next = NULL;
            cur_list2 = tmp;
            while (cur_list2 != NULL) {
                if (cur_list2->Next == NULL) {
                    free(cur_list2);
                    return;
                }
                else {
                    tmp = cur_list2->Next;
                    free(cur_list2);
                    cur_list2 = tmp;
                }
            }
        }
        else {
            tmp = cur_list1->Next;
            cur_list1->Next = cur_list2;
            cur_list2->Prev = cur_list1;
            cur_list2->Next = NULL;
            while (cur_list1 != NULL) {
                cur_list1 = tmp;
                if (cur_list1->Next == NULL) {
                    free(cur_list1);
                    return;
                }
                else {
                    tmp = cur_list1->Next;
                    free(cur_list1);
                    cur_list1 = tmp;
                }
            }
        }
        return;
    }

    while ((cur_list1->Next != NULL) && (cur_list2->Next != NULL)) {
        tmp = cur_list1->Next;
        tmp2 = cur_list2->Next;
        cur_list1->Next = cur_list2;
        cur_list2->Prev = cur_list1;
        cur_list1 = tmp;
        cur_list2->Next = cur_list1;
        cur_list1->Prev = cur_list2;
        cur_list2 = tmp2;
        if ((cur_list1->Next == NULL) || (cur_list2->Next == NULL)) {
            if (cur_list1->Next == NULL) {
                cur_list1->Next = cur_list2;
                cur_list2->Prev = cur_list1;
                tmp2 = cur_list2;
                while (cur_list2 != NULL) {
                    cur_list2 = cur_list2->Next;
                    if (cur_list2 == NULL) {
                        break;
                    }
                    tmp = cur_list2->Next;
                    free(cur_list2);
                    cur_list2 = tmp;
                }
                tmp2->Next = NULL;
                break;
            }
            else {
                tmp = cur_list1->Next;
                cur_list1->Next = cur_list2;
                cur_list2->Prev = cur_list1;
                tmp2 = cur_list2;
                while (cur_list2 != NULL) {
                    cur_list1 = tmp;
                    if (cur_list2->Next == NULL) {
                        break;
                    }
                    tmp = cur_list2->Next;
                    free(cur_list2);
                    cur_list2 = tmp;
                }
                tmp2->Next = NULL;
                break;
            }
        }
    }
}

void printList(List **list) {
    List *head = NULL;
    int i = 0;

    head = *list;
    while (head != NULL) {
        printf("elem %d: = %d\n", ++i, head->Data);
        head = head->Next;
    }
}
