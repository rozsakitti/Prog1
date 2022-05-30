#include <string.h>
#include <unistd.h>

#define MAX_KULCS 100 //100bájt a mérete
#define BUFFER_MERET 256

int main(int argc, char** argv){ //parancssori argumentum

	char kulcs[MAX_KULCS]; //karaktertömb
	char buffer[BUFFER_MERET]; //beleolvassuk a szövegünket

	int kulcs_index = 0; //ezen fogunk lépegetni -> a kulcs melyik karakterén vagyunk
	int olvasott_bajtok = 0;

	int kulcs_meret = strlen(argv[1]); //aktuális kulcsméret(hány karakter a kulcs), paramétere a kulcs
	strncpy(kulcs, argv[1], MAX_KULCS); //másolás-> hova,mit, hány karakterre

	while (( olvasott_bajtok = read ( 0, (void*) buffer, BUFFER_MERET ))){ //read fv: honnan: 0=strandard input,hova olvassuk, hány bájtot
		
		for (int i = 0; i < olvasott_bajtok; ++i){

			buffer[i] = buffer[i] ^ kulcs[kulcs_index]; //exor, nem hatvány!!!!
			kulcs_index = (kulcs_index + 1) % kulcs_meret;
		}

		write ( 1, buffer, olvasott_bajtok ); //hova, mit, mennyi bájtot
	}

	return 0;
}

/*
g++ e.c -o e
ls
more tiszta.txt
./e 12345678 < tiszta.txt > titkos.txt //átírányítás, a tisztát rátesszük a bemenetre, majd titkosba kiirja
more titkos.txt
./e 12345678 < titkos.txt //visszakapjuk a tiszta szöveget

*/
