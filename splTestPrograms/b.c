#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#define typename(x) _Generic((x), int: "int", float: "float", default: "other")
#define print_any(X) _Generic((X), int: print_int, char *: print_pchar, char: print_char, float: print_float)(X)

int print_int(int i) { return printf("%d", i); }

int print_float(float f) { return printf("%f", f); }

int print_pchar(char *c) { return printf("%s", c); }

int print_char(char c) { return printf("%c", c); }

int main(void) {

	int a, b;

	char c;

	float d, e;

	char str[254];
	printf("Please enter a value: ");
	scanf("%s", str);
	if(typename(a) == "other")
		a = *str;
	else if(typename(a) == "int")
		a = atoi(str);
	else if(typename(a) == "float")
		a = atof(str);

	printf("Please enter a value: ");
	scanf("%s", str);
	if(typename(b) == "other")
		b = *str;
	else if(typename(b) == "int")
		b = atoi(str);
	else if(typename(b) == "float")
		b = atof(str);


	if (a > b) {
		print_any("A");
	}
	else {
		print_any("B");
	}

	printf("\n");
	printf("Please enter a value: ");
	scanf("%s", str);
	if(typename(d) == "other")
		d = *str;
	else if(typename(d) == "int")
		d = atoi(str);
	else if(typename(d) == "float")
		d = atof(str);

	e = d * 2.3;
	print_any(e);
	printf("\n");
	printf("Please enter a value: ");
	scanf("%s", str);
	if(typename(c) == "other")
		c = *str;
	else if(typename(c) == "int")
		c = atoi(str);
	else if(typename(c) == "float")
		c = atof(str);

	print_any(c);
	printf("\n");

}
