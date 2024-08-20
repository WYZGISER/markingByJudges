#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;


//案例描述
//选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分

//实现步骤
//1、创建5名选手，放到vector中
//遍历vector容器， 取出来每一选手，执行for循环，可以把10个评分打分存到deque容器中
//sort算法对deque容器中分数排序，去除最高和最低分
//deque容器遍历一遍，累加总分
//获取平均分


//选手类
class Person {
public:
	Person(string name, int score) {
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;//姓名
	int m_Score;//平均分

};

void createPerson(vector<Person> &v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		//将创建的Person对象放到容器中
		Person p = Person(name, score);
		v.push_back(p);
	}
}

void showScore(vector<Person>&v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->m_Name << ":" <<  it->m_Score << endl;
	}
 }

//打分
void setScore(vector<Person>&v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//将评委的打分放入到deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			//给个随机分
			int score = rand() % 41 + 60;//随奇数60~100
			d.push_back(score);//把评委的评分放到deque容器中
		}

		

		//排序
		sort(d.begin(),d.end());

		//去除最高和最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;//累加每个评委的分数
		}
		int avg = sum / d.size();

		//将平均分赋值给选手身上
		(*it).m_Score = avg;

		//测试
		//cout << "选手：" << (*it).m_Name << " 打分：" << (*it).m_Score << endl;

		//显示最后的得分
		
	}
	showScore(v);
}

int main() {
	//随机数种子
	srand((unsigned int)time(NULL)); 


	//1、创建5名选手
	vector<Person>v;//存放选手的容器
	createPerson(v);
	//测试
	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).m_Name<<"--"<<(*it).m_Score << endl; 
	}*/
	//2、给5名选手打分
	setScore(v);

	//3、显示最后的得分

	system("pause");
	return 0;
}
