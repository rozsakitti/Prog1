#define MAX_TITKOS 4096 //teljes szöveg
#define OLVASAS_BUFFER 256
#define KULCS_MERET 8
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>

double atlagos_szohossz(const char titkos[], int titkos_meret){  //kiszámolja az átlagos szóhosszt

	int sz = 0;

	for (int i = 0; i < titkos_meret; i++)
		if (titkos[i] == ' ') //szóközönként lépked
			++sz;

	return (double) titkos_meret / sz;

}

int tiszta_lehet (const char titkos[], int titkos_meret){ //jellegzetes szavakat keres

	double szohossz = atlagos_szohossz(titkos, titkos_meret);

	return szohossz < 9.0 && szohossz > 6.0 &&
		strcasestr (titkos, "nem") && strcasestr (titkos, "hogy") &&
		strcasestr (titkos, "az") && strcasestr (titkos, "Ha"); //ezek a szavak benne vannak-e a titkos tömbben

}

void exor (const char kulcs[], int kulcs_meret, //titkosítás
	char titkos[], int tikos_meret){

	int kulcs_index = 0;

	for (int i = 0; i < tikos_meret; i++){
		titkos[i] = titkos[i] ^ kulcs[kulcs_index];
		kulcs_index = (kulcs_index + 1) % kulcs_meret;
	}
}

int exor_tores(const char kulcs[], int kulcs_meret, //visszafejtés
	char titkos[], int titkos_meret){

	exor (kulcs, kulcs_meret, titkos, titkos_meret);

	return tiszta_lehet (titkos, titkos_meret); //fv: megnézi, h jó-e

}

int main(){

	char kulcs[KULCS_MERET]; //kulcstömb
	char titkos[MAX_TITKOS]; //tömb a titkosított szövegre
	char *p = titkos;
	int olvasott_bajtok;

	while ((olvasott_bajtok =  
		read ( 0, (void*) p, //standard inputrol a p-be olvasunk
		(p - titkos + OLVASAS_BUFFER < //megfelelő méretben olvasson be
		MAX_TITKOS) ? OLVASAS_BUFFER : titkos + MAX_TITKOS - p ))) 

	p += olvasott_bajtok;

	for (int i = 0; i < MAX_TITKOS - (p - titkos); ++i) //amibe nem olvastunk titkosított szöveget azt nullázza ki
		titkos[p - titkos + i] = '\0';
 
	for (int ii = '0'; ii <= '9'; ++ii)
		for (int ji = '0'; ji <= '9'; ++ji)
			for (int ki = '0';  ki <= '9'; ++ki)
				for (int li = '0'; li <= '9'; ++li)
					for (int mi = '0'; mi <= '9'; ++mi) 
						for (int ni = '0'; ni <= '9'; ++ni)
							for (int oi = '0'; oi <= '9'; ++oi)
								for (int pi = '0'; pi <= '9'; ++pi){
									kulcs[0] = ii;
									kulcs[1] = ji;
									kulcs[2] = ki;
									kulcs[3] = li;
									kulcs[4] = mi;
									kulcs[5] = ni;
									kulcs[6] = oi;
									kulcs[7] = pi;
					//visszafejtés
					if (exor_tores(kulcs, KULCS_MERET, titkos, p - titkos))
						printf(
							"Kulcs: [%c%c%c%c%c%c%c%c]\nTiszta szöveg: [%s\n]", //kiírjuk a kulcsot és a tiszta szöveget
							ii, ji, ki, li, mi, ni, oi, pi, titkos);

					exor (kulcs, KULCS_MERET, titkos, p - titkos);

				}

	return 0;
}
