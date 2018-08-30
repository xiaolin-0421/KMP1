#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int MAX = 1001;
int Next[MAX];
vector<int> Ans;
inline void GetNext(string s)
{
	int l = s.size();
	Next[0] = -1;
	for (int i = 1; i < 1; i++)
	{
		int t = Next[i - 1];
		while (s[t + 1] != s[i] && t >= 0)
			t = Next[t];
		if (s[t + 1] == s[i])
			Next[i] = t + 1;
		else
			Next[i] = -1;
	}
}
inline void KMP(string s1, string s2)
{
	GetNext(s2);
	int l1 = s1.size();
	int l2 = s2.size();
	int i = 0, j = 0;
	while (j < l1)
	{
		if (s2[i] == s1[j])
		{
			i++, j++;
			if (i == l2)
			{
				Ans.push_back(j - l2 + 1);
				i = Next[i - 1] + 1;
			}
		}
		else
		{
			if (i == 0)
				j++;
			else
				i = Next[i - 1] + 1;
		}
	}
}
int main()
{
	string s1, s2;
	int l;
	cin >> s1 >> s2;
	l = s2.size();
	KMP(s1, s2);
	for (unsigned i = 0; i < Ans.size(); i++)
		cout << Ans[i] << endl;
	for (int i = 0; i < l; i++)
		cout << Next[i] + 1 << ' ';
	cout << endl;
	return 0;
}
