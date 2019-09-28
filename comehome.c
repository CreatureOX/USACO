/*
ID:keepagr1
PROG:comehome
LANG:C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INF 60000	/* bigger than longest possible path */

int dist[52][52];

int char2num(char c){
    if(isupper(c)){
		return c-'A';
	}else{
		return c-'a'+26;
	}
}

int main(){
    FILE *fin, *fout;
    int i, j, k, npath, d;
    char a, b;
    int m;

    fin = fopen("comehome.in", "r");
    fout = fopen("comehome.out", "w");
    for(i=0; i<52; i++){
		for(j=0; j<52; j++){
			dist[i][j] = INF;
		}
	}
    for(i=0; i<26; i++){
		dist[i][i] = 0;
	}
    fscanf(fin, "%d\n", &npath);
    for(i=0; i<npath; i++) {
		fscanf(fin, "%c %c %d\n", &a, &b, &d);
		a = char2num(a);
		b = char2num(b);
		if(dist[a][b] > d){
			dist[a][b] = dist[b][a] = d;
		}
    }

    /* floyd warshall all pair shortest path */
    for(k=0; k<52; k++){
		for(i=0; i<52; i++){
			for(j=0; j<52; j++){
				if(dist[i][k]+dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}

    /* find closest cow */
    m = INF;
    a = '#';
    for(i='A'; i<='Y'; i++) {
		d = dist[char2num(i)][char2num('Z')];
		if(d < m) {
			m = d;
			a = i;
		}
    }
    fprintf(fout, "%c %d\n", a, m);
    return 0;
}