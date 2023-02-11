#include<bits/stdc++.h>
using namespace std;

typedef char St20[20];
struct NN
{
	St20 NgoaiNgu;
	char CapDo;
	NN *next;
};

struct CB
{
	St20 Ten;
	NN *DSNN;
	CB *left, *right;
};

NN *taoNN()
{
	NN *a = new NN;
	cout << "Nhap ten Ngoai Ngu: ";
	fflush(stdin);
	gets(a->NgoaiNgu);
	cout << "Cap Do: ";
	cin >> a->CapDo;
	a->next = NULL;
	return a;
}

CB *insertCB(CB *T, St20 name)
{
	if(T == NULL){
		T = (CB *)malloc(sizeof(CB));
		T->DSNN = NULL;
		int n;
		cout << "Nhap so ngoai ngu cua can bo "<<name<<": ";
		cin >> n;
		for(int i = 0; i < n; i++)
        {
			if(T->DSNN == NULL)
				T->DSNN = taoNN();
			else
            {
				NN *p;
				for(p = T->DSNN; p->next != NULL; p = p->next);
				p->next = taoNN();
			}
		}
		T->right = T->left = NULL;
		strcpy(T->Ten, name);
		return T;
	}
    else
    {
        if(strcmp(T->Ten,name)>0)
		    T->left=insertCB(T->left,name);
	    else
		    T->right=insertCB(T->right,name);
    }
}

void showNN(NN *p)
{
	if(p == NULL)
		cout << "khong biet ngoai ngu nao";
	else
    {
		for(p; p != NULL; p = p->next)
        {
			cout << p->NgoaiNgu << "-" << p->CapDo;
			if(p->next != NULL)
				cout << ", ";
		}
	}
}

void xuat(CB *T, int i)
{
	if(T != NULL)
    {
		i++;
		xuat(T->left, i);
		cout << i << ". " << T->Ten << ": ";
		showNN(T->DSNN);
		cout << endl;
		xuat(T->right, i);
	}
}

void search(CB *T, St20 name)
{
	if(T != NULL)
    {
		if(strcmp(T->Ten, name)>0)
			search(T->left, name);
		else 
        {
            if(strcmp(T->Ten, name)<0)
			    search(T->right, name);
		    else
			    xuat(T,0);
        }
	}
}

void delKey(CB *&T, St20 name)
{
	if(T != NULL)
    {
		if(strcmp(T->Ten, name)>0)
			delKey(T->left, name);
		else
        {
            if(strcmp(T->Ten, name)<0)
			    delKey(T->right, name);
		    else
            {
			    CB *p = T;
			    if(T->left == NULL)
			    	T = T->right;
			    else
                {
                    if(T->right == NULL)
                    T = T->left;
                    else
                    {
				        CB *a = T, *q = a->right;
				        while(q->left != NULL)
                        {
				      	    a = q;
				      	    q = q->left;
				        }
				        strcpy(p->Ten, q->Ten);
				        p->DSNN = q->DSNN;
				        if(p->right != q)
				      	    a->left = q->right;
				        else
				      	    a->right = q->left;
			        }
                }
		    }
        }
	}
}

int main()
{
	CB *T = NULL;
	int n;
	cout << "Nhap so can bo: ";
	cin >> n;
	for(int i = 0; i < n; i++)
    {
		St20 name;
		cout << "Nhap ten can bo: ";
		fflush(stdin);
		gets(name);
		T = insertCB(T,name);
	}
	xuat(T,0);
	St20 name;
	cout << "Nhap ten can bo can bo sung: ";
	fflush(stdin);
	gets(name);
	T = insertCB(T,name);
	cout << "\ndanh sach can bo sau bo sung: " << endl;
	xuat(T,0);
	cout << "\ndanh sach sau tim kiem can bo: "<< name <<endl;
	search(T,name);
	cout << "Nhap ten can xoa: ";
	St20 ten;
	fflush(stdin);
	gets(ten);
	cout << "\ndanh sach sau khi xoa "<< ten <<endl;
	delKey(T,ten);
    xuat(T,0);
}