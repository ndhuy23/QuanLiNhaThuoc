#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

struct Date {
    int ngay;
    int thang;
    int nam;
};

struct nhanVien {
    long long maNhanVien;
    string matKhau;
    string tenNhanVien;
    Date ngaySinh;
    Date ngayVaoLam;
    string queQuan;
    long luongCoBan;
    int diemDanh;
    int soThangDaLam;
    int soNamDaLam;
    string bangCap;
    nhanVien* next;
    nhanVien* prev;
};
struct luongNhanVien {
    long long maNhanVien;
    string tenNhanVien;
    long luongCoBan;
    int diemDanh;
    int luong;
    Date ngayNhanLuong;
    luongNhanVien* next;
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

struct listNhanVien {
    nhanVien* head;
    nhanVien* tail;
};

struct listLuong {
    luongNhanVien* head;
    luongNhanVien* tail;
};

void init(listKhoThuoc& lkt, listKhachHang& lkh, listThuocChuaNhap& ltcn) {//tao list
    lkt.head = lkt.tail = NULL;
    lkh.head = lkh.tail = NULL;
    ltcn.head = ltcn.tail = NULL;
}

void inits(listNhanVien& lnv, listLuong& ll) {
    lnv.head = lnv.tail = NULL;
    ll.head = ll.tail = NULL;
}
void capNhatNodeTail(listKhoThuoc& lkt) {
    Thuoc* node = lkt.head;
    while (node->next != NULL) {
        node = node->next;
    }
    lkt.tail = node;
}
string chuanHoaTen(string& ten) {//chuan hoa ten so dep
    while (ten[0] == ' ') {
        ten.erase(ten.begin() + 0);
    }
    while (ten[ten.length() - 1] == ' ') {
        ten.erase(ten.begin() + ten.length() - 1);
    }
    for (int i = 0; i <= ten.length(); i++) {
        if (ten[i] == ' ' && ten[i + 1] == ' ') {
            ten.erase(ten.begin() + i);
            i--;
        }
    }
    return ten;
}

string chuanHoaHoaDon(string ma) {//chuan hoa ma don de so sanh thu co don cu k
    string res = "";
    for (int i = 0; i < ma.length(); i++) {
        res += toupper(ma[i]);
    }
    return res;
}

bool kiemTraMaHoaDon(listKhachHang lkh, string ma) {
    DonThuoc* p = lkh.head;
    while (p != NULL) {
        if (p->maDonThuoc == ma) {
            return true;
        }
        p = p->next;
    }
    return false;
}

bool namNhuan(int nam) {
    if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
        return true;
    return false;
}
bool sosanhDate(const Date& d1, const Date& d2)
{
    if (d1.nam < d2.nam)
        return false; // d1(3/11/2021) d2(3/10/2022)
    else if (d1.nam == d2.nam)
    {
        if (d1.thang < d2.thang)
            return false; //d1(3/10/2022) d2(3/11/2022)
        else if (d1.thang == d2.thang)
        {
            if (d1.ngay < d2.ngay)
                return false;
        }
    }
    return true;
}
int returnNgay(int thang, int nam) {
    switch (thang) {
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
        if (namNhuan(nam) == true)
            return 29;
        return 28;
    }
}
bool kiemTraNgayCoBangNhauKhong(Date p, Date q);
bool kiemTraKhoThuoc1(listKhoThuoc& lkt, Thuoc* p) {
    Thuoc* temp = lkt.head;
    while (temp != NULL) {
        if (temp->thuoc.tenThuoc == p->thuoc.tenThuoc && kiemTraNgayCoBangNhauKhong(temp->thuoc.hanSuDung, p->thuoc.hanSuDung) && temp->thuoc.giaTien == p->thuoc.giaTien && temp->thuoc.donVi == p->thuoc.donVi) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool kiemTraKhoThuoc(string ten, listKhoThuoc& lkt) {
    Thuoc* node = lkt.head;
    while (node != NULL) {
        if (ten == node->thuoc.tenThuoc) {
            return true;
        }
        node = node->next;
    }
    return false;
}

bool kiemTraSoLuong(string ten, int soLuong, listKhoThuoc lkt) {
    Thuoc* node = lkt.head;
    while (node != NULL) {
        if (ten == node->thuoc.tenThuoc) {
            if (soLuong <= node->thuoc.soLuong) {
                return true;
            }
        }
        node = node->next;
    }
    return false;
}

bool kiemTraNgayCoBangNhauKhong(Date d1, Date d2) {
    return (d1.ngay == d2.ngay && d1.thang == d2.thang && d1.nam == d2.nam);
}

bool kiemTraMaNhanVien(listNhanVien& lnv, long long maNhanVien) {
    nhanVien* node = lnv.head;
    while (node != NULL) {
        if (node->maNhanVien == maNhanVien) {
            return false;
        }
        node = node->next;
    }
    return true;
}


Thuoc* split(Thuoc* head) {
    Thuoc* fast = head, * slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Thuoc* temp = slow->next;
    slow->next = NULL;
    return temp;
}

Thuoc* merge(Thuoc* first, Thuoc* second)
{
    if (!first)
        return second;

    if (!second)
        return first;

    if (first->thuoc.tenThuoc < second->thuoc.tenThuoc)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
Thuoc* mergeSort(Thuoc* head)
{
    if (!head || !head->next)
        return head;
    Thuoc* second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}
void capNhatSoLuongTrongKho(listKhoThuoc& lkt, string tenThuoc, int soLuong) {
    Thuoc* node = lkt.head;
    while (node != NULL) {
        if (node->thuoc.tenThuoc == tenThuoc) {
            node->thuoc.soLuong = node->thuoc.soLuong - soLuong;
        }
        node = node->next;
    }
}

nhanVien* createNhanVien(long long maNhanVien, string tenNhanVien, Date ngaySinh, string queQuan, string bangCap, long luongCoBan, int diemDanh, int soThangDaLam, int soNamDaLam, Date ngayVaoLam, string matKhau) {
    nhanVien* node = new nhanVien;
    node->maNhanVien = maNhanVien;
    node->tenNhanVien = tenNhanVien;
    node->ngaySinh.ngay = ngaySinh.ngay;
    node->ngaySinh.thang = ngaySinh.thang;
    node->ngaySinh.nam = ngaySinh.nam;
    node->queQuan = queQuan;
    node->bangCap = bangCap;
    node->ngayVaoLam.ngay = ngayVaoLam.ngay;
    node->ngayVaoLam.thang = ngayVaoLam.thang;
    node->ngayVaoLam.nam = ngayVaoLam.nam;
    node->luongCoBan = luongCoBan;
    node->diemDanh = diemDanh;
    node->soThangDaLam = soThangDaLam;
    node->soNamDaLam = soNamDaLam;
    node->matKhau = matKhau;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void themNhanVien(listNhanVien& lnv) {
    long long maNhanVien;
    string tenNhanVien;
    Date ngaySinh;
    Date ngayVaoLam;
    string queQuan;
    string bangCap;
    long luongCoBan;
    int diemDanh;
    int soThangDaLam;
    int soNamDaLam;
    do {
        cout << "\nNhap ma nhan vien: ";
        cin >> maNhanVien;
        if (!kiemTraMaNhanVien(lnv, maNhanVien)) {
            cout << "\nMa nhan vien da ton tai, moi nhap lai";
        }
    } while (!kiemTraMaNhanVien(lnv, maNhanVien));
    cout << "\nNhap ten nhan vien: ";
    cin.ignore();
    getline(cin, tenNhanVien);
    tenNhanVien = chuanHoaTen(tenNhanVien);
    cout << "\nNhap ngay thang nam sinh";
    cout << "\nNhap nam sinh: ";
    do {
        cin >> ngaySinh.nam;
        if (ngaySinh.nam < 1950 || ngaySinh.nam > 2000) {
            cout << "\nNam sinh khong hop le";
        }
    } while (ngaySinh.nam < 1950 || ngaySinh.nam > 2000);
    cout << "\nNhap thang sinh: ";
    do {
        cin >> ngaySinh.thang;
        if (ngaySinh.thang < 1 || ngaySinh.thang > 12) {
            cout << "\nThang khong hop le";
        }
    } while (ngaySinh.thang < 1 || ngaySinh.thang > 12);
    cout << "\nNhap ngay sinh: ";
    do {
        cin >> ngaySinh.ngay;
        if (ngaySinh.ngay < 1 || ngaySinh.ngay > returnNgay(ngaySinh.thang, ngaySinh.nam)) {
            cout << "\nThang " << ngaySinh.thang << " chi co " << returnNgay(ngaySinh.thang, ngaySinh.nam) << " ngay";
            cout << "\nMoi nhap lai: ";
        }
    } while (ngaySinh.ngay < 1 || ngaySinh.ngay > returnNgay(ngaySinh.thang, ngaySinh.nam));
    cout << "\nNhap que quan: ";
    cin.ignore();
    getline(cin, queQuan);
    cout << "\nNhap luong co ban: ";
    do {
        cin >> luongCoBan;
        if (luongCoBan < 0) {
            cout << "\nNhap lai";
        }
    } while (luongCoBan < 0);
    cout << "\nNhap bang cap: ";
    cin.ignore();
    getline(cin, bangCap);
    diemDanh = 0;
    soThangDaLam = 0;
    soNamDaLam = 0;
    cout << "\nNhap ngay vao lam";
    cout << "\nNhap nam: ";
    do {
        cin >> ngayVaoLam.nam;
        if (ngayVaoLam.nam > 2022) {
            cout << "\nNam khong hop le";
        }
    } while (ngayVaoLam.nam > 2022);
    cout << "\nNhap thang: ";
    do {
        cin >> ngayVaoLam.thang;
        if (ngayVaoLam.thang < 1 || ngayVaoLam.thang > 12) {
            cout << "\nThang khong hop le";
        }
    } while (ngayVaoLam.thang < 1 || ngayVaoLam.thang > 12);
    cout << "\nNhap ngay: ";
    do {
        cin >> ngayVaoLam.ngay;
        if (ngayVaoLam.ngay < 1 || ngayVaoLam.ngay > returnNgay(ngayVaoLam.thang, ngayVaoLam.nam)) {
            cout << "\nThang " << ngayVaoLam.thang << " chi co " << returnNgay(ngayVaoLam.thang, ngayVaoLam.nam) << " ngay";
            cout << "\nMoi nhap lai: ";
        }
    } while (ngayVaoLam.ngay < 1 || ngayVaoLam.ngay > returnNgay(ngayVaoLam.thang, ngayVaoLam.nam));
    cout << "\nCap pass dang nhap cho nhan vien: ";
    string matKhau;
    cin.ignore();
    getline(cin, matKhau);
    nhanVien* node = createNhanVien(maNhanVien, tenNhanVien, ngaySinh, queQuan, bangCap, luongCoBan, diemDanh, soThangDaLam, soNamDaLam, ngayVaoLam, matKhau);
    if (lnv.head == NULL) {
        lnv.head = lnv.tail = node;
    }
    else {
        lnv.tail->next = node;
        node->prev = lnv.tail;
        lnv.tail = node;
    }
    cout << "\nDa them nhan vien" << endl;
    system("pause");
}

void searchNhanVien(listNhanVien lnv,long long maNV) {
    for (nhanVien* node = lnv.head; node != NULL; node = node->next) {
        if (node->maNhanVien == maNV) {
            cout << "\nMa nhan vien: " << node->maNhanVien;
            cout << "\nTen nhan vien: " << node->tenNhanVien;
            cout << "\nNgay thang nam sinh: " << node->ngaySinh.ngay << "/" << node->ngaySinh.thang << "/" << node->ngaySinh.nam;
            cout << "\nQue quan: " << node->queQuan;
            cout << "\nNgay vao lam: " << node->ngayVaoLam.ngay << "/" << node->ngayVaoLam.thang << "/" << node->ngayVaoLam.nam;
            cout << "\nLuong co ban: " << node->luongCoBan;
            cout << "\nBang cap: " << node->bangCap;
            cout << "\nSo ngay da diem danh trong thang qua: " << node->diemDanh;
            cout << "\nSo thang da lam trong nam qua: " << node->soThangDaLam;
            cout << "\nSo nam da lam: " << node->soNamDaLam;
            cout << "\n------------------------------------------" << endl;
            system("pause");
            return;
        }
    }
    cout << "Khong co nhan vien ban muon tim !!!" << endl;
    system("pause");
}

void thayDoiThongTinNhanVien(listNhanVien& lnv) {
    if (lnv.head == NULL) {
        cout << "\nDanh sach nhan vien hien dang trong" << endl;
        system("pause");
        return;
    }
    else {
        cout << "\nNhap ma nhan vien can thay doi thong tin: ";
        long long maNhanVien;
        do {
            cin >> maNhanVien;
            if (kiemTraMaNhanVien(lnv, maNhanVien)) {
                cout << "\nHien khong co ma nhan vien nay, vui long nhap lai: ";
            }
        } while (kiemTraMaNhanVien(lnv, maNhanVien));
        nhanVien* node = lnv.head;
        while (node->maNhanVien != maNhanVien) {
            node = node->next;
        }
        while (true) {
            system("cls");
            cout << "\n=========Thong tin co the thay doi=============";
            cout << "\n1.Ten nhan vien";
            cout << "\n2.Luong co ban";
            cout << "\n3.Bang cap";
            cout << "\n4.Hoan tat thay doi";
            int luaChon;
            cout << "\nNhap lua chon: ";
            do {
                cin >> luaChon;
                if (luaChon < 1 || luaChon > 4) {
                    cout << "\nNhap sai";
                }
            } while (luaChon < 1 || luaChon > 4);
            if (luaChon == 1) {
                string tenNhanVien;
                cout << "\nNhap ten moi cua nhan vien: ";
                cin.ignore();
                getline(cin, tenNhanVien);
                node->tenNhanVien = chuanHoaTen(tenNhanVien);
            }
            else if (luaChon == 2) {
                cout << "\nNhap luong thay the: ";
                int luongCoBan;
                do {
                    cin >> luongCoBan;
                    if (luongCoBan < 0) {
                        cout << "\nNhap sai";
                    }
                } while (luongCoBan < 0);
                node->luongCoBan = luongCoBan;
            }
            else if (luaChon == 3) {
                cout << "\nNhap bang cap moi: ";
                string bangCap;
                cin.ignore();
                getline(cin, bangCap);
                node->bangCap = bangCap;
            }
            else {
                cout << "\nDa cap nhat hoan tat thong tin cua " << node->maNhanVien << endl;
                system("pause");
                return;
            }
        }
    }
    cout << "\nDa thay doi" << endl;
    system("pause");
    return;
}

luongNhanVien* createBangLuong(long long maNhanVien, string tenNhanVien, long luongCoBan, int diemDanh, Date ngayNhanLuong) {
    luongNhanVien* node = new luongNhanVien;
    node->maNhanVien = maNhanVien;
    node->tenNhanVien = tenNhanVien;
    node->luongCoBan = luongCoBan;
    node->diemDanh = diemDanh;
    node->ngayNhanLuong = ngayNhanLuong;
    node->luong = luongCoBan * diemDanh;
    node->next = NULL;
    return node;
}

void traLuongNhanVien(listNhanVien& lnv, listLuong& ll) {
    if (lnv.head == NULL) {
        cout << "\nHien chua co nhan vien de tra luong" << endl;
        system("pause");
        return;
    }
    Date ngayNhanLuong;
    cout << "\nNhap ngay tinh luong";
    cout << "\nNhap nam: ";
    cin >> ngayNhanLuong.nam;
    cout << "\nNhap thang: ";
    do {
        cin >> ngayNhanLuong.thang;
        if (ngayNhanLuong.thang < 1 || ngayNhanLuong.thang > 12) {
            cout << "\nNhap sai";
        }
    } while (ngayNhanLuong.thang < 1 || ngayNhanLuong.thang > 12);
    cout << "\nNhap ngay: ";
    do {
        cin >> ngayNhanLuong.ngay;
        if (ngayNhanLuong.ngay < 1 || ngayNhanLuong.ngay > returnNgay(ngayNhanLuong.thang, ngayNhanLuong.nam)) {
            cout << "\nThang " << ngayNhanLuong.thang << " chi co toi da " << returnNgay(ngayNhanLuong.thang, ngayNhanLuong.nam) << " ngay";
        }
    } while (ngayNhanLuong.ngay < 1 || ngayNhanLuong.ngay > returnNgay(ngayNhanLuong.thang, ngayNhanLuong.nam));
    nhanVien* node = lnv.head;
    while (node != NULL) {
        luongNhanVien* node1 = createBangLuong(node->maNhanVien, node->tenNhanVien, node->luongCoBan, node->diemDanh, ngayNhanLuong);
        node->diemDanh = 0;
        node->soThangDaLam += 1;
        if (ngayNhanLuong.thang == 12) {
            node->soNamDaLam += 1;
        }
        if (ll.head == NULL) {
            ll.head = ll.tail = node1;
        }
        else {
            ll.tail->next = node1;
            ll.tail = node1;
        }
        node = node->next;
    }
    cout << "\nDa tra luong nhan vien thang " << ngayNhanLuong.thang << endl;
    system("pause");
}

void kiemTraBangLuong(listLuong& ll, long long taiKhoan, string matKhau) {
    if (ll.head == NULL) {
        cout << "\nBang luong hien con trong" << endl;
        system("pause");
        return;
    }
    else if (taiKhoan == 2151120005 && matKhau == "bgxinh") {
        cout << "\nBan muon kiem tra mot nhan vien hay toan bo nhan vien";
        cout << "\n1. Mot nhan vien";
        cout << "\n2. Toan bo nhan vien";
        int luaChon;
        cout << "\nNhap lua chon :";
        do {
            cin >> luaChon;
            if (luaChon < 1 || luaChon > 2) {
                cout << "\nNhap sai";
            }
        } while (luaChon < 1 || luaChon > 2);
        if (luaChon == 1) {
            long long maNhanVien;
            cout << "\nNhap ma nhan vien: ";
            cin >> maNhanVien;
            luongNhanVien* node = ll.head;
            while (node != NULL) {
                if (node->maNhanVien == maNhanVien) {
                    cout << "\nThong tin bang luong";
                    cout << "\nMa nhan vien: " << node->maNhanVien;
                    cout << "\nTen nhan vien: " << node->tenNhanVien;
                    cout << "\nLuong thang " << node->ngayNhanLuong.thang << " :" << node->luong << endl;
                }
                node = node->next;
            }
        }
        else {
            luongNhanVien* node = ll.head;
            while (node != NULL) {
                cout << "\nThong tin bang luong";
                cout << "\nMa nhan vien: " << node->maNhanVien;
                cout << "\nTen nhan vien: " << node->tenNhanVien;
                cout << "\nLuong: " << node->ngayNhanLuong.thang << " :" << node->luong << endl;
                node = node->next;
            }
        }
    }
    else {
        luongNhanVien* node = ll.head;
        while (node != NULL) {
            if (node->maNhanVien == taiKhoan) {
                cout << "\nThong tin bang luong";
                cout << "\nMa nhan vien: " << node->maNhanVien;
                cout << "\nTen nhan vien: " << node->tenNhanVien;
                cout << "\nLuong: thang " << node->ngayNhanLuong.thang << " :" << node->luong << endl;
            }
            node = node->next;
        }
    }
    system("pause");
}

void inDanhSachNhanVien(listNhanVien& lnv) {
    if (lnv.head == NULL) {
        cout << "\nHien khong co nhan vien" << endl;
        system("pause");
        return;
    }
    else {
        cout << "\n==========Thong tin nhan vien=============";
        nhanVien* node = lnv.head;
        while (node != NULL) {
            cout << "\nMa nhan vien: " << node->maNhanVien;
            cout << "\nTen nhan vien: " << node->tenNhanVien;
            cout << "\nNgay thang nam sinh: " << node->ngaySinh.ngay << "/" << node->ngaySinh.thang << "/" << node->ngaySinh.nam;
            cout << "\nQue quan: " << node->queQuan;
            cout << "\nNgay vao lam: " << node->ngayVaoLam.ngay << "/" << node->ngayVaoLam.thang << "/" << node->ngayVaoLam.nam;
            cout << "\nLuong co ban: " << node->luongCoBan;
            cout << "\nBang cap: " << node->bangCap;
            cout << "\nSo ngay da diem danh trong thang qua: " << node->diemDanh;
            cout << "\nSo thang da lam trong nam qua: " << node->soThangDaLam;
            cout << "\nSo nam da lam: " << node->soNamDaLam;
            cout << "\n------------------------------------------" << endl;
            node = node->next;
        }
    }
    system("pause");
}
nhanVien* splitNV(nhanVien* head) {
    nhanVien* fast = head, * slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    nhanVien* temp = slow->next;
    slow->next = NULL;
    return temp;
}

nhanVien* mergeNV(nhanVien* first, nhanVien* second)
{
    // If first linked list is empty 
    if (!first)
        return second;

    // If second linked list is empty 
    if (!second)
        return first;

    // Pick the smaller value 
    if (first->maNhanVien < second->maNhanVien)
    {
        first->next = mergeNV(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = mergeNV(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
nhanVien* mergeSortNV(nhanVien* head)
{
    if (!head || !head->next)
        return head;
    nhanVien* second = splitNV(head);

    // Recur for left and right halves 
    head = mergeSortNV(head);
    second = mergeSortNV(second);

    // Merge the two sorted halves 
    return mergeNV(head, second);
}
void capNhatNodeTailNV(listNhanVien &lnv) {
    nhanVien* node = lnv.head;
    while (node->next != NULL) {
        node = node->next;
    }
    lnv.tail = node;
}

void xoaNhanVien(listNhanVien& lnv) {
    if (lnv.head == NULL) {
        cout << "\nDanh sach nhan vien hien dang trong" << endl;
        system("pause");
        return;
    }
    cout << "\nNhap ma nhan vien can xoa: ";
    long long maNhanVien;
    cin >> maNhanVien;
    nhanVien* node = lnv.head;
    for (node; node != NULL; node = node->next) {
        if (node->maNhanVien == maNhanVien) {
            cout << "\nBan co chac muon xoa nhan vien khong";
            cout << "\n1. Co";
            cout << "\n2. Khong" << endl;
            int luaChon;
            cin >> luaChon;
            if (luaChon == 1) {
                if (node == lnv.head && node == lnv.tail) {
                    lnv.head = lnv.tail = NULL;
                }
                else if (node == lnv.head) {
                    lnv.head = node->next;
                    lnv.head->prev = NULL;
                    node->next = NULL;
                    delete node;
                }
                else {
                    if (node != lnv.tail) {
                        node->next->prev = node->prev;
                        node->prev->next = node->next;
                        delete node;
                    }
                    else {
                        lnv.tail = node->prev;
                        lnv.tail->next = NULL;
                        node->prev = NULL;
                        delete node;
                    }
                }
                cout << "\nDa xoa nhan vien" << endl;
                system("pause");
                return;
            }
            else {
                cout << "\nDa huy thao tac xoa" << endl;
                system("pause");
                return;
            }
        }
    }
    cout << "\nKhong tim thay ma nhan vien" << endl;
    system("pause");
    return;

}

DonThuoc* makeNode(listKhoThuoc& lkt, int tongKhachHang, string maHoaDon, string tenKhachHang, string bieuHien, int n, string tenThuoc[], int soLuong[]) {
    DonThuoc* node = new DonThuoc();
    node->maDonThuoc = maHoaDon;
    node->khachHang.ten = tenKhachHang;
    node->khachHang.bieuHien = bieuHien;
    node->soLoaiThuoc = n;
    node->tongTien = 0;
    for (int i = 0; i < n; i++) {
        node->thuoc[i].tenThuoc = tenThuoc[i];
        node->thuoc[i].soLuong = soLuong[i];
        Thuoc* temp = lkt.head;
        while (temp->thuoc.tenThuoc != tenThuoc[i]) {
            temp = temp->next;
        }
        temp->thuoc.soLuong = temp->thuoc.soLuong - soLuong[i];
        node->thuoc[i].donVi = temp->thuoc.donVi;
        node->thuoc[i].giaTien = temp->thuoc.giaTien;
        node->thuoc[i].hanSuDung.ngay = temp->thuoc.hanSuDung.ngay;
        node->thuoc[i].hanSuDung.thang = temp->thuoc.hanSuDung.thang;
        node->thuoc[i].hanSuDung.nam = temp->thuoc.hanSuDung.nam;
        node->thuoc[i].ngayVeKho.ngay = temp->thuoc.ngayVeKho.ngay;
        node->thuoc[i].ngayVeKho.thang = temp->thuoc.ngayVeKho.thang;
        node->thuoc[i].ngayVeKho.nam = temp->thuoc.ngayVeKho.nam;
        node->tongTien = node->tongTien + node->thuoc[i].giaTien * node->thuoc[i].soLuong;
    }
    Date ngayMuaHang;
    time_t now = time(0);
    tm* t = localtime(&now);
    node->khachHang.ngayMuaHang.ngay = t->tm_mday;
    node->khachHang.ngayMuaHang.thang = t->tm_mon + 1;
    node->khachHang.ngayMuaHang.nam = 1900 + t->tm_year;
    return node;
}


void themKhachHangKhongCoHoaDon(listKhoThuoc& lkt, listKhachHang& lkh, listThuocChuaNhap& ltcn, int& tongKhachHang) {
    string maHoaDon, tenKhachHang, bieuHien;
    tongKhachHang += 1;
    cout << "\nMa don thuoc: " << "DT" + to_string(tongKhachHang);
    maHoaDon = "DT" + to_string(tongKhachHang);
    cout << "\nNhap ten khach hang: ";
    cin.ignore();
    getline(cin, tenKhachHang);
    cout << "\nNhap bieu hien: ";
    getline(cin, bieuHien);
    int n;
    cout << "\nSo loai thuoc can ban: ";
    cin >> n;
    string tenThuoc[5];
    int soLuong[5];
    for (int i = 0; i < n; i++) {
        string ten;
        cout << "\nNhap ten thuoc: ";
        cin.ignore();
        getline(cin, ten);
        if (kiemTraKhoThuoc(ten, lkt) == true) {
            Thuoc* node = lkt.head;
            while (node->thuoc.tenThuoc != ten) {
                node = node->next;
            }
            cout << "\nNhap so luong " << node->thuoc.donVi << " " << node->thuoc.tenThuoc << " can ban: ";
            int sl;
            cin >> sl;
            if (kiemTraSoLuong(ten, sl, lkt) == true) {
                tenThuoc[i] = ten;
                soLuong[i] = sl;
            }
            else {
                cout << "\nSo luong " << node->thuoc.tenThuoc << " hien tai khong du";
                cout << "\nCo can thay doi loai thuoc khac khong hay bo qua thuoc hien tai (thay the nhap 1, bo qua nhap 0) ";
                int luaChon;
                cin >> luaChon;
                if (luaChon == 1) {
                    cout << "\nMoi nhap lai ten thuoc thay the";
                    i--;
                }
                else {
                    i--;
                    n--;
                    if (n == 0) {
                        cout << "\nHien nha thuoc da het tat ca thuoc ban can, vui long quay lai sau, cam on da dung dich vu" << endl;
                        tongKhachHang = tongKhachHang - 1;
                        system("pause");
                        return;
                    }
                }
            }
        }
        else {
            cout << "\nHien trong kho khong co " << ten;
            int luaChon;
            cout << "\nCo can thay doi loai thuoc khac khong hay bo qua thuoc hien tai (thay the nhap 1, bo qua nhap 0) ";
            cin >> luaChon;
            if (luaChon == 1) {
                cout << "\nMoi nhap loai thuoc thay the";
                i--;
            }
            else {
                i--;
                n = n - 1;
                if (n == 0) {
                    cout << "\nHien nha thuoc da het tat ca thuoc ban can, vui long quay lai sau, cam on da dung dich vu" << endl;
                    tongKhachHang = tongKhachHang - 1;
                    system("pause");
                    return;
                }
            }
        }
    }
    DonThuoc* node = makeNode(lkt, tongKhachHang, maHoaDon, tenKhachHang, bieuHien, n, tenThuoc, soLuong);
    if (lkh.head == NULL) {
        lkh.head = lkh.tail = node;
    }
    else {
        lkh.tail->next = node;
        node->prev = lkh.tail;
        lkh.tail = node;
    }
    cout << "\nCam on da su dung dich vu" << endl;
    system("pause");
}

DonThuoc* capNhatHoaDonMoi(listKhoThuoc& lkt, DonThuoc* p, int tongKhachHang, Date ngayMuaHang) {
    DonThuoc* node = new DonThuoc();
    node->maDonThuoc = "DT" + to_string(tongKhachHang);
    node->soLoaiThuoc = p->soLoaiThuoc;
    node->khachHang.ten = p->khachHang.ten;
    node->khachHang.bieuHien = p->khachHang.bieuHien;
    node->khachHang.ngayMuaHang.ngay = ngayMuaHang.ngay;
    node->khachHang.ngayMuaHang.thang = ngayMuaHang.thang;
    node->khachHang.ngayMuaHang.nam = ngayMuaHang.nam;
    for (int i = 0; i < p->soLoaiThuoc; i++) {
        node->thuoc[i].tenThuoc = p->thuoc[i].tenThuoc;
        node->thuoc[i].soLuong = p->thuoc[i].soLuong;
        node->thuoc[i].hanSuDung.ngay = p->thuoc[i].hanSuDung.ngay;
        node->thuoc[i].hanSuDung.thang = p->thuoc[i].hanSuDung.thang;
        node->thuoc[i].hanSuDung.nam = p->thuoc[i].hanSuDung.nam;
        node->thuoc[i].ngayVeKho.ngay = p->thuoc[i].ngayVeKho.ngay;
        node->thuoc[i].ngayVeKho.thang = p->thuoc[i].ngayVeKho.thang;
        node->thuoc[i].ngayVeKho.nam = p->thuoc[i].ngayVeKho.nam;
        node->thuoc[i].donVi = p->thuoc[i].donVi;
        capNhatSoLuongTrongKho(lkt, node->thuoc[i].tenThuoc, node->thuoc[i].soLuong);
    }
    node->tongTien = p->tongTien;
    return node;
}

void themKhachHangCoHoaDon(listKhoThuoc& lkt, listKhachHang& lkh, listThuocChuaNhap& ltcn, int& tongKhachHang) {
    int luaChon;
    cout << "\nKhach co mua lai theo hoa don cu khong (co nhap 1, khong nhap 0): "; cin >> luaChon;
    if (luaChon == 1) {
        string maDonThuoc;
        cout << "\nNhap ma hoa don cu: ";
        cin.ignore();
        getline(cin, maDonThuoc);
        maDonThuoc = chuanHoaHoaDon(maDonThuoc);
        DonThuoc* p = lkh.head;
        while (p != NULL) {
            if (p->maDonThuoc == maDonThuoc) {
                cout << "\nDa tim thay don thuoc, cua hang se lay hoa don moi cho quy khach ";
                cout << "\nMa don thuoc moi la: " << "DT" + to_string(tongKhachHang);
                Date ngayMuaHang;
                time_t now = time(0);
                tm* t = localtime(&now);
                ngayMuaHang.ngay = t->tm_mday;
                ngayMuaHang.thang = t->tm_mon + 1;
                ngayMuaHang.nam = 1900 + t->tm_year;
                for (int i = 0; i < p->soLoaiThuoc; i++) {
                    if (kiemTraKhoThuoc(p->thuoc[i].tenThuoc, lkt) == true) {
                        if (kiemTraSoLuong(p->thuoc[i].tenThuoc, p->thuoc[i].soLuong, lkt) == true) {
                            cout << "\nVui long cho chung toi kiem tra kho thuoc";
                        }
                        else {
                            cout << "\nHien so luong con lai trong kho khong du, xin quay lai sau" << endl;
                            system("pause");
                            return;
                        }
                    }
                    else {
                        cout << "\nHien nha thuoc da het " << p->thuoc[i].tenThuoc << " nhu yeu cau cua don thuoc cu";
                        cout << "\nVui long quay lai sau, chung toi xin loi vi su bat tien nay" << endl;
                        system("pause");
                        return;
                    }
                }
                tongKhachHang += 1;
                DonThuoc* newNode = capNhatHoaDonMoi(lkt, p, tongKhachHang, ngayMuaHang);
                lkh.tail->next = newNode;
                newNode->prev = lkh.tail;
                lkh.tail = newNode;
                cout << "\nDa cap nhat xong, cam on da dung dich vu!" << endl;
                system("pause");
                return;
            }
            p = p->next;
        }
        cout << "\nMa don thuoc khong dung, vui long kiem tra lai hoa don!" << endl;
        system("pause");
        return;
    }
    else {
        themKhachHangKhongCoHoaDon(lkt, lkh, ltcn, tongKhachHang);
    }
}

Thuoc* createNode(string tenThuoc, int soLuong, Date hanSuDung, Date ngayVeKho, string donVi, long long giaTien) {
    Thuoc* node = new Thuoc();
    node->thuoc.tenThuoc = tenThuoc;
    node->thuoc.soLuong = soLuong;
    node->thuoc.hanSuDung.ngay = hanSuDung.ngay;
    node->thuoc.hanSuDung.thang = hanSuDung.thang;
    node->thuoc.hanSuDung.nam = hanSuDung.nam;
    node->thuoc.ngayVeKho.ngay = ngayVeKho.ngay;
    node->thuoc.ngayVeKho.thang = ngayVeKho.thang;
    node->thuoc.ngayVeKho.nam = ngayVeKho.nam;
    node->thuoc.donVi = donVi;
    node->thuoc.giaTien = giaTien;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void danhSachThuocChuaVeKho(listKhoThuoc& lkt, listKhachHang& lkh, listThuocChuaNhap& ltcn, string tenThuoc, int soLuong, Date hanSuDung, Date ngayVeKho, string donVi, long long giaTien) {
    Thuoc* node = createNode(tenThuoc, soLuong, hanSuDung, ngayVeKho, donVi, giaTien);
    if (ltcn.head == NULL) {
        ltcn.head = ltcn.tail = node;
    }
    else {
        ltcn.tail->next = node;
        node->prev = ltcn.tail;
        ltcn.tail = node;
    }
}

void themVaoKhoThuoc(listKhoThuoc& lkt, string tenThuoc, int soLuong, Date hanSuDung, Date ngayVeKho, string donVi, long long giaTien) {
    Thuoc* node = createNode(tenThuoc, soLuong, hanSuDung, ngayVeKho, donVi, giaTien);
    if (lkt.head == NULL) {
        lkt.head = lkt.tail = node;
    }
    else {
        lkt.tail->next = node;
        node->prev = lkt.tail;
        lkt.tail = node;
    }
}

void chuyenThuocVaoKho(listKhoThuoc& lkt, listKhachHang& lkh, listThuocChuaNhap& ltcn) {
    Date d;
    time_t now = time(0);
    tm* t = localtime(&now);
    d.ngay = t->tm_mday;
    d.thang = t->tm_mon + 1;
    d.nam = 1900 + t->tm_year;
    Thuoc* node = ltcn.head;
    int dem = 0;
    while (node != NULL) {
        if (sosanhDate(d, node->thuoc.ngayVeKho)) {
            if (kiemTraKhoThuoc1(lkt,node)) {
                for (Thuoc* k = lkt.head; k != NULL; k = k->next) {
                    if (k->thuoc.tenThuoc == node->thuoc.tenThuoc && kiemTraNgayCoBangNhauKhong(k->thuoc.hanSuDung,node->thuoc.hanSuDung)&&k->thuoc.giaTien == node->thuoc.giaTien&&k->thuoc.donVi == node->thuoc.donVi) {
                        k->thuoc.soLuong += node->thuoc.soLuong;
                        cout << "Da chuyen " << node->thuoc.tenThuoc << " vao kho" << endl;
                        if (node == ltcn.head && node == ltcn.tail) {
                            ltcn.head = ltcn.tail = NULL;
                        }
                        else if (node == ltcn.head) {
                            Thuoc* p = node;
                            ltcn.head = p->next;
                            node = p->next;
                            delete(p);
                            continue;
                        }
                        else {
                            if (node != ltcn.tail) {
                                Thuoc* p = node;
                                node = p->next;
                                p->prev->next = node;
                                node->prev = p->prev;
                                delete(p);
                                continue;
                            }
                            else {
                                Thuoc* p = node;
                                node = p->prev;
                                ltcn.tail = node;
                                node->next = NULL;
                                delete(p);
                                continue;
                            }
                        }
                    }
                    
                }
            }
            else if (node == ltcn.head) {
                Thuoc* p = node;
                cout << "\nDa chuyen " << node->thuoc.tenThuoc << " vao kho" << endl;
                ltcn.head = p->next;
                node = p->next;
                themVaoKhoThuoc(lkt, p->thuoc.tenThuoc, p->thuoc.soLuong, p->thuoc.hanSuDung, p->thuoc.ngayVeKho, p->thuoc.donVi, p->thuoc.giaTien);
                delete(p);
                continue;
            }
            else {
                if (node != ltcn.tail) {
                    Thuoc* p = node;
                    cout << "\nDa chuyen" << node->thuoc.tenThuoc << " vao kho" << endl;
                    node = p->next;
                    p->prev->next = node;
                    node->prev = p->prev;
                    themVaoKhoThuoc(lkt, p->thuoc.tenThuoc, p->thuoc.soLuong, p->thuoc.hanSuDung, p->thuoc.ngayVeKho, p->thuoc.donVi, p->thuoc.giaTien);
                    delete(p);
                    continue;
                }
                else {
                    Thuoc* p = node;
                    cout << "\nDa chuyen " << node->thuoc.tenThuoc << " vao kho" << endl;
                    node = p->prev;
                    ltcn.tail = node;
                    node->next = NULL;
                    themVaoKhoThuoc(lkt, p->thuoc.tenThuoc, p->thuoc.soLuong, p->thuoc.hanSuDung, p->thuoc.ngayVeKho, p->thuoc.donVi, p->thuoc.giaTien);
                    delete(p);
                    continue;
                }
            }
        }
        node = node->next;
    }
    cout << "\nDa chuyen het cac loai thuoc moi ve vao kho" << endl;
    system("pause");
}

void kiemTraThuocQuaHan(listKhoThuoc& lkt) {
    Date d;
    time_t now = time(0);
    tm* t = localtime(&now);
    d.ngay = t->tm_mday;
    d.thang = t->tm_mon + 1;
    d.nam = 1900 + t->tm_year;
    Thuoc* node = lkt.head;
    while (node != NULL) {
        if (sosanhDate(d,node->thuoc.hanSuDung)) {
            if (node == lkt.head) {
                Thuoc* p = node;
                cout << "\nDa loai bo " << node->thuoc.tenThuoc << " ra khoi kho";
                node = p->next;
                lkt.head = node;
                delete(p);
                continue;
            }
            else {
                if (node != lkt.tail) {
                    Thuoc* p = node;
                    cout << "\nDa loai bo " << node->thuoc.tenThuoc << " ra khoi kho";
                    node = p->next;
                    p->prev->next = node;
                    node->prev = p->prev;
                    delete(p);
                    continue;
                }
                else {
                    Thuoc* p = node;
                    cout << "\nDa loai bo " << node->thuoc.tenThuoc << " ra khoi kho";
                    node = p->prev;
                    lkt.tail = node;
                    node->next = NULL;
                    delete(p);
                    continue;
                }
            }
        }
        node = node->next;
    }
    cout << "\nDa loai bo tat ca thuoc het han" << endl;
    system("pause");
}

void kiemTraThuocDaHet(listKhoThuoc& lkt) {
    Thuoc* node = lkt.head;
    while (node != NULL) {
        if (node->thuoc.soLuong == 0) {
            if (node == lkt.head) {
                Thuoc* p = node;
                node = p->next;
                lkt.head = node;
                delete(p);
                continue;
            }
            else {
                if (node != lkt.tail) {
                    Thuoc* p = node;
                    node = p->next;
                    node->prev = p->prev;
                    p->prev->next = node;
                    delete(p);
                    continue;
                }
                else {
                    Thuoc* p = node;
                    node = p->prev;
                    lkt.tail = node;
                    node->next = NULL;
                    delete(p);
                    continue;
                }
            }
        }
        node = node->next;
    }
}

void print(listKhachHang lkh) {//nay de kiem tra thong tin thu dung k, cu de do k can xoa
    if (lkh.head == NULL) {
        cout << "\nHien chua co danh sach khach hang" << endl;
    }
    else {
        DonThuoc* p = lkh.head;
        while (p != NULL) {
            cout << "\nMa don thuoc: " << p->maDonThuoc;
            cout << "\nTen khach hang: " << p->khachHang.ten;
            cout << "\nBieu hien: " << p->khachHang.bieuHien;
            cout << "\nNgay mua Hang: " << p->khachHang.ngayMuaHang.ngay << "/" << p->khachHang.ngayMuaHang.thang << "/" << p->khachHang.ngayMuaHang.nam;
            for (int i = 0; i < p->soLoaiThuoc; i++) {
                cout << "\n" << left << setw(10) << "Ten loai thuoc: " << left << setw(10) << p->thuoc[i].tenThuoc << endl;
                cout << "So luong: " << p->thuoc[i].soLuong << endl;
                cout << "Han su dung: " << p->thuoc[i].hanSuDung.ngay << "/" << p->thuoc[i].hanSuDung.thang << "/" << p->thuoc[i].hanSuDung.nam << endl;
            }
            cout << "Thanh tien: " << p->tongTien << endl;
            cout << "===========================================" << endl;
            p = p->next;
        }
    }
    system("pause");
}

void inThuocChuaNhap(listThuocChuaNhap ltcn) {
    if (ltcn.head == NULL) {
        cout << "\nHien chua co thuoc dang nhap";
    }
    else {
        Thuoc* node = ltcn.head;
        while (node != NULL) {
            cout << "\nTen thuoc:" << node->thuoc.tenThuoc;
            cout << "\nSo luong: " << node->thuoc.soLuong;
            cout << "\nHan su dung: " << node->thuoc.hanSuDung.ngay << "/" << node->thuoc.hanSuDung.thang << "/" << node->thuoc.hanSuDung.nam;
            cout << "\nNgay ve kho: " << node->thuoc.ngayVeKho.ngay << "/" << node->thuoc.ngayVeKho.thang << "/" << node->thuoc.ngayVeKho.nam;
            node = node->next;
        }    
    }
    cout << endl;
    system("pause");
}
void searchThuoc(listKhoThuoc lkt, string name) {
    int dem = 0;
    for (Thuoc* p = lkt.head; p != NULL; p = p->next) {
        if (p->thuoc.tenThuoc == name) {
            cout << "\nTen thuoc:" << p->thuoc.tenThuoc;
            cout << "\nSo luong: " << p->thuoc.soLuong;
            cout << "\nHan su dung: " << p->thuoc.hanSuDung.ngay << "/" << p->thuoc.hanSuDung.thang << "/" << p->thuoc.hanSuDung.nam;
            cout << "\nGia tien: " << p->thuoc.giaTien << "/" << p->thuoc.donVi << endl;
            cout << "------------------------------------------------------" << endl;
            dem++;
        }
    }
    if (dem != 0) {
        cout << "Khong co thuoc ban can tim !!!" << endl;
    }
}
void inKhoThuoc(listKhoThuoc lkt) {
    if (lkt.head == NULL) {
        cout << "\nHien kho da het thuoc";
    }
    else {
        cout << "\n------Duoi day la tat ca thuoc hien co trong kho------";
        Thuoc* node = lkt.head;
        while (node != NULL) {
            cout << "\nTen thuoc:" << node->thuoc.tenThuoc;
            cout << "\nSo luong: " << node->thuoc.soLuong;
            cout << "\nHan su dung: " << node->thuoc.hanSuDung.ngay << "/" << node->thuoc.hanSuDung.thang << "/" << node->thuoc.hanSuDung.nam;
            cout << "\nGia tien: " << node->thuoc.giaTien << "/" << node->thuoc.donVi << endl;
            cout << "------------------------------------------------------" << endl;
            node = node->next;
        }
    }
    cout << endl;
    system("pause");
}

void quanLi(listKhoThuoc& lkt, listKhachHang& lkh, listThuocChuaNhap& ltcn, listNhanVien& lnv, listLuong& ll, long long taiKhoan, string matKhau) {
    cout << "\nBan da dang nhap voi tu cach quan li";
    int luaChon;
    while (true) {
        system("cls");
        cout << "\n============Cac hoat dong cua quan li=============";
        cout << "\n1. Them nhan vien";
        cout << "\n2. Thay doi thong tin nhan vien";
        cout << "\n3. Tra luong nhan vien";
        cout << "\n4. Kiem tra bang luong";
        cout << "\n5. Tim kiem nhan vien";
        cout << "\n6. Xoa nhan vien";
        cout << "\n7. In danh sach nhan vien";
        cout << "\n8. Ket thuc ca lam viec";
        cout << "\n==================================================";
        cout << "\nNhap lua chon: ";
        do {
            cin >> luaChon;
            if (luaChon > 8 || luaChon < 1) {
                cout << "\nNhap lai";
            }
        } while (luaChon > 8 || luaChon < 1);
        if (luaChon == 1) {
            themNhanVien(lnv);
        }
        else if (luaChon == 2) {
            thayDoiThongTinNhanVien(lnv);
        }
        else if (luaChon == 3) {
            traLuongNhanVien(lnv, ll);
        }
        else if (luaChon == 4) {
            kiemTraBangLuong(ll, taiKhoan, matKhau);
        }
        else if (luaChon == 5) {
            cout << "Moi nhap ma nhan vien cam tim: ";
            long long manv;
            cin >> manv;
            searchNhanVien(lnv, manv);
        }
        else if (luaChon == 6) {
            xoaNhanVien(lnv);
        }
        else if (luaChon == 7) {
            lnv.head = mergeSortNV(lnv.head);
            capNhatNodeTailNV(lnv);
            inDanhSachNhanVien(lnv);
        }
        else {
            cout << "\nKet thuc ca lam viec"<<endl; 
            return;
        }
    }
}
void nhanVienLamViec(listKhoThuoc& lkt, listKhachHang& lkh, listThuocChuaNhap& ltcn, listNhanVien& lnv, listLuong& ll, long long taiKhoan, string matKhau, int& tongKhachHang, string tenNhanVien) {
    int lc;
    while (true) {
        system("cls");
        cout << "\nChao " << tenNhanVien << endl;
        cout << "\n----------------------------------------";
        cout << "\n1.Ban thuoc cho benh nhan";
        cout << "\n2.Kiem tra danh sach don thuoc";
        cout << "\n3.Dat mua them thuoc";
        cout << "\n4.Danh sach thuoc dang ve";
        cout << "\n5.Nhan thuoc da chuyen den";
        cout << "\n6.Kiem tra va loai bo thuoc qua han";
        cout << "\n7.Tim kiem thuoc trong kho";
        cout << "\n8.In kho thuoc";
        cout << "\n9.Kiem tra bang luong ca nhan";
        cout << "\n10.Ket thuc ca lam viec";
        cout << "\n--------------------------------------";
        do {
            cout << "\nNhap lua chon: ";
            cin >> lc;
            if (lc > 10 || lc < 1) {
                cout << "\nNhap lai";
            }
        } while (lc > 10 || lc < 1);
        if (lc == 1) {
            themKhachHangCoHoaDon(lkt, lkh, ltcn, tongKhachHang);
        }
        else if (lc == 2) {
            print(lkh);
        }
        else if (lc == 3) {
            string tenThuoc;
            cout << "\nTen thuoc: ";
            cin.ignore();
            getline(cin, tenThuoc);
            int soLuong;
            cout << "\nSo luong thuoc ve: ";
            cin >> soLuong;
            while (soLuong <= 0)
            {
                cout << "So luong thuoc ve phai lon hon 0. Moi nhap lai: ";
                cin >> soLuong;
            }
            string donVi;
            cout << "\nDon vi tinh so luong: ";
            cin.ignore();
            getline(cin, donVi);
            long long giaTien;
            cout << "\nGia tien moi don vi sau khi nhap ve: ";
            cin >> giaTien;
            while (giaTien < 0) {
                cout << "Gia tien khong duoc la so am. Moi nhap lai: ";
                cin >> giaTien;
            }
            Date hanSuDung;
            Date ngayVeKho;
            
            do {
                cout << "\nNhap han su dung (nam): "; cin >> hanSuDung.nam;
                if (hanSuDung.nam < 2021) {
                    cout << "\nNhap sai";
                }
            } while (hanSuDung.nam < 2021);
            do {
                cout << "\nNhap han su dung (thang): ";
                cin >> hanSuDung.thang;
                if (hanSuDung.thang < 1 || hanSuDung.thang > 12) {
                    cout << "\nNhap sai";
                }
            } while (hanSuDung.thang < 1 || hanSuDung.thang > 12);
            do {
                cout << "\nNhap han su dung (ngay): ";
                cin >> hanSuDung.ngay;
                if (hanSuDung.ngay < 1 || hanSuDung.ngay > returnNgay(hanSuDung.thang, hanSuDung.nam)) {
                    cout << "\nNhap sai ngay, thang " << hanSuDung.thang << " chi co " << returnNgay(hanSuDung.thang, hanSuDung.nam) << " ngay";
                    cout << "\nMoi nhap lai";
                }
            } while (hanSuDung.ngay < 1 || hanSuDung.ngay > returnNgay(hanSuDung.thang, hanSuDung.nam));
            do {
                cout << "\nNhap ngay ve kho (nam): ";
                cin >> ngayVeKho.nam;
                if (ngayVeKho.nam > hanSuDung.nam) {
                    cout << "\nNgay ve kho phai be hon han su dung";
                }
            } while (ngayVeKho.nam > hanSuDung.nam);
            do {
                cout << "\nNhap ngay ve kho (thang): ";
                cin >> ngayVeKho.thang;
                if (ngayVeKho.thang < 1 || ngayVeKho.thang > 12) {
                    cout << "\nNhap sai thang";
                }
            } while (ngayVeKho.thang < 1 || ngayVeKho.thang > 12);
            do {
                cout << "\nNhap ngay ve kho (ngay): ";
                cin >> ngayVeKho.ngay;
                if (ngayVeKho.ngay < 1 || ngayVeKho.ngay > returnNgay(ngayVeKho.thang, ngayVeKho.nam)) {
                    cout << "\nNhap sai ngay, thang " << ngayVeKho.thang << " chi co " << returnNgay(ngayVeKho.thang, ngayVeKho.nam) << " ngay";
                    cout << "\nMoi nhap lai";
                }
            } while (ngayVeKho.ngay < 1 || ngayVeKho.ngay > returnNgay(ngayVeKho.thang, ngayVeKho.nam));
            danhSachThuocChuaVeKho(lkt, lkh, ltcn, tenThuoc, soLuong, hanSuDung, ngayVeKho, donVi, giaTien);
        }
        else if (lc == 4) {
            inThuocChuaNhap(ltcn);
        }
        else if (lc == 5) {
            chuyenThuocVaoKho(lkt, lkh, ltcn);
        }
        else if (lc == 6) {
            kiemTraThuocQuaHan(lkt);
            kiemTraThuocDaHet(lkt);
        }
        else if (lc == 7) {
            cout << "Moi nhap ten loai thuoc can tim: ";
            string thuoc;
            cin.ignore();
            getline(cin, thuoc);
            searchThuoc(lkt, thuoc);
        }
        else if (lc == 8) {
            lkt.head = mergeSort(lkt.head);
            capNhatNodeTail(lkt);
            inKhoThuoc(lkt);
        }
        else if (lc == 9) {
            kiemTraBangLuong(ll, taiKhoan, matKhau);
        }
        else {
            cout << "\nKet thuc ca lam viec" << endl;
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
    string matKhau;
    int tongKhachHang = 0;
    ifstream inputThuoc("DSThuoc.txt",ios_base::in);
    if (!inputThuoc) {
        cerr << "Error: file not opened." << endl;
        return 1;
    }
    string tenThuoc, soLuong, ngay, thang, nam, ngay1, thang1, nam1, donVi, giaTien;
    while (!inputThuoc.eof()) {
        getline(inputThuoc, tenThuoc);
        getline(inputThuoc, soLuong);
        getline(inputThuoc, ngay);
        getline(inputThuoc, thang);
        getline(inputThuoc, nam);
        getline(inputThuoc, ngay1);
        getline(inputThuoc, thang1);
        getline(inputThuoc, nam1);
        getline(inputThuoc, donVi);
        getline(inputThuoc, giaTien);
        int d = ngay.length();
        int m = thang.length();
        int y = nam.length();
        int d1 = ngay1.length();
        int m1 = thang1.length();
        int y1 = nam1.length();
        int day, month, year, day1, month1, year1;
        day = month = year = day1 = month1 = year1 = 0;
        for (int i = d - 1; i >= 0; --i) {
            day += (int)(ngay[i] - '0') * pow(10, d - i - 1);
        }
        for (int i = m - 1; i >= 0; --i) {
            month += (int)(thang[i] - '0') * pow(10, m - i - 1);
        }
        for (int i = y - 1; i >= 0; --i) {
            year += (int)(nam[i] - '0') * pow(10, y - i - 1);
        }
        for (int i = d - 1; i >= 0; --i) {
            day1 += (int)(ngay1[i] - '0') * pow(10, d1 - i - 1);
        }
        for (int i = m - 1; i >= 0; --i) {
            month1 += (int)(thang1[i] - '0') * pow(10, m1 - i - 1);
        }
        for (int i = y - 1; i >= 0; --i) {
            year1 += (int)(nam1[i] - '0') * pow(10, y1 - i - 1);
        }
        Date hanSuDung, ngayVeKho;
        hanSuDung.ngay = day;
        hanSuDung.thang = month;
        hanSuDung.nam = year;
        ngayVeKho.ngay = day1;
        ngayVeKho.thang = month1;
        ngayVeKho.nam = year1;
        int sl = 0;
        int c = soLuong.length();
        for (int i = c - 1; i >= 0; --i) {
            sl += (int)(soLuong[i] - '0') * pow(10, c - i - 1);
        }
        long long gia = 0;
        int e = giaTien.length();
        for (int i = e - 1; i >= 0; --i) {
            gia += (long long)(giaTien[i] - '0') * pow(10, e - i - 1);
        }
        themVaoKhoThuoc(lkt, tenThuoc, sl, hanSuDung, ngayVeKho, donVi, gia);
    }
    inputThuoc.close();
    lkt.head = mergeSort(lkt.head);
    capNhatNodeTail(lkt);
    while (true) {
        system("cls");
        cout << "Moi nhap tai khoan de xac nhan chuc vu";
        cout << "\nMoi nhap ma nhan vien: ";
        long long taiKhoan;
        cin >> taiKhoan;
        if (taiKhoan == 2151120005) {
            cout << "\nNhap mat khau: ";
            cin.ignore();
            getline(cin, matKhau);
            if (matKhau == "bgxinh") {
                quanLi(lkt, lkh, ltcn, lnv, ll, taiKhoan, matKhau);
            }
            else {
                cout << "\nSai mat khau" << endl;
                system("pause");
            }
        }
        else {
            if (lnv.head == NULL) {
                cout << "\nChua co nhan vien nao" << endl;
                system("pause");
            }
            else {
                nhanVien* node = lnv.head;
                while (node->maNhanVien != taiKhoan) {
                    node = node->next;
                }
                if (node == NULL) {
                    cout << "\nMa nhan vien khong ton tai";
                }
                else {
                    cout << "\nNhap mat khau: ";
                    cin.ignore();
                    getline(cin, matKhau);
                    if (matKhau == node->matKhau) {
                        node->diemDanh += 1;
                        nhanVienLamViec(lkt, lkh, ltcn, lnv, ll, taiKhoan, matKhau, tongKhachHang, node->tenNhanVien);
                    }
                    else {
                        cout << "\nSai mat khau";
                    }
                }
            }
        }
    }
    return 0;
}