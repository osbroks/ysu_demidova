/*
Словом назовем  последовательность букв латинского алфавита
длины не более 20. Предложением - всякую последовательность
не более 30 слов, разделенных одним или несколькими пробелами, оканчивающуюся
символом ".", "!", "?". Напишите программу, читающую заданное предложение,
контророурующую его правильность и вополняюющую функцию, которая: распечатывает все слова,
состоящие из одинковых букв и содержащие не менее 2 символов.
*/
#include<stdio.h>
#include<stdlib.h>

#define WORD 20
#define WORDS 30

int checkSentence(int, char *);
void checkWord(int, char *);
void checkWords(int, char *);
void printWords(int, char *);
int main(int argv, char *argc){
	int i = 0,
		len = 0,
		lenSentence = 0,
		flag = 0;
	char sentence[WORD*WORDS];
	char ch;
	
	while((ch = getchar()) != '\n'){
		if(ch != ' '){
			flag = 0;
			sentence[i] = ch;
			i++;
			len++;
		}
		else if(flag == 0){
			flag = 1;
			sentence[i] = ch;
			i++;
			len++;
		}
	}

	lenSentence = checkSentence(len, sentence);
	checkWord(lenSentence, sentence);
	checkWords(lenSentence, sentence);
	printWords(lenSentence, sentence);

	system("PAUSE");
	return 0;
}

void printWords(int lenSentence, char *sentence){
	int i = 0,
		c = 0,
		len = 0,
		num = 0,
		pointer = 0;

	char ch, ch1;
	ch = sentence[0];
	for(i = 0; i <= lenSentence; i++){
		ch1 = sentence[i];
		if(ch == ch1 && (ch1 != ' ' || ch1 != '\0')){
			len++;
		}
		else if (len >= 2 && (ch1 != ' ' || ch1 != '\0')){
			pointer = i - len;
			num++;
			printf("word %d: ", num);
			for(c = pointer; c <u i; c++){
				printf("%c", sentence[c]);
			}
			printf("\n");
			len = 0;
			ch = sentence[i+1];
		}
		else {
			len = 0;
			ch = sentence[i+1];
		}
	}
}

void checkWords(int lenSentence, char *sentence){
	int i = 0,
		words = 0;
	for(i = 0; i < lenSentence; i++){
		if(sentence[i] == ' '){
			words++;
		}
		if(words > WORDS){
			printf("INCORRECT SENTENCE");
			return;
		}
	}
}

void checkWord(int lenSentence, char *sentence){
	int i = 0,
		wordLen = 0;
	for(i = 0; i < lenSentence; i++){
		if(sentence[i] == ' '){
			wordLen = 0;
		}
		else{
			wordLen++;
		}
		if(wordLen > WORD){
			printf("\nINCORRECT WORD");
			return;
		}
	}
}

int checkSentence(int len, char *sentence){
	int i = 0,
		lenSentence = 0;
	for(i = 0; i < len; i++){
		if(sentence[i] == '.' ||
			sentence[i] == '!' ||
			sentence[i] == '?'){
				printf("\nEND SENTENCE");
				break;
		}
		else {
			lenSentence++;
		}
	}
	return lenSentence;
}
