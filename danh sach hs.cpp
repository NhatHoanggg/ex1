#include <bits/stdc++.h>

using namespace std;

struct ds{
	char ten[30];
	float t,v,avg;
};

istream &operator >> (istream & in , ds & a);
ostream &operator << (ostream & out, ds & a); 

bool ascending (float left, float right);
bool descending(float left, float right);

void Sort	(ds *&a, int n, bool compFunc(float, float ));


int main(){
	int n ;
	cout << "Nhap so hoc sinh : " ;
	cin >> n;
	ds *a = new ds [n+1]; 
	for (int i =1 ; i <= n ; i++ ){
		cout << "Nhap thong tin hoc sinh thu " << i << endl;
		cin >> a[i];
		}
		
	cout << "#=============================#" << endl << endl;
	cout << "THONG TIN VUA NHAP : " << endl << endl;
	for (int i =1 ; i<=n ; i++){
		cout<< "Hoc sinh thu " << i << endl;
		cout<< a[i]; 
		} 
		
	cout << "#=============================#" << endl << endl;
	cout << " #    SAU KHI SAP XEP :    #" << endl << endl; 
	
	Sort(a,n,ascending);
	for (int i =1 ; i<=n ; i++){
		cout<< "Hoc sinh thu " << i << endl;
		cout<< a[i]; 
		} 
	return 0;
}

bool ascending (float left, float right){
    return left > right;
}
bool descending(float left, float right){
    return left < right;
}

istream & operator >> (istream & in, ds &a){
	cout << "- Ho ten : " ; fflush(stdin);
	fgets(a.ten,30,stdin);
	cout << "- Diem van: ";  in >> a.v; 
	cout << "- Diem toan: "; in >> a.t;
}

ostream & operator << (ostream & out, ds &a){
	cout << "- Ho ten : "   << a.ten ;
	cout << "- Diem van: "  << a.v   << endl;
	cout << "- Diem toan: " << a.t   << endl;
	a.avg = (a.t + a.v)/2;
	cout << "- DTB : "      << a.avg << endl;
	cout << "- Hoc luc: "   ;
	
	if (a.avg >= 8){
		cout << "GIOI" << endl;
	}
	else if (a.avg >= 7){
		cout << "KHA" << endl;
	}
	else if (a.avg >=5){
		cout << "TRUNG BINH" << endl;
	}
	else {
		cout << "YEU" << endl;
	}
	return out;
}

void Sort(ds *&a, int n, bool compFunc(float, float))
{
	for (int i =1 ; i<= n-1 ; i++ )
		for (int j=i+1 ; j<=n ; j++ )
			if (compFunc(a[i].avg, a[j].avg)) {
				ds temp=a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}



