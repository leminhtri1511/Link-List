#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int Info;
	Node *next;
};

Node *taoNode(int x)
{
	Node *a = new Node;
	a->Info = x;
	a->next = NULL;
	return a;
}

void xuat(Node *F)
{
	for(Node *p = F; p != NULL; p = p->next)
		cout << p->Info << " ";

	cout << endl;
}

void taods(Node *&F)
{
	int n;
	cout << "Nhap so node trong danh sach: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cout << "Nhap Node them vao danh sach: ";
		cin >> x;
		if(F == NULL)
			F = taoNode(x);
		else
		{
			Node *p;
			for(p = F; p->next != NULL; p = p->next);
			p->next = taoNode(x);
		}
	}
}
// CAU 1
void timNodeBeHonX(Node *F){
	int x;
	cout << "Nhap node can so sanh: ";
	cin >> x;
	for(Node *p = F; p != NULL; p = p->next)
	{
		if(p->Info < x)
			cout << p->Info<<" ";
		
	}
	cout << endl;
}

void sapXep(Node *F)
{
	for(Node *p = F; p -> next != NULL; p = p->next)
	{
		for(Node *q = p->next; q != NULL; q = q->next)
		{
			if(p->Info > q->Info)
			{
				int d = p->Info;
				p->Info = q->Info;
				q->Info = d;
			}
		}
	}
}
// CAU 2
void chen(Node *F)
{
	int x;
	cout << "Nhap Node can chen: ";
	cin >> x;
	Node *a = taoNode(x);
	Node *t, *p;
	for(p = F; p != NULL; p = p->next)
	{
		if(p->Info < x)
			t = p;
		
	}
	if(p == F)
	{
		a->next = p;
		F = a;
	}
	else
	{
		a->next = p;
		t->next = a;
	}
	xuat(F);
}
// CAU 3
void xoa(Node *F)
{
	int x;
	cout << "Nhap Node can xoa: ";
	cin >> x;
	Node *t, *p, *a;
	for(p = F; p->Info != x; p = p->next)
		t = p;
	if(p == F)
	{
		a = F;
		F = p->next;
		delete a;
	}
	else
	{
		a = p;
		t->next = p->next;
		delete a;
	}
}
// CAU 4
void GTLN(Node *F)
{
	sapXep(F);
	Node *p;
	for(p = F; p->next != NULL; p = p->next);
	for(Node *q = F; q != NULL; q = q->next)
	{
		if(q->Info == p->Info)
			cout << q->Info << " ";
		
	}
	cout << endl;
}
// CAU 5
void BoSungCuoiDS(Node *F)
{
	int x;
	cout << "Nhap Node can chen: ";
	cin >> x; 
	Node *p;
	for(p = F; p->next != NULL; p = p->next);
	p->next = taoNode(x);
}
// CAU 6
void xoaNodeCuoi(Node *F)
{
	Node *p, *q;
	for(p = F; p->next != NULL; p = p->next)
		 q= p;
	Node *a = p;
	q->next = p->next;
	delete a;
}
// CAU 7
Node *TimDiaChi(Node *F, int x)
{
	Node *p;
	for(p = F; p->Info != x; p = p->next);
	return p;
}

// CAU 8
void indsNguoc(Node *F)
{
	for(Node *p = F; p->next != NULL; p = p->next)
	{
		for(Node *q = p->next; q != NULL; q = q->next)
		{
			if(p->Info < q->Info)
			{
				int a = p->Info;
				p->Info = q->Info;
				q->Info = a;
			}
		}
	}
	xuat(F);
}
// CAU 9
Node *taoDsMoi(Node *&F, Node *&L)
{
	L = F;
	return L;
}
// Cau 10
void Giao(Node *&F, Node *&L, Node *&K)
{
	for(Node *q = L; q != NULL; q = q->next)
	{
		bool t = false;
		for(Node *a = F; a != NULL; a = a->next)
		{
			if(q->Info != a->Info)
				t = false;
			else
			{
				t = true;
				break;
			}
		}
		if(t == true)
		{
			int x = q->Info;
			if(K == NULL)
				K = taoNode(x);
			else
			{
				Node *p;
				for(p = K; p->next != NULL; p = p->next);
				p->next = taoNode(x);
			}
		}
	}
	sapXep(K);
}

Node *Hop(Node *&F, Node *&L, Node *&K)
{
	K = F;
	for(Node *q = L; q != NULL; q = q->next)
	{
		bool t = false;
		for(Node *a = F; a != NULL; a = a->next)
		{
			if(q->Info != a->Info)
				t = true;
			else
			{
				t = false;
				break;
			}
		}
		if(t == true)
		{
			int x = q->Info;
			Node *p;
			if(K == NULL)
				K = taoNode(x);
			else
			{
				Node *p;
				for(p = K; p->next != NULL; p = p->next);
				p->next = taoNode(x);
			}
		}
	}
	sapXep(K);
	return K;
}
int main()
{
	Node *F = NULL;
	taods(F);
	xuat(F);
	timNodeBeHonX(F);
	chen(F);
	xoa(F);
	xuat(F);
	GTLN(F);
	xoaNodeCuoi(F);
	xuat(F);
	Node *L = NULL;
	taods(L);
	xuat(L);
	Node *K = NULL;
	K = Hop(F, L, K);
	xuat(K);
}