/*���ڸ������ĸ�ʽ*/  

#include <iostream> 
using namespace std; 
int main()  

{  

    float f=2.0/3.0,f1=0.000000001,f2=-9.9;  

	cout<<f<<' '<<f1<<' '<<f2<<endl;      //������� 


    cout.setf(ios::showpos);              //ǿ��������ǰ��+�� 


    cout<<f<<' '<<f1<<' '<<f2<<endl;  

    cout.unsetf(ios::showpos);            //ȡ������ǰ��+�� 


    cout.setf(ios::showpoint);            //ǿ����ʾС��������Ч0 


    cout<<f<<' '<<f1<<' '<<f2<<endl;  

    cout.unsetf(ios::showpoint);          //ȡ����ʾС��������Ч0 


    cout.setf(ios::scientific);          //��ѧ������ 


    cout<<f<<' '<<f1<<' '<<f2<<endl;  

    cout.unsetf(ios::scientific);        //ȡ����ѧ������ 


    cout.setf(ios::fixed);                //���������ʾ 


    cout<<f<<' '<<f1<<' '<<f2<<endl;  

    cout.unsetf(ios::fixed);              //ȡ�����������ʾ 


    cout.precision(18);                  //����Ϊ18������Ϊ6 


    cout<<f<<' '<<f1<<' '<<f2<<endl;  

    cout.precision(6);                    //���Ȼָ�Ϊ6 

	cout<<4<<endl;
	cout.setf(ios::fixed);  
	cout.precision(1);  
	cout<<(double)5/3<<endl; 
	return 0;
}  
