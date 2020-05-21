#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
	


	if( argc == 3 ){
    		
     
    
        FILE *fp = fopen(argv[2],"r");
        
        if(!fp){
			printf("错误：文件读取失败\n");
            return -1;
        }        
        
        //对参数进行判断
		
        
        if( !strcmp(argv[1],"-c") ){//字符数
			char temp;
            int num = 0;
            temp = fgetc(fp);
			while( temp != EOF ){
				//putchar(temp);
                temp = fgetc(fp);
                num++;
			}
            printf("字符数：%d\n",num);
            
        }
        else if( !strcmp(argv[1],"-w") ){//单词数
			int w = 0;
            char a = fgetc(fp);
            while( a != EOF){
                if( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') ){
                    while( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') )
                        a =fgetc(fp);
                    w++;
                    a =fgetc(fp);
                    
                }
                else
                    a =fgetc(fp);
            }
            printf("单词数：%d\n",w);
            
        }
       
        else{
			printf("错误：参数超出范围！必须是-w 或者 -c\n");
            printf("允许参数：-c，-w，-l\n");
        }
        int n=fclose(fp);
    }
    else{
		printf("错误：运行参数必须要3个!\n");
		printf("用法：wc.exe [parameter] [file_name]\n 见实验报告");
    }
	system("pause");
	return 0;
}

