#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct sach{
	float maS;
	char tenS[30];
	char namXB[5];
	char tenTG[30];
	float sooke;
};
struct node{
	sach data;
	node *next;
};
struct list{
	node *head;
	node *tail;
};
void CreateList(list &l){
	l.head=l.tail=NULL;
}
node *CreateNode(sach x){
	node *p= new node;
	cout<<"MA SACH:";
	cin>>x.maS;
	cout<<"TEN SACH:";
	fflush(stdin);
	gets(x.tenS);
	cout<<"NAM XUAT BAN:";
	fflush(stdin);
	gets(x.namXB);
	cout<<"TEN TAC GIA:";
	fflush(stdin);
	gets(x.tenTG);
	cout<<"SO O KE:";
	cin>>x.sooke;
	p->data=x;
	p->next=NULL;
	return p;
}
void addhead(list &l,node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		p->next=l.head;
		l.head=p;
	}
}
void addtail(list &l,node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		l.tail->next=p;
		l.tail=p;
	}
}
void sapxep(list &l){
	node *p,*q;
	for(node *p=l.head;p!=l.tail;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->data.maS>q->data.maS){
				sach x=p->data;
				p->data=q->data;
				q->data=x;
			}
		}
	}
}
void xoacuoi(list &l){
	for(node *i=l.head;i!=NULL;i=i->next){
		if(i->next==l.tail){
			delete l.tail;
			i->next=NULL;
			l.tail=i;
		}
	}
}
void xoadau(list &l){
	for(node *k=l.head;k!=NULL;k=k->next){
		if(k==l.head){
			delete l.head;
			k=k->next;
			l.head=k;
		}
	}
}
void input(list &l, int n){
	for(int i=0; i<n; i++){
		sach x;
		cout<<"\t\t==================\n";
		cout<<"QUYEN THU:"<<i<<endl;
		node *p=CreateNode(x);
		addtail(l,p);
	}
}
void xuat(sach x){
	cout<<"\n"<<x.maS;
	cout<<"\t"<<x.tenS;
	cout<<"\t"<<x.namXB;
	cout<<"\t"<<x.tenTG;
	cout<<"\t"<<x.sooke;
}
void output(list l){
	node *p=l.head;
	sach x;
	while(p!=NULL){
		xuat(p->data);
		p=p->next;
	}
}
void timkiem(list l){
	int u;
	cout<<"\nNHAP TEN SACH CAN TIM:";
	cin>>u;
	for(node *h=l.head;h!=NULL;h=h->next){
		if(h->data.maS==u){
			output(l);
			return;
		}
	}
	cout<<"KHONG CO SACH CAN TIM:\n"<<u;
}
void huydanhsach(list &l){
	for(node *p=l.head;p!=NULL;p=p->next){
		node *o=l.head;
		l.head=p->next;
		delete o;
	}
	l.tail=NULL;
}
int main(){
	int n;
	list l;
	sach x;
	node *p;
	while(true){
	cout<<"\n1. NHAP THONG TIN SACH:";
	cout<<"\n2. XUAT THONG TIN SACH:";
	cout<<"\n3. THEM SACH VAO DAU:";
	cout<<"\n4. THEM SACH VAO CUOI:";
	cout<<"\n5. SAP XEP SACH THEO MA SACH:";
	cout<<"\n6. XOA SACH DAU DANH SACH:";
	cout<<"\n7. XOA SACH CUOI DANH SACH:";
	cout<<"\n8. TIEM KIEM SACH THEO MA SACH:";
	cout<<"\n9. XOA TOAN BO DANH SACH:";
	cout<<"\n10. THOAT.";
	int chon;
	cout<<"\n\t>>>>CHON SO:";
	cin>>chon;
	switch(chon){
	     case 1:{
	     	int n;
	        cout<<"NHAP SO LUONG SACH:";
	        cin>>n;
	     	input(l,n);
			break;
		 }
		 case 2:{
		 	output(l);
			break;
		 }
		 case 3:{
		 	p=CreateNode(x);
		    cout<<"SAU KHI THEM SACH DAU DANH SACH LA:";
		 	addhead(l,p);
		 	output(l);
			break;
		 }
		 case 4:{
		 	p=CreateNode(x);
		 	cout<<"SAU KHI THEM SACH CUOI DANH SACH LA:";
		 	addtail(l,p);
		 	output(l);
			break;
		 }
		  case 5:{
		  	cout<<"SAU KHI SAP XEP LA:\n";
		  	sapxep(l);
		  	output(l);
			break;
		  }
		  case 6:{
		  	cout<<"DANH SACH SACH KHI XOA:\n";
		  	xoadau(l);
		  	output(l);
			break;
		  }
		  case 7:{
		  	cout<<"DANH SACH SAU KHI XOA:\n";
		  	xoacuoi(l);
		  	output(l);
			break;
		  }
		  case 8:{
		  	cout<<"SAU KHI TIM KIEM SACH LA:\n";
		  	timkiem(l);
			break;
		  }
		  case 9:{
		  	cout<<"SAU KHI DA HUY NHAP LAI TU DAU:\n";
		  	huydanhsach(l);
			break;
		  }
		  case 10:{
		  	cout<<"THOAT!\n";
			break;
		  }
	}
}
}
