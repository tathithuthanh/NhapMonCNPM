//////////////////////////
//TGIAC
/*
Yêu cầu 1:  Xây dựng cấu trúc ĐIỂM gồm tung độ và hoành độ (số nguyên)
-      Viết quá tải hàm nhập,xuất điểm
-      Viết hàm tính khoảng cách giữa 2 điểm
-      Viết quá tải so sánh bằng giữa 2 điểm: kiểm tra 2 điểm có trùng nhau không?
 
Yêu cầu 2: Xây dựng cấu trúc TAMGIAC gồm 3 điểm (PHẢI dựa vào cấu trúc ĐIỂM ở trên)
-      Viết quá tải hàm nhập,xuất (không cần kiểm tra điều kiện của tam giác, giả sư với 3 điểm bất kỳ đều là tam giác)
-      Viết hàm tính chu vi tam giác
-      Quá tải toán tử + hai tam giác (HD: cộng chu vi tam giác)
-      Quá tải toán tử <  dùng để so sánh 2 tam giác (HD: so sánh dựa vào chu vi)
-      Quá tải toán tử so sánh bằng dùng kiểm tra 2 TAM GIÁC có trùng nhau hay không?
 
Yêu cầu 3: nhập dữ liệu tọa độ của 2 tam giác theo cấu trúc
-      Dòng 1: 3 điểm của tam giác 1
-      Dòng 2: 3 điểm của tam giác 2
Xuất kết quả theo cấu trúc sau:
-      Dòng 1: xuất các tọa độ của tam giác 1
-      Dòng 2: xuất các tọa độ của tam giác 2
-      Dòng 1: ghi TRUE, nếu tam giác 1 < tam giác 2, ngược lại ghi FALSE
-      Dòng 2: ghi TRUE, nếu 2 tam giác trùng nhau, ngược lại ghi FALSE
 
Ví dụ:
Input:
1 2 3 4 5 6
7 8 9 0 1 2
 
Output:
(1,2)(3,4)(5,6)
(7,8)(9,0)(1,2)
TRUE
FALSE.

*/

#include <iostream>
#include <cmath>

using namespace std;

//structure

struct Diem{
    int tung, hoanh;
    
    bool operator== (Diem X){
        return (double) tung == X.tung && hoanh == X.hoanh;
    }
    
    bool operator!= (Diem X){
        return !(*this == X);
    }
};

struct TamGiac{
    Diem dinhA, dinhB, dinhC;
};


istream& operator>> (istream& input,  Diem & X);
ostream& operator<< (istream& output, Diem   X);

istream& operator>> (istream& input,  TamGiac & T);
ostream& operator<< (ostream& output, TamGiac   T);

double tinhKhoangCach(Diem A, Diem B);

double chuVi(TamGiac T);
double operator+ (TamGiac T1, TamGiac T2);
Diem timTrongTam (TamGiac T);
bool operator< (TamGiac T1, TamGiac T2);
bool operator== (TamGiac T1, TamGiac T2);

int main(){
    
    TamGiac tg1, tg2;
    
    cin >> tg1 >> tg2;
    
    cout << tg1 << endl << tg2 << endl;
    
    if(tg1 < tg2) cout << "TRUE";
    else cout << "FALSE";
    
    cout << endl;
    
    if (tg1 == tg2) cout << "TRUE";
    else cout << "FALSE";
    
    return 0;
}



double tinhKhoangCach(Diem A, Diem B){
    return (double) sqrt(pow(B.hoanh - A.hoanh,2) + pow(B.tung - A.tung,2));
}

istream& operator>> (istream& input, Diem & X){
    input >> X.hoanh >> X.tung;
    return input;
}

ostream& operator<< (ostream& output, Diem  X){
    output << "(" << X.hoanh << "," << X.tung << ")";
    return output;
}

istream& operator>> (istream& input,  TamGiac & T){
    input >> T.dinhA >> T.dinhB >> T.dinhC;
    return input;
}

ostream& operator<< (ostream& output, TamGiac   T){
    output << T.dinhA << T.dinhB << T.dinhC;
    return output;
}

double chuVi(TamGiac T){
    return tinhKhoangCach(T.dinhA, T.dinhB)
         + tinhKhoangCach(T.dinhB, T.dinhC)
         + tinhKhoangCach(T.dinhA, T.dinhC);
}

double operator+ (TamGiac T1, TamGiac T2){
    return chuVi(T1) + chuVi(T2);
}

bool operator< (TamGiac T1, TamGiac T2){
    return chuVi(T1) < chuVi(T2);
}

Diem timTrongTam (TamGiac T){
    Diem tam;
    tam.hoanh = (T.dinhA.hoanh + T.dinhB.hoanh + T.dinhC.hoanh)/3;
    tam.tung = (T.dinhA.tung + T.dinhB.tung + T.dinhC.tung)/3;
    
    return tam;
}

bool operator== (TamGiac T1, TamGiac T2){
    return timTrongTam(T1) == timTrongTam(T2);
}


////////////////////////////////
/*
//Điểm trong không gian và mặt phẳng 

Xây dựng cấu trúc điểm trong mặt phẳng Oxy 
Viết quá tải toán tử nhập ( >> ) , xuất ( << ) (xuất theo dạng (x, y) ) 
viết quá tải toán tử trừ ( - ) để tính khoảng cách giữa 2 điểm 
viết quá tải toán tử so sánh nhỏ hơn ( < ) để so sánh toạ độ của 2 điểm (theo thứ tự hoành độ rồi tới tung độ)

Xây dựng cấu trúc điểm trong không gian Oxyz
Viết quá tải toán tử nhập ( >> ) , xuất ( << ) (xuất theo dạng (x, y, z) )
viết quá tải toán tử trừ ( - ) để tính khoảng cách giữa 2 điểm 
viết quá tải toán tử so sánh nhỏ hơn ( < ) để so sánh toạ độ của 2 điểm (theo thứ tự ưu tiên hoành độ, tung độ, cao độ)  
Xây dựng cấu trúc mảng lưu trữ cấu trúc điểm ở trên sử dụng template
Viết quá tải toán tử nhập ( >> ) , xuất ( << )
viết hàm tìm khoảng cách lớn nhất giữa 2 điểm trong mảng (tìm trong mảng 2 điểm sao cho khoảng cách giữa 2 điềm đó là lớn nhất )
viết hàm sắp xếp mảng tăng dần
viết hàm sắp xếp mảng giảm dần
Dữ liệu nhập:
chuỗi "Oxy" và "Oxyz" và toạ độ điểm, nếu là Oxy thì nhập điểm trong mp Oxy , nếu là Oxyz thì nhập điểm trong không gian Oxyz

Dữ liệu xuất:
dòng 1: xuất ra mảng toạ độ trong hệ toạ độ Oxy theo thứ tự tăng dần, mỗi phần tử cách nhau 1 khoảng trắng
dòng 2:  xuất ra mảng toạ độ trong hệ toạ độ Oxyz theo thứ tự giảm dần, mỗi phần tử cách nhau 1 khoảng trắng 
dòng 3: xuất ra khoảng cách lớn nhất giữa 2 điểm trong mảng toạ độ Oxy, làm tròn đến 3 chữ số thập phân
dòng 4:  xuất ra khoảng cách lớn nhất giữa 2 điểm trong mảng toạ độ Oxyz, làm tròn đến 3 chữ số thập phân

lưu ý: sử dụng roundf(n * 1000) / 1000 ; để làm tròn n tới 3 chữ số thập phân 

Input:
Oxy 1 2
Oxyz 1 2 3
Oxy 5 2
Oxyz 4 5 6
Oxy 7 8

Output:
(1,2) (5,2) (7,8) 
(4,5,6) (1,2,3) 
8.485
5.196
*/

#include <iostream>
#include <math.h>
#include <string>
using namespace std;
struct Oxy
{
	int x, y;
};
istream& operator>>(istream& in, Oxy& oxy);
ostream& operator<<(ostream& out, Oxy oxy);
bool operator<(Oxy o1, Oxy o2);
float operator-(Oxy o1, Oxy o2);
struct Oxyz
{
	int x, y, z;
};
istream& operator>>(istream& in, Oxyz& oxy);
ostream& operator<<(ostream& out, Oxyz oxy);
bool operator<(Oxyz o1, Oxyz o2);
float operator-(Oxyz o1, Oxyz o2);
template <typename T>
struct Mang
{
	int spt;
	T a[100];
	T& operator[](int i) {
		return a[i];
	}
		Mang() {
		spt = 0;
	}
};
template <typename T>
istream& operator>>(istream& in, Mang<T>& m);
template <typename T>
ostream& operator<<(ostream& out, Mang<T> m);
template <typename T>
float timMax(Mang<T> m);
template <typename T>
Mang<T> sapXepTangDan(Mang<T>& m);
template <typename T>
Mang<T> sapXepGiamDan(Mang<T>& m);
int main() {
	string kt;
	Mang<Oxy> m1;
	Mang<Oxyz> m2;
	while (cin>>kt)
	{
		if (kt=="Oxy")
		{
			Oxy o1;
			cin >> o1;
			m1[m1.spt++] = o1;
		}
		else if(kt=="Oxyz"){
			Oxyz o1;
			cin >> o1;
			m2[m2.spt++] = o1;
		}
	}
	cout << sapXepTangDan<Oxy>(m1) << endl;
	cout << sapXepGiamDan<Oxyz>(m2) << endl;
	cout << timMax<Oxy>(m1)<<endl;
	cout << timMax<Oxyz>(m2)<<endl;
	//system("pause");
	return 0;
}
istream& operator>>(istream& in, Oxy& oxy) {
	in >> oxy.x >> oxy.y;
	return in;
}
ostream& operator<<(ostream& out, Oxy oxy) {
	out << '(' << oxy.x << ',' << oxy.y << ')';
	return out;
}
bool operator<(Oxy o1, Oxy o2) {
	return (o1.x < o2.x) || (o1.x == o2.x && o1.y < o2.y);
}
float operator-(Oxy o1, Oxy o2) {
	return sqrt(pow((o1.x - o2.x), 2)+ pow((o1.y - o2.y), 2));
}
istream& operator>>(istream& in, Oxyz& oxy) {
	in >> oxy.x >> oxy.y >> oxy.z;
	return in;
}
ostream& operator<<(ostream& out, Oxyz oxy) {
	out << '(' << oxy.x << ',' << oxy.y << ',' << oxy.z << ')';
	return out;
}
bool operator<(Oxyz o1, Oxyz o2) {
	return (o1.x < o2.x) || (o1.x == o2.x && o1.y < o2.y) || (o1.x == o2.x && o1.y == o2.y && o1.z < o2.z);
}
float operator-(Oxyz o1, Oxyz o2) {
	return sqrt(pow((o1.x - o2.x), 2) + pow((o1.y - o2.y), 2) + pow((o1.z - o2.z), 2));
}
template <typename T>
istream& operator>>(istream& in, Mang<T>& m) {
	T p;
	while (cin>>p)
	{
		m[m.spt++] = p;
	}
	return in;
}
template <typename T>
ostream& operator<<(ostream& out, Mang<T> m) {
	for (int i = 0; i < m.spt; i++)
	{
		cout << m[i] << ' ';
	}
	return out;
}
template <typename T>
float timMax(Mang<T> m) {
	float imax = m[0] - m[1];
	for (int  i = 0; i < m.spt; i++)
	{
		for (int  j = 1; j < m.spt; j++)
		{
			if ((m[i] - m[j]) > imax) {
				imax = m[i] - m[j];
			}
		}
	}
	return roundf(imax * 1000) / 1000;
}
template <typename T>
Mang<T> sapXepTangDan(Mang<T>& m) {
	for (int i = 0; i < m.spt; i++)
	{
		for (int j =i+ 1; j < m.spt; j++)
		{
			if (m[j] < m[i])
			{
				T tem = m[i];
				m[i] = m[j];
				m[j] = tem;
			}
		}
	}
	return m;
}
template <typename T>
Mang<T> sapXepGiamDan(Mang<T>& m) {
	for (int i = 0; i < m.spt; i++)
	{
		for (int j = i + 1; j < m.spt; j++)
		{
			if (m[i] < m[j])
			{
				T tem = m[i];
				m[i] = m[j];
				m[j] = tem;
			}
		}
	}
	return m;
}


///////////////////////////
//TEMPLATEHCN
/*
Xây dựng 1 cấu trúc mảng có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra số nhỏ nhất và tổng của các dãy số đó ra màn hình.
Với các qui ước:
-  Kiểu N: là số nguyên ( <=1000)
-  Kiểu H: là hình chữ nhật (được mô tả ở đây)
Dữ liệu đầu vào:
- Dòng đầu tiên: nhập vào loại kiểu của dãy số (kiểu a hoặc b)
- Các dòng còn lại, mỗi dòng chứa 1 số thuộc kiểu của dòng đầu tiên
Dữ liệu đầu ra:
-          Dòng 1: số nhỏ nhất (thuộc kiểu đã cho).
-          Dòng 2: tổng của dãy số.
Lưu ý:  
-          Nếu kết quả là hình chữ nhật thì tổng dãy chỉ lấy chính xác 1 chữ số thập phân.
-          Số lượng phần tử của dãy <= 100
 
Ví dụ 1:
Input:
N
1
2
3
4
Output:
          1
          10
Ví dụ 2:
Input:
H
1 2
2 3
3 4
4 5
Output:
          [HCN] 1,2
          48.0

*/

#include <iostream>
#include <iomanip>
using namespace std;
struct HCN
{
	float dai, rong;

};
istream& operator>>(istream& in, HCN& hcn) {
	in >> hcn.dai >> hcn.rong;
	return in;
}
ostream& operator<<(ostream& out, HCN hcn) {
	out << "[HCN] " << hcn.dai << ',' << hcn.rong;
	return out;
}
float chuVi(HCN h) {
	return (h.dai + h.rong) * 2;
}
float operator+(float k, HCN h) {
	return chuVi(h) + k;
}
float operator+(HCN k, HCN h) {
	return chuVi(h) + chuVi(k);
}

bool operator<(HCN h1, HCN h2) {
	return chuVi(h1) < chuVi(h2);
}
template <typename T>
struct Mang
{
	int spt;
	T a[100];
	T& operator[](int i) {
		return a[i];
	}
	Mang() {
		spt = 0;
	}
};
template <typename T>
istream& operator>>(istream& in, Mang<T>& m) {
	T a;
	while (cin >> a)
	{
		m[m.spt++] = a;
	}
	return in;
}
template <typename T>
ostream& operator<<(ostream& out, Mang<T> m) {
	for (int i = 0; i < m.spt; i++)
	{
		cout << m[i] << ' ';
	}
	return out;
}
template <typename T>
float tinhTong(Mang<T> m) {
	float kq = 0;
	for (int i = 0; i < m.spt; i++)
	{
		kq = kq + m[i];
	}
	return kq;
}
template <typename T>
T timMin(Mang<T> m) {
	int imin = 0;
	for (int i = 0; i < m.spt; i++)
	{
		if (m[i] < m[imin])
		{
			imin = i;
		}
	}
	return m[imin];
}
int main() {
	char kt;
	cin >> kt;

	if (kt == 'N')
	{
		Mang<int> m;
		cin >> m;
		cout << timMin<int>(m) << endl;
		cout << tinhTong<int>(m);
	}
	else if (kt == 'H')
	{
		Mang<HCN> m;
		cin >> m;
		cout << timMin<HCN>(m) << endl;
		cout << setprecision(1) << fixed << tinhTong<HCN>(m);
	}
	return 0;
}


//////////////////////////////
//DATE
/*
Ngày Tháng Năm 
 
Xây dựng cấu trúc để biểu diễn ngày ,tháng, năm (kiểu số nguyên và phải hợp lệ) 
 
Viết quá tải toán tử nhập ( >> ) ,xuất ( << ) (có kiểm tra tính hợp lệ hiện thị ra màn hình dạng MM/DD/YYYY) 
Viết hàm kiểm tra năm nhuận khi biết ngày tháng năm (ngày 15/01/2016 thuộc năm nhuận )
viết hàm tìm ngày thứ mấy trong năm khi biết ngày tháng năm (VD: ngày 15/01/2016 là ngày thứ 15 trong năm 2016)
viết hàm xác định thứ trong tuần khi biết ngày tháng năm (16/05/2016 là thứ 2 )
viết hàm tìm ngày kế tiếp khi biết ngày tháng năm (VD: 15/05/2016 ngày kế tiếp là 16/05/2016)
viết quá tải toán tử so sánh bằng ( == )  để so sánh 2 ngày trùng nhau (VD: 17/05/2011 == 17/05/2011 )
viết hàm kiểm tra xem 2 ngày có trùng thứ trong tuần không (VD : 16/05/2016 trùng thứ với 09/05/2016 vì cùng là thứ 2)
viết quá tải so sánh nhỏ hơn ( < ) để so sánh ngày nào nhỏ hơn (VD: 15/05/2013 < 02/07/2013)
viết quá tải so sánh trừ ( - ) để tính số ngày giữa 2 ngày (VD: 15/05/2015 đến ngày 20/05/2015 cách nhau 5 ngày ) 
gợi ý : cách tính thứ của ngày trong năm :
nếu tháng của ngày đó nhỏ hơn 3 thì biến đổi tháng = tháng + 12 , năm  = năm - 1 ,nếu tháng của ngày đó lớn hơn 2 thì giữ nguyên ,sau đó thế vào CT : 
n = (ngày+2*tháng+(3*(tháng+1)) / 5 + năm + (năm / 4)) % 7 
với n = 0 là Chủ Nhật, n = 1 là thứ 2 , n = 3 là thứ 3,.....
 
dữ liệu nhập: 
dòng 1: ngày thứ 1, có dạng DD MM YYYY
dòng 2: ngày thứ 2, có dạng DD MM YYYY
 
dữ liệu xuất: 
dòng 1: xuất ra ngày 1 ,thuộc  thứ mấy trong trong tuần, ngày thứ mấy trong năm, ngày kế tiếp,  nếu ngày 1 là năm nhuân in ra "TRUE", ngược lại in ra "FALSE", 
dòng 2: xuất ra ngày 2 ,thuộc  thứ mấy trong trong tuần, ngày thứ mấy trong năm, ngày kế tiếp, nếu ngày 2 là năm nhuân in ra "TRUE", ngược lại in ra "FALSE",
dòng 3: nếu ngày 1 và 2 có thứ trong tuần trùng nhau thì in ra "TRUE" ,ngược lại in ra "FALSE"
dòng 4: nếu ngày 1 nhỏ hơn ngày 2 thì in ra "1 < 2", nếu ngày 1 trùng ngày 2 in ra "1 = 2", nếu ngày 1 lớn hơn ngày 2 in ra "1 > 2"
dòng 5: số ngày giữa ngày 1 và ngày 2
lưu ý : 
Chủ Nhật - xuất ra "Sunday"
Thứ 2 - xuất ra "Monday"
Thứ 3 - xuất ra "Tuesday"
Thứ 4 - xuất ra "Wednesday"
Thứ 5 - xuất ra "Thursday"
Thứ 6 - xuất ra "Friday"
Thứ 7 - xuất ra "Saturday"

Ví dụ:

Input
Output
17 05 2016
05 05 2015
17/05/2016 Tuesday 138 18/05/2016 TRUE
05/05/2015 Tuesday 125 06/05/2015 FALSE
TRUE
1 > 2
378

*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

struct Date {
	int day, month, year;
	void operator = (Date dt) {
		day = dt.day;
		month = dt.month;
		year = dt.year;
	}
	Date() {
		day = month = year = 1;
	}
};


istream& operator >> (istream& is, Date& dt);
ostream& operator << (ostream& out, Date dt);
bool isLeap(Date dt);
int cntDay(Date dt);
string dayOfTheWeek(Date dt);
Date nextDate(Date dt);
bool operator == (Date dt1, Date dt2);
bool coincidentDayOfTheWeek(Date dt1, Date dt2);
bool operator < (Date dt1, Date dt2);
int operator - (Date dt1, Date dt2);

int main() {
	//ifstream ifile("DATE.inp");
	Date dt1, dt2;
	cin >> dt1 >> dt2;
	//ifile.close();
	//ofstream ofile("DATE.out");
	cout << dt1 << " " << dayOfTheWeek(dt1) << " " << cntDay(dt1) << " " << nextDate(dt1) << " ";
	if (isLeap(dt1)) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
	cout << dt2 << " " << dayOfTheWeek(dt2) << " " << cntDay(dt2) << " " << nextDate(dt2) << " ";
	if (isLeap(dt2)) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
	if (coincidentDayOfTheWeek(dt1, dt2)) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
	if (dt1 < dt2) cout << "1 < 2" << endl;
	else if (dt1 == dt2) cout << "1 = 2" << endl;
	else cout << "1 > 2" << endl;
	cout << dt1 - dt2;
	//ofile.close();
	return 0;
}

istream& operator >> (istream& is, Date& dt) {
	do {
		is >> dt.day >> dt.month >> dt.year;
	} while (dt.day <= 0 || dt.day > 31 || dt.month <= 0 || dt.month > 12 || dt.year <= 0);
	return is;
}
ostream& operator << (ostream& out, Date dt) {
	if (dt.day < 10) out << "0" << dt.day;
	else out << dt.day;
	out << "/";
	if (dt.month < 10) out << "0" << dt.month;
	else out << dt.month;
	out << "/";
	//if (dt.year < 10) os << "000" << dt.year;
	//else if (dt.year < 100) os << "00" << dt.year;
	//else if (dt.year < 1000) os << "000" << dt.year;
	out << dt.year;
	return out;
}
bool isLeap(Date dt) {
	return ((dt.year % 4 == 0) && (dt.year % 100 != 0)) || (dt.year % 400 == 0);
}
int cntDay(Date dt) {
	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int res = 0;
	if (isLeap(dt)) day[2] = 29;
	for (int i = 1; i < dt.month; i++) {
		res += day[i];
	}
	res += dt.day;
	return res;
}
string dayOfTheWeek(Date dt) {
	if (dt.month < 3) {
		dt.month += 12;
		dt.year--;
	}
	int n = (dt.day + 2 * dt.month + (3 * (dt.month + 1)) / 5 + dt.year + (dt.year / 4)) % 7;
	if (n == 0) return "Sunday";
	else if (n == 1) return "Monday";
	else if (n == 2) return "Tuesday";
	else if (n == 3) return "Wednesday";
	else if (n == 4) return "Thursday";
	else if (n == 5) return "Friday";
	else if (n == 6) return "Saturday";
	return "";
}
Date nextDate(Date dt) {
	Date res;
	dt.day++;
	switch (dt.day) {
		case 32: {
			dt.day = 1;
			if (dt.month == 12) {
				dt.month = 1;
				dt.year++;
			}
			else dt.month++;
			break;
		}
		case 31: {
			switch (dt.month) {
			case 4: case 6: case 9: case 11: {
				dt.day = 1;
				dt.month++;
				break;
			}
			default:
				break;
			}
			break;
		}
		case 30: {
			if (dt.month == 2 && isLeap(dt)) {
				dt.day = 1;
				dt.month = 3;
			}
			break;
		}
		case 29: {
			if (dt.month == 2 && !isLeap(dt)) {
				dt.day = 1;
				dt.month = 3;
			}
			break;
		}
	}
	res.day = dt.day;
	res.month = dt.month;
	res.year = dt.year;
	return res;
}
bool operator == (Date dt1, Date dt2) {
	return (dt1.day == dt2.day) && (dt1.month == dt2.month) && (dt1.year == dt2.year);
}
bool coincidentDayOfTheWeek(Date dt1, Date dt2) {
	return dayOfTheWeek(dt1) == dayOfTheWeek(dt2);
}
bool operator < (Date dt1, Date dt2) {
	if (dt1.year == dt2.year) {
		if (dt1.month == dt2.month) {
			if (dt1.day < dt2.day) return true;
			else return false;
		}
		else if (dt1.month < dt2.month) return true;
		else return false;
	}
	else if (dt1.year < dt2.year) {
		return true;
	}
	else return false;
}
int operator - (Date dt1, Date dt2) {
	if (dt1.year == dt2.year) return abs(dt1.year - dt2.year);
	else {
		Date tmp, tmp1;
		tmp = (dt1.year < dt2.year) ? dt1 : dt2;
		tmp1 = (dt1.year < dt2.year) ? dt2 : dt1;
		int res = 365 - cntDay(tmp);
		if (isLeap(tmp)) {
			res++;
		}
		tmp.year++;
		while (tmp.year < dt2.year || tmp.year < dt1.year) {
			res += 365;
			if (isLeap(tmp)) {
				res++;
			}
			tmp.year++;
		}
		if (tmp.year == tmp1.year) {
			res += cntDay(tmp1);
		}
		return res;
	}
}


/////
//SoDao
/*
Yêu cầu 1:
Xây dựng cấu trúc SoDao (Số Đảo) biểu diễn một cấu trúc mới gồm 1 thành phần:
-  Một số tự nhiên có 3 chữ số.
Yêu cầu xây dựng các hàm sau:
1. Quá tải nhập và xuất SoDao (xem ví dụ để hiểu rõ hơn cách xuất 1 SoDao)
2. Viết hàm trả về số đảo ngược của SoDao (bằng cách trả về số ngược ).
3. Quá tải so sánh > hai SoDao: giá trị đảo ngược (giá trị đảo ngược của SoDao nào lớn hơn thì sẽ xác định số đó là số lớn hơn)
4. Quá tải cộng + với tham số là 1 SoDao và 1 số nguyên, nội dung hàm là lấy giá trị đảo ngược của SoDao cộng với số nguyên đó, kết trả về của hàm là 1 số nguyên.
Yêu cầu 2:
Sử dụng cấu trúc ở trên, giải bài tập với các yêu cầu sau:
Input:
Gồm 2 dòng, mỗi dòng chứa 1 số tự nhiên có 3 chữ số đại diện cho số SoDao (Dữ liệu đầu vào đảm bảo mỗi dòng chứa 1 số tự nhiên có 3 chữ số).
Output:
-   Dòng 1: Xuất thông tin của SoDao 1
-   Dòng 2: Xuất thông tin của SoDao 2
-   Dòng 3: xuất chữ “YES” (không có dấu “ ) nếu SoDao 1 > SoDao 2, ngược lại xuất “NO” (không có dấu “ )
-   Dòng 4: Xuất tổng SoDao 1 và SoDao 2
(Sử dụng toán tử + được mô tả ở trên, HD: lấy SoDao 1 cộng với số 0, sau đó lấy kết quả cộng với SoDao 2)     	           
 
Ví dụ:
Input
Output
127
456
[SoDao] 127
[SoDao] 456
YES
1375

*/


#include<iostream>
#include<cmath>
using namespace std;

struct SoDao
{
    int n;  
};
istream& operator >> (istream& in,SoDao &sd);
ostream& operator << (ostream& out,SoDao sd);
int SoDaoNguoc(SoDao sd);
bool operator > (SoDao sd1,SoDao sd2);
int operator + (SoDao sd,int n);


int main(){
    SoDao a,b;
    cin>>a>>b;
    cout<<a<<endl;
    cout<<b<<endl;
    if(a>b)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    cout<< (b+(a+ 0));
    return 0;
}

istream& operator >> (istream& in,SoDao &sd)
{
    in>>sd.n;
    return in;
}
ostream& operator << (ostream& out,SoDao sd)
{
    out<<"[SoDao] "<<sd.n;
    return out;
}
int SoDaoNguoc(SoDao sd)
{
    int tam,gan = 0;
    while(sd.n != 0){
        tam = sd.n%10;
        gan = gan*10 + tam;
        sd.n/=10;
    }
    return gan;
}
bool operator > (SoDao sd1,SoDao sd2)
{
    return (SoDaoNguoc(sd1) > SoDaoNguoc(sd2));  
}
int operator + (SoDao sd,int n)
{
    return(SoDaoNguoc(sd) + n);
}



///////////////////////////////
//TemplateSoMoi
// khuon hinh so moi
/*
Xây dựng 1 cấu trúc mảng có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra số lớn nhất, số lượng số lớn nhất có trong dãy và tổng của các dãy số đó ra màn hình.
Với các qui ước:
- 	Kiểu N: là số nguyên ( <=1000)
- 	Kiểu M: là SoMoi (được mô tả ở đây)
Dữ liệu đầu vào:
- Dòng đầu tiên: nhập vào loại kiểu của dãy số (kiểu N hoặc M)
- Các dòng còn lại, mỗi dòng chứa 1 số thuộc kiểu của dòng đầu tiên
Dữ liệu đầu ra:
-          Dòng 1: số lớn nhất (thuộc kiểu đã cho).
-          Dòng 2: Xuất số lượng số lớn nhất có trong dãy.
-          Dòng 2: tổng của dãy số.
Lưu ý:  
-          Số lượng phần tử của dãy <= 1000
 
Ví dụ 1:
Input:
N
1
4
3
4
Output:
          4
          2
          12
Ví dụ 2:
Input:
M
12
23
Output:
[SoMoi] 23
1
[SoMoi]8



*/
#include <iostream>
#include <stdio.h>
using namespace std;
struct somoi {
	int a;
};
template<class L>
struct Khuonhinh {
	L so;
};
istream& operator>>(istream& cin, somoi &p) {
	cin >> p.a;
	return cin;
}
ostream& operator<<(ostream& cout, somoi p) {
	cout << "[SoMoi] " << p.a;
	return cout;
}
int congchuso(somoi p1) {
	int tong = 0,m;
	while (p1.a != 0) {
		m=p1.a % 10;
		tong += m;
		p1.a /= 10;
	}
	return tong;
}
somoi operator >(somoi p1, somoi p2) {
	if (p1.a > p2.a)
		return p1;
	else return p2;
}

int operator +(somoi p1, int t) {
	return congchuso(p1) + t;
}
int main()
{
	char kitu;
	cin >> kitu;
	if (kitu == 'N') {
		Khuonhinh<int> p;
		int tong = 0, a[100]; int i = 0,dsl=0;	//dsl dem so lon
		int gan = 0;
		while (cin >> p.so) {
			a[i] = p.so;
			tong = a[i] + tong;
			if (a[i] > gan) gan = a[i];
			i++;
		}
		for (int j = 0; j < i; j++) {
			if (gan == a[j]) dsl++;
		}
		cout << gan << endl <<dsl<<endl<< tong;
	}
	if (kitu == 'M') {
		Khuonhinh<somoi> p;
		int i = 0, dsl = 0;	//dsl dem so lon
		somoi a[100], gan; gan.a = 0; int tong = 0;
		while (cin >> p.so) {
			a[i] = p.so;
			tong = a[i] + tong;
			gan = a[i] > gan;
			i++;
		}
		for (int j = 0; j < i; j++) {
			if (gan.a == a[j].a) dsl++;
		}
		cout << gan << endl << dsl << endl <<"[SoMoi] "<< tong;
	}
}
------------------------------------------
#include<iostream>
using namespace std;

struct Somoi{
    long n;
    void operator = (int a){
        n=a;
    };
};
template<typename T>
struct Mang {
    int spt;
    T mg[100];
};

istream & operator >>(istream & in, Somoi &a);
ostream & operator << (ostream & out, Somoi a);
int Congcs (Somoi a);
bool operator < (Somoi a,Somoi b);
bool operator == (Somoi a,Somoi b);
Somoi operator +(Somoi a,Somoi b);
    template<typename T>
istream & operator >>(istream & in, Mang<T> &a);
    template<typename T>
T soMax (Mang<T> a);
    template<typename T>
int Dem(Mang<T> a); 
    template<typename T>
T congMang(Mang<T> a);

int main (){
    char x;
    cin>>x;
    if (x=='N') {
        Mang<int> m1;
        cin>>m1;
        cout<<soMax<int>(m1)<<endl;
        cout<<Dem<int>(m1)<<endl;
        cout<<congMang(m1);
    }
    else if (x=='M'){
        Mang<Somoi> m2;
        cin>>m2;
        cout<<soMax<Somoi>(m2)<<endl;
        cout<<Dem<Somoi>(m2)<<endl;
        cout<<congMang(m2);
    }
}
istream & operator >>(istream & in, Somoi &a){
    in>>a.n;
    return in;
};
ostream & operator << (ostream & out, Somoi a){
    out<<"["<<"SoMoi"<<"]"<<" "<<a.n;
    return out;
};
int Congcs (Somoi k){
    long m=k.n;
    int kq=0;
    int p[100],dem=0;
    long n;
    while(m!=0){
        n=m%10;
        p[dem]=n;
        m=m/10;
        ++dem;
    };
    for (int i=0;i<dem;++i){
        kq=kq+p[i];
    }
    return kq;
};
bool operator < (Somoi a,Somoi b){
    if (a.n<b.n) return true;
    else return false;
};
bool operator == (Somoi a,Somoi b){
    if (a.n==b.n) return true;
    else return false;
};
Somoi operator + (Somoi a,Somoi b){
    Somoi kq;
    kq.n=Congcs(a)+Congcs(b);
    return kq;
};
template<typename T>
istream & operator >>(istream & in, Mang<T> &a){
    T n;
    a.spt=0;
    while(in>>n){
        a.mg[a.spt]=n;
        ++a.spt;
    }
};
template<typename T>
T soMax (Mang<T> a){
    T max=a.mg[0];
    for (int i=1;i<a.spt;++i){
        if(max<a.mg[i])max=a.mg[i];
    }
    return max;
};
template<typename T>
int Dem(Mang<T> a){
    int dem=0;
    T max=soMax(a);
    for (int i=0;i<a.spt;++i){
        if(max==a.mg[i])++dem;
    }
    return dem;
}; 
template<typename T>
T congMang (Mang<T> a){
    T kq;
    kq= 0;
    for (int i=0;i<a.spt;++i){
        kq=kq+a.mg[i];
    }
    return kq;
};



//////////////////////////////////////////////
//LOGIN_UP
/*
Tèo đam mê lập trình. Cậu ấy rất siêng năng luyện tập và rất muốn vào trang upcoder.xyz - hệ thống chấm bài tự động để làm bài tập.
Tuy nhiên hiện tại hệ thống upcoder.xyz bị một số người phá hoại bằng cách tấn công DDOS.
Để chống lại điều này, hệ thống yêu cầu mọi người phải nhập một xâu kí tự bất kì, xâu này chỉ gồm các chữ cái từ 'a'...'z', không chứa ký tự trắng. Sao cho khi xóa đi một số chữ cái nào đó thì xâu đó trở thành "upcoder". Tất nhiên là không được tráo đổi vị trí các chữ cái, mà chỉ được xóa bớt đi một số chữ cái.
 
Ví dụ Tèo muốn vào trang upcoder.xyz để làm bài. Sau khi gõ địa chỉ trang web, hệ thống thông báo Tèo nhập vào một xâu ký tự. Tèo gõ: "ahihiupcccccodeeeerrr", hệ thống sẽ xem xét xâu này và tự động loại bỏ các chữ cái để trở thành từ "upcoder". Như vậy Tèo vào được hệ thống để làm bài.
 
Nhưng khi Tèo gõ: "uppdcoer", hệ thống không thể làm cách nào để xóa bớt chữ cái để trở thành từ "upcoder" được. Như vậy Tèo không vào được hệ thống.
 
Nhiệm vụ của bạn là xác định xem, khi Tèo gõ một xâu, xâu đó có được chấp nhận để Tèo vào hệ thống làm bài hay không?
 
Input:
Một dòng chứa xâu chữ cái mà Tèo định gõ, với chiều dài từ 1 đến 100 ký tự.
Output:
Nếu Tèo được đồng ý vào hệ thống, xuất "YES", ngược lại xuất "NO" (không xuất dấu ngoặc kép).
 
Ví dụ:
Input:
ahihiupcccccodeeeerrr
Output:
YES
Input:
uppdcoer
Output:
NO
Input:
upxyzcccccteoder
Output:
YES

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int s1, s2, s3, s4, s5, s6, s7;
    s1 = s.find('u',0);
    s2 = s.find('p',s1);
    s3 = s.find('c',s2);
    s4 = s.find('o',s3);
    s5 = s.find('d',s4);
    s6 = s.find('e',s5);
    s7 = s.find('r',s6);
    if(s1 < s2 && s2 < s3 && s3 < s4 && s4 < s5 && s5 < s6 && s6 < s7)  cout << "YES";
    else cout << "NO";
    return 0;
}

////////////////////////////////////////////////
//time
/*
Yêu cầu xây dựng cấu trúc Time biểu diễn thời gian theo định dạng:
giờ : phút: giây
(0<=giờ<24, 0<=phút<59, 0<=giây<59)
Bên cạnh đó xây dựng các hàm sau cho cấu trúc trên:
1. Quá tải toán tử nhập (HD: nhập vào gồm 3 số nguyên (tương ứng là giờ, phút, giây), mỗi số nguyên là 1 dòng, xem ví dụ để hiểu rõ hơn)
2. Quá tải toán tử xuất (HD: xuất ra theo định dạng giờ:phút:giây)
3. Viết hàm đặt tên là timestamp mục đích đổi 1 biến cấu trúc Time sang giây (HD: 1 giờ = 60 phút, 1 phút = 60 giây)
Ví dụ:
 	1:0:0  đổi sang được 3600 giây
3. Quá tải toán tử so sánh < hai số ở Time, nếu timestamp của số 1 < timestamp của số 2
4. Quá tải toán tử cộng + hai số Time với nhau, kết quả trả về là Time (cộng tương ứng giờ, phút, giây).
5. Quá tải toán tử cộng + một số ở Time với một số nguyên dương (tượng trưng cho giây), kết quả trả về 1 số nguyên (HD: dùng hàm timestamp đổi Time ra giây rồi cộng với số nguyên dương).
Yêu cầu 2:
Sử dụng cấu trúc ở trên, giải bài tập với các yêu cầu sau:
Input:
3 dòng đầu chứa giờ phút giây của số Time 1
3 dòng sau chứa giờ phút giây của số Time 2
Output:
- Dòng 1: Xuất số Time 1
- Dòng 2: Xuất số Time 2
- Dòng 3: Xuất timestamp của Time 1
- Dòng 4: Xuất timestamp của Time 2
- Dòng 5: Xuất chữ “true” (không có dấu “ ) nếu Time 1 < Số Time 2, ngược lại xuất “false” (không có dẫu “ )
 

*/
#include<iostream>
using namespace std;
struct timet
{
  int gio, phut, giay;  
};

istream &operator >>(istream &is, timet &t)
{
    is>>t.gio>>t.phut>>t.giay;
    return is;
}
ostream &operator <<(ostream &os, timet t)
{
    os<<t.gio<<":"<<t.phut<<":"<<t.giay;
    return os;
}
int timestamp (timet t)
{
    if((t.gio==1)&&(t.phut==0)&&(t.giay==0))
    {
        return t.gio*3600;
    }
    else
    { return t.gio*3600+t.giay+t.phut*60;}
}
bool operator < (timet t1, timet t2)
{
    if(timestamp(t1)<timestamp(t2))
    return true;
    else
    {return false;}
}
int operator +(int n, timet t)
{
    return n+ timestamp(t);
}
timet operator + (timet t1, timet t2)
{
    return t1+t2;
}
int main()
{
    timet t1,t2;
    cin>>t1>>t2;
    cout<<t1<<endl;
    cout<<t2<<endl;
    cout<<timestamp(t1)<<endl;
    cout<<timestamp(t2)<<endl;
    if(t1<t2)
    cout<<"true";
    else 
    cout<<"false";
    return 0;
}


////////////////////////////////
/*
Xây dựng 1 cấu trúc mảng có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra số lớn nhất và tổng của dãy số tương ứng ra màn hình.
Với các qui ước:
- Kiểu T: là số Time (được định nghĩa tại câu 1)
- Kiểu N: là một số nguyên ở hệ 10
Dữ liệu đầu vào:
Gồm nhiều dòng, mỗi dòng là gồm chứa 2 thông tin: : [kiểu]  [số] (xem ví dụ để hiểu rõ hơn) 
(Lưu ý: mỗi số kiểu T nhập trên 1 hàng gồm 3 số nguyên)
Dữ liệu đầu ra:
-  Dòng 1:  số lớn nhất của số Time.
-  Dòng 2: tổng của tất cả số Time
-  Dòng 3: số lớn nhất của số nguyên hệ 10.
-  Dòng 4: Tổng của tất cả số hệ 10
(nếu dòng nào không có tìm thấy kết quả thì xuất ra chữ “khong co” (không có dấu “)
Lưu ý:  
-  Số lượng phần tử của dãy <= 100

Ví dụ 1:

Input
Output
N 1
T 1 0 0
N 2
T 1 0 1
1:0:1
7201
2
3



 
Ví dụ 2:

Input
Output
N 1
N 2
khong co
khong co
2
3



*/

#include <bits/stdc++.h>
using namespace std;

struct TG{
    int h,m,s;
    
    TG(){
        h=0;   m=0;   s=0;
    }
};    
    istream& operator>>(istream &in, TG &t){
        in>>t.h>>t.m>>t.s;
        return in;
    }
     ostream &operator<<(ostream &ou, TG t){
        ou<<t.h<<":"<<t.m<<":"<<t.s<<endl;
    }
    bool operator<(TG t1, TG t2){
        return (t1.h*3600+t1.m*60+t1.s<t2.h*3600+t2.m*60+t2.s);
    }
     TG operator+(TG t1, TG t2){
        TG t;
        int x=t1.h*3600+t1.m*60+t1.s+t2.h*3600+t2.m*60+t2.s;
        t.s=x%60; x/=60;
        t.m=x%60; t.h=x/60;
        return t;
    }
     TG operator+(TG t1, int s){
        TG t;
        int x=t1.h*3600+t1.m*60+t1.s+s;
        t.s=x%60; x/=60;
        t.m=x%60; t.h=x/60;
        return t;
    }
    
    

long timell(TG t1){
        return (t1.h*3600+t1.m*60+t1.s);
    }
int main(){
    TG t,max,tong;
    long n=0, maxn=0, tongn=0;
    char c;
    while(cin>>c){
        if(c=='T'){
            cin>>t;
            if(max<t) max=t;
            tong=tong+t;
        }
        else if(c=='N'){
            cin>>n;
            if(maxn<n) maxn=n;
            tongn=tongn+n;
        }
    }
    if(t.h==0&&t.m==0&&t.s==0) {
        cout<<"khong co"<<endl;
        cout<<"khong co"<<endl;
        cout<<maxn<<endl<<tongn;
    }
    else if(n==0&&maxn==0&&tongn==0) {
        cout<<max<<timell(tong)<<endl;
        cout<<"khong co"<<endl;
        cout<<"khong co"<<endl;
    }
    else { 
        cout<<max<<timell(tong)<<endl;
        cout<<maxn<<endl<<tongn;
    }
    /*cin>>t1>>t2;
    cout<<t1<<t2;
    cout<<timell(t1)<<endl;
    cout<<timell(t2)<<endl;
    if(t1<t2) cout<<"true";
    else cout<<"false";*/
    
}
/////////////////////////////////
#include<iostream>

using namespace std;
struct thoigian
{
	int gio, phut, giay;
	thoigian() {
		gio = 0;
		phut = 0;
		giay = 0;
	}
};
istream& operator >> (istream& in, thoigian& t)
{
	in >> t.gio >> t.phut >> t.giay;
	return in;
}
ostream& operator <<(ostream& os, thoigian t)
{
	os << t.gio << ":" << t.phut << ":" << t.giay;
	return os;
}
int doiTG(thoigian t)
{
	return t.gio * 3600 + t.phut * 60 + t.giay;
}
bool operator < (thoigian t1, thoigian t2)
{
	if (doiTG(t1) < doiTG(t2))
		return true;
	else
		return false;
}
thoigian operator + (thoigian t1, thoigian t2)
{
	thoigian kq;
	kq.gio = t1.gio + t2.gio;
	kq.phut = t1.phut + t2.phut;
	kq.giay = t1.giay + t2.giay;
	return kq;
}
int operator + (thoigian t, int n)
{
	return doiTG(t) + n;
}
int main()
{
	thoigian t, maxT, tongT;
	int n = 0, maxN=0, tongN=0;
	char k;
	while (cin >> k)
	{
		if (k == 'T')
		{
			cin >> t;
			if (maxT < t) maxT = t;
			tongT = tongT + t;
		}
		if (k == 'N')
		{
			cin >> n;
			if (maxN < n) maxN = n;
			tongN = tongN + n;
		}
	}
	if (t.gio == 0 && t.phut == 0 && t.giay == 0)
	{
		cout << "khongco" << endl << "khongco" << endl;
		cout << maxN << endl << tongN;
	}
	else
		if (n == 0 && maxN == 0 && tongN == 0)
		{
			cout << maxT << endl << doiTG(tongT) << endl;
			cout << "khongco" << endl << "khongco" << endl;
		}
		else
		{
			cout << maxT << endl << doiTG(tongT) << endl;
			cout << maxN << endl << tongN << endl;
		}
	return 0;
}

///////////////////////
//DATHUC
/*
Xây dựng cấu trúc BacNhat biểu diễn một đa thức bậc 1 có dạng ax+b, trong đó a,b là số nguyên
 
Yêu cầu 1:
a) Xây dựng cấu trúc trên.
b) Viết quả tải toán tử nhập và xuất cho cấu trúc trên (nhập hệ số a,b)
c) Viết hàm tính giá trị của BacNhat với giá trị x cụ thể
ví dụ: với F(x) =  2x + 3 và x = 2;
               F(2) =   2*2 + 3 =  4 +3 =7
d) Hãy cài đặt hàm quá tải toán tử cộng 2 BacNhat bằng cách cộng từng hệ số với nhau, kết quả trả về 1 BacNhat.
ví dụ: 
F1(x) = 2x + 3
F2(x) = 5x + 6
=> Tong(x) = 7x + 9
e) hãy cài đặt quá tải toán tử so sánh bằng, so sánh 2 BacNhat bằng xét tổng 2 hệ số a+b
ví dụ:
F1(x) = 2x + 3
F2(x) = 5x + 6
F1 không bằng F2, vì 2 + 3 != 5+6
 
Yêu cầu 2:
Viết chương trình nhập vào theo cấu trúc sau
- Dòng 1 là 2 hệ số của 1 BacNhat  F1
- Dòng 2 là 2 hệ số của 1 BacNhat F2
- Dòng 3 là 1 số nguyên x0
 
Xuất kết quả theo cấu trúc sau:
- Dòng 1: xuất F1 (dạng đầy đủ ax+b)
- Dòng 2: xuất F2 (dạng đầy đủ ax+b)
- Dòng 3: xuất tổng F1 và F2 (xem cách xuất ở ví dụ bên dưới)
- Dòng 4: giá trị F1(x0)
- Dòng 5: giá trị F2(x0)
- Dòng 6: xuất TRUE nếu 2 BacNhat bằng nhau, ngược lại xuất FALSE
 
Ví dụ:
 
Input
Output
2 3
5 6
2
2x+3
5x+6
2x+3+5x+6=7x+9
7
16
FALSE

*/
#include<iostream>
using namespace std;

struct BacNhat
{
    int a,b;
};
istream & operator >> (istream &is, BacNhat& m)
{
    is>>m.a>>m.b;
    return is;
}
ostream & operator << (ostream &os, BacNhat m)
{
    os<<m.a<<"x+"<<m.b;
    return os;
}

BacNhat operator+ (BacNhat m, BacNhat n)
{
    BacNhat kq;
    kq.a=m.a+n.a;
    kq.b=m.b+n.b;
    return kq;
}
int GTBN (BacNhat m, int x)
{
    return (m.a*x+m.b);
}
bool operator == (BacNhat m, BacNhat n)
{
    if(m.a+m.b==n.a+n.b)
    return true;
    else
    return false;
}
bool operator != (BacNhat m, BacNhat n)
{
    return (m!=n);
}
int main()
{
    BacNhat f1, f2,s;
    int x;
    cin>>f1>>f2;
    cin>>x;
    s=f1+f2;
    cout<<f1<<endl;
    cout<<f2<<endl;
    cout<<f1<<"+"<<f2<<"="<<s<<endl;
    cout<<GTBN(f1,x)<<endl;
    cout<<GTBN(f2,x)<<endl;
    if(f1==f2)
    cout<<"TRUE";
    else
    cout<<"FALSE";
    return 0;
    
}

//////////////////////////////////////////////////
/*
Cho cấu trúc mảng 1 chiều.
yêu cầu xây dựng các hàm quá tải sau:
Nhập
Xuất.
Gán
Cộng
So sánh bằng
So sánh khác
Toán tử []
Viết một chương trình nhập vào 2 mảng 1 chiều, xuất "yes" nếu 2 mảng giống nhau, ngược lại xuất "no" nếu 2 mảng khác nhau.
Hướng dẫn nhập:
Dòng 1: nhập số lượng phần tử mảng thứ 1 (<=10)
Dòng 2: Nhập các phần tử của mảng thứ 1 (mỗi phần tử có giá trị <=100)
Dòng 3: nhập số lượng phần tử mảng thứ 2 (<=10)
Dòng 4: Nhập các phần tử của mảng thứ 2 (mỗi phần tử có giá trị <=100)
ví dụ:
input:
3
1 2 3
4
1 2 5 7
output:
no

*/
#include <iostream>

using namespace std;

struct mang {
    int a[100], n;
    int &operator[] (int i){
        return a[i];}
        void operator = (mang p){
            n=p.n;
            for(int i=0; i<p.n; i++)
            a[i] = p[i];
        }
    };

istream &operator >> (istream &in, mang &p);
ostream &operator << (ostream &out, mang &p);
bool operator ==(mang p1, mang p2);
bool operator !=(mang p1, mang p2);
int operator +(mang p);
istream &operator >> (istream &in, mang &p){
        in>>p.n;
        for(int i=0; i<p.n; i++)  in>>p[i];
        return in;
    }
    ostream &operator << (ostream &out, mang &p){
        out<<p.n<< endl;
        for(int i=0; i<p.n; i++)
        out<<p[i]<<' ';
        return out;
    }
    bool operator ==(mang p1, mang p2){
        if(p1.n != p2.n) return false;
         for (int i=0; i<p1.n; i++){
             if(p1[i]!=p2[i]) return false;
         }
         return true;
    }
    bool operator !=(mang p1, mang p2){
        return!(p1==p2);
    }
      int operator +(mang p){
      int s=0;
      for(int i=0; i<p.n; i++){
          s+=p.a[i];
      }
      return s;
  }  


int main()
{
    mang p1, p2;
    cin>> p1>> p2;
    if(p1==p2) 
      cout<< "yes";
      else cout<< "no";
    return 0;
}
///////////////////////////////////////////////////
/*
+Xây dựng cấu trúc PhanSo:
Viết quá tải toán tử: >>, <<, ==,!=,+
 
+ xây dựng cấu trúc mảng Phân số
viết quá tải toán tử: >>,<<,[].
 
viết ct nhập vào dãy phân số, yêu cầu xuất tổng phân số sau khi rút gọn
ví dụ:
1 2
2 3
3 4
 
output:
23/12

*/
#include <iostream>

using namespace std;

struct PhanSo
{
    int tu,mau;
};

struct MangPhanSo{
    int n;
    PhanSo ap[100];    
    MangPhanSo(){
        n = 0;
    }
    PhanSo& operator[](int i){
        return ap[i];
    }
};

istream& operator>>(istream& is, PhanSo & p);
ostream& operator<<(ostream& out, PhanSo  p);
bool operator==(PhanSo p1, PhanSo p2);
bool operator!=(PhanSo p1, PhanSo p2);
PhanSo operator+(PhanSo p1, PhanSo p2);
int UCLN(int a, int b);
PhanSo rutGon(PhanSo& p);
istream& operator>>(istream &is, MangPhanSo& m);
ostream& operator<<(ostream &out, MangPhanSo m);

int main(){
    MangPhanSo ap;
    cin>>ap;
   PhanSo p;
    p.tu = 0;
    p.mau = 1;
    for (int i=0;i<ap.n;++i)
        p= p+ ap[i];
    cout<<rutGon(p);
    
    return 0;
}

int UCLN(int a, int b){
    while (b!=0){
        int r = a % b;
        a = b;
        b = r;
    }    
    return a;
}

PhanSo rutGon(PhanSo& p){
    int d = UCLN(p.tu,p.mau);
    p.tu /= d;
    p.mau /= d;
    
    return p;
}

PhanSo operator+(PhanSo p1, PhanSo p2){
    PhanSo kq;
    kq.tu = p1.tu*p2.mau + p1.mau*p2.tu;
    kq.mau = p1.mau * p2.mau;
    return kq;
}
bool operator==(PhanSo p1, PhanSo p2){
    return p1.tu*p2.mau == p1.mau*p2.tu;
}
bool operator!=(PhanSo p1, PhanSo p2){
    return !(p1==p2);
}
istream& operator>>(istream& is, PhanSo & p){
    is>>p.tu>>p.mau;
    return is;
}
ostream& operator<<(ostream& out, PhanSo  p){
    out<<p.tu<<"/"<<p.mau;
    return out;
}
istream& operator>>(istream &is, MangPhanSo &m){
    PhanSo p;
    while (cin>>p){
        m[m.n++] = p;  
    }
    return is;
}
ostream& operator<<(ostream &out, MangPhanSo m){
    for (int i=0; i < m.n; ++i)
        out<<m[i]<<endl;
    return out;
}





    










/////////////////////////////////////////////////
///////////////////////////////////////////////////////
/*
Cho cấu trúc Phân số gồm tử và mẫu.
yêu cầu xây dựng các hàm quá tải sau:
Nhập
Xuất.
Gán
Cộng
So sánh bằng
So sánh khác
Viết một chương trình nhập vào 2 phân số, yêu cầu xuất như sau
xuất tổng 2 phân số (sau khi rút gọn)
ví dụ:
input:
1 2
2 4
output:
1/1

*/
#include <iostream>
using namespace std;
struct Phanso{
    int tu, mau;
};

istream &operator>>(istream &in, Phanso &p);
ostream &operator<<(ostream &out, Phanso &p);
Phanso operator + (Phanso p1, Phanso p2);
bool operator== (Phanso p1, Phanso p2);
bool operator != (Phanso p1, Phanso p2);
int UCLN(int a, int b);
Phanso rutgon(Phanso p);

int UCLN(int a, int b){
    if(b==0) return a;
    else
    return UCLN(b, a%b);
}
Phanso rutgon(Phanso p){
    int t;
    t=UCLN (p.tu, p.mau);
    p.tu/=t;
    p.mau/=t;
    return p;
}
istream &operator>>(istream &in, Phanso &p){
    in>> p.tu>>p.mau;
    return in;
}
ostream &operator<<(ostream &out, Phanso &p){
    out<< p.tu<<"/"<<p.mau;
    return out;
}
Phanso operator + (Phanso p1, Phanso p2){
    Phanso kq;
    kq.tu = p1.tu*p2.mau+p1.mau*p2.tu;
    kq.mau= p1.mau*p2.mau;
    return rutgon(kq);
}
bool operator== (Phanso p1, Phanso p2){
    return (p1.tu*p2.mau == p1.mau*p2.tu);
}
bool operator != (Phanso p1, Phanso p2){
    return (p1!=p2);
}
int main(){
Phanso p1, p2, tong;
cin>>p1>>p2;
tong = p1+p2;
cout<<tong;
    return 0;
}

////////////////////////////////////////////////////////////////////////////

/*
hien thi sl so chinh phuong co trong mang
yes neu thay k trong mang, no neu khong thay
sx mang khong phai scp tang dan
yêu cầu sử dụng mảng động con trỏ để thực hiện các yêu cầu sau
input: 
d1: số nguyên N (số lượng phần tử mảng) và số nguyên k
d2: N số nguyên liên tiếp cách nhau bởi 1 khoảng trắng cho biết các giá trị của mảng.
output:
d1: hiển thị số lượng các số chính phương có trong mảng
d2: hiển thị Yes nếu tìm thấy giá trị k trong mảng và No nếu không tìm thấy
d3: hiển thị mảng sau khi đã loại bỏ các số chính phương và sắp xếp theo thứ tự giá trị tăng dần, cách nhau 1 khoảng trắng.
vd:
input:
6 4
1 5 4 3 21 9
output:
3
Yes
3 5 21
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool ktscp(int n)
{
	int k = sqrt(n);
	if (k * k == n)
		return true;
	return false;
}

int main()
{
	int n, k;
	int a[100];
	int dem = 0;
	int kt;
	cin >> n;
	cin >> k;
	vector<int>b;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (ktscp(a[i])) // neu la scp se dem
			dem++;
		else 
			b.push_back(a[i]); // khong phai thi them ptu do vao vector
	}
	cout << dem << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == k)
			kt = true;
	}
	if (kt) { cout << "Yes" << endl; }
	else
		cout << "No" << endl;

	
	sort(b.begin(), b.end());
	for (int i = 0; i < b.size(); i++)
	{
		cout << b [i]<< " ";
	}
}


/////////////////////////////////////////////////////////////////////////////////////
/* ktra chuoi s1 co trong chuoi s2 khong va dem so lan xuat hien*/
// kiểm tra chuỗi s1 có trong chuỗi s2 không và đếm số lần xuất hiện
/*
viết chương trình nhập vào 2 chuỗi S1 độ dài N1 và S2 độ dài N2. hãy kiểm tra xem S1 có xuất hiện trong chuỗi S2 không? Nếu có hãy đếm số lần xuất hiện chuỗi S1 trong chuỗi S2.
input:
Chuỗi S1
Chuỗi S2
output:
FOUND nếu S1 có trong S2, ngược lại NOTFOUND
nếu FOUND thì xuất số lần xuất hiện
*/

#include <iostream>
#include <string>
using namespace std;


int main() {

	string s1, s2;
	int vitri, dem = 0;
	getline(cin, s1);
	getline(cin, s2);
	int v= s2.find(s1);
	while (v != -1) {
		
		dem++;
		v = s2.find(s1, v + 1);
	}
	if (dem > 0) {
		cout << "FOUND" << endl;
		cout << dem;
	}
	else
		cout << "NOT FOUND";
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
listen và sliten là anagram
input: 
listen
slite
output:
Yes
*/
//anagram
// listen va sliten la anagram
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if (s1.size() != s2.size())
	{
		cout << "No" << endl;
	}
	else
	{
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 == s2) cout << "Yes";
		else
			cout << "No" << endl;
	}
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// palidrome
/*
input: Nhập từ file vector_inp.txt
gồm nhiều số nguyên liên tiếp cách nhau bởi một khoảng trắng cho biết giá trị của mảng (0<= giá trị <= 10^5)
output: xuất ra file vector_out.txt
d1: xuất số đối xứng lớn nhất và tính tổng các số đối xứng trong danh sách.
d2: sắp xếp dãy chứa các số đối xứng theo thứ tự giảm dần
d3: sắp xếp dãy chứa các số đối xứng nhỏ nhất và tính tổng các số không đối xứng trong danh sách.
d4: sắp xếp dãy số chứa các số không đối xứng theo thứ tự tăng dần
*/




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TEMPLATESOMOI
/*
Xây dựng 1 cấu trúc mảng có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra số lớn nhất, số lượng số lớn nhất có trong dãy và tổng của các dãy số đó ra màn hình.
Với các qui ước:
- 	Kiểu N: là số nguyên ( <=1000)
- 	Kiểu M: là SoMoi (được mô tả ở đây)
Dữ liệu đầu vào:
- Dòng đầu tiên: nhập vào loại kiểu của dãy số (kiểu N hoặc M)
- Các dòng còn lại, mỗi dòng chứa 1 số thuộc kiểu của dòng đầu tiên
Dữ liệu đầu ra:
-          Dòng 1: số lớn nhất (thuộc kiểu đã cho).
-          Dòng 2: Xuất số lượng số lớn nhất có trong dãy.
-          Dòng 2: tổng của dãy số.
Lưu ý:  
-          Số lượng phần tử của dãy <= 1000

Ví dụ 1:
Input:
N
1
4
3
4
Output:
          4
          2
          12
Ví dụ 2:
Input:
M
12
23
Output:
[SoMoi] 23
1
[SoMoi]8

*/

#include <iostream>
#include <string>
using namespace std;


struct somoi {
	int n;
};
istream& operator>>(istream& in, somoi& sm) {
	in >> sm.n;
	return in;
}
ostream& operator<<(ostream& out, somoi sm) {
	out << "[SoMoi]"<<sm.n;
	return out;
}
bool operator<(somoi m1,somoi m2) {
	return m1.n < m2.n;
}
bool operator==(somoi m1, somoi m2) {
	return m2.n == m1.n;
}
int tong(somoi sm) {
	int r = 0,n=sm.n;
	while (n!= 0) {
		r = r + n% 10;
		n = n / 10;
	}
	return r;
}
int operator+(somoi  sm1, int Y) {
	return tong(sm1) + Y;
}

template<class T>
struct m1c {
	int x;
	T a[1000];
	T& operator[](int i) {
		return a[i];
	}
};

template <class T>
int tinhTong(m1c<T>m) {
	int s = 0;
	for (int i = 0; i < m.x; i++) {
		s = s + m[i];
	}
	return s;
}
template <class T>
T max(m1c<T>m) {
	T max = m[0];
	for (int i = 0; i < m.x; i++) {
		if (max < m[i]) {
			max = m[i];
		}
	}
	return max;
}

template <class T>
int dem(m1c<T>m) {
	int dem = 0;
	for (int i = 0; i < m.x; i++) {
		if (max(m) == m[i]) {
			dem++;
		}
	}
	return dem;
}

int main() {
	m1c<int>a;
	m1c<somoi>sm;
	a.x = 0;
	sm.x = 0;
	string kt;
	cin >> kt;
	if (kt == "N") {
		int t;
		while (cin >> t) {
				a[a.x++] = t;
		}
	}
	if (kt == "M") {
		somoi m;
		while (cin >> m) {
			sm[sm.x++] = m;
		}
	}
	if (a.x != 0) {
		cout << max(a)<<endl;
		cout << dem(a)<<endl<<tinhTong(a);
	}
	if (sm.x != 0) {
		cout << max(sm) << endl;
		cout << dem(sm) << endl;
		int tong = 0;
		for (int i = 0; i < sm.x; i++) {
			tong = sm[i] + tong;
		}
		cout << "[SoMoi]"<<tong;
	}
	//system("pause");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TEMPLATEHCN
/*
Xây dựng 1 cấu trúc mảng có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra số nhỏ nhất và tổng của các dãy số đó ra màn hình.
Với các qui ước:
-  Kiểu N: là số nguyên ( <=1000)
-  Kiểu H: là hình chữ nhật (được mô tả ở đây)
Dữ liệu đầu vào:
- Dòng đầu tiên: nhập vào loại kiểu của dãy số (kiểu a hoặc b)
- Các dòng còn lại, mỗi dòng chứa 1 số thuộc kiểu của dòng đầu tiên
Dữ liệu đầu ra:
-          Dòng 1: số nhỏ nhất (thuộc kiểu đã cho).
-          Dòng 2: tổng của dãy số.
Lưu ý:  
-          Nếu kết quả là hình chữ nhật thì tổng dãy chỉ lấy chính xác 1 chữ số thập phân.
-          Số lượng phần tử của dãy <= 100
 
Ví dụ 1:
Input:
N
1
2
3
4
Output:
          1
          10
Ví dụ 2:
Input:
H
1 2
2 3
3 4
4 5
Output:
          [HCN] 1,2
          48.0

*/


#include <iostream>
#include <iomanip>
using namespace std;
struct HCN
{
	float dai, rong;

};
istream& operator>>(istream& in, HCN& hcn) {
	in >> hcn.dai >> hcn.rong;
	return in;
}
ostream& operator<<(ostream& out, HCN hcn) {
	out << "[HCN] " << hcn.dai << ',' << hcn.rong;
	return out;
}
float chuVi(HCN h) {
	return (h.dai + h.rong) * 2;
}
float operator+(float k, HCN h) {
	return chuVi(h) + k;
}
float operator+(HCN k, HCN h) {
	return chuVi(h) + chuVi(k);
}

bool operator<(HCN h1, HCN h2) {
	return chuVi(h1) < chuVi(h2);
}
template <typename T>
struct Mang
{
	int spt;
	T a[100];
	T& operator[](int i) {
		return a[i];
	}
	Mang() {
		spt = 0;
	}
};
template <typename T>
istream& operator>>(istream& in, Mang<T>& m) {
	T a;
	while (cin >> a)
	{
		m[m.spt++] = a;
	}
	return in;
}
template <typename T>
ostream& operator<<(ostream& out, Mang<T> m) {
	for (int i = 0; i < m.spt; i++)
	{
		cout << m[i] << ' ';
	}
	return out;
}
template <typename T>
float tinhTong(Mang<T> m) {
	float kq = 0;
	for (int i = 0; i < m.spt; i++)
	{
		kq = kq + m[i];
	}
	return kq;
}
template <typename T>
T timMin(Mang<T> m) {
	int imin = 0;
	for (int i = 0; i < m.spt; i++)
	{
		if (m[i] < m[imin])
		{
			imin = i;
		}
	}
	return m[imin];
}
int main() {
	char kt;
	cin >> kt;

	if (kt == 'N')
	{
		Mang<int> m;
		cin >> m;
		cout << timMin<int>(m) << endl;
		cout << tinhTong<int>(m);
	}
	else if (kt == 'H')
	{
		Mang<HCN> m;
		cin >> m;
		cout << timMin<HCN>(m) << endl;
		cout << setprecision(1) << fixed << tinhTong<HCN>(m);
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TEMP_M1C
/*
Xây dựng khuôn hình cấu trúc mảng 1 chiều đặt tên là M1C.
 
yêu cầu viết hàm nhập, xuất mảng, tổng các phần tử trong mảng.
 
Các tên hàm và kiểu trả về của các hàm mà đề yêu cầu: void nhap, void xuat, int tong
 
input:
- Nhập vào 1 dãy số nguyên.
 
output:
- Xuất tổng các phần tử ra màn hình
 
vi dụ:
1 2 3
output:
6
 
Yêu cầu đề:
1. Viết đúng tên hàm, tên cấu trúc
2. Xây dựng khuôn hình trong file .h

*/
#include <iostream>
using namespace std;
int main()
{
    int a,tong=0;
    while(cin>>a){
        tong+=a;
    }
    cout<<tong;
}
void nhap();
void xuat();
int tong();
template <typename T>
struct M1C{
  int spt;  
};
////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Template1
/*
Viết 1 hàm template tìm phần tử lớn nhất trong 3 số
Yêu cầu xuất phần tử lớn nhất trong 3 số

qui ước: a là số nguyên, b là số thực, c là phân số
(các số nhập <= 100)
 
ví dụ:
a 1 2 3 tức là nhập 3 số nguyên
 
Dữ liệu vào:
Dòng 1: là nhập vào loại số
3 dòng tiếp theo: mỗi dòng chứa 1 số thuộc kiểu của dòng 1
 
Dữ liệu ra: gồm 1 dòng là số lớn nhất tìm thấy
 
ví dụ 1:
 
input
a
1
2
3
output
3
 
ví dụ 2:
input:
c
1 2
1 1
2 3
 
output
1/1
*/

#include <iostream>
using namespace std;
struct phanSo {
    int tu, mau;
    void operator = (phanSo p)
    {
        tu=p.tu;
        mau=p.mau;
    }
};
istream &operator >> (istream &in, phanSo &p);
ostream &operator << (ostream &out, phanSo p);
bool operator < (phanSo p1, phanSo p2);

template <typename T>
T timmax(T x, T y, T z);

int main() {
    char x;
    cin>> x;
   if(x=='a')
   {
       int x,y,z;
       cin>>x>>y>>z;
       cout<< timmax<int>(x,y,z);
   }
   if(x=='b')
   {
       float x,y,z;
       cin>>x>>y>>z;
       cout<< timmax<float>(x,y,z);
   }
   if(x=='c')
   {
       phanSo x,y,z;
       cin>>x>>y>>z;
       cout << timmax<phanSo>(x,y,z);
   }
    return 0;
}

istream &operator >> (istream &in, phanSo & p){
    in >> p.tu >> p.mau;
    return in;
}

ostream &operator << (ostream &out, phanSo p){
    out << p.tu << "/" << p.mau;
    return out;
}

template<typename T>
T timmax(T x, T y, T z) {
   T max = x;
   if(x < y) {
       max=y;
   }
   if(y<z) {
       max=z;
   }
   return max;
}

bool operator < (phanSo p1, phanSo p2) {
     if (float( p1.tu / p1.mau) < float( p2.tu / p2.mau)){
        return 1;
     }
     return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//KhuonHinhTong
/*
Xây dựng chương trình có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số gồm nhiều loại số, yêu cầu xuất ra tổng của từng loại số ra màn hình.
Với các qui ước:
o   Kiểu a: là số nguyên
o   Kiểu b: là số phân số
Dữ liệu đầu vào:
o   Gồm nhiều dòng còn lại, mỗi dòng chứa kiểu và 1 số thuộc kiểu đó
Dữ liệu đầu ra: Ghi ra 2 dòng:
o   Dòng 1: tổng của loại số nguyên
o   Dòng 2: tổng của loại phân số (kết quả đã được rút gọn)
Nếu không tìm thấy tổng của loại nào thì xuất kết quả “khong co” (chữ thường, không dấu) tại vị trí của loại đó
         
Ví dụ 1:
Input:
a 1
b  1 2
b  2 3
Output:
          1
          7/6
 
Ví dụ 1:
Input:
b  1 2
b  2 3
 
Output:
          khong co
         7/6
 

*/


#include <iostream>
using namespace std;
struct PhanSo {
	int tu, mau;
	void operator=(PhanSo x) {
		tu = x.tu;
		mau = x.mau;
	}
	PhanSo() {
		tu = 0; mau = 1;
	}
};
template <typename T>
struct Mang {
	T a[1001];
	int dem;
	Mang() {
		dem = 0;
	}
	T & operator[](int i) {
		return a[i];
	}
};
ostream& operator<<(ostream& oss, PhanSo x);

istream& operator>>(istream& is, PhanSo &x);

PhanSo operator+(PhanSo x, PhanSo y);

int UCLN(PhanSo x);


template <typename T>
void tinhTong(Mang<T> m);

int main() {
	Mang<int> arr1;
	Mang<PhanSo> arr2;
	char x;
	while (cin >> x) {
		if (x == 'a') {
			cin >> arr1[arr1.dem];
			arr1.dem++;
		}
		if (x == 'b'){
			cin >> arr2[arr2.dem];
			arr2.dem++;
		}
	}
	tinhTong<int>(arr1); cout << endl;
	tinhTong<PhanSo>(arr2); cout << endl;
	return 0;
}
ostream& operator<<(ostream& oss, PhanSo x) {
	oss << x.tu/UCLN(x) << "/" << x.mau/UCLN(x);
	return oss;
}

istream& operator>>(istream& is, PhanSo &x) {
	is >> x.tu >> x.mau;
	return is;
}

PhanSo operator+(PhanSo x, PhanSo y) {
	PhanSo k;
	k.tu = x.tu*y.mau + x.mau*y.tu;
	k.mau = x.mau*y.mau;
	return k;
}

template <typename T>
void tinhTong(Mang<T> m) {
	T sum = m[0];
	for (int i = 1; i < m.dem; i++) {
		sum = sum + m[i];
	}
	if (m.dem == 0) {
		cout << "khong co";
	}
	else cout << sum;
	//return sum;
}

int UCLN(PhanSo x) {
	int r;
	while (x.mau != 0) {
		r = x.tu%x.mau;
		x.tu = x.mau;
		x.mau = r;
	}
	return x.tu;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// KhuonHinh3
/*
Xây dựng 1 cấu trúc mảng có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra số nhỏ nhất của từng loại số ra màn hình.
Với các qui ước:
o   Kiểu a: là số nguyên
o   Kiểu b: là số thực
o   Kiểu c: là phân số
Dữ liệu đầu vào:
o   Gồm nhiều dòng còn lại, mỗi dòng chứa kiểu và 1 số thuộc kiểu đó
Dữ liệu đầu ra:
Ghi ra 3 dòng:
o   Dòng 1: số nhỏ nhất của loại số nguyên
o   Dòng 2: số nhỏ nhất của loại số thực.
o   Dòng 3: số nhỏ nhất của loại phân số.
Nếu không tìm thấy số nhỏ nhất của loại nào thì xuất kết quả “khong co” (chữ thường, không dấu) tại vị trí của loại đó
 
Ví dụ 1:
Input:
a 1
b 1.2
c  1 2
b  2.4
c  2 3
Output:
          1
         1.2
         1/2

Input:
a 1
b 1.2
c  1 2
b  2.4
c  2 3
Output:
          1
         1.2
         1/2
 
Ví Ví dụ 2:
Input:
b 1.2
c  1 2
b  2.4
c  2 3
 
Output:
          khong co
         1.2
         1/2
dụ 2:
Input:
b 1.2
c  1 2
b  2.4
c  2 3
 
Output:
          khong co
         1.2
         1/2
   
*/
 
#include<iostream>
using namespace std;
template<typename T>
struct Mang{
    int spt;
    T a[100];
    T & operator [](int i){
        return a[i];
    }
    Mang(){
        spt=0;
    }
};
struct PhanSo{
    int tu;
    int mau;
    void operator =(PhanSo ps){
        tu=ps.tu;
        mau=ps.mau;
    }
};
 
template<typename T>
istream & operator >>(istream & in,Mang<T> &m);
template<typename T>
ostream & operator <<(ostream & out,Mang<T> m);
template<typename T>
T soNho(Mang<T>m);
 
istream & operator >>(istream &in, PhanSo &ps);
ostream & operator <<(ostream &out, PhanSo ps);
bool operator <(PhanSo ps1, PhanSo ps2);
 
int main(){
    Mang<int>ma;
    Mang<float>mb;
    Mang<PhanSo>mc;
    char x;
    while(cin>>x){
    switch(x){
        case 'a':{
                int m;
                cin>>m;
                ma[ma.spt++]=m;
                break;
        }
        case 'b':{
                float m;
                cin>>m;
                mb[mb.spt++]=m;
                break;
        }
         case 'c':{
                PhanSo ps;
                cin>>ps;
                mc[mc.spt++]=ps;
                break;
         }
 
		default: break;
		}
    }
    if(ma.spt==0)
        cout<<"khong co"<<endl;
    else
    cout<<soNho(ma)<<endl;
    if(mb.spt==0)
        cout<<"khong co"<<endl;
    else
    cout<<soNho(mb)<<endl;
    if(mc.spt==0)
        cout<<"khong co"<<endl;
    else
    cout<<soNho(mc)<<endl;
}
template<typename T>
istream & operator >>(istream & in,Mang<T> &m){
    T x;
    m.spt=0;
    while(in>>x){
        m[m.spt]=x;
        m.spt++;
    }
    return in;
}
template<typename T>
ostream & operator <<(ostream & out,Mang<T> m);
template<typename T>
T soNho(Mang<T>m){
    T min=m[0];
    for(int i=0;i<m.spt;i++){
        if(m[i]<min)
        min=m[i];
    }
    return min;
}
istream &operator >>(istream &in, PhanSo &ps){
    in>>ps.tu>>ps.mau;
    return in;
}
ostream &operator <<(ostream &out, PhanSo ps){
    out<<ps.tu<<"/"<<ps.mau;
    return out;
}
bool operator <(PhanSo ps1, PhanSo ps2){
   return ps1.tu*ps2.mau < ps2.tu*ps1.mau;
}
 
---------------------------------------------------------------------------------
// template2
/*
Xây dựng 1 cấu trúc mảng (hoặc lớp) có sử dụng khuôn hình, áp dụng cho bài sau:
          Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra tổng của các dãy số đó ra màn hình.
Với các qui ước:
-      Kiểu a: là số nguyên
-      Kiểu b: là phân số
Dữ liệu đầu vào:
-      Dòng đầu tiên: nhập vào loại kiểu của dãy số (kiểu a hoặc b)
-      Các dòng còn lại, mỗi dòng chứa 1 số thuộc kiểu của dòng đầu tiên
Dữ liệu đầu ra:
-      Gồm 1 số duy nhất (thuộc kiểu đã cho).
Lưu ý:  
- Nếu kết quả là phân số thì phân số đó đã được rút gọn.
    
Ví dụ 1:
Input:
a
1
2
3
4
Output:
          10
Ví dụ 2:
Input:
b
1 2
2 3
3 4
4 5
Output:
          163/60
 
*/
 
#include <iostream>
#define max 200
using namespace std;
struct phanso {
    int tu, mau;
 
phanso operator + (phanso p) {
    phanso kq;
    kq.tu= p.tu*mau + p.mau*tu;
    kq.mau= p.mau*mau;
    return kq;
}
 
void operator = (int a) {
    tu= a;
    mau= 1;
}
};
template <typename T>
struct mang {
    int spt;
    T a[max];
    T & operator[] (int i) {
        return a[i];
    }
};
 
istream &operator >> (istream &in, phanso &p);
ostream &operator << (ostream &out, phanso p);
 
template<typename T>
istream &operator >> (istream &in, mang<T> &m);
 
template<typename T>
ostream & operator << (ostream &out, mang<T> m);
 
void rutgonps (phanso &p);
int UCLN (int a, int b);
 
template <typename T>
T tinhtong(mang<T> m);
 
int main() {
    char k;
    cin>> k;
    if(k=='a') {
        mang<int> ms;
        cin>> ms;
        cout<< tinhtong(ms);
    }
    else
    if(k=='b') {
        mang<phanso> ms;
        cin>> ms;
        phanso tong= tinhtong(ms);
        rutgonps(tong);
        cout<< tong;
    }
    return 0;
}
 
istream &operator >> (istream &in, phanso &p) {
    in>> p.tu >> p.mau;
    return in;
}
ostream &operator << (ostream &out, phanso p) {
    out << p.tu <<"/" << p.mau;
    return out;
}
 
template <typename T>
istream &operator >> (istream &in, mang<T> &m) {
     m.spt = 0;
    T tmp;
    while (in >> tmp){
        m[m.spt] = tmp;
        m.spt++;
    }
return in;
}
template <typename T>
ostream& operator<< (ostream& out, mang<T> m);
 
int UCLN (int a, int b){
    int r;
    
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}
 
void rutgonps(phanso & p){
    int uoc = UCLN(p.tu, p.mau);
    p.tu /= uoc;
    p.mau /= uoc;
}
 
template <typename T>
T tinhtong(mang<T> m){
    T kq;
    kq = 0;
    for (int i = 0; i < m.spt; i++){
        kq = kq + m[i];
    }
    return kq;
}
 
 
 
/////////////////////////////////////////////////////////////////
//KhuonHinhSS
//khuonhinhsosanh
/*
Viết hàm khuôn hình so sánh 2 số
Nhập vào 2 số, xuất true nếu 2 số bằng nhau, ngược lại xuất false
qui ước:
kiểu a là số nguyên
kiểu b là số thực
kiểu c là phân số
 
ví dụ
a
1
2
 
output
false
*/
#include<iostream>
#include<cmath>
using namespace std;
struct phanso
{
    int tu, mau;
    void operator=(phanso p)
    {
        tu=p.tu;
        mau=p.mau;
    }
};
 
istream &operator >>(istream &in, phanso &p);
ostream &operator <<(ostream &out, phanso p);
 
template<typename T>
bool ss( T a, T b);
bool operator == (phanso p1, phanso p2);
 
int main()
{
    char x;
    cin>>x;
    if(x=='a')
    {
        int a,b; cin>>a>>b;
        if(ss<int>(a,b))
        cout<<"true"; else cout<<"false";
    }
    if(x=='b')
    {
        float a,b;
        cin>>a>>b;
        if(ss<float>(a,b))
        cout<<"true"; else cout<<"false";
    }
    if(x=='c')
    {
        phanso p1, p2;
        cin>>p1>>p2;
        if(ss<phanso>(p1,p2))
        cout<< "true";
        else
        cout<<"false";
    }
        
}
 
istream &operator >> (istream &in, phanso &p)
{
    in>>p.tu>>p.mau;
    return in;
}
ostream &operator << (ostream &out, phanso p)
{
    out<<p.tu<<"/"<<p.mau;
    return out;
}
 
template<typename T>
bool ss(T a, T b)
{
    if(a==b)
    return true;
    return false;
}
 
bool operator ==(phanso p1, phanso p2)
{
    return(p1.tu*p2.mau==p2.tu*p1.mau);
}
///////////////////////////////////////////////////////////////
//template1
/*
Viết 1 hàm template tìm phần tử lớn nhất trong 3 số
Yêu cầu xuất phần tử lớn nhất trong 3 số
 
qui ước: a là số nguyên, b là số thực, c là phân số
(các số nhập <= 100)
 
ví dụ:
a 1 2 3 tức là nhập 3 số nguyên
 
Dữ liệu vào:
Dòng 1: là nhập vào loại số
3 dòng tiếp theo: mỗi dòng chứa 1 số thuộc kiểu của dòng 1
 
Dữ liệu ra: gồm 1 dòng là số lớn nhất tìm thấy
 
ví dụ 1:
 
input
a
1
2
3
output
3
 
ví dụ 2:
input:
c
1 2
1 1
2 3
 
output
1/1
 
*/
 
 
#include <iostream>
using namespace std;
struct phanSo {
    int tu, mau;
    void operator = (phanSo p)
    {
        tu=p.tu;
        mau=p.mau;
    }
};
istream &operator >> (istream &in, phanSo &p);
ostream &operator << (ostream &out, phanSo p);
bool operator < (phanSo p1, phanSo p2);
 
template <typename T>
T timmax(T x, T y, T z);
 
int main() {
    char x;
    cin>> x;
   if(x=='a')
   {
       int x,y,z;
       cin>>x>>y>>z;
       cout<< timmax<int>(x,y,z);
   }
   if(x=='b')
   {
       float x,y,z;
       cin>>x>>y>>z;
       cout<< timmax<float>(x,y,z);
   }
   if(x=='c')
   {
       phanSo x,y,z;
       cin>>x>>y>>z;
       cout << timmax<phanSo>(x,y,z);
   }
    return 0;
}
 
istream &operator >> (istream &in, phanSo & p){
    in >> p.tu >> p.mau;
    return in;
}
 
ostream &operator << (ostream &out, phanSo p){
    out << p.tu << "/" << p.mau;
    return out;
}
 
template<typename T>
T timmax(T x, T y, T z) {
   T max = x;
   if(x < y) {
       max=y;
   }
   if(y<z) {
       max=z;
   }
   return max;
}
 
bool operator < (phanSo p1, phanSo p2) {
     if (float( p1.tu / p1.mau) < float( p2.tu / p2.mau)){
        return 1;
     }
     return 0;
}
 
 
///////////////////////////////////////////////////////
//CONTRO2
//xoa phan tu k
/*
Xoá phần tử k 
 
Xoá tất cả phần tử có giá trị K trong danh sách liên kết đơn có n phần tử 
 
Input:
dòng 1: chứa số nguyên n (100>=n >= 1) và số nguyên K ( -1000<=k<=1000)
dòng 2: chứa n phần tử mỗi phần tử cách nhau 1 khoảng trắng (mỗi phần tử là số nguyên có giá trị tuyệt đối <= 1000)
 
Output:
dòng 1 : số phần tử của danh sách sau khi xoá
dòng 2: chứa n phần tử của danh sách sau khi xoá , mỗi phần tử cách nhau 1 khoảng trắng
 
lưu ý : PHẢI dùng danh sách liên kết để làm bài 
 
input:
6 2
1 2 3 6 2 8
output:
4
1 3 6 8
 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
int arr[100];
for(int i=0;i<n;i++)
{
	cin>>arr[i];
}
int *pointer=arr;
int dem=0;
for(int i=0;i<n;i++)
{   
	if(*(pointer+i)!=k)
	dem++;
}
cout<<dem<<endl;
for(int j=0;j<n;j++)
{   
	if(*(pointer+j)!=k)
	cout<<*(pointer+j)<<" ";
}
return 0;
}
 
//////////////////////////////////
//sophuc sophucltnc
/*
Số có dạng z = a + bi, gọi là số phức. Trong đó a gọi là phần thực (real), còn b gọi là phần ảo (image).
|z| = sqrt(a2 + b2), gọi là mô-đun của số phức z
Cho hai số phức z1 = a + bi, z2 = c + di
Cộng, trừ số phức: z1 + z2 = (a+c) + (b+d)i
Trừ số phức: z1 - z2 = (a-c) + (b-d)i
Xây dựng cấu trúc mô tả một dãy N (0 <= N <= 10,000) số phức với các thao tác sau:
a)     Tính tổng N số phức
b)    Tính hiệu N số phức
c)     Tính mô-đun N số phức
d)    Xuất N số phức theo định dạng: z = a + bi (với a là phần thực và b là phần ảo)
 
Yêu cầu: sử dụng kĩ thuật cấp phát động và con trỏ để quản lý dãy số. Bài làm không đúng yêu cầu sẽ không được tính điểm.
 
Input:
-       N dòng, mỗi dòng là 1 cặp a và b mô tả thông tin phần thực và phần ảo của 1 số phức.
Output:
-       Dòng 1: xuất N số phức theo định dạng {a+bi}, mỗi số phức cách nhau 1 khoảng trắng;
-       Dòng 2: giá trị mô-đun của N số phức, lấy tối đa 2 số lẻ ở phần thập phân, mỗi giá trị cách nhau 1 khoảng trắng;
-       Dòng 3: xuất tổng N số phức
 
Input
Output
1 2
3 4
{1+2i} {3+4i} 
2.24 5.00 
{4+6i}
 
 
Input
Output
0 -2
3 4
1 1
1 -1
-2 0
{-2i} {3+4i} {1+i} {1-i} {-2} 
2.00 5.00 1.41 1.41 2.00 
{3+2i}
 
*/
#include<bits/stdc++.h>
using namespace std;
struct SoPhuc{
    int real,image;
    SoPhuc& operator=(int){
        real=0;
        image=1;
    }
};
istream&operator>>(istream&is,SoPhuc &s){
    is>>s.real>>s.image;
    return is;
}
ostream&operator<<(ostream&os, SoPhuc s){
    if(s.real!=0&&s.image!=0){
        if(s.image>0){
            if(s.image==1){os<<"{"<<s.real<<"+"<<"i"<<"}";}
         else os<<"{"<<s.real<<"+"<<s.image<<"i"<<"}";
        }
         if(s.image<0){
             if(s.image==-1){ os<<"{"<<s.real<<"-i"<<"}";}
        else os<<"{"<<s.real<<s.image<<"i"<<"}";
    }
}
    if(s.real==0&&s.image!=0) os<<"{"<<s.image<<"i"<<"}";
    if(s.real!=0&&s.image==0) os<<"{"<<s.real<<"}";
    return os;
}
SoPhuc operator+(SoPhuc s1, SoPhuc s2){
    SoPhuc tong;
    tong.real=s1.real+s2.real;
    tong.image=s1.image+s2.image;
    return tong;
}
SoPhuc operator-(SoPhuc s1, SoPhuc s2){
    SoPhuc hieu;
    hieu.real=s1.real-s2.real;
    hieu.image=s1.image-s2.image;
    return hieu;
}
double modun(SoPhuc s){
    double x;
    x=sqrt(pow(s.real,2)+pow(s.image,2));
    //return sqrt((s.real*s.real)+(s.image*s.image));
    return x;
}
int main(){
    int n=0;
    SoPhuc *p=new SoPhuc [n];
    SoPhuc s1;
    while(cin>>s1){
        p[n++]=s1;
    }
    for(int i=0;i<n;++i){
        cout<<p[i]<<" ";
    } cout<<endl;
    for(int i=0;i<n;++i){
        cout<<fixed<<setprecision(2)<<modun(p[i])<<" ";
    }
    SoPhuc tong=p[0];
    for(int i=1;i<n;++i){
        tong=tong+p[i];
    } cout<<endl<<tong;
   // cout<<fixed<<setprecision(2)<<modun(s1);
    return 0;
}
////////////////////////////////////////////////////////////
//CONTRO1
//tim min max
/*
Tìm Min-Max  
 
cho danh sách liên kết đơn n phần tử (số nguyên) tìm giá trị lớn nhất và nhỏ nhất trong danh sách và in ra vị trí của các giá trị lớn nhất, giá trị nhỏ nhất trong danh sách đó 
dư liệu được cho như sau:
dòng đầu tiên là n (số phần tử của danh sách)
n dòng tiếp theo là giá trị của phần tử thứ i trong danh sách 
dữ liệu ra xuất ra:
dòng đầu tiên xuất ra giá trị lớn nhất 
dòng tiếp theo xuất ra vị trí của các phần tử lớn nhất trong danh sách mỗi phần tử cách nhau 1 khoảng trắng
dòng tiếp theo xuất ra giá trị nhỏ nhất 
dòng tiếp theo xuất ra vị trí của các phần tử nhỏ nhất trong danh sách, mỗi phần tử cách nhau 1 khoảng trắng
lưu ý: dùng con trỏ để làm bài  
 
ví dụ:
input :
7
-1 2 6 3 6 -1 2
output :
6
3 5
-1
1 6
 
Lưu ý danh sách được đánh số từ 1
 
*/
#include<iostream>
using namespace std;
int main(){
    int n,a[100];
    int *p=a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>*(p+i);
    }
    int max;
    max=*p;
    for(int i=0;i<n;i++){
        if(max<*(p+i))
        max=*(p+i);
    }
    cout<<max<<endl;
     for(int i=0;i<n;i++){
        if(max==*(p+i))
        cout<<(i+1)<<" ";
    }
    cout<<endl;
    int min=*p;
     for(int i=0;i<n;i++){
        if(min>*(p+i))
        min=*(p+i);
    }
    cout<<min<<endl;
     for(int i=0;i<n;i++){
        if(min==*(p+i))
        cout<<(i+1)<<" ";
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//Bài vector VECTOR
// vector
//tong chu so khong nguyen to
/*
Nhập vào một dãy số nguyên dương gồm N phần tử theo cấu trúc:
- Dòng đầu ghi số nguyên dương N.
- N dòng tiếp theo, mỗi dòng ghi một số nguyên dương.
Yêu cầu: Xét mọi số nguyên trong dãy đã cho, nếu số đó là số nguyên tố thì yêu cầu tính tổng các chữ số không phải là số nguyên tố của nó, ngược lại xuất -1.
 
Ví dụ
input
3
28
9817
23
output
-1
18
0
 
*/
/*(sử dụng fstream và vector)
 
Viết chương trình hoàn chỉnh cho bài toán sau:
 
Nhập vào một dãy số nguyên dương gồm N phần tử từ tập tin “input.txt” theo cấu trúc:
 
- Dòng đầu ghi số nguyên dương N.
 
- N dòng tiếp theo, mỗi dòng ghi một số nguyên dương.
 
Yêu cầu: Xét mọi số nguyên trong dãy đã cho, nếu số đó là số nguyên tố thì yêu cầu tính tổng các chữ số không phải là số nguyên tố của nó, ngược lại xuất -1.
 
Dữ liệu xuất ra được ghi vào tập tin “output.txt”.
 
input
3
 
28
 
9817
 
23
 
output
-1
 
18
 
0*/
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
 
using namespace std;
 
bool SNT(int n);
int tongChuSo(int n);
 
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    
    int n, a[100], x;
    vector<int> v;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    
    for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		if (!SNT(v[i]))
			cout << -1 << endl;
		else
			cout << tongChuSo(v[i]) << endl;
	}
 
    
    
    cin.close();
    cout.close();
    return 0;
}
 
bool SNT(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); ++i)
	    if (n%i == 0)
		    return false;
	return true;
}
 
int tongChuSo(int n)
{
	int s = 0;
	int chuso;
 
	while (n != 0)
	{
		chuso = n % 10;
		if (!SNT(chuso))
			s += chuso;
		n /= 10;
 
	}
	return s;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
------------
#include <iostream>
#include <cmath>
using namespace std;
 
/*int N;
char a[100][100];
int b[100][100];
char c[100];
int */  
 
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool KTNT(int n) {
	if (n < 2) return false;
	else {
		if (n == 2) return true;
		else {
			for (int i = 2; i <= sqrt(n); i++) {
				if (n % i == 0) return false;
			}
		}
	}
	return true;
}
 
int Sum(vector<int> n) {
	int sum = 0;
	for (int i = 0; i < n.size(); i++) {
		if (KTNT(n[i]) == false)
			sum += n[i];
	}
	return sum;
}
 
void XuLy(int n) {
	vector<int> a;
	if (KTNT(n) == false)
		cout << "-1";
	else {
		while (n != 0) {
			int giaTri = n % 10;
			a.push_back(giaTri);
			//
			n /= 10;
			//
		}
		cout << Sum(a);
	}
	
}
int main() {
	int n;
	cin >> n;
	int tmp;
	vector<int> Luu;
	while (n--) {
		cin >> tmp;
		Luu.push_back(tmp);
	}
 
	for (int i = 0; i < Luu.size(); i++)
	{
		XuLy(Luu[i]);
		cout << endl;
	}
 
 
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
//fstream1
//sochinhphuong
/*
SỐ CHÍNH PHƯƠNG
 
Nhập vào 1 số và kiểm tra số đó có phải là số chính phương không?
 
dữ liệu vào từ file "FSTREAM.inp":
dòng 1 : số nguyên n
 
dữ liệu xuất ra file "FSTREAM.out":
dòng 1 : Xuất: "YES" nếu đó là số chính phương, ngược lại xuất "NO"
 
input: 4
output: YES
 
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
 
bool ktraCP(int n){
    int x = sqrt(n);
    return x*x == n;
}
 
int main(){
    ifstream ifile("FSTREAM.inp");
    ofstream ofile("FSTREAM.out");
    int n;
    ifile >> n;
    if(ktraCP(n))
        ofile << "YES";
    else
        ofile << "NO";
    
    return 0;
}
 
//////////////////////////////////////////////////////
//vector
//tongchusokhongnguyento
/*
Viết chương trình hoàn chỉnh cho bài toán sau:
Nhập vào một dãy số nguyên dương gồm N phần tử theo cấu trúc:
- Dòng đầu ghi số nguyên dương N.
- N dòng tiếp theo, mỗi dòng ghi một số nguyên dương.
Yêu cầu: Xét mọi số nguyên trong dãy đã cho, nếu số đó là số nguyên tố thì yêu cầu tính tổng các chữ số không phải là số nguyên tố của nó, ngược lại xuất -1.
 
Ví dụ
input
3
28
9817
23
output
-1
18
0
 
*/
#include <iostream>
#include <cmath>
#include <vector>
 
using namespace std;
 
bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}
int tong(int n){
    int tong = 0;
    while(n>0){
        int r = n%10;
        if(!isPrime(r)){
            tong+=r;
        }
        n = n/10;
    }
    return tong;
}
 
int main(){
    int n, num, pos;
    vector<int> V;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>num;
        if(isPrime(num)){
            V.push_back(num);
            cout<<tong(V.at(0))<<endl;
            V.clear();
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
 
////////////////////////////////////////////////////////////////////////////
//vector3
//loai bo so chinh phuong
/*
Sử dụng container vector, anh/chị hãy viết chương trình đọc vào các số nguyên, sau đó loại bỏ các số chính phương trong vector rồi xuất ra các số chẵn theo thứ tự tăng dần.
 
ví dụ:
input
7 6 5 4 3 2 1
output
2 6
 
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iterator>
using namespace std;
bool soCP(int a) {
	int b = sqrt(a);
	return b * b == a;
}
bool soChan(int a) {
	return a % 2 != 0;
}
int main() {
	vector<int> v;
	int n;
	while (cin >> n)
	{
		v.push_back(n);
	}
	vector<int>::iterator iterCP = remove_if(v.begin(), v.end(), soCP);
	v.erase(iterCP,v.end());	
	vector<int>::iterator iterSC = remove_if(v.begin(), v.end(), soChan);
	v.erase(iterSC,v.end());
	sort(v.begin(), v.end());
	ostream_iterator<int> output(cout, " ");
	copy(v.begin(), v.end(), output);
	return 0;
}
 
///////////////////////////////////////////////////////////////////
//fstream1
// nhap xuat file chuan
/*
Nhập vào 2 số nguyên a và b.
yêu cầu xuất ra tổng của 2 số a và b
 
Dữ liệu vào từ file văn bản: input.txt gồm 2 số nguyên
Dữ liệu ra màn hình tổng 2 số nguyên đó
 
ví dụ:
 
Input:  2  3
Output: 5
 
*/
#include <iostream>
#include <fstream>
 
using namespace std;
ifstream fi("input.txt");
 
int main(){
    int a, b;
    fi >> a >> b;
    cout << a + b;
}
//////////////////////////////////////////////////////////////
//fstream2
// nhap va xuat file
/*
Nhập vào 2 số nguyên a và b.
yêu cầu xuất ra tổng của 2 số a và b
 
Dữ liệu vào từ file văn bản: input.txt gồm 2 số nguyên
Dữ liệu ra file văn bản output.txt tổng 2 số nguyên đó
 
ví dụ:
 
Input:  2  3
Output: 5
 
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");
    int a,b;
    ifile>>a>>b;
    ofile<<a+b;
    ifile.close();
    ofile.close();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//fstream3
/*
Nhập vào 2 số nguyên a và b.
yêu cầu xuất ra tổng của 2 số a và b
 
Dữ liệu vào từ bàn phím (nhập chuẩn) gồm 2 số nguyên
Dữ liệu ra file văn bản out.txt tổng 2 số nguyên đó
 
ví dụ:
 
Input:  2  3
Output: 5
 
*/
#include <iostream>
#include <fstream>
 
using namespace std;
ofstream fo("out.txt");
 
int main(){
    int a, b;
    cin >> a >> b;
    fo << a + b;
}
/////////////////////////////////////////////////////////////////////////////
//ôn tập cấu trúc quá tải toán tử template
/*
ÔN TẬP CẤU TRÚC, QUÁ TẢI TOÁN TỬ, TEMPLATE
 
Yêu cầu 1:
 
Xây dựng cấu trúc PhanSo biểu diễn phân số gồm 2 thành phần a, b trong đó a, b là số không âm.
 
+ Viết quá tải toán tử nhập và xuất ( >> ; << ) cho cấu trúc trên.
 
Lưu ý:
 
Dữ liệu nhập vào ở dạng chuỗi như sau: “1/2” thì ta sẽ được phân số với các thành phần tương ứng: a = 1 và b = 2.
Khi xuất có kiểm tra tính hợp lí. Ví dụ: xuất phân số “2/1”, “1/1”, hoặc “0/3”  đều SAI.
 
+ Viết quá tải toán tử so sánh ==, <, > để so sánh 2 phân số.
 
+ Viết quá tải toán tử + để cộng hai phân số. Kết quả trả về là một phân số tối giản.
 
 
 
Yêu cầu 2: Có sử dụng template.
 
Xây dựng cấu trúc Mảng 1 chiều thực hiện các yêu cầu sau:
 
+ Viết quả tải nhập (>>), xuất (<<) cho cấu trúc.
 
 
+ Viết hàm tongPhanTu tính tổng các phần tử của mảng.
 
+ Viết hàm phanTuMax tìm phần tử lớn nhất trong mảng.
 
+ Viết hàm sapXep để sắp xếp mảng 1 chiều. Tham số truyền vào theo tùy chọn ‘<’ là sắp xếp tăng dần, ‘>’ là sắp xếp giảm dần.
 
Lưu ý: Sử dụng giá trị mặc định là sắp xếp tăng dần.
 
 
Ví dụ:
 
sapXep(m1)      => sắp xếp m1 tăng dần.
sapXep(m1,’<’) => sắp xếp m1 tăng dần.
sapXep(m1,’>’) => sắp xếp m1 giảm dần.
 
 
 
Dữ liệu vào:
 
Dòng 1: 1 ký tự in hoa ( I hoặc F ). Nếu ‘I’ thì  là kiểu số nguyên, ‘F’ là phân số.
Dòng 2: 1 số nguyên dương n là số phần tử của mảng thứ 1.
Dòng 3: n số (số nguyên hoặc phân số tùy vào tùy chọn ở dòng 1), mỗi số cách nhau một khoảng trắng, là các phần tử của mảng thứ 1.
Dòng 4: 1 số nguyên dương n là số phần tử của mảng thứ 2.
Dòng 5: n số (số nguyên hoặc phân số tùy vào tùy chọn ở dòng 1), mỗi số cách nhau một khoảng trắng, là các phần tử của mảng thứ 2.
 
 
 
Dữ liệu xuất:
 
Dòng 1: xuất mảng 1 vừa nhập
Dòng 2: xuất phần tử lớn nhất của mảng 1 theo mẫu: MAX 1 = X trong đó X là phần tử lớn nhất.
Dòng 3: xuất tổng các phần tử của mảng 1 theo mẫu: SUM 1 = X trong đó X là kết quả tìm được.
Dòng 4:
Nếu là mảng số nguyên thì xuất các phần tử của mảng 1 theo mẫu: tăng dần các phần tử chẵn, tăng dần các phần tử lẻ.
Ví dụ: m1 = {4, 5, 2, 3, 1} thì xuất ra: 2 4 1 3 5
 
Nếu là mảng phân số thì xuất các phần tử của mảng 1 sau khi đã sắp xếp tăng dần.
Ví dụ: m1 = { 1/2, 1/3, 2/4, 1/5, 4/6 } thì xuất ra: 1/5 1/3 1/2 1/2 2/3
 
Dòng 5: xuất mảng 2.
Dòng 6: xuất phần tử lớn nhất của mảng 2 theo mẫu: MAX 2 = X trong đó X là phần tử lớn nhất.
Dòng 7: xuất tổng các phần tử của màng 2 theo mẫu: SUM 2 = X trong đó X là kết quả tìm được.
Dòng 8:
Nếu là mảng số nguyên thì xuất các phần tử của mảng 2 theo mẫu: giảm dần các phần tử lẻ, giảm dần các phần tử chẵn.
Ví dụ: m2 = {5, 1, 6, 4, 2, 3} thì xuất ra: 5 3 1 6 4 2
 
 
Nếu là mảng phân số thì xuất các phần tử của mảng 2 sau khi đã sắp xếp giảm dần.
Ví dụ: m2 = { 2/3, 1/4, 4/5, 3/6, 2/7, 1/8 } thì xuất ra: 4/5 2/3 1/2 2/7 1/4 1/8
 
Dòng 9: xuất mảng tổng của mảng 1 và mảng 2 ban đầu.
 
 
 
Ví dụ:
 
Input
I
5
4 5 2 3 1
6
5 1 6 4 2 3
Output
4 5 2 3 1
MAX 1 = 5
SUM 1 = 15
2 4 1 3 5 
5 1 6 4 2 3
MAX 2 = 6
SUM 2 = 21
5 3 1 6 4 2 
9 6 8 7 3 3
 
Input
F
5
1/2 1/3 2/4 1/5 4/6
6
2/3 1/4 4/5 3/6 2/7 1/8
Output
1/2 1/3 1/2 1/5 2/3
MAX 1 = 2/3
SUM 1 = 11/5
1/5 1/3 1/2 1/2 2/3
2/3 1/4 4/5 1/2 2/7 1/8
MAX 2 = 4/5
SUM 2 = 2207/840
4/5 2/3 1/2 2/7 1/4 1/8
7/6 7/12 13/10 7/10 20/21 1/8
*/
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;
int soSanh(int a,int b){
    return a > b;
}
int UCLN(int a,int b){
    a = abs(a);
    b = abs(b);
    if(b == 0)
        return a;
    return UCLN(b,a%b);    
}
int string_to_int(string s){
	int res = atoi(s.c_str());
	return res;
}
struct phanSo{
    int tu,mau;
    string ps;
};
 
istream& operator >> (istream& in,phanSo &p);
ostream& operator << (ostream& out,phanSo &p);
void rutGon(phanSo &p);
bool operator == (phanSo ps1,phanSo ps2);
bool operator < (phanSo ps1,phanSo ps2);
bool operator > (phanSo ps1,phanSo ps2);
phanSo operator + (phanSo ps1,phanSo ps2);
 
template<typename T>
struct mang1c{
    T mang[100];
    int soPtu;
};
template<typename T>
istream& operator >> (istream& in,mang1c<T> &m);
template<typename T>
ostream& operator << (ostream& out,mang1c<T> m);
template<typename T>
T phanTuMax (mang1c<T> m);
template<typename T>
T tongPhanTu(mang1c<T> m);
template<typename T>
T sapXep(mang1c<T> &m, char c);
template<typename T>
T sapXep(mang1c<T> &m);
template<typename T>
mang1c<T> tong2Mang(mang1c<T> m1,mang1c<T> m2);
void sortGiam(mang1c<int> &m);
 
int main(){
    char c;
    cin >> c;
    if(c == 'I'){
        mang1c<int> a,b,tong_2_mang;
        int _max1,_max2,sum1,sum2;
        cin >> a >> b;
        tong_2_mang = tong2Mang(a,b);
        _max1 = phanTuMax (a);
        _max2 = phanTuMax (b);
        sum1 = tongPhanTu(a);
        sum2 = tongPhanTu(b);
        cout << a << endl;
        cout << "MAX 1 = " << _max1 << endl;
        cout << "SUM 1 = " << sum1 << endl;
        sapXep(a);
        cout << a << endl;
        cout << b << endl;
        cout << "MAX 2 = " << _max2 << endl;
        cout << "SUM 2 = " << sum2 << endl;
        sortGiam(b);
        cout << b << endl;
        cout << tong_2_mang;
    }
    else if(c == 'F'){
        mang1c<phanSo> a,b,tong_2_mang;
        phanSo _max1,_max2,sum1,sum2;
        cin >> a >> b;
        tong_2_mang = tong2Mang(a,b);
        _max1 = phanTuMax (a);
        _max2 = phanTuMax (b);
        sum1 = tongPhanTu(a);
        sum2 = tongPhanTu(b);
        cout << a << endl;
        cout << "MAX 1 = " << _max1 << endl;
        cout << "SUM 1 = " << sum1 << endl;
        sapXep(a,'<'); 
        cout << a << endl;
        cout << b << endl;
        cout << "MAX 2 = " << _max2 << endl;
        cout << "SUM 2 = " << sum2 << endl;
        sapXep(b,'>');
        cout << b << endl;
       cout << tong_2_mang;
    }
    
    return 0;
}
 
//struct phanSo
istream& operator >> (istream& in,phanSo &p){
    in >> p.ps;
    string ts,ms;
    int gan;
    for(int i = 0;i < p.ps.length();i++){
        if(p.ps[i] == '/'){
            gan = i;
            break;
        }
        ts += p.ps[i];
    }
    for(int i = gan + 1;i < p.ps.length();i++){
        ms += p.ps[i];
    }
    p.tu = string_to_int(ts);
    p.mau = string_to_int(ms);
    return in;
}
ostream& operator << (ostream& out,phanSo &p){
    int y = UCLN(p.tu,p.mau);
    if(y != 1){
        p.tu /= y;
        p.mau /= y;
    }
    if(p.tu == 0)
        out << 0;
    else if(p.mau == 1)
        out << p.tu;
    else if((p.tu > 0 && p.mau > 0) || (p.tu < 0 && p.mau < 0))
        out << abs(p.tu) << "/" << abs(p.mau);
    else if((p.tu*p.mau < 0))
        out << -(abs(p.tu)) << "/" << abs(p.mau);
        
    return out;
}
void rutGon(phanSo &p){
    int y = UCLN(p.tu,p.mau);
    p.tu /= y;
    p.mau /= y;
}
bool operator == (phanSo ps1,phanSo ps2){
    return ((float)ps1.tu/ps1.mau == (float)ps2.tu/ps2.mau);
}
bool operator < (phanSo ps1,phanSo ps2){
    return ((float)ps1.tu/ps1.mau < (float)ps2.tu/ps2.mau);
}
bool operator > (phanSo ps1,phanSo ps2){
    return ((float)ps1.tu/ps1.mau > (float)ps2.tu/ps2.mau);
}
phanSo operator + (phanSo ps1,phanSo ps2){
    phanSo kq;
    kq.tu = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    rutGon(kq);
    return kq;
}
// struct mang1c
template<typename T>
istream& operator >> (istream& in,mang1c<T> &m){
    in >> m.soPtu;
    for(int i = 0;i < m.soPtu;i++){
        in >> m.mang[i];
    }
    return in;
}
template<typename T>
ostream& operator << (ostream& out,mang1c<T> m){
    for(int i = 0;i < m.soPtu;i++){
        out << m.mang[i] << " ";
    }
    return out;
}
template<typename T>
T phanTuMax (mang1c<T> m){
    T _max = m.mang[0];
    for(int i = 1;i < m.soPtu;i++){
        if(_max < m.mang[i])
            _max = m.mang[i];
    }
    return _max;
}
template<typename T>
T tongPhanTu(mang1c<T> m){
    T tong = m.mang[0];
    for(int i = 1;i < m.soPtu;i++){
        tong = tong + m.mang[i];
    }
    return tong;
}
template<typename T>
T sapXep(mang1c<T> &m, char c){
    if(c == '<'){
        for(int i = 0;i < m.soPtu;i++){
            for(int j = i + 1;j < m.soPtu;j++){
                if(m.mang[i] > m.mang[j]){
                    phanSo tam;
                    tam = m.mang[i];
                    m.mang[i] = m.mang[j];
                    m.mang[j] = tam;
                }
            }
        }
    }
    else if(c == '>'){
        for(int i = 0;i < m.soPtu;i++){
            for(int j = i + 1;j < m.soPtu;j++){
                if(m.mang[i] < m.mang[j]){
                    phanSo tam;
                    tam = m.mang[i];
                    m.mang[i] = m.mang[j];
                    m.mang[j] = tam;
                }
            }
        }
    }
}
template<typename T>
T sapXep(mang1c<T> &m){
    int chan[m.soPtu];
    int le[m.soPtu];
    int demChan = 0,demLe = 0;
    for(int i = 0;i < m.soPtu;i++){
        if(m.mang[i]%2 == 0){
            chan[demChan] = m.mang[i];
            demChan++;
        }
        else{
            le[demLe] = m.mang[i];
            demLe++;
        }
    }
    sort(chan,chan+demChan);
    sort(le,le+demLe);
    for(int i = 0;i < demChan;i++){
        m.mang[i] = chan[i];
    }
    for(int i = 0;i < demLe;i++){
        m.mang[demChan+i] = le[i];
    }
}
template<typename T>
mang1c<T> tong2Mang(mang1c<T> m1,mang1c<T> m2){
    mang1c<T> kq;
    int _max = m1.soPtu > m2.soPtu ? m1.soPtu : m2.soPtu;
    int _min = m1.soPtu < m2.soPtu ? m1.soPtu : m2.soPtu;
    kq.soPtu = _max;
    if(m1.soPtu >= m2.soPtu){
        for(int i = 0;i < m1.soPtu;i++){
            kq.mang[i] = m1.mang[i];
        }
    }
    else if(m1.soPtu < m2.soPtu){
        for(int i = 0;i < m2.soPtu;i++){
            kq.mang[i] = m2.mang[i];
        }
    }
    for(int i = 0;i < _min;i++){
        kq.mang[i] = m1.mang[i] + m2.mang[i];
    }
    return kq;
}
void sortGiam(mang1c<int> &m){
    // sort(m.mang,m.mang+m.soPtu,soSanh);
    int le[m.soPtu],demLe = 0;
    int chan[m.soPtu],demChan = 0;
    for(int i = 0;i < m.soPtu;i++){
        if(m.mang[i]%2 != 0){
            le[demLe] = m.mang[i];
            demLe++;
        }
        else{
            chan[demChan] = m.mang[i];
            demChan++;
        }
    }
    sort(le,le+demLe,soSanh);
    sort(chan,chan+demChan,soSanh);
    for(int i = 0;i < demLe;i++){
        m.mang[i] = le[i];
    }
    for(int i = 0;i < demChan;i++){
        m.mang[demLe + i] = chan[i];
    }
}
 
///////////////////////////////////////////////////////////////////////////////////
//vector1
/*
Nhập vào một dãy số dùng vector.
yêu cầu dùng iterator để xuất ra màn hình
- Dòng 1 xuất theo chiều thuận (từ begin() đến end() )
- Dòng 2 xuất theo chiều ngược (từ rbegin() đến rend() )
 
ví dụ:
input:
1 2 3
output
1 2 3
3 2 1
 
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
 
using namespace std;
 
int main(){
    int x;
    vector<int> v;
    while(cin>>x){
        v.push_back(x);
    }
    vector<int>::iterator it;
    for(it=v.begin(); it<v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=v.end()-1; it>=v.begin(); it--){
        cout<<*it<<" ";
    }
    return 0;
}
-------------------------------
#include<bits/stdc++.h>
using namespace std;
 
int main(){
vector <int> mang;
 
int n;
while (cin>>n)
mang.push_back(n);
 
for(int i=0;i<mang.size();i++)
cout<<mang[i]<<" ";
cout<<endl;
int z=mang.size();
 
for (int i=0;i<z-1;i++)
for (int j=i;j<z;j++)
{
if (mang[i]<mang[j])
swap(mang[i],mang[j]);
}
 
for(int i=0;i<mang.size();i++)
cout<<mang.at(i)<<" ";
 
return 0;
}
-------------------------------------
// Làm quen nhập xuất.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
 
//#include "pch.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
 
 
int main()
{
	vector<int> v;
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
 
	ostream_iterator<int> output(cout, " ");
	copy(v.begin(), v.end(), output);
	cout << endl;
	copy(v.rbegin() ,v.rend(), output);
 
	return 0;
}
 
--------------------------------
//#include "pch.h"
#include <iostream>
#include <math.h>
#include <string>
#include <cstdio>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
void thuan(vector<int> v)
{
	vector <int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
}
void nguoc(vector<int> v)
{
	vector <int>::reverse_iterator it;
	for (it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << *it << " ";
	}
}
int main()
{
	vector<int> v;
	
	int x;
	while (cin >> x)
	{
		v.push_back(x);
	}
	thuan(v);
	cout << endl;
	nguoc(v);
	cout << endl;
	
//	system("pause");
	return 0;
}
////////////////////////////////////////////////////////////////////////
//vector2
/*
Nhập:
 
Dòng 1: nhập vị trí cần xóa hoặc đoạn cần xóa [a,b), hoặc nếu là -1 thì xóa hết dãy
Dòng 2: nhập vào 1 dãy số
 
Xuất:
mảng sau khi xóa, nếu dãy rỗng xuất ra chữ "empty"
 
ví dụ 1:
input:
2
1 2 3 4
 
output:
1 2 4
 
ví dụ 2:
input:
1 3
1 2 3 4
 
output:
1 4
 
 
*/
//#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int epSo(string s)
{
	int sum = 0;
	for (int i = 0; i < s.length(); ++i) {
		sum = sum * 10 + (int)s[i] - 48;
	}
	return sum;
}
 
int main()
{
	vector<int> v;
	string s, s1[2];
	getline(cin, s);
	int n;
	while (cin >> n)
	{
		v.push_back(n);
	}
	int temp = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != ' ') {
			s1[temp] += s[i];
		}
		else
			temp++;
	}
	//cout << temp << endl;
	if (temp == 0)
	{	
		if (s1[0] == "-1")
		{
			v.clear();
		}
		else
		{
			int k = epSo(s1[0]);
			v.erase(v.begin() + k);
		}
	}
	else
	{
		int k = epSo(s1[0]);
		int l = epSo(s1[1]);
		v.erase(v.begin() + k, v.begin() + l);
	}
	if (v.empty())
	{
		cout << "empty";
		return 0;
	}
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
 
	return 0;
}
------------------------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int ChuoiSo(string s);
 
int main(){
    vector<int> v;
    string s, opt[2];
    int n;
    getline (cin,s);
    
    while(cin>>n){
        v.push_back(n);
    }
    
    int spt=0;
    for(int i=0;i<s.size();i++){
        if(s[i] != ' '){
            opt[spt] +=s[i];
        }
        else
            spt++;
    }
    spt++;
    
    if(spt==1){
        if(opt[0]=="-1"){
            v.clear();
        }
        else{
            int a=ChuoiSo(opt[0]);
            v.erase(v.begin()+a);
        }
    }
    else if(spt==2){
        int b,c;
        b=ChuoiSo(opt[0]);
        c=ChuoiSo(opt[1]);
        v.erase(v.begin()+b, v.begin()+c);
    }
    
    if(!v.empty()){
        vector<int>::iterator it;
        for(it=v.begin(); it != v.end(); it++){
            cout<< *it <<" ";
        }
    }
    else
        cout<<"empty";
    
    return 0;
}
int ChuoiSo(string s){
	int so = 0, n = s.size();
	for (int i = 0; i < n; i++)
		so = so * 10 + (int)(s[i] - 48);
 
	return so;
}
--------------------------------------------
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    stringstream ss(s);
    int x;
    vector <int> v1;
    while(ss >> x){
        v1.push_back(x);
    }
    vector <int> v2;
    while(cin >> x){
        v2.push_back(x);
    }
    if (v1.size() == 1){
        if(v1[0] == -1){
            v2.clear();
        }
        else
        v2.erase(v2.begin() + v1[0]);
    }
    else
    v2.erase(v2.begin() + v1[0], v2.begin()+ v1[1]);
    if(v2.empty()){
        cout << "empty";
    }
    else{
    for(int i=0;i<v2.size();i++){
        cout << v2[i] << " ";
    }
    }
}
 
///////////////////////////////////////////////////////////////////////////
//vector
//tổng chữ số không nguyên tố
/*
Viết chương trình hoàn chỉnh cho bài toán sau:
Nhập vào một dãy số nguyên dương gồm N phần tử theo cấu trúc:
- Dòng đầu ghi số nguyên dương N.
- N dòng tiếp theo, mỗi dòng ghi một số nguyên dương.
Yêu cầu: Xét mọi số nguyên trong dãy đã cho, nếu số đó là số nguyên tố thì yêu cầu tính tổng các chữ số không phải là số nguyên tố của nó, ngược lại xuất -1.
 
Ví dụ
input
3
28
9817
23
output
-1
18
0
 
*/
#include <iostream>
using namespace std;
bool ktSNT(int a) {
	if (a == 2 || a == 3)
	{
		return true;
	}
	else if (a == 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i < a; i++)
		{
			if (a%i == 0)
			{
				return false;
			}
		}
	}
	return true;
}
int tinhTongSNT(int a) {
	int tong = 0;
	if (ktSNT(a)) {
		while (a >= 10)
		{
			int k = a % 10;
			if (!ktSNT(k))
			{
				tong = tong + k;
			}
			a /= 10;
		}
		if (a < 10) {
			if (!ktSNT(a))
			{
				tong = tong + a;
			}
		}
 
	}
	return tong;
}
int main() {
	int n, a[100], spt;
	cin >> spt;
	for (int i = 0; i < spt; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < spt; i++)
	{
		if (!ktSNT(a[i]))
		{
			cout << -1 << endl;
		}
		else {
			cout << tinhTongSNT(a[i]) << endl;
		}
	}
	//system("pause");
	return 0;
}
-------------------------------
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
bool  SoNT(int x) {
	if (x == 1 || x == 0) {
		
		return false;
	}
	int count = 0;
	for (int i = 2; i <= x; i++) {
		if ((x % i)==0) {
			count ++ ;
			//cout << "count" << i << count << endl;
 
		}
		//cout << "count"<<i<<count << endl;
	}
	if (count == 1) {
		//cout << "true";
	    return true;
	}
	else {
		return false;
	}
}
int TongSo(int x) {
	int Sum = 0;
	int x_ = x;
	
	while (x_!= 0) {
	   int z = x_ % 10;
		if (!(SoNT(z))) {
			Sum =Sum+ z;
		}
		x_ = x_ / 10;
	}
	return Sum;
}
int main() {
	int x;
	cin >> x;
	int a[10];
	for (int i = 0; i < x; i++) {
		cin >> a[i];
	}
	
for (int i = 0; i < x; i++) {
		if (!SoNT(a[i])) {
			cout << -1 << "\n";
		}
		else {
		
			cout << TongSo(a[i]) << "\n";
		}
	}
}
 
 
////////////////////////////////////////////////////////////////////////////////////////
//vector3
//loại bỏ số chính phương
/*
Sử dụng container vector, anh/chị hãy viết chương trình đọc vào các số nguyên, sau đó loại bỏ các số chính phương trong vector rồi xuất ra các số chẵn theo thứ tự tăng dần.
 
ví dụ:
input
7 6 5 4 3 2 1
output
2 6
 
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <cmath>
#include <algorithm>
using namespace std;
 
bool ktCP(int a);
bool chan(int a);
void printVector(const std::vector< int > &integers2);
int main()
{
	vector<int> a;
	int x;
	vector<int>::iterator re;
	while (cin >> x)
	{
		a.push_back(x);
	}
	re = remove_if(a.begin(), a.end(), ktCP);
	a.erase(re, a.end());
	re = remove_if(a.begin(), a.end(), chan);
	a.erase(re, a.end());
	sort(a.begin(), a.end());
	printVector(a);
}
void printVector(const std::vector< int > &integers2)
{
	std::vector< int >::const_iterator constIterator;
	for (constIterator = integers2.begin(); constIterator != integers2.end(); constIterator++)
		cout << *constIterator << ' ';
}
bool ktCP(int a)
{
	if (sqrt(a) * sqrt(a) == a)
		return true;
	else
		return false;
}
 
bool chan(int a)
{
	if (a % 2 != 0)
		return 1;
	else
		return 0;
}
 
------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
void xuat (vector<int> a) {
    for (int i = 0 ; i < a.size() ; ++i) cout << a[i] << " ";
}
 
bool kiem_tra_so_chinh_phuong (int a) {
    int i = sqrt (a);
    if (i*i == a) return true;
    else return false;
}
 
void xoa_bo (vector<int> &a) {
    for (int i = 0 ; i < a.size() ; ++i) {
        if (kiem_tra_so_chinh_phuong (a[i]) == true || a[i] % 2 != 0) {
            a.erase (a.begin() + i);
            --i;
        }
    }
}
 
void hoan_vi (int &a , int &b) {
    int c = a;
    a = b;
    b = c;
}
 
void sap_xep_tang_dan (vector<int> a) {
    for (int i = 0 ; i < a.size() - 1 ; ++i) {
        for (int j = i + 1 ; j < a.size() ; ++j) if (a[i] > a[j]) hoan_vi (a[i] , a[j]);
    }
    xuat (a);
}
 
int main() {
    vector<int> a;
    int x;
    while (cin >> x) a.push_back(x);
    xoa_bo (a);
    sap_xep_tang_dan (a);
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////

 
 
 
ĐỆ QUY
//LASTNUM
//So cuoi cung
/*
Một LASTNUM được xác định là tổng các chữ số của số đó, sau đó lại tiếp tục tính tổng các chữ số của số mới tạo ra cho đến khi chỉ còn 1 chữ số duy nhất.
Nhờ bạn hãy giúp tìm ra số cuối cùng đó nhé!
Yêu cầu: Cho số N, bạn hãy tìm LASTNUM của số đó.
Dữ liệu nhập:
  Gồm 1 số nguyên N duy nhất (1 ≤ N ≤ 101000000).
Dữ liệu xuất:
  Gồm 1 số nguyên duy nhất là LASTNUM tìm được.
Ví dụ
input
79
output
7
Các số được tạo ra lần lượt là 79 ➔ 16 ➔  7
 
*/
#include <iostream>
#define lli long long int
using namespace std;
lli tong(lli x)
{
    lli sum=0;
    while (x!=0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
 
lli Try(lli n)
{
    if (n<10)
        return n;
    else
        return Try(tong(n));
}
int main()
{
    lli x;
    cin>>x;
    cout<<Try(x);
    return 0;
}
----------------------------------
#include<iostream>
using namespace std;
int tongcs(int x){
    int tong=0;
    while(x!=0){
        tong=tong+x%10;
        x=x/10;
    } return tong;
}
int lastnum(int x){
    while(x/10!=0){
        x=tongcs(x);
    } return x;
}
int main(){
    int n;
    int tong=0;
    while(cin>>n){
        tong+=lastnum(n);
    } cout<<tong;
    return 0;
}
 
///////////////////////////////////////////////////
//gameboo
//tro choi boo
/*
Sinh viên Sư Phạm đang chuẩn bị chơi trò “Boo”. Mọi người đứng trên một hàng dài, trong đó mỗi người trong hàng sẽ nói to một chữ cái nhanh nhất có thể. Ai nói sai đầu tiên thì sẽ bị xử thua.
 
Dãy các kí tự “Boo” có thể kéo dài liên tục và không giới hạn. Chúng sẽ bắt đầu như sau:
b o o b o o o b o o b o o o o b o o b o o o b o o b o o o o
 
Dãy kí tự trên được diễn tả như sau:
Gọi S(0) là dãy ba kí tự “b o o”.
Sau đó dãy kí tự S(k) sẽ bằng dãy S(k-1) và thêm vào “b o … o” với k+2 chữ o, và sau đó cộng thêm một lần nữa dãy S(k-1). 
Ví dụ:
S(0) = "b o o"
S(1) = "b o o b o o o b o o"
S(2) = "b o o b o o o b o o b o o o o b o o b o o o b o o"
Với cách này sẽ tạo được dãy kí tự rất dài, và dãy này sẽ dùng cho game "Boo".
 
Tèo là 1 trong số các sinh viên tham gia trò chơi "Boo". Tèo rất thông minh nên sẽ tính trước được kí tự thứ N của dãy này là chữ “b” hay chữ “o”. Tèo đố bạn đáp số là gì?
 
Input:
Dòng 1: số nguyên dương T - số lượng test (T <= 10)
T dòng tiếp theo, mỗi dòng gồm một số nguyên N (1 <= N <= 10^9). 
Output:
T dòng, mỗi dòng chứa duy nhất kí tự “b” hoặc “o” (đáp số của từng câu hỏi mà Tèo đưa ra)
 
Ví dụ:
Input
2
11
24
Output:
b
o
Giải thích: Ký tự thứ 11 trong dãy trên là b và ký tự thứ 24 trong dãy là o
 
*/
#include <iostream>
 
using namespace std;
 
/* Tính độ dài của dãy S(k) */
int len(int k){
	int x;
	if (k == -1) 
		return 0;
	x = len(k - 1);
	
	return x + k + 3 + x;
}
 
/* Trả về ký tự thứ n trong dãy S(k) */
char solve(int n, int k){
	if (n > len(k)) 
		return solve(n, k + 1);
	if (n <= len(k - 1)) 
		return solve(n, k - 1);
	n = n - len(k - 1); /* Bỏ đi dãy S(k-1) tính từ vị trí đầu tiên */
	if (n <= k + 3) /* kiểm tra xem n có nằm ở đoạn giữa hay không ? */
		return (n == 1) ? 'b' : 'o';
	n = n - (k + 3);
	
	return solve(n, k - 1);
}
 
int main(){
	long T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << solve(n, 0) << endl;
	}
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//LTNC
//Final01
/*
Hãy sử dụng kĩ thuật đệ quy để tính giá trị sin và cos (độ chính xác 0.0001) của một giá trị số thực x (radian) theo công thức sau:
sin(x) = x – x3/3! + x5/5! + … + (-1)n(x2n+1/(2n+1)!)
cos(x) = 1 – x2/2! + x4/4! + … + (-1)n(x2n/(2n)!)
Lưu ý: 
chương trình phải sử dụng kĩ thuật đệ quy 
không dùng các hàm toán học sin, cos trong thư viện để tính toán
 
Input: Giá trị số thực x
Output: dòng đầu tiên là giá trị sin(x), làm tròn 2 số lẻ; dòng thứ hai là giá trị cos(x), làm tròn 2 số lẻ
 
Vd:
Input:
1
Ouput
0.84
0.54
 
Hướng dẫn cách làm tròn:
Ví dụ: làm tròn n tới 3 chữ số thập phân ==> dùng hàm roundf(n * 1000) / 1000
 
*/
#include <iostream>
#include <math.h>
 
using namespace std;
float LuyThua(int n,float x){
    float s=1;
    for(int i=0;i<n;i++){
        s=s*x;
    }
    return s;
}
float GiaiThua(int n){
    float s=1;
    for(int i=1;i<=n;i++){
        s=s*i;
    }
    return s;
}
float Mu(int n){
    float s=1;
    for(int i=0;i<n;i++){
        s=s*(-1);
    }
    return s;
}
float Sin(int n,float x){
    if(n==0) return x;
    return Sin(n-1,x) + Mu(n)*( LuyThua(2*n+1,x)/GiaiThua(2*n+1) );
}
float Cos(int n,float x){
    if(n==0) return 1;
    return Cos(n-1,x) + Mu(n)*( LuyThua(2*n,x)/GiaiThua(2*n) );
}
 
int main(){
    float x;
    int n=10;
    cin>>x;
    cout<<roundf(Sin(n,x)*100)/100<<endl;
    cout<<roundf(Cos(n,x)*100)/100;
}
////////////////////////////////////////////////////////////////////////////
//DAYSO
/*
Cho một dãy số được cho theo quy tắc sau:
a0 ­= 0
a1 = 1
 
a2i = ai
a2i+1 = ai+ai+1
với i = 1, 2, 3, …
 
Cho một số n, hãy viết chương trình đệ quy tìm số lớn nhất trong các số a0, a1, a2, a3, …, an
Input:
o  Nhập vào một con số nguyên n (1 ≤ n ≤ 900)
Output:
o  Xuất ra giá trị lớn nhất tìm thấy.
Ví dụ:
Input
Output
5
 
3
 
 
 
*/
#include <iostream>
 
using namespace std;
 
int Func(int n){
    if (n == 0 || n == 1){
        return n;
    }
    else{
        if (n%2 == 0){
            return Func(n/2);
        }
        else{
            return Func(n/2) + Func(n/2 + 1);
        }
    }
}
 
int main(){
    int n;
    cin >> n;
    int t = 0;
    for (int i=1; i<=n; i++){
        if (t < Func(i)){
            t = Func(i);
        }
    }
    cout << t;
}
 
//////////////////////////////////////////////////////-----------------------------------
// DEQUY9
//ôn tập đệ quy
/*
Cho tổng S(n) = 1 + (1+2) + (1+2+3) + (1+2+3+4) + .... + (1+2+3+4+...+n)
và tổng P(n) = 1 + 1.2 + 1.2.3 + 1.2.3.4 + .... + 1.2.3.4....n
 
với n là số nguyên dương.
 
Hãy viết hàm đệ quy để tính 2 tổng trên với số n nhập từ bàn phím (n<=20)
 
Ví dụ:
input
3
output
S(3) = 10    (Lưu ý: có khoảng trắng phía trước và sau dấu "=")
P(3) = 9
 
input
5
output
S(5) = 35
P(5) = 153
 
Lưu ý: PHẢI sử dụng ĐỆ QUY để làm bài này.
 
*/
#include<iostream>
using namespace std;
 
long tongS(int n);
long tongP(int n);
int main(){
    int n;
    cin>>n;
    cout<< "S("<<n<<")="<<tongS(n)<< endl;
    cout<< "P("<<n<<")="<<tongP(n)<< endl;
    return 0;
}
long tongS(int n){
    if( n==1)return 1;
    else{
        long S=0;
        for (int i=0; i<=n; i++){
            S+=i;
        }
        return S+ tongS(n-1);
    }
}
long tongP( int n){
    if (n==1) return 1;
    else{
        long S=1;
        for( int i=1;i<=n; i++){
            S*=i;
        }
        return S+ tongP(n-1);
    }
}
 
 
 
 
/////////////////////////////////////////////////////////////////////
//CONNECT
/*
Cho n số nguyên dương a1,a2,…,ai,…an (a[i] <=109). Từ các số nguyên này người ta tạo ra một số nguyên mới bằng cách kết nối tất cả các số đã cho viết liên tiếp nhau. Ví dụ, với n = 4 và các số 12, 34, 567, 890 ta có thể tạo ra các  số mới như sau: 1234567890, 3456789012, 8905673412, …. Dễ thấy rằng có 4! = 24 cách tạo mới như vậy. Trong trường hợp này, số lớn nhất có thể tạo thành là 8905673412.
Yêu cầu: cho n các số a1,a2,…,ai,…,an. Hãy xác định số lớn nhất có thể kết nối được theo quy tắc trên.
Hãy in ra một cách nối các số đó lại với nhau sau cho đạt được số lớn nhất.
Dữ liệu vào: cho trong file văn bản CONNECT.INP gồm n+1 dòng
          - Dòng đầu là số N. (0 < N <= 100)
          - Trong các dòng còn lại, dòng thứ  i + 1 ghi số ai
Dữ liệu ra: Ghi vào file văn bản CONNECT.OUT số lớn nhất được kết nối thành từ các số ban đầu
 
ví dụ:
 
CONNECT.INP   
4
12
34
567
890   
 
CONNECT.OUT
8905673412
*/
#include <iostream>
#include <string.h>
#include <fstream>
 
using namespace std;
const int maxc = 10000, maxcc = 1000;
struct td{
    string c, t;
}s[maxc];
fstream fi, fo;
int n;
bool Free[maxc];
int max_length = 0;
string s_X[maxc];
string Res;
 
void Nhap(){
    fi >> n;
 
    for (int i=1; i<=n; i++){
        fi >> s[i].c;
        while ((s[i].c)[0] == '0'){
            (s[i].c).erase(0,1);
        }
        s[i].t=  s[i].c;
        if ((s[i].c).length() > max_length){
            max_length = (s[i].c).length();
        }
    }
    Res = '0';
    memset(Free, true, sizeof(Free));
}
 
 
void SapXep(){
    for (int i=1; i <= n-1; i++){
        for (int j=i+1; j<=n; j++){
            if (s[i].t + s[j].t < s[j].t + s[i].t){
                swap(s[i], s[j]);
            }
        }
    }
}
 
void Xuly(){
    for (int i=1; i<=n; i++){
        while ((s[i].c).length() < max_length){
            s[i].c = s[i].c + "0";
        }
    }
    SapXep();
    for (int i=1; i<=n; i++){
        fo << s[i].t;
    }
}
 
/*
void QuayLui(int i){
    for (int j=1; j<=n; j++){
        if (Free[j]){
            s_X[i] = s[j];
            if (i == n){
                string s_p = "";
                for (int k=1; k<=n; k++){
                    s_p = s_p + s_X[k];
                }
                if (Res < s_p){
                    Res = s_p;
                }
            }
            else{
                Free[j] = false;
                QuayLui(i+1);
                Free[j] = true;
            }
        }
    }
}
 
void Xuat(){
    fo << Res;
}
*/
 
int main(){
    fi.open("CONNECT.INP", ios::in);
    fo.open("CONNECT.OUT", ios::out | ios::trunc);
    Nhap();
    Xuly();
    //QuayLui(1);
    //Xuat();
    fi.close();
    fo.close();
}
 
-------------------------------
#include <iostream>
#include <fstream>
using namespace std;
 
ifstream ifile("CONNECT.INP");
ofstream ofile("CONNECT.OUT");
int main(){
    int n;
    ifile>>n;
    string s[10000];
    for(int i=0; i<n;i++){
        ifile>>s[i];
    }
    ifile.close();
    for(int i=0;i<n-1;i++){
        for(int j=i+1; j<n; j++){
            if(s[i]+s[j]<s[j]+s[i])
            swap(s[i],s[j]);
        }
    }
    for(int i=0; i<n;i++){
        ofile<<s[i];
    }
    ofile.close();
    return 0;
}
////////////////////////////////////////////////////////////
//palindrom
/*
Một số nguyên gọi là palindrom nếu nó đọc từ trái sang cũng bằng đọc từ phải sang. Ví dụ 121 là số palindrom.
Yêu cầu:
-         Hãy xây dựng hàm kiểm tra một số có phải là palindrom hay không?
-         Viết chương trình sử dụng hàm đã viết để in ra các số palindrom.
 
Dữ liệu vào trong gồm n + 1 dòng:
-         dòng đầu ghi số n ( 0 < n < 1000 )
-         n dòng còn lại mỗi dòng ghi một số nguyên dương m (0< m <106)
Kết quả in ra màn hình các số Palindrom
 
Ví dụ: 
4
102
121
250
9889
 
Kết quả xuất ra màn hình các số Palindrom là:  
121   9889
*/
#include<iostream>
using namespace std;
bool Palindrom(int a){
    int p;
    int b=a;
    int s=0;
    while (a>0){
        p=a%10;
        s=s*10+p;
        a=a/10;
    }
    if (s==b)
    return true;
    return false;
    
}
int main(){
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        if (Palindrom(a[i]))
        cout << a[i] <<  " ";
    }
    return 0;
}
-----------------------------------
#include <iostream>
using namespace std;
bool Palindrom(int n ) {
    int r,sum=0,a;
    a=n;  
    while(n>0)  
    {  
        r=n%10;  
        sum=(sum*10)+r;  
        n=n/10;  
    }  
    if(a==sum)
        return true;
    else  
        return false;
    
}
void Input(int a[], int n){
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
}
int main()  
{  
    int a[100];
    int n;
    cin >> n;
    Input(a,n);
    for ( int i = 0; i<n;i++){
    if( Palindrom(a[i]) == true )
    cout<< a[i]<< " ";
    }
    return 0;
}
/////////////////////////////////////////////////////////////
//Catalan
/*
Ta gọi dãy Catalan là dãy Cn được định nghĩa bởi công thức sau:

 
Hãy tính giá trị của dãy Catalan ứng với mỗi số nguyên dương n nhập từ bàn phím.
 
Dữ liệu vào: gồm nhiều dòng, mỗi dòng là một số nguyên dương.
Dữ liệu ra:giá trị của dãy Catalan ứng với từng input.
 
Ví dụ:
Input:
2
3
4
 
Output:
2
5
14
*/
#include <iostream>
using namespace std;
 
long catalan(int n);
 
long catalan(int n)
{
	long s = 0;
	if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		
		for (int i = 0; i < n; i++)
		{
			s += catalan(i)*catalan(n-i-1);
		}
	}
 
	return s;
 
}
int main()
{
	int n;
	while (cin>>n)
	{
		cout << catalan(n) << endl;
	}
	return 0;
 
}
 
//////////////////////////////////////////////////////////////////////
//DEQUY8
//Tổ Hợp Chập K
/*
Tổ Hợp Chập K
 
Nhập vào số nguyên dương n và số nguyên k (1 <= k <= n) và sử dụng phương pháp đệ quy in ra giá trị C(n,k) của tổ hợp chập k của n bằng cách dựa vào công thức: C(n, k) = C(n-1, k) + C(n-1, k-1), biết C(n, n) = 1, C(n, 1) = n
 
input: gồm 2 số n và k 
 
Output: Giá trị C(n, k)
 
input :
5 3 
ouput:
10
 
*/
//////////////////////////////////
//DEQUY7
//Dãy Fibonacy
/*
Dãy Fibonacy
 
Dãy số fibonacy được định nghĩa như sau:
f1 = f2 = 1
fn = fn-1 + fn-2  (với n >= 3)
Bạn hãy viết chương trình sử dụng đệ quy in ra n số đầu tiên của dãy số fibonacy.
 
Dữ liệu nhập:
là số nguyên n (1<= n <= 40)
 
Dữ liệu xuất:
Là n số fibonacy đầu tiên trên cùng một dòng, mỗi số cách nhau một khoảng trắng.
 
input:
5
output:
1 1 2 3 5
 
*/
#include <iostream>
using namespace std;
 
int fibonacy(int n);
 
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cout << fibonacy(i) << " ";
    }
    return 0;
}
 
int fibonacy(int n){
    
    if (n == 1 || n == 2) {
        return 1;
    }
     return fibonacy(n-1)+fibonacy(n-2);
}
 
/////////////////////////////////////////////////////////////
//DEQUY6
// Tính tổng 3
 
/*
Tính Tổng 3
 
dùng phương pháp ĐỆ QUY để tính tổng sau : 
 
S(n) = x - x3/3! + x5/5! + .... + ((-1)n)*(x2n+1/(2n+1)!) 
 
dữ liệu input: n và x
 
dữ liệu ra output : Tổng S (làm tròn đến 3 chữ số thập phân)
 
lưu ý : dùng hàm roundf(n * 1000) / 1000 để làm tròn n tới 3 chữ số thập phân 
 
input :
5 2
output:
0.909
 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
float tong(int n,int x);
float giaithua(int n);
 
int main()
{
    int n,x;
    cin >> n >> x;
    cout << roundf(tong(n,x) * 1000) / 1000;
}
 
float tong(int n, int x)
{
    if(n == 0) return x;
    if(!(n % 2))
        return tong(n-1, x) + (pow(x, 2*n+1)/giaithua(2*n+1));
    else 
        return tong(n-1, x) + (-1)*(pow(x, 2*n+1)/giaithua(2*n+1));
}
float giaithua(int n)
{
    if(n == 1) return 1;
    return n * giaithua(n - 1);
}
 
///////////////////////////////////////////////
//DEQUY5
//Tính tổng 2
/*
Tính tổng 2
sử dụng phương pháp ĐỆ QUY tính tổng sau : 
 
S(n) = 1 + x + x3/3! + x5/5! + .... + x2n+1/(2n+1)!
 
Dữ liệu input: chứa n và x (0
 
Dữ liệu output : Tổng S (làm tròn tới 3 chữ số thập phân)
 
Lưu ý : dùng hàm roundf(n * 1000) / 1000 để làm tròn n tới 3 chữ số thập phân 
 
input :
5 2
output:
4.627
 
*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
 
long gthua(int n){
    if(n==1||n==0)
        return 1;
    else
        return n* gthua(n-1);
}
 
double tong(int n,int x){
    if(n==0)
        return x;
    else{
        return pow(x,2*n+1)/gthua(2*n+1) + tong(n-1,x);
    }    
}
 
int main(){
    int n,x;
    cin>>n>>x;
    double s= 1+tong(n,x);
    cout<<roundf(s*1000)/1000<<endl;
    //<<setprecision(3)<<fixed << s;
    return 0;
}
/////////////////////////////////////////////////////
//DEQUY4
// Tính tổng
/*
Tính tổng 
tính tổng theo công thức sau bằng phương pháp ĐỆ QUY: 
 
S(n) = 1 + x + x2 + x3 + ..... + xn 
 
dữ liệu nhập: số n và x
 
dữ liệu xuất: tổng S
 
input:
5 2
output
63
 
*/
#include <iostream>
using namespace std;
long gt(int , int );
long S(int , int );
int main(){
    int p,x;
    cin>>x>>p;
    cout<<S(p,x);
    return 0;
}
long gt(int p, int x){
    if(x==0) return 1;
    else
    return gt(p,x-1)*p;
}
long S(int p,int x){
    if(x==0) return 1;
    else
    return S(p,x-1) + gt(p,x);
}
/////////////////////////////////////////////////
//DEQUY3
// Liệt kê chỉnh hợp không lặp chập k
/*
Liệt kê chỉnh hợp không lặp chập k
 
liệt kê chỉnh hợp không lặp chập k của tập n phần tử S = {1, 2, 3, 4, ..... , n }
Dữ liệu nhập:
- Gồm hai số nguyên k và n cách nhau 1 khoảng trắng (1 ≤ k ≤ n ≤ 9)
Dữ liệu xuất:
mỗi dòng là một chỉnh hợp chập k
 
input:
2 3
output:
12
13
21
23
31
32
 
*/
#include<iostream>
#include<cmath>
using namespace std;
int k,n,a[100];
bool b[10];
int Try(int i);
int main(){
    cin>>k>>n;
    Try(0);
    return 0;
}
int Try(int i){
    if(i>=k)
    {
        for(int m=0;m<k;m++){
            cout<<a[m]<<endl;
        }
    }
    else{
        for(int j=1;j<=n;j++)
        {
            if(!b[j]){
            a[i]=j;
            b[j]=true;
            Try(i+1);
            b[j]=false;
            }
        }
    }
}
//////////////////////////////////////////////////////////
//DEQUY2
//Liệt kê chuỗi hoán vị
/*
Liệt kê chuỗi hoán vị
Cho n chữ số 1, 2, 3, .., n (1 ≤ n ≤ 8), hãy liệt kê tất cả các hoán vị của n chữ số trên theo thứ tự từ điển.
Dữ liệu nhập:
- Là số nguyên n (1 ≤ n ≤ 8)
Dữ liệu xuất:
- Dòng thứ nhất là số nguyên m thể hiện số lượng hoán vị có được.
- Trong m dòng tiếp theo, mỗi dòng liệt kê một hoán vị theo thứ tự từ điển. Trong một hoán vị các chữ số đứng sát nhau (không dùng khoảng trắng để ngăn cách các chữ số)
 
Ví dụ
input
2
output
2
12
21
 
input
3
output
6
123
132
213
231
312
321
 
*/
#include<iostream>
#include<vector>
using namespace std;
 
int count=0,sum=0;
char x;
int size;
bool check[1000];
vector<string>X;
string res;
void dequy(char n) {
    if(count==size){sum++;X.push_back(res);}
    else {
        for(char i='1';i<=size+48;i++)
        if(check[i]==false){
        res+=i;
        check[i]=true;
        count++;
        dequy(i);
        check[i]=false;
        count--;
        res.erase(res.size()-1,1);
        }
    }
}
 
int main() {
 cin>>size;
 dequy(1);
 cout<<sum<<endl;
 for(int i=0;i<X.size();i++)cout<<X[i]<<endl;
}
 
/////////////////////////////////////////////
//DEQUY
//
/*
Cho k chữ số 1, 2, 3, ..., k (1 ≤ k ≤ 9), hãy liệt kê các chuỗi k-phân có chiều dài n theo thứ tự từ điển (xem ví dụ để hiểu rõ hơn chuỗi k-phân).
Dữ liệu nhập:
- Gồm hai số nguyên k và n cách nhau 1 khoảng trắng (1 ≤ k ≤ 9, 1 ≤ n ≤ 5)
Dữ liệu xuất:
- Dòng đầu tiên là một số nguyên m - số lượng chuỗi k-phân tính được.
- Trong m dòng tiếp theo, mỗi dòng là một chuỗi k-phân, các dòng sắp theo thứ tự từ điển.
Ví dụ
                                            
 
*/
 
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int dem = 0;
int p[100];
int sl;
void Nhap(vector<int>&a, vector<int>&b, int &n){
	cin >> n;
	cin >> sl;
	for (int i = 0; i <= n; i++){
		b.push_back(1);
	}
}
 
void Xuly(int n){
	
	for (int i = 1; i <= sl; i++){
		cout << p[i] << " ";
	}
	cout << endl;
}
void Hoanvi(vector<int>&b, int n, int k){
	for (int i = 1; i <= n; i++){
		if (b[i]){
			p[k] = i;
			b[i] = 0;
			if (k == sl){
				Xuly(n);
				
			}
			else{
				b[i] = 1;
				Hoanvi(b, n, k + 1);
			}
			b[i] = 1;
		}
	}
}
int main(){
	vector<int>a, b;
	int n;
	Nhap(a, b, n);
	cout << pow(n, sl) << endl;
	Hoanvi(b, n, 1);
	//system("pause");
	return 0;
}
//////////////////////////////////////////////////////
//UCLN
/*
Nhập vào 2 số nguyên a và b.
Yêu cầu tìm UCLN của 2 số đó.
 
ví dụ
input:
10 8
 
output
2
*/
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    int ucln;
    cin>>a>>b;
    if (a==0) ucln=b;
    else if (b==0) ucln=a;
    else{
        while (a!=b)
        {
            if (a>b) a-=b;
            else b-=a;
        }
        ucln=a;
    }
    cout<<ucln;
    return 0;
}
////////////////////////////////////////////////////////
// đổi cơ số 10 sang 2
//DOICS10_2
/*
Nhập vào 1 số nguyên ở hệ 10, yêu cầu xuất ra 1 số ở hệ 2
 
vi dụ:
input:
10
 
output:
1010
*/
#include <iostream>
using namespace std;
int main()
{
    long dec,rem,i=1,sum=0;
    
    cin>>dec;
    do
    {
        rem=dec%2;
        sum=sum + (i*rem);
        dec=dec/2;
        i=i*10;
    }while(dec>0);
    cout<<sum<<endl;
    cin.get();
    cin.get();
 
    return 0;
}
 
//////////////////////////////////
//DAYNP
// dãy nhị phân
/*
Xuất tất cả dãy nhị phân có độ dài là n.
input gồm 1 số tự nhiên n, n>=1
Ouput: xuất tất cả dãy số nhị phân có độ dài n, theo thứ tự tăng dần (mỗi dãy là 1 một dòng)
 
Ví dụ:
Input:
3
output:
000
001
010
011
100
101
110
111
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, a[100];
 
void print(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << endl;
}
void trans(int a[], int n, int pos) {
    for(int i = pos; i < n; ++i) {
        a[i] = 0;
    }
}
void search(int a[], int n) {
    print(a,n);
    int i = n - 1;
    while(i > 0) {
        if(a[i] == 1)   
            i--;
        if(a[i] == 0) {
            a[i] = 1;
            trans(a, n, i + 1);
            print(a, n);
            i = n - 1;
        }
    }
}
 
int main() {
    cin >> n;
    if(n == 1) 
        cout << 0 << endl << 1;
    else 
        search(a, n);
    
    
    return 0;
}
///////////////////////////////////////////////////////
//TONGCS
//tổng chữ số
/*
Viết một chương trình đệ quy tính tổng các chữ số của số N cho trước   (N<= 123456789)
 
Ví dụ: 
 
Input: 123 
 
Ouput: 6 
 
(vì : 1+2+3 =6)
 
*/
#include <iostream>
 
using namespace std;
int n;
 
void Nhap(){
    cin >> n;
}
 
int S(int n){
    return (n <= 9)?n:n%10 + S(n/10);
}
 
int main(){
    Nhap();
    cout << S(n);
}
---------------------------------
#include <iostream>
using namespace std;
int tong(int n){
    if(n==0)
        return 0;
    else 
        return n%10 + tong(n/10);
}
int main(){
    int n;
    cin>>n;
    cout<<tong(n);
}
////////////////////
// ĐỆ QUY QUAY LUI
//DEQUY_DAUMO
//dầu mỏ
/*
Giả sử có một thềm lục địa giàu dầu mỏ. Người ta chia thềm lục địa thành lưới ô vuông có M dòng và N cột (1 ≤ M ≤ 15, 1 ≤ N ≤ 15). Trên mỗi ô của lưới người ta ghi một số nguyên A (1 ≤ A ≤ 1000) được gọi là trữ lượng dầu của ô đó. Để khai thác, người ta dùng một giàn khoan di động. Do kinh phí có hạn nên giàn khoan không thể chạy hết vùng có dầu được. Vì vậy, người ta qui định, nếu giàn khoan đang ở ô có tọa độ [dòng ; cột] = [x ; y] thì chỉ được phép di chuyển đến ô có tọa độ [dòng ; cột] lần lượt là [x + 1 ; y] hoặc [x ; y + 1].
Yêu cầu: Viết chương trình sử dụng đệ quy quay lui để tìm đường đi (theo qui định trên) cho giàn khoan để đi từ vị trí [1 ; 1] đến vị trí [M ; N] và khai tác được lượng dầu nhiều nhất.
Dữ liệu vào: 
Dòng đầu tiên là hai giá trị M, N cách nhau một một khoảng cách. 
M dòng tiếp theo, mỗi dòng có N giá trị A được viết cách nhau một khoảng cách.
Dữ liệu ra:
Dòng đầu tiên là tổng số dầu thu được sau hành trình của giàn khoan. 
Các dòng tiếp theo, mỗi dòng là hai giá trị [dòng ; cột] viết cách nhau khoảng cách chỉ vị trí (theo thứ tự) trên lưới mà giàn khoan đã đi qua.
Dữ liệu input đảm bảo tồn tại duy nhất 1 đường đi.
Ví dụ:
 
Input
Output
4 5
1 5 1 3 4
6 7 9 1 5
1 1 8 4 5
1 3 4 3 3
43
1 1
2 1
2 2
2 3
3 3
3 4
3 5
4 5
 
*/
 
#include <iostream>
#include <vector>
#define MAX 50
 
using namespace std;
 
struct Diem{
    int x, y;
};
 
int dx[] = {1, 0};
int dy[] = {0, 1};
int a[MAX+1][MAX+1];
int M, N;
int sum, kq;
vector<Diem> duongdi, ddi_max;
Diem tmp;
 
void Try(int x, int y){
    if(x == M && y == N){
        if (kq <= sum) {
            kq = sum;
            ddi_max.clear();
            for(int i = 0; i < duongdi.size(); i++){
                tmp.x = duongdi[i].x;
                tmp.y = duongdi[i].y;
                ddi_max.push_back(tmp);
            }
        }
    }
    else{
        for (int k = 0; k < 2; k++){
            int xx = x + dx[k];
            int yy = y + dy[k];
            
            if(xx >= 1 && xx <= M && yy >= 1 && yy <= N){
                sum += a[xx][yy];
                tmp.x = xx;
                tmp.y = yy;
                duongdi.push_back(tmp);
                Try(xx,yy);
                duongdi.pop_back();
                sum -= a[xx][yy];
            }
        }
    }
}
 
int main(){
    cin >> M >> N;
    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            cin >> a[i][j];
        }
    }
    
    sum = a[1][1];
    tmp.x = 1;
    tmp.y = 1;
    duongdi.push_back(tmp);
    Try(1,1);
    
    cout << kq << endl;
    for (int i = 0; i < ddi_max.size(); i++){
        cout << ddi_max[i].x << " " << ddi_max[i].y << endl;
    }
    
    return 0;
}
 
 
 
////////////////////////////////////
//QUANTUONG
//quân tượng
/*
Xét bàn cờ vuông kích thước n×n. Các dòng được đánh số từ 1 đến n, từ dưới lên trên. Các cột được đánh số từ 1 đến n từ trái qua phải.
Ô nằm trên giao của dòng i và cột j được gọi là ô (i,j).
Trên bàn cờ có m (0 ≤ m ≤ n) quân cờ. Với m > 0, quân cờ thứ i ở ô (ri, ci), i = 1,2,..., m. Không có hai quân cờ nào ở trên cùng một ô. Trong số các ô còn lại của bàn cờ, tại ô (p, q) có một quân tượng. Mỗi một nước đi, từ vị trí đang đứng quân tượng chỉ có thể di chuyển đến được những ô trên cùng đường chéo với nó mà trên đường đi không phải qua các ô đã có quân.

Minh họa bàn cờ 8*8 và cách đi của quân tượng
 
Cần phải đưa quân tượng từ ô xuất phát (p, q) về ô đích (s,t). Giả thiết là ở ô đích không có quân cờ. Nếu ngoài quân tượng không có quân nào khác trên bàn cờ thì chỉ có 2 trường hợp: hoặc là không thể tới được ô đích, hoặc là tới được sau không quá 2 nước đi (hình trái). Khi trên bàn cờ còn có các quân cờ khác, vấn đề sẽ không còn đơn giản như vậy.
Yêu cầu: Cho kích thước bàn cờ n, số quân cờ hiện có trên bàn cờ m và vị trí của chúng, ô xuất phát và ô đích của quân tượng. Hãy xác định số nước đi ít nhất cần thực hiện để đưa quân tượng về ô đích hoặc đưa ra số -1 nếu điều này không thể thực hiện được.
Input
Dòng đầu tiên chứa 6 số nguyên n, m, p, q, s, t. (n <= 20)
Nếu m > 0 thì mỗi dòng thứ i trong m dòng tiếp theo chứa một cặp số nguyên r_i , c_i xác định vị trí quân thứ i.
Hai số liên tiếp trên cùng một dòng được ghi cách nhau ít nhất một dấu cách.
Output
Gồm 1 dòng duy nhất là số nước đi tìm được
Ví dụ:
Input:
8 4 5 4 8 7
7 2
2 1
3 6
7 6
 
Output:
3
 
*/
#include <iostream>
#include <queue>
#define MAX 100
 
using namespace std;
 
int n, m, p, q, s, t, r, c,
    dx[]={-1, -1, 1, 1},
    dy[]={-1, 1, -1, 1},
    a[MAX][MAX],
    visited[MAX][MAX];
 
int BFS(int x, int y){
    queue<pair<int,int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    int cnt = 0;
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        int x = tmp.first, y = tmp.second;
        q.pop();
        for(int i=0; i<4; ++i){
            int xx=x+dx[i], yy=y+dy[i];
            while(xx>=1 && xx<=n && yy>=1 && yy<=n && !visited[xx][yy]){
                a[xx][yy] = min(a[xx][yy], a[x][y]+1);
                if(xx == s && yy == t)
                    return a[s][t];
                q.push(make_pair(xx, yy));
                xx+=dx[i], yy+=dy[i];
            }
        }
        cnt++;
        if (cnt == 100000) return -1;
    }
    return -1;
}
int main(){
    cin >> n >> m >> p >> q >> s >> t;
    
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            a[i][j] = 2e9;
    
    a[p][q]=0;
    
    while(m--){
        cin >> r>> c;
        visited[r][c] = true;
    }
    
    cout << BFS(p,q);
    
    return 0;
}
///////////////////////////////////////////////////////////////
//TIMCHU
//tìm chữ
/*
Cho một ma trận mxn chứa các ký tự in hoa từ A->Z, ví dụ một ma trận 4x4 có các ký tự sau:
 
0
1
2
3
0
S
U
C
D
1
E
P
H
H
2
K
C
A
K
3
Z
Y
M
L
Từ ô xuất phát (x,y) bạn có thể di chuyển theo 4 hướng trên, dưới, trái, phải (mỗi lần chỉ được di chuyển 1 ô). Bằng cách di chuyển như vậy bạn sẽ ráp được một số chuỗi, yêu cầu xác định xem chuỗi Z có tồn tại hay không bằng cách di chuyển như vậy (với Z là chuỗi cần tìm)
Dữ liệu đầu vào:
- Dòng đầu chứa 4 số nguyên m,n,x,y (mỗi số cách nhau 1 khoảng trắng)
- Dòng thứ 2 chứa chuỗi Z cần tìm (Z không có chứa khoảng trắng, gồm các ký tự A->Z)
- m dòng tiếp theo, mỗi dòng chứa n ký tự in hoa (mỗi ký tự cách nhau 1 khoảng trắng).
Dữ liệu liệu đầu ra:
-  Dòng 1: Nếu tìm thấy chuỗi Z thì xuất ra chữ YES, ngược lại xuất ra chữ NO
-  Dòng 2: nếu dòng 1 là YES, thì dòng 2 xuất vị trí tìm thấy ký tự cuối cùng của Z.
Ví dụ1:
Input:
 
4
4
0
0
 
SUPHAM
 
S
U
C
D
 
E
P
H
H
 
K
C
A
K
 
Z
Y
M
L
Ouput:
YES
(3,2)
 
Ví dụ 2:
Input:
 
4
4
0
0
 
SANKHAU
 
S
U
C
D
 
E
P
H
H
 
K
C
A
K
 
Z
Y
M
L
Ouput:
NO
 
*/
#include <iostream>
#include <string>
 
#define MAX 100
 
using namespace std;
 
//cấu trúc
struct BANGCHU
{
    char kitu;
    bool danhdau;
};
 
//biến toàn cục
BANGCHU bangchu[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
bool possible = false;
int id = 0;
 
int m, n, x, y;
string chuoi;
 
//prototype
void xuatMaTran();
void timChu(int x, int y);
 
 
int main()
{
    cin >> m >> n >> x >> y;
    cin >> chuoi;
    
    //cout << chuoi.size()-1 << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> bangchu[i][j].kitu;
            bangchu[i][j].danhdau = 0;
        }
    }
    
    //xuatMaTran(m, n);
    timChu(x,y);
    
    if (!possible) cout << "NO";
    return 0;
    
    //xuatMaTran();
}
 
//define
void timChu(int x, int y)
{
    //cout << "#" << id << endl;
    if (id == chuoi.size()-1) // kiểm tra nếu đường đi có độ dài bằng chuỗi cần tìm
    {
        cout << "YES\n";
        cout << "(" << x << "," << y << ")";
        possible = true;
    }
    else
    {
        for (int cachdi = 0; cachdi < 4; cachdi++)
        {
            //di chuyển ô chọn theo 4 hướng
            int xx = x + dx[cachdi];
            int yy = y + dy[cachdi];
            //giới hạn bàn cờ (không thể bước ra ngoài bàn cờ)
            if (0 <= xx && xx < m && 0 <= yy && yy < n)
            {
                //so sánh kí tự trong bàn cờ với kí tự tương ứng của chuỗi
                //và kiểm tra đã đi qua vị trí đó hay chưa?
                if (bangchu[xx][yy].kitu == chuoi[id+1] &&
                    bangchu[xx][yy].danhdau == 0)
                {
                    ++id;
                    bangchu[xx][yy].danhdau = 1; //đánh dấu đi qua ô chọn và tìm chữ kế tiếp
                    
                    //xuatMaTran(); cout << endl;
                    timChu(xx,yy);
                    //nếu không có đường thì quay lui và tìm hướng khác
                    bangchu[xx][yy].danhdau = 0;
                    --id;
                }
            }
        }
    }
}
 
 
void xuatMaTran()
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << bangchu[i][j].kitu << " ";
        }cout << endl;
    }cout << "-----------" << endl;
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << bangchu[i][j].danhdau << " ";
        }cout << endl;
    }
}
/////////////////////////////////////////////////
//ROBOT2
//robot tìm đường
/*
Cho một bảng vuông (n x n) ô (2<=n<=100) các ô ghi các số là 0, 1 hoặc -1. Tìm  đường đi của Robot, từ góc trái  trên xuống góc phải dưới theo nguyên tắc chỉ được dịch chuyển sang phải và xuống dưới sao cho các số trên đường đi tạo thành một số nhị phân có giá trị NHỎ NHẤT (lưu ý không được đi qua ô có giá trị -1)
Dữ liệu input
-          Dòng đầu tiên ghi giá trị  n
-          n dòng tiếp theo, trên mỗi dòng ghi n số 0, 1  hoặc -1 các số này cách nhau ít nhất một khoảng trắng.
Dữ liệu output: gồm một số duy nhất là giá trị thập phân của số nhị phân được tạo thành ở trên.
Ví dụ:
 
Input
Output
5
1  0  1  1  0 
0  0  1  0  1
0  0  1  0  1
1  0  0  1  1
1  1  0  1  0
258
 
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 101
#define ll long long
#define oo (ll)1e9
 
using namespace std;
 
ifstream is("robot2.inp");
ofstream os("robot2.out");
 
int a[MAX][MAX];
ll f[MAX][MAX];
 
int main() {
	int n;
	is >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			is >> a[i][j];
			f[i][j] = oo;	// khởi tạo quãng đường tới ô (i,j) là vô cực. Vì cần tìm nhỏ nhất.
		}
	}
 
	f[1][1] = a[1][1];		// f[i][j] = giá trị đường đi lớn nhất tới ô (i,j)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			if (a[i][j] == -1) {	// không đi
				f[i][j] = oo;
			}
			else if (i == 1) {
				if (f[i][j - 1] == oo || a[i][j - 1] == -1)	// không đi
					f[i][j] = oo;
				else
					f[i][j] = f[i][j - 1] * 2 + a[i][j];
			}
			else if (j == 1) {
				if (f[i - 1][j] == oo || a[i - 1][j] == -1)	// không đi
					f[i][j] = oo;
				else 
					f[i][j] = f[i - 1][j] * 2 + a[i][j];
			}
			else {
				if (f[i][j - 1] == oo && f[i - 1][j] == oo)
					f[i][j] = oo;
				else
					f[i][j] = min(f[i][j - 1], f[i - 1][j]) * 2 + a[i][j];
			}
		}
	}
	os << f[n][n] << endl;
 
	return 0;
}
 
////////////////////////////////////////////////
//ROBOT
//robot tìm đường
/*
Cho một bảng vuông (n x n) ô (2<=n<=100) các ô ghi các số là 0 hoặc 1. Tìm  đường đi của Robot, từ góc trái  trên xuống góc phải dưới theo nguyên tắc chỉ được dịch chuyển sang phải và xuống dưới sao cho các số trên đường đi tạo thành một số nhị phân có giá trị lớn nhất.
Dữ liệu vào
-   Dòng đầu tiên ghi giá trị  n
-   n dòng tiếp theo, trên mỗi dòng ghi n số 0 hoặc 1 các số này cách nhau ít nhất một khoảng trắng.
Dữ liệu ra: gồm một số duy nhất là giá trị thập phân của số nhị phân được tạo thành ở trên.
ví dụ:
input
5
1 0 1 1 0
0 0 1 0 1
0 0 1 0 1
1 0 0 1 1
1 1 0 1 0
input:
374
 
*/
#include <iostream>
 
using namespace std;
int n, a[100][100],sum=0,max1=0;
int dx[2]={0,1}, dy[2]={1,0};
void creArr();
void backtrack(int x, int y);
int main()
{
    creArr();
    backtrack(0,0);
    cout<<max1;
    return 0;
}
void creArr(){
    cin >> n;
for(int i=0;i<n;++i)
for(int j=0;j<n;++j)
cin>>a[i][j];
}
void backtrack(int x, int y){
    if(x==n-1 and y==n-1){
        sum=sum*2+a[x][y];
        if(sum>max1) max1=sum;
        sum=(sum-a[x][y])/2;
    }
    else{
        for(int i=0;i<2;++i){
            if(x>n-1 or y>n-1 ) continue;
               sum=sum*2+a[x][y];
               backtrack(x+dx[i],y+dy[i]);
               sum=(sum-a[x][y])/2;
        }
    }
}
///////////////////////////////////////////
//RAYNAU
//xác định rầy nâu
/*
Bằng phương pháp chụp không ảnh xác định các vùng lúa đang bị rầy nâu phá hoại, trên ảnh chụp của vùng đất lớn hình chữ nhật, những vùng đất có màu xám là những vùng đất bị rầy nâu phá hoại, những vùng có màu xanh là những vùng đất còn tốt.
Để xác định vị trí của các vùng đất bị rầy nâu phá hoại hay không phá hoại, người ta chia hình chữ nhật trên thành các lưới ô vuông. Hãy lập trình xác định các vùng đất bị rầy nâu phá hoại, chỉ ra các vùng đất gồm các ô nào, tổng diện tích và diện tích các vùng này với mỗi ô là một đơn vị diện tích.
 
Yêu cầu:
 
Dữ liệu:
-         Dòng đầu là kích thước vùng đất cho bởi hai biến M, N với (1 <= M, N <= 250)
-         M dòng tiếp theo, mỗi dòng chứa N cột cho biết ô đất có  rầy hay không
(1 nếu có rầy, 0 nếu không có rầy)
 
Dữ liệu ra:
-         Dòng đầu ghi tổng diện tích vùng đất có rầy.
-         Các dòng tiếp theo: số đầu tiên là diện tích các ô chung cạnh có rầy, kế tiếp là vị trí các ô có rầy (thứ tự ô ghi theo từ trên xuống dưới, từ trái qua phải, ô đếm từ vị trí số 1)
 
ví  dụ:
INPUT
OUTPUT
4 4
1 1 0 0
0 1 0 0
0 0 0 1
0 0 0 0
4
3 [1,1], [1,2], [2,2]
1 [3,4]
 
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream is("RAY.INP");
ofstream os("RAY.OUT");
int n,m,a[100][100];
int luu1[100],luu2[100],dem,s=0;
void Try(int x,int y);
int main(){
    is>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            is>>a[i][j];
            if(a[i][j]==1) s++;
        }
    }
    os<<s<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==1){
                dem=0;
                Try(i,j);
                os<<dem<<" ";
                for(int k=1;k<=dem;k++){
                    os<<"["<<luu1[k]<<","<<luu2[k]<<"]"<<" ";
                    if(k!=dem) os<<", ";
                }
                os<<endl;
            }
        }
    }
    os.close();
    is.close();
}
void Try(int x,int y){
    if(a[x][y]==1){
        dem++;
        luu1[dem]=x;
        luu2[dem]=y;
        a[x][y]=0;
        if(x>1) Try(x-1,y);
        if(x<m) Try(x+1,y);
        if(y<n) Try(x,y+1);
        if(y>1) Try(x,y-1);
    }
}
/////////////////////////////////
//TAMGIACPASCAL
/*

 
Hình trên được gọi là tam giác Pascal.
 
Yêu cầu nhập vào số nguyên dương n. Hãy xuất ra dòng thứ n của tam giác Pascal.
 
Ví dụ:
 
Input:
3
Output:
1 2 1
 
Input:
4
Output:
1 3 3 1
 
Input:
7
Output:
1 6 15 20 15 6 1
 
*/
#include <iostream>
using namespace std;
 
int main()
{
    unsigned long long int m[1000][1000],n;
    cin>>n;
    for(int i=1;i<=n;i++)
        m[i][1]=1;
    for (int i=2;i<=n;i++)
        m[i][2]=i-1;
    
    for(int j=3;j<=n;j++)
        for(int i=j;i<=n;i++)
        {
            if (j==i) m[i][j]=1;
            else
            {
                m[i][j]=m[i-1][j]+m[i-1][j-1];
            }
        }
        
    for(int i=1;i<=n;i++)
        cout<<m[n][i]<<" ";
            
    return 0;
        
            
}
//////////////////////////////////
//Tamgiacso2
// tìm đường đi tam giác số 2
/*
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
 
Hình trên là một bảng tam giác các số nguyên không âm. Hãy viết chương trình để tính tổng lớn nhất các số trên đường đi từ đỉnh tam giác và kết thúc tại một điểm nào đó ở đáy tam giác.
 
Mỗi nước đi ta được quyền đi thẳng xuống số phía dưới hoặc số bên phải của số ngay dưới nó (mỗi lần chỉ đi đến một số).
 
Dữ liệu input
	+ Dòng 1: ghi số N là số lượng dòng của tam giác.
	+ Dòng thứ i+1 (1<= i <= N) ghi i số nguyên không âm.
 
Kết quả :
	+ Dòng 1: tổng lớn nhất đó.
        + Dòng 2: đường đi sao cho tổng tìm được là lớn nhất (gồm N số nguyên, mỗi số cách nhau một khoảng trắng).
 
Lưu ý: Nếu có nhiều đường đi, xuất ra tất cả các đường đi đó, mỗi đường đi trên một dòng.
 
Ví dụ:
 
Input
Output
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
5
7
3 8
8 0 3
3 7 4 5
9 5 1 6 7
30
7 3 8 7 5




 
30
7 3 8 3 9
7 3 8 7 5
7 8 3 5 7
 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int N;
int a[10001][10001]{};
int S[10001][10001]{};
bool kq[10001][10001]{};
int Vt[10001]{};
 
bool MySort(int x,int y)
{
    return (S[N][x] < S[N][y]) || (S[N][x] == S[N][y] && x < y); 
}
 
void Input()
{
    cin >> N;
    for(int i(1);i<=N;i++)
    {
        for(int j(1);j<=i;j++)
        {
            cin >> a[i][j];
        }
        Vt[i] = i;
    }
}
 
void TamGiacSo1()
{
    S[1][1] = a[1][1];
    for(int i(2);i<=N;i++)
    {
        S[i][1] = S[i-1][1] + a[i][1];
        S[i][i] = S[i-1][i-1] + a[i][i];
    }
    
    for(int i(2);i<=N;i++)
    {
        for(int j(1);j<=i;j++)
        {
            S[i][j] = max(S[i-1][j-1],S[i-1][j]) + a[i][j];
        }
    }
}
 
void Result()
{
    int Col[10001]{};
    int cnt{0};
    sort(Vt+1,Vt+N+1,MySort);
    
    for(int i(N);i>=1;i--)
    {
        if(S[N][Vt[N]] == S[N][Vt[i]])
        {
            cnt++;
            Col[cnt] = Vt[i];
        }
        else
        {
            break;
        }
    }
    cout << S[N][Vt[N]] << "\n";
       
    int i;
    int j;
    for(int k(cnt);k>=1;k--)
    {
        i = N;
        j = Col[k];
        memset(kq,false,sizeof(kq));
        kq[i][j] = true;
        kq[1][1] = true;
        while(i > 0 && j > 0)
        {
            if(S[i][j] == S[i-1][j] + a[i][j])
            {
                i--;
                kq[i][j] = true;
            }
            else
            {
                i--;
                j--;
                kq[i][j] = true;
            }
        }
        
        for(int i(1);i<=N;i++)
        {
            for(int j(1);j<=i;j++)
            {
                if(kq[i][j] == true)
                {
                    cout << a[i][j] << " "; 
                }
            }
        }
        cout << "\n";
    }
}
 
int main()
{
    Input();
    TamGiacSo1();
    Result();
    return 0;
}
/////////////////////////////////
//tamgiacso
//đường đi tam giác số
/*
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
 
Hình trên là một bảng tam giác các số nguyên không âm. Hãy viết chương trình để tính tổng lớn nhất các số trên đường đi từ đỉnh tam giác và kết thúc tại một điểm nào đó ở đáy tam giác.
 
Mỗi nước đi ta được quyền đi thẳng xuống số phía dưới hoặc số bên phải của số ngay dưới nó (mỗi lần chỉ đi đến một số).
 
Dữ liệu input
	+ Dòng 1: ghi số N là số lượng dòng của tam giác.
	+ Dòng thứ i+1 (1<= i <= N) ghi i số nguyên không âm.
 
Kết quả:
	+ Dòng 1: đường đi sao cho tổng tìm được là lớn nhất (gồm N số nguyên, mỗi số cách nhau một khoảng trắng) (dữ liệu đầu vào đảm bảo chỉ duy nhất 1 đường đi thỏa mãn)
	+ Dòng 2: tổng lớn nhất đó.
	
Ví dụ:
 
Input
Output
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
7 3 8 7 5
30
 
*/
#include<fstream>
using namespace std;
 
int vitri[100][100];
int luu[100];
int xuat[100];
int dem = 0;
int pt = 0;
int a;
int Max = 0;
void Tamgiac(int x,int y);
 
int main(){
	ifstream ip("TAMGIACSO.inp");
	ofstream op("TAMGIACSO.out");
	ip >> a;
	for (int i = 0; i < a; i++)
		for (int j = 0; j <= i; j++)
			ip >> vitri[i][j];
	Tamgiac(0, 0);
	for (int i = 0; i < pt; i++)
		op << xuat[i] << " ";
	op << endl << Max;
	ip.close();
	op.close();
}
 
 
int tong = 0;
void Tamgiac(int x,int y){
	if (x > a - 1 || y > a - 1)
		return;
	else{
		tong += vitri[x][y];
		luu[dem++] = vitri[x][y];
		if (x == a-1)
			if (Max < tong){
			    pt = dem;
				Max = tong;
				for (int i = 0; i < dem; i++)
					xuat[i] = luu[i];
			}
		Tamgiac(x + 1, y);
		Tamgiac(x + 1, y + 1);
		tong -= vitri[x][y];
		dem--;
	}
}
////////////////////////////////////////////////
//MADITUAN2
// mã đi tuần 2
/*
Trong luật cờ vua, mỗi nước đi của quân mã được quy định như sau: quân mã đang ở vị trí X như hình bên dưới có thể đi đến một trong các ô mà mũi tên chỉ đến (theo đường chéo của hình chữ nhật 2x3).

Yêu cầu: Cho trước bàn cờ kích thước n x m ô. Hãy đếm số nước đi ít nhất để quân mã di chuyển từ ô có tọa độ (x1, y1) đến ơ có tọa độ (x2, y2). Trong trường hợp không đến được thì xuất ra giá trị -1.
Dữ liệu input
Dòng 1 ghi 2 số nguyên dương n, m (2 <= n, m <= 1000).
Dòng 2 ghi 2 số nguyên x1, y1 (1 <= x1 <= n, 1 <= y1 <= m).
Dòng 3 ghi 2 số nguyên x2, y2 (1 <= x2 <= n, 1 <= y2 <= m).
      	Các số ghi trên cùng một dòng cách nhau ít nhất một kí tự trắng.
Kết quả: Ghi ra một số nguyên duy nhất cho biết số nước đi ít nhất để quân mã di chuyển từ ô (x1, y1) đến ô (x2, y2). Nếu không đến được thì ghi số -1.
Ví dụ:
 
Input
Output
4 6
1 1
2 4
2
 
*/
#include <iostream>
#include <string.h>
#include <queue>
 
using namespace std;
const long long int maxc = 1000000, maxcc = 1000;
struct toado{
    int x, y;
}s, f, k[9], X[maxc];
int n, m;
int a[maxcc][maxcc];
int countt;
queue <int> Qx, Qy;
 
void Nhap(){
    cin >> n >> m >> s.x >> s.y >> f.x >> f.y;
    X[0].x = s.x;
    X[0].y = s.y;
    k[1].x = 1;
    k[2].x = 2;
    k[3].x = 2;
    k[4].x = 1;
    k[5].x = -1;
    k[6].x = -2;
    k[7].x = -2;
    k[8].x = -1;
    k[1].y = 2;
    k[2].y = 1;
    k[3].y = -1;
    k[4].y = -2;
    k[5].y = -2;
    k[6].y = -1;
    k[7].y = 1;
    k[8].y = 2;
}
 
void BFS(){
    toado u;
    Qx.push(s.x);
    Qy.push(s.y);
    a[s.x][s.y] = false;
    int Count = 0;
    while (!Qx.empty()){
        u.x = Qx.front();
        u.y = Qy.front();
        Qx.pop();
        Qy.pop();
        Count++;
        for (int i=1; i<=8; i++){
            if (a[u.x + k[i].x][u.y + k[i].y] == 0 && u.x + k[i].x >= 1 && u.x + k[i].x <= n && u.y + k[i].y >= 1 && u.y + k[i].y <= m){
                a[u.x + k[i].x][u.y + k[i].y] = a[u.x][u.y] + 1;
                Qx.push(u.x + k[i].x);
                Qy.push(u.y + k[i].y);
                if (u.x + k[i].x == f.x && u.y + k[i].y == f.y){
                    cout << a[u.x + k[i].x][u.y + k[i].y];
                    break;
                }
            }
        }
    }
}
 
int main(){
    Nhap();
    BFS();
}
/////////////////////////////////
//madituan1
// mã đi tuần 1
/*
Mã đi tuần (hay hành trình của quân mã) là bài toán về việc di chuyển một quân mã trên bàn cờ vua (8 x 8). Quân mã được đặt ở một ô trên một bàn cờ trống nó phải di chuyển theo quy tắc của cờ vua để đi qua mỗi ô trên bàn cờ đúng một lần.
 

(nguồn: wikipedia )
 
Yêu cầu nhập vào 1 số nguyên n (bàn cờ n*n), xuất ra số cách di chuyển quân mã.
 
ví dụ
input:
5
 
output:
1728
*/
#include <iostream>
#include <fstream>
#define MAX 8
 
using namespace std;
 
int dong[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int cot[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
 
int n, stt, demKQ;
int BC[MAX][MAX];
 
void Try(int x, int y);
 
int main(){
	cin >> n;
	
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++){
			stt = 1;
			BC[x][y] = 1;
			
			Try(x, y);
 
			BC[x][y] = 0;
		}
 
	cout << demKQ << endl;
	
	return 0;
}
 
void Try(int x, int y){
	if (stt >= n*n)
		demKQ++;
	else{
		for (int i = 0; i < 8; ++i){
			int x2 = x + dong[i];
			int y2 = y + cot[i];
			if (0 <= x2 && x2 < n && 0 <= y2 && y2 < n && BC[x2][y2] == 0){
				stt++;
				BC[x2][y2] = stt;
 
				Try(x2, y2);
 
				BC[x2][y2] = 0;
				stt--;
			}
		}
	}
}
 
 
    
 
///////////////////////////////////////////
//H N
//hán nấm
/*
HÁI NẤM
 
Một cháu gái hàng ngày được mẹ giao nhiệm vụ đến thăm bà nội. Từ nhà mình đến nhà bà nội cô bé phải đi qua một khu rừng có rất nhiều loại nấm. Trong số các loại nấm, có ba loại có thể ăn được. Cô bé đánh số ba loại nấm ăn được lần lượt là 1, 2 và 3. Là một người cháu  hiếu thảo cho nên cô bé quyết định mỗi lần đến thăm bà, cô sẽ hái ít nhất hai loại nấm ăn được để nấu súp cho bà. Khu rừng mà cô bé đi qua được chia thành lưới ô vuông gồm n hàng và m cột. Các hàng của lưới được đánh số từ trên xuống dưới bắt đầu từ 1, còn các cột – đánh số từ trái sang phải, bắt đầu từ 1. Ô nằm giao của hàng i và cột j có tọa độ (i,  j). Trên mỗi ô vuông, trừ ô (1,1) và ô (n, m) các ô còn lại hoặc có nấm độc và  cô bé không dám  đi vào (đánh dấu là  -1), hoặc là có đúng một loại nấm có thể ăn được (đánh dấu bằng số hiệu của loại nấm đó). Khi cô bé đi vào một ô vuông có nấm ăn được thì cô bé sẽ hái loại nấm mọc trên ô đó. Xuất phát từ ô (1,1), để đến được nhà bà nội ở ô (n, m) một cách nhanh nhất cô bé luôn đi theo hướng sang phải hoặc xuống dưới.
 

 
       Bạn hãy giúp cô bé tìm ra một đường đi theo yêu cầu trên (không qua nấm độc và qua ít nhất 2 loại nấm ăn được). Chú ý là đường đi sẽ dài n + m - 1 ô, kể cả nhà cô bé ở đầu và nhà bà nội ở cuối.
 
Dữ liệu input
- Dòng thứ nhất là hai số nguyên n, m cách nhau một khoảng trắng ( 1 ≤ n,m ≤ 20)
- Trong n dòng tiếp theo, mỗi dòng là m số nguyên cách nhau một khoảng trắng. Các số nguyên biểu thị các loại nấm trong khu rừng (-1: nấm độc; 1, 2, 3: các nấm loại 1, 2, 3). Riêng 2 ô (1,1) và (n,m) có giá trị là 0 biểu thị nhà cô bé và nhà bà nội.
 
Dữ liệu output:
- Nếu không có đường đi, in ra -1.
- Nếu có đường đi, in ra số cách đi từ nhà cô bé đến nhà bà nội sao cho trên đường đi cô bé hái được ít nhất 2 loại nấm
 
Ví dụ
 
input (test 1)
3 4
0 3 -1 2
3 3 3 3
3 1 3 0
output
3
 
giải thích : test1 sẽ có 3 cách đi ứng với 3 mũi tên khác nhau như trên hình 
 
*/
#include <iostream>
#include <fstream>
using namespace std;
 
int a[20][20];
int f[20][20];
int n, m;
int k = 0;
 
bool check()
{
    int k = -1;
    for(int p=0 ;p<n ;++p)
    {
        for(int q=0 ;q<m ;++q)
        {
            if(f[p][q])
            {
                if(a[p][q] > 0)
                {
                    if(k == -1)
                        k = a[p][q];
                    else
                    {
                        if(k != a[p][q])
                            return true;
                    }
                }
            }
        }
    }
    return false;
}
 
void Try(int i, int j)
{
    for(int x = j; x<m; ++x)
    {
        if(a[i][x] == -1) break;
 
        if(i<n-1)
            for(int z=0; z<m; ++z)
                f[i + 1][z] = false;
 
        f[i][x] = true;
 
        if(i == n-1)
        {
            if(x == m-1)
            {
                if(check())
                    k++;
            }
        }
        else
            Try(i+1, x);
    }
}
 
int main()
{
    ifstream ifile("HANA.inp");
 
    ifile>>n>>m;
 
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            ifile>>a[i][j];
            f[i][j] = 0;
        }
    }
 
    Try(0, 0);
 
    ofstream ofile("HANA.out");
 
    ofile<<(k == 0 ? -1 : k);
 
    return 0;
}
 
 
--------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#define MAX 20
 
using namespace std;
struct ToaDo{
	int x, y;
};
 
void Try(int i, int j);
 
int dong[] = { 1, 0 };
int cot[] = { 0, 1 };
int n, m, a[MAX][MAX], sokq;
vector <ToaDo> ddi;
vector <int> da_hai(4, 0);
 
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
 
	ToaDo S;
	S.x = S.y = 1;
	ddi.push_back(S);
	
	Try(1, 1);
 
    if (sokq > 0)
		cout << sokq << endl;
	else
		cout << -1 << endl;
 
	return 0;
}
 
void Try(int i, int j){
	if (i == n && j == m){
		int sonam = 0;
		for (int k = 1; k <= 3; k++){
			if (da_hai[k] > 0){
				sonam++;
			}
		}
		if (sonam >= 2){
			sokq++;
		}
	}
	else{
		for (int k = 0; k <= 1; k++){
			ToaDo tmp;
			tmp.x = i + dong[k];
			tmp.y = j + cot[k];
			
			if (0 < tmp.x && tmp.x <= n && 0 < tmp.y && tmp.y <= m && a[tmp.x][tmp.y] != -1){
				ddi.push_back(tmp);
				int loainam = a[tmp.x][tmp.y];
				if (loainam != 0)
					da_hai[loainam]++;
 
				Try(tmp.x, tmp.y);
 
				da_hai[loainam]--;
				ddi.pop_back();
			}
		}
	}
}
 
///////////////////////////////////////////
//DUHA
// du hành
/*
DU HÀNH
 
Alpha Centauri-M (ACM) là một hành tinh với rất nhiều cảnh đẹp cho du khách từ Trái đất. Bản đồ của ACM được chia thành một lưới gồm M dòng, N cột. Các cột được đánh số từ 1 đến N theo chiều từ trái sang phải. Các dòng được đánh số từ 1 đến M theo chiều từ trên xuống dưới. Có một vài ô của lưới là núi lửa nên không thể viếng thăm được.  Các ô còn lại gọi là ô an toàn.
 
      Khi tiến đến ACM, phi thuyền sẽ hạ cánh tại một ô an toàn nào đó. Sau đó du khách sẽ viếng thăm hành tinh bằng xe tự hành. Bắt đầu từ ô hạ cánh (r0, c0), xe tự hành có thể đi đến bốn ô lân cận là (r0-1, c0), (r0+1, c0), (r0, c0-1), (r0, c0+1). Sau đó xe tự hành sẽ tiếp tục di chuyển theo quy tắc sau:
 
       1. Quẹo phải và tiến đến 1 ô.
       2. Quẹo trái và tiến đến 1 ô.
       3. Thực hiện lại bước 1.
 
      Xe tự hành chỉ có thể viếng thăm ô an toàn, vì vậy nó sẽ dừng lại nếu ô kế tiếp là không an toàn hoặc đi ra ngoài bản đồ. Hình bên dưới minh họa một bản đồ gồm M= 6 dòng và N= 7 cột. Từ ô hạ cánh là ô (4, 3), bạn có thể viếng thăm 16 ô, kể cả ô hạ cánh.
 

 
     Nhiệm vụ của bạn là tìm ô hạ cánh sao cho có thể viếng thăm nhiều ô nhất của Alpha Centauri-M
.
Dữ liệu nhập:
- Dòng đầu tiên là hai số nguyên M, N cách nhau một khoảng trắng (1 ≤ M, N ≤ 15).
- Trong M dòng tiếp theo, mỗi dòng chứa các số 0, 1 thể hiện tình trạng bản đồ (1 là ô an toàn, 0 là ô không an toàn), các số xếp sát nhau.
 
Dữ liệu xuất:
- Là số nguyên xác định số lượng ô có thể thăm nhiều nhất.
 
Ví dụ
input
3 3
011
111
111
output
8
 
input
6 7
1101011
0111111
1111101
1111111
1111110
0111111
output
20
 
*/
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 100
string s;
int dong, cot, G[MAX][MAX], a[MAX][MAX], res = 0, dem = 0;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
int upx[] = { 0, -1 }, upy[] = { 1, 0 };
int rightx[] = { 1, 0 }, righty[] = { 0, 1 };
int downx[] = { 0, 1 }, downy[] = { -1, 0 };
int leftx[] = { -1, 0 }, lefty[] = { 0, -1 };
void khoiTao();
void diemDung(int x, int y);
void duHanh(int n, int x, int y);
int main(){
	ifstream ifile("DUHA.inp");
	ifile >> dong >> cot;
	for (int i = 0; i < dong; ++i){
		ifile >> s;
		for (unsigned int j = 0; j < s.size(); ++j)
			G[i][j] = s[j] - 48;
	}
	ifile.close();
	ofstream ofile("DUHA.out");
	for (int i = 0; i < dong; ++i){
		for (int j = 0; j < cot; ++j){
			khoiTao();
			dem = 0;
			if (a[i][j] == 1){
				++dem;
				a[i][j] = 0;
				diemDung(i, j);
				res = max(res, dem);
			}
		}
	}
	ofile << res;
	ofile.close();
	return 0;
}
void khoiTao(){
	for (int i = 0; i < dong; ++i){
		for (int j = 0; j < cot; ++j)
			a[i][j] = G[i][j];
	}
}
void diemDung(int x, int y){
	for (int i = 0; i < 4; ++i){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx < dong && yy >= 0 && yy < cot && a[xx][yy] == 1){
			++dem;
			a[xx][yy] = 0;
			duHanh(i, xx, yy);
		}
	}
}
void duHanh(int n, int x, int y){
	bool tmp = true;
	if (n == 0){
		while (tmp){
			for (int i = 0; i < 2; ++i){
				x += upx[i];
				y += upy[i];
				if (x >= 0 && x < dong && y >= 0 && y < cot && a[x][y] == 1){
					++dem;
					a[x][y] = 0;
				}
				else{
					tmp = false;
					break;
				}
			}
		}
	}
	if (n == 1){
		while (tmp){
			for (int i = 0; i < 2; ++i){
				x += rightx[i];
				y += righty[i];
				if (x >= 0 && x < dong && y >= 0 && y < cot && a[x][y] == 1){
					++dem;
					a[x][y] = 0;
				}
				else{
					tmp = false;
					break;
				}
			}
		}
	}
	if (n == 2){
		while (tmp){
			for (int i = 0; i < 2; ++i){
				x += downx[i];
				y += downy[i];
				if (x >= 0 && x < dong && y >= 0 && y < cot && a[x][y] == 1){
					++dem;
					a[x][y] = 0;
				}
				else{
					tmp = false;
					break;
				}
			}
		}
	}
	if (n == 3){
		while (tmp){
			for (int i = 0; i < 2; ++i){
				x += leftx[i];
				y += lefty[i];
				if (x >= 0 && x < dong && y >= 0 && y < cot && a[x][y] == 1){
					++dem;
					a[x][y] = 0;
				}
				else{
					tmp = false;
					break;
				}
			}
		}
	}
}
//////////////////////////////////////////////////////////
//TT
//tiền tệ
/*
TIỀN TỆ
 
Một người mẹ muốn chia đều cho hai đứa con số tiền trong túi của mình. Khi rút tiền trong túi ra, bà thấy có n đồng tiền (n ≤ 20) với các loại mệnh giá khác nhau. Bà cảm thấy lo lắng chia cho hai người con có được không.
 
Yêu cầu: Bạn hãy giúp bà ấy chia tiền cho hai người con. Nếu chia được thì nêu rõ số cách chia.
 
Dữ liệu vào: Gồm 02 dòng:
+Dòng đầu ghi số n là số đồng tiền (1≤  n ≤ 20)
+Dòng sau ghi mệnh giá các đồng tiền là các số nguyên dương có cùng đơn vị tính (0≤t[i]≤500).
 
Dữ liệu ra: Dòng thứ nhất ghi số cách chia, nếu không thể chia được thì ghi “ khong chia duoc”. Các dòng sau trong trường hợp chia được, mỗi dòng là 01 cách chia với quy ước người thứ nhất có tên là “A”, người thứ hai có tên là “B” và phải tương ứng với thứ tự của các đồng tiền mà bà đưa ra. 
 
Ví dụ
input
6
1 2 2 5 10 10
output
4
A A A B A B
A A A B B A
B B B A A B
B B B A B A
 
input
6
1 2 2 5 10 1
output
khong chia duoc
 
*/
#include <iostream>
using namespace std;
 
const int Max = 1000;
int n;
int money[Max];
char a[Max];
char result[Max];
int Count = 0;
bool checkAble;
 
void Try(int i);
void arrayOut(char a[], int count);
void countRes(int i);
 
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> money[i];
	countRes(0);
	if(checkAble)
		cout << Count << endl;
	Try(0);
	if (!checkAble)
		cout << "khong chia duoc" << endl;
	//system("pause");
	return 0;
}
void countRes(int i)
{
	if (i == n)
	{
		int tongA = 0, tongB = 0;
		for (int k = 0; k < n; k++)
		{
			if (a[k] == 'A')
				tongA += money[k];
			else
				tongB += money[k];
		}
		if (tongA == tongB)
		{
			checkAble = true;
			Count++;
		}
	}
	else
	{
		for (char j = 'A'; j <= 'B'; j++)
		{
			a[i] = j;
			countRes(i + 1);
		}
	}
}
 
 
void Try(int i)
{
	if (i == n)
	{
		int tongA = 0, tongB = 0;
		for (int k = 0; k < n; k++)
		{
			if (a[k] == 'A')
				tongA += money[k];
			else
				tongB += money[k];
		}
		if (tongA == tongB)
		{
			arrayOut(a, n);
			cout << endl;
		}		
	}
	else
	{
		for (char j = 'A'; j <= 'B'; j++)
		{
			a[i] = j;
			Try(i + 1);
		}
	}
}
 
void arrayOut(char a[], int count)
{
	for (int i = 0; i < count; i++)
		cout << a[i] << " ";
}
////////////////////////////////////////////////////////////////
//LINE
//trò chơi line
/*
Trò chơi Line
Trò chơi Line là trò chơi di chuyển các viên bi trong một hình vuông 9 x 9 ô. Bi được ăn khi tạo thành các hàng, cột, đường chéo gồm 5 viên bi liên tiếp cùng màu.
 
   
 
        Một thuật toán được sử dụng trong trò chơi là tìm đường đi để di chuyển một viên bi. Giả sử trò chơi Line tổng quát có n dòng, n cột. Đánh số các dòng từ 1 đến n theo thứ tự từ trên xuống dưới, đánh số các cột từ 1 đến n theo thứ tự từ trái sang phải. Giả sử có một viên bi tại ô (y, x) - dòng y cột x, bi có thể di chuyển đến 1 trong 4 ô (y+1, x), (y-1, x), (y, x+1), (y, x-1), nếu ô đó đang trống. Cho vị trí bắt đầu và vị trí kết thúc của viên bi, hãy viết chương trình xác định xem có tồn tại đường đi để di chuyển viên bi hay không.
 
Dữ liệu nhập: gồm các dòng sau
    - Dòng thứ nhất gồm năm số n, sy, sx, dy, dx, mỗi số cách nhau một khoảng trắng (2 ≤ n ≤ 9; 1 ≤ sy,       sx, dy, dx ≤ n). sy là chỉ số dòng, sx là chỉ số cột của viên bi cần di chuyển. dy là chỉ số dòng, dx là         chỉ số cột của vị trí cần di chuyển viên bi đến.
    - Trong n dòng tiếp theo, mỗi dòng gồm n số nguyên 0 hoặc 1, mỗi số cách nhau một khoảng trắng,         biểu thị tình trạng của trò chơi. Số 1 nghĩa là vị trí ô đó có bi, số 0 nghĩa là vị trí ô đó đang trống.
      (Dữ liệu cho bảo đảm tại ô (sy, sx) có giá trị là 1, tại ô (dy, dx) có giá trị là 0)
 
Dữ liệu xuất:
  - Nếu tìm được đường đi, in ra YES.
  - Nếu không tìm được đường đi, in ra NO.
 
lưu ý: nhập xuất file với file input là "LINE.inp" và file output là "LINE.out"
 
Ví dụ:
 
input
3 1 1 3 3
1 0 1
1 0 1
1 1 0
output
NO
 
input
3 1 1 3 3
1 0 1
1 0 0
1 1 0
output
YES
 
*/
#include <iostream>
#include <cstring>
#include <fstream>
 
using namespace std;
const int maxc = 1e7, maxcc = 1e3;
ifstream fi("LINE.inp");
ofstream fo("LINE.out");
struct ToaDo{
    int x, y;
}k[5], X[maxc], s, f;
int n;
bool a[maxcc][maxcc];
 
void Nhap(){
    fi >> n >> s.y >> s.x >> f.y >> f.x;
    int t;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            fi >> t;
            if (t == 1){
                a[j][i] = true;
            }
            else{
                a[j][i] = false;
            }
        }
    }
    k[1].x = 0;
    k[2].x = 1;
    k[3].x = 0;
    k[4].x = -1;
    k[1].y = 1;
    k[2].y = 0;
    k[3].y = -1;
    k[4].y = 0;
}
 
void DFS(ToaDo u){
    for (int j=1; j<=4; j++){
        if (a[u.x + k[j].x][u.y + k[j].y] != true && u.x + k[j].x >=1 && u.x + k[j].x <= n && u.y + k[j].y >=1 && u.y + k[j].y <= n){
            if (u.x + k[j].x == f.x && u.y + k[j].y == f.y){
                fo << "YES";
                a[u.x + k[j].x][u.y + k[j].y] = true;
                return;
            }
            a[u.x + k[j].x][u.y + k[j].y] = true;
            ToaDo p;
            p.x = u.x + k[j].x;
            p.y = u.y + k[j].y;
            DFS(p);
        }
    }
}
 
int main(){
    Nhap();
    DFS(s);
    if (!a[f.x][f.y]){
        fo << "NO";
    }
    fi.close();
    fo.close();
}
//////////////////////////////////////////
//OCSE
//ốc sên ăn rau
/*
 Ốc sên ăn rau
       Có một khu vườn hình chữ nhật kích thước n x m ô vuông (n dòng, m cột). Ta đánh số các dòng từ 1 đến n theo chiều từ trên xuống dưới, các cột từ 1 đến m theo chiều từ trái qua phải. Tại những ô vuông là đất bình thường người ta trồng rau. Tuy nhiên có một số ô là đá nên không trồng rau được. Có một chú ốc sên tại ô (y, x), y là vị trí dòng, x là vị trí cột. Từ một ô, chú ốc sên chỉ có thể di chuyển sang 4 ô liền kề (y-1, x), (y+1, x), (y, x-1), (y, x+1). Nếu gặp ô đá thì ốc sên không đi vào được
.
 
 Ốc sên đang rất đói. Bạn hãy xác định xem chú có thể ăn được số lượng rau nhiều nhất là bao nhiêu.
 
Dữ liệu vào: gồm các dòng sau:
- Dòng thứ nhất gồm bốn số nguyên n, m, y, x, mỗi số các nhau một khoảng trắng (1 ≤ y ≤ n ≤ 100,1 ≤ x ≤ m ≤ 100).
- Trong n dòng tiếp theo, mỗi dòng gồm m số nguyên 0 hoặc 1 biểu thị vườn rau, mỗi số cách nhau một khoảng trắng. Số 0 nghĩa là ô rau, còn số 1 nghĩa là ô đá.(Dữ liệu cho đảm bảo ô (y, x) là ô rau)
 
Dữ liệu xuất:
- Là một số nguyên xác định số lượng ô lớn nhất mà ốc sên có thể di chuyển đến.
 
Ví dụ
input
4 5 2 4
0 0 1 0 0
0 1 0 0 1
1 0 0 0 0
0 1 0 0 1
output: 
10
 
*/
#include <iostream>
using namespace std;
 
int n,m,a[101][101],dem=0;
 
void Try(int y, int x) {
    if (a[y][x] == 1) return;
    else {
        a[y][x] = 1;
        dem++;
 
        Try(y-1,x);
        Try(y+1,x);
        Try(y,x-1);
        Try(y,x+1);
    }
}
 
int main() {
    int y,x;
    cin >> n >> m >> y >> x;
 
    for (int i=0; i<=n+1; i++) {
        a[i][0] = 1;
        a[i][m+1] = 1;
    }
    for (int i=0; i<=m+1; i++) {
        a[0][i] = 1;
        a[n+1][i] = 1;
    }
    
 
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
 
    Try(y,x);
 
    cout << dem;
 
    return 0;
}
////////////////////////////////////////////
//balo2
/*
Cho cái túi chứa được trọng lượng tối đa là w. Có n đồ vật, đồ vật thứ i có khối lượng a[i] và giá trị c[i], 1<= i <=n. Tìm cách xếp đồ vật vào túi sao cho đạt giá trị lớn nhất. (số lượng 1 vật có thể chọn 1 hoặc không chọn)
 
Input:
n w
a[1] c[1]
a[2] c[2]
...
a[n] c[n]
 
Output:
S: Giá trị lớn nhất của các vật đã chọn
num[1] num[2] ... num[n] : số lượng các vật được chọn
Ví dụ:
 
Input
Output
4 11
3 4
5 6
6 5
1 3
13
1 1 0 1
 
*/
#include <iostream>
using namespace std;
int w,maxC,n;
int tongW=0;
int a[100],choose[100],_choose[100],c[100];
int caculateW()
{
	int s=0;
	for (int i=0;i<n;i++)
		if (choose[i]==1)
			s+=a[i];
	return s;
}
int caculateC()
{
	int s=0;
	for (int i=0;i<n;i++)
		if (choose[i]==1)
			s+=c[i];
	return s;
}
void _Try(int i)
{
	if (i==n)
	{
		if (caculateC()>maxC && caculateW()<=w)
		{
			maxC=caculateC();
			for (int j=0;j<n;j++)
				_choose[j]=choose[j];
		}
	}
	else
	{
		for (int j=0;j<=1;j++)
		{
			choose[i]=j;
			_Try(i+1);
		}
	}
}
int main()
{	
	cin >> n >>w;
	for (int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	maxC=0;
	_Try(0);
	cout<<maxC<<endl;
	for (int i=0;i<n;i++)
			cout<<_choose[i]<<" ";
	return 0;
}
/////////////////////////////////////////////////
//balo1
/*
Cho n món hàng có khối lượng lần lượt là a[0], a[1], ... ,a[n-1] (đơn vị là kg) và 1 balô có khả năng chứa là w (kg).
 
yêu cầu chọn những món hàng nào bỏ vào balô sao cho tổng khối lượng là lớn nhất và không vượt quá w
 
dữ liệu vào: gồm 2 dòng
- dòng 1: chứa 2 số n và w
- dòng 2: chứa n số nguyên a[0], a[1], ... ,a[n-1]
 
dữ liêu ra : gồm 2 dòng
- dòng 1: khối lượng tối ưu của balo sau khi chọn các món hàng
- dòng 2: thứ tự các món hàng được chọn (số nhỏ ghi trước số lớn ghi sau)
 
ví dụ
input:
3 10
3 5 7
 
output:
10
0 2
*/
#include <iostream>
 
using namespace std;
void creArr(int n, int *a);
void findMax(int n, int *a, int w);
int main()
{
int n, w;
cin >>n>> w;
int *a=new int[n];
creArr(n,a);
findMax(n,a,w);
delete[] a;
return 0;
}
void creArr(int n, int *a){
    for(int i=0;i<n;++i)
    cin>>*(a+i);
}
void findMax(int n, int *a, int w){
int max1=0, sum, x, y;
for(int i=0;i<n-1;++i)
for(int j=i+1;j<n;++j){
    sum=*(a+i) + *(a+j);
    if(sum>w) continue;
    if(sum<max1) continue;
    max1=sum;
    x=i;
    y=j;
}
cout<<max1<<endl<<x<<" "<<y;
}
//////////////////////////////////////////////////////////////////////////////////////
//timduong
//tìm đường trong đồ thị
/*
Cho đồ thị đơn vô hướng G=(V,U) (không có trọng số), tìm độ dài đường đi ngắn nhất từ đỉnh S đến đỉnh T.
input
- số đỉnh (nV), số cạnh (nE), đỉnh xuất phát (S), đỉnh kết thúc (T).
- nE dòng tiếp theo mỗi dòng gồm 2 số a, b biểu diễn cạnh ab
ouput
- một số nguyên duy nhất là đường đi ngắn nhất từ S đến T.
 
ví dụ:

input:
6 6 1 6
1 2
1 3
1 5
2 4
3 5
5 6
 
ouput:
2
*/
 
 
#include <bits/stdc++.h>
using namespace std;
#define fto(i,x,y) for(int i=(x);i<(y);i++)
int a[100][100],check[100];
int n,m,s,t,x,y,cnt=00;
void Try(int i){
    if(i==t){
        cnt++;
    }
    else{
        for(int j=0;j<n;j++){
            if(a[i][j]==1 and check[j]==1){
                check[j]=0;
                //kq[i]=j;
                Try(i+1);
                //kq[i]-=j;
                check[j]=1;
            }
        }
    }
}
int main(){
    cin>>n>>m>>s>>t;
    fto(i,0,n)
        fto(j,0,m)
            a[i][j]=0;
    fto(i,0,n){
        fto(j,0,m){
            cin>>x>>y;
            a[x][y]=a[y][x]=1;
        }
    }
    fto(i,0,n)
        check[i]=1;
    Try(s);   
    cout<<cnt;
    return 0;
}
 
///////////////////////////////////
//hexa
//chuyển từ thập phân sang hexa
/*
Viết chương trình chuyển đổi một số từ hệ thập phân sang hệ thập lục phân (hexa)
 
Dữ liệu vào: số nguyên dương n<=10^9 (ở hệ thập phân)
Dữ liệu ra: giá trị của n trong hệ hexa
 
Ví dụ:
Input: 816
Output: 330
*/
#include <iostream>
#include <vector>
using namespace std;
vector<char> arr;
int n;
 
void xuatKQ();
void addString(int k);
void conventHEX(int n);
 
int main() {
	cin >> n;
	conventHEX(n);
//	system("pause");
	return 0;
}
 
void xuatKQ() {
	for (vector<char>::reverse_iterator rit = arr.rbegin(); rit < arr.rend(); rit++) {
		cout << *rit;
	}
}
 
void addString(int k) {
	char x;
	if (k <= 9) {
		x = (char)((int)k + 48);
		arr.push_back(x);
	}
	else {
		x = (char)((int)k + 55);
		arr.push_back(x);
	}
}
 
void conventHEX(int n) {
	if (n < 16) {
		addString(n % 16);
		xuatKQ();
	}
	else {
		addString(n % 16);
		conventHEX(n / 16);
	}
}
-------------------------------
#include <iostream>
using namespace std;
 
char a[16] = {[0] = '0', [1] = '1', [2] = '2', [3] = '3', [4] = '4', [5] = '5', [6] = '6', [7] = '7', [8] = '8', [9] = '9', [10] = 'A', [11] = 'B', [12] = 'C', [13] = 'D', [14] = 'E', [15] = 'F'};
 
int main() {
    string str="";
    int so;
 
    cin >> so;
 
    while (so != 0) {
        str = a[so%16] + str;
        so /= 16;
    }
 
    cout << str;
 
    return 0;
}

//////////////////////
//CON TRỎ
//Josephus
/*
Bài toán Josephus là một trong những bài toán rất nổi tiếng, ra đời từ rất sớm, khoảng năm 370 sau công nguyên bởi Aurelius Ambrosius, là một Tiến sĩ Hội thánh sống vào khoảng năm 340 đến 397 sau công nguyên. Ông cũng được xem là vị thánh bảo trợ của thành phố Milan, nước Ý.
 
Bài toán đưa ra bởiAmbrôsiô như sau: Titus Flavius Vespasianus là một vị tướng lãnh đạo quân đội tài năng, người về sau đã trở thành hoàng đế La Mã (từ năm 69 đến năm 79), đã cùng với quân đội dưới sự chỉ huy của ông ta dập tắt cuộc nổi loạn của người Do Thái chống lại đế quốc La Mã. Trong cuộc vây hãm Yodfat, Vespasian đã bắt được Flavius Josephus, một nhà lãnh đạo kháng chiến của người Do Thái. Sau khi bắt được các tù nhân Do Thái, người La Mã quyết định xử tử tù nhân bằng cách cho toàn bộ xếp thành vòng tròn và bắt đầu đếm từ một, cứ người nào đến 3 là bị giết cho đến khi chỉ còn lại 1 người. Trước yêu cầu khắc nghiệt như trên, Josephus đã nhanh chóng tìm ra vị trí để mình và người bạn thân không bị giết. Hỏi rằng ông đã chọn vị trí nào cho ông?
 
Bài toán cần giải:
Cho N người đứng thành vòng tròn và số M (ở đây cho dễ ta sẽ giả sử M < N). Bắt đầu từ người số 1, anh ta sẽ đếm 1, người bên trái anh ta đếm 2, ... cho tới người đếm M sẽ tự động bước ra khỏi vòng tròn đó và người bên trái anh ta tiếp tục đếm lại 1 ... Cứ thế cho tới khi vòng không còn người nào. Xuất thứ tự người ra khỏi vòng tròn.
Ví dụ: với N = 9, M=7 thì thứ tự sẽ là: 7  5  4  6  9  3  8  1 2
*/
#include <iostream>
 
using namespace std;
int m,n,i,j,a[10000],k[10000],d,h,b,v;
int main()
{
    cin >>n >>m;
    for (i=1;i<=n;i++) a[i]=i; d=0; h=0; b=0; v=n;
    while (d!=v)
    {
       h++; b++;
       if (b==m)
       {
           cout <<a[h] <<" ";
           for (j=h;j<=n;j++) a[j]=a[j+1]; n--; b=0; d++; h--;
       }
       if (h==n) h=0;
    }
    return 0;
}
 
//////////////////////////////
//CONTRO1
// tim min max
/*
Tìm Min-Max  
 
cho danh sách liên kết đơn n phần tử (số nguyên) tìm giá trị lớn nhất và nhỏ nhất trong danh sách và in ra vị trí của các giá trị lớn nhất, giá trị nhỏ nhất trong danh sách đó 
dư liệu được cho như sau:
dòng đầu tiên là n (số phần tử của danh sách)
n dòng tiếp theo là giá trị của phần tử thứ i trong danh sách 
dữ liệu ra xuất ra:
dòng đầu tiên xuất ra giá trị lớn nhất 
dòng tiếp theo xuất ra vị trí của các phần tử lớn nhất trong danh sách mỗi phần tử cách nhau 1 khoảng trắng
dòng tiếp theo xuất ra giá trị nhỏ nhất 
dòng tiếp theo xuất ra vị trí của các phần tử nhỏ nhất trong danh sách, mỗi phần tử cách nhau 1 khoảng trắng
lưu ý: dùng con trỏ để làm bài  
 
ví dụ:
input :
7
-1 2 6 3 6 -1 2
output :
6
3 5
-1
1 6
 
Lưu ý danh sách được đánh số từ 1
 
*/
// CONTRO1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
 
#include <iostream>
using namespace std;
 
int main()
{
	int n, max=0, min=1000, demmax = 0, demmin = 0;
	cin >> n;
	int *a = new int[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	cout << max << endl;
	for (int i = 1; i <= n; i++) {
		if (a[i] == max)
			cout << i << " ";
	}
	cout << endl;
	cout << min << endl;
	for (int i = 1; i <= n; i++) {
		if (a[i] == min)
			cout << i << " ";
	}
	
	return 0;
}
 
///////////////////////////////////////
//CONTRO2
//Xoá phần tử k 
/*
Xoá phần tử k 
 
Xoá tất cả phần tử có giá trị K trong danh sách liên kết đơn có n phần tử 
 
Input:
dòng 1: chứa số nguyên n (100>=n >= 1) và số nguyên K ( -1000<=k<=1000)
dòng 2: chứa n phần tử mỗi phần tử cách nhau 1 khoảng trắng (mỗi phần tử là số nguyên có giá trị tuyệt đối <= 1000)
 
Output:
dòng 1 : số phần tử của danh sách sau khi xoá
dòng 2: chứa n phần tử của danh sách sau khi xoá , mỗi phần tử cách nhau 1 khoảng trắng
 
lưu ý : PHẢI dùng danh sách liên kết để làm bài 
 
input:
6 2
1 2 3 6 2 8
output:
4
1 3 6 8
 
*/
#include <iostream>
#include <fstream>
using namespace std;
 
struct Node
{
	int data;
	Node * link;
};
 
struct List
{
	Node* first;
	Node* last;
};
 
void init(List& l);
Node* getNode(int x);
void insertFirst(List& l, int x);
void insertLast(List& l, int x);
void xoaDau(List&l);
void xoaSau(List&l, Node*q);
void xoasoK(List& l, int k);
 
int dem(List& l);
 
int main()
{
	List l;
	init(l);
	
	int n, k, x;
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		insertLast(l, x);
	}
	
	for (int i = 1; i <= n; i++)
	{
		xoasoK(l, k);
	}
 
	cout << dem(l) << endl;
	
	Node* p = l.first;
	
	while (p != NULL)
	{
		cout << p->data;
		p = p->link;
	}
	
	return 0;
}
 
void init(List& l)
{
	l.first = l.last = NULL;
}
 
Node* getNode(int x)
{
	Node*p;
	p = new Node;
	p->data = x;
	p->link = NULL;
	return p;
}
 
void insertFirst(List&l, int x)
{
	Node* new_ele = getNode(x);
	if (l.first == NULL)
	{
		l.first = l.last = new_ele;
	}
	else
	{
		new_ele->link = l.first;
		l.first = new_ele;
	}
}
 
void insertLast(List& l, int x)
{
	Node *new_ele = getNode(x);
	if (l.first == NULL)
	{
		l.first = l.last = new_ele;
	}
	else
	{
		l.last->link = new_ele;
		l.last = new_ele;
	}
}
 
void xoaDau(List&l)
{
	if (l.first != NULL)
	{
        Node*p = l.first;
		l.first = p->link;
		if (l.first == NULL)
		{
			l.last = NULL;
		}//neu danh sach chi co 1 node
		delete p;
    }
}
 
void xoaSau(List&l, Node*q)
{
	if (q != NULL && q->link != NULL)
	{
		Node*p = q->link;
		q->link = p->link;
		if (p == l.last)
		{
			l.last = q;
		}
		delete p;
	}
}
 
void xoasoK(List& l, int k)
{
	if (l.first != NULL)
	{
		Node *p = l.first;
		if (p->data == k) xoaDau(l);
		else
		{
			for (Node*p = l.first; p->link != NULL; p = p->link)
			{
				if (p->link->data == k)
				{
					xoaSau(l, p);
					break;
				}
			}
		}
	}
	else return;
}
 
int dem(List &l)
{
	Node*p = l.first;
	int dem = 0;
	while (p != NULL)
	{
		dem++;
		p = p->link;
	}
	return dem;
}
////////////////////////////////////////////////////
//CONTRO3
//Thêm phần tử vào vị trí K
/*
Thêm phần tử vào vị trí K
 
cho danh sách liên kết đơn gồm n phần tử ,hãy thêm phần tử a vào vị trí k trong danh sách 
 
Input:
dòng 1: chứa 3 số nguyên n , a và k (100> n, k >=1, -1000 <= a <= 1000)
dòng 2: chứa n phần tử của danh sách ,mỗi phần tử cách nhau 1 khoảng trắng (mỗi phần tử là số nguyên có giá trị tuyệt đối <= 1000)
 
Output:
dòng 1: chứa số phần tử của danh sách sau khi thêm 
dòng 2: chứa các phần tử của danh sách sau khi thêm ,mỗi phần tử cách nhau 1 khoảng trắng 
 
lưu ý: 
1 . Phải dùng danh sách liên kết để làm bài
2. Chỉ số được đánh từ 1
 
Ví dụ:
input:
5 8 3
1 2 3 4 5
 
output:
6
1 2 8 3 4 5
 
*/
#include <iostream>
using namespace std;
struct Node{
    int value;
    Node *next;
};
struct List{
    Node *first;
    Node *last;
};
void initList(List &l){
    l.first=l.last=NULL;
}
Node *getNode(int a){
    Node *p = new Node;
    p->value = a;
    p->next = NULL;
    return p;
}
void addNode(List& l,Node *p){
    if(l.first==NULL)
        l.first=l.last=p;
    else
        l.last->next=p;
        l.last=p;
}
void addHead(List& l,Node *p){
    p->next=l.first;
    l.first=p;
}
void printList(List l){
    Node *p = l.first;
    while(p!=NULL){
        cout<<p->value<<" ";
        p=p->next;
    }
}
int main(){
    int n,x,k,a;
    List l;
    initList(l);
    cin>>n>>x>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        addNode(l,getNode(a));
    }
    if(k==1){
        addHead(l,getNode(x));
        n++;
    }
    else if(k==n+1){
        addNode(l,getNode(x));
        n++;
    }
    else if(k>1&&k<=n){
        Node *p = l.first;
        Node *pt = getNode(x);
        int dem=1;
        while(dem!=k-1){
            p=p->next;
            dem++;
        }
        pt->next=p->next;
        p->next = pt;
        n++;
    }
    cout<<n<<endl;
    printList(l);
}
////////////////////////////////////////
//CONTRO5
//A=B+C
/*
cho danh sách liên kết đơn các số nguyên có nhiều hơn 3 giá trị và các giá trị trong danh sách khác nhau từng đôi một .Hãy xác định xem trong danh sách có bộ 3 giá trị ( a, b, c ) nào thoả điều kiện a = b + c (với a, b, c là 3 giá trị khác nhau trong danh sách ) hay không , nếu có xuất ra "YES" ngược lại xuất ra "NO"
 
dữ liệu input: 
·         dòng 1 : số phần tử của danh sách sách liên kết đơn 
·         dòng 2 : các phần tử của danh sách , mỗi phần tử cách nhau 1 khoảng trắng 
 
dữ liệu output:
·         dòng 1 : xuất ra "YES" hoặc "NO"
Ví dụ:
 
Input
Output
6
1 2 3 4 5 6
YES
 
 
 
lưu ý: dùng danh sách liên kết để làm bài
 
*/
 
/**
 *  Author: lethuc_upcoder.hcmue.edu.vn
 *  Uong cafe xong !! :v
**/
 
#include <iostream>
using namespace std;
 
struct Node{
    int data;
    Node* pNext;
};
 
void init(Node* &p){
    p = NULL;
}
 
Node* creNode(int x){
    Node* res = new Node;
    res->data = x;
    res->pNext = NULL;
    return res;
}
 
void showList(Node* list){
    Node* tmp = list;
    while (tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->pNext;
    }
}
 
void pushF(Node* &list,int x){
    Node* New = creNode(x);
    if (list == NULL){
        list = New;
    } else {
        New->pNext = list;
        list = New;
    }
}
 
void pushM(Node* &list,int x){
    Node* New = creNode(x);
    Node* tmp = list->pNext;
    list->pNext = New;
    New->pNext = tmp;
}
 
void pushB(Node* &list,int x){
    Node* New = creNode(x);
    if (list == NULL){
        list = New;
    } else{
        Node* tmp = list;
        while (tmp->pNext != NULL){
            tmp = tmp->pNext;
        }    
        tmp->pNext = New;
    }
}
 
void delAllVal(Node* &list,int x){
    
    Node* tmp = list;
    Node* prev;
    
    while (tmp != NULL && tmp->data == x){
        list = tmp->pNext;
        delete(tmp);
        tmp = list;
    }
    
    while (tmp != NULL){
        while (tmp != NULL && tmp->data != x){
            prev = tmp;
            tmp = tmp->pNext;
        }
        if (tmp == NULL) break;
        
        
        prev->pNext = tmp->pNext;
        delete(tmp);
        tmp = prev->pNext;
        
    }
    
}
 
void solve(Node* list){
    bool ok = false;
    Node* iter1=list;
    Node* iter2;
    Node* iter3;
    while(iter1 != NULL){
        iter2=iter1->pNext;
        
        while(iter2!=NULL){
            iter3=iter2->pNext;
            
            while(iter3!=NULL){
                if (   iter1->data + iter2->data == iter3->data
                    || iter1->data + iter3->data == iter2->data
                    || iter2->data + iter3->data == iter1->data
                ){
                    ok = true;
                    break;
                }
                
                iter3 = iter3->pNext;
            }
            if (ok) break;
            
            iter2 = iter2->pNext;
        }
        if (ok) break;
        
        iter1 = iter1->pNext;
    }
    cout << (ok ? "YES" : "NO");
}
 
int main(){
    Node* myList;
    init(myList);
    int n,x;
    cin >> n;
    while (n--){
        cin >> x;
        pushB(myList,x);
    }
    solve(myList);
}
 
////////////////////////////////////////
//Pointer_ array_01
// con trỏ và mảng
/*
Cho một mảng các số nguyên, hãy kiểm tra mảng có tính đối xứng hay không?
Yêu cầu:
Sử dụng biến con trỏ để quản lý mảng
Sử dụng vùng nhớ động để cấp phát mảng
Input:
- Dòng đầu tiên: số nguyên cho biết số lượng phần tử mảng
- Dòng thứ hai: danh sách các số nguyên là giá trị của từng phần tử mảng, mỗi phần tử cách nhau khoảng trắng.
Output:
- Nếu mảng có tính đối xứng, in ra dòng chữ: "mang doi xung"
- Nếu mảng không có tính đối xứng, in ra dòng chữ: "mang khong doi xung" và các cặp phần tử làm cho mảng không đối xứng.
 
Ví dụ:
Input:
5
1 2 3 2 1
Output:
mang doi xung
 
Input:
5
1 2 3 4 5
Output:
mang khong doi xung
1 5
2 4
 
*/
#include<iostream>
using namespace std;
void nhap(int *a, int n){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
bool kt(int *a,int n){
    bool flag = true;
    for(int i=0;i<n/2;i++){
        if(a[i]!=a[n-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
void xuatvt(int *a, int n){
    for(int i=0;i<n/2;i++){
        if(a[i]!=a[n-i-1]){
            cout<<a[i]<<" "<<a[n-i-1]<<endl;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int *a;
    a = new int[n];
    nhap(a,n);
    if(kt(a,n)==false){
        cout<<"mang khong doi xung"<<endl;
        xuatvt(a,n);
    }else{
        cout<<"mang doi xung";
    }
    return 0;
}
///////////////////////////////////////////////////////////
//con trỏ mảng 2 chiều
//pointer_mang 2
/*
Viết chương trình tạo ra ma trận đơn vị cấp N.
Yêu cầu:
Sử dụng biến con trỏ để quản lý mảng
Sử dụng vùng nhớ động để cấp phát mảng
Input: số nguyên dương cho biết cấp của ma trận
Output: ma trận đơn vị tương ứng. Mỗi phần tử mảng cách nhau 1 khoảng trắng
 
Ví dụ:
Input: 2
Output:
1 0
0 1
 
Input: 5
1 0 0 0 0
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
 
*/
#include<bits/stdc++.h>
#define COL 50
#define ROW 50
using namespace std;
int main(){
    int m[COL][ROW];
    int n;
    cin>>n;
    int **ppa=new int*[n];
    for(int i=0;i<n;i++){
        ppa[i]=new int[n];
    }
    //nhap
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ppa[i][j];
        }
    }*/
    //xuat
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           
           
            if(i==j)
            ppa[i][j]=1;
             cout<<ppa[i][j]<<" ";
        
        
    }
         cout<<endl;
    }
    return 0;
}
/////////////////////////////////////
//Pointer_MissingPrime
//con trỏ MissingPrime
/*
Cho dãy số nguyên tố được sắp theo thứ tự tăng dần. Gọi m là số nguyên tố nhỏ nhất trong dãy và M là số nguyên tố lớn nhất trong dãy. 
Hãy xác định trong đoạn từ m đến M còn thiếu những số nguyên tố nào và tự động điền những số còn thiếu để tạo thành một mảng các giá trị số nguyên tố liên tục từ m đến M
Yêu cầu:
Sử dụng biến con trỏ để quản lý mảng
Sử dụng vùng nhớ động để cấp phát mảng
Input: hai số nguyên tố m và M, với m < M
Output: mảng các số nguyên tố liên tục từ m đến M, mỗi số cách nhau 1 khoảng trắng
 
Ví dụ: 
Input: 2 11
Output: 2 3 5 7 11
 
Input: 13 17
Output: 13 17
 
*/
#include<iostream>
#include<cmath>
using namespace std;
bool ktra(int n){
    float k=sqrt(n);
    for(int i=2;i<=k;i++){
        if(n%i==0 ) return false;
    }
    return true;
}
int main(){
    int m,M;
    cin>>m>>M;
    int *a=new int[M];
    
    for(int i=m;i<=M;i++){
        if(ktra(i)==true)   cout<<i<<" ";
    }
    delete[]a;
}
//////////////////////////////////
//1718_2_LTNC_Midterm_01
//1718 HK2 LTNC - Số phức
/*
Số có dạng z = a + bi, gọi là số phức. Trong đó a gọi là phần thực (real), còn b gọi là phần ảo (image).
|z| = sqrt(a2 + b2), gọi là mô-đun của số phức z
Cho hai số phức z1 = a + bi, z2 = c + di
Cộng, trừ số phức: z1 + z2 = (a+c) + (b+d)i
Trừ số phức: z1 - z2 = (a-c) + (b-d)i
Xây dựng cấu trúc mô tả một dãy N (0 <= N <= 10,000) số phức với các thao tác sau:
a)     Tính tổng N số phức
b)    Tính hiệu N số phức
c)     Tính mô-đun N số phức
d)    Xuất N số phức theo định dạng: z = a + bi (với a là phần thực và b là phần ảo)
 
Yêu cầu: sử dụng kĩ thuật cấp phát động và con trỏ để quản lý dãy số. Bài làm không đúng yêu cầu sẽ không được tính điểm.
 
Input:
-       N dòng, mỗi dòng là 1 cặp a và b mô tả thông tin phần thực và phần ảo của 1 số phức.
Output:
-       Dòng 1: xuất N số phức theo định dạng {a+bi}, mỗi số phức cách nhau 1 khoảng trắng;
-       Dòng 2: giá trị mô-đun của N số phức, lấy tối đa 2 số lẻ ở phần thập phân, mỗi giá trị cách nhau 1 khoảng trắng;
-       Dòng 3: xuất tổng N số phức
 
Ví dụ 1:
Input
Output
1 2
3 4
{1+2i} {3+4i} 
2.24 5.00 
{4+6i}
 
 
Ví dụ 2:
Input
Output
0 -2
3 4
1 1
1 -1
-2 0
{-2i} {3+4i} {1+i} {1-i} {-2} 
2.00 5.00 1.41 1.41 2.00 
{3+2i}
 
*/
 #include <bits/stdc++.h>
using namespace std;
typedef struct {
    int a,b;
} z;
 
void output(z m) {
    cout << '{';
    if(m.a!=0) cout << m.a;
    if(m.b>1) cout << '+' << m.b << 'i';
    if(m.b==1) cout << '+' << 'i';
    if(m.b==-1) cout << '-' << 'i';
    if(m.b<-1) cout << m.b << 'i';
    cout << '}' << " ";
}
 
z sum(z m, z n) {
    z result;
    result.a=m.a+n.a;
    result.b=m.b+n.b;
    return result;
}
float module(z m) {
    return (float)sqrt(m.a*m.a+m.b*m.b);
}
int main() {
    z *m=new z[10000];
    int n=0;
    z t; t.a=0; t.b=0;
    while(cin >> m[n].a >> m[n].b) n++;
    for(int i=0;i<n;i++)
    output(m[i]);
    cout << endl;
    for(int i=0;i<n;i++)
        cout << fixed << setprecision(2) << module(m[i]) << " ";
    cout << endl;
    for(int i=0;i<n;i++)
        t=sum(t,m[i]);
    output(t);
}
 
 
///////////////////////////////////////////////
//COMPLEX_NUMBER
//số phức
/*
Số có dạng z = a + bi, trong đó a, b là số thực, i2 = -1, gọi là số phức. Trong đó a gọi là phần thực (real), còn b gọi là phần ảo (image).
, gọi là mô-đun của số phức z
Cho hai số phức z1 = a + bi, z2 = c + di
Cộng, trừ số phức:
 
 
Xây dựng cấu trúc mô tả một dãy N (0 <= N <= 10,000) số phức với các thao tác sau:
a)     Tính tổng N số phức
b)    Tính hiệu N số phức
c)     Tính mô-đun N số phức
d)    Xuất N số phức theo định dạng: z = a + bi (với a là phần thực và b là phần ảo)
 
Yêu cầu: sử dụng kĩ thuật cấp phát động và con trỏ để quản lý dãy số. Bài làm không đúng yêu cầu sẽ không được tính điểm.
 
Input:
-       N dòng, mỗi dòng là 1 cặp a và b mô tả thông tin phần thực và phần ảo của 1 số phức.
Output:
-       Dòng 1: xuất N số phức theo định dạng {a+bi}, mỗi số phức cách nhau 1 khoảng trắng;
-       Dòng 2: giá trị mô-đun của N số phức, lấy tối đa 2 số lẻ ở phần thập phân, mỗi giá trị cách nhau 1 khoảng trắng;
Dòng 3: xuất tổng N số phức
 
Ví dụ:
 
Input
Output
3 4
-2 5
11 -14
{3+4i} {-2+5i} {11-14i}
5.00 5.39 17.80
{12-5i}
 
*/
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
struct SoPhuc{
    double a,b;
};
struct List{
    int n;
    SoPhuc *z1;
};
bool Nhap(SoPhuc *z){
   return cin>>z->a>>z->b;
}
void Xuat(SoPhuc z){
     if(z.b>=0){
        cout<<"{"<<z.a<<"+"<<z.b<<"i}";
     }
        else cout<<"{"<<z.a<<z.b<<"i}";
}
SoPhuc TongSP(SoPhuc z1, SoPhuc z2){
    SoPhuc z3;
    z3.a=z1.a+z2.a;
    z3.b=z1.b+z2.b;
    return z3;
}
double Modun(SoPhuc z1){
    return sqrt(z1.a*z1.a+z1.b*z1.b);
}
SoPhuc Hieu(SoPhuc z1, SoPhuc z2){
    SoPhuc z3;
    z3.a=z1.a-z2.a;
    z3.b=z1.b-z2.b;
    return z3;
}
void NhapDS(SoPhuc ds[],int *n){
   int i=0;
   while(Nhap(&ds[i])){
       i++;
   }
   *n=i;
}
void XuatDS(SoPhuc ds[],int n){
    for(int i=0;i<n;++i){
        Xuat(ds[i]);
        cout<<" ";
    }
}
void XuatModun(SoPhuc ds[],int n){
    for(int i=0;i<n;++i){
        cout<<fixed;
        cout<<setprecision(2)<<Modun(ds[i])<<" ";
    }
    cout<<endl;
}
void XuatTongSP(SoPhuc ds[],int n){
    cout<<fixed;
    SoPhuc sum={0,0};
    for(int i=0;i<n;++i){
        sum=TongSP(sum,ds[i]);
    }
    Xuat(sum);
}
int main(){
    SoPhuc ds[100];
    int n;
    NhapDS(ds,&n);
    XuatDS(ds,n);
    cout<<endl;
    XuatModun(ds,n);
   // cout<<endl;
   cout<<fixed;
   cout<<setprecision(0);
    XuatTongSP(ds,n);
    return 0;
}
 
