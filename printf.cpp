#include <cstdio>
#include <cstring>
#include <cstdarg>

/************************************************************
 *
 * TBD: Revise the minprintf to handle more of the other 
 *      facilities of printf
 *
 ***********************************************************/
void minprintf(char *fmt,...){
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;

  va_start(ap,fmt);
  for(p=fmt; *p; p++){
    if(*p != '%'){
      putchar(*p);
      continue;
    }
    switch(*++p){
    case 'd':
      ival = va_arg(ap, int);
      printf("%d",ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%f",dval);
      break;
    case 's':
      for(sval=va_arg(ap,char *); *sval; sval++)
        putchar(*sval);
      break;
    default:
      putchar(*p);
      break;
    }
  }
  va_end(ap);
}

int main(){
  char c='!';
  char ch[]="hello,world";
  int num=1234567890;
  float fl=123.456789;
  //printf("hello,world\n");
  //printf("hello,world%c\n",c);
  printf(":%10s:%10c:\n",ch,c);
  printf(":%.10s:%10c:\n",ch,c);
  printf(":%10s:%10d:\n",ch,num);
  printf(":%15.10s:%10d:\n",ch,num);
  // Both the number before and after the period('.') specify the 
  // mininum digits an intiger should show
  printf(":%-15.10s:%5.8d:\n",ch,num);
  printf(":%-15.10s:%5.8f:\n",ch,fl);
  minprintf(":%s:%f:\n",ch,fl);
}
