 /*
ID: keepagr1
LANG: C
PROG: preface
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char *encode[] = {
	"", "I", "II", "III", "IV",
		"V", "VI", "VII", "VIII", "IX",
};
 
char *romandigit(int d, char *ivx) //返还字符指针，指向一个字符
{
	char *s, *p;
	static char str[10];
	
	for(s=encode[d%10], p=str; *s; s++, p++) {
		switch(*s){
		case 'I':
			*p = ivx[0];break;
		case 'V':
			*p = ivx[1];break;
		case 'X':
			*p = ivx[2];break;
		}
	}
	*p = '\0';
	return str;
}
 
char *roman(int n){
	static char buf[20];	
	strcpy(buf, "");
	strcat(buf, romandigit(n/1000,"M"));
	strcat(buf, romandigit(n/100,"CDM"));
	strcat(buf, romandigit(n/10,"XLC"));
	strcat(buf, romandigit(n,"IVX"));
	return buf;
}
 
int main(){
	int i, n;
	char *s;
	int count[256];
	
	FILE *fin = fopen("preface.in", "r");
	FILE *fout = fopen("preface.out", "w");
	
	fscanf(fin,"%d",&n);
	for(s="IVXLCDM"; *s; s++)
		count[*s] = 0;
	
	for(i=1;i<=n;i++)
		for(s=roman(i);*s;s++)
			count[*s]++;
		
		for(s="IVXLCDM"; *s; s++)
			if(count[*s])
				fprintf(fout, "%c %d\n", *s, count[*s]);
	
	return 0;
}
