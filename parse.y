%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "def.h"


int yylex();
int nowTable=0;//当前符号表
int maxTable = 0;//符号表的总数
int nextinstr = 100;//下一条三地址指令的索引
int ncodes = 0;//记录三地址指令的总数
int tmpVal = 0;//临时变量
int nts=0;//翻译生成的编号
int params=0;//函数参数的个数
void yyerror(const char* msg);
extern FILE *yyin;
extern int numLines;
%}

%union {
        char name[256];
        char *namePtr;
        double dval;
        struct symbol *symp;
        struct translate *attr;
        int instr;
}
//终结符
%token T_TURE
%token T_FALSE
%token <name> T_TYPE
%token <name> T_ID
%token T_ADD
%token T_SUB
%token T_MUL
%token T_DIV
%token T_MOD
%token T_ASSIGNOP
%token T_GT
%token T_LT
%token T_GE
%token T_LE
%token T_AND     
%token T_OR                                                  
%token <symp> T_NUM
%token <symp> T_DECIMAL
%token T_LEFTPAREN
%token T_LEFTBRACE
%token T_LEFTBRACKET
%token T_RIGHTPAREN
%token T_RIGHTBRACE
%token T_RIGHTBRACKET
%token T_SEMICOLON
%token T_COMMA                                            
%token T_STRING
%token T_NOT
%token T_IF
%token T_ELSE
%token T_WHILE
%token T_FOR
%token T_RETURN
%token T_EQUAL
%token T_UNEQUAL
%token T_ERROR
%token T_BREAK
%token T_CONTINUE
//优先级从低到高,结合性:left,right,级联
%nonassoc T_ID
%left T_COMMA
%right T_ASSIGNOP
%left T_OR
%left T_AND
%left T_EQUAL T_UNEQUAL
%nonassoc T_GE T_LE T_LT T_GT

%left T_ADD T_SUB
%left T_MUL T_DIV T_MOD
%right  T_NOT 
%right UMINUS
%left T_LEFTPAREN T_RIGHTPAREN
%left T_LEFTBRACKET T_RIGHTBRACKET
//非终结符
%type <attr> expression if_stmt while_loop N other statements block func_call
%type <instr> M



%%
//程序或者外部声明
program         :  func program            {}               
                |  declares program        {}
                |                          {}
                ;
//表达式:
expression      :  expression T_ADD expression           {$$=&ts[nts];nts++;sprintf($$->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s+%s",$$->name,$1->name,$3->name);genCodes(c);}
                |  expression T_SUB expression           {$$=&ts[nts];nts++;sprintf($$->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s-%s",$$->name,$1->name,$3->name);genCodes(c);}
                |  expression T_MUL expression           {$$=&ts[nts];nts++;sprintf($$->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s*%s",$$->name,$1->name,$3->name);genCodes(c);}
                |  expression T_DIV expression           {$$=&ts[nts];nts++;sprintf($$->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s/%s",$$->name,$1->name,$3->name);genCodes(c);}
                |  expression T_MOD expression           {$$=&ts[nts];nts++;sprintf($$->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s+%s",$$->name,$1->name,$3->name);genCodes(c);}
                |  expression T_AND M expression         {$$=&ts[nts];nts++;backPatch($1->trueList,$1->tTop,$3);merge($$->falseList,&($$->fTop),$1->falseList,$1->fTop,$4->falseList,$4->fTop);assign($$->trueList,&($$->tTop),$4->trueList,$4->tTop);}
                |  expression T_OR M expression          {$$=&ts[nts];nts++;backPatch($1->falseList,$1->fTop,$3);merge($$->trueList,&($$->tTop),$1->trueList,$1->tTop,$4->trueList,$4->tTop);assign($$->falseList,&($$->fTop),$4->falseList,$4->fTop);}
                |  expression T_GT expression            {$$=&ts[nts];nts++;$$->trueList[$$->tTop]=nextinstr;($$->tTop)++;char c[2000];sprintf(c,"if %s>%s goto ",$1->name,$3->name);genCodes(c);$$->falseList[$$->fTop]=nextinstr;($$->fTop)++;genCodes("goto ");}
                |  expression T_GE expression            {$$=&ts[nts];nts++;$$->trueList[$$->tTop]=nextinstr;($$->tTop)++;char c[2000];sprintf(c,"if %s>=%s goto ",$1->name,$3->name);genCodes(c);$$->falseList[$$->fTop]=nextinstr;($$->fTop)++;genCodes("goto ");}
                |  expression T_LT expression            {$$=&ts[nts];nts++;$$->trueList[$$->tTop]=nextinstr;($$->tTop)++;char c[2000];sprintf(c,"if %s<%s goto ",$1->name,$3->name);genCodes(c);$$->falseList[$$->fTop]=nextinstr;($$->fTop)++;genCodes("goto ");}
                |  expression T_LE expression            {$$=&ts[nts];nts++;$$->trueList[$$->tTop]=nextinstr;($$->tTop)++;char c[2000];sprintf(c,"if %s<=%s goto ",$1->name,$3->name);genCodes(c);$$->falseList[$$->fTop]=nextinstr;($$->fTop)++;genCodes("goto ");}
                |  expression T_EQUAL expression         {$$=&ts[nts];nts++;$$->trueList[$$->tTop]=nextinstr;($$->tTop)++;char c[2000];sprintf(c,"if %s==%s goto ",$1->name,$3->name);genCodes(c);$$->falseList[$$->fTop]=nextinstr;($$->fTop)++;genCodes("goto ");}
                |  expression T_UNEQUAL expression       {$$=&ts[nts];nts++;$$->trueList[$$->tTop]=nextinstr;($$->tTop)++;char c[2000];sprintf(c,"if %s!=%s goto ",$1->name,$3->name);genCodes(c);$$->falseList[$$->fTop]=nextinstr;($$->fTop)++;genCodes("goto ");}
                |  T_ID T_ASSIGNOP expression            {if (symlook($1)==-1){char e[500];sprintf(e,"Not declared Variable: %s!",$1);yyerror(e);}$$=&ts[nts];nts++;char c[600];sprintf(c,"%s=%s",$1,$3->name);genCodes(c);}
                |  T_LEFTPAREN expression T_RIGHTPAREN   {$$=&ts[nts];nts++;sprintf($$->name,"%s",$2->name);assign($$->falseList,&($$->fTop),$2->falseList,$2->fTop);assign($$->trueList,&($$->tTop),$2->trueList,$2->tTop);}
                |  T_SUB expression %prec UMINUS         {$$=&ts[nts];nts++;sprintf($$->name,"t%d",tmpVal);tmpVal++;char c[600];sprintf(c,"%s=-%s",$$->name,$2->name);genCodes(c);}
                |  T_NOT expression                      {$$=&ts[nts];nts++;assign($$->trueList,&($$->tTop),$2->falseList,$2->fTop);assign($$->falseList,&($$->fTop),$2->trueList,$2->tTop);}
                |  T_ID                                  {if (symlook($1)==-1){char e[500];sprintf(e,"Not declared Variable: %s!",$1);yyerror(e);}$$=&ts[nts];nts++;sprintf($$->name,"%s",$1);}
                |  func_call                             {$$=&ts[nts];nts++;char t[5];sprintf($$->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s = call %s, %d",$$->name,$1->name,params);genCodes(c);params=0;}
                |  T_DECIMAL                             {$$=&ts[nts];nts++;sprintf($$->name,"%s",$1->name);}
                |  T_NUM                                 {$$=&ts[nts];nts++;sprintf($$->name,"%s",$1->name);}
                |  T_TURE                                {$$=&ts[nts];nts++;$$->trueList[$$->tTop]=nextinstr;($$->tTop)++;genCodes("goto ");}
                |  T_FALSE                               {$$=&ts[nts];nts++;$$->falseList[$$->fTop]=nextinstr;($$->fTop)++;genCodes("goto ");}
                |  T_STRING                              {}
                ;

//回填记录的行号                
M               :                                        {$$=nextinstr;}
                ;

//语句:
statements      :  M expression T_SEMICOLON statements              {$$=&ts[nts];nts++;$$->nextList[$$->nTop]=$1;($$->nTop)++;}
                |  if_stmt M statements                             {$$=&ts[nts];nts++;assign($$->nextList,&($$->nTop),$3->nextList,$3->nTop);backPatch($1->nextList,$1->nTop-1,$2);backPatch($1->falseList,$1->fTop-1,$2);}
                |  while_loop M statements                          {$$=&ts[nts];nts++;assign($$->nextList,&($$->nTop),$3->nextList,$3->nTop);backPatch($1->nextList,$1->nTop,$2);}
                |  for_loop statements                              {$$=&ts[nts];nts++;assign($$->nextList,&($$->nTop),$2->nextList,$2->nTop);}
                |  declares statements                              {$$=&ts[nts];nts++;assign($$->nextList,&($$->nTop),$2->nextList,$2->nTop);}
                |  T_RETURN expression T_SEMICOLON statements       {$$=&ts[nts];nts++;assign($$->nextList,&($$->nTop),$4->nextList,$4->nTop);char c[300];sprintf(c,"return %s",$2->name);genCodes(c);}
                |  T_BREAK T_SEMICOLON statements                   {}
                |  T_CONTINUE T_SEMICOLON statements                {}
                |                                                   {$$=&ts[nts];nts++;$$->nextList[$$->nTop]=nextinstr;($$->nTop)++;}
                ;
//{语句}:
block           :  T_LEFTBRACE statements T_RIGHTBRACE  {$$=&ts[nts];nts++;assign($$->nextList,&($$->nTop),$2->nextList,$2->nTop);}
                ;
//函数的定义,type id (parameters) block 生成一个新的符号表来记录里边的符号:
func            :  T_TYPE T_ID {symInsert($2,"func",0);pushTable($2);char c[300];sprintf(c,"%s:",$2);genCodes(c);} T_LEFTPAREN parameters T_RIGHTPAREN block {popTable();}
                ;
//参数:type id
parameters      :  parameter T_TYPE T_ID  {symInsert($3,$2,0);}
                |  {}
                ;
//参数:type id,
parameter       :  parameter T_TYPE T_ID T_COMMA  {symInsert($3,$2,0);}
                |  {}
                ;
//函数调用:id(call_parameter)
func_call       :  T_ID {params=0;} T_LEFTPAREN call_parameters T_RIGHTPAREN  {$$=&ts[nts];nts++;if (symlook($1)==-1){yyerror("function is not declared");}sprintf($$->name,"%s",$1);}
                ;
//函数调用的参数
call_parameters :   expression call_parameter{params++;char c[300];sprintf(c,"param %s",$1->name);genCodes(c);}
                |    {}
                ;
//函数调用的参数,
call_parameter  :  T_COMMA expression  call_parameter{params++;char c[300];sprintf(c,"param %s",$2->name);genCodes(c);}
                |   {}
                ;

//while循环,while(E) {statements}
while_loop      :  T_WHILE M T_LEFTPAREN expression T_RIGHTPAREN M other{$$=&ts[nts];nts++;backPatch($4->trueList,$4->tTop,$6);assign($$->nextList,&($$->nTop),$4->falseList,$4->fTop);char c[500];sprintf(c,"goto %d",$2);genCodes(c);}
                ; 
//for循环
for_loop        :  T_FOR T_LEFTPAREN for_exp T_SEMICOLON for_exp T_SEMICOLON for_exp T_RIGHTPAREN other {}
                ;

for_exp         :  expression for_other{}
                |{}
                ;

for_other       :  for_other T_COMMA expression{}
                |{}
                ;
//if语句,单分支和双分支:
if_stmt         :  T_IF T_LEFTPAREN expression T_RIGHTPAREN M other N T_ELSE M other {$$=&ts[nts];nts++;backPatch($3->trueList,$3->tTop,$5);backPatch($3->falseList,$3->fTop,$9);struct translate tmp;merge(tmp.nextList,&(tmp.nTop),$6->nextList,$6->nTop,$7->nextList,$7->nTop);merge($$->nextList,&($$->nTop),tmp.nextList,tmp.nTop,$10->nextList,$10->nTop);}
                |  T_IF T_LEFTPAREN expression T_RIGHTPAREN M other {$$=&ts[nts];nts++;backPatch($3->trueList,$3->tTop,$5);merge($$->nextList,&($$->nTop),$3->falseList,$3->fTop,$6->nextList,$6->nTop);}
                ;
//other后边要跳转的next:
N               :  {$$=&ts[nts];nts++;$$->trueList[$$->tTop]=nextinstr;($$->tTop)++;genCodes("goto ");}  
                ;
//括号,语句:{statements}
other           :  block                       {$$=&ts[nts];nts++;assign($$->nextList,&($$->nTop),$1->nextList,$1->nTop);}
                |  T_BREAK T_SEMICOLON         {}
                |  T_CONTINUE T_SEMICOLON      {}
                ;
//变量;
declares        :  declare T_SEMICOLON          
                ;
//变量类型，标识符声明，记录到符号表中:
declare         :  declare T_COMMA T_ID  {symInsert($3,sTables[nowTable].sym[sTables[nowTable].top-1].type,0);}
                |  T_TYPE T_ID           {symInsert($2,$1,0);}
                ;

%%

void yyerror(const char* msg) {
        printf("At %d line,an error has been checked\n",numLines);
        printf("%s\n",msg);
        exit(1);
}
//根据name在当前符号表和之前的符号表中查找符号,返回下标,不存在返回-1
int symlook(char *name)
{
    int now = nowTable;
    while(now!=-1){
        for (int j=0;j<sTables[now].top;j++){
            if (!strcmp(sTables[now].sym[j].name, name))
            {
                return j;
            }
        }
        now = sTables[now].pre;
    }
    return -1;
}
//根据name在当前符号表中查找符号,返回下标,不存在返回-1
int symLookNow(char *name){
    for (int j=0;j<sTables[nowTable].top;j++)
        if (!strcmp(sTables[nowTable].sym[j].name, name))
        {
            return j;
        }
    return -1;
}
//符号表入栈
void pushTable(char *name){
    int tmp;
    if (nowTable==200){
        yyerror("symbol tables stack is full!\n");
    }else{
        maxTable++;
        tmp = nowTable;//上一个符号表
        nowTable = maxTable;
        sTables[nowTable].top = 0;//初始化top ,pre , name
        sTables[nowTable].pre = tmp;
        sprintf(sTables[nowTable].name,"%s",name);
    }
}
//符号表出栈
void popTable(){
    nowTable = sTables[nowTable].pre;
}
//在当前符号表中插入符号，返回插入的符号或存在的符号
struct symbol *symInsert(char *name,char *type,double value)
{
    if (sTables[nowTable].top==201){
        return NULL;
    }
    int p = symLookNow(name);
    if (p==-1){//当前符号表中不存在这个符号
        sprintf(sTables[nowTable].sym[sTables[nowTable].top].name,"%s",name);
        sprintf(sTables[nowTable].sym[sTables[nowTable].top].type,"%s",type);
        sTables[nowTable].sym[sTables[nowTable].top].value = value;
        sTables[nowTable].top++;
        return &(sTables[nowTable].sym[sTables[nowTable].top-1]);
    }else{
        return &(sTables[nowTable].sym[p]);
    }
    return NULL;
}
//更新符号表(name,type,value)
void symUpdate(char *name,char *type,double value)
{
    int p;
    p = symlook(name);
    if (p!=-1){//符号表中存在这个符号
        sprintf(sTables[nowTable].sym[p].name,"%s",name);
        sprintf(sTables[nowTable].sym[p].type,"%s",type);
        sTables[nowTable].sym[p].value = value;
        return;
    }
    yyerror("symbol not existed");
    return;
}
//生成中间代码，编号,三地址指令
void genCodes(char* code){
    IntermediateLanguage[ncodes].no = nextinstr;
    sprintf(IntermediateLanguage[ncodes].sentence,"%s",code);
    nextinstr++;
    ncodes++;
}
//回填,把链表的区域值填成m
void backPatch(int *b,int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<ncodes;j++){
            if (IntermediateLanguage[j].no == *(b+i)){
                sprintf(IntermediateLanguage[j].sentence,"%s%d",IntermediateLanguage[j].sentence,m);
                break;
            }
        }
    }
}
//合并,将链表b和链表c合并成新的链表a
void merge(int *a,int *na,int *b,int nb,int *c,int nc){
    int i=0;
    int j=0;
    while (i<nb){
        *(a+*na) = *(b+i);
        (*na)++;
        i++;
    }
     while (j<nc){
        *(a+*na) = *(c+j);
        (*na)++;
        j++;
    }
}
//赋值,将链表b的值copy到链表a
void assign(int *a,int *na,int *b,int nb){
    int i=0;
    while (i<nb){
        *(a+*na) = *(b+i);
        (*na)++;
        i++;
    }
}
//打印所有符号表中的所有符号的信息
void printSym(){
    for (int i=0;i<=maxTable;i++){
        printf("symbol table of %s:\n",sTables[i].name);
        printf("No. %d  pre: %d\n",i,sTables[i].pre);
        for (int j=0;j<sTables[i].top;j++)
            printf("%-15s%-15s%-15lf\n",sTables[i].sym[j].name,sTables[i].sym[j].type,sTables[i].sym[j].value);
        printf("*****************************************\n\n");
    }
}
//主函数,输入源文件进行分析
int main(int argc,char *argv[]) {
    //初始化翻译三地址代码表和符号表
    for(int i=0;i<1000;i++){
        ts[i].tTop=0;
        ts[i].fTop=0;
        ts[i].nTop=0;
    }
     for(int i=0;i<200;i++){
        sTables[i].top=0;
        sTables[i].pre=-1;
    }
    sTables[nowTable].top = 0;
    sprintf(sTables[nowTable].name,"%s","global");
    //提前插入Print函数
    symInsert("Print","func",0);
    //词法分析和语法分析，中间代码生成
    if (argc==2){
            yyin=fopen(argv[1],"r");
    }
    int result = yyparse();
    //打印符号表
    printSym();
    //打印中间代码
    printf("the intermediate language:\n");
    for (int i=0;i<ncodes;i++){
        printf("%d: %s\n",IntermediateLanguage[i].no,IntermediateLanguage[i].sentence);
    }
    return result;
}
