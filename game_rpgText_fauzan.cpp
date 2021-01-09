/*
dibuat oleh Muhammad Fauzan
Kelas 1B
20210053
Game Technology

Game simple Turn Based Style berbasis text
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// deklarasi global
int peran;
string nama, kelas;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// deklarasi fungsi
void buat_karakter();
void pemain();
void batas_pemain();
void serangan_pemain();
void musuh_goblin();
void lawan_goblin();
void musuh_guardian();
void lawan_guardian();
void musuh_naga();
void lawan_naga();
void musuh_vampire();
void lawan_vampire();
void berantem();
void game();
void lanjutkan();
void menang();
void kalah();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// data untuk status pemain dan musuh
struct stats
{
    int level;
    int darah_max;
    int darah;
    int darah_baru;
    int magic_point;
    int magic_max;
    int potion;
    int elixir;
} player, goblin, guardian, naga, vampire;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi utama
int main() 
{
	//membersihkan layar
    cout << "\033[2J\033[1;1H";
    // memanggil fungsi membuat karakter
    buat_karakter();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi pemain
void pemain()
{
    // data pemain
    if (peran == 1) {player.darah = 35; player.darah_max = 35; player.magic_point = 20; player.magic_max = 20;} // jika peran ksatria
    if (peran == 2) {player.darah = 40; player.darah_max = 40; player.magic_point = 15; player.magic_max = 15;} // jika peran petarung
    if (peran == 3) {player.darah = 30; player.darah_max = 30; player.magic_point = 25; player.magic_max = 25;} // jika peran pemanah
    if (peran == 4) {player.darah = 25; player.darah_max = 25; player.magic_point = 40; player.magic_max = 40;} // jika peran penyihir
    // data item
    player.potion = 5;
    player.elixir = 5;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi batas pemain
void batas_pemain()
{
	///////////////////////////////////////////////////////////////////////////////////////
	if (player.darah <= 0)                      {player.darah       = 0;}                // jika darah player di bawah 0 maka akan stuck di 0 (gak bisa min)
	if (player.darah >= player.darah_max)       {player.darah       = player.darah_max;} // jika darah player di atas max maka akan stuck di max (gak bisa lebih)
	if (player.magic_point <= 0)                {player.magic_point = 0;}                // jika magic player di bawah 0 maka akan stuck di 0 (gak bisa min)
	if (player.magic_point >= player.magic_max) {player.magic_point = player.magic_max;} // jika magic player di atas max maka akan stuck di max (gak bisa lebih)
	///////////////////////////////////////////////////////////////////////////////////////
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi gerakan pemain
void serangan_pemain() 
{
	// serangan ///////////////////////////////////////////////////
	cout << "serangan : " << endl;
	// jika peran ksatria
	if (peran == 1) {
		cout << "1. slash       2. X-cut" << endl;
		cout << "3. sky slash   4. double slash" << endl;
	}
	// jika peran petarung
	if (peran == 2) {
		cout << "1. punch         2. uppercut" << endl;
		cout << "3. skull break   4. ORA-ORA" << endl;
	}
	// jika peran pemanah
	if (peran == 3) {
		cout << "1. shoot       2. wing shoot" << endl;
		cout << "3. fire shoot  4. arrow rain" << endl;
	}
	// jika peran penyihir
	if (peran == 4) {
		cout << "1. light shoot   2. heal" << endl;
		cout << "3. electric      4. elemental attack" << endl;
	}
	// item //////////////////////////////////////////////////////
	cout << endl << "item : " << endl;
	cout << "5. potion "<< player.potion << "      6. elixir " << player.elixir <<  endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi musuh goblin
void musuh_goblin(int darah)
{
	// data goblin
	goblin.darah = darah;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi musuh guardian
void musuh_guardian(int darah)
{
	// data guardian
	guardian.darah = darah;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi musuh naga
void musuh_naga(int darah)
{
	// data naga
	naga.darah = darah;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi musuh vampire
void musuh_vampire(int darah)
{
	// data vapire
	vampire.darah     = darah;
	vampire.darah_max = 50;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi membuat karakter
void buat_karakter()
{   
    // input nama
    input_nama:
    cout << "masukkan nama [tidak boleh ada spasi] : ";
    cin  >> nama;
    
    // input peran
    input_peran:
    cout << endl << "1. ksatria\n2. petarung\n3. pemanah\n4. penyihir\npilih peran anda [1..4] : ";
    cin  >> peran;
    
    if      (peran == 1) {kelas = "ksatria"; } 
    else if (peran == 2) {kelas = "petarung";}
    else if (peran == 3) {kelas = "pemanah"; } 
    else if (peran == 4) {kelas = "penyihir";} 
    // jika input selain angka 1 - 4 maka akan input peran ulang
    else                 {cout << "\033[2J\033[1;1H"; cout << "input salah"; goto input_peran;}
    
    // panggil data pemain dari fungsi
    pemain();
    
    //membersihkan layar
    cout << "\033[2J\033[1;1H";
    // output data pemain
    cout << "selamat datang " << nama               << endl;
    cout << "===============" << endl               << endl;
    cout << "peran anda : "   << kelas              << endl;
    cout << "darah : "        << player.darah       << endl;
    cout << "magic : "        << player.magic_point << endl;

    // output dan input lanjutan
    lanjutan :
    int pilihan_lanjut;
    cout << "\n1. lanjutkan bermain  2. kembali \npilih [1..2] : ";
    cin  >> pilihan_lanjut;

    if      (pilihan_lanjut == 1) {game();}                                      // jika pilih nomor 1
    else if (pilihan_lanjut == 2) {cout << "\033[2J\033[1;1H"; goto input_nama;} // jika pilih nomor 2
    else                          {goto lanjutan;}                               // jika pilih nomor selain 1 dan 2
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string header = "anda melawan goblin\n\n";
// fungsi berantem lawan goblin
void lawan_goblin()
{
	berantem_goblin :
	// deklarasi
	int serangan;
	//membersihkan layar
    cout << "\033[2J\033[1;1H";

	// output goblin
	cout << header;
	cout << "Goblin\n";
	cout << "HP : " << goblin.darah << endl << endl << endl;

	// output player
	cout << nama    << endl;
	batas_pemain();
	cout << "HP : " << player.darah       << endl;
	cout << "MP : " << player.magic_point << endl << endl;
	// pause
	cout << "[klik enter untuk melanjutkan] ";
	cin.ignore();
	cin.get();

	// output gerakan
	serangan_pemain();
	cout << "pilih serangan [1..4] : ";
	cin  >> serangan;

	switch(serangan)
	{
		// serangan pertama
		case 1:
			// jika peran ksatria
			if (peran == 1) {header = "anda menggunakan slash\ngoblin -2\n\n";       goblin.darah -= 2;}
			// jika peran petarung
			if (peran == 2) {header = "anda menggunakan punch\ngoblin -3\n\n";       goblin.darah -= 3;}
			// jika peran pemanah
			if (peran == 3) {header = "anda menggunakan shoot\ngoblin -2\n\n";       goblin.darah -= 2;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 0) {header = "anda menggunakan light shoot\ngoblin -2\n\n"; goblin.darah -= 2; player.magic_point -= 1;}
			break;
		// serangan kedua
		case 2:
			// jika peran ksatria
			if (peran == 1) {header = "anda menggunakan x-cut\ngoblin -4\n\n";      goblin.darah -= 4;}
			// jika peran petarung
			if (peran == 2) {header = "anda menggunakan uppercut\ngoblin -5\n\n";   goblin.darah -= 5;}
			// jika peran pemanah
			if (peran == 3) {header = "anda menggunakan wing shoot\ngoblin -3\n\n"; goblin.darah -= 3;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 1) {header = "anda menggunakan heal\nHP anda +5\n\n"; player.darah += 5; player.magic_point -= 2;}
			break;
		// serangan ketiga
		case 3:
			// jika peran ksatria
			if (peran == 1 && player.magic_point > 1) {header = "anda menggunakan sky slash\ngoblin -6\n\n";   goblin.darah -= 6; player.magic_point -= 2;}
			// jika peran petarung
			if (peran == 2 && player.magic_point > 0) {header = "anda menggunakan skull break\ngoblin -8\n\n"; goblin.darah -= 8; player.magic_point -= 1;}
			// jika peran pemanah
			if (peran == 3 && player.magic_point > 1) {header = "anda menggunakan fire shoot\ngoblin -6\n\n";  goblin.darah -= 6; player.magic_point -= 2;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 2) {header = "anda menggunakan tornado\ngoblin -7\n\n";     goblin.darah -= 7; player.magic_point -= 3;}
			break;
		// serangan keempat
		case 4:
			// jika peran ksatria
			if (peran == 1 && player.magic_point > 4) {header = "anda menggunakan double slash\ngoblin -10\n\n";     goblin.darah -= 10; player.magic_point -= 5;}
			// jika peran petarung
			if (peran == 2 && player.magic_point > 1) {header = "anda menggunakan ORA-ORA\ngoblin -12\n\n";          goblin.darah -= 12; player.magic_point -= 2;}
			// jika peran pemanah
			if (peran == 3 && player.magic_point > 4) {header = "anda menggunakan arrow rain\ngoblin -9\n\n";        goblin.darah -=  9; player.magic_point -= 5;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 4) {header = "anda menggunakan elemental attack\ngoblin -13\n\n"; goblin.darah -= 13; player.magic_point -= 5;}
			break;
		// item potion
		case 5:
			if (player.potion > 0) {header = "anda menggunakan potion\nHP anda +20\n\n"; player.darah += 20; player.potion -= 1;}
			break;
		// item elixir
		case 6:
			if (player.elixir > 0) {header = "anda menggunakan elixir\nMP anda +10\n\n"; player.magic_point += 10; player.elixir -= 1;}
			break;
		// jika input selain 1-6
		default:
			goto berantem_goblin;
			break;
	}

	//membersihkan layar
    cout << "\033[2J\033[1;1H";
	// output goblin
	cout << header;
	cout << "Goblin\n";
	/////////////////////////////////////////////
	if (goblin.darah <= 0) {goblin.darah = 0;} // jika darah goblin di bawah 0 maka akan stuck di 0 (gak bisa min)
	/////////////////////////////////////////////
	cout << "HP : " << goblin.darah << endl << endl << endl;

	// output player
	cout << nama << endl;
	batas_pemain();
	cout << "HP : " << player.darah       << endl;
	cout << "MP : " << player.magic_point << endl << endl;
	lanjutkan();

	// serangan goblin
	srand(time(0)); // waktu random
	int gerakan_goblin = rand() % 2; // random 0 dan 1
	switch(gerakan_goblin)
	{
		case 0:  header = "goblin menggunakan spear\nanda -2\n\n"; player.darah -= 2; break; // serangan spear (0)
		default: header = "goblin menggunakan kick\nanda -1\n\n";  player.darah -= 1; break; // serangan kick (1)
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi berantem lawan guardian
string header2 = "anda melawan guardian\n\n";
void lawan_guardian()
{
	berantem_guardian :
	// deklarasi
	int serangan;
	//membersihkan layar
    cout << "\033[2J\033[1;1H";

	// output guardian
	cout << header2;
	cout << "guardian\n";
	cout << "HP : " << guardian.darah << endl << endl << endl;

	// output player
	cout << nama    << endl;
	batas_pemain();
	cout << "HP : " << player.darah       << endl;
	cout << "MP : " << player.magic_point << endl << endl;
	lanjutkan();

	// output gerakan
	serangan_pemain();
	cout << "pilih serangan [1..4] : ";
	cin  >> serangan;

	switch(serangan)
	{
		// serangan pertama
		case 1:
			// jika peran ksatria
			if (peran == 1) {header2 = "anda menggunakan slash\nguardian -2\n\n";       guardian.darah -= 2;}
			// jika peran petarung
			if (peran == 2) {header2 = "anda menggunakan punch\nguardian -3\n\n";       guardian.darah -= 3;}
			// jika peran pemanah
			if (peran == 3) {header2 = "anda menggunakan shoot\nguardian -2\n\n";       guardian.darah -= 2;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 0) {header2 = "anda menggunakan light shoot\nguardian -2\n\n"; guardian.darah -= 2; player.magic_point -= 1;}
			break;
		// serangan kedua
		case 2:
			// jika peran ksatria
			if (peran == 1) {header2 = "anda menggunakan x-cut\nguardian -4\n\n";      guardian.darah -= 4;}
			// jika peran petarung
			if (peran == 2) {header2 = "anda menggunakan uppercut\nguardian -5\n\n";   guardian.darah -= 5;}
			// jika peran pemanah
			if (peran == 3) {header2 = "anda menggunakan wing shoot\nguardian -3\n\n"; guardian.darah -= 3;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 1) {header2 = "anda menggunakan heal\nHP anda +5\n\n"; player.darah += 5; player.magic_point -= 2;}
			break;
		// serangan ketiga
		case 3:
			// jika peran ksatria
			if (peran == 1 && player.magic_point > 1) {header2 = "anda menggunakan sky slash\nguardian -6\n\n";   guardian.darah -= 6; player.magic_point -= 2;}
			// jika peran petarung
			if (peran == 2 && player.magic_point > 0) {header2 = "anda menggunakan skull break\nguardian -8\n\n"; guardian.darah -= 8; player.magic_point -= 1;}
			// jika peran pemanah
			if (peran == 3 && player.magic_point > 1) {header2 = "anda menggunakan fire shoot\nguardian -6\n\n";  guardian.darah -= 6; player.magic_point -= 2;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 2) {header2 = "anda menggunakan tornado\nguardian -7\n\n";     guardian.darah -= 7; player.magic_point -= 3;}
			break;
		// serangan keempat
		case 4:
			// jika peran ksatria
			if (peran == 1 && player.magic_point > 4) {header2 = "anda menggunakan double slash\nguardian -10\n\n";     guardian.darah -= 10; player.magic_point -= 5;}
			// jika peran petarung
			if (peran == 2 && player.magic_point > 1) {header2 = "anda menggunakan ORA-ORA\nguardian -12\n\n";          guardian.darah -= 12; player.magic_point -= 2;}
			// jika peran pemanah
			if (peran == 3 && player.magic_point > 4) {header2 = "anda menggunakan arrow rain\nguardian -9\n\n";        guardian.darah -=  9; player.magic_point -= 5;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 4) {header2 = "anda menggunakan elemental attack\nguardian -13\n\n"; guardian.darah -= 13; player.magic_point -= 5;}
			break;
		// item potion
		case 5:
			if (player.potion > 0) {header2 = "anda menggunakan potion\nHP anda +20\n\n"; player.darah += 20; player.potion -= 1;}
			break;
		// item elixir
		case 6:
			if (player.elixir > 0) {header2 = "anda menggunakan elixir\nMP anda +10\n\n"; player.magic_point += 10; player.elixir -= 1;}
			break;
		// jika input selain 1-6
		default:
			goto berantem_guardian;
			break;
	}

	//membersihkan layar
    cout << "\033[2J\033[1;1H";
	// output guardian
	cout << header2;
	cout << "guardian\n";
	/////////////////////////////////////////////////
	if (guardian.darah <= 0) {guardian.darah = 0;} // jika darah guardian di bawah 0 maka akan stuck di 0 (gak bisa min)
	/////////////////////////////////////////////////
	cout << "HP : " << guardian.darah << endl << endl << endl;

	// output player
	cout << nama << endl;
	batas_pemain();
	cout << "HP : " << player.darah       << endl;
	cout << "MP : " << player.magic_point << endl << endl;
	lanjutkan();

	// serangan guardian
	srand(time(0)); // waktu random
	int gerakan_guardian = rand() % 2; // random 0 dan 1
	switch(gerakan_guardian)
	{
		case 0:  header2 = "guardian menggunakan spear\nanda -5\n\n"; player.darah -= 5; break; // serangan spear (0)
		default: header2 = "guardian menggunakan kick\nanda -3\n\n";  player.darah -= 3; break; // serangan kick (1)
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi berantem lawan naga
string header3 = "anda melawan naga\n\n";
void lawan_naga()
{
	berantem_naga :
	// deklarasi
	int serangan;
	//membersihkan layar
    cout << "\033[2J\033[1;1H";

	// output naga
	cout << header3;
	cout << "naga\n";
	cout << "HP : " << naga.darah << endl << endl << endl;

	// output player
	cout << nama    << endl;
	batas_pemain();
	cout << "HP : " << player.darah       << endl;
	cout << "MP : " << player.magic_point << endl << endl;
	lanjutkan();

	// output gerakan
	serangan_pemain();
	cout << "pilih serangan [1..4] : ";
	cin  >> serangan;

	switch(serangan)
	{
		// serangan pertama
		case 1:
			// jika peran ksatria
			if (peran == 1) {header3 = "anda menggunakan slash\nnaga -2\n\n";       naga.darah -= 2;}
			// jika peran petarung
			if (peran == 2) {header3 = "anda menggunakan punch\nnaga -3\n\n";       naga.darah -= 3;}
			// jika peran pemanah
			if (peran == 3) {header3 = "anda menggunakan shoot\nnaga -2\n\n";       naga.darah -= 2;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 0) {header3 = "anda menggunakan light shoot\nnaga -2\n\n"; naga.darah -= 2; player.magic_point -= 1;}
			break;
		// serangan kedua
		case 2:
			// jika peran ksatria
			if (peran == 1) {header3 = "anda menggunakan x-cut\nnaga -4\n\n";      naga.darah -= 4;}
			// jika peran petarung
			if (peran == 2) {header3 = "anda menggunakan uppercut\nnaga -5\n\n";   naga.darah -= 5;}
			// jika peran pemanah
			if (peran == 3) {header3 = "anda menggunakan wing shoot\nnaga -3\n\n"; naga.darah -= 3;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 1) {header3 = "anda menggunakan heal\nHP anda +5\n\n"; player.darah += 5; player.magic_point -= 2;}
			break;
		// serangan ketiga
		case 3:
			// jika peran ksatria
			if (peran == 1 && player.magic_point > 1) {header3 = "anda menggunakan sky slash\nnaga -6\n\n";   naga.darah -= 6; player.magic_point -= 2;}
			// jika peran petarung
			if (peran == 2 && player.magic_point > 0) {header3 = "anda menggunakan skull break\nnaga -8\n\n"; naga.darah -= 8; player.magic_point -= 1;}
			// jika peran pemanah
			if (peran == 3 && player.magic_point > 1) {header3 = "anda menggunakan fire shoot\nnaga -6\n\n";  naga.darah -= 6; player.magic_point -= 2;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 2) {header3 = "anda menggunakan tornado\nnaga -7\n\n";     naga.darah -= 7; player.magic_point -= 3;}
			break;
		// serangan keempat
		case 4:
			// jika peran ksatria
			if (peran == 1 && player.magic_point > 4) {header3 = "anda menggunakan double slash\nnaga -10\n\n";     naga.darah -= 10; player.magic_point -= 5;}
			// jika peran petarung
			if (peran == 2 && player.magic_point > 1) {header3 = "anda menggunakan ORA-ORA\nnaga -12\n\n";          naga.darah -= 12; player.magic_point -= 2;}
			// jika peran pemanah
			if (peran == 3 && player.magic_point > 4) {header3 = "anda menggunakan arrow rain\nnaga -9\n\n";        naga.darah -=  9; player.magic_point -= 5;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 4) {header3 = "anda menggunakan elemental attack\nnaga -13\n\n"; naga.darah -= 13; player.magic_point -= 5;}
			break;
		// item potion
		case 5:
			if (player.potion > 0) {header3 = "anda menggunakan potion\nHP anda +20\n\n"; player.darah += 20; player.potion -= 1;}
			break;
		// item elixir
		case 6:
			if (player.elixir > 0) {header3 = "anda menggunakan elixir\nMP anda +10\n\n"; player.magic_point += 10; player.elixir -= 1;}
			break;
		// jika input selain 1-6
		default:
			goto berantem_naga;
			break;
	}

	//membersihkan layar
    cout << "\033[2J\033[1;1H";
	// output naga
	cout << header3;
	cout << "naga\n";
	//////////////////////////////////////////
	if (naga.darah <= 0) {naga.darah = 0;}  // jika darah naga di bawah 0 maka akan stuck di 0 (gak bisa min)
	//////////////////////////////////////////
	cout << "HP : " << naga.darah << endl << endl << endl;

	// output player
	cout << nama << endl;
	batas_pemain();
	cout << "HP : " << player.darah       << endl;
	cout << "MP : " << player.magic_point << endl << endl;
	lanjutkan();

	// serangan naga
	srand(time(0)); // waktu random
	int gerakan_naga = rand() % 2; // random 0 dan 1
	switch(gerakan_naga)
	{
		case 0:  header3 = "naga menggunakan fire breath\nanda -10\n\n"; player.darah -= 10; break; // serangan fire breath (0)
		default: header3 = "naga menggunakan claw\nanda -5\n\n";         player.darah -= 5;  break; // serangan claw (1)
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi berantem lawan vampire
string header4 = "anda melawan vampire\n\n";
void lawan_vampire()
{
	berantem_vampire :
	// deklarasi
	int serangan;
	//membersihkan layar
    cout << "\033[2J\033[1;1H";

	// output vampire
	cout << header4;
	cout << "vampire\n";
	cout << "HP : " << vampire.darah << endl << endl << endl;

	// output player
	cout << nama    << endl;
	batas_pemain();
	cout << "HP : " << player.darah       << endl;
	cout << "MP : " << player.magic_point << endl << endl;
	lanjutkan();

	// output gerakan
	serangan_pemain();
	cout << "pilih serangan [1..4] : ";
	cin  >> serangan;

	switch(serangan)
	{
		// serangan pertama
		case 1:
			// jika peran ksatria
			if (peran == 1) {header4 = "anda menggunakan slash\nvampire -2\n\n";       vampire.darah -= 2;}
			// jika peran petarung
			if (peran == 2) {header4 = "anda menggunakan punch\nvampire -3\n\n";       vampire.darah -= 3;}
			// jika peran pemanah
			if (peran == 3) {header4 = "anda menggunakan shoot\nvampire -2\n\n";       vampire.darah -= 2;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 0) {header4 = "anda menggunakan light shoot\nvampire -2\n\n"; vampire.darah -= 2; player.magic_point -= 1;}
			break;
		// serangan kedua
		case 2:
			// jika peran ksatria
			if (peran == 1) {header4 = "anda menggunakan x-cut\nvampire -4\n\n";      vampire.darah -= 4;}
			// jika peran petarung
			if (peran == 2) {header4 = "anda menggunakan uppercut\nvampire -5\n\n";   vampire.darah -= 5;}
			// jika peran pemanah
			if (peran == 3) {header4 = "anda menggunakan wing shoot\nvampire -3\n\n"; vampire.darah -= 3;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 1) {header4 = "anda menggunakan heal\nHP anda +5\n\n"; player.darah += 5; player.magic_point -= 2;}
			break;
		// serangan ketiga
		case 3:
			// jika peran ksatria
			if (peran == 1 && player.magic_point > 1) {header4 = "anda menggunakan sky slash\nvampire -6\n\n";   vampire.darah -= 6; player.magic_point -= 2;}
			// jika peran petarung
			if (peran == 2 && player.magic_point > 0) {header4 = "anda menggunakan skull break\nvampire -8\n\n"; vampire.darah -= 8; player.magic_point -= 1;}
			// jika peran pemanah
			if (peran == 3 && player.magic_point > 1) {header4 = "anda menggunakan fire shoot\nvampire -6\n\n";  vampire.darah -= 6; player.magic_point -= 2;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 2) {header4 = "anda menggunakan tornado\nvampire -7\n\n";     vampire.darah -= 7; player.magic_point -= 3;}
			break;
		// serangan keempat
		case 4:
			// jika peran ksatria
			if (peran == 1 && player.magic_point > 4) {header4 = "anda menggunakan double slash\nvampire -10\n\n";     vampire.darah -= 10; player.magic_point -= 5;}
			// jika peran petarung
			if (peran == 2 && player.magic_point > 1) {header4 = "anda menggunakan ORA-ORA\nvampire -12\n\n";          vampire.darah -= 12; player.magic_point -= 2;}
			// jika peran pemanah
			if (peran == 3 && player.magic_point > 4) {header4 = "anda menggunakan arrow rain\nvampire -9\n\n";        vampire.darah -=  9; player.magic_point -= 5;}
			// jika peran penyihir
			if (peran == 4 && player.magic_point > 4) {header4 = "anda menggunakan elemental attack\nvampire -13\n\n"; vampire.darah -= 13; player.magic_point -= 5;}
			break;
		// item potion
		case 5:
			if (player.potion > 0) {header4 = "anda menggunakan potion\nHP anda +20\n\n"; player.darah += 20; player.potion -= 1;}
			break;
		// item elixir
		case 6:
			if (player.elixir > 0) {header4 = "anda menggunakan elixir\nMP anda +10\n\n"; player.magic_point += 10; player.elixir -= 1;}
			break;
		// jika input selain 1-6
		default:
			goto berantem_vampire;
			break;
	}

	//membersihkan layar
    cout << "\033[2J\033[1;1H";
	// output vampire
	cout << header4;
	cout << "vampire\n";
	///////////////////////////////////////////////////////////////////////////////
	if (vampire.darah <= 0)                 {vampire.darah = 0;}                 // jika darah vampire di bawah 0 maka akan stuck di 0 (gak bisa min)
	if (vampire.darah >= vampire.darah_max) {vampire.darah = vampire.darah_max;} // jika darah vampire di bawah 0 maka akan stuck di 0 (gak bisa min)
	///////////////////////////////////////////////////////////////////////////////
	cout << "HP : " << vampire.darah << endl << endl << endl;

	// output player
	cout << nama << endl;
	batas_pemain();
	cout << "HP : " << player.darah       << endl;
	cout << "MP : " << player.magic_point << endl << endl;
	lanjutkan();

	// serangan vampire
	srand(time(0)); // waktu random
	int gerakan_vampire = rand() % 4; // random 0 - 3
	switch(gerakan_vampire)
	{
		case 0:  header4 = "vampire menggunakan fire ball\nanda -10\n\n";       player.darah -= 10; break; // serangan fire ball (0)
		case 1:  header4 = "vampire menggunakan electric\nanda -10\n\n";        player.darah -= 10; break; // serangan electrick (1)
		case 2:  header4 = "vampire menggunakan dark power\nvampire +5\n\n";    vampire.darah += 5; break; // serangan dark power (2)
		case 3:  header4 = "vampire menggunakan suck\nanda -3  vampire +5\n\n"; player.darah -= 3; vampire.darah += 5; break; // serangan suck (3)
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void berantem(int musuh /*1.goblin 2.guardian 3.naga 4.vampire*/)
{
	switch(musuh)
	{
		// goblin
		case 1:
			musuh_goblin(5);
			gelut_goblin:
		    lawan_goblin();
		    //////////////////////////////////////////////////////////////////////////////////////////////
			if      (goblin.darah <= 0) {menang();}          // jika darah goblin 0 maka menang
			else if (player.darah <= 0) {kalah(); }          // jika darah player 0 maka kalah
		  	else                        {goto gelut_goblin;} // jika darah masih tersisa maka lanjutkan
		  	//////////////////////////////////////////////////////////////////////////////////////////////
			break;
		// guardian
		case 2:
			musuh_guardian(20);
			gelut_guardian:
		    lawan_guardian();
		    //////////////////////////////////////////////////////////////////////////////////////////////
			if      (guardian.darah <= 0) {menang();}             // jika darah guardian 0 maka menang
			else if (player.darah <= 0)   {kalah(); }             // jika darah player 0 maka kalah
		  	else                          {goto gelut_guardian;}  // jika darah masih tersisa maka lanjutkan
		  	//////////////////////////////////////////////////////////////////////////////////////////////
			break;
		// naga
		case 3:
			musuh_naga(40);
			gelut_naga:
		    lawan_naga();
		    //////////////////////////////////////////////////////////////////////////////////////////////
			if      (naga.darah <= 0)  {menang();}         // jika darah naga 0 maka menang
			else if (player.darah <= 0){kalah(); }         // jika darah player 0 maka kalah
		  	else                       {goto gelut_naga;}  // jika darah masih tersisa maka lanjutkan
		  	//////////////////////////////////////////////////////////////////////////////////////////////
			break;
		// vampire
		case 4:
			musuh_vampire(70);
			gelut_vampire:
		    lawan_vampire();
		    //////////////////////////////////////////////////////////////////////////////////////////////
			if      (vampire.darah <= 0){menang();}            // jika darah vampire 0 maka menang
			else if (player.darah <= 0) {kalah(); }            // jika darah player 0 maka kalah
		  	else                        {goto gelut_vampire;}  // jika darah masih tersisa maka lanjutkan
		  	//////////////////////////////////////////////////////////////////////////////////////////////
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fungsi game berlangsung
void game()
{
	// panggil fungsi untuk memanggil datanya
	pemain();

	//membersihkan layar
    cout << "\033[2J\033[1;1H";

    // intro cerita
	cout << "Suatu hari di suatu kerajaan seorang putri diculik oleh vampire yang jahat.\nAnda adalah seorang yang dapat dipercaya untuk menyelamatkan putri.\n\n";
	lanjutkan();

	// jalan pertama
	int jalan1;
	//membersihkan layar
    cout << "\033[2J\033[1;1H";

	cout << "=================================================" << endl << endl << endl;


	cout << "===================        ======================" << endl;
	cout << "                  |        |                     " << endl;
	cout << "                  |        |                     " << endl;
	cout << "                  |        |                     " << endl;
	cout << "                  |   x    |                     " << endl;
	cout << "                  |        |                     " << endl;
	cout << "                  |        |                     " << endl << endl;

	cout << "anda berada di jalan pertigaan, mana jalan yang anda pilih ?" << endl;
	cout << "1. kiri     2. kanan" << endl;
	cout << "pilih [1..2] "; cin  >> jalan1;

	//membersihkan layar
   	cout << "\033[2J\033[1;1H";

	switch(jalan1)
	{
		// jalan ke kiri
		case 1:
			cout << "=================================================" << endl << endl;

			cout << "  x                                              " << endl;
			cout << "===================        ======================" << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl << endl;

			cout << "anda memilih jalan kiri.\nanda bertemu dengan goblin.\n\n";
			lanjutkan();
			break;
		// jalan ke kanan
		default:
			cout << "=================================================" << endl << endl;

			cout << "                                             x   " << endl;
			cout << "===================        ======================" << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl << endl;

			cout << "anda memilih jalan kanan.\nanda menemukan 1 potion.\n\n"; player.potion += 1;
			lanjutkan();

			//membersihkan layar
   			cout << "\033[2J\033[1;1H";

   			cout << "=================================================" << endl << endl;

			cout << "  x                                              " << endl;
			cout << "===================        ======================" << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl;
			cout << "                  |        |                     " << endl << endl;

			cout << "anda melanjutkan ke jalan kiri.\nanda bertemu dengan goblin.\n\n";
			lanjutkan();
	}

    // lawan goblin
    berantem(1);
  	lanjutkan();

	// jalan kedua
	int jalan2;
	//membersihkan layar
    cout << "\033[2J\033[1;1H";

    cout << "   |        |                     " << endl;
	cout << "   |        |                     " << endl;
	cout << "   |        |                     " << endl;
	cout << "   |        |                     " << endl;
	cout << "   |        |                     " << endl;
	cout << "   |        |                     " << endl;
	cout << "   |        ======================" << endl;
	cout << "   |                              " << endl;
	cout << "   |                              " << endl;
	cout << "   |        ======================" << endl;
	cout << "   |        |                     " << endl;
	cout << "   |        |                     " << endl;
	cout << "   |        |                     " << endl;
	cout << "   |   x    |                     " << endl;
	cout << "   |        |                     " << endl;
	cout << "   |        |                     " << endl << endl;

	cout << "anda berada di jalan pertigaan, mana jalan yang anda pilih ?" << endl;
	cout << "1. lurus     2. kanan" << endl;
	cout << "pilih [1..2] "; cin  >> jalan2;

	//membersihkan layar
    cout << "\033[2J\033[1;1H";

	switch(jalan2)
	{
		// jalan lurus
		case 1:
			cout << "   |        |                     " << endl;
			cout << "   |   x    |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        ======================" << endl;
			cout << "   |                              " << endl;
			cout << "   |                              " << endl;
			cout << "   |        ======================" << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl << endl;

			cout << "anda memilih jalan kanan.\nanda menemukan 1 elixir.\n\n"; player.elixir += 1;
			lanjutkan();

			//membersihkan layar
		    cout << "\033[2J\033[1;1H";

		    cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        ======================" << endl;
			cout << "   |                              " << endl;
			cout << "   |                         x    " << endl;
			cout << "   |        ======================" << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl << endl;

			cout << "anda melanjutkan ke jalan kanan.\nanda bertemu dengan goblin.\n\n";
			lanjutkan();
			break;

		default:
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        ======================" << endl;
			cout << "   |                              " << endl;
			cout << "   |                         x    " << endl;
			cout << "   |        ======================" << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl;
			cout << "   |        |                     " << endl << endl;

			cout << "anda memilih jalan kanan.\nanda bertemu dengan goblin.\n\n";
			lanjutkan();
			break;
	}

	// lawan goblin
	berantem(1);
  	lanjutkan();

	//membersihkan layar
    cout << "\033[2J\033[1;1H";
	// jembatan
    cout << "			===================			 " << endl;
	cout << "	^		|                 |			 " << endl;
	cout << "			|                 |	^		 " << endl;
	cout << "			===================		^	 " << endl;
	cout << "			|    o       o    |			 " << endl;
	cout << "		^	|                 |			 " << endl;
	cout << "	^		===================		^	 " << endl;
	cout << "			|                 |			 " << endl;
	cout << "			|                 |			 " << endl;
	cout << "			===================			 " << endl;
	cout << "			|                 |	^		 " << endl;
	cout << "		^	|                 |			^" << endl;
	cout << "			===================			 " << endl;
	cout << "			|                 |			 " << endl;
	cout << "	^		|                 |		^	 " << endl;
	cout << "		^	===================			 " << endl;
	cout << "			|        x        |			 " << endl;
	cout << "			|                 |			^" << endl;
	cout << "			===================          " << endl << endl;
	
	cout << "anda berada di jembatan menuju istana vampire.\nanda bertemu dengan 2 guardian." << endl;
	lanjutkan();

	// lawan guardian
	berantem(2);
  	lanjutkan();

	// lawan guardian
	berantem(2);
  	lanjutkan();

	//membersihkan layar
    cout << "\033[2J\033[1;1H";
	// istanan pertama
    cout << "             |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "             |   o    |"     << endl;
	cout << "             |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "         =====        =====" << endl;
	cout << "         |       x        |" << endl;
	cout << "         |                |" << endl << endl;

	cout << "anda masuk ke istana vampire.\nanda bertemu dengan guardian." << endl;

	lanjutkan();

	// lawan guardian
	berantem(2);
  	lanjutkan();

	// istanan kedua
	int istana2;
	//membersihkan layar
    cout << "\033[2J\033[1;1H";
	
    cout << "             |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "  ========   |        |"     << endl;
	cout << " |        |  |        |"     << endl;
	cout << " |         ===        |"     << endl;
	cout << " |                    |"     << endl;
	cout << " |         ===        |"     << endl;
	cout << " |        |  |        |"     << endl;
	cout << "  ========   |        |"     << endl;
	cout << "             |        |"     << endl;
	cout << "             |   x    |"     << endl;
	cout << "             |        |"     << endl << endl;

	cout << "anda melanjutkan ke koridor istana.\nada ruangan di sebelah kiri dan jalan lurus.\nmana jalan yang anda pilih ?" << endl;
	cout << "1. kiri     2. lurus" << endl;
	cout << "pilih [1..2] "; cin  >> istana2;

	switch(istana2)
	{
		// ruangan kiri
		case 1:
			//membersihkan layar
		    cout << "\033[2J\033[1;1H";
			
		    cout << "             |        |"     << endl;
			cout << "             |        |"     << endl;
			cout << "             |        |"     << endl;
			cout << "  ========   |        |"     << endl;
			cout << " |        |  |        |"     << endl;
			cout << " |         ===        |"     << endl;
			cout << " |   x                |"     << endl;
			cout << " |         ===        |"     << endl;
			cout << " |        |  |        |"     << endl;
			cout << "  ========   |        |"     << endl;
			cout << "             |        |"     << endl;
			cout << "             |        |"     << endl;
			cout << "             |        |"     << endl << endl;

			cout << "anda memilih ke ruangan kiri.\nanda menemukan 5 potion dan 3 elixir.\n\n"; player.potion += 5; player.elixir += 3;
			lanjutkan();

			//membersihkan layar
		    cout << "\033[2J\033[1;1H";
			
		    cout << "             |        |"     << endl;
			cout << "             |    x   |"     << endl;
			cout << "             |        |"     << endl;
			cout << "  ========   |        |"     << endl;
			cout << " |        |  |        |"     << endl;
			cout << " |         ===        |"     << endl;
			cout << " |                    |"     << endl;
			cout << " |         ===        |"     << endl;
			cout << " |        |  |        |"     << endl;
			cout << "  ========   |        |"     << endl;
			cout << "             |        |"     << endl;
			cout << "             |        |"     << endl;
			cout << "             |        |"     << endl << endl;

			cout << "anda melanjutkan ke jalan.\nanda bertemu dengan guardian." << endl;
			lanjutkan();
			break;
		// lurus
		default:
			//membersihkan layar
		    cout << "\033[2J\033[1;1H";
			
		    cout << "             |        |"     << endl;
			cout << "             |    x   |"     << endl;
			cout << "             |        |"     << endl;
			cout << "  ========   |        |"     << endl;
			cout << " |        |  |        |"     << endl;
			cout << " |         ===        |"     << endl;
			cout << " |                    |"     << endl;
			cout << " |         ===        |"     << endl;
			cout << " |        |  |        |"     << endl;
			cout << "  ========   |        |"     << endl;
			cout << "             |        |"     << endl;
			cout << "             |        |"     << endl;
			cout << "             |        |"     << endl << endl;

			cout << "anda memilih jalan lurus.\nanda bertemu dengan guardian." << endl;

			lanjutkan();
			break;
	}

	// lawan guardian
	berantem(2);
  	lanjutkan();

  	// istanan ketiga
	int istana3;
	//membersihkan layar
    cout << "\033[2J\033[1;1H";
	
    cout << "             |        |            " << endl;
	cout << "             |        |            " << endl;
	cout << "             |        |            " << endl;
	cout << "             |        |   ======== " << endl;
	cout << "             |        |  |        |" << endl;
	cout << "             |        ===         |" << endl;
	cout << "             |                    |" << endl;
	cout << "             |        ===         |" << endl;
	cout << "             |        |  |        |" << endl;
	cout << "             |        |   ======== " << endl;
	cout << "             |        |            " << endl;
	cout << "             |   x    |            " << endl;
	cout << "             |        |            " << endl << endl;

	cout << "anda melanjutkan ke koridor istana.\nada ruangan di sebelah kanan dan jalan lurus.\nmana jalan yang anda pilih ?" << endl;
	cout << "1. lurus     2. kanan" << endl;
	cout << "pilih [1..2] "; cin  >> istana3;

	switch(istana3)
	{
		// lurus
		case 1:
			//membersihkan layar
		    cout << "\033[2J\033[1;1H";
			
		    cout << "             |        |            " << endl;
			cout << "             |   x    |            " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |   ======== " << endl;
			cout << "             |        |  |        |" << endl;
			cout << "             |        ===         |" << endl;
			cout << "             |                    |" << endl;
			cout << "             |        ===         |" << endl;
			cout << "             |        |  |        |" << endl;
			cout << "             |        |   ======== " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |            " << endl << endl;

			cout << "anda memilih jalan lurus.\nanda bertemu dengan naga penjaga istana." << endl;
			lanjutkan();
			break;
		// ruangan kanan
		default:
			//membersihkan layar
		    cout << "\033[2J\033[1;1H";
			
		    cout << "             |        |            " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |   ======== " << endl;
			cout << "             |        |  |        |" << endl;
			cout << "             |        ===         |" << endl;
			cout << "             |               x    |" << endl;
			cout << "             |        ===         |" << endl;
			cout << "             |        |  |        |" << endl;
			cout << "             |        |   ======== " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |            " << endl << endl;

			cout << "anda memilih ke ruangan kiri.\nanda menemukan 3 potion dan 5 elixir.\n\n"; player.potion += 3; player.elixir += 5;
			lanjutkan();

			//membersihkan layar
		    cout << "\033[2J\033[1;1H";
			
		    cout << "             |        |            " << endl;
			cout << "             |   x    |            " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |   ======== " << endl;
			cout << "             |        |  |        |" << endl;
			cout << "             |        ===         |" << endl;
			cout << "             |                    |" << endl;
			cout << "             |        ===         |" << endl;
			cout << "             |        |  |        |" << endl;
			cout << "             |        |   ======== " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |            " << endl;
			cout << "             |        |            " << endl << endl;

			cout << "anda melanjutkan ke jalan.\nanda bertemu dengan naga penjaga istana." << endl;
			lanjutkan();
			break;
	}

	// lawan naga
	berantem(3);
  	lanjutkan();

	//membersihkan layar
    cout << "\033[2J\033[1;1H";
	// istanan keempat
    cout << "  ================================ " << endl;
	cout << " |                                | " << endl;
	cout << " |                                | " << endl;
	cout << " |               v                | " << endl;
	cout << " |                                | " << endl;
	cout << " |                                | " << endl;
	cout << " |                                | " << endl;
	cout << " |                                | " << endl;
	cout << " |               X                | " << endl;
	cout << " |                                | " << endl;
	cout << "  ===========          =========== " << endl;
	cout << "             |        | " << endl;
	cout << "             |        | " << endl << endl;

	cout << "anda berhasil menemukan vampire.\nanda melawannya." << endl;
	lanjutkan();

	// lawan vampire
	berantem(4);
  	lanjutkan();

  	//membersihkan layar
    cout << "\033[2J\033[1;1H";
  	// tamat
  	cout << "selamat " << nama << "." << endl << endl;
  	cout << "anda berhasil menyelamatkan putri dari vampire yang jahat." << endl;
  	cout << "putri dan semua rakyat kerajaan hidup dengan tenang." << endl;
  	cout << "beristirahatlah pahlawan...." << endl << endl;
  	cout << "=====" << endl;
  	cout << "TAMAT" << endl;
  	cout << "=====" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void lanjutkan()
{
	// pause
	cout << "[klik enter untuk melanjutkan] ";
	cin.ignore();
	cin.get();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menang()
{
	cout << "anda menang" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void kalah()
{                       
	cout << "anda kalah" << endl; 
	exit(0);
}