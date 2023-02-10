#include<bits/stdc++.h>
using namespace std;

struct HocSinh
{
	string MaHS;
	string HoTen;
	string NgaySinh;
	HocSinh *next;
};

struct Lop
{
	Lop *Down;
	string TenLop;
	HocSinh *head;
};

void nhap(HocSinh *sv)
{
	cout << "Nhap Ho Ten sinh vien: ";
	fflush(stdin);
	getline(cin, sv->HoTen);
	cout << "Nhap Ma so sinh vien : ";
	fflush(stdin);
	getline(cin, sv->MaHS);
	cout << "Nhap NgaySinh cua sinh vien : ";
	fflush(stdin);
	getline(cin ,sv->NgaySinh);
}
HocSinh *taonode()
{
	HocSinh *sv = new HocSinh;
	nhap(sv);
	sv->next = NULL;
	return sv;
}

Lop *taoLop()
{
	Lop *l = new Lop;
	cout<<"Nhap ten Lop: ";
	fflush(stdin);
	getline(cin, l->TenLop);
	l->Down = NULL;
	l->head = NULL;
	int n;
	cout << "--nhap so sinh vien cua lop " << l->TenLop << ": ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "--nhap thong tin sinh vien thu " << i+1 << endl;
		HocSinh *p = taonode();
		if(l->head == NULL)
	        l->head = p;
	    else{
	        HocSinh *q = l->head;
	        while(q->next != NULL)
	        {
	            q=q->next;
	        }
	        q->next=p;
	    }
	}
	return l;
}
void Show(HocSinh *l) 
{
	int i = 1;
	for (HocSinh* k = l; k != NULL; k = k->next) {
		cout<<"STT: " << i;
		cout << "\tMSSV : " << k->MaHS;
		cout << "\tHo Ten  : " << k->HoTen ;
		cout << "\tNgay Sinh : " << k->NgaySinh ;
        cout << endl;
        i++;
	}
}

void xuat(Lop *first)
{
	for(Lop *p=first; p!=NULL; p=p->Down)
	{
		cout<<"---danh sach hoc sinh lop " << p->TenLop << endl;
		Show(p->head);
	}
}

Lop *DiaChi(Lop *first, string Blop)
{
	bool a = false;
	for(Lop *p = first; p != NULL; p = p->Down)
	{
		if(p->TenLop == Blop)
		{
			return p;
			a = true;
			break;
		}
	}
	if(a == false)
		return NULL;
}

void InDSHS(Lop *first, string Blop)
{
	Lop *p = DiaChi(first, Blop);
	if(p == 0)
		cout << "----Lop khong co sinh vien!!!" << endl;
	else
		Show(p->head);
}

int SiSo(Lop *first, string Blop)
{
	Lop *p = DiaChi(first, Blop);
	if(p == 0)
		return 0;
	else
	{
		int dem = 0;
		for(HocSinh *a = p->head; a != NULL; a = a->next)
			dem++;
		return dem;	
	}
}

void inSiSoCacLop(Lop *first)
{
	int i = 1, tong = 0;
	for(Lop *p = first; p != NULL; p = p->Down)
	{
		int dem = 0;
		for(HocSinh *q=p->head; q!=NULL; q=q->next)
			dem++;
		cout << i << ". Lop " << p->TenLop << ": " << dem << " HS" << endl;
		i++;
		tong += dem;
	}
	cout << "---------------------" << endl;
	cout << "Tong cong: "<<tong<<" HS" << endl;
}

void BoSung(Lop *first, string Blop, string ma, string hoten, string ngaysinh)
{
	Lop *p = DiaChi(first, Blop);
	if(p == 0)
	{
		Lop *a = new Lop;
		a->Down = NULL; 
		a->TenLop = Blop;
		HocSinh *sv = new HocSinh;
		sv->MaHS = ma;
		sv->HoTen = hoten;
		sv->NgaySinh = ngaysinh;
		sv->next = NULL;
		a->head = sv;
		Lop *q;
		for(q = first; q->Down != NULL; q = q->Down);
		q->Down = a;
	}
	else
	{
		bool z = false;
			for(HocSinh *f = p->head; f != NULL; f = f->next)
			{
				if(f->MaHS == ma)
				{
					f->MaHS = ma;
					f->HoTen = hoten;
					f->NgaySinh = ngaysinh;
					z = true;
				}
			}
			if(z == false)
			{
				HocSinh *sv = new HocSinh;
				sv->MaHS = ma;
				sv->HoTen = hoten;
				sv->NgaySinh = ngaysinh;
				sv->next = NULL;
				HocSinh *f;
				for(f = p->head; f->next != NULL; f = f->next);
				f->next = sv;
			}
	}
	xuat(first);
}

void xoa(Lop *l, string ma, string Blop)
{
	Lop *i;
	for(Lop *a = l; a != NULL; a = a->Down)
	{
		if(a->TenLop == Blop)
		{
			HocSinh *q, *p;
			for(p = a->head; p != NULL; p = p->next)
			{
				if(p->MaHS == ma)
				{
					if(p == a->head)
					{
						HocSinh *z = p;
						a->head = p->next;
						delete z;	
					}
					else
					{
						HocSinh *z = p;
						q->next = p->next;
						delete z;
					}
				}
				q = p;
			}
			if(a->head == NULL)
			{
				if(a == l)
					l = a->Down;	
				else
					i->Down = a->Down;
			}
		}
		i = a;
	}
	xuat(l);
}

int main()
{
	Lop *first = NULL;
	int n;
	cout << "Nhap so Lop: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "-- Nhap thong tin Lop thu "<<i+1<<endl;
		Lop *p = taoLop();
		if(first == NULL)
	        first=p;
	    else
		{
	        Lop *q = first;
	        while(q->Down != NULL)
	        {
	            q = q->Down;
	        }
	        q->Down = p;
	    }
	}
	string Blop;
	cout << "\n--Nhap ten lop can tim: ";
	fflush(stdin);
	getline(cin,Blop);
	cout << "\n--Danh sach lop " << Blop << endl;
	InDSHS(first, Blop);
	cout << "\n--Si So Lop " << Blop << ": " << SiSo(first, Blop) << endl;
	inSiSoCacLop(first);
	HocSinh *sv = new HocSinh;
	cout << "\nnhap thong tin sinh vien can sua hoac them" << endl;
	nhap(sv);
	BoSung(first, Blop, sv->MaHS, sv->HoTen, sv->NgaySinh);
	string ma;
	cout << "\nNhap ma can xoa: ";
	fflush(stdin);
	getline(cin, ma);
	xoa(first, ma, Blop);
}