#include <stdio.h>

int main(){

    int age = 25; //it is a normal integer which is a whole number

    /* 'unsigned' mean no negative numbers. 
     a intger can normally contain both negative and positive numbers.
     but 'unsigned' integer removes the negative side
     so the usigned int age; can only have a positive number
     so a unsigned intger can have more positive numbers because there are no negative numbers
     */
    // an unsigned integer can hold n^32 -1 numbers as it starts from 0
     unsigned int B; // it will contail pure 32 bit positive numbers
     B = 0;
     printf("%u\n", B); // this will print only 0

     B= -1;
     printf("%u", B); // there is no negative number so -1 wraps around and prints 4294967295 

     B = 4294967295;
     printf("\n%d", B + 1); // it prints 1 as it does not have the capacity for more numbers 
     // 11111111 11111111 11111111 11111111
     //


}