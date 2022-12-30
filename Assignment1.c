#include <stdio.h>
#include <string.h>
#define SIZE  100

void reverse_string( char* str){
   int length= strlen(str);
   char temp;
   for(int i = 0 ; i < length/2 ; i++){
      temp = str[i];
      str[i]=str[length-i-1];
      str[length-i-1]=temp;
   }
}
  
int main(){
   char str[SIZE]="";
   char ch;
   int indx=0;
   printf("enter string:\n");
   while(ch!='\n'){
      scanf("%c",&ch);
      str[indx++]=ch;
   }
   reverse_string(str);
   printf("string in reverse order:%s",str);
   return 0 ;
}