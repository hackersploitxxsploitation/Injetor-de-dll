#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
int injetor_dll(char caminhodll[],int pid){
    //  PID  -  do processo  ou seja o  numero que identifica o  rpoocesso.

char *b=&caminhodll;
    HANDLE p=OpenProcess(PROCESS_VM_WRITE && PROCESS_VM_OPERATION,FALSE,pid);//Identificador para o  process  aberto.
    LPVOID x= VirtualAllocEx(p,NULL,strlen(caminhodll),MEM_COMMIT,PAGE_READWRITE);
    WriteProcessMemory(p,x,b,strlen(caminhodll),NULL);
    LPTHREAD_START_ROUTINE k =(LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32"),
			"LoadLibraryW");
   HANDLE v =  CreateRemoteThread(p,NULL,0,k,x,0,0);
   WaitForSingleObject(v,INFINITE);
    printf("funçao  e thread executada com sucesso  \n");


return 0;}

int main(){
    char m[]="=====BEM VINDO AO INJETOR DE DLL  PARA UM  PROCESSO. SELECIONE  UM  CAMINHO  USANDO  BARRAS  DUPLAS E UM  NUMERO PARA  O  PID";
printf(" %s \n",m);
printf("Digite o  PID do  processo  alvo : \n");
DWORD  z;
char s[600];
scanf("%d",&z);
printf(" Digite o  caminho  nao se esqueça  de preecher com  barras duplas : \n ");
scanf(" %s",s);
injetor_dll(s,z);



     return 0;   }
