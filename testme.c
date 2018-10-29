#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    char c;
    c = (char)((rand() % 94) + 32); // produces a character b/w ( and }
    return c;
}

char *inputString()
{	
	char* consonants = "bcdfghjklmnpqrstvwxyz";
	char* b = "aeioubt";
	char* c = "aeioukhcr";
	char* d = "aeioudg";
	char* f = "aeiouf";
	char* g = "aeioughn";
	char* h = "aeiout";
	char* j = "aeiou";
	char* k = "aeioun";
	char* l = "aeioudfl";
	char* m = "aeioumbn";
	char* n = "aeioung";
	char* p = "aeioupshn";
	char* q = "u";
	char* r = "aeiourh";
	char* s = "aeiousch";
	char* t = "aeiouthc";
	char* v = "aeiou";
	char* w = "aeiourh";
	char* x = "aeiou";
	char* y = "aeiou";
	char* z = "aeiouz";
	char* start = "r";

    char* str;

    str = malloc(6*sizeof(char));
	memset(str, '\0', 6);
    int i; 
	int len;
	char* nextPool = start;
    for(i=0; i<5; i++){
	  len = strlen(nextPool);
	  str[i] = nextPool[rand()%strlen(nextPool)];
	  switch (str[i]){
		case 'b':
			nextPool = b;
			break;
		case 'c':
			nextPool = c;
			break;
		case 'd':
			nextPool = d;
			break;
		case 'f':
			nextPool = f;
			break;
		case 'g':
			nextPool = g;
			break;
		case 'h':
			nextPool = h;
			break;
		case 'j':
			nextPool = j;
			break;
		case 'k':
			nextPool = k;
			break;
		case 'l':
			nextPool = l;
			break;
		case 'm':
			nextPool = m;
			break;
		case 'n':
			nextPool = n;
			break;
		case 'p':
			nextPool = p;
			break;
		case 'q':
			nextPool = q;
			break;
		case 'r':
			nextPool = r;
			break;
		case 's':
			nextPool = s;
			break;
		case 't':
			nextPool = t;
			break;
		case 'v':
			nextPool = v;
			break;
		case 'w':
			nextPool = w;
			break;
		case 'x':
			nextPool = x;
			break;
		case 'y':
			nextPool = y;
			break;
		case 'z':
			nextPool = z;
			break;
		default:
// if vowel, next letter will be a consonant - inputstring does not support the use of dipthongs
			nextPool = consonants;
	  }
    }
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
// to produce the error, c must reach the values in order exactly and the string must be "reset\0"
    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
    free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
