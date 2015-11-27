#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
 char opcode[10],operand[10],label[10],a[10],ad[10],symbol[10],ch; char code[10][10],code1[10][10]={"33","44","53","57"};
 char mnemonic[10][10]={"START","LDA","STA","LDCH","STCH","END"};
 char mnemonic1[10][10]={"LDA","STA","LDCH","STCH"};
 int locctr,start,length,i=0,j=0,k,l=0;
 int st,diff,address,add,len,actual_len,finaddr,prevaddr;
 FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7;
 fp1=fopen("INPUT.txt","r");
 fp2=fopen("SYMTAB.txt","w");
 fp3=fopen("process.txt","w");
 fscanf(fp1,"%s%s%s",label,opcode,operand);
