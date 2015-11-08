/*
Словом назовем  последовательность букв латинского алфавита
длины не более 20. Предложением - всякую последовательность
не более 30 слов, разделенных одним или несколькими пробелами, оканчивающуюся
символом ".", "!", "?". Напишите программу, читающую заданное предложение,
контророурующую его правильность и вополняюющую функцию, которая: распечатывает все слова,
состоящие из одинковых букв и содержащие не менее 2 символов.
*/
#include<stdio.h>

#pragma warning(disable: 4669)

#define WORD 20 // длина слова
#define WORDS 30 //количество слов

void CheckInsert(int, char*, char*);
void CheckWords(int, char*);
void CheckSentences(int, char*);
void CheckSpaces(int, char*, char*);
int LenCheckedSentences(int, char*);
void PrintArray(int, char*);
void FindWords(int, char*, char*);
system();

int main(int argv, char *argc[]) {
	int	i = 0,
		len = 0, //длина массива
		ch = 0;
	int lenSentences = 0;
	char Sentences[WORD*WORDS];
	char checkedSentences[WORD*WORDS];
	char words[WORD*WORDS];

	for (i = 0; i < WORD*WORDS; i++) {
		checkedSentences[i] = '*';
		words[i] = 0;
	}

	i = 0;
	while ((ch = getchar()) != '\n') {
		Sentences[i] = ch;
		i++;
		len++;
	}

	CheckInsert(len, Sentences, checkedSentences);
	lenSentences = LenCheckedSentences(len, checkedSentences);

	PrintArray(lenSentences, checkedSentences);

	FindWords(lenSentences, checkedSentences, words);

	system("PAUSE");
	return 0;
}

void CheckInsert(int len, char* Sentences, char* checkedSentences) {
	int i = 0,
		lenSentences = 0;
	CheckSpaces(len, Sentences, checkedSentences);
	lenSentences = LenCheckedSentences(len, checkedSentences);
	CheckWords(lenSentences, checkedSentences);
	CheckSentences(lenSentences, checkedSentences);
}

int LenCheckedSentences(int len, char* checkedSentences) {
	int i = 0,
		lenSentences = 0;
	for (i = 0; i < len; i++) {
		if (checkedSentences[i] == '*') {
			break;
		}
		else {
			lenSentences++;
		}
	}
	return lenSentences;
}

void PrintArray(int lenSentences, char* checkedSentences) {
	int i = 0;
	printf("Array: ");
	for (i = 0; i < lenSentences; i++) {
		printf("%c", checkedSentences[i]);
	}
	puts("\n");
}

void CheckSpaces(int len, char* Sentences, char* checkedSentences) {
	int i = 0,
		num = 0,
		lenSentences = 0,
		flag = -1;
	char ch;
	for (i = 0; i < len; i++) {
		ch = Sentences[i];
		if (ch != ' ') {
			if (checkedSentences[num] == ' ') {
				num++;
				checkedSentences[num] = ch;
			}
			checkedSentences[num] = ch;
			flag = 0;
			num++;
		}
		else if (flag == 0) {
			checkedSentences[num] = ch;
			flag = 1;
		}
	}
}

void CheckWords(int len, char* checkedSentences) {
	int i = 0,
		wordLen = 0,
		flag = 0;
	char ch;
	for (i = 0; i < len; i++) {
		ch = checkedSentences[i];
		if (ch == ' ') {
			wordLen = 0;
		}
		else {
			wordLen++;
		}
		if (wordLen > WORD) {
			printf("Incorrect WORD, Word must been <= 20 chars\n");
			return;
		}
	}
}

void CheckSentences(int lenSentences, char* checkedSentences) {
	int i = 0,
		num = 0,
		word = 0;
	for (i = 0; i < lenSentences; i++) {
		if (checkedSentences[i] == ' ') {
			word++;
		}
		if (word > WORDS) {
			printf("Incorrect Sentences");
			return;
		}
		if (checkedSentences[i] == '!' ||
			checkedSentences[i] == '?' ||
			checkedSentences[i] == '.') {
			num++;
			printf("Sentences %d\n", num);
		}
	}
}

void FindWords(int lenSentences, char* checkedSentences, char* words) {
	int i = 0,
		j = 0,
		flag = 0,
		len = 0;
	char ch1, chI;
	for (i = 0; i < lenSentences; i++) {
		ch1 = checkedSentences[i];
		chI = checkedSentences[i + 1];
		if (ch1 == chI) {
			ch1 = chI;
			len++;
			flag = 1;
			words[i] = ch1;
		}
		else {
			flag = 0;
			words[i] = 0;
		}
		if (checkedSentences[i] == ' ') {
			len = 0;
			words[i] = ' ';
		}
	}
}
