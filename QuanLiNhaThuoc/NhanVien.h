#pragma once
#include "DoiTuong.h"

void init(listKhoThuoc& lkt, listKhachHang& lkh, listThuocChuaNhap& ltcn) {//tao list
    lkt.head = lkt.tail = NULL;
    lkh.head = lkh.tail = NULL;
    ltcn.head = ltcn.tail = NULL;
}

string chuanHoaHoaDon(string ma) {//chuan hoa ma don de so sanh thu co don cu k
    string res = "";
    for (int i = 0; i < ma.length(); i++) {
        res += toupper(ma[i]);
    }
    return res;
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
    time_t now = time(0);
    tm* t = localtime(&now);
    node->khachHang.ngayMuaHang.ngay = t->tm_mday;
    node->khachHang.ngayMuaHang.thang = t->tm_mon + 1;
    node->khachHang.ngayMuaHang.nam = 1900 + t->tm_year;
    return node;
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

void capNhatSoLuongTrongKho(listKhoThuoc& lkt, string tenThuoc, int soLuong) {
    Thuoc* node = lkt.head;
    while (node != NULL) {
        if (node->thuoc.tenThuoc == tenThuoc) {
            node->thuoc.soLuong = node->thuoc.soLuong - soLuong;
        }
        node = node->next;
    }
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

bool kiemTraNgayCoBangNhauKhong(Date d1, Date d2) {
    return (d1.ngay == d2.ngay && d1.thang == d2.thang && d1.nam == d2.nam);
}

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
            if (kiemTraKhoThuoc1(lkt, node)) {
                for (Thuoc* k = lkt.head; k != NULL; k = k->next) {
                    if (k->thuoc.tenThuoc == node->thuoc.tenThuoc && kiemTraNgayCoBangNhauKhong(k->thuoc.hanSuDung, node->thuoc.hanSuDung) && k->thuoc.giaTien == node->thuoc.giaTien && k->thuoc.donVi == node->thuoc.donVi) {
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
        if (sosanhDate(d, node->thuoc.hanSuDung)) {
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

Thuoc* mergeSort(Thuoc* head)
{
    if (!head || !head->next)
        return head;
    Thuoc* second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

void capNhatNodeTail(listKhoThuoc& lkt) {
    Thuoc* node = lkt.head;
    while (node->next != NULL) {
        node = node->next;
    }
    lkt.tail = node;
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