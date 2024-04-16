#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Fraction
{
	int num, denum, i1, i2;
	float nombre;
	char nbr[20];
}Fraction;

int ppcm(int a, int b);
int pgcd(int a, int b);
int recherche(char c, char* s);
void reduit(Fraction* a);
void saisir(Fraction* a);
void afficher(Fraction a);
void afficherInt(int a);
void afficheFloat(float a);
void afficherFraction(Fraction* a);
Fraction plus(Fraction a, Fraction b);
Fraction minus(Fraction a, Fraction b);
Fraction times(Fraction a, Fraction b);
Fraction divided(Fraction a, Fraction b);
Fraction inverse(Fraction a);
float inverseint(int a);
Fraction exponent(Fraction a, int b);
Fraction squared(Fraction a);
int factorielle(int a);
void primeNumber(int nombre);
int same(Fraction a, Fraction b);
int different(Fraction a, Fraction b); 
int superior(Fraction a, Fraction b);
int inferior(Fraction a, Fraction b);
int sameint(int a, int b);
int differentint(int a, int b); 
int superiorint(int a, int b);
int inferiorint(int a, int b);
int samefloat(float a, float b);
int differentfloat(float a, float b); 
int superiorfloat(float a, float b);
int inferiorfloat(float a, float b);


int main()
{
	int rep, nbr;
	Fraction n1, n2, n3;
	printf("\n Les operations disponibles sont les suivantes(incluant les fractions pour les operations de 1 a 6)\n\n 1. Addition\n\n 2. Soustraction\n\n 3. Multiplication\n\n 4. Division\n\n 5. Exposant\n\n 6. Comparaison(uniquement pour les fractions)\n\n 7. Factorielle\n\n 8.Nombre premier\n\n 9. Inverse\n");
	printf("\n Quelle operation voulez-vous effectuer(1, 2, 3, 4, 5, 6, 7, 8 ou 9): ");
	scanf("%d", &rep);
	switch(rep)
	{
		case 1:
		{
			printf("\n Entrer un nombre: ");
			saisir(&n1);
			printf("\n Entrer-en un autre: ");
			saisir(&n2);
			printf("\n ");
			afficher(n1);
			printf(" + ");
			afficher(n2);
			printf(" = ");
			afficher(plus(n1, n2));
			break;
		}
		
		case 2:
		{
			printf("\n Entrer un nombre: ");
			saisir(&n1);
			printf("\n Entrer-en un autre: ");
			saisir(&n2);
			printf("\n ");
			afficher(n1);
			printf(" - ");
			afficher(n2);
			printf(" = ");
			afficher(minus(n1, n2));
			break;
		}
		
		case 3:
		{
			printf("\n Entrer un nombre: ");
			saisir(&n1);
			printf("\n Entrer-en un autre: ");
			saisir(&n2);
			printf("\n ");
			afficher(n1);
			printf(" * ");
			afficher(n2);
			printf(" = ");
			
			if(same(n1, n2) == 1)
				afficher(squared(n1));
				
			else if(different(n1, n2) == 1)
				afficher(times(n1, n2));
				
			break;
		}
		
		case 4:
		{
			printf("\n Entrer un nombre: ");
			saisir(&n1);
			printf("\n Entrer-en un autre: ");
			saisir(&n2);
			printf("\n ");
			afficher(n1);
			printf(" / ");
			afficher(n2);
			printf(" = ");
			afficher(divided(n1, n2));
			break;
		}
		
		case 5:
		{
			printf("\n Entrer le nombre: ");
			saisir(&n1);
			printf("\n Entrer l'exposant: ");
			scanf("%d", nbr);
			
			if(superiorint(nbr, 0) == 1)
			{
				printf("\n");
				afficher(n1);
				printf(" ^ %d = ", nbr);
				
				if(nbr != 2)
					afficher(exponent(n1, nbr));
				else
					afficher(squared(n1));
			}
			
			else if(inferiorint(nbr, 0) == 1)
				printf("\n Erreur, exposant inferieur a 1");
				
			break;
		}
		
		case 6:
		{
			printf("\n Entrer un nombre: ");
			saisir(&n1);
			printf("\n Entrer-en un autre: ");
			saisir(&n2);
			printf("\n");
			afficher(n1);
			
			if(superior(n1, n2) == 1)
				printf(" est superieur a");
			
			else if(inferior(n1, n2) == 1)
				printf(" est inferieur a");
				
			else if(same(n1, n2) == 1)
				printf(" est egal a");
				
			else if(different(n1, n2) == 1)
				printf(" est different de");
				
			afficher(n2);
			break;
		}
		
		case 7:
		{
			printf("\n Entrer le nombre: ");
			scanf("%d", &nbr);
			printf("\n %d! = %d", nbr, factorielle(nbr));
			break;
		}
		
		case 8:
		{
			printf("\n Entrer le nombre: ");
			scanf("%d", &nbr);
			primeNumber(nbr);
			break;
		}
		
		case 9:
		{
			printf("\n Entrer le nombre: ");
			scanf("%d", &nbr);
			printf("\n 1/%d = ", nbr);
			afficheFloat(inverseint(nbr));
			break;
		}
	}
	return 0;
}

int ppcm(int a, int b)
{ 
	int x=a, y=b;
	
	while(x != y)
	{
		if(x > y)
			y += b;
		else if(y > x)
			x += a;
	}

	return x;
}

int pgcd(int a, int b)
{
	int r=0;
	r = a%b;

	while(r != 0)
	{
		a = b;
		b = r;
		r = a%b;
	}
	
	return b;
}

int recherche(char c, char* s)
{
	int a;
	for(int i=0; i < strlen(s); i++)
	{
		if(c == s[i])
		{
			a = i;
			break;
		}

		else if(c != s[i] && i == strlen(s)-1)
			a = -1;
	}

	return a;
}

void reduit(Fraction* a)
{
	int div=0;
	div = pgcd(a->num, a->denum);
	a->num = a->num/div;
	a->denum = a->denum/div;

	if(a->denum < 0)
	{
		a->num *= -1;
		a->denum *= -1;
	}

	else if(a->denum == 1)
		a->i1 = -1;
}

void saisir(Fraction* a)
{
	int it=0, taille=0;
	char strn[10], strd[10];
	scanf("%s", a->nbr);
	a->i1 = recherche('/', a->nbr);
	a->i2 = recherche('.', a->nbr);
	taille = strlen(a->nbr);

	if(a->i1 != -1)
	{
		for(int i=0; i < a->i1; i++)
		{
			strn[i] = a->nbr[i];
		}

		for(int i = a->i1+1; i < taille; i++)
		{
			strd[it] = a->nbr[i];
			it++;
		}

		a->num = atoi(strn);
		a->denum = atoi(strd);

		if(a->denum == 0)
		{
			printf(" Erreur, correction automatique, denominateur = 1\n\n");
			a->denum = 1;
		}
		
		if(a->num == 0)
			a->denum = 1;
		else
			reduit(a);
	}

	else
	{
		if(a->i2 != -1)
		{
			char** p=NULL;
			a->nombre = strtod(a->nbr, p);
		}

		else
		{
			a->num = atoi(a->nbr);
			a->denum = 1;
		}
	}
}

void afficher(Fraction a)
{
	if(a.i1 != -1)
	{
		if(a.denum != 1)
			printf("%d/%d", a.num, a.denum);
		else
			afficherInt(a.num);
	}

	else
	{
		if(a.i2 != -1)
			afficheFloat(a.nombre);
		else
			afficherInt(a.num);
	}
}

void afficherInt(int a)
{
	printf("%d", a);
}

void afficheFloat(float a)
{
	char rep[20], r[20];
	gcvt(a, 6, rep);
	printf("%s", rep);
}

Fraction plus(Fraction a, Fraction b)
{
	Fraction c;
	if(a.i1 != -1)
	{
		if(b.i1 != -1)
		{
			c.num = a.num*b.denum + b.num*a.denum;
			c.denum = a.denum*b.denum; 
			reduit(&c);
			c.i1 = 1;
		}
		
		else
		{
			if(b.i2 != -1)
			{
				float n, d;
				n = (float)a.num;
				d = (float)a.denum;
				c.nombre = n/d + b.nombre;
				c.i2 = 1;
				c.i1 = -1;
			}
			
			else
			{
				c.num = a.num + b.num*a.denum;
				c.denum = a.denum;
				reduit(&c);
				c.i1 = 1;

			}
		}
	}
	
	else
	{
		if(a.i2 != -1)
		{
			c.i2 = 1;
			c.i1 = -1;
			
			if(b.i1 != -1)
				c.nombre = (b.num + a.nombre*b.denum)/b.denum;
			else
			{
				if(b.i2 != -1)
				{
					if(differentfloat(a.nombre, b.nombre) == 1)
						c.nombre = a.nombre + b.nombre;
					else
						c.nombre = a.nombre*2;
				}
				else
					c.nombre = a.nombre + b.num;
			}
		}
		
		else
		{
			if(b.i1 != -1)
			{
				c.num = a.num*ppcm(a.denum, b.denum)/a.denum + b.num*ppcm(a.denum, b.denum)/b.denum;
				c.denum = ppcm(a.denum, b.denum);
				c.i1 = 1;
			}
			else
			{
				if(b.i2 != -1)
				{
					c.nombre = a.num + b.nombre;
					c.i2 = 1;
					c.i1 = -1;
				}
				else
				{
					c.num = a.num + b.num;
					c.i1 = -1;
					c.i2 = -1;
				}
			}
		}
	}
	
	return c;
}

Fraction minus(Fraction a, Fraction b)
{
	Fraction c;
	if(a.i1 != -1)
	{
		if(b.i1 != -1)
		{
			c.num = a.num*b.denum - b.num*a.denum;
			c.denum = a.denum*b.denum; 
			reduit(&c);
			c.i1 = 1;
		}
		
		else
		{
			if(b.i2 != -1)
			{
				float n, d;
				n = (float)a.num;
				d = (float)a.denum;
				c.nombre = n/d - b.nombre;
				c.i2 = 1;
				c.i1 = -1;
			}
			
			else
			{
				c.num = a.num - b.num*a.denum;
				c.denum = a.denum;
				reduit(&c);
				c.i1 = 1;

			}
		}
	}
	
	else
	{
		if(a.i2 != -1)
		{
			c.i2 = 1;
			c.i1 = -1;
			
			if(b.i1 != -1)
				c.nombre = (a.nombre*b.denum - b.num)/b.denum;
			else
			{
				if(b.i2 != -1)
				{
					if(samefloat(a.nombre, b.nombre) == 1)
						c.nombre = 0;
					else
						c.nombre = a.nombre - b.nombre;
				}
				else
					c.nombre = a.nombre - b.num;
			}
		}
		
		else
		{
			if(b.i1 != -1)
			{
				c.num = a.num*ppcm(a.denum, b.denum)/a.denum - b.num*ppcm(a.denum, b.denum)/b.denum;
				c.denum = ppcm(a.denum, b.denum);
				c.i1 = 1;
			}
			else
			{
				if(b.i2 != -1)
				{
					c.nombre = a.num - b.nombre;
					c.i2 = 1;
					c.i1 = -1;
				}
				else
				{
					c.num = a.num - b.num;
					c.i1 = -1;
					c.i2 = -1;
				}
			}
		}
	}
	
	return c;
}
Fraction times(Fraction a, Fraction b)
{
	Fraction c;
	if(a.i1 != -1)
	{
		if(b.i1 != -1)
		{
			c.num = a.num*b.num;
			c.denum = a.denum*b.denum;
			reduit(&c);
			c.i1 = 1;
		}
		
		else
		{
			if(b.i2 != -1)
			{
				c.nombre = a.num*b.nombre/a.denum;
				c.i2 = 1;
				c.i1 = -1;
			}
			
			else
			{
				c.num = a.num*b.num;
				c.denum = a.denum;
				reduit(&c);
				c.i1 = 1;
			}
		}
	}
	
	else
	{
		if(a.i2 != -1)
		{
			c.i2 = 1;
			c.i1 = -1;
			
			if(b.i1 != -1)
				c.nombre = b.num*a.nombre/b.denum;
			else
			{
				if(b.i2 != -1)
					c.nombre = a.nombre*b.nombre;
				else
					c.nombre = a.nombre*b.num;
			}
		}
		
		else
		{
			if(b.i1 != -1)
			{
				c.num = a.num*b.num;
				c.denum = b.denum;
				c.i1 = 1;
			}
			else
			{
				if(b.i2 != -1)
				{
					c.nombre = a.num*b.nombre;
					c.i2 = 1;
					c.i1 = -1;
				}
				else
				{
					c.num = a.num*b.num;
					c.i1 = -1;
					c.i2 = -1;
				}
			}
		}
	}
	
	return c;
}

Fraction divided(Fraction a, Fraction b)
{
	Fraction c;
	if(a.i1 != -1)
	{
		if(b.i1 != -1)
		{
			c.num = a.num*b.denum;
			c.denum = a.denum*b.num;
			reduit(&c);
			c.i1 = 1;
		}
		
		else
		{
			if(b.i2 != -1)
			{
				c.nombre = a.num/(b.nombre*a.denum);
				c.i2 = 1;
				c.i1 = -1;
			}
			
			else
			{
				c.num = a.num;
				c.denum = a.denum*b.num;
				reduit(&c);
				c.i1 = 1;
			}
		}
	}
	
	else
	{
		if(a.i2 != -1)
		{
			c.i2 = 1;
			c.i1 = -1;
			
			if(b.i1 != -1)
				c.nombre = b.num/(a.nombre*b.denum);
			else
			{
				if(b.i2 != -1)
					c.nombre = a.nombre/b.nombre;
				else
					c.nombre = a.nombre/b.num;
			}
		}
		
		else
		{
			if(b.i1 != -1)
			{
				c.num = a.num*b.denum;
				c.denum = b.num;
				c.i1 = 1;
				reduit(&c);
			}
			else
			{
				if(b.i2 != -1)
				{
					c.nombre = a.num/b.nombre;
					c.i2 = 1;
					c.i1 = -1;
				}
				else
				{
					c.num = a.num/b.num;
					c.i1 = -1;
					c.i2 = -1;
				}
			}
		}
	}
	
	return c;
}

Fraction inverse(Fraction a)
{
	Fraction c;
	
	if(a.i1 != -1)
	{
		c.i1 = 1;
		c.num = a.denum;
		c.denum = a.num;
	}
	
	else
	{
		if(a.i2 != -1)
		{
			c.i2 = 1;
			c.i1 = -1;
			c.nombre = 1/a.nombre;
		}
		
		else
		{
			c.nombre = 1/(float)a.num;
			c.i2 = 1;
			c.i1 = -1;
		}
	}
	return c;
}

float inverseint(int a)
{
	float c = (float)a;
	return 1/c;
}

Fraction exponent(Fraction a, int b)
{
	Fraction c;
	if(a.i1 != -1)
	{
		c.i1 = 1;
		c.num = a.num;
                c.denum = a.denum;
		for(int i=2; i <= b; i++)
		{
			c.num = c.num*a.num;
			c.denum = c.denum*a.denum;
		}
		reduit(&c);
	}
	
	else
	{
		if(a.i2 != -1)
		{ 
			c.i2 = 1;
			c.i1 = -1;
			c.nombre = a.nombre;
			
			for(int i=2; i <= b; i++)
			{
				c.nombre = c.nombre*a.nombre;
			}
		}
		
		else
		{
			c.num = a.num;
			c.i1 = -1;
			c.i2 = -1;
			
			for(int i=2; i <= b; i++)
			{
				c.num = c.num*a.num;
			}
		}
	}

	return c;
}

Fraction squared(Fraction a)
{
	return exponent(a, 2);
}

int factorielle(int a)
{
	if (a <= 0)
		return 0;
		
	else if(a == 1)
		return 1;
	else 
		return a*factorielle(a-1);
}

void primeNumber(int nombre)
{
	int i=2;
	do
    	{
		if(nombre%i == 0 && nombre != 1 && nombre != 2 && nombre != 3)
        	{
        	    printf(" Ce nombre n'est pas premier\n\n");
        	    break;
        	}
        	
        	else if( nombre == 1 || nombre == 2 || nombre == 3)
        	{
        	    printf(" Ce nombre est premier\n\n");
        	    break;
        	}
        	
        	else if(i == nombre-1 && nombre%i != 0)
        	{
        	    printf(" Ce nombre est premier\n\n");
        	    break;
        	}
        	
        	i++;
        	
        }while (i < nombre);
}
int same(Fraction a, Fraction b)
{
	if(sameint(a.num, b.num) == 1 && sameint(a.denum, b.denum) == 1)
		return 1;
	else
		return 0;
}

int different(Fraction a, Fraction b)
{
	if(differentint(a.num, b.num) == 1 && differentint(a.denum, b.denum) == 1)
		return 1;
	else
		return 0;
}

int superior(Fraction a, Fraction b)
{
	if(superiorfloat(a.num/a.denum, b.num/b.denum) == 1)
		return 1;
	else
		return 0;
}

int inferior(Fraction a, Fraction b)
{
	if(inferiorfloat(a.num/a.denum, b.num/b.denum) == 1)
		return 1;
	else
		return 0;
}

int sameint(int a, int b)
{
	if(a == b)
		return 1;
	else
		return 0;
}

int differentint(int a, int b)
{
	if(a != b)
		return 1;
	else
		return 0;
}

int superiorint(int a, int b)
{
	if(a > b)
		return 1;
	else
		return 0;
}

int inferiorint(int a, int b)
{
	if(a < b)
		return 1;
	else
		return 0;
}

int samefloat(float a, float b)
{
	if(a == b)
		return 1;
	else
		return 0;
}

int differentfloat(float a, float b)
{
	if(a != b)
		return 1;
	else
		return 0;
}

int superiorfloat(float a, float b)
{
	if(a > b)
		return 1;
	else
		return 0;
}

int inferiorfloat(float a, float b)
{
	if(a < b)
		return 1;
	else
		return 0;
}
