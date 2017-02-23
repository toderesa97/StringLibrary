// test_mistring.c
// ===============
// Batería de pruebas de la biblioteca "mistring"
//
// Podrás empezar a usarla cuando hayas hecho un fichero "mistring.h"
// al menos con los cuerpos vacíos de las funciones mi_strlen, mi_strcat 
// y mi_strequals

#ifndef TEST
#include "mistring.h"
#endif

#include <assert.h>
#include <stdio.h>

// Este bloque es para probar que "test_mistring.c" está correctamente
// escrito, sin necesidad de que aún esté implementado "mi_string.c"
// En ese caso, compilar con la opción -DTEST
#ifdef TEST
#include <string.h>
#define mi_strlen strlen
#define mi_strcat strcat
#define mi_strequals(a,b) (strcmp(a,b)==0)
#endif

#define DebeSerCierto(x)	assert(x)
#define DebeSerFalso(x)		assert(!(x))

void INICIO_TEST (const char* titulo_test)
{
  printf("- batería de pruebas para %s: ", titulo_test); 
 	// fflush fuerza que se imprima el mensaje anterior
	// sin necesidad de utilizar un salto de línea
	fflush(stdout);
}

void FIN_TEST (const char* titulo_test)
{
  printf ("hecho\n");
}

void test_mi_strlen()
{
  char cadena_1000 [1000];
  int i;
  #define LONGITUD_TEST 500
  for (i=0; i<LONGITUD_TEST; i++) 
  {
    cadena_1000[i] = 32+(rand()%96);
  }
  cadena_1000[LONGITUD_TEST] = '\0'; 
  
  INICIO_TEST("mi_strlen");
	DebeSerCierto(mi_strlen("hola mundo") == 10);
	DebeSerCierto(mi_strlen("") == 0);
	DebeSerCierto(mi_strlen(cadena_1000) == LONGITUD_TEST);
	FIN_TEST("mi_strlen");
}

void test_mi_strcat()
{
	char cadena1[15] = { 'h','o','l','a', '\0' };
	char* resultado = mi_strcat(cadena1," mundo");
	INICIO_TEST("mi_strcat");
	DebeSerCierto(cadena1 == resultado);
	DebeSerCierto(mi_strlen(cadena1)==10);
	DebeSerCierto(mi_strequals(cadena1,"hola mundo"));
	DebeSerFalso(mi_strequals(cadena1,"hola"));
	FIN_TEST("mi_strcat");
}

void test_mi_strcopy(){
	char s1[100] = "Muy buenos dias por la mañana";
	char s2[50] = "Pio pio! :-)";
	INICIO_TEST("mi_strcpy");
	char* nueva_cadena = mi_strcpy(s1, s2);
	DebeSerCierto(nueva_cadena == s1);

	mi_strcpy(s2,s1);
	DebeSerCierto(mi_strequals(s2, "Pio pio! :-)"));
	FIN_TEST("mi_strcpy");
}

void test_mi_strequals(){
	char s1[100] = "¡Muy buenos dias por la mañana!";
	char s2[50] = "Pio pio!:-)";
	
	INICIO_TEST("mi_strequals");
	DebeSerFalso(mi_strequals(s1,s2));
	mi_strcpy(s2,s1);
	DebeSerCierto(mi_strequals(s2,"¡Muy buenos dias por la mañana!"));
	FIN_TEST("mi_strequals");

}

void test_mi_strdup(){
	char s2[55] = "La programación es un arte";

	INICIO_TEST("mi_strdup");
	char* duplicado_s2 = mi_strdup(s2);
	DebeSerFalso(duplicado_s2 == s2);
	DebeSerCierto(mi_strequals(duplicado_s2,s2));
	
	//alterando el contenido de s2 para comprobar que no
	//se mantiene una referencia y que efectivamente está duplicado!!
	*s2 = 'P'; 
	DebeSerFalso(mi_strequals(duplicado_s2,s2));
	FIN_TEST("mi_strdup");
}


void ejecuta_tests ()
{
	test_mi_strlen();
	test_mi_strequals();
	test_mi_strcat();
	test_mi_strcopy();
	test_mi_strdup();
}

main()
{
	puts("Iniciando tests...");
	
	ejecuta_tests();
	
	puts("Batería de test completa.");
}

