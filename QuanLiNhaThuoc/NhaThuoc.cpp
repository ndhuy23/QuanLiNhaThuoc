#include "DoiTuong.h"
#include "NhanVien.h"
#include "QuanLy.h"

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
            if (lnv.head == NULL) {
                cout << "\nHien khong co nhan vien" << endl;
                system("pause");
            }
            else {
                lnv.head = mergeSortNV(lnv.head);
                capNhatNodeTailNV(lnv);
                inDanhSachNhanVien(lnv);
            }
        }
        else {
            cout << "\nKet thuc ca lam viec" << endl;
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
    ifstream inputThuoc("DSThuoc.txt", ios_base::in);
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