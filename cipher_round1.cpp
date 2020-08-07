/*
Shivam Tripathi
*/

#include<bits/stdc++.h>
using namespace std;

//function to check whether a string is balanced or not
void isBalanced(string str)
{
	int n=str.size();	//size of input string
	stack<char> s;	//stack data structure using STL container

	//iterating over each character in the input string
	for(char c: str)
	{
		//we also handled the case of space characters in the input string
		if((c!=' ') && (c=='[' || c=='(' || c=='{'))
			s.push(c);
		else if((c==']') && (s.top()=='['))
			s.pop();
		else if((c==')') && (s.top()=='('))
			s.pop();
		else if((c=='}') && (s.top()=='{'))
			s.pop();
	}

	//if stack is empty after the above loop, it means that 
	//all bracket balanced out each other correspondingly
	if(s.empty())
		cout<<"YES\n";
	else
		cout<<"NO\n";

	return;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t;	//Number of test cases
    cin>>t;
    cin.ignore(); //To clear the input buffer before taking string class input
   	string str; 
    while(t--)
    {	
    	getline(cin,str);
    	isBalanced(str);	//function to check string is balanced or not
    }
    return 0;
}