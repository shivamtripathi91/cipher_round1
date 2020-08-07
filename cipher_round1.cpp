/*
SHIVAM TRIPATHI

The subject you're submitting assignment for: Data Structure

Q: A bracket is considered to be following of the characters ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{], ‘}’.
Two brackets are considered to be a matched pair if the an opening bracket
( i.e., (, [, or { ) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same
type. There are three types of matched pairs of brackets: [ ], { }, and ( ).
A matching pair of brackets is not balanced if the set of brackets it encloses are not
matched.
For example, { [ ( ] ) } is not balanced because the contents in
between { and } are not balanced. The pair of square brackets encloses a single,
unbalanced opening bracket, (, and the pair of parentheses encloses a single,
unbalanced closing square bracket, ].
By this logic, we say a sequence of brackets is balanced if the following conditions
are met:
1. It contains no unmatched brackets.
2. The subset of brackets enclosed within the confines of a matched pair of brackets
is also a matched pair of brackets.
Given n string of rackets, determine whether each sequence of brackets is
balanced. If string is balanced, return YES, otherwise return NO.
EXAMPLE:
Input:
2
[ ( { } ) ]
{ ( ] }
Output:
YES
NO
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
//un-comment the following for input-output in text files(offline mode)
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
