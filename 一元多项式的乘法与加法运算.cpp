#include<iostream>
using namespace std;

struct PolyNode
{
	int coef;
	int expon;
	PolyNode* next;
};

class Polynomial
{
public:
	Polynomial();
	void ReadPoly();
	void PostInsert(int c, int e, PolyNode* ptr);
	void Insert(int c, int e);//按指数降序插入
	Polynomial* Multiply(const Polynomial& p);
	Polynomial* Add(const Polynomial& p);
	void PrintPoly();
private:
	PolyNode* head;
	PolyNode* tail;
};
Polynomial::Polynomial()
{
	head = tail = new PolyNode;
	tail->next = nullptr;
}
void Polynomial::ReadPoly()
{
	int N;
	cin >> N;
	while (N--)
	{
		int c, e;
		cin >> c >> e;
		this->PostInsert(c, e, tail);
	}
}
void Polynomial::PostInsert(int c, int e, PolyNode* ptr)
{
	PolyNode* temp = new PolyNode;
	temp->coef = c;
	temp->expon = e;
	temp->next = ptr->next;
	ptr->next = temp;
	if (ptr == tail)
	{
		tail = tail->next;
	}
}
void Polynomial::Insert(int c, int e)
{
	if (!this->head->next)
	{
		this->PostInsert(c, e, this->tail);
	}
	else
	{
		PolyNode* p = this->head;
		while (p->next && e < p->next->expon)
		{
			p = p->next;
		}
		if (p->next && e == p->next->expon)
		{
			if (c + p->next->coef != 0)
			{
				p->next->coef += c;
			}
			else
			{
				PolyNode* t = p->next;
				p->next = t->next;
				delete t;
			}
		}
		else
		{
			this->PostInsert(c, e, p);
		}
	}
}
Polynomial* Polynomial::Multiply(const Polynomial& p)
{
	Polynomial* pro = new Polynomial;
	PolyNode* p1 = this->head->next;
	PolyNode* p2 = p.head->next;
	if (!p1 || !p2)
	{
		return nullptr;
	}
	while (p1)
	{
		while (p2)
		{
			pro->Insert(p1->coef * p2->coef, p1->expon + p2->expon);
			p2 = p2->next;
		}
		p1 = p1->next;
		p2 = p.head->next;
	}
	return pro;
}
Polynomial* Polynomial::Add(const Polynomial& p)
{
	Polynomial* sum = new Polynomial;
	PolyNode* p1 = this->head->next;
	PolyNode* p2 = p.head->next;
	while (p1 && p2)
	{
		if (p1->expon == p2->expon)
		{
			if (p1->coef + p2->coef != 0)
			{
				sum->PostInsert(p1->coef + p2->coef, p1->expon, sum->tail);
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->expon > p2->expon)
		{
			sum->PostInsert(p1->coef, p1->expon, sum->tail);
			p1 = p1->next;
		}
		else
		{
			sum->PostInsert(p2->coef, p2->expon, sum->tail);
			p2 = p2->next;
		}
	}
	while (p1)
	{
		sum->PostInsert(p1->coef, p1->expon, sum->tail);
		p1 = p1->next;
	}
	while (p2)
	{
		sum->PostInsert(p2->coef, p2->expon, sum->tail);
		p2 = p2->next;
	}
	return sum;
}
void Polynomial::PrintPoly()
{
	int flag = 0;
	PolyNode* p = this->head->next;
	while (p)
	{
		if (!flag)
		{
			flag = 1;
		}
		else
		{
			cout << " ";
		}
		cout << p->coef << " " << p->expon;
		p = p->next;
	}
}

int main()
{
	Polynomial P1, P2;
	P1.ReadPoly();
	P2.ReadPoly();
	(P1.Multiply(P2))->PrintPoly();
	cout << endl;
	(P1.Add(P2))->PrintPoly();
	return 0;
}