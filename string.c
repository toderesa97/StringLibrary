#include <stdio.h>
char* mistr_copy(char* s1, char* s2);
char* mistr_copy(char* s1, char* s2);
int str_len(char* c);
int mi_strequals(char* s1, char* s2);
char* mi_strcat(char* s1, char* s2);

int main(){

	
	char s1[100] = ", how are you?";
	char s2[100] = ", how are you?";
	mi_strcat(s1, s2);

	//expected: Hi you there!, how are you?
	printf("obtained:%s\n", s1);

	//expected: false (0)
	printf("obtained:%d\n", mi_strequals(s1, s2));
	
}

int str_len(char *c){
	int length = 0;
	char* ptr = c;
	while(*(ptr++) != 0) length++;
	return length;	
}

char *mistr_copy(char *s1, char *s2){
	char* ptrs2 = s2;
	char* ptrs1 = s1;
	char final = '\0';
	while(*ptrs2 !=0 || *ptrs1 !=0){
		*(ptrs1++) = *(ptrs2++);
	}
	*ptrs1 = final;
	return ptrs1;
}

char* mi_strcat(char* s1, char* s2){
	while(*s1){
		s1++;
	}
	while(*s2){
		*(s1++) = *(s2++);
	}
	*s1 = '\0';
}

int mi_strequals(char* s1, char* s2){
	while(*s1 != '\0' && *s2 != '\0'){
		if(*s1++ != *s2++) return 0;
	}
	//return (*s1=='\0' && *s2=='\0');
	return str_len(s1) != str_len(s2);
}
