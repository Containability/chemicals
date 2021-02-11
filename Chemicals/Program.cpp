# include<iostream>
# include<string>
# include<sstream>
# include<list>
# include<algorithm>
# include<vector>
using namespace std;
//1306170024 MERT AKYAZI 
class Node
{
	public:
	Node() { }
	Node(vector<Node> a)
	{
		this->NodeList = a;
	}
	int connection;
	vector<Node> NodeList;
	list<string> connection_list;
	Node operator +(vector<Node> a)
	{

		for (int i = 0; i < a.size(); i++)
			this->NodeList.push_back(a[i]);
		return *this;
	}

};

class H :public Node
{
public:
	static int connection;

int FindNumbers(string input)
{
	size_t found;
	found = input.find('H');
	if (found != string::npos)
	{
		return input[found - 1] - '0';
	}
	else
		return 0;
}




};
int H::connection = 1;
class O : public Node
{
public:
	static int connection;

int FindNumbers(string input)
{
	size_t found;
	found = input.find('O');
	if (found != string::npos)
	{
		return input[found - 1] - '0';
	}
	else
		return 0;
}
};
int O::connection = 2;
class K : public Node
{
public:
	static int connection;

int FindNumbers(string input)
{
	size_t found;
	found = input.find('K');
	if (found != string::npos)
	{
		return input[found - 1] - '0';
	}
	else
		return 0;
}
};
int K::connection = 3;
class C : public Node
{
public:
	static int connection;

int FindNumbers(string input)
{
	size_t found;
	found = input.find('C');
	if (found != string::npos)
	{
		return input[found - 1] - '0';
	}
	else
		return 0;
}
};
int C::connection = 4;
int main()
{
	string input = "";
	getline(cin, input);
	H h;
	h.connection = 1;
	O o;
	o.connection = 2;
	K k;
	k.connection = 3;
	C c;
	c.connection = 4;
	int number_of_h = h.FindNumbers(input);
	int number_of_o = o.FindNumbers(input);
	int number_of_k = k.FindNumbers(input);
	int number_of_c = c.FindNumbers(input);

	//this area resizing for the assertion problem solving

	h.NodeList.resize(number_of_h);
	for (int i = 0; i < number_of_h; i++)
	{
		h.NodeList[i].connection_list.resize(h.connection);

	}
	o.NodeList.resize(number_of_o);
	for (int i = 0; i < number_of_o; i++)
	{
		o.NodeList[i].connection_list.resize(o.connection);

	}
	k.NodeList.resize(number_of_k);
	for (int i = 0; i < number_of_k; i++)
	{
		k.NodeList[i].connection_list.resize(k.connection);

	}
	c.NodeList.resize(number_of_c);
	for (int i = 0; i < number_of_c; i++)
	{
		c.NodeList[i].connection_list.resize(c.connection);

	}
	//////////////////////////////////////////////////////////

	//this area for C looking for connection if it is possible with a node any other than C and connects
	int forh = 0;

	for (int a = 0; a < number_of_c; a++)
	{
		list<string>::iterator control1 = c.NodeList[a].connection_list.begin();
		int om = 0;
		while (*control1 != "")
		{
			control1++;
			om++;
			if (om == 4)
				break;
		}
		for (; forh < number_of_h && om < 4;)
		{
			for (int ab = 0; ab < 4 - om && ab < h.connection; ab++)
			{
				h.NodeList[forh].connection_list.push_front((string)"C" + (char)((a + 1) + '0'));
				*control1 = (string)"H" + (char)((forh + 1) + '0');
				control1++;
			}
			forh++;

		}
	}
	int fork = 0;
	for (int a = 0; a < number_of_c; a++)
	{
		list<string>::iterator control1 = c.NodeList[a].connection_list.begin();
		int om = 0;
		while (*control1 != "")
		{
			control1++;
			om++;
			if (om == 4)
				break;
		}

		for (; fork < number_of_k && om < 4;)
		{
			for (int ab = 0; ab < 4 - om && ab < k.connection; ab++)
			{
				k.NodeList[fork].connection_list.push_front((string)"C" + (char)((a + 1) + '0'));
				*control1 = (string)"K" + (char)((fork + 1) + '0');
				control1++;
			}
			fork++;

		}
	}
	int foro = 0;

	for (int a = 0; a < number_of_c; a++)
	{
		list<string>::iterator control1 = c.NodeList[a].connection_list.begin();
		int om = 0;
		while (*control1 != "")
		{
			control1++;
			om++;
			if (om == 4)
				break;
		}
		for (; foro < number_of_o && om < 4;)
		{
			for (int ab = 0; ab < 4 - om && ab < o.connection; ab++)
			{
				o.NodeList[foro].connection_list.push_front((string)"C" + (char)((a + 1) + '0'));
				*control1 = (string)"O" + (char)((foro + 1) + '0');
				control1++;
			}
			foro++;

		}
	}






//Area B and flags checking for connection to K if if any connection list have empty slot other from k node list and connects.

B:
	int kk2 = 0;
	int kk = 0;
	for (int a = 0; a < number_of_h; a++)
	{
		int counter3 = 0;
		list<string>::iterator control2 = h.NodeList[a].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter3++;
			if (counter3 == 1)
				break;
		}
		if (counter3 < 1)
		{
			kk = a;
			goto flag;

		}
	}

	for (int aa = 0; aa < number_of_o; aa++)
	{
		int counter2 = 0;
		list<string>::iterator control2 = o.NodeList[aa].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter2++;
			if (counter2 == 2)
				break;
		}

		if (counter2 < 2)
		{
			kk2 = aa;
			goto flag2;
		}

	}
	goto Out;
flag:
	for (int b = 0; b < number_of_k; b++)
	{
		int counter = 0;
		list<string>::iterator control2 = k.NodeList[b].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter++;
			if (counter == 3)
			{
				break;
			}
		}

		if (counter < k.connection)
		{
			*control2 = (string)"H" + (char)((kk + 1) + '0');
			h.NodeList[kk].connection_list.push_front((string)"K" + (char)((b + 1) + '0'));
			goto B;
		}
	}
flag2:
	for (int b = 0; b < number_of_k; b++)
	{
		int counter = 0;
		list<string>::iterator control2 = k.NodeList[b].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter++;
			if (counter == 3)
				break;
		}

		if (counter < k.connection)
		{
			*control2 = (string)"O" + (char)((kk2 + 1) + '0');
			o.NodeList[kk2].connection_list.push_front((string)"K" + (char)((b + 1) + '0'));
			goto B;
		}
	}


Out:
	//This area connects same nodes


	for (int b = 0; b < number_of_c; b++)
	{
		int counter = 0;

		list<string>::iterator control2 = c.NodeList[b].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter++;
			if (counter == 4)
				break;
		}
		for (int ae = 0; ae < number_of_c; ae++)
		{
			int counter2 = 0;
			if (ae == b)
			{
				continue;
			}
			list<string>::iterator control3 = c.NodeList[ae].connection_list.begin();

			while (*control3 != "")
			{
				control3++;
				counter2++;
				if (counter2 == 4)
					break;

			}
			if (counter < c.connection && counter2 < c.connection)
			{

				*control2 = (string)"C" + (char)((ae + 1) + '0');
				*control3 = (string)"C" + (char)((b + 1) + '0');

			}


		}
	}


	for (int b = 0; b < number_of_k; b++)
	{
		int counter = 0;

		list<string>::iterator control2 = k.NodeList[b].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter++;
			if (counter == 3)
				break;
		}
		for (int ae = 0; ae < number_of_k; ae++)
		{
			int counter2 = 0;
			if (ae == b)
			{
				continue;
			}
			list<string>::iterator control3 = k.NodeList[ae].connection_list.begin();

			while (*control3 != "")
			{
				control3++;
				counter2++;
				if (counter2 == 3)
					break;

			}

			if (counter < k.connection && counter2 < k.connection)
			{
				*control2 = (string)"K" + (char)((ae + 1) + '0');
				*control3 = (string)"K" + (char)((b + 1) + '0');
			}



		}
	}


	for (int b = 0; b < number_of_o; b++)
	{
		int counter = 0;

		list<string>::iterator control2 = o.NodeList[b].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter++;
			if (counter == 2)
				break;
		}
		for (int ae = 0; ae < number_of_o; ae++)
		{
			int counter2 = 0;
			if (ae == b)
			{
				continue;
			}
			list<string>::iterator control3 = o.NodeList[ae].connection_list.begin();

			while (*control3 != "")
			{
				control3++;
				counter2++;
				if (counter2 == 2)
					break;
			}

			if (counter < o.connection && counter2 < o.connection)
			{
				*control2 = (string)"O" + (char)((ae + 1) + '0');
				*control3 = (string)"O" + (char)((b + 1) + '0');
			}



		}
	}

	///////////////////////////////////////////////////////////////////////////////////

	//this area controls if any unstable node exist if exist than goto A.
	for (int b = 0; b < number_of_h; b++)
	{
		int counter = 0;
		list<string>::iterator control2 = h.NodeList[b].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter++;

			if (counter == 1)
				break;
		}

		if (counter < h.connection)
		{
			cout << "Unstable";
			goto A;
		}
	}
	for (int b = 0; b < number_of_o; b++)
	{
		int counter = 0;
		list<string>::iterator control2 = o.NodeList[b].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter++;

		}

		if (counter < o.connection)
		{
			cout << "Unstable";
			goto A;
		}
	}
	for (int b = 0; b < number_of_k; b++)
	{
		int counter = 0;
		list<string>::iterator control2 = k.NodeList[b].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter++;
			if (counter == 3)
				break;
		}

		if (counter < k.connection)
		{
			cout << "Unstable";
			goto A;
		}
	}
	for (int b = 0; b < number_of_c; b++)
	{
		int counter = 0;
		list<string>::iterator control2 = c.NodeList[b].connection_list.begin();
		while (*control2 != "")
		{
			control2++;
			counter++;
			if (counter == 4)
				break;
		}

		if (counter < c.connection)
		{
			cout << "Unstable";
			goto A;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////
	//this area prints:::
	for (int a = 0; a < number_of_c; a++)
	{
		list<string>::iterator it = c.NodeList[a].connection_list.begin();
		cout << (string)"C" + (char)((a + 1) + '0') << "-> ";
		for (int i = 0; i < c.connection; i++)
		{

			cout << *it << "  ";
			it++;
		}
		cout << endl;
	}
	for (int a = 0; a < number_of_k; a++)
	{
		list<string>::iterator it2 = k.NodeList[a].connection_list.begin();
		cout << (string)"K" + (char)((a + 1) + '0') << "-> ";
		for (int i = 0; i < k.connection; i++)
		{
			cout << *it2 << "  ";
			it2++;
		}
		cout << endl;
	}
	for (int a = 0; a < number_of_o; a++)
	{
		list<string>::iterator it3 = o.NodeList[a].connection_list.begin();
		cout << (string)"O" + (char)((a + 1) + '0') << "-> ";
		for (int i = 0; i < o.connection; i++)
		{
			cout << *it3 << "  ";
			it3++;
		}
		cout << endl;
	}
	for (int a = 0; a < number_of_h; a++)
	{
		list<string>::iterator it4 = h.NodeList[a].connection_list.begin();
		cout << (string)"H" + (char)((a + 1) + '0') << "-> ";
		for (int i = 0; i < h.connection; i++)
		{
			cout << *it4 << "  ";
			it4++;
		}
		cout << endl;
	}
/////////////////////////////////////////////////////////////////
A:

	return 0;
}




