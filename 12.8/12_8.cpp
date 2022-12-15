#include<stdio.h>
#include<stdlib.h>
struct myTime
{
	int year;
	int month;
	int day;
};
struct myCal
{
	myTime t1;
	myCal();
	myCal(char* file);
	bool IsLeap(int);
	int DiffDay(myTime d_time);
	int Difftime();
	void PrintCal(int, int);
	void PrintCal(int);
	void PrintYear();
	int GetWeekDay();
};
void bar();
const int DaysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char WeekName[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int main()
{
	
	myCal cal("date.txt");
	printf("year:%d, Leap:%d\n", cal.t1.year, cal.IsLeap(cal.t1.year));
	printf("1900/01/01 到 %d/%d/%d 共%d 天\n", cal.t1.year, cal.t1.month, cal.t1.day, cal.DiffDay(cal.t1));
	printf("%d/%d/%d 星期%s, %d\n", cal.t1.year, cal.t1.month, cal.t1.day, WeekName[cal.GetWeekDay()], cal.GetWeekDay()); 
	cal.PrintCal(cal.t1.year, cal.t1.month);
	
	
	cal.PrintCal(cal.t1.year);
	return 0;
}

int myCal::GetWeekDay()
{
	int diffD=0;
	diffD=DiffDay(t1);
	return (1+diffD)%7;	
}

void bar()
{
	char weekday[7][10] = {"星期天", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};

	//printf("                              萬年曆                                        \n\n");
	for(int i=0;i<7;i++)
	{
		printf("%10s", weekday[i]);
	}
	printf("\n");
}
	
myCal::myCal()
{

}

myCal::myCal(char* filename)
{
	
	FILE *fptr=fopen(filename,"r");
	fscanf(fptr, "%d", &t1.year);
	fscanf(fptr, "%d", &t1.month);
	fscanf(fptr, "%d", &t1.day);
	printf("%d %d %d\n", t1.year, t1.month, t1.day);
}

bool myCal::IsLeap(int year)
{
	//西元年 如果為400的倍數一定閏年 
	//       如果不為400的倍數，但是為100倍數就不閏年
	//       如果不為400且不為100，但是為4的倍數就閏年
	//       其他，不閏年
	if(year%400==0)
		return true;
	else if(year%100==0)
		return false;
	else if(year%4==0)
		return true;
	else
		return false;
}

int myCal::DiffDay(myTime d_time)
{
	int totalDays=0; 
	//計算差幾年
	 for(int i=1900;i<d_time.year;i++)
	 {
	 	if(IsLeap(i))
	 		totalDays += 366;
		else
			totalDays += 365; 
	 }
	 
	 //月 
	 for(int i=1;i<d_time.month;i++)
	 {
	 	totalDays += DaysOfMonth[i-1];
	 	if(i==2 && IsLeap(d_time.year))
	 		totalDays +=1; 
	 }
	//日
	
	totalDays += d_time.day-1; 
	
	return totalDays;
}


void myCal::PrintCal(int year, int month)
{
	bar();
	myCal temp;
	temp.t1.year=year;
	temp.t1.month=month;
	temp.t1.day=1;
	int totalDays=temp.DiffDay(temp.t1);
	printf("WeekDay:%d\n",temp.GetWeekDay());
	for(int i=0;i<temp.GetWeekDay();i++)
	{
		printf("          ");
	}
	for(int i=0;i<DaysOfMonth[temp.t1.month-1];i++)
	{
		printf("%10d", i+1);
		if((temp.GetWeekDay()+i+1)%7==0)
			printf("\n"); 
	}
	if(month==2 && IsLeap(temp.t1.year))
		printf("        29");
	
	printf("\n");	

}

void myCal::PrintCal(int year)
{
	//bar();
	for(int i=1;i<=12;i++)
	{
		PrintCal(year, i);
	}

}