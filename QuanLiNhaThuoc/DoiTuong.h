#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

struct Date {
    int ngay;
    int thang;
    int nam;
};

struct thongtinThuoc {
    string tenThuoc;
    int soLuong;
    long long giaTien;
    string donVi;
    Date hanSuDung;
    Date ngayVeKho;
};

struct Thuoc {
    thongtinThuoc thuoc;
    Thuoc* next;
    Thuoc* prev;
};

struct KhachHang {
    string ten;
    Date ngayMuaHang;
    string bieuHien;
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

struct listNhanVien {
    nhanVien* head;
    nhanVien* tail;
};

struct listLuong {
    luongNhanVien* head;
    luongNhanVien* tail;
};