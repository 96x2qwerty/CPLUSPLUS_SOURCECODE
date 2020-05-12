#include<iostream>
#include<windows.h>
#include<string.h>
#include<conio.h>
using namespace std;

void Try(const char *path) //Duyet file voi duong dan path
{
	//tao filter tim kiem
	char filter[MAX_PATH];
	strcpy(filter, path);
	strcat(filter, "\\*.*");//ghep vao chuoi filter

	//tro den file dau tien trong thu muc
	WIN32_FIND_DATA fdata;
	HANDLE hFind = FindFirstFile(filter, &fdata);
	do
	{
		if (strcmp(fdata.cFileName, ".") == 0) continue;
		if (strcmp(fdata.cFileName, "..") == 0) continue;//khong la thu muc goc, k la thu muc cha
		if (fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//neu la thu muc
		{
			//lenh lien quan den tm 1: hienthi,taomoi...
			cout << fdata.cFileName << endl;
			//tao duong dan den tm con
			char buffer(MAX_PATH);
			strcpy(buffer, path);
			strcat(buffer, "\\");
			strcat(buffer, fdata.cFileName);
			//duyet thu muc con
			Try(buffer);

			//lenh lien quan den thu muc 2: xoa
		}
		else
		{
			//lenh lien quan den file
		}
	} while (FindNextFile(hFind, &fdata) != 0);
}

int main()
{
	Try("D:\\game");
	system("pause");
	return 0;
}