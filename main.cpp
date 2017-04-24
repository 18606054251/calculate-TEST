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
		    	num[i+1]=randomNumber(0,10);/*�������Ū������0-9�������������Ū��  (number[t]<number[t+1])  �Ƿ�ֹ����1-1��10-10���ȵȵ���� */ 
				if (num[i]==0)
				{
					num[i]=randomNumber(1,11);/*���if�������ǵ�number[t]=0ʱ��number[t+1]��СҲֻ��0����������ѭ�������ԣ���ֹnumber[t]=0.*/
				}
			}
		}
    }
    
    for (i=1;i<=3;i++)
    {
    	if(a_1[i]=="/")
		{	
       		double theMiddle,a,b;//���theMiddle�������жϳ����᲻�����С������֮��ġ�
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
		}//���õ���int����ת��Ϊstring�͡� 
	
	int brackets;//brackets�����ŵ���˼������һ��ͨ���������ȷ�����š� 
	brackets=randomNumber(1,20);/*���brackets==1����ǰ�����������ţ��Դ����Ƶõ�������������š�Ϊ�������ų��ֵĸ��ʽ��Ͱ�������ķ�Χ�����ˡ�*/
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
	cout<<"���İ�������0"<<endl;
	cout<<"English Edition Please Inter 1"<<endl;
	int theLanguage;
	cin >> theLanguage;
	if (theLanguage==0)
	{
		cout<<"��ӭ��ʹ�ô�\'���\'������һ�����������0-10�����������\'���\'��������һ�����֣����ǽ�Ϊ�����ɶ�����Ŀ��ÿ����һ����Ŀ����Ҫ����һ���𰸣����ǽ�Ϊ���ж϶Դ���ܰ��ʾ������Ĵ���Ҫ���������߷������������ǰ����ѵ��������exit��"<<endl;
	}
	if (theLanguage==1)
	{
		cout<<"Welcome to use this \'software\'��This is a randomly generated 0-10 arithmetic of the \'software\'. Please enter a number, how many questions we will be generated for you.Each generated a topic you need to enter an answer, we will be wrong for you. Warm prompt: the answer to the input needs to be an integer or scores.If you want to be the end of the training in advance, please enter exit"<<endl;
	}
	
	 
	
}

int main()
{
	string theQuestion;
	int true_Total=0,wrong_Total=0;
	int i,t,k;
	srand(unsigned(time(0)));
	scan();
	int howMany;//howMany ���û�����ģ���������������ɶ�����Ŀ��
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
	cout<<"��ȷ��������"<<true_Total<<endl;
	cout<<"�����������"<<wrong_Total<<endl; 
	cout<<"лл����ʹ�á�"<<endl; 
}
