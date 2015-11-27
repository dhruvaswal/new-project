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
 
 if(strcmp(opcode,"START")==0)
  {
   start=atoi(operand);
   locctr=start;
   fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
   fscanf(fp1,"%s%s%s",label,opcode,operand);
  }
 else
  locctr=0;
 while(strcmp(opcode,"END")!=0)
  {
   fprintf(fp3,"%d",locctr);
   if(strcmp(label,"**")!=0)
     fprintf(fp2,"%s\t%d\n",label,locctr);
   strcpy(code[i],mnemonic[j]);
   while(strcmp(mnemonic[j],"END")!=0)
    {
     if(strcmp(opcode,mnemonic[j])==0)
     {
      locctr+=3;
      break;
     }
     strcpy(code[i],mnemonic[j]);
     j++;
    }
   if(strcmp(opcode,"WORD")==0)
    locctr+=3;
   else if(strcmp(opcode,"RESW")==0)
    locctr+=(3*(atoi(operand)));
   else if(strcmp(opcode,"RESB")==0)
    locctr+=(atoi(operand));
   else if(strcmp(opcode,"BYTE")==0)
    ++locctr;
   fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
   fscanf(fp1,"%s%s%s",label,opcode,operand);
  }
  fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
  length=locctr-start;
fclose(fp1);
  fclose(fp2);
  fclose(fp3);
