#include<iostream>
using namespace std;
int centurycal(int year)
{
	year=year-(year%100);
	year=year%400;
	year=year/100;
	if (year==1){return 4;}
	if (year==2){return 2;}
	if (year==3){return 0;}
	if (year==0){return 6;}
}
int yearcal(int year)
{
	year=year%100;
	year=year+(year/4);
	year=year%7;
	return year;
}
int leapcal(int year)
{
	int x,y,z;
	x=year%4;
	if (x==0)
	{goto step1;}
	else
	{goto step4;}
	step1:
	{
		y=year%100;
		if(y==0)
		{goto step2;}
		else 
		{goto step3;}
	}
	step2:
	{
		z=year%400;
		if (z==0)
		{goto step3;}
		else
		{goto step4;}
	}
	step3: {return 1;}
	step4: {return 0;}
	
}
int monthcal(int leap, int month)
{
	if (month ==1)
	{
		if(leap==1)
		return 6;
		else
		return 0;
	}
	if (month==2)
	{
		if (leap==1)
		return 2;
		else
		return 3;
	}
	if (month==3){return 3;}
	if (month==4){return 6;}
	if (month==5){return 1;}
	if (month==6){return 4;}
	if (month==7){return 6;}
	if (month==8){return 2;}
	if (month==9){return 5;}
	if (month==10){return 0;}
	if (month==11){return 3;}
	if (month==12){return 6;}
	
}
void daycal(int date)
{
	cout<<endl<<"The day is ";
	if (date==0){cout<<"Sunday";}
	if (date==1){cout<<"Monday";}
	if (date==2){cout<<"Tuesday";}
	if (date==3){cout<<"Wednesday";}
	if (date==4){cout<<"Thursday";}
	if (date==5){cout<<"Friday";}
	if (date==6){cout<<"Saturday";}
	cout<<endl;	
}
int main()
{
	int date,month,year,centurycode,yearcode,monthcode,leap;
	cout<<"This program is to find the day of the week."<<endl<<endl;
	cout<<"Enter the date: ";
	cin>>date;
	cout<<"Enter the month: ";
	cin>>month;
	cout<<"Enter the year: ";
	cin>>year;
	if (date >31 || month> 12)
	{
		cout<<endl<<"Enter proper values."<<endl;
	}
	else
	{
	centurycode=centurycal(year);
	yearcode=yearcal(year);
	leap=leapcal(year);
	monthcode=monthcal(leap, month);
	date=date+centurycode+yearcode+monthcode;
	date=date%7;
	daycal(date);
	cout<<endl<<"Program dedicated to Ritvik Saran.";
    }
    return 0;
}
