#define NSYMS 200 
#define NSTS 200
#define MAXSENTENCE 256

//符号的定义，name,type,value
struct symbol {
  char name[256];
  char type[256];
  double value;
};

//符号表：符号的容量,当前指针top,符号表名字name,上一个符号表
struct symbolTable{
  struct symbol sym[NSYMS];
  int top;
  char name[256];
  int pre;
}sTables[NSTS];
//真出口,假出口,下一个出口
struct translate{
  char name[256];
  int trueList[100];
  int falseList[100];
  int nextList[100];
  int tTop;
  int fTop;
  int nTop;
}ts[2000];
//生成代码的编号,句子
struct code{
  int no;
  char sentence[256];
};

struct code IntermediateLanguage[MAXSENTENCE];
//相关函数的定义
int symlook();
void symUpdate(char *name,char *type,double value);
struct symbol *symInsert(char *name,char *type,double value);
void pushTable(char *name);
void popTable();
void backPatch(int *b,int n,int m);
void merge(int *a,int *na,int *b,int nb,int *c,int nc);
void assign(int *a,int *na,int *b,int nb);
void genCodes(char* code);
int symLookNow(char *name);
void printSym();