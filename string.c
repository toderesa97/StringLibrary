#include <stdio.h>
#include <stdlib.h>
#include "mistring.h"

char* mi_strcpy(char* s1, char* s2);
int mi_strlen(char* c);
int mi_strequals(char* s1, char* s2);
char* mi_strcat(char* s1, char* s2);
char* mi_strdup(char* str);
/*
int main(){

	
	char s1[100] = "abcde";
	char s2[100] = "abcd";
	printf("s1 :%s\n",s1);
	printf("s2 :%s\n",s2);
	printf("Comprobando si dos string son iguales (s1 y s2):%d\n", mi_strequals(s1, s2));

	mi_strcat(s1, s2);
	
	//expected: Hi you there!, how are you?
	printf("String concatenados (a s1):%s\n", s1);

	//expected: false (0)
	
	char* cad_new = mi_strdup(s1);
	printf("s1 is:%s\n",s1);
	*s1 = 'O'; //to see if there are difference!
	printf("s1 modificada con una O en el comienzo:%s\n",s1);
	printf("variable cad_new duplicada de s1 NO modificada:%s\n",cad_new);
	
}
*/
int mi_strlen(char *c){
	int length = 0;
	char* ptr = c;
	while(*ptr++) length++;
	return length;	
}

char *mi_strcpy(char *s1, char *s2){
	char* ptrs2 = s2;
	char* ptrs1 = s1;
	char final = '\0';
	while(*ptrs2 || *ptrs1){
		*(ptrs1++) = *(ptrs2++);
	}
	*ptrs1 = final;
	return s1;
}

char* mi_strcat(char* s1, char* s2){
	char * initial = s1;
	while(*s1){
		s1++;
	}
	while(*s2){
		*(s1++) = *(s2++);
	}
	*s1 = '\0';
	return initial;
}

int mi_strequals(char* s1, char* s2){
	while(*s1 != '\0' && *s2 != '\0'){
		if(*s1++ != *s2++) return 0;
	}
	return (*s1=='\0' && *s2=='\0');
}

char* mi_strdup(char* str){
	char* ptr = malloc(mi_strlen(str)*sizeof(char));
	char* initial = ptr;
	while(*str){
		*ptr++ = *str++;
	}
	
	return initial;
	
}
