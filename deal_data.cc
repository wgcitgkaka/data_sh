#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct result
{
	string prefix;
	string nexthop;
};

string convert(string line);
int my_atoi(string s);
string my_itos_ipv4(int num);

#define ERROR_LABLE "Error:"

int main()
{
	ofstream out;
	ifstream in;
	in.open("data_r00");
	out.open("result_r00");
	string line;
	int i = 0;
	struct result a;
	char b[1024];

	if(!in.is_open())
	{
		cout << "cannot open the file!!" << endl;
		return 1;
	}

	while(in >> line)
	{
		i ++;
//		cout << line << endl;

		if(i % 2 == 1)
		{
			a.prefix = convert(line);
		}

		if(i % 2 == 0)
		{
			i = 0;
			a.nexthop = line;
			sprintf(b,"%s %s",a.prefix.c_str(),a.nexthop.c_str());
			//cout << b << endl;
			out << b << endl;
		}
	}

	in.close();

	return 0;
}

string convert(string Prefix)
{
	vector<int> SplitPos;
    
	int i, strLen = Prefix.length();
	for (i = 0 ; i < strLen ; i ++)
	{
		if (Prefix[i] == '.' || Prefix[i] == '/')
		{
			SplitPos.push_back(i);
		}
	}
    if (SplitPos.size () != 4) {
        printf ("%s Can Not Trans %s\n",ERROR_LABLE, Prefix.c_str());
	    return string ("");
    }
	string res = "";
	int start = 0, PosNum = SplitPos.size();
	for (i = 0 ; i < PosNum ; i ++)
	{
		res += my_itos_ipv4( my_atoi(Prefix.substr(start, SplitPos[i] - start)) );
		start = SplitPos[i] + 1;
	}
	int len = my_atoi( Prefix.substr(start, strLen - start) );
	
	return res.substr(0,len);
}

int my_atoi(string s)
{
	int num = 0;
	int len = s.length();
	for (int i = 0 ; i < len ; i ++)
	{
		num = num * 10 + s[i] - '0';
	}
	return num;
}

string my_itos_ipv4(int num)
{
	char s[10];
	for (int i = 7 ; i >= 0 ; i --)
	{
		s[i] = (num % 2) + '0';
		num >>= 1;
	}
	s[8] = 0;		    
	string res = s;
	return res;
}





