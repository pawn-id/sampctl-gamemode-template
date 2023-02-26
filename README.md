
# Sampctl Gamemode Template

Ini adalah sebuah template untuk kalian yang ingin membuat gamemode SA:MP menggunakan sampctl, template ini sudah dilengkapi dengan gamemode modular, serta beberapa include penting yang kalian dapat langsung gunakan tanpa mengunduh secara manual.

## Persiapan

Sebelum kalian melakukan instalasi/pemasangan repositori ini, alangkah baiknya kalian memenuhi syarat berikut:
1. Sudah menginstall [sampctl](https://github.com/southclaws/sampctl/releases)
2. Mengetahui tentang [git](https://git-scm.com) (opsional)
3. Faham tentang gamemode modular

## Instalasi

Untuk menggunakan template ini, silahkan download repositori nya dengan menggunakan
```bash
git clone https://github.com/pawn-id/sampctl-gamemode-template.git
```

atau bisa juga mendownload repositori secara manual menggunakan tombol "Download" (yang warna hijau) di github.com itu sendiri. Jika repositori sudah terdownload maka selanjutnya silahkan edit pawn.json sesuai dengan kebutuhan kamu, jika kamu melihat ada kata seperti `NAMAPROJECTMU` itu berarti ganti saja dengan nama gamemode yang akan kamu kerjakan, kalau melihat ada kata seperti `NAMAKAMU` itu berarti tinggal ganti saja dengan nama username github kamu (jika punya), atau kamu bisa isi sembarang. Sesudah itu kamu dapat mengetik perintah berikut:
```bash
sampctl package update
```

Untuk melakukan "Sync" package.

## Penggunaan

Untuk menggunakan sampctl itu sangat mudah, dan akan dibagi menjadi 3 bagian:

### Compile gamemode

Untuk melakukan compile, kamu hanya cukup mengetikkan perintah:
```bash
sampctl build
```
NOTE: Bagi yang menggunakan sampctl versi 1.9.1 atau kebawah, bisa menambahkan `p` atau `package` diantara `sampctl` dan `build`.

### Menjalankan server

Untuk menjalankan server menggunakan sampctl, kamu dapat mengetikkan perintah berikut:
```bash
sampctl run
```

NOTE: Bagi yang menggunakan sampctl versi 1.9.1 atau kebawah, bisa menambahkan `p` atau `package` diantara `sampctl` dan `run`.

### Watch

Watch ini agak spesial dari yang lain, dia bisa compile gamemode ketika kalian menyimpan perubahan dalam gamemode utama dengan menekan CTRL + S, bahkan juga bis menjalankan server ketika selesai menyimpan perubahan. Caranya sendiri cukup mudah, pastikan gamemode nya sudah terbuka, lalu silahkan melihat bagian [Compile gamemode](#compile-gamemode) atau [Menjalankan server](#menjalankan-server) dan tambahkan `--watch` setelah `build` dan `run`.

