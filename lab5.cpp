#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){

  const char* short_options = "hlpc";

  const struct option long_options[] = {
    {"help",no_argument,NULL,'h'},
    {"loop",no_argument,NULL,'l'},
    {"pwd",no_argument,NULL,'p'},
    {"cout",no_argument,NULL,'c'},
    {NULL,0,NULL,0}
  };
  bool help = false;
  bool loop = false;
  bool pwd = false;
  bool cout = false;
  int rez;
  int option_index;

  while ((rez=getopt_long(argc,argv,short_options,
    long_options,&option_index))!=-1){

    switch(rez){
      case 'h': {
        help = true;
        break;
      };
      case 'l': {
        loop = true;
        break;
      };
  
      case 'p': {
        pwd = true;
        break;
      };
      case 'c': {
        cout = true;
        break;
      };
      case '?': default: {
        printf("found unknown option\n");
        break;
      };
    };
  };
  if(help)
    printf("Arg: help\n");
  if(loop)
    printf("Arg: loop\n");
  if(pwd)
    printf("Arg: pwd\n");
  if(cout)
    printf("Arg: cout\n");
  return 0;
};
