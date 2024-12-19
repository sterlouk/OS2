#include <stdio.h>
#include <stdlib.h>

int add(int* pa, int* pb, int* pc) {
    int sum;
    sum = *pa + *pb + *pc;
    printf("1st argument is the address of a: pa = %p\nthen the value of a: a = %d\n", pa, *pa);
    printf("2nd argument is the address of b: pb = %p\nthen the value of b: b = %d\n", pb, *pb);
    printf("3rd argument is the address of c: pc = %p\nthen the value of c: c = %d\n", pc, *pc);

    printf("the sum of the numbers is: a + b + c = %d\n", sum);
    
    return sum;
    
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    int* pa = &a;
    int* pb = &b;
    int* pc = &c;
    add(pa, pb, pc);
    return 0;
}
