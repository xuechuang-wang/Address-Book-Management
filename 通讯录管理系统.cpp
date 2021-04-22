#include <iostream>
#include <string>
using namespace std;
#define  MAX 1000


// �����ϵ�˽ṹ��
struct Person
{
	string m_Name; // ����
	int m_Sex; // �Ա�   1 ��  2Ů
	int m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //��ַ
};
 
// ���ͨѶ¼�ṹ��
struct Addressbooks
{

	//ͨѶ¼�б������ϵ�˵�����
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};


//////*********************************************/////
//////********                             ********/////
//////********       1�������ϵ��         ********/////
//////********                             ********/////
//////*********************************************/////
void addPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size  == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			// �������1����2�������˳�ѭ������Ϊ���������ȷֵ
			// �������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������: " << endl;
		}

		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;  
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼�е�����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;

		system("pause"); // �밴���������
		system("cls"); // ��������
	}

}

//////*********************************************/////
//////********                             ********/////
//////********       2����ʾ������ϵ��     ********/////
//////********                             ********/////
//////*********************************************/////
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�е������Ƿ�Ϊ0�����Ϊ0����ʾͨѶ¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ�ļ�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name
			<< "  ���䣺 " << abs->personArray[i].m_Age
			<< "  �Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů")  //����1 ��ʾ:��; ����2����ʾ:Ů
			<< "  �绰�� " << abs->personArray[i].m_Phone 
			<< "  סַ�� " << abs->personArray[i].m_Addr<< endl;

		}
	}
	system("pause"); // �����������
	system("cls"); //����

}

//////*********************************************/////
//////********                             ********/////
//////********       3��ɾ����ϵ��         ********/////
//////********                             ********/////
//////*********************************************/////
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼�� ����2  �Ա�����
int isExist(Addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�Ҵ��ˣ�����������������е��±���
		}
	}
	return -1; //�������������û���ҵ�������-1
}

//ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;

	//ret == -1 δ�鵽
	//ret != -1 �鵽��
	int ret = isExist(abs, name);
	
	if (ret != -1)
	{
		//���ҵ��ˣ�����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼�е���Ա��
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause"); // �����������
	system("cls"); //����

}

//////*********************************************/////
//////********                             ********/////
//////********       4��������ϵ��         ********/////
//////********                             ********/////
//////*********************************************/////
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������ " << abs->personArray[ret].m_Name
			<< "  ����; " << abs->personArray[ret].m_Age
			<< "  �Ա� " << abs->personArray[ret].m_Sex
			<< "  �绰�� " << abs->personArray[ret].m_Phone
			<< "  סַ�� " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause"); // �����������
	system("cls"); //����
}

//////*********************************************/////
//////********                             ********/////
//////********       5���޸���ϵ��         ********/////
//////********                             ********/////
//////*********************************************/////
void mosifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				//������ȷ �˳�ѭ������
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}


		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	//�������������
	system("pause");
	system("cls");

}

//////*********************************************/////
//////********                             ********/////
//////********       6�������ϵ��         ********/////
//////********                             ********/////
//////*********************************************/////
void cleanPerson(Addressbooks* abs)
{
	int x = 0;
	cout << "��ȫ����յ�ǰ��ϵ����Ϣ���Ƿ�ȷ��? " << endl;
	cout << "1��ȷ�� " << endl;
	cout << "2��ȡ�� " << endl;
	cin >> x;
	
	while (true)
	{
		switch (x)
		{
		case 1:
			{
				abs->m_Size = 0;  //����ǰ��¼��ϵ��������Ϊ0�����߼���ղ���
				cout << "ͨѶ¼�ѿ�" << endl;
			}
			break;
		case 2:
			cout << "��ӭ�´�ʹ��" << endl;
			break;
		default:
			break;
		}
		break;


	}
	//�������������
	system("pause");
	system("cls");
	
	
	

}


//////*********************************************/////
//////********                             ********/////
//////********           �˵�����          ********/////
//////********                             ********/////
//////*********************************************/////
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;

}

//////*********************************************/////
//////********                             ********/////
//////********           ������            ********/////
//////********                             ********/////
//////*********************************************/////
int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	 


	int select = 0; // �����û�ѡ������ı���

	while (true)
	{
		showMenu();	//�˵�����

		cin >> select;

		switch (select)
		{
		case 1:  //�����ϵ��
			addPerson(&abs);  //���õ�ַ���ݣ���������ʵ��
			break;
		case 2:  //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:  //ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:  //������ϵ��
			findPerson(&abs);
			break;
		case 5:  //�޸���ϵ��
			mosifyPerson(&abs);
			break;
		case 6:  //�����ϵ��
			cleanPerson(&abs);
			break;
		case 0:  //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause"); 
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0;

}