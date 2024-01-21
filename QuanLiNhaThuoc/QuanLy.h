#pragma once
#include "DoiTuong.h"

void inits(listNhanVien& lnv, listLuong& ll) {
    lnv.head = lnv.tail = NULL;
    ll.head = ll.tail = NULL;
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

bool namNhuan(int nam) {
    if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
        return true;
    return false;
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

void searchNhanVien(listNhanVien lnv, long long maNV) {
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

void capNhatNodeTailNV(listNhanVien& lnv) {
    nhanVien* node = lnv.head;
    while (node->next != NULL) {
        node = node->next;
    }
    lnv.tail = node;
}

void inDanhSachNhanVien(listNhanVien& lnv) {
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
    system("pause");
}