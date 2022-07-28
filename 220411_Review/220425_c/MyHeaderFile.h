#pragma once

#define PRINT_ERROR(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg);


typedef struct A {
	int a;
	int b;
} A;

int Add(int a, int b);