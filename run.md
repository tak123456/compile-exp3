# flex进行词法分析，bison语法分析,生成三地址代码(中间代码)
# 编译
flex lexer.l
bison -d  parse.y
gcc parse.tab.c lex.yy.c -o a.out
# 运行
./a.out input.txt