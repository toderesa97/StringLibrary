#include <stdio.h>
#include <stdlib.h>

char* mi_strcpy(char* s1, char* s2);
int mi_strlen(char* c);
int mi_strequals(char* s1, char* s2);
char* mi_strcat(char* s1, char* s2);
char* mi_strdup(char* str);

int main(){

	
	char s1[100] = "abcd";
	char s2[100] = "efgh";
	mi_strcat(s1, s2);

	//expected: Hi you there!, how are you?
	printf("obtained:%s\n", s1);

	//expected: false (0)
	printf("obtained:%d\n", mi_strequals(s1, s2));

	char* cad_new = mi_strdup(s1);
	printf("s1 is:%s\n",s1);
	*s1 = 'O'; //to see if there are difference!
	printf("s1 is:%s\n",s1);
	printf("cad_new is:%s\n",cad_new);
	
}

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
	return mi_strlen(s1) != mi_strlen(s2);
}

char* mi_strdup(char* str){
	
	
	char* ptr = malloc(mi_strlen(str)*sizeof(char));
	mi_strcpy(ptr, str);
	return ptr;
	/*
	printf("\nfunction mi_strdup: %c\n",*str);
	while(*str){
		*ptr++ = *str++;
		printf("%c",*ptr);
	}
	printf("NO ENTRO");
	return ptr;
	*/
}
