#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;


//��������
//ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ����

//ʵ�ֲ���
//1������5��ѡ�֣��ŵ�vector��
//����vector������ ȡ����ÿһѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
//deque��������һ�飬�ۼ��ܷ�
//��ȡƽ����


//ѡ����
class Person {
public:
	Person(string name, int score) {
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;//����
	int m_Score;//ƽ����

};

void createPerson(vector<Person> &v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;

		//��������Person����ŵ�������
		Person p = Person(name, score);
		v.push_back(p);
	}
}

void showScore(vector<Person>&v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->m_Name << ":" <<  it->m_Score << endl;
	}
 }

//���
void setScore(vector<Person>&v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//����ί�Ĵ�ַ��뵽deque������
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			//���������
			int score = rand() % 41 + 60;//������60~100
			d.push_back(score);//����ί�����ַŵ�deque������
		}

		

		//����
		sort(d.begin(),d.end());

		//ȥ����ߺ���ͷ�
		d.pop_back();
		d.pop_front();

		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;//�ۼ�ÿ����ί�ķ���
		}
		int avg = sum / d.size();

		//��ƽ���ָ�ֵ��ѡ������
		(*it).m_Score = avg;

		//����
		//cout << "ѡ�֣�" << (*it).m_Name << " ��֣�" << (*it).m_Score << endl;

		//��ʾ���ĵ÷�
		
	}
	showScore(v);
}

int main() {
	//���������
	srand((unsigned int)time(NULL)); 


	//1������5��ѡ��
	vector<Person>v;//���ѡ�ֵ�����
	createPerson(v);
	//����
	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).m_Name<<"--"<<(*it).m_Score << endl; 
	}*/
	//2����5��ѡ�ִ��
	setScore(v);

	//3����ʾ���ĵ÷�

	system("pause");
	return 0;
}
