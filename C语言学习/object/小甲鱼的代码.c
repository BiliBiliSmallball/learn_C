//小甲鱼统计代码量的程序

#include <io.h>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAX			256

long total;

int countlines(const char *filename);
void findAllCodes(const char *path);
void findAllFilem(const char *path);

int countlines(const char *filename)
{
	FILE *fp;
	int count = 0;
	int temp;
	
	if ((fp= fopen(filename,"r")) == NULL)
	{
		fprintf(stderr,"无法打开文件:%s\n",filename);
		return 0;
	}
	
	while((temp = fgetc(fp)) != EOF)
	{
		if (temp == '\n')
		{
			count++;
		}
	}
	
	fclose(fp);
	
	return count;
}

void findAllCodes(const char *path)
{
	struct _finddata_t fa;
	long handle;
	char thePath[MAX],targer[MAX];
	
	strcpy(thePath,path);
	if((handle = _findfirst(strcat(thePath,"/*.c"),&fa)) != -1L)
	{
		do
		{
			sprintf(targer, "%s/%s", path,fa.name);
			total += countLines(targer);		
		}while (_findnext(handle,&fa) == 0);
	}
	
	_findclose(handle);
}

void findAllDirs(const char *path)
{
	 struct _finddata_t fa;
        long handle;
        char thePath[MAX];
        
        strcpy(thePath, path);
        if((handle = _findfirst(strcat(thePath, "/*"), &fa)) == -1L)
        {
                fprintf(stderr, "The path %s is wrong!\n",path);
                return;
        }
   
        do
        {        
                if (!strcmp(fa.name, ".") || !strcmp(fa.name, ".."))
                        continue;
                    
                if( fa.attrib == _A_SUBDIR)
                {        
                        sprintf(thePath, "%s/%s", path, fa.name);
                        findAllCodes(thePath);
                        findALLDirs(thePath);
                }
        }while (_findnext(handle, &fa) == 0);
   
        _findclose(handle);   
}

int main()
{
    char path[MAX] = ".";
        
    printf("计算中...\n");
        
    findAllCodes(path);
    findAllDirs(path);
        
    printf("目前你总共写了 %ld 行代码！\n\n", total);
    system("pause");
        
    return 0;		
} 
