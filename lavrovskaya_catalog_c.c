#include"CATALOG.H"
#pragma warning(disable: 4996)

void addFile(Catalog **catalog) {
    Catalog *head = NULL,
        *file = NULL,
        *current = NULL;

    int count = 0,
        i = 0,
        j = 0;

    char *name;
    int ch = 0;

    time_t *time_date = NULL;

    unsigned int file_size = 0;

    size_t catalog_size = sizeof(Catalog);
    size_t name_size = sizeof(char);
    size_t tm_size = sizeof(time_t);

    system("CLS");
    head = *catalog;
    do {
        fflush(stdin);
        printf("How mach files do you want add?\nCount of files: ");
        scanf("%d", &count);
        for (i = 0; i < count; i++) {
            file = (Catalog *)malloc(catalog_size);
            name = (char *)malloc(name_size * LENGTH_FILE_NAME);
            time_date = (time_t *)malloc(tm_size);
            *time_date = time(NULL);
            nameEntering(name);

            file_size = rand() % 10;
            file->Next_File = NULL;
            file->Name = name;
            file->Size = file_size;
            file->Date = localtime(time_date);

            if (!*catalog) {
                *catalog = file;
                head = *catalog;
            }
            else {
                current = head;
                while (current->Next_File != NULL) {
                    current = current->Next_File;
                }
                current->Next_File = file;
            }
        }
        printf("Do you want add some files? y/n : ");
        scanf("%d", &ch);
    }
    while (ch = getchar() == 'y');
}


void nameEntering(char *name) {
    printf("Enter the file name: ");
    scanf("%s", name);
}
void printList(Catalog **catalog){
    Catalog *current = *catalog;
    int i = 1;
    while (current != NULL) {
        printf("\nFile %d, size: %d bytes, name: %s\n", i, current->Size, current->Name);
        printf("%04d/%02d/%02d %02d:%02d:%02d \n", 
            current->Date->tm_year + 1900, 
            current->Date->tm_mon + 1,
            current->Date->tm_mday,
            current->Date->tm_hour,
            current->Date->tm_min,
            current->Date->tm_sec);
        current = current->Next_File;
        i++;
    }
}

void delFiles(Catalog **catalog) {
    Catalog *current = *catalog,
        *tmp = NULL;

    unsigned int year = 0,
        mounth = 0,
        day = 0;

    printf("Insert date- \n");
    printf("Insert year: ");
    scanf("%d", &year);
    printf("Insert mounth: ");
    scanf("%d", &mounth);
    printf("Insert day: ");
    scanf("%d", &day);

    while (current->Next_File != NULL) {
        tmp = current->Next_File;
        if (!tmp) {
            return;
        }
        if ((current->Date->tm_year + 1900 == year) && (current->Date->tm_mon + 1 == mounth) && (current->Date->tm_mday == day)) {

        }
        current = current->Next_File;
    }
    

}
