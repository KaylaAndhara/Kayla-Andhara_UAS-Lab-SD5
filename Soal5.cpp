#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Fungsi rekursif dengan Memoization untuk menghitung kedalaman karyawan.
int calculateDepth(int employee_index, const vector<int>& managers, vector<int>& depth) {
    if (depth[employee_index] != 0) {
        return depth[employee_index];
    }

    int manager_id = managers[employee_index];
    
    // Kasus Base: Root (Manajer Puncak)
    if (manager_id == -1) {
        depth[employee_index] = 1;
        return 1;
    }

    // Kasus Rekursif: Kedalaman = 1 + Kedalaman manajer
    int manager_index = manager_id - 1;
    int current_depth = 1 + calculateDepth(manager_index, managers, depth);
    
    depth[employee_index] = current_depth;
    
    return current_depth;
}

void solve_pesta() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Baca N
    if (!(cin >> N)) return;

    // managers[i] adalah ID (1-based) manajer dari karyawan i+1.
    vector<int> managers(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> managers[i])) return;
    }

    // depth[i] menyimpan kedalaman. Diinisialisasi 0.
    vector<int> depth(N, 0);
    int max_groups = 0;

    // Hitung kedalaman maksimum
    for (int i = 0; i < N; ++i) {
        int current_depth = calculateDepth(i, managers, depth);
        max_groups = max(max_groups, current_depth);
    }

    // Output: Jumlah grup minimum
    cout << max_groups << endl;
}

// === 2. SOLUSI MASALAH: LAUNDRY KILAT (Penjadwalan Greedy) ===

struct Pelanggan {
    string nama;
    int berat;
    string layanan; 
    int waktu_cuci; 
    int prioritas_layanan; // 1: Express, 2: Reguler
};

// Fungsi komparator untuk pengurutan Greedy
bool comparePelanggan(const Pelanggan& a, const Pelanggan& b) {
    // 1. Express (1) didahulukan dari Reguler (2)
    if (a.prioritas_layanan != b.prioritas_layanan) {
        return a.prioritas_layanan < b.prioritas_layanan; 
    }
    
    // 2. Jika layanan sama, Berat terbesar didahulukan (DESCENDING)
    return a.berat > b.berat; 
}

void solve_laundry_kilat() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Baca N
    if (!(cin >> N)) return;

    vector<Pelanggan> daftar_pelanggan;

    // Baca data N pelanggan
    for (int i = 0; i < N; ++i) {
        Pelanggan p;
        if (!(cin >> p.nama >> p.berat >> p.layanan)) break;

        if (p.layanan == "express") {
            p.waktu_cuci = 5;
            p.prioritas_layanan = 1;
        } else if (p.layanan == "reguler") {
            p.waktu_cuci = 10;
            p.prioritas_layanan = 2;
        }

        daftar_pelanggan.push_back(p);
    }

    // Urutkan daftar pelanggan sesuai aturan Greedy
    sort(daftar_pelanggan.begin(), daftar_pelanggan.end(), comparePelanggan);

    // Hitung dan cetak output
    long long total_waktu = 0;
    cout << "Urutan pemrosesan (nama pelanggan):" << endl;
    for (size_t i = 0; i < daftar_pelanggan.size(); ++i) {
        const auto& p = daftar_pelanggan[i];
        total_waktu += (long long)p.berat * p.waktu_cuci;
        
        cout << p.nama;
        if (i < daftar_pelanggan.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    cout << "Total waktu yang dibutuhkan:" << endl;
    cout << total_waktu << " menit" << endl;
}


// === FUNGSI UTAMA (MAIN) ===

int main() {
    // Aktifkan salah satu fungsi yang ingin Anda jalankan:

    // 1. Untuk menjalankan Solusi Masalah Pesta:
    solve_pesta();

    // 2. Untuk menjalankan Solusi Masalah Laundry Kilat, hapus komentar pada baris di bawah ini dan beri komentar pada solve_pesta() di atas:
    // solve_laundry_kilat(); 

    return 0;
}
