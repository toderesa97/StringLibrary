#include <stdio.h>
char* mistr_copy(char* s1, char* s2);
int str_len(char* c);

int main(){
	
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
