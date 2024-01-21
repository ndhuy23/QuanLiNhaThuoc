#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Date {
	int ngay;
	int thang;
	int nam;
};

struct nhanVien{
    long maNhanVien;
    string tenNhanVien;
    Date ngaySinh;
    Date ngayVaoLam;
    string queQuan;
    long luongCoBan;
    int diemDanh;
    int soThangDaLam;
    int soNamDaLam;
    string bangCap;
    nhanVien *next;
    nhanVien *prev;
};
struct luongNhanVien{
    long maNhanVien;
    string tenNhanVien;
    long luongCoBan;
    int diemDanh;
    int luong;
    Date ngayNhanLuong;
    luongNhanVien *next;
};
struct thongtinThuoc {
	string tenThuoc;
	int soLuong;
	long long giaTien;
	string donVi;
	Date hanSuDung;
	Date ngayVeKho;
};

struct KhachHang {
	string ten;
	Date ngayMuaHang;
	string bieuHien;
};

struct Thuoc {
	thongtinThuoc thuoc;
	Thuoc* next;
	Thuoc* prev;
};

struct DonThuoc {
	string maDonThuoc;
	KhachHang khachHang;
	int soLoaiThuoc;
	thongtinThuoc thuoc[10];
	long long tongTien;
	DonThuoc* next;
	DonThuoc* prev;
};

struct listKhachHang {
	DonThuoc* head;
	DonThuoc* tail;
};

struct listKhoThuoc {
	Thuoc* head;
	Thuoc* tail;
};

struct listThuocChuaNhap {
	Thuoc* head;
	Thuoc* tail;
};

struct listNhanVien{
    nhanVien *head;
    nhanVien *tail;
};

struct listLuong{
    luongNhanVien *head;
    luongNhanVien *tail;
};

void init(listKhoThuoc &lkt, listKhachHang &lkh, listThuocChuaNhap &ltcn) {//tao list
	lkt.head = lkt.tail = NULL;
	lkh.head = lkh.tail = NULL;
	ltcn.head = ltcn.tail = NULL;
}

void inits(listNhanVien &lnv, listLuong &ll){
    lnv.head = lnv.tail = NULL;
    ll.head = ll.tail = NULL;
}

string chuanHoaTen(string ten){//chuan hoa ten so dep
    string res="";
    stringstream ss(ten);
    string token;
    while(ss>>token){
        res+=toupper(token[0]);
        for(int i =1; i<token.length(); i++){
            res += tolower(token[i]);
        }
        res+=" ";
    }
    res.erase(res.length()-1);
    return res;
}

string chuanHoaHoaDon(string ma){//chuan hoa ma don de so sanh thu co don cu k
    string res="";
    for(int i=0; i<ma.length(); i++){
        res+=toupper(ma[i]);
    }
    return res;
}

bool kiemTraMaHoaDon(listKhachHang lkh, string ma){
    DonThuoc *p = lkh.head;
    while(p!=NULL){
        if(p->maDonThuoc == ma){
            return true;
        }
        p=p->next;
    }
    return false;
}

bool namNhuan(int nam){
    if((nam%4==0 && nam%100!=0)||nam%400==0)
        return true;
    return false;
}

int returnNgay(int thang, int nam){
    switch(thang){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if(namNhuan(nam)==true)
                return 29;
            return 28;
    }
}

bool kiemTraKhoThuoc(string ten, listKhoThuoc &lkt){
    Thuoc *node = lkt.head;
    while(node != NULL){
        if(ten == node->thuoc.tenThuoc){
            return true;
        }
        node = node->next;
    }
    return false;
}

bool kiemTraSoLuong(string ten, int soLuong, listKhoThuoc lkt){
    Thuoc *node = lkt.head;
    while(node !=NULL){
        if(ten == node -> thuoc.tenThuoc){
            if(soLuong <= node -> thuoc.soLuong){
                return true;
            }
        }
        node = node ->next;
    }
    return false;
}

bool kiemTraMaNhanVien(listNhanVien &lnv, long maNhanVien){
    nhanVien *node = lnv.head;
    while(node != NULL){
        if(node -> maNhanVien == maNhanVien){
            return false;
        }
        node = node -> next;
    }
    return true;
}

void capNhatSoLuongTrongKho(listKhoThuoc &lkt, string tenThuoc, int soLuong){
    Thuoc *node = lkt.head;
    while(node != NULL){
        if(node ->thuoc.tenThuoc == tenThuoc){
            node ->thuoc.soLuong = node -> thuoc.soLuong - soLuong;
        }
        node = node ->next;
    }
}

nhanVien *createNhanVien(long maNhanVien, string tenNhanVien, Date ngaySinh, string queQuan, string bangCap, long luongCoBan, int diemDanh, int soThangDaLam, int soNamDaLam, Date ngayVaoLam){
    nhanVien *node = new nhanVien;
    node -> maNhanVien = maNhanVien;
    node -> tenNhanVien = tenNhanVien;
    node -> ngaySinh.ngay = ngaySinh.ngay;
    node -> ngaySinh.thang = ngaySinh.thang;
    node -> ngaySinh.nam = ngaySinh.nam;
    node -> queQuan = queQuan;
    node -> bangCap = bangCap;
    node -> ngayVaoLam.ngay = ngayVaoLam.ngay;
    node -> ngayVaoLam.thang = ngayVaoLam.thang;
    node -> ngayVaoLam.nam = ngayVaoLam.nam;
    node -> luongCoBan = luongCoBan;
    node -> diemDanh = diemDanh;
    node -> soThangDaLam = soThangDaLam;
    node -> soNamDaLam = soNamDaLam;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}

void themNhanVien(listNhanVien &lnv){
    long maNhanVien;
    string tenNhanVien;
    Date ngaySinh;
    Date ngayVaoLam;
    string queQuan;
    string bangCap;
    long luongCoBan;
    int diemDanh;
    int soThangDaLam;
    int soNamDaLam;
    do{
        cout<<"\nNhap ma nhan vien: ";
        cin>>maNhanVien;
        if(kiemTraMaNhanVien(lnv, maNhanVien) == false){
            cout<<"\nMa nhan vien da ton tai, moi nhap lai";
        }
    }while(kiemTraMaNhanVien(lnv, maNhanVien) == false);
    cout<<"\nNhap ten nhan vien: ";
    cin.ignore();
    getline(cin, tenNhanVien);
    tenNhanVien = chuanHoaTen(tenNhanVien);
    cout<<"\nNhap ngay thang nam sinh";
    cout<<"\nNhap nam sinh: ";
    do{
        cin>>ngaySinh.nam;
        if(ngaySinh.nam < 1950 || ngaySinh.nam > 2000){
            cout<<"\nNam sinh khong hop le";
        }
    }while(ngaySinh.nam < 1950 || ngaySinh.nam > 2000);
    cout<<"\nNhap thang sinh: ";
    do{
        cin>>ngaySinh.thang;
        if(ngaySinh.thang < 1 || ngaySinh.thang > 12){
            cout<<"\nThang khong hop le";
        }
    }while(ngaySinh.thang < 1 || ngaySinh.thang > 12);
    cout<<"\nNhap ngay sinh: ";
    do{
        cin>>ngaySinh.ngay;
        if(ngaySinh.ngay < 1 || ngaySinh.ngay > returnNgay(ngaySinh.thang, ngaySinh.nam)){
            cout<<"\nThang "<<ngaySinh.thang<<" chi co "<<returnNgay(ngaySinh.thang, ngaySinh.nam)<<" ngay";
            cout<<"\nMoi nhap lai: ";
        }
    }while(ngaySinh.ngay < 1 || ngaySinh.ngay > returnNgay(ngaySinh.thang, ngaySinh.nam));
    cout<<"\nNhap que quan: ";
    cin.ignore();
    getline(cin, queQuan);
    cout<<"\nNhap luong co ban: ";
    do{
        cin>>luongCoBan;
        if(luongCoBan < 0){
            cout<<"\nNhap lai";
        }
    }while(luongCoBan < 0);
    cout<<"\nNhap bang cap: ";
    cin.ignore();
    getline(cin, bangCap);
    diemDanh = 0;
    soThangDaLam = 0;
    soNamDaLam = 0;
    cout<<"\nNhap ngay vao lam";
    cout<<"\nNhap nam: ";
    do{
        cin>>ngayVaoLam.nam;
        if(ngayVaoLam.nam > 2022){
            cout<<"\nNam khong hop le";
        }
    }while(ngayVaoLam.nam > 2022);
    cout<<"\nNhap thang: ";
    do{
        cin>>ngayVaoLam.thang;
        if(ngayVaoLam.thang < 1 || ngayVaoLam.thang > 12){
            cout<<"\nThang khong hop le";
        }
    }while(ngayVaoLam.thang < 1 || ngayVaoLam.thang > 12);
    cout<<"\nNhap ngay: ";
    do{
        cin>>ngayVaoLam.ngay;
        if(ngayVaoLam.ngay < 1 || ngayVaoLam.ngay > returnNgay(ngayVaoLam.thang, ngayVaoLam.nam)){
            cout<<"\nThang "<<ngayVaoLam.thang<<" chi co "<<returnNgay(ngayVaoLam.thang, ngayVaoLam.nam)<<" ngay";
            cout<<"\nMoi nhap lai: ";
        }
    }while(ngayVaoLam.ngay < 1 || ngayVaoLam.ngay > returnNgay(ngayVaoLam.thang, ngayVaoLam.nam));
    nhanVien *node = createNhanVien(maNhanVien, tenNhanVien, ngaySinh, queQuan, bangCap, luongCoBan, diemDanh, soThangDaLam, soNamDaLam, ngayVaoLam);
    if(lnv.head == NULL){
        lnv.head = lnv.tail = node;
    }
    else{
        lnv.tail -> next = node;
        node -> prev = lnv.tail;
        lnv.tail = node;
    }
    cout<<"\nDa them nhan vien";
}

void thayDoiThongTinNhanVien(listNhanVien &lnv){
    if(lnv.head == NULL){
        cout<<"\nDanh sach nhan vien hien dang trong";
        return;
    }
    else{
        cout<<"\nNhap ma nhan vien can thay doi thong tin: ";
        int maNhanVien;
        do{
            cin>>maNhanVien;
            if(kiemTraMaNhanVien(lnv, maNhanVien)){
                cout<<"\nHien khong co ma nhan vien nay, vui long kiem tra lai";
            }
        }while(kiemTraMaNhanVien(lnv, maNhanVien));
        nhanVien *node = lnv.head;
        while(node -> maNhanVien != maNhanVien){
            node = node -> next;
        }
        while(true){
            cout<<"\n=========Thong tin co the thay doi=============";
            cout<<"\n1.Ten nhan vien";
            cout<<"\n2.Luong co ban";
            cout<<"\n3.Bang cap";
            cout<<"\n4.Hoan tat thay doi";
            int luaChon;
            cout<<"\nNhap lua chon: ";
            do{
                cin>>luaChon;
                if(luaChon < 1 || luaChon > 4){
                    cout<<"\nNhap sai";
                }
            }while(luaChon < 1 || luaChon > 4);
            if(luaChon == 1){
                string tenNhanVien;
                cout<<"\nNhap ten moi cua nhan vien: ";
                cin.ignore();
                getline(cin, tenNhanVien);
                node -> tenNhanVien = chuanHoaTen(tenNhanVien);
            }
            else if(luaChon == 2){
                cout<<"\nNhap luong thay the: ";
                int luongCoBan;
                do{
                    cin>>luongCoBan;
                    if(luongCoBan < 0){
                        cout<<"\nNhap sai";
                    }
                }while(luongCoBan < 0);
                node -> luongCoBan = luongCoBan;
            }
            else if(luaChon == 3){
                cout<<"\nNhap bang cap moi: ";
                string bangCap;
                cin.ignore();
                getline(cin, bangCap);
                node -> bangCap = bangCap;
            }
            else{
                cout<<"\nDa cap nhat hoan tat thong tin cua "<<node -> maNhanVien;
                return;
            }
        }
    }
    cout<<"\nDa thay doi";
    return;
}

luongNhanVien *createBangLuong(long maNhanVien, string tenNhanVien, long luongCoBan, int diemDanh, Date ngayNhanLuong){
    luongNhanVien *node = new luongNhanVien;
    node -> maNhanVien = maNhanVien;
    node -> tenNhanVien = tenNhanVien;
    node -> luongCoBan = luongCoBan;
    node -> diemDanh = diemDanh;
    node -> ngayNhanLuong = ngayNhanLuong;
    node -> luong = luongCoBan * diemDanh;
    node -> next = NULL;
    return node;
}

void traLuongNhanVien(listNhanVien &lnv, listLuong &ll){
    if(lnv.head == NULL){
        cout<<"\nHien chua co nhan vien de tra luong";
        return;
    }
    Date ngayNhanLuong;
    cout<<"\nNhap ngay tinh luong";
    cout<<"\nNhap nam: ";
    cin>>ngayNhanLuong.nam;
    cout<<"\nNhap thang: ";
    do{
        cin>>ngayNhanLuong.thang;
        if(ngayNhanLuong.thang < 1 || ngayNhanLuong.thang > 12){
            cout<<"\nNhap sai";
        }
    }while(ngayNhanLuong.thang < 1 || ngayNhanLuong.thang > 12);
    cout<<"\nNhap ngay: ";
    do{
        cin>>ngayNhanLuong.ngay;
        if(ngayNhanLuong.ngay < 1 || ngayNhanLuong.ngay > returnNgay(ngayNhanLuong.thang, ngayNhanLuong.nam)){
            cout<<"\nThang "<<ngayNhanLuong.thang<<" chi co toi da "<<returnNgay(ngayNhanLuong.thang, ngayNhanLuong.nam)<<" ngay";
        }
    }while(ngayNhanLuong.ngay < 1 || ngayNhanLuong.ngay > returnNgay(ngayNhanLuong.thang, ngayNhanLuong.nam));
    nhanVien *node = lnv.head;
    while(node != NULL){
        luongNhanVien *node1 = createBangLuong(node -> maNhanVien, node -> tenNhanVien, node -> luongCoBan, node -> diemDanh, ngayNhanLuong);
        node -> diemDanh = 0;
        node -> soThangDaLam += 1;
        if(ngayNhanLuong.thang == 12){
            node -> soNamDaLam += 1;
        }
        if(ll.head == NULL){
            ll.head = ll.tail = node1;
        }
        else{
            ll.tail -> next = node1;
            ll.tail = node1;
        }
        node = node -> next;
    }
    cout<<"\nDa tra luong nhan vien thang "<<ngayNhanLuong.thang;
}

void kiemTraBangLuong(listLuong &ll, long taiKhoan, string matKhau){
    if(ll.head  == NULL){
        cout<<"\nBang luong hien con trong";
        return;
    }
    else if(taiKhoan == 2151120005 && matKhau == "xinh6b9g"){
        cout<<"\nBan muon kiem tra mot nhan vien hay toan bo nhan vien";
        cout<<"\n1. Mot nhan vien";
        cout<<"\n2. Toan bo nhan vien";
        int luaChon;
        cout<<"\nNhap lua chon :";
        do{
            cin>>luaChon;
            if(luaChon < 1 || luaChon > 2){
                cout<<"\nNhap sai";
            }
        }while(luaChon < 1 || luaChon > 2);
        if(luaChon == 1){
            int maNhanVien;
            cout<<"\nNhap ma nhan vien: ";
            cin>>maNhanVien;
            luongNhanVien *node = ll.head;
            while(node != NULL){
                if(node -> maNhanVien == maNhanVien){
                    cout<<"\nThong tin bang luong";
                    cout<<"\nMa nhan vien: "<<node -> maNhanVien;
                    cout<<"\nTen nhan vien: "<<node -> tenNhanVien;
                    cout<<"\nLuong thang "<<node -> ngayNhanLuong.thang<<" :"<<node -> luong;
                }
                node = node -> next;
            }
        }
        else{
            luongNhanVien *node = ll.head;
            while(node != NULL){
                cout<<"\nThong tin bang luong";
                cout<<"\nMa nhan vien: "<<node -> maNhanVien;
                cout<<"\nTen nhan vien: "<<node -> tenNhanVien;
                cout<<"\nLuong: "<<node -> ngayNhanLuong.thang<<" :"<<node -> luong;
            node = node -> next;
            }
        }
    }
    else{
        luongNhanVien *node = ll.head;
        while(node != NULL){
            if(node -> maNhanVien == taiKhoan){
                cout<<"\nThong tin bang luong";
                cout<<"\nMa nhan vien: "<<node -> maNhanVien;
                cout<<"\nTen nhan vien: "<<node -> tenNhanVien;
                cout<<"\nLuong: "<<node -> ngayNhanLuong.thang<<" :"<<node -> luong;
            }
            node = node -> next;
        }
    }
}

void inDanhSachNhanVien(listNhanVien &lnv){
    if(lnv.head == NULL){
        cout<<"\nHien khong co nhan vien";
        return;
    }
    else{
        cout<<"\n==========Thong tin nhan vien=============";
        nhanVien *node = lnv.head;
        while(node != NULL){
            cout<<"\nMa nhan vien: "<<node -> maNhanVien;
            cout<<"\nTen nhan vien: "<<node -> tenNhanVien;
            cout<<"\nNgay thang nam sinh: "<<node -> ngaySinh.ngay<<"/"<<node -> ngaySinh.thang<<"/"<<node -> ngaySinh.nam;
            cout<<"\nQue quan: "<<node -> queQuan;
            cout<<"\nNgay vao lam: "<<node -> ngayVaoLam.ngay<<"/"<<node -> ngayVaoLam.thang<<"/"<<node -> ngayVaoLam.nam;
            cout<<"\nLuong co ban: "<<node -> luongCoBan;
            cout<<"\nBang cap: "<<node -> bangCap;
            cout<<"\nSo ngay da diem danh trong thang qua: "<<node -> diemDanh;
            cout<<"\nSo thang da lam trong nam qua: "<<node -> soThangDaLam;
            cout<<"\nSo nam da lam: "<<node -> soNamDaLam;
            cout<<"\n------------------------------------------";
            node = node -> next;
        }
    }
 }
 
void xoaNhanVien(listNhanVien &lnv){
    if(lnv.head == NULL){
        cout<<"\nDanh sach nhan vien hien dang trong";
        return;
    }
    cout<<"\nNhap ma nhan vien can xoa: ";
    int maNhanVien;
    cin>>maNhanVien;
    nhanVien *node = lnv.head;
    while(node -> maNhanVien != maNhanVien && node != NULL){
        node = node -> next;
    }
    if(node != NULL){
        cout<<"\nBan co chac muon xoa nhan vien khong";
        cout<<"\n1. Co";
        cout<<"\n2. Khong";
        int luaChon;
        cin>>luaChon;
        if(luaChon == 1){
            if(node == lnv.head){
                lnv.head = node -> next;
                lnv.head -> prev = NULL;
                node -> next = NULL;
                delete node;
            }
            else{
                if(node != lnv.tail){
                    node -> next -> prev = node -> prev;
                    node -> prev -> next = node -> next;
                    delete node;
                }
                else{
                    lnv.tail = node -> prev;
                    lnv.tail -> next = NULL;
                    node -> prev = NULL;
                    delete node;
                }
            }
            cout<<"\nDa xoa nhan vien";
            return;
        }
        else{
            cout<<"\nDa huy thao tac xoa";
            return;
        }
    }
    else{
        cout<<"\nKhong tim thay ma nhan vien";
        return;
    }
}

DonThuoc* makeNode(listKhoThuoc &lkt, int tongKhachHang, string maHoaDon, string tenKhachHang, string bieuHien, int n, string tenThuoc[], int soLuong[]) {
	DonThuoc *node = new DonThuoc();
	node -> maDonThuoc = maHoaDon;
	node -> khachHang.ten = tenKhachHang;
	node -> khachHang.bieuHien;
	node -> soLoaiThuoc = n;
	node -> tongTien = 0;
	for(int i = 0; i<n; i++){
	    node -> thuoc[i].tenThuoc = tenThuoc[i];
	    node -> thuoc[i].soLuong = soLuong[i];
	    Thuoc *temp = lkt.head;
	    while(temp-> thuoc.tenThuoc != tenThuoc[i]){
	        temp = temp -> next;
	    }
	    temp -> thuoc.soLuong = temp -> thuoc.soLuong;
	    node -> thuoc[i].donVi = temp ->thuoc.donVi;
	    node -> thuoc[i].giaTien = temp ->thuoc.giaTien;
	    node -> thuoc[i].hanSuDung.ngay = temp -> thuoc.hanSuDung.ngay;
	    node -> thuoc[i].hanSuDung.thang = temp -> thuoc.hanSuDung.thang;
	    node -> thuoc[i].hanSuDung.nam = temp -> thuoc.hanSuDung.nam;
	    node -> thuoc[i].ngayVeKho.ngay = temp -> thuoc.ngayVeKho.ngay;
	    node -> thuoc[i].ngayVeKho.thang = temp -> thuoc.ngayVeKho.thang;
	    node -> thuoc[i].ngayVeKho.nam = temp -> thuoc.ngayVeKho.nam;
	    node -> tongTien = node -> tongTien + node -> thuoc[i].giaTien * node -> thuoc[i].soLuong;
	}
	int ngay, thang, nam;
	cout<<"\nVui long nhap thong tin ngay mua hang";
	do{
	    cout<<"\nNhap ngay mua hang (nam): ";
	    cin>>nam;
	    if(nam < 2022){
	        cout<<"\nNam be hon nam hien tai";
	        cout<<"\nMoi nhap lai";
	    }
	}while(nam < 2022);
	do{
	    cout<<"\nNhap ngay mua hang (thang): ";
	    cin>>thang;
	    if(thang < 1 || thang > 12){
	        cout<<"\nNhap sai, vui long nhap lai";
	    }
	}while(thang < 1 || thang > 12);
	do{
	    cout<<"\nNhap ngay mua hang (ngay): ";
	    cin>>ngay;
	    if(ngay < 1 || ngay > returnNgay(thang, nam)){
	        cout<<"\nThang "<<thang<<"  cho toi da "<<returnNgay<<" ngay, vui long nhap lai";
	    }
	}while(ngay < 1 || ngay > returnNgay(thang, nam));
	node -> khachHang.ngayMuaHang.ngay = ngay;
	node -> khachHang.ngayMuaHang.thang = thang;
	node -> khachHang.ngayMuaHang.nam = nam;
	return node;
}

void themKhachHangKhongCoHoaDon(listKhoThuoc &lkt, listKhachHang &lkh, listThuocChuaNhap &ltcn, int &tongKhachHang){
    string maHoaDon, tenKhachHang, bieuHien;
    tongKhachHang += 1;
	cout<<"\nMa don thuoc: "<<"DT" + to_string(tongKhachHang);
	maHoaDon = "DT" + to_string(tongKhachHang);
	cout<<"\nNhap ten khach hang: ";
	cin.ignore();
	getline(cin,tenKhachHang);
	cout<<"\nNhap bieu hien: ";
	getline(cin,bieuHien);
	int n;
	cout<<"\nSo loai thuoc can ban: ";
	cin>>n;
	string tenThuoc[n];
	int soLuong[n];
	for(int i =0; i<n; i++){
	    string ten;
	    cout<<"\nNhap ten thuoc: ";
	    cin.ignore();
	    getline(cin, ten);
	    if(kiemTraKhoThuoc(ten, lkt)==true){
	        Thuoc *node = lkt.head;
	        while(node -> thuoc.tenThuoc != ten){
	            node = node -> next;
	        }
	        cout<<"\nNhap so luong "<<node ->thuoc.donVi<<" "<<node ->thuoc.tenThuoc<<" can ban: ";
	        int sl;
	        cin>>sl;
	        if(kiemTraSoLuong(ten, sl, lkt)== true){
	            tenThuoc[i] = ten;
	            soLuong[i] = sl;
	        }
	        else{
	            cout<<"\nSo luong "<<node -> thuoc.tenThuoc<<" hien tai khong du";
	            cout<<"\nCo can thay doi loai thuoc khac khong hay bo qua thuoc hien tai (thay the nhap 1, bo qua nhap 0) ";
	            int luaChon;
	            cin>>luaChon;
	            if(luaChon == 1){
	                cout<<"\nMoi nhap lai ten thuoc thay the";
	                i--;
	            }
	            else{
	                i--;
	                n--;
	                if(n == 0){
        	        cout<<"\nHien nha thuoc da het tat ca thuoc ban can, vui long quay lai sau, cam on da dung dich vu";
        	        tongKhachHang = tongKhachHang -1;
        	        return;
    	            }
	            }
	        }
	    }
	    else{
	        cout<<"\nHien trong kho khong co "<<ten;
	        int luaChon;
	        cout<<"\nCo can thay doi loai thuoc khac khong hay bo qua thuoc hien tai (thay the nhap 1, bo qua nhap 0) ";
	        cin>>luaChon;
	        if(luaChon == 1){
	            cout<<"\nMoi nhap loai thuoc thay the";
	            i--;
	        }
	        else{
	            i--;
	            n = n-1;
	            if(n == 0){
    	        cout<<"\nHien nha thuoc da het tat ca thuoc ban can, vui long quay lai sau, cam on da dung dich vu";
    	        tongKhachHang = tongKhachHang -1;
    	        return;
	            }
	        }
	    }
	}
	DonThuoc *node = makeNode(lkt, tongKhachHang, maHoaDon, tenKhachHang, bieuHien, n, tenThuoc, soLuong);
	if(lkh.head == NULL){
	    lkh.head = lkh.tail = node;
	}
	else{
	    lkh.tail -> next = node;
	    node -> prev = lkh.tail;
	    lkh.tail = node;
	}
	cout<<"\nCam on da su dung dich vu";
}

DonThuoc *capNhatHoaDonMoi(listKhoThuoc &lkt, DonThuoc *p, int tongKhachHang, Date ngayMuaHang){
    DonThuoc *node = new DonThuoc();
    node -> maDonThuoc = "DT" + to_string(tongKhachHang);
    node -> soLoaiThuoc = p->soLoaiThuoc;
    node -> khachHang.ten = p->khachHang.ten;
    node -> khachHang.bieuHien = p->khachHang.bieuHien;
    node -> khachHang.ngayMuaHang.ngay = ngayMuaHang.ngay;
    node -> khachHang.ngayMuaHang.thang = ngayMuaHang.thang;
    node -> khachHang.ngayMuaHang.nam = ngayMuaHang.nam;
    for(int i=0; i< p->soLoaiThuoc; i++){
        node ->thuoc[i].tenThuoc = p->thuoc[i].tenThuoc;
        node ->thuoc[i].soLuong = p->thuoc[i].soLuong;
        node ->thuoc[i].hanSuDung.ngay = p->thuoc[i].hanSuDung.ngay;
        node ->thuoc[i].hanSuDung.thang = p->thuoc[i].hanSuDung.thang;
        node ->thuoc[i].hanSuDung.nam = p->thuoc[i].hanSuDung.nam;
        node ->thuoc[i].ngayVeKho.ngay = p->thuoc[i].ngayVeKho.ngay;
        node ->thuoc[i].ngayVeKho.thang = p->thuoc[i].ngayVeKho.thang;
        node ->thuoc[i].ngayVeKho.nam = p->thuoc[i].ngayVeKho.nam;
        node ->thuoc[i].donVi = p->thuoc[i].donVi;
        capNhatSoLuongTrongKho(lkt, node -> thuoc[i].tenThuoc, node -> thuoc[i].soLuong);
    }
    node -> tongTien = p->tongTien;
    return node;
}

void themKhachHangCoHoaDon(listKhoThuoc &lkt, listKhachHang &lkh, listThuocChuaNhap &ltcn, int &tongKhachHang){
    int luaChon;
    cout<<"\nKhach co mua lai theo hoa don cu khong (co nhap 1, khong nhap 0): ";cin>>luaChon;
	if(luaChon == 1){
       string maDonThuoc;
       cout<<"\nNhap ma hoa don cu: ";
       cin.ignore();
       getline(cin,maDonThuoc);
       maDonThuoc = chuanHoaHoaDon(maDonThuoc);
       DonThuoc *p = lkh.head;
       while(p!=NULL){
           if(p->maDonThuoc == maDonThuoc){
               cout<<"\nDa tim thay don thuoc, cua hang se lay hoa don moi cho quy khach ";
               cout<<"\nMa don thuoc moi la: "<<"DT"+to_string(tongKhachHang);
               Date ngayMuaHang;
               cout<<"\nNhap ngay mua hang";
               cout<<"\nNhap nam: ";cin>>ngayMuaHang.nam;
               do{
            	    cout<<"\nNhap thang: ";cin>>ngayMuaHang.thang;
            	    if(ngayMuaHang.thang > 12 || ngayMuaHang.thang <1){
            	        cout<<"\nNhap sai thang!";
            	    }
            	}while(ngayMuaHang.thang > 12 || ngayMuaHang.thang <1);
                do{
                    cout<<"\nNhap ngay: ";cin>>ngayMuaHang.ngay;
                    if(ngayMuaHang.ngay < 1 || ngayMuaHang.ngay > returnNgay(ngayMuaHang.thang,ngayMuaHang.nam)){
                        cout<<"\nNhap sai ngay!";
                    }
                }while(ngayMuaHang.ngay < 1 || ngayMuaHang.ngay > returnNgay(ngayMuaHang.thang,ngayMuaHang.nam));
               for(int i = 0; i < p->soLoaiThuoc; i++){
                   if(kiemTraKhoThuoc(p->thuoc[i].tenThuoc, lkt)==true){
                       if(kiemTraSoLuong(p->thuoc[i].tenThuoc, p->thuoc[i].soLuong, lkt)== true){
                           cout<<"\nVui long cho chung toi kiem tra kho thuoc";
                       }
                       else{
                           cout<<"\nHien so luong con lai trong kho khong du, xin quay lai sau";
                           return;
                       }
                   }
                   else{
                       cout<<"\nHien nha thuoc da het "<<p->thuoc[i].tenThuoc<<" nhu yeu cau cua don thuoc cu";
                       cout<<"\nVui long quay lai sau, chung toi xin loi vi su bat tien nay";
                       return;
                   }
               }
               tongKhachHang +=1;
               DonThuoc *newNode = capNhatHoaDonMoi(lkt, p, tongKhachHang, ngayMuaHang);
               lkh.tail -> next = newNode;
               newNode -> prev = lkh.tail;
               lkh.tail = newNode;
               cout<<"\nDa cap nhat xong, cam on da dung dich vu!";
               return;
           }
           p=p->next;
       }
       cout<<"\nMa don thuoc khong dung, vui long kiem tra lai hoa don!";
       return;
	}
	else{
	    themKhachHangKhongCoHoaDon(lkt, lkh, ltcn, tongKhachHang);
	}
}

Thuoc *createNode(string tenThuoc, int soLuong, Date hanSuDung, Date ngayVeKho, string donVi, long long giaTien){
    Thuoc *node = new Thuoc();
    node ->thuoc.tenThuoc = tenThuoc;
    node ->thuoc.soLuong = soLuong;
    node ->thuoc.hanSuDung.ngay = hanSuDung.ngay;
    node ->thuoc.hanSuDung.thang = hanSuDung.thang;
    node ->thuoc.hanSuDung.nam = hanSuDung.nam;
    node ->thuoc.ngayVeKho.ngay = ngayVeKho.ngay;
    node ->thuoc.ngayVeKho.thang = ngayVeKho.thang;
    node ->thuoc.ngayVeKho.nam = ngayVeKho.nam;
    node ->thuoc.donVi = donVi;
    node ->thuoc.giaTien = giaTien;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}

void danhSachThuocChuaVeKho(listKhoThuoc &lkt, listKhachHang &lkh, listThuocChuaNhap &ltcn, string tenThuoc, int soLuong, Date hanSuDung, Date ngayVeKho, string donVi, long long giaTien){
    Thuoc *node = createNode(tenThuoc, soLuong, hanSuDung, ngayVeKho, donVi, giaTien);
    if(ltcn.head == NULL){
        ltcn.head = ltcn.tail = node;
    }
    else{
        ltcn.tail -> next = node;
        node -> prev = ltcn.tail;
        ltcn.tail = node;
    }
}

void themVaoKhoThuoc(listKhoThuoc &lkt, string tenThuoc, int soLuong, Date hanSuDung, Date ngayVeKho, string donVi, long long giaTien){
    Thuoc *node = createNode(tenThuoc, soLuong, hanSuDung, ngayVeKho, donVi, giaTien);
    if(lkt.head == NULL){
        lkt.head = lkt.tail = node;
    }
    else{
        lkt.tail -> next = node;
        node -> prev = lkt.tail;
        lkt.tail = node;
    }
}

void chuyenThuocVaoKho(listKhoThuoc &lkt, listKhachHang &lkh, listThuocChuaNhap &ltcn){
    int ngay,thang,nam;
    cout<<"\nHom nay la ngay: ";cin>>ngay;
    cout<<"\nThang: ";cin>>thang;
    cout<<"\nNam: ";cin>>nam;
    Thuoc *node = ltcn.head;
    while(node != NULL){
        if(nam >= node ->thuoc.ngayVeKho.nam){
            if(thang >= node ->thuoc.ngayVeKho.thang){
                if(ngay >= node ->thuoc.ngayVeKho.ngay){
                    if(node == ltcn.head){
                        Thuoc *p = node;
                        cout<<"\nDa chuyen "<<node -> thuoc.tenThuoc<<" vao kho";
                        ltcn.head = p-> next;
                        node = p-> next;
                        themVaoKhoThuoc(lkt,p->thuoc.tenThuoc, p->thuoc.soLuong, p->thuoc.hanSuDung, p->thuoc.ngayVeKho, p->thuoc.donVi, p->thuoc.giaTien);
                        delete(p);
                        continue;
                    }
                    else{
                        if(node != ltcn.tail){
                            Thuoc *p = node;
                            cout<<"\nDa chuyen"<<node -> thuoc.tenThuoc<<" vao kho";
                            node = p-> next;
                            p->prev->next = node;
                            node -> prev = p->prev;
                            themVaoKhoThuoc(lkt,p->thuoc.tenThuoc, p->thuoc.soLuong, p->thuoc.hanSuDung, p->thuoc.ngayVeKho, p->thuoc.donVi, p->thuoc.giaTien);
                            delete(p);
                            continue;
                        }
                        else{
                            Thuoc *p = node;
                            cout<<"\nDa chuyen "<<node -> thuoc.tenThuoc<<" vao kho";
                            node = p->prev;
                            ltcn.tail = node;
                            node -> next = NULL;
                            themVaoKhoThuoc(lkt, p->thuoc.tenThuoc, p->thuoc.soLuong, p->thuoc.hanSuDung, p->thuoc.ngayVeKho, p->thuoc.donVi, p->thuoc.giaTien);
                            delete(p);
                            continue;
                        }
                    }
                }
            }
        }
        node=node->next;
    }
    cout<<"\nDa chuyen het cac loai thuoc moi ve vao kho";
}

void kiemTraThuocQuaHan(listKhoThuoc &lkt){
    int ngay, thang, nam;
    cout<<"\nXin moi nhap ngay hien tai";
    cout<<"\nNgay: ";
    cin>>ngay;
    cout<<"\nThang: ";
    cin>>thang;
    cout<<"\nNam: ";
    cin>>nam;
    Thuoc *node = lkt.head;
    while(node != NULL){
        if(node ->thuoc.hanSuDung.nam <= nam){
            if(node -> thuoc.hanSuDung.thang <= thang){
                if(node -> thuoc.hanSuDung.ngay <= ngay){
                    if(node == lkt.head){
                        Thuoc *p = node;
                        cout<<"\nDa loai bo "<<node ->thuoc.tenThuoc<<" ra khoi kho";
                        node = p-> next;
                        lkt.head = node;
                        delete(p);
                        continue;
                    }
                    else{
                        if(node != lkt.tail){
                            Thuoc *p = node;
                            cout<<"\nDa loai bo "<<node -> thuoc.tenThuoc<<" ra khoi kho";
                            node = p-> next;
                            p->prev->next = node;
                            node -> prev = p->prev;
                            delete(p);
                            continue;
                        }
                        else{
                            Thuoc *p = node;
                            cout<<"\nDa loai bo "<<node -> thuoc.tenThuoc<<" ra khoi kho";
                            node = p->prev;
                            lkt.tail = node;
                            node -> next = NULL;
                            delete(p);
                            continue;
                        }
                    }
                }
            }
        }
        node = node -> next;
    }
    cout<<"\nDa loai bo tat ca thuoc het han";
}

void kiemTraThuocDaHet(listKhoThuoc &lkt){
    Thuoc *node = lkt.head;
    while(node !=NULL){
        if(node -> thuoc.soLuong  == 0){
            if(node == lkt.head){
                Thuoc *p = node;
                node = p-> next;
                lkt.head = node;
                delete(p);
                continue;
            }
            else{
                if(node != lkt.tail){
                    Thuoc *p = node;
                    node = p-> next;
                    node ->prev = p->prev;
                    p->prev->next = node;
                    delete(p);
                    continue;
                }
                else{
                    Thuoc *p = node;
                    node = p->prev;
                    lkt.tail = node;
                    node-> next = NULL;
                    delete(p);
                    continue;
                }
            }
        }
        node=node->next;
    }
}

void print(listKhachHang lkh){//nay de kiem tra thong tin thu dung k, cu de do k can xoa
    if(lkh.head == NULL){
        cout<<"\nHien chua co danh sach khach hang";
    }
    else{
        DonThuoc *p = lkh.head;
        while(p!=NULL){
            cout<<"\nMa don thuoc: "<<p->maDonThuoc;
            cout<<"\nTen khach hang: "<<p->khachHang.ten;
            cout<<"\nBieu hien: "<<p->khachHang.bieuHien;
            cout<<"\nNgay mua Hang: "<<p->khachHang.ngayMuaHang.ngay<<"/"<<p->khachHang.ngayMuaHang.thang<<"/"<<p->khachHang.ngayMuaHang.nam;
            for(int i =0; i<p->soLoaiThuoc; i++){
                cout<<"\n"<<left<<setw(10)<<"Ten loai thuoc: "<<left<<setw(10)<<p->thuoc[i].tenThuoc<<left<<setw(10)<<"So luong: "<<left<<setw(10)<<p->thuoc[i].soLuong<<left<<setw(10)<<"Han su dung: "<<p->thuoc[i].hanSuDung.ngay<<"/"<<p->thuoc[i].hanSuDung.thang<<"/"<<p->thuoc[i].hanSuDung.nam;
                }
            cout<<"\nThanh tien: "<<p->tongTien;
            p=p->next;
            }
    }
}

void inThuocChuaNhap(listThuocChuaNhap ltcn){
    if(ltcn.head == NULL){
        cout<<"\nHien chua co thuoc dang nhap";
    }
    else{
        Thuoc *node = ltcn.head;
        while(node != NULL){
        cout<<"\nTen thuoc:"<<node ->thuoc.tenThuoc;
        cout<<"\nSo luong: "<<node ->thuoc.soLuong;
        cout<<"\nHan su dung: "<<node ->thuoc.hanSuDung.ngay<<"/"<<node ->thuoc.hanSuDung.thang<<"/"<<node ->thuoc.hanSuDung.nam;
        cout<<"\nNgay ve kho: "<<node ->thuoc.ngayVeKho.ngay<<"/"<<node ->thuoc.ngayVeKho.thang<<"/"<<node ->thuoc.ngayVeKho.nam;
        node = node -> next;
        }
    }
}

void inKhoThuoc(listKhoThuoc lkt){
    if(lkt.head == NULL){
        cout<<"\nHien kho da het thuoc";
    }
    else{
        cout<<"\nDuoi day la tat ca thuoc hien co trong kho";
        Thuoc *node = lkt.head;
        while(node != NULL){
        cout<<"\nTen thuoc:"<<node ->thuoc.tenThuoc;
        cout<<"\nSo luong: "<<node ->thuoc.soLuong;
        cout<<"\nHan su dung: "<<node ->thuoc.hanSuDung.ngay<<"/"<<node ->thuoc.hanSuDung.thang<<"/"<<node ->thuoc.hanSuDung.nam;
        cout<<"\nGia tien: "<<node->thuoc.giaTien<<"/"<<node->thuoc.donVi;
        node = node->next;
        }
    }
}

void quanLi(listKhoThuoc &lkt, listKhachHang &lkh, listThuocChuaNhap &ltcn, listNhanVien &lnv, listLuong &ll, long taiKhoan, string matKhau){
    cout<<"\nBan da dang nhap voi tu cach quan li";
    int luaChon; 
    while(true){
        cout<<"\n============Cac hoat dong cua quan li=============";
        cout<<"\n1. Them nhan vien";
        cout<<"\n2. Thay doi thong tin nhan vien";
        cout<<"\n3. Tra luong nhan vien";
        cout<<"\n4. Kiem tra bang luong";
        cout<<"\n5. Xoa nhan vien";
        cout<<"\n6. In danh sach nhan vien";
        cout<<"\n7. Ket thuc ca lam viec";
        cout<<"\n==================================================";
        cout<<"\nNhap lua chon: ";
        do{
            cin>> luaChon;
            if(luaChon > 7 || luaChon < 1){
                cout<<"\nNhap lai";
            }
        }while(luaChon > 7 || luaChon < 1);
        if(luaChon == 1){
            themNhanVien(lnv);
        }
        else if(luaChon == 2){
            thayDoiThongTinNhanVien(lnv);
        }
        else if(luaChon == 3){
            traLuongNhanVien(lnv, ll);
        }
        else if(luaChon == 4){
            kiemTraBangLuong(ll, taiKhoan, matKhau);
        }
        else if(luaChon == 5){
            xoaNhanVien(lnv);
        }
        else if(luaChon == 6){
            inDanhSachNhanVien(lnv);
        }
        else{
            cout<<"\nKet thuc ca lam viec";
            return;
        }
    }
}
void nhanVienLamViec(listKhoThuoc &lkt, listKhachHang &lkh, listThuocChuaNhap &ltcn, listNhanVien &lnv, long taiKhoan, string matKhau, int &tongKhachHang){
    cout<<"\nBan da dang nhap voi tu cach nhan vien";
    int lc;
    while(true){
        cout<<"\n----------------------------------------";
        cout<<"\n1.Ban thuoc cho benh nhan";
        cout<<"\n2.Kiem tra danh sach don thuoc";
        cout<<"\n3.Dat mua them thuoc";
        cout<<"\n4.Danh sach thuoc dang ve";
        cout<<"\n5.Nhan thuoc da chuyen den";
        cout<<"\n6.Kiem tra va loai bo thuoc qua han";
        cout<<"\n7.In kho thuoc";
        cout<<"\n8.Ket thuc ca lam viec";
        cout<<"\n--------------------------------------";
        do{
            cout<<"\nNhap lua chon: ";
            cin>>lc;
            if(lc > 8 || lc < 1){
                cout<<"\nNhap lai";
            }
        }while(lc > 8 || lc < 1);
        if(lc == 1){
            themKhachHangCoHoaDon(lkt,lkh,ltcn, tongKhachHang);
        }
        else if(lc == 2){
            print(lkh);
        }
        else if(lc == 3){
            string tenThuoc;
            cout<<"\nTen thuoc: ";
            cin.ignore();
            getline(cin,tenThuoc);
            int soLuong;
            cout<<"\nSo luong thuoc ve: ";
            cin>>soLuong;
            string donVi;
            cout<<"\nDon vi tinh so luong: ";
            cin.ignore();
            getline(cin, donVi);
            long long giaTien;
            cout<<"\nGia tien moi don vi sau khi nhap ve: ";
            cin>>giaTien;
            Date hanSuDung;
            Date ngayVeKho;
            cout<<"\nNhap han su dung (nam): ";cin>>hanSuDung.nam;
            do{
                cout<<"\nNhap han su dung (thang): ";
                cin>>hanSuDung.thang;
                if(hanSuDung.thang < 1 || hanSuDung.thang > 12){
                    cout<<"\nNhap sai";
                }
            }while(hanSuDung.thang < 1 || hanSuDung.thang > 12);
            do{
                cout<<"\nNhap han su dung (ngay): ";
                cin>>hanSuDung.ngay;
                if(hanSuDung.ngay < 1 || hanSuDung.ngay > returnNgay(hanSuDung.thang,hanSuDung.nam)){
                    cout<<"\nNhap sai ngay, thang "<<hanSuDung.thang<<" chi co "<<returnNgay(hanSuDung.thang,hanSuDung.nam)<<" ngay";
                    cout<<"\nMoi nhap lai";
                }
            }while(hanSuDung.ngay < 1 || hanSuDung.ngay > returnNgay(hanSuDung.thang,hanSuDung.nam));
            do{
                cout<<"\nNhap ngay ve kho (nam): ";
                cin>>ngayVeKho.nam;
                if(ngayVeKho.nam >= hanSuDung.nam){
                    cout<<"\nNgay ve kho phai be hon han su dung";
                }
            }while(ngayVeKho.nam >= hanSuDung.nam);
            do{
                cout<<"\nNhap ngay ve kho (thang): ";
                cin>>ngayVeKho.thang;
                if(ngayVeKho.thang < 1 || ngayVeKho.thang > 12){
                    cout<<"\nNhap sai thang";
                }
            }while(ngayVeKho.thang < 1 || ngayVeKho.thang > 12);
            do{
                cout<<"\nNhap ngay ve kho (ngay): ";
                cin>>ngayVeKho.ngay;
                if(ngayVeKho.ngay < 1 || ngayVeKho.ngay > returnNgay(ngayVeKho.thang, ngayVeKho.nam)){
                    cout<<"\nNhap sai ngay, thang "<<ngayVeKho.thang<<" chi co "<<returnNgay(ngayVeKho.thang, ngayVeKho.nam)<<" ngay";
                    cout<<"\nMoi nhap lai";
                }
            }while(ngayVeKho.ngay < 1 || ngayVeKho.ngay > returnNgay(ngayVeKho.thang, ngayVeKho.nam));
            danhSachThuocChuaVeKho(lkt, lkh, ltcn, tenThuoc, soLuong ,hanSuDung, ngayVeKho, donVi, giaTien);
        }
        else if(lc == 4){
            inThuocChuaNhap(ltcn);
        }
        else if(lc == 5){
            chuyenThuocVaoKho(lkt, lkh, ltcn);
        }
        else if(lc == 6){
            kiemTraThuocQuaHan(lkt);
            kiemTraThuocDaHet(lkt);
        }
        else if(lc == 7){
            inKhoThuoc(lkt);
        }
        else{
            cout<<"\nKet thuc ca lam viec";
            return;
        }
    }
}
int main() {
    listKhoThuoc lkt;
    listKhachHang lkh;
    listThuocChuaNhap ltcn;
    listNhanVien lnv;
    listLuong ll;
    init(lkt, lkh, ltcn);
    inits(lnv, ll);
    long taiKhoan;
    string matKhau;
    int tongKhachHang = 0;
    while(true){
        cout<<"\nMoi nhap tai khoan de xac nhan chuc vu";
        cout<<"\nMoi nhap ma nhan vien: ";
        cin>>taiKhoan;
        cout<<"\nNhap mat khau: ";
        cin.ignore();
        getline(cin, matKhau);
        if(taiKhoan == 2151120005 && matKhau == "bgxinh"){
            quanLi(lkt, lkh, ltcn, lnv, ll, taiKhoan, matKhau);
        }
        else{
            nhanVienLamViec(lkt, lkh, ltcn, lnv, taiKhoan, matKhau, tongKhachHang);
        }
    }
    return 0;
}
