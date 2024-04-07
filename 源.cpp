#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string st = "0123456789";
ofstream fout;
void dfs(string str[], int x, int y);
void print(string str[]);
bool check(string str[], int x, int y, char k);
int main()
{
	ifstream fin;
	string filename;
	cin >> filename;
	fin.open(filename);
	if (fin.is_open() == false)
	{
		cout << "file open failure." << endl;
		return 0;
	}
	string buffer;
	string str[9];
	int k = 0;
	while (getline(fin, buffer) && buffer != "")
	{
		str[k++] = buffer;
	}
	fin.close();
	fout.open(filename, ios::app);
	if (fout.is_open() == false)
	{
		cout << "file open failure." << endl;
		return 0;
	}
	fout << "solution:" << endl;
	dfs(str, 0, 0);
	fout.close();
	return 0;
}
void dfs(string str[], int x, int y)
{
	if (x == 9)
	{
		print(str);
		exit(0);
		return;
	}
	if (str[x][y] == '0')
	{
		for (int k = 1; k < 10; k++)
		{
			if (check(str, x, y, st[k]))
			{
				str[x][y] = st[k];
				dfs(str, x + (y + 1) / 9, (y + 1) % 9);
			}
		}
		str[x][y] = '0';
	}
	else
	{
		dfs(str, x + (y + 1) / 9, (y + 1) % 9);
	}
}
void print(string str[])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fout << str[i][j] << " ";
		}
		fout << endl;
	}
}
bool check(string str[], int x, int y, char k)
{
	for (int l = 0; l < 9; l++)
	{
		if (str[x][l] == k || str[l][y]==k)
			return false;
	}
	for (int l = (x / 3) * 3; l < (x / 3 + 1) * 3; l++)
	{
		for (int m = (y / 3) * 3; m < (y / 3 + 1) * 3; m++)
		{
			if (str[l][m] == k)
				return false;
		}
	}
	return true;
}