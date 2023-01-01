#include <stdio.h>
#include <string.h>
#define SIZE  100

void reverse_string( char* str){
   
   int length= strlen(str);//length of the string
   char* left = str;//index of the first element (most left)
   char* right = str + length - 1;//index of the last element (most right)
  
   while(left<right){ //swap
   
      char temp = *left;
      *left = *right;
      *right = temp;
      
      left++; right--; //to move the pointer
   }
}
  
int main(){

   char str[SIZE]="\0";
   char ch;
   int index=0;
   
   printf("enter string:\n");

   while(ch!='\n'){
      scanf("%c",&ch);
      str[index++]=ch;
   }
   
   reverse_string(str);
   printf("string in reverse order:%s",str);
   return 0 ;
}