#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

void input(Complex *c) {
    printf("Enter real and imaginary parts: ");
    scanf("%f %f", &c->real, &c->imag);
}

void display(Complex c) {
    printf("%.2f + %.2fi\n", c.real, c.imag);
}

Complex Add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex Sub(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex Mul(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

int main() {
    Complex num1, num2, num3;

    input(&num1);
    input(&num2);

    num3 = Add(num1, num2);
    printf("Addition: ");
    display(num3);

    num3 = Sub(num1, num2);
    printf("Subtraction: ");
    display(num3);

    num3 = Mul(num1, num2);
    printf("Multiplication: ");
    display(num3);

    return 0;
}