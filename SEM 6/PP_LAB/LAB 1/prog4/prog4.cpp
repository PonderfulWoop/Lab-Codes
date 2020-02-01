#include <bits/stdc++.h>
using namespace std;

// driver code
int main()
{
	fstream file;
	string word, t, q, filename;

	// filename of the file
	filename = "cranfield0001.txt";
	string s1("<TEXT>");
	string s2("</TEXT>");
	// opening file
	file.open(filename.c_str());
	int flag = 0;
	while (file >> word)
	{
		// displaying content
		if(s1.compare(word) == 0){
			flag = 1;
			continue;
		}
		if(s2.compare(word) == 0)
			flag = 0;
		if(flag == 1)
			cout<<word<<" ";
	}

	return 0;
}
