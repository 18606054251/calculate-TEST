#include<iostream>
#include<string>
#include<math.h>
#include<ctime>
#include <cstdlib>
#include<sstream>
#include<string.h>
#include"solve.h"
using namespace std;
int true_Total=0,wrong_Total=0;
int random(int start, int end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}

char symbol (int n)
{
	char aa;
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

int main()
{
	FILE *f;
	char str[10][1000];
	f=fopen("language","r");
	while(fgets(str[0],1000,f)!=NULL){
		printf("%s",str[0]); 
	}
	char lan[100];
	scanf("%s",lan);
	fclose(f);
	f=fopen(lan,"r");
	while(f==NULL){
		printf("Ŀǰ��֧�ִ����ԣ�����������:");
		scanf("%s",lan);
		f=fopen(lan,"r");
	}
	
	fgets(str[1],1000,f);
	fgets(str[2],1000,f);
	fgets(str[3],1000,f);
	fgets(str[4],1000,f);
	fgets(str[5],1000,f);
	fgets(str[6],1000,f);
	fgets(str[7],1000,f);
	fgets(str[8],1000,f);
	fgets(str[9],1000,f);
	int n=strlen(str[2]);
	str[2][n-1]='\0';
	
	
	int theLanguage=0;
	
	if (theLanguage==0)
	{
		
		cout<<str[1]<<endl;
	}
	if (theLanguage==1)
	{
		cout<<"Welcome to use this \'software\'��This is a randomly generated 0-10 arithmetic of the \'software\'. Please enter a number, how many questions we will be generated for you.Each generated a topic you need to enter an answer, we will be wrong for you. Warm prompt: the answer to the input needs to be an integer or scores.If you want to be the end of the training in advance, please enter exit"<<endl;
	}
	int howMany;//howMany ���û�����ģ���������������ɶ�����Ŀ��
	
	cin >> howMany; 
	
	int number[5];
	srand(unsigned(time(0)));
	for(int i=1;i<=howMany;i++)
	{
		if(theLanguage==0)
		{
			
			cout <<str[2]<<i<<endl;; 
		}
		if(theLanguage==1)
		{
			cout <<"for the "<<i<<":   ";
		} 

		for (int t=1;t<=4;t++)
		{
		    number[t]=random(1,11);
    	}//��������� 
    	
    	char a_1[5];
    	int mark[4];
    	for (int t=1;t<=3;t++)
    	{
    		mark[t]=random(1,5);
    		a_1[t]=symbol(mark[t]);
    		a_1[4]='=';
		}//���ﶨ���a_1[5]�����������ȷ�����ŵģ�1--��+����2--��-����3--��*����4--��/���� 
		
		for(int t=1;t<=3;t++)
		{
			if(mark[t]==2)
			{
				for (;number[t]<=number[t+1];)
				{
					number[t+1]=random(0,10);/*�������Ū������0-9�������������Ū��  (number[t]<number[t+1])  �Ƿ�ֹ����1-1��10-10���ȵȵ���� */ 
					if (number[t]==0)
					{
						number[t]=random(1,11);/*���if�������ǵ�number[t]=0ʱ��number[t+1]��СҲֻ��0����������ѭ�������ԣ���ֹnumber[t]=0.*/
					}
				}
			}
		}//�����������ȷ�����ּ��ź�ǰһ�����ִ��ڵ��ں�������֣���ֹ���ֲ������� 
		
		for(int t=1;t<=3;t++)
		{
			if(mark[t]==4)
			{	
        		double theMiddle,a,b;//���theMiddle�������жϳ����᲻�����С������֮��ġ�
			    int theMiddle_1;
				a=(double)(number[t]);
	    		b=(double)(number[t+1]);
		    	theMiddle=a/b;
	    		theMiddle_1=(int)(theMiddle);	
				for(;theMiddle!=theMiddle_1;)
				{
					number[t+1]=random(1,11);
		    		b=(double)(number[t+1]);
			    	theMiddle=a/b;
		    		theMiddle_1=(int)(theMiddle);
				}
			}
		}//��ֹ����7/3�����޷���������ݡ� 
			
		string theNumber[5];
		for(int m=1;m<=4;m++)
		{
			for (int n=0;n<=10;n++)
			{
				if (number[m]==n)
				{
	    			ostringstream oss;
			        oss << n;
		    		theNumber[m]=oss.str();
		    	}
			}
		}//���õ���int����ת��Ϊstring�͡� 
		
		int brackets;//brackets�����ŵ���˼������һ��ͨ���������ȷ�����š� 
		brackets=random(1,20);/*���brackets==1����ǰ�����������ţ��Դ����Ƶõ�������������š�Ϊ�������ų��ֵĸ��ʽ��Ͱ�������ķ�Χ�����ˡ�*/
		string theQuestion;
		if (brackets==1) 
		theQuestion="("+theNumber[1]+a_1[1]+theNumber[2]+")"+a_1[2]+theNumber[3]+a_1[3]+theNumber[4];
		else if (brackets==2)  
		theQuestion=theNumber[1]+a_1[1]+"("+theNumber[2]+a_1[2]+theNumber[3]+")"+a_1[3]+theNumber[4];
		else if (brackets==3) 
		theQuestion=theNumber[1]+a_1[1]+theNumber[2]+a_1[2]+"("+theNumber[3]+a_1[3]+theNumber[4]+")";
		else if (brackets==4) 
		theQuestion="("+theNumber[1]+a_1[1]+theNumber[2]+a_1[2]+theNumber[3]+")"+a_1[3]+theNumber[4];
		else if (brackets==5) 
		theQuestion=theNumber[1]+a_1[1]+"("+theNumber[2]+a_1[2]+theNumber[3]+a_1[3]+theNumber[4]+")";
		else 
		theQuestion=theNumber[1]+a_1[1]+theNumber[2]+a_1[2]+theNumber[3]+a_1[3]+theNumber[4];
		
		cout <<theQuestion<<endl;
		
		solve a;
		string yourAnswer,trueAnswer;
		if (theLanguage==1)
        {
        	cout <<"please input your answer: ";
        	cin>>yourAnswer;
        	trueAnswer=a.getAnswer(theQuestion);
		    cout<<"the true answer is: "<<trueAnswer<<endl;
		    if (yourAnswer=="exit")
			{
				break;
			}
		    if (yourAnswer==trueAnswer)
		    {
		    	cout<<"Great, you are true!"<<endl;
		    	cout<<endl; 
		    	true_Total++;
			}
			if (yourAnswer!=trueAnswer)
			{
				cout<<"SORRY, you are wrong..."<<endl;
				cout<<endl; 
				wrong_Total++;
			}
		}
		if (theLanguage==0)
        {
        	cout <<str[4];
        	cin>>yourAnswer;
        	cout<<endl;
        	trueAnswer=a.getAnswer(theQuestion);
		    cout<<str[5]<<trueAnswer<<endl;
		    if (yourAnswer=="exit")
			{
				break;
			}
		    if (yourAnswer==trueAnswer)
		    {
		    	cout<<str[6]<<endl;
		    	cout<<endl; 
		    	true_Total++;
			}
			if (yourAnswer!=trueAnswer)
			{
				cout<<str[7]<<endl;
				cout<<endl; 
				wrong_Total++;
			}
		}
		
	} 
	
	if (theLanguage==0)
	{
		cout<<str[8]<<true_Total<<endl;
		cout<<str[9]<<wrong_Total<<endl; 
	}
	if (theLanguage==1)
	{
		cout<<"The true total: "<<true_Total<<endl;
		cout<<"The wrong total: "<<wrong_Total<<endl; 
	}
	
	return 0;
}
