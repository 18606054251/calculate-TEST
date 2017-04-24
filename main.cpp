#include<iostream>
#include<string>
#include<math.h>
#include<ctime>
#include <cstdlib>
#include<sstream>
#include"solve.h"
using namespace std;

int randomNumber(int start, int end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}

string randomOperation()
{
	int n;
	n=randomNumber(1,5);
	string aa;
	if (n==1)
	aa='+';
	if (n==2)
	aa='-';
	if (n==3)
	aa='*';
	if (n==4)
	aa='/';
	return aa;
}

string generateExpression()
{
	string theQuestion;
	int num[5];
	string a_1[5];
	int i,t,k;
	
	for (i=1;i<=4;i++)
	{
		num[i]=randomNumber(1,11);
	}
	
	for (i=1;i<4;i++)
	{
		a_1[i]=randomOperation();
		
		
		
	}
	for(i=1;i<=3;i++)
	{
		if(a_1[i]=="-")
		{
			for (;num[i]<=num[i+1];)
			{
		    	num[i+1]=randomNumber(0,10);/*这里故意弄成生成0-9的随机数和条件弄成  (number[t]<number[t+1])  是防止发生1-1；10-10；等等的情况 */ 
				if (num[i]==0)
				{
					num[i]=randomNumber(1,11);/*这个if的作用是当number[t]=0时，number[t+1]最小也只是0，会陷入死循环，所以，防止number[t]=0.*/
				}
			}
		}
    }
    
    for (i=1;i<=3;i++)
    {
    	if(a_1[i]=="/")
		{	
       		double theMiddle,a,b;//这个theMiddle是用来判断除法会不会出现小数啊，之类的。
		    int theMiddle_1;
			a=(double)(num[i]);
	    	b=(double)(num[i+1]);
	    	theMiddle=a/b;
	    	theMiddle_1=(int)(theMiddle);	
			for(;theMiddle!=theMiddle_1;)
			{
				num[i+1]=randomNumber(1,11);
		   		b=(double)(num[i+1]);
		    	theMiddle=a/b;
		   		theMiddle_1=(int)(theMiddle);
			}
		}
	}
	
	a_1[4]='=';
	
	string theNumber[5];
		for(int m=1;m<=4;m++)
		{
			for (int n=0;n<=10;n++)
			{
				if (num[m]==n)
				{
	    			ostringstream oss;
			        oss << n;
		    		theNumber[m]=oss.str();
		    	}
			}
		}//将得到的int类型转化为string型。 
	
	int brackets;//brackets是括号的意思，我们一样通过随机数来确定括号。 
	brackets=randomNumber(1,20);/*如果brackets==1代表前两个数字括号；以此类推得到其他情况的括号。为了让括号出现的概率降低把随机数的范围扩大了。*/
	if (brackets==1) 
	theQuestion="("+theNumber[1]+a_1[1]+theNumber[2]+")"+a_1[2]+theNumber[3]+a_1[3]+theNumber[4]+a_1[4];
	else if (brackets==2) 
	theQuestion=theNumber[1]+a_1[1]+"("+theNumber[2]+a_1[2]+theNumber[3]+")"+a_1[3]+theNumber[4]+a_1[4];
	else if (brackets==3) 
	theQuestion=theNumber[1]+a_1[1]+theNumber[2]+a_1[2]+"("+theNumber[3]+a_1[3]+theNumber[4]+")"+a_1[4];
	else if (brackets==4) 
	theQuestion="("+theNumber[1]+a_1[1]+theNumber[2]+a_1[2]+theNumber[3]+")"+a_1[3]+theNumber[4]+a_1[4];
	else if (brackets==5) 
	theQuestion=theNumber[1]+a_1[1]+"("+theNumber[2]+a_1[2]+theNumber[3]+a_1[3]+theNumber[4]+")"+a_1[4];
	else 
	theQuestion=theNumber[1]+a_1[1]+theNumber[2]+a_1[2]+theNumber[3]+a_1[3]+theNumber[4]+a_1[4];
	
	return theQuestion;
	
}

int scan()
{
	cout<<"中文版请输入0"<<endl;
	cout<<"English Edition Please Inter 1"<<endl;
	int theLanguage;
	cin >> theLanguage;
	if (theLanguage==0)
	{
		cout<<"欢迎您使用此\'软件\'，这是一款能随机生成0-10的四则运算的\'软件\'。请输入一个数字，我们将为您生成多少题目。每生成一个题目您需要输入一个答案，我们将为您判断对错。温馨提示：输入的答案需要是整数或者分数。如果想提前结束训练请输入exit。"<<endl;
	}
	if (theLanguage==1)
	{
		cout<<"Welcome to use this \'software\'，This is a randomly generated 0-10 arithmetic of the \'software\'. Please enter a number, how many questions we will be generated for you.Each generated a topic you need to enter an answer, we will be wrong for you. Warm prompt: the answer to the input needs to be an integer or scores.If you want to be the end of the training in advance, please enter exit"<<endl;
	}
	
	 
	
}

int main()
{
	string theQuestion;
	int true_Total=0,wrong_Total=0;
	int i,t,k;
	srand(unsigned(time(0)));
	scan();
	int howMany;//howMany 是用户输入的，它代表‘软件’生成多少题目。
	cin >> howMany;
	for(i=1;i<=howMany;i++)
	{
		theQuestion=generateExpression();
		cout<<theQuestion;
		solve a;
		string yourAnswer,trueAnswer;
		cin>>yourAnswer;
        trueAnswer=a.getAnswer(theQuestion);
		if (yourAnswer=="exit")
		{
			break;
		}
	    if (yourAnswer==trueAnswer)
	    {
	    	cout<<endl; 
	    	true_Total++;
		}
		if (yourAnswer!=trueAnswer)
		{
			cout<<endl; 
			wrong_Total++;
		}
	}
	cout<<"正确的题数："<<true_Total<<endl;
	cout<<"错误的题数："<<wrong_Total<<endl; 
	cout<<"谢谢您的使用。"<<endl; 
}
