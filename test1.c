#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef struct Complex {
	float realpart;
	float imagpart;
}Complex;

void assign (Complex *A, float real, float imag) {
	A->realpart = real;
	A->imagpart = imag;
}
void add (Complex *c,Complex A,Complex B){
	c->realpart = A.realpart + B.realpart;
	c->imagpart = A.imagpart + B.realpart;
}
void sub(Complex* c, Complex A, Complex B) {
	c->realpart = A.realpart + B.realpart;
	c->imagpart = A.imagpart + B.realpart;
}
void multiply(Complex* c, Complex A, Complex B) {
	c->realpart = A.realpart * B.realpart - A.imagpart * B.realpart;
	c->imagpart = A.imagpart + B.realpart + A.realpart * B.realpart;
}

int div(Complex* c, Complex A, Complex B) {
	double temp = B.realpart * B.realpart + B.imagpart * B.imagpart;
		printf("temp = %f\n", temp);
	if(temp == 0){
		return -1;
	}
	printf("%f\n", A.realpart * B.realpart + A.imagpart * B.realpart);
	printf("%f\n", A.imagpart + B.realpart - A.realpart * B.realpart);
	c->realpart = (A.realpart * B.realpart + A.imagpart * B.realpart) / temp;
	c->imagpart = (A.imagpart + B.realpart - A.realpart * B.realpart) / temp;
	return 0;
}
void main() {
	Complex z1, z2 , z3, z4 , z;
	assign(&z1, 8.0, 6.0);
	assign(&z2, 4.0, 3.0);
	multiply(&z3, z1, z2);
	printf("z3 = %f + %fi\n", z3.realpart, z3.imagpart);
	add(&z4, z2, z3);
	printf("z4 = %f + %fi\n", z4.realpart, z4.imagpart);
	int ret = div(&z, z3, z4);
	if (ret == -1) {
		printf("div by zero");
	}
	else {
		printf("ret = %f + %fi\n", z.realpart, z.imagpart);
	}
	return 0;

}
