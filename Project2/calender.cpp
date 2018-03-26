#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
using namespace std;
struct Activity
{
	int start_time;
	int duration;
	string user_id;
	string act_id;
	string activity;
	float priority;
};
void menu()
{
	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole,6);
	cout<<"Enter choice 0 to print the calender "<<endl;
	cout<<"Enter choice 1 to clean the calender "<<endl;
	cout<<"Enter choice 2 to List all activities of a given user "<<endl;
	cout<<"Enter choice 3 to List the top 5 activities of a given user "<<endl;
	cout<<"Enter choice 4 to List the five busiest users in a given time period "<<endl;
	cout<<"Enter choice 5 to Print activity stats for a given month."<<endl;
	cout<<"Enter choice 6 to Print Calendar Stats (for the whole year)."<<endl;
	cout<<"Enter choice 7 to Remove a user from the calendar "<<endl;
	cout<<"Enter choice 8 to Save the calendar."<<endl;
}
void bubblesort(Activity array1[],int size)
{

	Activity temp;
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1-i;j++)
			if(array1[j].priority<array1[j+1].priority)
			{
				temp=array1[j];
				array1[j]=array1[j+1];
				array1[j+1]=temp;

			}
	}
}
int increment(Activity *&k)
{
	Activity *temp;
	int i=0;
	if(k!=NULL)
	{
		for(;k[i].activity!="";i++)
		{}
	}
	temp=new Activity[i+2];
	if(i!=0)
	{
		for(int j=0;j<i;j++)
			temp[j]=k[j];
		//delete []k;
	}
	k=new Activity[i+2];  
	if(i!=0)
	{
		for(int j=0;j<i;j++)
			k[j]=temp[j];	  
	}
	delete[]temp;

	return i;
}
void clean_the_calender(Activity ****&ptr)
{
	int days=0;
	for(int i=0;i<12;i++)
	{
		if(i == 0 || i == 2 || i == 4 || i== 6 || i==7 || i == 9 || i==11)
		{
			days=30;
		}
		else if(i==3 || i==5 ||i==8 || i==10)
		{
			days=29;
		}
		else
		{
			days=27;
		}


		for(int j=0;j<=days;j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						for(int m=l+1;ptr[i][j][k][m].activity!="";m++)
						{
							if(ptr[i][j][k][l].user_id==ptr[i][j][k][m].user_id)
							{
								if(ptr[i][j][k][l].priority>ptr[i][j][k][m].priority)
								{
									for(int a=m;ptr[i][j][k][a].activity!="";a++)
									{
										ptr[i][j][k][a]=ptr[i][j][k][a+1];
									}
								}
								else if(ptr[i][j][k][l].priority<ptr[i][j][k][m].priority)
								{
									for(int b=l;ptr[i][j][k][b].activity!="";b++)
									{
										ptr[i][j][k][b]=ptr[i][j][k][b+1];
									}
								}
							}
						}
					}
			}
		}
	}
	cout<<"The calender is cleaned and each hour contains user with highest priority . "<<endl;
	
}
int counting_activities(char arr[])
{
	int no_of_users=0;
	ifstream fin;
	fin.open("sample1.txt");
	if(!fin)
	{
		cout<<"File not opened "<<endl;
	}
	else 
	{
		while(!fin.eof())
		{
			fin.getline(arr,1000,'\n');
			no_of_users++;
		}
	}
	return no_of_users;
	fin.close();
}
void printing_activities(Activity ****&ptr)
{
	string user_id;
	int s_day=0;
	int s_month=0;
	int e_day=0;
	int e_month=0;
	cin.ignore(1);
	cout<<"Enter user_id "<<endl;
	getline(cin,user_id);
	cout<<"Enter start day  "<<endl;
	cin>>s_day;
	cout<<"Enter start month "<<endl;
	cin>>s_month;
	cout<<"Enter end day "<<endl;;
	cin>>e_day;
	cout<<"Enter end month "<<endl;
	cin>>e_month;


	s_day--, s_month--, e_day--, e_month--;
	int arr[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for (int i = s_month; i <= e_month; i++)
	{
		if (i == s_month + 1)
			s_day = 0;
		for (int j = s_day; j < arr[i]; j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						if(ptr[i][j][k][l].user_id==user_id)
							cout<<ptr[i][j][k][l].activity<<"\n";
					}
			}
		}
	}
}
void top_5_activities(Activity ****&ptr)
{
	Activity * ptr1=NULL;
	int count=0;
	int index=0;
	string user_id;
	int s_day=0;
	int s_month=0;
	int e_day=0;
	int e_month=0;
	cin.ignore(1);
	cout<<"Enter user_id "<<endl;
	getline(cin,user_id);
	cout<<"Enter start day  "<<endl;
	cin>>s_day;
	cout<<"Enter start month "<<endl;
	cin>>s_month;
	cout<<"Enter end day "<<endl;;
	cin>>e_day;
	cout<<"Enter end month "<<endl;
	cin>>e_month;

	s_day--, s_month--, e_day--, e_month--;
	int arr[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for (int i = s_month; i <= e_month; i++)
	{
		if (i == s_month + 1)
			s_day = 0;
		for (int j = s_day; j < arr[i]; j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{

						if(ptr[i][j][k][l].user_id==user_id)
						{
							count++;
						}
					}
			}
		}
	}

	ptr1=new Activity[count];

	int arr1[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for (int i = s_month; i <= e_month; i++)
	{
		if (i == s_month + 1)
			s_day = 0;
		for (int j = s_day; j < arr1[i]; j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						if(ptr[i][j][k][l].user_id==user_id)
						{						
							ptr1[index].activity=ptr[i][j][k][l].activity;
							ptr1[index++].priority=ptr[i][j][k][l].priority;
						}
					}
			}
		}
	}

	bubblesort(ptr1,count);

	for(int i=0;i<5;i++)
	{
		cout<<ptr1[i].activity<<endl;
	}

	delete [] ptr1;
}
void Top_5_busiest_users(Activity****&ptr)
{
	int u=0;
	int index=0;
	int size_of_user=0;
	int size=0;
	int s_day=0;
	int s_month=0;
	int e_day=0;
	int e_month=0;
	cin.ignore(1);
	cout<<"Enter start day  "<<endl;
	cin>>s_day;
	cout<<"Enter start month "<<endl;
	cin>>s_month;
	cout<<"Enter end day "<<endl;;
	cin>>e_day;
	cout<<"Enter end month "<<endl;
	cin>>e_month;


	int arr[]={31,28,31,30,31,30,31,31,30,31,30,31};
	s_day--, s_month--, e_day--, e_month--;
	for (int i = s_month; i <= e_month; i++)
	{
		if (i == s_month + 1)
			s_day = 0;
		for (int j = s_day; j < arr[i]; j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						size++;
					}
			}
		}
	}


	string *poi;
	poi=new string [size]();


	int arr1[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for (int i = s_month; i <= e_month; i++)
	{
		if (i == s_month + 1)
			s_day = 0;
		for (int j = s_day; j < arr1[i]; j++)
		{

			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						poi[u++]=ptr[i][j][k][l].user_id;
					}
			}
		}
	}

	for(int i=0;i<size;i++)
	{
		if(poi[i]!="\0")
		{
			for(int j=i+1;j<size;j++)
			{
				if(poi[i]==poi[j])
				{
					poi[j]="\0";
				}
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		if(poi[i]!="\0")
		{
			size_of_user++;
		}
	}

	string *pointer_containing_user;
	pointer_containing_user=new string[size_of_user]();

	for(int i=0;i<size;i++)
	{
		if(poi[i]!="\0")
		{
			pointer_containing_user[index++]=poi[i];
		}
	}


	int *counting=NULL;
	counting=new int [size_of_user]();

	int arr2[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for (int i = s_month; i <= e_month; i++)
	{
		if (i == s_month + 1)
			s_day = 0;
		for (int j = s_day; j < arr2[i]; j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						for(int m=0;m<size_of_user;m++)
						{
							if(ptr[i][j][k][l].user_id==pointer_containing_user[m])
							{
								counting[m]=++counting[m];
							}
						}
					}
			}
		}
	}
	string name;
	int temp=0;
	for(int i=0;i<size_of_user-1;i++)
	{
		for(int j=0;j<size_of_user-1-i;j++)
			if(counting[j]<counting[j+1])
			{
				temp=counting[j];
				counting[j]=counting[j+1];
				counting[j+1]=temp;

				name=pointer_containing_user[j];
				pointer_containing_user[j]=pointer_containing_user[j+1];
				pointer_containing_user[j+1]=name;

			}
	}

	cout<<"Top five users are "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<i+1<<":"<<pointer_containing_user[i]<<endl;
	}

	delete [] poi;
	delete [] pointer_containing_user;
	delete [] counting;
}
void activity_stats_for_month(Activity ****&ptr)
{
	int size_of_arr=0;
	int a=0;
	double average_activities_per_day=0;
	int busiest_day_of_month=0;
	int temp=0;
	int per_day_activities=0;
	int total_no_of_activities=0;
	int days=0;
	int  month;
	cin.ignore(1);
	cout<<"Enter the month "<<endl;
	cin>>month;
	month--;

	if(month == 0 || month == 2 || month == 4 || month == 6 || month==7 || month == 9 || month==11)
	{
		days=30;
	}
	else if(month==3 || month==5 ||month==8 || month==10)
	{
		days=29;
	}
	else
	{
		days=27;
	}

	for(int i=0;i<=days;i++)
	{
		for(int j=0;j<24;j++)
		{
			if(ptr[month][i][j]!=NULL)
				for(int k=0;ptr[month][i][j][k].activity!="";k++)
				{
					total_no_of_activities++;
					per_day_activities++;
				}
		}
		if(i==0)
		{
			temp=per_day_activities;
		}
		else if(per_day_activities>temp)
		{
			temp=per_day_activities;
			busiest_day_of_month=i;
		}
	}
	average_activities_per_day=total_no_of_activities/days;

	cout<<"1:Total no of activities in the month are "<<total_no_of_activities<<"."<<endl;
	cout<<"2:Average activities per day are "<<average_activities_per_day<<"."<<endl;
	cout<<"3:The date of busiest day of the month is "<<busiest_day_of_month+1<<"."<<endl;
	cout<<"4:The total activities in the busiest day are "<<temp<<endl;

	string * arr=NULL;
	arr = new string[total_no_of_activities];

	for(int i=0;i<=days;i++)
	{
		for(int j=0;j<24;j++)
		{
			if(ptr[month][i][j]!=NULL)
			 for(int k=0;ptr[month][i][j][k].activity!="";k++)
			 {
				 arr[a++]=ptr[month][i][j][k].user_id;
			 }
		}
	}


	for(int i=0;i<total_no_of_activities;i++)
	{
		if(arr[i]!="\0")
		{
			for(int j=i+1;j<total_no_of_activities;j++)
			{
				if(arr[i]==arr[j])
				{
					arr[j]="\0";
				}
			}
		}
	}
	for(int i=0;i<total_no_of_activities;i++)
	{
		if(arr[i]!="\0")
		{
			size_of_arr++;
		}
	}


	a=0;
	string *pointer_containing_user;
	pointer_containing_user=new string[size_of_arr]();

	for(int i=0;i<total_no_of_activities;i++)
	{
		if(arr[i]!="\0")
		{
			pointer_containing_user[a++]=arr[i];
		}
	}


	int *counting=NULL;
	counting=new int [size_of_arr]();


	for(int i=0;i<=days;i++)
	{
		for(int j=0;j<24;j++)
		{
			if(ptr[month][i][j]!=NULL)
			 for(int k=0;ptr[month][i][j][k].activity!="";k++)
			 {
				 for(int l=0;l<size_of_arr;l++)
				 {
					 if(pointer_containing_user[l]==ptr[month][i][j][k].user_id)
					 {
						 counting[l]=++counting[l];
					 }
				 }

	 		 }
		 }
	 }
	string name;
	int temp1=0;
	for(int i=0;i<size_of_arr-1;i++)
	{
		for(int j=0;j<size_of_arr-1-i;j++)
			if(counting[j]<counting[j+1])
			{
				temp1=counting[j];
				counting[j]=counting[j+1];
				counting[j+1]=temp1;

				name=pointer_containing_user[j];
				pointer_containing_user[j]=pointer_containing_user[j+1];
				pointer_containing_user[j+1]=name;
			}
	}
	cout<<"5:The busiest user of the month is "<<pointer_containing_user[0]<<"."<<endl;
	cout<<"6:The no of activities of the busiest user are "<<counting[0]<<"."<<endl;

	delete [] counting;
	delete [] arr;
	delete [] pointer_containing_user;
}
void activity_stats_for_year(Activity ****&ptr)
{
	int size_of_arr=0;
	int busiest_month=0;
	int temp=0;
	int average_activities_per_month=0;
	int per_month_activities=0;
	int days=0;
	int total_no_of_activities=0;
	for(int i=0;i<12;i++)
	{
		if(i == 0 || i == 2 || i == 4 || i== 6 || i==7 || i == 9 || i==11)
		{
			days=30;
		}
		else if(i==3 || i==5 ||i==8 || i==10)
		{
			days=29;
		}
		else
		{
			days=27;
		}


		for(int j=0;j<=days;j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						total_no_of_activities++;
					}
			}
			per_month_activities++;
		}
		if(i==0)
		{
			temp=per_month_activities;
		}
		else if(per_month_activities>0)
		{
			temp=per_month_activities;
			busiest_month=i;
		}
	}
	average_activities_per_month=total_no_of_activities/12;
	
	
	cout<<"1:Total no of activities in the year are "<<total_no_of_activities<<"."<<endl;
	cout<<"2:Average activities per month are "<<average_activities_per_month<<"."<<endl;
	cout<<"3:The busiest month of the year is "<<busiest_month+1<<"."<<endl;
	cout<<"4:The total activities in the busiest month are "<<temp<<endl;


	string * arr=NULL;
	arr=new string[total_no_of_activities]();
		int a=0;

	for(int i=0;i<12;i++)
	{
		if(i == 0 || i == 2 || i == 4 || i== 6 || i==7 || i == 9 || i==11)
		{
			days=30;
		}
		else if(i==3 || i==5 ||i==8 || i==10)
		{
			days=29;
		}
		else
		{
			days=27;
		}

		for(int j=0;j<=days;j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						arr[a++]=ptr[i][j][k][l].user_id;
	
					}
			}
		}
	}
	for(int i=0;i<total_no_of_activities;i++)
	{
		if(arr[i]!="\0")
		{
			for(int j=i+1;j<total_no_of_activities;j++)
			{
				if(arr[i]==arr[j])
				{
					arr[j]="\0";
				}
			}
		}
	}
	for(int i=0;i<total_no_of_activities;i++)
	{
		if(arr[i]!="\0")
		{
			size_of_arr++;
		}
	}


	a=0;
	string *pointer_containing_user;
	pointer_containing_user=new string[size_of_arr]();

	for(int i=0;i<total_no_of_activities;i++)
	{
		if(arr[i]!="\0")
		{
			pointer_containing_user[a++]=arr[i];
		}
	}


	int *counting=NULL;
	counting=new int [size_of_arr]();

	for(int i=0;i<12;i++)
	{
		if(i == 0 || i == 2 || i == 4 || i== 6 || i==7 || i == 9 || i==11)
		{
			days=30;
		}
		else if(i==3 || i==5 ||i==8 || i==10)
		{
			days=29;
		}
		else
		{
			days=27;
		}


		for(int j=0;j<=days;j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						for(int m=0;m<size_of_arr;m++)
						{
							if(pointer_containing_user[m]==ptr[i][j][k][l].user_id)
							{
								counting[m]=++counting[m];
							}
						}
					}
			}
		}
	}
	string name;
	int temp1=0;
	for(int i=0;i<size_of_arr-1;i++)
	{
		for(int j=0;j<size_of_arr-1-i;j++)
			if(counting[j]<counting[j+1])
			{
				temp1=counting[j];
				counting[j]=counting[j+1];
				counting[j+1]=temp1;

				name=pointer_containing_user[j];
				pointer_containing_user[j]=pointer_containing_user[j+1];
				pointer_containing_user[j+1]=name;
			}
	}
	cout<<"5:The busiest user of the year is "<<pointer_containing_user[0]<<"."<<endl;
	cout<<"6:The no of activities of the busiest user are "<<counting[0]<<"."<<endl;

	delete [] counting;
	delete [] arr;
	delete [] pointer_containing_user;
}
void Remove_user(Activity ****&ptr)
{
	bool flag = false;
	string user_id;
	cin.ignore(1);
	cout<<"Enter the user which is to be removed "<<endl;
	getline(cin,user_id);
	int arr[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<arr[i];j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
				{
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						if(ptr[i][j][k][l].user_id==user_id)
						{
							flag==true;
							for(int a=l;ptr[i][j][k][a].activity!="";a++)
							{
								ptr[i][j][k][a]=ptr[i][j][k][a+1];
							}
						}
					}
				}
			}
		}
	}
	if(flag==true)
	{
	cout<<"The user you entered has been removed "<<endl;
	}
	else
	{
		cout<<"The user is not present in the calender "<<endl;
	}
}
void Save_calender(Activity ****&ptr)
{
	ofstream fout;
	fout.open("savecalender.txt");
	int arr[]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<arr[i];j++)
		{
			for(int k=0;k<24;k++)
			{
				if(ptr[i][j][k]!=NULL)
				{
					for(int l=0;ptr[i][j][k][l].activity!="";l++)
					{
						fout<<ptr[i][j][k][l].start_time<<",";
						fout<<ptr[i][j][k][l].duration<<",";
						fout<<ptr[i][j][k][l].user_id<<",";
						fout<<ptr[i][j][k][l].act_id<<",";
						fout<<ptr[i][j][k][l].activity<<",";
						fout<<ptr[i][j][k][l].priority<<"\n";

					}
				}
			}
		}
	}
	cout<<"The calender have been saved "<<endl;
}
void main()
{
	char arr[1000]={'\0'};
	int no_of_activities=counting_activities(arr);
	Activity**** calender=NULL;
	calender=new Activity*** [12];
	int days=0;
	for(int i=0;i<12;i++)
	{
		if(i==0 || i==2 ||  i==4 || i==6 || i==7 || i==9 || i==11)
		{
			days=31;			
		}
		else if(i==1)
			days=28;
		else
			days=30;
		calender[i]=new Activity**[days];
		for(int j=0;j<days;j++)
		{
			calender[i][j]=new Activity*[24];

			for(int k=0;k<24;k++)
				calender[i][j][k]=NULL;
		}
	}	

	int a=0;
	char str[1000]={'\0'};

	ifstream file;
	file.open("sample1.txt");
	if(file.is_open())
	{
		for (int i = 0; i < no_of_activities; ++i)
		{
			file.getline(str,1000,'\n');
			int day=atoi(strtok(str,"/"));
			int month=atoi(strtok('\0',","));
			day--;month--;			
			int start_time=atoi(strtok('\0',","));
			int end_time=atoi(strtok('\0',","));		
			int duration=end_time-start_time;
			string user_id=strtok('\0',",");
			string act_id=strtok('\0',",");
			string activity=strtok('\0',",");
			float priority=atof(strtok('\0',""));
			int x=increment(calender[month][day][start_time]);
			calender[month][day][start_time][x].activity=activity;
			calender[month][day][start_time][x].act_id=act_id;
			calender[month][day][start_time][x].start_time=start_time;
			calender[month][day][start_time][x].user_id=user_id;
			calender[month][day][start_time][x].duration=duration;
			calender[month][day][start_time][x].priority=priority;
			calender[month][day][start_time][x+1].activity="";
		}
		file.close();
	}
	int choice=0;
	HANDLE hconsole=0;
	hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hconsole,10);
	menu();

	cout<<"Enter the choice "<<endl;
	cin>>choice;
	while(choice!=10)
	{
	
	if(choice==0)
	{}
	else if(choice==1)
	{
		clean_the_calender(calender);
	}
	if(choice==2)
	{
		printing_activities(calender);
	}
	else if(choice==3)
	{
		top_5_activities(calender);
	}
	else if(choice==4)
	{
		Top_5_busiest_users(calender);
	}
	else if(choice==5)
	{
		activity_stats_for_month(calender);
	}
	else if(choice==6)
	{
		activity_stats_for_year(calender);
	}
	else if(choice==7)
	{
		Remove_user(calender);
	}
	else if(choice==8)
	{
		Save_calender(calender);
	}
	menu();

	cout<<"Enter the choice "<<endl;
	cin>>choice;

	}
	system("pause");
} 


