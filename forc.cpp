// forc.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

//���ݴ������������һ���ַ�������Ҫ����Դ�ַ�������ָ��
void Generic(int iAssign,int iBit,int iSourceMax,char *cSources,char *cStrings)
{
    int iPow = 1;
    for(iBit;iBit>=0;iBit--)
    {
        //��Դ�ַ����е��ַ��ֱ𸳸�Ŀ���ַ���
        *(cStrings+iBit) = *(cSources+(iAssign/iPow)%iSourceMax);
        iPow = iPow*iSourceMax;
    }
}

/*����x��y�η�*/
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
//���һ���ַ���������
void Clean(char *cArray, int iBit)
{
    int i;
    for(i=0;i<iBit;i++)
    {
        *(cArray+i) = '\0';
    }
}
//̽���ַ������ȣ��������Ļس����ű�ɿ��ַ�
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
	int iBitMax=len;//�ֵ�λ��
	FILE* fp=fopen(FILE_PATH,"w");

	int iSourceMax=Bits(string);
	for(int iBitNow=1;iBitNow<=iBitMax;iBitNow++) //������λ�����е���
    {
        for(int iAssign=0;iAssign<(int)pow((double)iSourceMax,(double)iBitNow);iAssign++) //���ڶ��ٴ����ɽ��е���
        {
            Generic(iAssign,iBitNow-1,iSourceMax,&string[0],&cStrings[0]);
			if(strlen(cStrings)==len){
				printf("�����ɣ�%s��д�룩",cStrings);
				fputs(cStrings,fp);
				fputc('\n',fp);
			}
			else{
				printf("�����ɣ�%s����д�룩",cStrings);
			}
            Clean(cStrings,10);
        }
    }
	return true;
}
