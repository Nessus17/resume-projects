#include <iostream>
#include <string>
using namespace std;
void menu(string nome[], string cognome[], string tel[]);
void nct(string nome[], string cognome[], string tel[]);
void mostra(string nome[], string cognome[], string tel[]);
void ricerca(string nome[], string cognome[], string tel[]);
void cancella(string nome[], string cognome[], string tel[]);
void modifica(string nome[], string cognome[], string tel[]);
int c=0;

int main(){
	string nome[100];
	string cognome[100];
	string tel[100];
	menu(nome, cognome, tel);
	return 0;
}

void menu(string nome[], string cognome[], string tel[]){
	int s;
	char sn;
	do{
		cout<<"---------MENU------\n";
		cout<<" 1: nuovo contatto\n";
		cout<<" 2: ricerca contatto\n";
		cout<<" 3: mostra contatti\n";
		cout<<" 4: cancella contatto\n";
		cout<<" 5: modifica contatto\n";
		cout<<"-----> ";
		cin>>s;
		switch(s){
			case 1:
				nct(nome, cognome, tel);
				break;
				
			case 2:
				ricerca(nome, cognome, tel);
				break;
				
			case 3:
				mostra(nome, cognome, tel);
				break;
			
			case 4:
				cout<<"inserisci posizione contatto da cancellare: ";
				cancella(nome, cognome, tel);
				break;
				
			case 5:
				cout<<"inserisci posizione contatto da modificare: ";
				modifica(nome, cognome, tel);
				break;
			
					
			default:
				cout<<"---ERRORE, SCELTA NON VALIDA---\n";
				break;
			
		}
		cout<<"tornare al menu? (s/n)";
		cin>>sn;
		system("CLS");
	}while((sn=='s')||(sn=='S'));
}

void nct(string nome[], string cognome[], string tel[]){
	int j, a, b, t;
	string temp1, temp2, temp3, temp4;
	cout<<"inserisic il nome: ";
	cin>>nome[c];
	cout<<"inserisci il cognome: ";
	cin>>cognome[c];
	cout<<"inserisci il numero: ";
	cin>>tel[c];
	for(int i=0;i<c;i++){
		j=c;
		while(j>0 && nome[j]<nome[j-1]){
			temp1=nome[j];
			nome[j]=nome[j-1];   
			nome[j-1]=temp1;
			
			temp2=cognome[j];
			cognome[j]=cognome[j-1];   
			cognome[j-1]=temp2;
			
			temp3=tel[j];
			tel[j]=tel[j-1];   
			tel[j-1]=temp3;
			j--;
		}	
	}
	for(int i=0;i<c;i++){
		j=0;
		while(j<c-1){
			if(nome[j]==nome[j+1])
			{
				if(cognome[j]>cognome[j+1])
				{
					temp1=nome[j];
					nome[j]=nome[j+1];   
					nome[j+1]=temp1;
			
					temp2=cognome[j];
					cognome[j]=cognome[j+1];   
					cognome[j+1]=temp2;
			
					temp3=tel[j];
					tel[j]=tel[j+1];   
					tel[j+1]=temp3;
				}
			}
			j++;
		}
	}

	c++;
	cout<<"numero contatti memorizzati: "<<c<<endl;
}

void ricerca(string nome[], string cognome[], string tel[]){
	string n, co;
	int p=0, u=c-1, m;
	bool flag=false;
	cout<<"inserisci nome: ";
	cin>>n;
	while(!flag&&p<=u){
		
		m=(u+p)/2;
		
		if(n==nome[m]){
			flag=true;
			
		}else{
			
			if(nome[m]>n){
				u=m-1;
			
			}else{
				p=m+1;
			} 	
		}
	}
	if(n!=nome[m]){
		cout<<"contatto non trovato\n";
	}else{
		for(int n=-1;nome[m]==nome[m+n];n++){
		cout<<"\n"<<nome[m+n]<<"\n"<<cognome[m+n]<<"\n"<<tel[m+n]<<endl;
		}
	if(nome[m]!=nome[m+1]){
		cout<<"\n"<<nome[m]<<"\n"<<cognome[m]<<"\n"<<tel[m]<<endl;
		}
	}
}


void mostra(string nome[], string cognome[], string tel[]){
	if(c>0){
		int i;
		for(i=0;i<c;i++){
			cout<<"\nnome \t cognome \t tel \t"<<endl;
			cout<<nome[i]<<" \t "<<cognome[i]<<" \t  "<<tel[i]<< " \t"<<endl;
		}
	}else{
		cout<<"ERRORE: INSERIRE ALMENO UN ELEMENTO"<<endl;
	}
}

void cancella(string nome[], string cognome[], string tel[]){
    int a, i;
	cin>>a;
    for (i=a; i<c-1; i++){
        nome[i] = nome[i+1];
        cognome[i] = cognome[i+1];
        tel[i] = tel[i+1];
    } 
    c--;
}

void modifica(string nome[], string cognome[], string tel[]){
	cancella(nome, cognome, tel);
	nct(nome, cognome, tel);
}
