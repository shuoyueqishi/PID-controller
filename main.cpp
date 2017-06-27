#include<iostream>
#include"pid_controller.h"
using namespace std;
int main()
{
	//��������PID
	PID_incremental pid1(0.35,0.65,0.005);
	float target=1000.0;
	float actual=0;
	float pid_increment=0.0;
	int N=50;
	pid1.pid_show();
	cout<<"target="<<target<<endl;
	for(;N>0;N--)
	{
		pid_increment=pid1.pid_control(target,actual);
		actual+=pid_increment;
		cout<<"N="<<50-N<<"   actual="<<actual<<endl;
	}
	pid1.pid_show();

	//����λ��PID
	PID_position pid2(0.65,0.35,0.002);
	pid2.pid_show();
	cout<<"target="<<target<<endl;
	N=50;
	for(;N>0;N--)
	{
		actual=pid2.pid_control(target,actual);
		cout<<"N="<<50-N<<"   actual="<<actual<<endl;
	}
	pid2.pid_show();

	system("pause");
	return 0;
}