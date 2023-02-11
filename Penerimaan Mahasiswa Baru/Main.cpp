/*
					Kelompok 5
	=============================================
	Judul Project : Program Penerimaan Siswa Baru
	=============================================
	Anggota :
	1. Muhammad Rizky Rachman		(21.11.3975)
	2. Mahardika Wildan Fitrian		(21.11.4036)
	3. Ivano Perlita HR				(21.11.3973)
	4. Ichsan Cahyanto				(21.11.4023)
	5. Muhammad Syahrizal			(21.11.3968)
	6. Hafid Zain					(21.11.4025)
*/

#include <iostream>	
#include <conio.h>
#include <string> //library untuk getline, konversi stoi,stod,dll
#include <dos.h>
#include <Windows.h>
#include "Cursor.h" //library setting color dan posisi x,y


using namespace std;

const int size_array = 1000; //paramater untuk ukuran array 


/*
	masuk ke fungsi untuk menyimpan semua data
*/


//struct database jalur reguler
struct jlr_reguler
{
	string jml_data;
	string nama[size_array];
	string ttl[size_array];
	string asal_sekolah[size_array];
	string alamat[size_array];
	string nomor_telp[size_array];
	string agama[size_array];
	string prodi[size_array];
	string status[size_array]; //data lolos/tidak lolos berdasarkan index array

	string jalur[size_array];
	string jarak[size_array];
	double hasilkonversi_jarak[size_array];
};
jlr_reguler reg; //inisialisasi struct 


//struct database jalur prestasi
struct jlr_prestasi
{
	string jml_data;
	string nama[size_array];
	string ttl[size_array];
	string asal_sekolah[size_array];
	string alamat[size_array];
	string nomor_telp[size_array];
	string agama[size_array];
	string prodi[size_array];
	string nilai[size_array];
	string status[size_array]; //data lolos/tidak lolos berdasarkan index array

	double hasilkonversi_nilai[size_array]; //tampungan hasil konversi nilai
	string jalur[size_array];
};
jlr_prestasi prest; //inisialisasi struct 


//struct database jalur bidikmisi
struct jlr_bidikmisi
{
	string jml_data;
	string nama[size_array];
	string ttl[size_array];
	string asal_sekolah[size_array];
	string alamat[size_array];
	string nomor_telp[size_array];
	string agama[size_array];
	string prodi[size_array];
	string penghasilan[size_array];
	string status[size_array]; //data lolos/tidak lolos berdasarkan index array

	int hasilkonversi_penghasilan[size_array]; //tampungan hasil konversi penghasilan
	string jalur[size_array];
};
jlr_bidikmisi bdkmisi; //inisialisasi struct 



/*
	masuk ke fungsi identifier
*/


//identifier fungsi
void loading_bar(); //fungsi loading
void home_page(); //tampilan halaman utama

void sub_menu_1(); //fungsi menu no.1
void jalur_reguler(); //fungsi input jalur reguler
void jalur_prestasi(); //fungsi input jalur prestasi
void jalur_bidikmisi(); //fungsi input jalur bidikmisi

void sub_menu_2(); //fungsi no.2
void pengumuman(); //tampilan menu pengumuman
void pengumuman_1(); //fungsi jalur pendaftaran
void pengumuman_2(); //fungsi informasi pendaftaran
void prodi(); //fungsi prodi yang tersedia di kampus ini
void hasilPMB_reguler(); //fungsi pengumuman hasil lolos/tidak lolos jalur reguler
void hasilPMB_prestasi(); //fungsi pengumuman hasil lolos/tidak lolos jalur prestasi
void hasilPMB_bidikmisi(); //fungsi pengumuman hasil lolos/tidak lolos jalur bidikmisi

void sub_menu_3(); //fungsi no.3 pencarian data

void sub_menu_4(); //fungsi no.4 menampilkan semua data yang mendaftar semua jalur

void sub_menu_5(); //fungsi no.5 tampilan menu sorting
void sort_ascending_reg(); //fungsi sorting secara ascending
void sort_descending_reg(); //fungsi sorting descending
void sort_ascending_prest(); //fungsi sorting secara ascending
void sort_descending_prest(); //fungsi sorting descending
void sort_ascending_bdkmisi(); //fungsi sorting secara ascending
void sort_descending_bdkmisi(); //fungsi sorting descending


string pilihanMenu; //variabel global


int menu()
{
	do
	{
		home_page();

		//string::size_type sz;
		//// konversi string ke integer
		//int conv1 = stoi(pilihanMenu, &sz);

		//switch (conv1)
		//{
		//case 1:
		//	sub_menu_1();

		//case 2:
		//	sub_menu_2();

		//case 3:
		//	sub_menu_3();

		//case 4:
		//	sub_menu_4();

		//case 5:
		//	sub_menu_5();

		//case 6:
		//	return 0;
		//}
		if (pilihanMenu == "1")
		{
			sub_menu_1();
		}
		else if (pilihanMenu == "2")
		{
			sub_menu_2();
		}
		else if (pilihanMenu == "3")
		{
			sub_menu_3();
		}
		else if (pilihanMenu == "4")
		{
			sub_menu_4();
		}
		else if (pilihanMenu == "5")
		{
			sub_menu_5();
		}
		else if (pilihanMenu == "6")
		{
			return 0;
		}
		else
		{
			home_page();
		}
		

	} while (pilihanMenu != "6");
}


int main()
{

	loading_bar();
	menu();

	



	//loading_bar();
	//home_page();

	//sub_menu_1();
	//jalur_reguler();
	//jalur_prestasi(); 
	//jalur_bidikmisi(); 

	//sub_menu_2();
	//pengumuman();
	//pengumuman_1(); 
	//pengumuman_2(); 
	//prodi();
	//hasilPMB_reguler();
	//hasilPMB_prestasi();
	//hasilPMB_bidikmisi();

	//sub_menu_3();

	//sub_menu_4();

	//sub_menu_5();
	//sort_ascending(); 
	//sort_descending(); 


	set_xy(33, 50);
	return 0;
}





void loading_bar()
{

	/*
		masuk ke fungsi bingkai loading bar
	*/
	//bingkai loading bar
	set_xy(35, 21); cout << char(179); //vertikal kiri
	set_xy(86, 21); cout << char(179); //vertikal kanan

	set_xy(35, 20);	cout << char(218);//pojok kiri atas
	set_xy(86, 20); cout << char(191); //pojok kanan atas

	set_xy(35, 22); cout << char(192); //pojok kiri bawah
	set_xy(86, 22); cout << char(217); //pojok kanan bawah

	//horisontal atas loading bar
	set_xy(36, 20);
	for (int i = 0; i < 50; i++)
	{
		cout << char(196);
	}

	//horisontal bawah loading bar
	set_xy(36, 22);
	for (int i = 0; i < 50; i++)
	{
		cout << char(196);
	}



	for (int i = 1; i <= 50; i++)
	{
		set_color(14, 0); //agar tidak seperti berkedip karena fungsi timpa tulisan hitam di bawah

		//bingkai judul
		set_xy(30, 2); cout << "==========================(S1-IF03)==========================";
		set_xy(30, 3); cout << "<<                                                         >>";
		set_xy(30, 4); cout << "<<<                                                       >>>";
		set_xy(30, 5); cout << "<<<<                                                     >>>>"; set_xy(46, 5); set_color(6, 0); cout << "Program Penerimaan Siswa Baru"; set_color(14, 0);
		set_xy(30, 6); cout << "<<<<<          -------------------------------          >>>>>";
		set_xy(30, 7); cout << "<<<<                                                     >>>>"; set_xy(52, 7); set_color(6, 0); cout << "Karya : Kelompok 5"; set_color(14, 0);
		set_xy(30, 8); cout << "<<<                                                       >>>";
		set_xy(30, 9); cout << "<<                                                         >>";
		set_xy(30, 10); cout << "==========================(S1-IF03)==========================";
		set_xy(30, 11); cout << "|                                                           |";
		set_xy(30, 12); cout << "|                                                           |";
		set_xy(30, 13); cout << "+                                                           +"; set_xy(46, 13); set_color(13, 0); cout << "UNIVERSITAS AMIKOM YOGYAKARTA"; set_color(14, 0);
		set_xy(30, 14); cout << "|                                                           |";
		set_xy(30, 15); cout << "|                                                           |";
		set_xy(30, 16); cout << "==========================(S1-IF03)==========================";


		set_color(15, 0);

		//loading.. display percentage
		set_xy(36, 19); cout << "Loading " << 2 * i << "%";

		//loading bar
		set_xy(36, 21);
		for (int j = 1; j <= i; j++)
		{
			set_color(13, 0);
			cout << char(219);
		}

		set_color(7, 0);

		Sleep(150 - i * 3);//kecepatan loading

		set_xy(36, 23);

		//keterangan dibawah loading bar
		if (i > 1 && i < 20)
		{
			cout << "Sedang Mengumpulkan Data";
		}

		//menimpa dengan karakter null (tipex) agar sisa tulisan hilang
		else if (i == 20)
		{
			cout << "                                     ";
		}

		else if (i > 20 && i < 37)
		{
			cout << "Akses ke Database";
		}

		//menimpa dengan karakter null (tipex) agar sisa tulisan hilang
		else if (i == 37)
		{
			cout << "                                     ";
		}

		else if (i > 37 && i < 48)
		{
			cout << "Hampir Selesai";
		}

		else if (i == 50)
		{
			cout << "Complete. Press Enter to Continue";
		}

	}


	set_xy(36, 24);
	system("pause");
	system("cls");
}

void home_page()
{

	set_color(6, 0);

	//Horisontal atas bingkai teks judul Univ
	for (int i = 0; i < 60; i++)
	{
		set_xy(31 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah bingkai teks judul Univ
	for (int i = 0; i < 61; i++)
	{
		set_xy(30 + i, 4);
		cout << char(22);
	}



	//horisontal bawah bingkai teks pilihan menu
	set_xy(31, 17);
	for (int i = 0; i < 60; i++)
	{
		cout << char(22);
	}

	//vertikal bingkai kanan teks pilihan menu
	for (int i = 0; i < 14; i++)
	{
		set_xy(90, 3 + i);
		cout << char(222);
	}

	//vertikal bingkai kiri teks pilihan menu
	for (int i = 0; i < 14; i++)
	{
		set_xy(30, 3 + i);
		cout << char(222);
	}


	/*
		masuk ke fungsi bingkai tulisan teks "menu utama"
	*/

	set_color(14, 0);
	set_xy(50, 6); cout << char(179); //vertikal kiri
	set_xy(72, 6); cout << char(179); //vertikal kanan
	set_xy(50, 5); cout << char(218); //pojok kiri atas
	set_xy(50, 7); cout << char(192); //pojok kiri bawah
	set_xy(72, 5); cout << char(191); //pojok kanan atas
	set_xy(72, 7); cout << char(217); //pojok kanan bawah

	//horisontal atas teks "menu utama"
	set_xy(51, 5);
	for (int i = 0; i < 21; i++)
	{
		cout << char(196);
	}

	//horisontal bawah teks "menu utama"
	set_xy(51, 7);
	for (int i = 0; i < 21; i++)
	{
		cout << char(196);
	}

	set_color(11, 0);
	set_xy(52, 6); cout << "M E N U   U T A M A";
	set_color(14, 0);
	set_xy(33, 9); cout << "1. Pendaftaran Mahasiswa Baru";
	set_xy(33, 10); cout << "2. Informasi Universitas";
	set_xy(33, 11); cout << "3. Cari Data Mahasiswa Baru";
	set_xy(33, 12); cout << "4. Tampilkan Data";
	set_xy(33, 13); cout << "5. Sorting Data";
	set_xy(33, 14); cout << "6. EXIT";

	set_color(15, 0);
	set_xy(36, 16); cout << "Pilih Menu [1/2/3/4/5/6] "; cout << char(16); cout << " ";
	set_xy(43, 3); cout << "U N I V E R S I T Y   O F   T O K Y O";
	


	set_xy(63, 16); getline(cin, pilihanMenu);
	
	

	set_xy(31, 19);
	system("pause");
	system("cls");
}




void sub_menu_1()
{
	set_color(11, 0);

	//Horisontal atas bingkai teks judul Univ
	for (int i = 0; i < 60; i++)
	{
		set_xy(31 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah bingkai teks judul Univ
	for (int i = 0; i < 61; i++)
	{
		set_xy(30 + i, 6);
		cout << char(22);
	}

	//horisontal bawah bingkai teks pilihan menu
	set_xy(31, 19);
	for (int i = 0; i < 60; i++)
	{
		cout << char(22);
	}


	//vertikal bingkai kanan teks pilihan menu
	for (int i = 0; i < 16; i++)
	{
		set_xy(90, 3 + i);
		cout << char(222);
	}

	//vertikal bingkai kiri teks pilihan menu
	for (int i = 0; i < 16; i++)
	{
		set_xy(30, 3 + i);
		cout << char(222);
	}

	set_color(6, 0);
	set_xy(44, 4); cout << "+++ Pendaftaran Mahasiswa Baru +++";

	set_color(14, 0);
	set_xy(33, 8); cout << "1. Jalur Reguler";
	set_xy(33, 10); cout << "2. Jalur Prestasi";
	set_xy(33, 12); cout << "3. Jalur Bidikmisi";
	set_xy(33, 14); cout << "4. BACK";

	set_color(15, 0);


	set_xy(36, 17); cout << "Masukan Pilihan Anda [1/2/3/4] "; cout << char(16); cout << " ";


	set_xy(69, 17); getline(cin, pilihanMenu);

	if (pilihanMenu == "1")
	{
		system("cls");
		return jalur_reguler();
	}
	else if (pilihanMenu == "2")
	{
		system("cls");
		return jalur_prestasi();
	}
	else if (pilihanMenu == "3")
	{
		system("cls");
		jalur_bidikmisi();
	}
	else if (pilihanMenu == "4")
	{
		system("cls");
		menu();
	}
	else
	{
		system("cls");
		sub_menu_1();
	}

	set_xy(31, 21);
	system("pause");
	system("cls");

}

void jalur_reguler()
{

	/*
		Masuk ke fungsi Header 

	*/
	set_color(14, 0);

	//Horisontal atas bingkai teks judul Univ
	for (int i = 0; i < 66; i++)
	{
		set_xy(27 + i, 2);
		cout << char(205);
	}

	//Horisontal bawah bingkai teks judul Univ
	for (int i = 0; i < 66; i++)
	{
		set_xy(27 + i, 6);
		cout << char(205);
	}

	//vertikal bingkai kanan teks judul Univ
	for (int i = 0; i < 3; i++)
	{
		set_xy(93, 3 + i);
		cout << char(186);
	}

	//vertikal bingkai kiri teks judul Univ
	for (int i = 0; i < 3; i++)
	{
		set_xy(26, 3 + i);
		cout << char(186);
	}

	set_xy(93, 2); cout << char(187); //bingkai pojok kanan atas judul
	set_xy(93, 6); cout << char(188); //bingkai pojok kanan bawah judul

	set_xy(26, 2); cout << char(201);//bingkai pojok kiri atas judul
	set_xy(26, 6); cout << char(200);//bingkai pojok kiri bawah judul


	/*
		Masuk ke fungsi input data calon pendaftar

	*/


	//horisontal atas input data
	for (int i = 0; i < 99; i++)
	{
		set_xy(10 + i, 10);
		cout << char(247);
	}

	//horisontal bawah input data
	for (int i = 0; i < 99; i++)
	{
		set_xy(10 + i, 34);
		cout << char(247);
	}

	
	set_color(11, 0);
	set_xy(42, 3); cout << "U N I V E R S I T Y   O F   T O K Y O";
	set_xy(44, 5); cout << "+++ Pendaftaran Mahasiswa Baru +++";

	set_xy(10, 8); cout << "# Jalur Pendaftaran REGULER";

	//input banyaknya pendaftar. banyaknya perulangan yang akan terjadi
	set_xy(15, 12); cout << "Banyak Mahasiswa yang mendaftar "; cout << char(16); cout << " "; getline(cin, reg.jml_data);


	//mengkonversi tipe data string ke integer
	//dikarenakan menggunakan fungsi getline, maka tidak dapat dikombinasikan dengan fungsi cin
	//penggunaan getline harus bertipekan string
	string::size_type sz;
	int konversi1 = stoi(reg.jml_data, &sz);


	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(18, 14);
		cout << ">Data ke- " << i;

		set_xy(18, 16); cout << "1. Nama Mahasiswa Baru    = "; getline(cin, reg.nama[i]); //cin >> reg.nama[i];
		set_xy(18, 17); cout << "2. Tempat, Tanggal Lahir  = "; getline(cin, reg.ttl[i]); //cin >> reg.ttl[i];
		set_xy(18, 18); cout << "3. Asal Sekolah           = "; getline(cin, reg.asal_sekolah[i]); //cin >> reg.asal_sekolah[i];
		set_xy(18, 19); cout << "4. Alamat                 = "; getline(cin, reg.alamat[i]); //cin >> reg.alamat[i];
		set_xy(18, 20); cout << "5. No. HP                 = "; getline(cin, reg.nomor_telp[i]); //cin >> reg.nomor_telp[i];
		set_xy(18, 21); cout << "6. Agama                  = "; getline(cin, reg.agama[i]); //cin >> reg.agama[i];
		set_xy(18, 22); cout << "7. Pilih Prodi            = "; getline(cin, reg.prodi[i]); //cin >> reg.prodi[i];
		set_xy(18, 25); cout << "*Note : Jarak Rumah Ke Kampus (Kilometer). Isi Hanya Angka Saja"; 
		set_xy(18, 23); cout << "8. Jarak Ke Kampus        = "; getline(cin, reg.jarak[i]); //cin >> reg.prodi[i];


		//untuk menghapus sisa tulisan waktu perulangan berjalan
		set_xy(18, 14); cout << "                                                                                          ";
		set_xy(18, 16); cout << "                                                                                          ";
		set_xy(18, 17); cout << "                                                                                          ";
		set_xy(18, 18); cout << "                                                                                          ";
		set_xy(18, 19); cout << "                                                                                          ";
		set_xy(18, 20); cout << "                                                                                          ";
		set_xy(18, 21); cout << "                                                                                          ";
		set_xy(18, 22); cout << "                                                                                          ";
		set_xy(18, 23); cout << "                                                                                          ";
		set_xy(18, 25); cout << "                                                                                          ";
		

	}

	set_xy(15, 12); cout << "                                                ";
	set_xy(10, 8);  cout << "                                                ";



	set_xy(10, 36);
	system("pause");
	system("cls");

	return sub_menu_1();
}

void jalur_prestasi()
{
	/*
		Masuk ke fungsi Header

	*/

	set_color(12, 0);
	//Horisontal atas bingkai teks judul Univ
	for (int i = 0; i < 66; i++)
	{
		set_xy(27 + i, 2);
		cout << char(205);
	}

	//Horisontal bawah bingkai teks judul Univ
	for (int i = 0; i < 66; i++)
	{
		set_xy(27 + i, 6);
		cout << char(205);
	}

	//vertikal bingkai kanan teks judul Univ
	for (int i = 0; i < 3; i++)
	{
		set_xy(93, 3 + i);
		cout << char(186);
	}

	//vertikal bingkai kiri teks judul Univ
	for (int i = 0; i < 3; i++)
	{
		set_xy(26, 3 + i);
		cout << char(186);
	}

	set_xy(93, 2); cout << char(187); //bingkai pojok kanan atas judul
	set_xy(93, 6); cout << char(188); //bingkai pojok kanan bawah judul

	set_xy(26, 2); cout << char(201);//bingkai pojok kiri atas judul
	set_xy(26, 6); cout << char(200);//bingkai pojok kiri bawah judul


	/*
		Masuk ke fungsi input data calon pendaftar

	*/


	//horisontal atas input data
	for (int i = 0; i < 99; i++)
	{
		set_xy(10 + i, 10);
		cout << char(247);
	}

	//horisontal bawah input data
	for (int i = 0; i < 99; i++)
	{
		set_xy(10 + i, 34);
		cout << char(247);
	}


	set_color(14, 0);
	set_xy(42, 3); cout << "U N I V E R S I T Y   O F   T O K Y O";
	set_xy(44, 5); cout << "+++ Pendaftaran Mahasiswa Baru +++";

	set_xy(10, 8); cout << "# Jalur Pendaftaran PRESTASI";

	//input banyaknya pendaftar. banyaknya perulangan yang akan terjadi
	set_xy(15, 12); cout << "Banyak Mahasiswa yang mendaftar "; cout << char(16); cout << " "; getline(cin, prest.jml_data);


	//mengkonversi tipe data string ke integer
	//dikarenakan menggunakan fungsi getline, maka tidak dapat dikombinasikan dengan fungsi cin
	//penggunaan getline harus bertipekan string
	string::size_type sz;
	int konversi2 = stoi(prest.jml_data, &sz);


	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(18, 14);
		cout << ">Data ke- " << i;

		set_xy(18, 16); cout << "1. Nama Mahasiswa Baru    = "; getline(cin, prest.nama[i]); 
		set_xy(18, 17); cout << "2. Tempat, Tanggal Lahir  = "; getline(cin, prest.ttl[i]); 
		set_xy(18, 18); cout << "3. Asal Sekolah           = "; getline(cin, prest.asal_sekolah[i]); 
		set_xy(18, 19); cout << "4. Alamat                 = "; getline(cin, prest.alamat[i]); 
		set_xy(18, 20); cout << "5. No. HP                 = "; getline(cin, prest.nomor_telp[i]); 
		set_xy(18, 21); cout << "6. Agama                  = "; getline(cin, prest.agama[i]); 
		set_xy(18, 22); cout << "7. Pilih Prodi            = "; getline(cin, prest.prodi[i]);

		set_xy(18, 25); cout << "*NOTE : Masukkan Nilai Skala (>=00.00 s/d <=40.00) gunakan tanda titik";
		set_xy(18, 23); cout << "8. Masukkan Nilai (NEM)   = "; getline(cin, prest.nilai[i]);


		//untuk menghapus sisa tulisan waktu perulangan berjalan
		set_xy(18, 14); cout << "                                                                                          ";
		set_xy(18, 16); cout << "                                                                                          ";
		set_xy(18, 17); cout << "                                                                                          ";
		set_xy(18, 18); cout << "                                                                                          ";
		set_xy(18, 19); cout << "                                                                                          ";
		set_xy(18, 20); cout << "                                                                                          ";
		set_xy(18, 21); cout << "                                                                                          ";
		set_xy(18, 22); cout << "                                                                                          ";
		set_xy(18, 23); cout << "                                                                                          ";
		set_xy(18, 25); cout << "                                                                                          ";
		
		
	}
	
	set_xy(15, 12); cout << "                                                ";
	set_xy(10, 8);  cout << "                                                ";




	set_xy(10, 36);
	system("pause");
	system("cls");

	return sub_menu_1();

}

void jalur_bidikmisi()
{

	/*
		Masuk ke fungsi Header

	*/
	set_color(9, 0);
	//Horisontal atas bingkai teks judul Univ
	for (int i = 0; i < 66; i++)
	{
		set_xy(27 + i, 2);
		cout << char(205);
	}

	//Horisontal bawah bingkai teks judul Univ
	for (int i = 0; i < 66; i++)
	{
		set_xy(27 + i, 6);
		cout << char(205);
	}

	//vertikal bingkai kanan teks judul Univ
	for (int i = 0; i < 3; i++)
	{
		set_xy(93, 3 + i);
		cout << char(186);
	}

	//vertikal bingkai kiri teks judul Univ
	for (int i = 0; i < 3; i++)
	{
		set_xy(26, 3 + i);
		cout << char(186);
	}

	set_xy(93, 2); cout << char(187); //bingkai pojok kanan atas judul
	set_xy(93, 6); cout << char(188); //bingkai pojok kanan bawah judul

	set_xy(26, 2); cout << char(201);//bingkai pojok kiri atas judul
	set_xy(26, 6); cout << char(200);//bingkai pojok kiri bawah judul


	/*
		Masuk ke fungsi input data calon pendaftar

	*/


	//horisontal atas input data
	for (int i = 0; i < 99; i++)
	{
		set_xy(10 + i, 10);
		cout << char(247);
	}

	//horisontal bawah input data
	for (int i = 0; i < 99; i++)
	{
		set_xy(10 + i, 34);
		cout << char(247);
	}


	set_color(15, 0);
	set_xy(42, 3); cout << "U N I V E R S I T Y   O F   T O K Y O";
	set_xy(44, 5); cout << "+++ Pendaftaran Mahasiswa Baru +++";

	set_xy(10, 8); cout << "# Jalur Pendaftaran BIDIKMISI";



	//input banyaknya pendaftar. banyaknya perulangan yang akan terjadi
	set_xy(15, 12); cout << "Banyak Mahasiswa yang mendaftar "; cout << char(16); cout << " "; getline(cin, bdkmisi.jml_data);


	//mengkonversi tipe data string ke integer
	//dikarenakan menggunakan fungsi getline, maka tidak dapat dikombinasikan dengan fungsi cin
	//penggunaan getline harus bertipekan string
	string::size_type sz;
	int konversi3 = stoi(bdkmisi.jml_data, &sz);


	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(18, 14);
		cout << ">Data ke- " << i;

		set_xy(18, 16); cout << "1. Nama Mahasiswa Baru    = "; getline(cin, bdkmisi.nama[i]);
		set_xy(18, 17); cout << "2. Tempat, Tanggal Lahir  = "; getline(cin, bdkmisi.ttl[i]);
		set_xy(18, 18); cout << "3. Asal Sekolah           = "; getline(cin, bdkmisi.asal_sekolah[i]);
		set_xy(18, 19); cout << "4. Alamat                 = "; getline(cin, bdkmisi.alamat[i]);
		set_xy(18, 20); cout << "5. No. HP                 = "; getline(cin, bdkmisi.nomor_telp[i]);
		set_xy(18, 21); cout << "6. Agama                  = "; getline(cin, bdkmisi.agama[i]);
		set_xy(18, 22); cout << "7. Pilih Prodi            = "; getline(cin, bdkmisi.prodi[i]);

		set_xy(18, 25); cout << "*NOTE : Format Penghasilan Orangtua Hanya (ANGKA) Tanpa Tanda Titik";
		set_xy(18, 23); cout << "8. Penghasilan Orangtua   = "; getline(cin, bdkmisi.penghasilan[i]);


		//untuk menghapus sisa tulisan waktu perulangan berjalan
		set_xy(18, 14); cout << "                                                                                          ";
		set_xy(18, 16); cout << "                                                                                          ";
		set_xy(18, 17); cout << "                                                                                          ";
		set_xy(18, 18); cout << "                                                                                          ";
		set_xy(18, 19); cout << "                                                                                          ";
		set_xy(18, 20); cout << "                                                                                          ";
		set_xy(18, 21); cout << "                                                                                          ";
		set_xy(18, 22); cout << "                                                                                          ";
		set_xy(18, 23); cout << "                                                                                          ";
		set_xy(18, 25); cout << "                                                                                          ";


	}

	set_xy(15, 12); cout << "                                                ";
	set_xy(10, 8);  cout << "                                                ";




	set_xy(10, 36);
	system("pause");
	system("cls");

	return sub_menu_1();
}




void sub_menu_2()
{

	/*
		masuk ke fungsi header, kepala 



	*/
	set_color(13, 0);
	//Horisontal atas 
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 12);
		cout << char(22);
	}

	set_color(14, 0);
	set_xy(57, 4); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 5);
		cout << char(220);
	}

	set_xy(67, 7); cout << "++ PENGUMUMAN ++";
	set_xy(60, 9); cout << "Jadwal - Hasil Seleksi - Berita";
	set_xy(59, 10); cout << "Update Setiap Hari Senin & Selasa";


	/*
		masuk ke fungsi isi. bagian bawah. 
	


	*/

	set_color(13, 0);
	//Horisontal atas 
	for (int i = 0; i < 90; i++)
	{
		set_xy(30 + i, 15);
		cout << char(220);
	}

	//Horisontal bawah 
	for (int i = 0; i < 90; i++)
	{
		set_xy(30 + i, 35);
		cout << char(220);
	}

	//vertikal kiri
	for (int i = 0; i < 20; i++)
	{
		set_xy(30, 15 + i);
		cout << char(220);
	}

	//vertikal kanan
	for (int i = 0; i < 20; i++)
	{
		set_xy(119, 15 + i);
		cout << char(220);
	}


	set_color(14, 0);
	set_xy(38, 19); cout << "1. Pengumuman";
	set_xy(38, 21); cout << "2. Program Studi";
	set_xy(38, 23); cout << "3. Hasil PMB Jalur REGULER";
	set_xy(38, 25); cout << "4. Hasil PMB Jalur PRESTASI";
	set_xy(38, 27); cout << "5. HASIL PMB Jalur BIDIKMISI";
	set_xy(38, 29); cout << "6. HOME";

	set_xy(38, 32); cout << "Pilih Menu [1/2/3/4/5/6] "; cout << char(16); cout << " ";

	set_color(15, 0);
	set_xy(65, 32); getline(cin, pilihanMenu);

	if (pilihanMenu == "1")
	{
		system("cls");
		return pengumuman();
	}
	else if (pilihanMenu == "2")
	{
		system("cls");
		return prodi();
	}
	else if (pilihanMenu == "3")
	{
		system("cls");
		hasilPMB_reguler();
	}
	else if (pilihanMenu == "4")
	{
		system("cls");
		hasilPMB_prestasi();
	}
	else if (pilihanMenu == "5")
	{
		system("cls");
		hasilPMB_bidikmisi();
	}
	else if (pilihanMenu == "6")
	{
		system("cls");
		menu();
	}
	else
	{
		system("cls");
		sub_menu_2();
	}


	set_xy(30, 38);
	system("pause");
	system("cls");


}

void pengumuman()
{


	/*
		masuk ke fungsi header, kepala 



	*/
	set_color(11, 0);
	//Horisontal atas 
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 12);
		cout << char(22);
	}
	set_color(14, 0);
	set_xy(57, 4); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 5);
		cout << char(220);
	}

	set_xy(67, 7); cout << "++ PENGUMUMAN ++";
	set_xy(62, 9); cout << "B E R I T A -- K A M P U S";
	set_xy(59, 10); cout << "Update Setiap Hari Senin & Selasa";


	/*
		masuk ke fungsi isi. bagian bawah.



	*/

	set_color(11, 0);
	//Horisontal atas 
	for (int i = 0; i < 90; i++)
	{
		set_xy(30 + i, 15);
		cout << char(220);
	}

	//Horisontal bawah 
	for (int i = 0; i < 90; i++)
	{
		set_xy(30 + i, 35);
		cout << char(220);
	}

	//vertikal kiri
	for (int i = 0; i < 20; i++)
	{
		set_xy(30, 15 + i);
		cout << char(220);
	}

	//vertikal kanan
	for (int i = 0; i < 20; i++)
	{
		set_xy(119, 15 + i);
		cout << char(220);
	}

	set_color(14, 0);

	set_xy(38, 21); cout << "1. Jalur Pendaftaran";
	set_xy(38, 23); cout << "2. Informasi Pendaftaran";
	set_xy(38, 25); cout << "3. BACK";
	
	set_xy(38, 29); cout << "Pilih Menu [1/2/3] "; cout << char(16); cout << " ";

	set_color(15, 0);

	set_xy(59, 29); getline(cin, pilihanMenu);

	if (pilihanMenu == "1")
	{
		system("cls");
		return pengumuman_1();
	}
	else if (pilihanMenu == "2")
	{
		system("cls");
		return pengumuman_2();
	}
	else if (pilihanMenu == "3")
	{
		system("cls");
		sub_menu_2();
	}
	else
	{
		system("cls");
		pengumuman();
	}


	set_xy(30, 38);
	system("pause");
	system("cls");

}

void pengumuman_1()
{

	/*
		masuk ke fungsi header, kepala 



	*/
	set_color(10, 0);
	//Horisontal atas 
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 12);
		cout << char(22);
	}

	set_color(14, 0);
	set_xy(57, 4); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 5);
		cout << char(220);
	}

	set_xy(67, 7); cout << "++ PENGUMUMAN ++";
	set_xy(65, 9); cout << "JALUR -- PENDAFTARAN";
	set_xy(59, 10); cout << "Update Setiap Hari Senin & Selasa";


	/*
		masuk ke fungsi isi. bagian bawah.



	*/
	set_color(10, 0);

	//Horisontal atas 
	for (int i = 0; i < 120; i++)
	{
		set_xy(15 + i, 15);
		cout << char(220);
	}

	//Horisontal bawah 
	for (int i = 0; i < 120; i++)
	{
		set_xy(15 + i, 40);
		cout << char(220);
	}

	
	set_color(14, 0);

	set_xy(20, 18); cout << "Jalur PMB yang tersedia di UNIVERSITY OF TOKYO : ";

	set_xy(20, 21); cout << "- Jalur REGULER";
	set_xy(20, 23); cout << "- Jalur PRESTASI";
	set_xy(20, 25); cout << "- Jalur Bidikmisi";
	

	set_xy(20, 30); cout << "Masukkan angka [0] untuk kembali "; cout << char(16); cout << " ";

	set_xy(55, 30); getline(cin, pilihanMenu);

	set_color(15, 0);

	if (pilihanMenu == "0")
	{
		system("cls");
		return pengumuman();
	}
	else
	{
		system("cls");
		pengumuman_1();
	}




	set_xy(15, 42);
	system("pause");
	system("cls");

}

void pengumuman_2()
{

	/*
		masuk ke fungsi header, kepala 



	*/
	set_color(13, 0);
	//Horisontal atas 
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 12);
		cout << char(22);
	}
	set_color(14, 0);
	set_xy(57, 4); cout << "U N I V E R S I T Y   O F   T O K Y O";


	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 5);
		cout << char(220);
	}

	set_xy(67, 7); cout << "++ PENGUMUMAN ++";
	set_xy(64, 9); cout << "JADWAL -- PENDAFTARAN";
	set_xy(59, 10); cout << "Update Setiap Hari Senin & Selasa";


	/*
		masuk ke fungsi isi. bagian bawah.



	*/

	set_color(13, 0);
	//Horisontal atas 
	for (int i = 0; i < 120; i++)
	{
		set_xy(15 + i, 15);
		cout << char(220);
	}

	//Horisontal bawah 
	for (int i = 0; i < 120; i++)
	{
		set_xy(15 + i, 43);
		cout << char(220);
	}



	set_color(14, 0);
	set_xy(20, 18); cout << "Jadwal Pembukaan PMB di UNIVERSITY OF TOKYO : ";

	set_color(13, 0);
	//garis bagi setiap jalur
	for (int i = 0; i < 60; i++)
	{
		set_xy(20 + i, 21);
		cout << char(22);
	}
	set_color(14, 0);
	set_xy(20, 23); cout << "- Jalur Prestasi 1 = 15 Desember 2022 s/d 31 Januari 2023";
	set_xy(20, 24); cout << "- Jalur Prestasi 2 = 10 Februari 2023 s/d 31 Maret 2023 ";
	
	set_color(13, 0);
	//garis bagi setiap jalur
	for (int i = 0; i < 60; i++)
	{
		set_xy(20 + i, 26);
		cout << char(22);
	}
	set_color(14, 0);
	set_xy(20, 28); cout << "- Jalur Bidikmisi = 13 April 2023 s/d 31 April 2023";

	set_color(13, 0);
	//garis bagi setiap jalur
	for (int i = 0; i < 60; i++)
	{
		set_xy(20 + i, 30);
		cout << char(22);
	}
	set_color(14, 0);
	set_xy(20, 32); cout << "- Jalur Reguler 1 = 13 April 2023 s/d 29 April 2023";
	set_xy(20, 33); cout << "- Jalur Reguler 2 = 01 Mei 2023 s/d 25 Mei 2023";
	set_xy(20, 34); cout << "- Jalur Reguler 3 = 27 Mei 2023 s/d 15 Juni 2023";

	set_color(13, 0);
	//garis bagi setiap jalur
	for (int i = 0; i < 60; i++)
	{
		set_xy(20 + i, 36);
		cout << char(22);
	}


	set_color(14, 0);
	set_xy(20, 40); cout << "Masukkan angka [0] untuk kembali "; cout << char(16); cout << " ";
	set_color(15, 0);

	set_xy(55, 40); getline(cin, pilihanMenu);

	if (pilihanMenu == "0")
	{
		system("cls");
		return pengumuman();
	}
	else
	{
		system("cls");
		pengumuman_2();
	}


	set_xy(15, 45);
	system("pause");
	system("cls");

	
}

void prodi()
{

	/*
		masuk ke fungsi header, kepala 



	*/
	set_color(12, 0);
	//Horisontal atas 
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 12);
		cout << char(22);
	}
	set_color(10, 0);
	set_xy(57, 4); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 5);
		cout << char(220);
	}

	set_xy(66, 7); cout << "++ Program Studi ++";
	set_xy(62, 9); cout << "Daftar Prodi Yang Tersedia";
	set_xy(61, 10); cout << "Syarat dan Ketentuan Berlaku";


	/*
		masuk ke fungsi isi. bagian bawah.



	*/

	set_color(12, 0);
	//Horisontal atas 
	for (int i = 0; i < 120; i++)
	{
		set_xy(15 + i, 15);
		cout << char(220);
	}

	//Horisontal bawah 
	for (int i = 0; i < 120; i++)
	{
		set_xy(15 + i, 43);
		cout << char(220);
	}



	set_color(10, 0);
	set_xy(20, 18); cout << "Program Studi University Of Tokyo";

	set_color(12, 0);
	//garis bagi setiap jalur
	for (int i = 0; i < 110; i++)
	{
		set_xy(20 + i, 21);
		cout << char(22);
	}
	set_color(10, 0);
	set_xy(20, 23); cout << "- Teknik Sipil (S1)";
	set_xy(20, 24); cout << "- Teknologi Informasi (S1)";

	set_color(12, 0);
	//garis bagi setiap jalur
	for (int i = 0; i < 110; i++)
	{
		set_xy(20 + i, 26);
		cout << char(22);
	}
	set_color(10, 0);
	set_xy(20, 28); cout << "- Sastra Jepang (S1)";

	set_color(12, 0);
	//garis bagi setiap jalur
	for (int i = 0; i < 110; i++)
	{
		set_xy(20 + i, 30);
		cout << char(22);
	}
	set_color(10, 0);
	set_xy(20, 32); cout << "- Ilmu Politik(S1)";
	set_xy(20, 33); cout << "- Sosiologi (S1)";
	set_xy(20, 34); cout << "- Psikologi (S1)";

	set_color(12, 0);
	//garis bagi setiap jalur
	for (int i = 0; i < 110; i++)
	{
		set_xy(20 + i, 36);
		cout << char(22);
	}

	set_color(12, 0);
	//garis vertikal pembagi 
	for (int i = 0; i < 16; i++)
	{
		set_xy(50, 21 + i);
		cout << char(222);
	}
	set_color(10, 0);
	set_xy(54, 23); cout << "- Arsitektur (S1)";
	set_xy(54, 24); cout << "- Teknik Kimia (S1)";

	set_xy(54, 28); cout << "- Sastra Inggris (S1)";

	set_xy(54, 32); cout << "- Ilmu Komunikasi (S1)";
	set_xy(54, 33); cout << "- Manajemen (S1)";
	set_xy(54, 34); cout << "- Akuntansi (S1)";

	set_color(12, 0);
	//garis vertikal pembagi 
	for (int i = 0; i < 16; i++)
	{
		set_xy(79, 21 + i);
		cout << char(222);
	}
	set_color(10, 0);
	set_xy(83, 23); cout << "- Teknik Pertanian (S1)";
	set_xy(83, 24); cout << "- Teknik Mesin (S1)";

	set_xy(83, 28); cout << "- Sastra Perancis (S1)";

	set_xy(83, 32); cout << "- Perbankan (D4)";
	set_xy(83, 33); cout << "- Bahasa Inggris (D4)";
	set_xy(83, 34); cout << "- Akuntansi Sektor Publik (D4)";

	set_color(12, 0);
	//garis vertikal pembagi 
	for (int i = 0; i < 16; i++)
	{
		set_xy(115, 21 + i);
		cout << char(222);
	}
	set_color(10, 0);
	set_xy(119, 23); cout << "SMA - IPA";

	set_xy(119, 28); cout << "SMA - IPS";

	set_xy(119, 33); cout << "SMA - IPS";


	set_xy(20, 40); cout << "Masukkan angka [0] untuk kembali "; cout << char(16); cout << " ";

	set_color(15, 0);

	set_xy(55, 40); getline(cin, pilihanMenu);

	if (pilihanMenu == "0")
	{
		system("cls");
		return sub_menu_2();
	}
	else
	{
		system("cls");
		prodi();
	}

	set_xy(15, 45);
	system("pause");
	system("cls");

}

void hasilPMB_reguler()
{
	/*
		masuk ke fungsi header, kepala isi



	*/
	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	set_xy(61, 8); cout << "++ HASIL PMB JALUR REGULER ++";

	/*
		masuk ke fungsi bawah, isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";


	//mengkonversi tipe data string ke integer
	//dikarenakan menggunakan fungsi getline, maka tidak dapat dikombinasikan dengan fungsi cin
	//penggunaan getline harus bertipekan string
	string::size_type sz;
	int konversi1 = stoi(reg.jml_data, &sz);


	/*
		masuk ke fungsi menampilkan hasil PMB dengan cara membaca isi array.
		menggunakan konsep kuota pendaftaran terbatas.
		jika sudah lebih dari 3 kali perrulangan input data pendaftaran, sisanya auto tidak lolos.
	*/


	//menampilkan isi array struct jalur reguler
	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(7, 17 + i); cout << reg.nama[i];
	}

	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(40, 17 + i); cout << reg.asal_sekolah[i];
	}

	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(70, 17 + i); cout << reg.prodi[i];
	}

	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(100, 17 + i); cout << "Jalur Reguler";
	}


	for (int i = 1; i <= konversi1; i++)
	{
		reg.hasilkonversi_jarak[i] = stod(reg.jarak[i], &sz);
	}
	
	//fungsi untuk mengkondisikan 
	//maka nilai variabel array status akan diisi "Gagal. Jangan Bersedih !!"
	for (int i = 1; i <= konversi1; i++)
	{
		if (reg.hasilkonversi_jarak[i] <= 15.00)
		{
			reg.status[i] = "Selamat. Berhasil !!";
		}
		else
		{
			reg.status[i] = "Gagal. Jangan Bersedih !!";
		}

	}

	
	//untuk menampilkan hasil lolos/tidak lolos
	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(120, 17 + i); cout << reg.status[i];

	}


	//setting untuk garis bawah daftar peserta

	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";
	

	cout << endl << endl;
	cout << "     ";


	system("pause");
	system("cls");

	return sub_menu_2();
}

void hasilPMB_prestasi()
{
	/*
		masuk ke fungsi header, kepala isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	set_xy(61, 8); cout << "++ HASIL PMB JALUR PRESTASI ++";

	/*
		masuk ke fungsi bawah, isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";


	//mengkonversi tipe data string ke integer
	//dikarenakan menggunakan fungsi getline, maka tidak dapat dikombinasikan dengan fungsi cin
	//penggunaan getline harus bertipekan string
	string::size_type sz;
	int konversi2 = stoi(prest.jml_data, &sz);


	/*
		masuk ke fungsi menampilkan hasil PMB dengan cara membaca isi array.
		menggunakan konsep kuota pendaftaran terbatas.
		jika sudah lebih dari 3 kali perrulangan input data pendaftaran, sisanya auto tidak lolos.
	*/


	//menampilkan isi array struct jalur reguler
	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(7, 17 + i); cout << prest.nama[i];
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(40, 17 + i); cout << prest.asal_sekolah[i];
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(70, 17 + i); cout << prest.prodi[i];
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(100, 17 + i); cout << "Jalur Prestasi";
	}



	/*
		masuk ke fungsi konversi tipe data untuk digunakan sebagai parameter lolos / tidak lolos
	*/

	//mengkonversi string menjadi double dan disimpan kedalam array
	for (int i = 1; i <= konversi2; i++)
	{
		prest.hasilkonversi_nilai[i] = stod(prest.nilai[i], &sz);
	}

	
	//fungsi pengkondisian
	for (int i = 1; i <= konversi2; i++)
	{

		if (prest.hasilkonversi_nilai[i] >= 30.00 && prest.hasilkonversi_nilai[i] <= 40.00)
		{
			prest.status[i] = "Selamat. Berhasil !!";
		}
		else
		{
			prest.status[i] = "Gagal. Jangan Bersedih !!";
		}

	}


	//untuk menampilkan hasil lolos/tidak lolos
	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(120, 17 + i); cout << prest.status[i];

	}


	//setting untuk garis bawah daftar peserta

	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";



	cout << endl << endl;
	cout << "     ";


	system("pause");
	system("cls");

	return sub_menu_2();

}

void hasilPMB_bidikmisi()
{
	/*
		masuk ke fungsi header, kepala isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	set_xy(61, 8); cout << "++ HASIL PMB JALUR BIDIKMISI ++";

	/*
		masuk ke fungsi bawah, isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";


	//mengkonversi tipe data string ke integer
	//dikarenakan menggunakan fungsi getline, maka tidak dapat dikombinasikan dengan fungsi cin
	//penggunaan getline harus bertipekan string
	string::size_type sz;
	int konversi3 = stoi(bdkmisi.jml_data, &sz);


	/*
		masuk ke fungsi menampilkan hasil PMB dengan cara membaca isi array.
		menggunakan konsep kuota pendaftaran terbatas.
		jika sudah lebih dari 3 kali perrulangan input data pendaftaran, sisanya auto tidak lolos.
	*/


	//menampilkan isi array struct jalur reguler
	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(7, 17 + i); cout << bdkmisi.nama[i];
	}

	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(40, 17 + i); cout << bdkmisi.asal_sekolah[i];
	}

	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(70, 17 + i); cout << bdkmisi.prodi[i];
	}

	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(100, 17 + i); cout << "Jalur Bidikmisi";
	}



	/*
		masuk ke fungsi konversi tipe data untuk digunakan sebagai parameter lolos / tidak lolos
	*/

	//mengkonversi string menjadi double dan disimpan kedalam array
	for (int i = 1; i <= konversi3; i++)
	{
		bdkmisi.hasilkonversi_penghasilan[i] = stoi(bdkmisi.penghasilan[i], &sz);
	}


	//fungsi pengkondisian
	for (int i = 1; i <= konversi3; i++)
	{

		if (bdkmisi.hasilkonversi_penghasilan[i] <= 5000000)
		{
			bdkmisi.status[i] = "Selamat. Berhasil !!";
		}
		else if (bdkmisi.hasilkonversi_penghasilan[i] > 5000000)
		{
			bdkmisi.status[i] = "Gagal. Jangan Bersedih !!";
		}

	}


	//untuk menampilkan hasil lolos/tidak lolos
	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(120, 17 + i); cout << bdkmisi.status[i];

	}


	//setting untuk garis bawah daftar peserta

	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";

	cout << endl << endl;
	cout << "     ";



	system("pause");
	system("cls");

	return sub_menu_2();
}




void sub_menu_3()
{
	/*
		masuk ke fungsi header, kepala isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	/*
		masuk ke fungsi bawah / isi
	
	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 15);
		cout << char(220);
	}

	//Horisontal bawah 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 47);
		cout << char(220);
	}
	

	//vertikal kiri
	for (int i = 0; i < 34; i++)
	{
		set_xy(6, 15 + i);
		cout << char(222);
	}

	//vertikal kanan
	for (int i = 0; i < 34; i++)
	{
		set_xy(143, 15 + i);
		cout << char(222);
	}


	/*
		masuk ke fungsi pencarian
	
	*/

	set_xy(5, 13); cout << char(16); cout << " Pencarian Data Mahasiswa Baru"; 


	string cari; //variabel untuk menyimpan nama yang akan dicari dan dicocokkan dengan array.

	set_xy(15, 20); cout << "*NOTE : Mohon Diperhatikan Huruf Besar / Kecilnya. Penulisan Nama Harus (Lengkap)";
	set_xy(15, 18); cout << "Masukkan Nama Mahasiswa "; cout << char(16); cout << " "; getline(cin, cari);
	set_xy(15, 20); cout << "*NOTE : Mohon Diperhatikan Huruf Besar / Kecilnya. Penulisan Nama Harus (Lengkap)";


	for (int i = 1; i < size_array; i++)
	{
		if (cari == reg.nama[i])
		{
			set_xy(22, 23); cout << "1. Nama Mahasiswa Baru    = "; cout << reg.nama[i];
			set_xy(22, 25); cout << "2. Tempat, Tanggal Lahir  = "; cout << reg.ttl[i];
			set_xy(22, 27); cout << "3. Asal Sekolah           = "; cout << reg.asal_sekolah[i];
			set_xy(22, 29); cout << "4. Alamat                 = "; cout << reg.alamat[i];
			set_xy(22, 31); cout << "5. No. HP                 = "; cout << reg.nomor_telp[i];
			set_xy(22, 33); cout << "6. Agama                  = "; cout << reg.agama[i];
			set_xy(22, 35); cout << "7. Program Studi          = "; cout << reg.prodi[i];
			set_xy(22, 37); cout << "8. Jalur Masuk            = "; cout << "Jalur REGULER";

			set_xy(22, 41); cout << "Nama [" << reg.nama[i] << "] " << "ditemukan di indeks ke- " << i; 

			break;
		}

		if (cari == prest.nama[i])
		{
			set_xy(22, 23); cout << "1. Nama Mahasiswa Baru    = "; cout << prest.nama[i];
			set_xy(22, 25); cout << "2. Tempat, Tanggal Lahir  = "; cout << prest.ttl[i];
			set_xy(22, 27); cout << "3. Asal Sekolah           = "; cout << prest.asal_sekolah[i];
			set_xy(22, 29); cout << "4. Alamat                 = "; cout << prest.alamat[i];
			set_xy(22, 31); cout << "5. No. HP                 = "; cout << prest.nomor_telp[i];
			set_xy(22, 33); cout << "6. Agama                  = "; cout << prest.agama[i];
			set_xy(22, 35); cout << "7. Program Studi          = "; cout << prest.prodi[i];
			set_xy(22, 37); cout << "8. Nilai (NEM)            = "; cout << prest.nilai[i];
			set_xy(22, 39); cout << "9. Jalur Masuk            = "; cout << "Jalur PRESTASI";

			set_xy(22, 44); cout << "Nama [" << prest.nama[i] << "] " << "ditemukan di indeks ke- " << i;

			break;
		}

		if (cari == bdkmisi.nama[i])
		{
			set_xy(22, 23); cout << "1. Nama Mahasiswa Baru    = "; cout << bdkmisi.nama[i];
			set_xy(22, 25); cout << "2. Tempat, Tanggal Lahir  = "; cout << bdkmisi.ttl[i];
			set_xy(22, 27); cout << "3. Asal Sekolah           = "; cout << bdkmisi.asal_sekolah[i];
			set_xy(22, 29); cout << "4. Alamat                 = "; cout << bdkmisi.alamat[i];
			set_xy(22, 31); cout << "5. No. HP                 = "; cout << bdkmisi.nomor_telp[i];
			set_xy(22, 33); cout << "6. Agama                  = "; cout << bdkmisi.agama[i];
			set_xy(22, 35); cout << "7. Program Studi          = "; cout << bdkmisi.prodi[i];
			set_xy(22, 37); cout << "8. Penghasilan Orangtua   = "; cout << bdkmisi.penghasilan[i];
			set_xy(22, 39); cout << "9. Jalur Masuk            = "; cout << "Jalur BIDIKMISI";

			set_xy(22, 44); cout << "Nama [" << bdkmisi.nama[i] << "] " << "ditemukan di indeks ke- " << i;

			break;
		}


	}







	

	set_xy(5, 50);
	system("pause");
	system("cls");

	menu();
}

void sub_menu_4()
{
	/*
		masuk ke fungsi header, kepala



	*/

	//Horisontal atas 
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 60; i++)
	{
		set_xy(45 + i, 12);
		cout << char(22);
	}

	set_xy(57, 4); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 5);
		cout << char(220);
	}

	set_xy(68, 7); cout << "++ DATABASE ++";
	set_xy(62, 9); cout << "B E R I T A -- K A M P U S";
	set_xy(59, 10); cout << "Update Setiap Hari Senin & Selasa";


	/*
		masuk ke menu bawah. isi
	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";

	/*
		masuk ke fungsi menampilkan semua data;
	
	*/

	string::size_type sz; //deklrasi intuk konversi data

	int konversi1 = stoi(reg.jml_data, &sz);
	int konversi2 = stoi(prest.jml_data, &sz);
	int konversi3 = stoi(bdkmisi.jml_data, &sz);


	/*
		Nama Mahasiswa
	*/
	int counter1 = 17; //posisi y dimulai nama mahasiswa
	int counter2, counter3;

	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(7, counter1 + i); cout << reg.nama[i];
		counter1++;
		counter2 = counter1 + i; //menyimpan posisi y
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(7, counter2 + i); cout << prest.nama[i];
		counter2++;
		counter3 = counter2 + i;
	}


	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(7, counter3 + i); cout << bdkmisi.nama[i];
		counter3++;
	}

	/*
		Asal sekolah
	*/

	counter1 = 17; //posisi y direset
	counter2 = 0; //nilai di reset
	counter3 = 0; //nilai di reset

	for (int i = 1; i <= konversi1; i++)
	{
	
		set_xy(40, counter1 + i); cout << reg.asal_sekolah[i];
		counter1++;
		counter2 = counter1 + i; //menyimpan posisi y
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(40, counter2 + i); cout << prest.asal_sekolah[i];
		counter2++;
		counter3 = counter2 + i;
	}


	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(40, counter3 + i); cout << bdkmisi.asal_sekolah[i];
		counter3++;
	}


	/*
		program studi
	*/

	counter1 = 17; //posisi y direset
	counter2 = 0; //nilai di reset
	counter3 = 0; //nilai di reset

	for (int i = 1; i <= konversi1; i++)
	{

		set_xy(70, counter1 + i); cout << reg.prodi[i];
		counter1++;
		counter2 = counter1 + i; //menyimpan posisi y
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(70, counter2 + i); cout << prest.prodi[i];
		counter2++;
		counter3 = counter2 + i;
	}


	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(70, counter3 + i); cout << bdkmisi.prodi[i];
		counter3++;
	}


	/*
		jalur masuk
	*/

	counter1 = 17; //posisi y direset
	counter2 = 0; //nilai di reset
	counter3 = 0; //nilai di reset

	for (int i = 1; i <= konversi1; i++)
	{

		set_xy(100, counter1 + i); cout << "Jalur REGULER";
		counter1++;
		counter2 = counter1 + i; //menyimpan posisi y
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(100, counter2 + i); cout << "Jalur PRESTASI";
		counter2++;
		counter3 = counter2 + i;
	}


	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(100, counter3 + i); cout << "Jalur BIDIKMISI";
		counter3++;
	}


	/*
		HASIL STATUS lolos/tdk lolos

		JALUR REGULER
	*/


	for (int i = 1; i <= konversi1; i++)
	{
		reg.hasilkonversi_jarak[i] = stod(reg.jarak[i], &sz);
	}

	for (int i = 1; i <= konversi1; i++)
	{
		if (reg.hasilkonversi_jarak[i] <= 15.00)
		{
			reg.status[i] = "Selamat. Berhasil !!";
		}
		else
		{
			reg.status[i] = "Gagal. Jangan Bersedih !!";
		}

	}


	/*
		masuk ke fungsi konversi tipe data untuk digunakan sebagai parameter lolos / tidak lolos

		JALUR PRESTASI
	*/

	//mengkonversi string menjadi double dan disimpan kedalam array
	for (int i = 1; i <= konversi2; i++)
	{
		prest.hasilkonversi_nilai[i] = stod(prest.nilai[i], &sz);
	}


	//fungsi pengkondisian
	for (int i = 1; i <= konversi2; i++)
	{

		if (prest.hasilkonversi_nilai[i] >= 30.00 && prest.hasilkonversi_nilai[i] <= 40.00)
		{
			prest.status[i] = "Selamat. Berhasil !!";
		}
		else
		{
			prest.status[i] = "Gagal. Jangan Bersedih !!";
		}

	}


	/*
		masuk ke fungsi konversi tipe data untuk digunakan sebagai parameter lolos / tidak lolos

		JALUR BIDIKMISI
	*/

	//mengkonversi string menjadi double dan disimpan kedalam array
	for (int i = 1; i <= konversi3; i++)
	{
		bdkmisi.hasilkonversi_penghasilan[i] = stoi(bdkmisi.penghasilan[i], &sz);
	}


	//fungsi pengkondisian
	for (int i = 1; i <= konversi3; i++)
	{

		if (bdkmisi.hasilkonversi_penghasilan[i] <= 5000000)
		{
			bdkmisi.status[i] = "Selamat. Berhasil !!";
		}
		else if (bdkmisi.hasilkonversi_penghasilan[i] > 5000000)
		{
			bdkmisi.status[i] = "Gagal. Jangan Bersedih !!";
		}

	}

	/*
		fungsi untuk menampilkan array setelah di lakukan pengkondisian
	*/

	counter1 = 17; //posisi y direset
	counter2 = 0; //nilai di reset
	counter3 = 0; //nilai di reset

	for (int i = 1; i <= konversi1; i++)
	{

		set_xy(120, counter1 + i); cout << reg.status[i];
		counter1++;
		counter2 = counter1 + i; //menyimpan posisi y
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(120, counter2 + i); cout << prest.status[i];
		counter2++;
		counter3 = counter2 + i;
	}


	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(120, counter3 + i); cout << bdkmisi.status[i];
		counter3++;
	}


	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";


	cout << endl << endl;
	cout << "     ";




	//set_xy(5, 50);
	system("pause");
	system("cls");

	menu();

}



void sub_menu_5()
{
	set_color(11, 0);

	//Horisontal atas bingkai teks judul Univ
	for (int i = 0; i < 60; i++)
	{
		set_xy(31 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah bingkai teks judul Univ
	for (int i = 0; i < 61; i++)
	{
		set_xy(30 + i, 6);
		cout << char(22);
	}

	//horisontal bawah bingkai teks pilihan menu
	set_xy(31, 22);
	for (int i = 0; i < 60; i++)
	{
		cout << char(22);
	}


	//vertikal bingkai kanan teks pilihan menu
	for (int i = 0; i < 19; i++)
	{
		set_xy(90, 3 + i);
		cout << char(222);
	}

	//vertikal bingkai kiri teks pilihan menu
	for (int i = 0; i < 19; i++)
	{
		set_xy(30, 3 + i);
		cout << char(222);
	}

	set_color(6, 0);
	set_xy(44, 4); cout << "+++ Sorting Data Mahasiswa Baru +++";

	set_color(14, 0);
	
	set_xy(33, 8);  cout << "1. Sorting Ascending Jalur Reguler";
	set_xy(33, 9); cout << "2. Sorting Descending Jalur Reguler";
	set_xy(33, 11); cout << "3. Sorting Ascending Jalur Prestasi";
	set_xy(33, 12); cout << "4. Sorting Descending Jalur Prestasi";
	set_xy(33, 14); cout << "5. Sorting Ascending Jalur Bidikmisi";
	set_xy(33, 15); cout << "6. Sorting Descending Jalur Bidikmisi";
	set_xy(33, 17); cout << "7. BACK";

	set_color(15, 0);


	set_xy(36, 20); cout << "Masukan Pilihan Anda [1/2/3/5/6/7] "; cout << char(16); cout << " ";

	set_xy(73, 20); getline(cin, pilihanMenu);

	if (pilihanMenu == "1")
	{
		system("cls");
		return sort_ascending_reg();
	}
	else if (pilihanMenu == "2")
	{
		system("cls");
		return sort_descending_reg();
	}
	else if (pilihanMenu == "3")
	{
		system("cls");
		return sort_ascending_prest();
	}
	else if (pilihanMenu == "4")
	{
		system("cls");
		return sort_descending_prest();
	}
	else if (pilihanMenu == "5")
	{
		system("cls");
		sort_ascending_bdkmisi();
	}
	else if (pilihanMenu == "6")
	{
		system("cls");
		return sort_descending_bdkmisi();
	}
	else if (pilihanMenu == "7")
	{
		system("cls");
		menu();
	}
	else
	{
		system("cls");
		sub_menu_5();
	}



	set_xy(31, 21);
	system("pause");
	system("cls");

}

void sort_ascending_reg()
{
	/*
		masuk ke fungsi header, kepala isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	set_xy(59, 8); cout << "++ HASIL SORTING ASCENDING PMB  ++";

	/*
		masuk ke fungsi bawah, isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";



	
	string temp; //tampungan sementara untuk  switch

	string::size_type sz;
	int konversi1 = stoi(reg.jml_data, &sz);


	for (int i = 1; i <= konversi1; i++)
	{
		reg.jalur[i] = "Jalur Reguler";

	}

	
	for (int i = 1; i <= konversi1; i++)
	{
		for (int j = 1; j <= konversi1 - i; j++)
		{
			if (reg.nama[j] > reg.nama[j + 1])
			{
				temp = reg.nama[j];
				reg.nama[j] = reg.nama[j + 1];
				reg.nama[j + 1] = temp;

				temp = reg.asal_sekolah[j];
				reg.asal_sekolah[j] = reg.asal_sekolah[j + 1];
				reg.asal_sekolah[j + 1] = temp;

				temp = reg.prodi[j];
				reg.prodi[j] = reg.prodi[j + 1];
				reg.prodi[j + 1] = temp;

				temp = reg.status[j];
				reg.status[j] = reg.status[j + 1];
				reg.status[j + 1] = temp;

			}
		}
	}
	

	for (int i =0; i <= konversi1; i++)
	{
		set_xy(7, 17 + i);
		cout << reg.nama[i];
	}


	for (int i = 0; i <= konversi1; i++)
	{
		set_xy(40, 17 + i);
		cout << reg.asal_sekolah[i];

	}


	for (int i = 0; i <= konversi1; i++)
	{
		set_xy(70, 17 + i);
		cout << reg.prodi[i];

	}

	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(100, 17 + i);
		cout << reg.jalur[i];
	}

	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(120, 17 + i);
		cout << reg.status[i];

	}



	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";


	cout << endl << endl;
	cout << "     ";




	//set_xy(5, 50);
	system("pause");
	system("cls");

	return sub_menu_5();
}

void sort_descending_reg()
{
	/*
		masuk ke fungsi header, kepala isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	set_xy(59, 8); cout << "++ HASIL SORTING DESCENDING PMB  ++";

	/*
		masuk ke fungsi bawah, isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";

	string temp; //tampungan sementara untuk  switch

	string::size_type sz;
	int konversi1 = stoi(reg.jml_data, &sz);


	for (int i = 1; i <= konversi1; i++)
	{
		reg.jalur[i] = "Jalur Reguler";

	}

	for (int i = 1; i <= konversi1; i++)
	{
		for (int j = 1; j <= konversi1 - i; j++)
		{
			if (reg.nama[j] < reg.nama[j + 1])
			{
				temp = reg.nama[j];
				reg.nama[j] = reg.nama[j + 1];
				reg.nama[j + 1] = temp;

				temp = reg.asal_sekolah[j];
				reg.asal_sekolah[j] = reg.asal_sekolah[j + 1];
				reg.asal_sekolah[j + 1] = temp;

				temp = reg.prodi[j];
				reg.prodi[j] = reg.prodi[j + 1];
				reg.prodi[j + 1] = temp;

				temp = reg.status[j];
				reg.status[j] = reg.status[j + 1];
				reg.status[j + 1] = temp;

			}
		}
	}

	for (int i = 0; i <= konversi1; i++)
	{
		set_xy(7, 17 + i);
		cout << reg.nama[i];
	}


	for (int i = 0; i <= konversi1; i++)
	{
		set_xy(40, 17 + i);
		cout << reg.asal_sekolah[i];

	}


	for (int i = 0; i <= konversi1; i++)
	{
		set_xy(70, 17 + i);
		cout << reg.prodi[i];

	}

	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(100, 17 + i);
		cout << reg.jalur[i];
	}

	for (int i = 1; i <= konversi1; i++)
	{
		set_xy(120, 17 + i);
		cout << reg.status[i];

	}



	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";


	cout << endl << endl;
	cout << "     ";




	//set_xy(5, 50);
	system("pause");
	system("cls");

	return sub_menu_5();

}


void sort_ascending_prest()
{
	/*
		masuk ke fungsi header, kepala isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	set_xy(59, 8); cout << "++ HASIL SORTING ASCENDING PMB  ++";

	/*
		masuk ke fungsi bawah, isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";

	string temp; //tampungan sementara untuk  switch

	string::size_type sz;
	int konversi2 = stoi(prest.jml_data, &sz);

	for (int i = 1; i <= konversi2; i++)
	{
		prest.jalur[i] = "Jalur Prestasi";

	}

	for (int i = 1; i <= konversi2; i++)
	{
		for (int j = 1; j <= konversi2 - i; j++)
		{
			if (prest.nama[j] > prest.nama[j + 1])
			{
				temp = prest.nama[j];
				prest.nama[j] = prest.nama[j + 1];
				prest.nama[j + 1] = temp;

				temp = prest.asal_sekolah[j];
				prest.asal_sekolah[j] = prest.asal_sekolah[j + 1];
				prest.asal_sekolah[j + 1] = temp;

				temp = prest.prodi[j];
				prest.prodi[j] = prest.prodi[j + 1];
				prest.prodi[j + 1] = temp;

				temp = prest.status[j];
				prest.status[j] = prest.status[j + 1];
				prest.status[j + 1] = temp;

			}
		}
	}

	for (int i = 0; i <= konversi2; i++)
	{
		set_xy(7, 17 + i);
		cout << prest.nama[i];
	}


	for (int i = 0; i <= konversi2; i++)
	{
		set_xy(40, 17 + i);
		cout << prest.asal_sekolah[i];

	}


	for (int i = 0; i <= konversi2; i++)
	{
		set_xy(70, 17 + i);
		cout << prest.prodi[i];

	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(100, 17 + i);
		cout << prest.jalur[i];
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(120, 17 + i);
		cout << prest.status[i];

	}



	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";


	cout << endl << endl;
	cout << "     ";




	//set_xy(5, 50);
	system("pause");
	system("cls");

	return sub_menu_5();



}

void sort_descending_prest()
{
	/*
		masuk ke fungsi header, kepala isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	set_xy(59, 8); cout << "++ HASIL SORTING DESCENDING PMB  ++";

	/*
		masuk ke fungsi bawah, isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";

	string temp; //tampungan sementara untuk  switch

	string::size_type sz;
	int konversi2 = stoi(prest.jml_data, &sz);

	for (int i = 1; i <= konversi2; i++)
	{
		prest.jalur[i] = "Jalur Prestasi";

	}

	for (int i = 1; i <= konversi2; i++)
	{
		for (int j = 1; j <= konversi2 - i; j++)
		{
			if (prest.nama[j] < prest.nama[j + 1])
			{
				temp = prest.nama[j];
				prest.nama[j] = prest.nama[j + 1];
				prest.nama[j + 1] = temp;

				temp = prest.asal_sekolah[j];
				prest.asal_sekolah[j] = prest.asal_sekolah[j + 1];
				prest.asal_sekolah[j + 1] = temp;

				temp = prest.prodi[j];
				prest.prodi[j] = prest.prodi[j + 1];
				prest.prodi[j + 1] = temp;

				temp = prest.status[j];
				prest.status[j] = prest.status[j + 1];
				prest.status[j + 1] = temp;

			}
		}
	}

	for (int i = 0; i <= konversi2; i++)
	{
		set_xy(7, 17 + i);
		cout << prest.nama[i];
	}


	for (int i = 0; i <= konversi2; i++)
	{
		set_xy(40, 17 + i);
		cout << prest.asal_sekolah[i];

	}


	for (int i = 0; i <= konversi2; i++)
	{
		set_xy(70, 17 + i);
		cout << prest.prodi[i];

	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(100, 17 + i);
		cout << prest.jalur[i];
	}

	for (int i = 1; i <= konversi2; i++)
	{
		set_xy(120, 17 + i);
		cout << prest.status[i];

	}



	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";


	cout << endl << endl;
	cout << "     ";




	//set_xy(5, 50);
	system("pause");
	system("cls");

	return sub_menu_5();

}


void sort_ascending_bdkmisi()
{
	/*
		masuk ke fungsi header, kepala isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	set_xy(59, 8); cout << "++ HASIL SORTING ASCENDING PMB  ++";

	/*
		masuk ke fungsi bawah, isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";

	string temp; //tampungan sementara untuk  switch

	string::size_type sz;
	int konversi3 = stoi(bdkmisi.jml_data, &sz);

	for (int i = 1; i <= konversi3; i++)
	{
		bdkmisi.jalur[i] = "Jalur Bidikmisi";

	}

	for (int i = 1; i <= konversi3; i++)
	{
		for (int j = 1; j <= konversi3 - i; j++)
		{
			if (bdkmisi.nama[j] > bdkmisi.nama[j + 1])
			{
				temp = bdkmisi.nama[j];
				bdkmisi.nama[j] = bdkmisi.nama[j + 1];
				bdkmisi.nama[j + 1] = temp;

				temp = bdkmisi.asal_sekolah[j];
				bdkmisi.asal_sekolah[j] = bdkmisi.asal_sekolah[j + 1];
				bdkmisi.asal_sekolah[j + 1] = temp;

				temp = bdkmisi.prodi[j];
				bdkmisi.prodi[j] = bdkmisi.prodi[j + 1];
				bdkmisi.prodi[j + 1] = temp;

				temp = bdkmisi.status[j];
				bdkmisi.status[j] = bdkmisi.status[j + 1];
				bdkmisi.status[j + 1] = temp;

			}
		}
	}

	for (int i = 0; i <= konversi3; i++)
	{
		set_xy(7, 17 + i);
		cout << bdkmisi.nama[i];
	}


	for (int i = 0; i <= konversi3; i++)
	{
		set_xy(40, 17 + i);
		cout << bdkmisi.asal_sekolah[i];

	}


	for (int i = 0; i <= konversi3; i++)
	{
		set_xy(70, 17 + i);
		cout << bdkmisi.prodi[i];

	}

	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(100, 17 + i);
		cout << bdkmisi.jalur[i];
	}

	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(120, 17 + i);
		cout << bdkmisi.status[i];

	}



	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";


	cout << endl << endl;
	cout << "     ";




	//set_xy(5, 50);
	system("pause");
	system("cls");

	return sub_menu_5();


}

void sort_descending_bdkmisi()
{
	/*
		masuk ke fungsi header, kepala isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 2);
		cout << char(22);
	}

	//Horisontal bawah
	for (int i = 0; i < 52; i++)
	{
		set_xy(49 + i, 10);
		cout << char(22);
	}

	//garis vertikal kiri
	for (int i = 0; i < 9; i++)
	{
		set_xy(50, 2 + i);
		cout << char(222);
	}

	//garis vertikal kanan
	for (int i = 0; i < 9; i++)
	{
		set_xy(99, 2 + i);
		cout << char(222);
	}


	set_xy(57, 5); cout << "U N I V E R S I T Y   O F   T O K Y O";

	//underline teks "university of tokyo"
	for (int i = 0; i < 37; i++)
	{
		set_xy(57 + i, 6);
		cout << char(220);
	}

	set_xy(59, 8); cout << "++ HASIL SORTING DESCENDING PMB  ++";

	/*
		masuk ke fungsi bawah, isi



	*/

	//Horisontal atas 
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 14);
		cout << char(247);
	}

	//Horisontal bawah
	for (int i = 0; i < 140; i++)
	{
		set_xy(5 + i, 16);
		cout << char(247);
	}


	set_xy(7, 15); cout << "Nama Mahasiswa";
	set_xy(40, 15); cout << "Asal Sekolah";
	set_xy(70, 15); cout << "Program Studi";
	set_xy(100, 15); cout << "Jalur";
	set_xy(120, 15); cout << "Status";

	string temp; //tampungan sementara untuk  switch

	string::size_type sz;
	int konversi3 = stoi(bdkmisi.jml_data, &sz);

	for (int i = 1; i <= konversi3; i++)
	{
		bdkmisi.jalur[i] = "Jalur Bidikmisi";

	}

	for (int i = 1; i <= konversi3; i++)
	{
		for (int j = 1; j <= konversi3 - i; j++)
		{
			if (bdkmisi.nama[j] < bdkmisi.nama[j + 1])
			{
				temp = bdkmisi.nama[j];
				bdkmisi.nama[j] = bdkmisi.nama[j + 1];
				bdkmisi.nama[j + 1] = temp;

				temp = bdkmisi.asal_sekolah[j];
				bdkmisi.asal_sekolah[j] = bdkmisi.asal_sekolah[j + 1];
				bdkmisi.asal_sekolah[j + 1] = temp;

				temp = bdkmisi.prodi[j];
				bdkmisi.prodi[j] = bdkmisi.prodi[j + 1];
				bdkmisi.prodi[j + 1] = temp;

				temp = bdkmisi.status[j];
				bdkmisi.status[j] = bdkmisi.status[j + 1];
				bdkmisi.status[j + 1] = temp;

			}
		}
	}

	for (int i = 0; i <= konversi3; i++)
	{
		set_xy(7, 17 + i);
		cout << bdkmisi.nama[i];
	}


	for (int i = 0; i <= konversi3; i++)
	{
		set_xy(40, 17 + i);
		cout << bdkmisi.asal_sekolah[i];

	}


	for (int i = 0; i <= konversi3; i++)
	{
		set_xy(70, 17 + i);
		cout << bdkmisi.prodi[i];

	}

	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(100, 17 + i);
		cout << bdkmisi.jalur[i];
	}

	for (int i = 1; i <= konversi3; i++)
	{
		set_xy(120, 17 + i);
		cout << bdkmisi.status[i];

	}



	cout << endl << endl;
	cout << "     ";
	cout << "============================================================================================================================================";


	cout << endl << endl;
	cout << "     ";




	//set_xy(5, 50);
	system("pause");
	system("cls");

	return sub_menu_5();

}