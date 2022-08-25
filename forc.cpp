// forc.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

//根据传入的数据生成一个字符串，需要传入源字符串数组指针
void Generic(int iAssign,int iBit,int iSourceMax,char *cSources,char *cStrings)
{
    int iPow = 1;
    for(iBit;iBit>=0;iBit--)
    {
        //将源字符串中的字符分别赋给目标字符串
        *(cStrings+iBit) = *(cSources+(iAssign/iPow)%iSourceMax);
        iPow = iPow*iSourceMax;
    }
}

/*计算x的y次方*/
double pow(double x,double y)
{
    int i;
    double result=1;
    if(x <= 0)
    {
        return -1;
    }
    for(i=0;i<(int)y;i++)
    {
        result = result*x;
    }
    return result;
}
//清除一个字符串的内容
void Clean(char *cArray, int iBit)
{
    int i;
    for(i=0;i<iBit;i++)
    {
        *(cArray+i) = '\0';
    }
}
//探测字符串长度，并把最后的回车符号变成空字符
int Bits(char *cArray)
{
    int i=0;
    while(1)
    {
        if((*(cArray+i) == '\n')||(*(cArray+i) == '\0'))
        {
            *(cArray+i) = '\0';
            break;
        }
        i++;
    }
    return i;
}

bool dic(char* FILE_PATH,char* string,int len){

	char* cStrings;
	int iBitMax=len;//字典位数
	FILE* fp=fopen(FILE_PATH,"w");

	int iSourceMax=Bits(string);
	for(int iBitNow=1;iBitNow<=iBitMax;iBitNow++) //按生成位数进行递增
    {
        for(int iAssign=0;iAssign<(int)pow((double)iSourceMax,(double)iBitNow);iAssign++) //按第多少次生成进行递增
        {
            Generic(iAssign,iBitNow-1,iSourceMax,&string[0],&cStrings[0]);
			if(strlen(cStrings)==len){
				printf("已生成：%s（写入）",cStrings);
				fputs(cStrings,fp);
				fputc('\n',fp);
			}
			else{
				printf("已生成：%s（不写入）",cStrings);
			}
            Clean(cStrings,10);
        }
    }
	return true;
}
