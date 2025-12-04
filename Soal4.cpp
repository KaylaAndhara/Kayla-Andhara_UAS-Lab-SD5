#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Pelanggan {
    string nama;
    int berat;
    string layanan; 
    int waktu_cuci; 

    // ID prioritas: 1 untuk Express, 2 untuk Reguler (nilai yang lebih kecil = prioritas lebih tinggi)
    int prioritas_layanan; 
};

bool comparePelanggan(const Pelanggan& a, const Pelanggan& b) {
    // Aturan 1: Prioritas layanan (Express vs Reguler)
    if (a.prioritas_layanan != b.prioritas_layanan) {
        return a.prioritas_layanan < b.prioritas_layanan; // Express (1) < Reguler (2)
    }
    
    // Aturan 2: Jika layanan sama, urutkan berdasarkan berat secara DESCENDING (terbesar duluan)
    return a.berat > b.berat; 
}

void solve_laundry_kilat() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Baris pertama berisi N (jumlah pelanggan)
    if (!(cin >> N)) return;

    vector<Pelanggan> daftar_pelanggan;

    // Baca data N pelanggan
    for (int i = 0; i < N; ++i) {
        Pelanggan p;
        cin >> p.nama >> p.berat >> p.layanan;

        // Tentukan waktu cuci per satuan berat dan prioritas
        if (p.layanan == "express") {
            p.waktu_cuci = 5;
            p.prioritas_layanan = 1; // Prioritas tertinggi
        } else if (p.layanan == "reguler") {
            p.waktu_cuci = 10;
            p.prioritas_layanan = 2; // Prioritas lebih rendah
        } else {
            continue; 
        }

        daftar_pelanggan.push_back(p);
    }

    sort(daftar_pelanggan.begin(), daftar_pelanggan.end(), comparePelanggan);

    long long total_waktu = 0;

    for (const auto& p : daftar_pelanggan) {
        total_waktu += (long long)p.berat * p.waktu_cuci;
    }

    cout << "Urutan pemrosesan (nama pelanggan):" << endl;
    for (size_t i = 0; i < daftar_pelanggan.size(); ++i) {
        cout << daftar_pelanggan[i].nama;
        if (i < daftar_pelanggan.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    // Output: Total waktu
    cout << "Total waktu yang dibutuhkan:" << endl;
    cout << total_waktu << " menit" << endl;
}

int main() {
    solve_laundry_kilat();
    return 0;
}
