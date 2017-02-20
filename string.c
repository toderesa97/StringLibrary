#include <stdio.h>
char* mistr_copy(char* s1, char* s2);
char* mistr_copy(char* s1, char* s2);
int str_len(char* c);
char* mi_strcat(char* s1, char* s2);

int main(){

	
	char s1[100] = "Hi you there!";
	char s2[100] = ", how are you?";
	mi_strcat(s1, s2);

	//expected: Hi you there!, how are you?
	printf("expected:%s\n", s1);
	
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
