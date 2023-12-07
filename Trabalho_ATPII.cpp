#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>

// MATHEUS OLIVEIRA DA SILVA - 262319446

struct tpData
{
	int d,m,a;
};

struct tpProdutos
{
	int CodProd,Estoque,CodForn;
	float Preco;
	tpData DtValidade;
	char Descr[25], Status;
};
					  
struct tpFornecedores
{
	int CodForn;
	char NomeForn[25], Cidade[25], Status;
};

struct tpClientes
{
	int QtdeCompras;
	float ValorTotComp;
	char cpf[11], NomeC[25], Status;
};

struct tpVendas
{
	int CodVenda;
	char cpf[11], Status;
	tpData DtVenda;
	float TotVenda;
};

struct tpVendas_Prod
{
	int Qtde, CodVenda, CodProd;
	float ValorUni;
	char Status;
};

void Moldura(int CI,int LI,int CF,int LF,int CorT,int CorF)
{
	int i;
	
	textcolor(9);
	textbackground(0);
	
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}
	
	textcolor(15);
}

void LimpaEntrada(void)
{
	gotoxy(38,19);
	printf("                                        ");
	gotoxy(39,19);
}

void LimpaTela(void)
{
	int i;
	
	for(i=6;i<18;i++)
	{
		gotoxy(29,i);
		printf("                                                  ");
	}
}

void InicioTela(int &C, int &L)
{
	LimpaTela();
	C=31;
	L=7;
	gotoxy(C,L);
}

void LimpaMenu(void)
{
	int i,j;
	
	for(i=6;i<21;i++)
	{
		gotoxy(3,i);
		printf("                        ");
	}
}

void LimpaMsg(void)
{
	gotoxy(13,23);
	printf("                                                                  ");
}

void EscrMsg(void)
{
	LimpaMsg();
	gotoxy(14,23);
}

void MolduraProg(void)
{
	Moldura(1,1,80,25,1,15);
	Moldura(2,2,79,4,1,15);
	Moldura(2,5,27,21,1,15);
	Moldura(2,22,79,24,1,15);
	Moldura(28,5,79,21,1,15);
	Moldura(29,18,78,20,1,15);
}

void MenuFornecedor(void)
{
	MolduraProg();
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	LimpaEntrada();
	gotoxy(4,7);
	printf("# #  FORNECEDORES  # #");
	gotoxy(3,9);
	printf("[A] CADASTRO");
	gotoxy(3,10);
	printf("[B] CONSULTA");
	gotoxy(3,11);
	printf("[C] EXCLUSAO");
	gotoxy(3,12);
	printf("[D] ALTERACAO");
	gotoxy(3,13);
	printf("[E] RELATORIO");
	gotoxy(3,14);
	printf("[F] AUMENTO DE PRECOS");
	gotoxy(3,19);
	printf("[R] VOLTAR");
	gotoxy(31,7);
	printf("SELECIONE UMA OPERACAO:");
	gotoxy(39,19);
}

void MenuCliente(void)
{
	MolduraProg();
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	gotoxy(5,7);
	printf("# #  CLIENTES  # #");
	gotoxy(3,9);
	printf("[A] CADASTRO");
	gotoxy(3,10);
	printf("[B] CONSULTA");
	gotoxy(3,11);
	printf("[C] EXCLUSAO");
	gotoxy(3,12);
	printf("[D] ALTERACAO");
	gotoxy(3,13);
	printf("[E] RELATORIO");
	gotoxy(3,19);
	printf("[R] VOLTAR");
	gotoxy(31,7);
	printf("SELECIONE UMA OPERACAO:");
	gotoxy(39,19);
}

void MenuProduto(void)
{
	MolduraProg();
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	gotoxy(5,7);
	printf("# #  PRODUTOS   # #");
	gotoxy(3,9);
	printf("[A] CADASTRO");
	gotoxy(3,10);
	printf("[B] CONSULTA");
	gotoxy(3,11);
	printf("[C] EXCLUSAO");
	gotoxy(3,12);
	printf("[D] ALTERACAO");
	gotoxy(3,13);
	printf("[E] RELATORIO");
	gotoxy(3,19);
	printf("[R] VOLTAR");
	gotoxy(31,7);
	printf("SELECIONE UMA OPERACAO:");
	gotoxy(39,19);
}

void MenuVendas(void)
{
	MolduraProg();
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	LimpaEntrada();
	gotoxy(7,7);
	printf("# #  VENDAS  # #");
	gotoxy(3,9);
	printf("[A] REALIZAR VENDA");
	gotoxy(3,10);
	printf("[B] VENDAS/PRODUTO");
	gotoxy(3,11);
	printf("[C] RELATORIO DE VENDAS");
	gotoxy(3,12);
	printf("[D] EXCLUIR VENDAS");
	gotoxy(3,13);
	printf("[E] CONSULTAR CUPOM");
	gotoxy(3,19);
	printf("[R] VOLTAR");
	gotoxy(31,7);
	printf("SELECIONE UMA OPERACAO:");
	gotoxy(39,19);
} 

void MenuBackup(void)
{
	MolduraProg();
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	LimpaEntrada();
	gotoxy(7,7);
	printf("# #  BACKUP  # #");
	gotoxy(3,9);
	printf("[A] REALIZAR BACKUP");
	gotoxy(3,10);
	printf("[B] RECUPERAR DADOS");
	gotoxy(3,11);
	printf("[C] LIMPAR EXCLUIDOS");
	gotoxy(3,19);
	printf("[R] VOLTAR");
	gotoxy(31,7);
	printf("SELECIONE UMA OPERCAO:");
	gotoxy(39,19);
} 

void MenuPrincipal(void)
{
	MolduraProg();
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	gotoxy(6,7);
	printf("# #  M E N U  # #");
	gotoxy(3,9);
	printf("[P] PRODUTOS");
	gotoxy(3,10);
	printf("[F] FORNECEDORES");
	gotoxy(3,11);
	printf("[C] CLIENTES");
	gotoxy(3,12);
	printf("[V] VENDAS");
	gotoxy(3,13);
	printf("[B] BACKUP");
	gotoxy(3,14);
	printf("[I] INSERIR DADOS");
	gotoxy(3,19);
	printf("[ESC] SAIR");
	gotoxy(31,7);
	printf("SELECIONE UMA OPERACAO:");
	LimpaEntrada();
}

char Menu(void)
{
	char op;
	textcolor(15);
	gotoxy(22,3);
	printf("# # #   T R A B A L H O   A T P   # # #");
	gotoxy(4,23);
	printf("MENSAGEM:");
	gotoxy(30,19);
	printf("ENTRADA:");
	MenuPrincipal();
	
	LimpaEntrada();
	return toupper(getch());
}

void ValidaData(int &d, int &m, int &a)
{
	int valida=0;
	
	do
	{
		LimpaMsg();
		LimpaEntrada();
		scanf("%d",&d);
		LimpaEntrada();
		scanf("%d",&m);
		LimpaEntrada();
		scanf("%d",&a);
		if(a>=2023 && a<2030)
		{
			if((d>=1 && d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12))
				valida=1;
			else
				if((d>=1 && d<=30) && (m==4 || m==6 || m==9 || m==11))
					valida=1;
				else
					if((d>=1 && d<=28) && m==2)
						valida=1;
					else
						if(d==29 && m==2 && ((a%400==0 || (a%4==0 && a%100!=0))))
							valida=1;
						else
						{
							EscrMsg();
							printf("DATA INVALIDA");
							getch();
						}
		}
		else
		{
			EscrMsg();
			printf("DATA INVALIDA");
			getch();
		}
	}while(valida!=1);
}

int ValidaCPF(char CPF[11])
{
	int i,mult,Dig[11],soma=0,resto,dig1,dig2;
	
	if(strlen(CPF)!=11)
		return 0;
	else
		if((strcmp(CPF,"00000000000")==0) || (strcmp(CPF,"11111111111")==0) || (strcmp(CPF,"22222222222")==0) || (strcmp(CPF,"33333333333")==0) || (strcmp(CPF,"44444444444")==0) || (strcmp(CPF,"55555555555")==0) || (strcmp(CPF,"66666666666")==0) || (strcmp(CPF,"77777777777")==0) || (strcmp(CPF,"88888888888")==0) || (strcmp(CPF,"99999999999")==0))
			return 0;
	else
	{
		for(i=0,mult=10;i<9;i++,mult--)
			soma+=(mult*(CPF[i]-48));
		resto=soma%11;
		dig1=11-resto;
		if(dig1==10 || dig1==11)
			dig1=0;
		if(dig1!=(CPF[9]-48))
			return 0;
		else
		{
			soma=0;
			for(i=0,mult=11;i<10;i++,mult--)
				soma+=(mult*(CPF[i]-48));
			resto=soma%11;
			dig2=11-resto;
			if(dig2==10 || dig2==11)
				dig2=0;
			if(dig2!=(CPF[10]-48))
				return 0;
		}
	}
	return 1;
}

void EntInv(void)
{
	EscrMsg();
	printf("ENTRADA INVALIDA");
	getch();
	LimpaMsg();
	LimpaEntrada();
}

char *ValidaString(void)
{
	int i;
	char StrAux[30];
	
	do
	{
		LimpaEntrada();
		fflush(stdin);
		gets(StrAux);
		if(strlen(StrAux)==0)
			EntInv();
		else
			return StrAux;
			
	}while(StrAux[0]!='/0');
}

int ConfirmaAlt(void)
{
	EscrMsg();
	printf("CONFIRMA ALTERACAO (S/N)?");
	LimpaEntrada();
	if(toupper(getche())=='S')
		return 1;
	else
		return 0;
}

int BuscaCPF(FILE *Ptr, char CPF[11])
{
	tpClientes R;
	int i,j,igual;
	rewind(Ptr);
	
	fread(&R,sizeof(tpClientes),1,Ptr);
	while(!feof(Ptr))
	{
		igual=0;
		for(i=0;i<11;i++)
		{
			if(CPF[i]==R.cpf[i] && R.Status=='A')
				igual=1;
			else
			{
				i=11;
				igual=0;
			}
		}
		if(igual==1)
			return ftell(Ptr)-sizeof(tpClientes);
		fread(&R,sizeof(tpClientes),1,Ptr);
	}
	return -1;
}

int BuscaCodForn(FILE *Ptr,int Cod) // BUSCA SEQUENCIAL INDEXADA
{
	tpFornecedores R;
	rewind(Ptr);
	
	fread(&R,sizeof(tpFornecedores),1,Ptr);
	while(!feof(Ptr) && (Cod>R.CodForn || R.Status=='I'))
		fread(&R,sizeof(tpFornecedores),1,Ptr);
	if(!feof(Ptr) && Cod==R.CodForn)
		return ftell(Ptr)-sizeof(tpFornecedores);
	else
		return -1;
}

int BuscaCupom(FILE *Ptr,int Cod)
{
	tpVendas R;
	rewind(Ptr);
	
	fread(&R,sizeof(tpVendas),1,Ptr);
	while(!feof(Ptr) && (Cod!=R.CodVenda || R.Status=='I'))
		fread(&R,sizeof(tpVendas),1,Ptr);
	if(!feof(Ptr))
		return ftell(Ptr)-sizeof(tpVendas);
	else
		return -1;
}

int BuscaCodProdSent(FILE *Ptr,int Cod) // BUSCA EXAUSTIVA COM SENTINELA
{
	tpProdutos R;
	int fim,pos;
	
	R.CodProd = Cod;
	R.Status = 'A';
	
	fseek(Ptr,0,2);
	fim = ftell(Ptr);
	fwrite(&R,sizeof(tpProdutos),1,Ptr);
	
	rewind(Ptr);
	
	fread(&R,sizeof(tpProdutos),1,Ptr);
	while(Cod!=R.CodProd || R.Status=='I')
		fread(&R,sizeof(tpProdutos),1,Ptr);
	
	pos = ftell(Ptr)-sizeof(tpVendas);
	
	R.Status = 'I';
	fseek(Ptr,fim,0);
	fwrite(&R,sizeof(tpProdutos),1,Ptr);
	
	if(pos+sizeof(tpProdutos)<=fim)
		return pos;
	else
		return -1;
}

int BuscaCodProd(FILE *Ptr,int Cod)
{
	tpProdutos R;
	rewind(Ptr);
	
	fread(&R,sizeof(tpProdutos),1,Ptr);
	while(!feof(Ptr) && (Cod!=R.CodProd || R.Status=='I'))
		fread(&R,sizeof(tpProdutos),1,Ptr);
	if(!feof(Ptr))
		return ftell(Ptr)-sizeof(tpProdutos);
	else
		return -1;
}

int BuscaProdVenda(FILE *Ptr,int Cod,int venda) // BUSCA EXAUSTIVA
{
	tpVendas_Prod R;
	rewind(Ptr);
	
	fread(&R,sizeof(tpVendas_Prod),1,Ptr);
	while(!feof(Ptr) && (R.CodVenda!=venda || (Cod!=R.CodProd || R.Status=='I')))
		fread(&R,sizeof(tpVendas_Prod),1,Ptr);
	if(!feof(Ptr))
		return ftell(Ptr)-sizeof(tpVendas_Prod);
	else
		return -1;
}

int BuscaVendaProd(FILE *Ptr,int Cod)
{
	tpVendas_Prod R;
	
	fread(&R,sizeof(tpVendas_Prod),1,Ptr);
	while(!feof(Ptr) && (Cod!=R.CodProd || R.Status=='I'))
		fread(&R,sizeof(tpVendas_Prod),1,Ptr);
		
	if(!feof(Ptr))
		return ftell(Ptr)-sizeof(tpVendas_Prod);
	else
		return -1;
}

int BuscaVendaCPF(FILE *Ptr, char CPF[11]) // BUSCA EXAUSTIVA
{
	tpVendas R;
	int i,j,igual;
	rewind(Ptr);
	
	fread(&R,sizeof(tpVendas),1,Ptr);
	while(!feof(Ptr))
	{
		igual=0;
		for(i=0;i<11;i++)
		{
			if(CPF[i]==R.cpf[i] && R.Status=='A')
				igual=1;
			else
			{
				i=11;
				igual=0;
			}
		}
		if(igual==1)
			return ftell(Ptr)-sizeof(tpVendas);
		fread(&R,sizeof(tpVendas),1,Ptr);
	}
	return -1;
}

//int BuscaVenda(FILE *Ptr,int Cod) // BUSCA SEQUENCIAL INDEXADA
//{
//	tpVendas_Prod R;
//	
//	fread(&R,sizeof(tpVendas_Prod),1,Ptr);
//	while(!feof && (Cod>R.CodVenda || R.Status=='I'))
//		fread(&R,sizeof(tpVendas_Prod),1,Ptr);
//	if(Cod==R.CodVenda)
//		return ftell(Ptr)-sizeof(tpVendas_Prod);
//	else
//		return -1;
//}

int BuscaVendaSeq(FILE *Ptr,int CodVenda)  // BUSCA BINÁRIA
{
	tpVendas R;
	int inicio=0,fim,meio;
	
	fseek(Ptr,0,2);
	fim = ftell(Ptr)/sizeof(tpVendas);
	meio = fim/2;
	
	fseek(Ptr,meio*sizeof(tpVendas),0);
	fread(&R,sizeof(tpVendas),1,Ptr);
	while(inicio<fim && (CodVenda!=R.CodVenda || R.Status=='I'))
	{
		if(R.CodVenda<CodVenda)
			inicio = meio+1;
		else
			fim = meio;
		meio = (inicio+fim)/2;
		fseek(Ptr,meio*sizeof(tpVendas),0);
		fread(&R,sizeof(tpVendas),1,Ptr);
	}
	if(CodVenda == R.CodVenda && R.Status=='A')
		return meio*sizeof(tpVendas);
	else
		return -1;
}

int BuscaFornProd(FILE *Ptr,int Cod) // BUSCA EXAUSTIVA
{
	tpProdutos R;
	
	fread(&R,sizeof(tpProdutos),1,Ptr);
	while(!feof(Ptr) && (Cod!=R.CodForn || R.Status=='I'))
		fread(&R,sizeof(tpProdutos),1,Ptr);
	if(!feof(Ptr))
		return ftell(Ptr)-sizeof(tpProdutos);
	else
		return -1;
}

void ValidaInt(int &IntAux)
{
	int valido=0;
	while(valido!=1)
	{
		if(scanf("%d",&IntAux)==1)
			valido=1;
		else
		{
			EscrMsg();
			printf("A ENTRADA DEVE SER UM NUMERO INTEIRO!");
			getch();
			fflush(stdin);
			LimpaMsg();
			LimpaEntrada();
		}
	}
}

void ValidaFloat(float &FloatAux)
{
	int valido=0;
	while(valido!=1)
	{
		if(scanf("%f",&FloatAux)==1)
			valido=1;
		else
		{
			EscrMsg();
			printf("A ENTRADA DEVE SER UM NUMERO!");
			getch();
			LimpaMsg();
			LimpaEntrada();
		}
		fflush(stdin);
	}
}

int QtdeForn(FILE *Ptr)
{
	tpFornecedores R;
	int i,qtde,cont=0;
	
	fseek(Ptr,0,2);
	qtde = ftell(Ptr)/sizeof(tpFornecedores);
	
	for(i=0;i<qtde;i++)
	{
		fseek(Ptr,i*sizeof(tpFornecedores),0);
		fread(&R,sizeof(tpFornecedores),1,Ptr);
		if(R.Status=='A')
			cont++;
	}
	rewind(Ptr);
	
	return cont;
}

int QtdeProd(FILE *Ptr)
{
	tpProdutos R;
	int i,qtde,cont=0;
	
	fseek(Ptr,0,2);
	qtde = ftell(Ptr)/sizeof(tpProdutos);
	
	for(i=0;i<qtde;i++)
	{
		fseek(Ptr,i*sizeof(tpProdutos),0);
		fread(&R,sizeof(tpProdutos),1,Ptr);
		if(R.Status=='A')
			cont++;
	}
	rewind(Ptr);
	
	return cont;
}

int QtdeCli(FILE *Ptr)
{
	tpClientes R;
	int i,qtde,cont=0;
	
	fseek(Ptr,0,2);
	qtde = ftell(Ptr)/sizeof(tpClientes);
	
	for(i=0;i<qtde;i++)
	{
		fseek(Ptr,i*sizeof(tpClientes),0);
		fread(&R,sizeof(tpClientes),1,Ptr);
		if(R.Status=='A')
			cont++;
	}
	rewind(Ptr);
	
	return cont;
}

int QtdeVendas(FILE *Ptr)
{
	tpVendas R;
	int i,qtde,cont=0;
	
	fseek(Ptr,0,2);
	qtde = ftell(Ptr)/sizeof(tpVendas);
	
	for(i=0;i<qtde;i++)
	{
		fseek(Ptr,i*sizeof(tpVendas),0);
		fread(&R,sizeof(tpVendas),1,Ptr);
		if(R.Status=='A')
			cont++;
	}
	rewind(Ptr);
	
	return cont;
}

int QtdeVP(FILE *Ptr)
{
	tpVendas_Prod R;
	int i,qtde,cont=0;
	
	fseek(Ptr,0,2);
	qtde = ftell(Ptr)/sizeof(tpVendas_Prod);
	
	for(i=0;i<qtde;i++)
	{
		fseek(Ptr,i*sizeof(tpVendas_Prod),0);
		fread(&R,sizeof(tpVendas_Prod),1,Ptr);
		if(R.Status=='A')
			cont++;
	}
	rewind(Ptr);
	
	return cont;
}

void InsercaoDireta(FILE *Ptr)
{
	tpFornecedores RA,RB;
	int Qtde;
	
	fseek(Ptr,0,2);
	Qtde = (ftell(Ptr)/sizeof(tpFornecedores))-1;
	
	fseek(Ptr,Qtde*sizeof(tpFornecedores),0);
	fread(&RA,sizeof(tpFornecedores),1,Ptr);
	
	fseek(Ptr,(Qtde-1)*sizeof(tpFornecedores),0);
	fread(&RB,sizeof(tpFornecedores),1,Ptr);
	
	while(Qtde>0 && RA.CodForn<RB.CodForn)
	{
		fseek(Ptr,(Qtde-1)*sizeof(tpFornecedores),0);
		fwrite(&RA,sizeof(tpFornecedores),1,Ptr);
		
		fseek(Ptr,Qtde*sizeof(tpFornecedores),0);
		fwrite(&RB,sizeof(tpFornecedores),1,Ptr);
		
		Qtde--;
		
		fseek(Ptr,Qtde*sizeof(tpFornecedores),0);
		fread(&RA,sizeof(tpFornecedores),1,Ptr);
		
		fseek(Ptr,(Qtde-1)*sizeof(tpFornecedores),0);
		fread(&RB,sizeof(tpFornecedores),1,Ptr);
	}
}

void CadForn(void)
{
	tpFornecedores R;
	int pos,C,L;
	char op;
	
	FILE *PtrForn = fopen("forn.dat","rb+");
	
	textcolor(12);
	gotoxy(3,9);
	printf("[A] CADASTRO");
	textcolor(15);
	InicioTela(C,L);
	printf("CADASTRO DE FORNECEDORES");
	gotoxy(31,9);
	printf("CODIGO DO FORNECEDOR: ");
	LimpaEntrada();
	ValidaInt(R.CodForn);
	while(R.CodForn>0)
	{
		pos=BuscaCodForn(PtrForn,R.CodForn);
		if(pos==-1)
		{
			gotoxy(53,9);
			printf("%d",R.CodForn);
			gotoxy(31,10);
			printf("NOME DO FORNECEDOR: ");
			LimpaEntrada();
			strcpy(R.NomeForn,ValidaString());
			if(strcmp(R.NomeForn,"0")==0)
			{
				EscrMsg();
				printf("CADASTRO CANCELADO");
			}
			else
			{
				strupr(R.NomeForn);
				gotoxy(51,10);
				printf("%s",R.NomeForn);
				gotoxy(31,11);
				printf("CIDADE DO FORNECEDOR: ");
				LimpaEntrada();
				strcpy(R.Cidade,ValidaString());
				if(strcmp(R.Cidade,"0")==0)
				{
					EscrMsg();
					printf("CADASTRO CANCELADO");
					getch();
				}
				else
				{
					strupr(R.Cidade);
					gotoxy(53,11);
					printf("%s",R.Cidade);
					R.Status='A';
					fseek(PtrForn,0,2);
					fwrite(&R,sizeof(tpFornecedores),1,PtrForn);
					EscrMsg();
					printf("FORNECEDOR CADASTRADO COM SUCESSO!");
				}
				
			}
		}
		else
		{
			EscrMsg();
			printf("FORNECEDOR JA CADASTRADO!");
		}
		getch();
		EscrMsg();
		printf("REALIZAR NOVO CADASTRO (S/N)?");
		LimpaEntrada();
		if(toupper(getche())=='S')
		{
			LimpaMsg();
			InicioTela(C,L);
			printf("CADASTRO DE FORNECEDORES");
			gotoxy(31,9);
			printf("CODIGO DO FORNECEDOR: ");
			LimpaEntrada();
			ValidaInt(R.CodForn);
		}
		else
		{
			EscrMsg();
			printf("MENU DE CADASTRO ENCERRADO!");
			LimpaEntrada();
			getch();
			R.CodForn=0;
		}
		InsercaoDireta(PtrForn);
	}
	fclose(PtrForn);
	LimpaTela();
	MenuFornecedor();
	LimpaEntrada();
}

void BubbleSort(void)
{
	tpClientes RA,RB;
	int QtdeReg,i,j;
	
	FILE *PtrCli = fopen("clientes.dat","rb+");
	
	fseek(PtrCli,0,2);
	QtdeReg = ftell(PtrCli)/sizeof(tpClientes);
	
	for(i=0;i<QtdeReg;i++)
	{
		for(j=0;j<QtdeReg-1;j++)
		{
			fseek(PtrCli,j*sizeof(tpClientes),0);
			fread(&RA,sizeof(tpClientes),1,PtrCli);
			fread(&RB,sizeof(tpClientes),1,PtrCli);
			if(strcmp(RA.NomeC,RB.NomeC)>0)
			{
				fseek(PtrCli,j*sizeof(tpClientes),0);
				fwrite(&RB,sizeof(tpClientes),1,PtrCli);
				fwrite(&RA,sizeof(tpClientes),1,PtrCli);
			}
		}
	}
}

void CadCli(void)
{
	tpClientes R;
	int i,pos,C,L,VCPF;
	char op;
	
	FILE *PtrCli = fopen("clientes.dat","ab+");
	
	textcolor(12);
	gotoxy(3,9);
	printf("[A] CADASTRO");
	textcolor(15);
	InicioTela(C,L);
	printf("CADASTRO DE CLIENTES");
	L+=2;
	gotoxy(C,L);
	printf("CPF DO CLIENTE:");
	L++;
	LimpaEntrada();
	fflush(stdin);
	strcpy(R.cpf,ValidaString());
	fflush(stdin);
	while(strcmp(R.cpf,"0")!=0)
	{
		VCPF = ValidaCPF(R.cpf);
		if(VCPF==0)
		{
			EscrMsg();
			printf("CPF INVALIDO");
			getch();
		}
		else
		{
			pos=BuscaCPF(PtrCli,R.cpf);
			if(pos==-1)
			{
				gotoxy(47,9);
				for(i=0;i<11;i++)
				{
					printf("%c",R.cpf[i]);
					if((i!=8) && (i+1)%3==0)
						printf(".");
					if(i==8)
						printf("-");
				}
				gotoxy(31,11);
				printf("NOME DO CLIENTE: ");
				L++;
				LimpaEntrada();
				strcpy(R.NomeC,ValidaString());
				if(strcmp(R.NomeC,"0")==0)
				{
					EscrMsg();
					printf("CADASTRO CANCELADO!");
					getch();
				}
				else
				{
					strupr(R.NomeC);
					gotoxy(48,11);
					printf("%s",R.NomeC);
					R.QtdeCompras=0;
					R.ValorTotComp=0;
					R.Status='A';
					EscrMsg();
					fwrite(&R,sizeof(tpClientes),1,PtrCli);
					printf("CLIENTE CADASTRADO COM SUCESSO!");
					LimpaEntrada();
					getch();
				}
			}
			else
			{
				EscrMsg();
				printf("CPF JA CADASTRADO");
				getch();
			}
		}
		EscrMsg();
		printf("REALIZAR NOVO CADASTRO (S/N)?");
		LimpaEntrada();
		if(toupper(getche())=='S')
		{
			InicioTela(C,L);
			printf("CADASTRO DE CLIENTES");
			gotoxy(C,L);
			L+=2;
			gotoxy(C,L);
			printf("CPF DO CLIENTE: ");
			L++;
			LimpaMsg();
			LimpaEntrada();
			fflush(stdin);
			strcpy(R.cpf,ValidaString());
		}
		else
		{
			EscrMsg();
			printf("MENU DE CADASTRO ENCERRADO!");
			LimpaEntrada();
			getch();
			strcpy(R.cpf,"0");
		}
	}
	fclose(PtrCli);
	BubbleSort();
	LimpaTela();
	MenuCliente();
	LimpaEntrada();
}

void SelectionSort(void)
{
	tpProdutos RA,RB;
	int i,j,menor,posmenor,QtdeReg;
	
	FILE *Ptr = fopen("produtos.dat","rb+");
	fseek(Ptr,0,2);
	QtdeReg = ftell(Ptr)/sizeof(tpProdutos);
	rewind(Ptr);
	
	for(i=0;i<QtdeReg-1;i++)
	{
		fseek(Ptr,i*sizeof(tpProdutos),0);
		fread(&RA,sizeof(tpProdutos),1,Ptr);
		menor = RA.CodProd;
		posmenor = i;
		for(j=i+1;j<QtdeReg;j++)
		{
			fseek(Ptr,j*sizeof(tpProdutos),0);
			fread(&RB,sizeof(tpProdutos),1,Ptr);
			if(RB.CodProd<menor)
			{
				menor=RB.CodProd;
				posmenor=j;
			}
		}
		if(posmenor!=i)
		{
			fseek(Ptr,posmenor*sizeof(tpProdutos),0);
			fread(&RB,sizeof(tpProdutos),1,Ptr);
			fseek(Ptr,posmenor*sizeof(tpProdutos),0);
			fwrite(&RA,sizeof(tpProdutos),1,Ptr);
			fseek(Ptr,i*sizeof(tpProdutos),0);
			fwrite(&RB,sizeof(tpProdutos),1,Ptr);
		}
	}
	fclose(Ptr);
}

void CadProd(void)
{
	tpProdutos R;
	tpFornecedores RF;
	int CodForn,posForn,pos,C,L;
	char op;
	
	FILE *Ptr = fopen("produtos.dat","rb+");
	FILE *PtrForn = fopen("forn.dat","rb");
	
	if(QtdeForn(PtrForn)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM FORNECEDORES CADASTRADOS!");
		getch();
	}
	else
	{	
		textcolor(12);
		gotoxy(3,9);
		printf("[A] CADASTRO");
		textcolor(15);
		InicioTela(C,L);
		printf("CADASTRO DE PRODUTOS");
		L+=2;
		gotoxy(C,L);
		printf("CODIGO DO PRODUTO:");
		L++;
		LimpaEntrada();
		ValidaInt(R.CodProd);
		while(R.CodProd>0)
		{
			pos=BuscaCodProdSent(Ptr,R.CodProd);
			if(pos==-1)
			{
				gotoxy(50,9);
				printf("%d",R.CodProd);
				gotoxy(C,L);
				printf("CODIGO DO FORNECEDOR:");
				L++;
				do
				{
					LimpaMsg();
					LimpaEntrada();
					ValidaInt(RF.CodForn);
					if(RF.CodForn==0)
					{
						EscrMsg();
						printf("CADASTRO CANCELADO!");
						getch();
						op='S';
					}
					else
					{
						posForn=BuscaCodForn(PtrForn,RF.CodForn);
						if(posForn==-1)
						{
							EscrMsg();
							printf("FORNECEDOR NAO ENCONTRADO!");
							LimpaEntrada();
							getch();
							EscrMsg();
						}
						else
						{
							EscrMsg();
							fseek(PtrForn,posForn,0);
							fread(&RF,sizeof(tpFornecedores),1,PtrForn);
							printf("CONFIRMA FORNECEDOR (S/N): %s",RF.NomeForn);
							LimpaEntrada();
							fflush(stdin);
							if(toupper(getch())=='S')
							{
								R.CodForn = RF.CodForn;
								op='S';
							}
							LimpaMsg();
						}
					}
				}while(op!='S');
				if(RF.CodForn!=0)
				{
					gotoxy(53,10);
					printf("%d",RF.CodForn);
					gotoxy(C,L);
					printf("DESCRICAO DO PRODUTO: ");
					L++;
					LimpaEntrada();
					strcpy(R.Descr,ValidaString());
					if(strcmp(R.Descr,"0")==0)
					{
						EscrMsg();
						printf("CADASTRO CANCELADO!");
						getch();
					}
					else
					{
						strupr(R.Descr);
						gotoxy(53,11);
						printf("%s",R.Descr);
						gotoxy(C,L);
						printf("QUANTIDADE EM ESTOQUE:");
						L++;
						LimpaEntrada();
						ValidaInt(R.Estoque);
						gotoxy(54,12);
						printf("%d",R.Estoque);
						gotoxy(C,L);
						printf("PRECO:");
						L++;
						LimpaEntrada();
						ValidaFloat(R.Preco);
						if(R.Preco==0)
						{
							EscrMsg();
							printf("CADASTRO CANCELADO!");
							getch();
						}
						else
						{
							gotoxy(38,13);
							printf("%.2f",R.Preco);
							gotoxy(C,L);
							printf("DATA DE VALIDADE:");
							L++;
							LimpaEntrada();
							ValidaData(R.DtValidade.d,R.DtValidade.m,R.DtValidade.a);
							if((R.DtValidade.d==0) && (R.DtValidade.m==0) && (R.DtValidade.a==0))
							{
								EscrMsg();
								printf("CADASTRO CANCELADO!");
								getch();
							}
							else
							{
								gotoxy(49,14);
								printf("%d/%d/%d",R.DtValidade.d,R.DtValidade.m,R.DtValidade.a);
								R.Status='A';
								fwrite(&R,sizeof(tpProdutos),1,Ptr);
								EscrMsg();
								printf("PRODUTO CADASTRADO COM SUCESSO!");
								LimpaEntrada();
								getch();
							}
						}	
					}
				}
			}
			else
			{
				EscrMsg();
				printf("PRODUTO JA CADASTRADO!");
				getch();
				LimpaMsg();
			}
			EscrMsg();
			printf("REALIZAR NOVO CADASTRO (S/N)?");
			LimpaEntrada();
			if(toupper(getche())=='S')
			{
				InicioTela(C,L);
				printf("CADASTRO DE PRODUTOS");
				gotoxy(C,L);
				L+=2;
				gotoxy(C,L);
				printf("CODIGO DO PRODUTO: ");
				L++;
				LimpaMsg();
				LimpaEntrada();
				ValidaInt(R.CodProd);
			}
			else
			{
				EscrMsg();
				printf("MENU DE CADASTRO ENCERRADO!");
				LimpaEntrada();
				R.CodProd=0;
			}
		}
	}
	fclose(PtrForn);
	fclose(Ptr);
	SelectionSort(); // ORDENAÇÃO SELECTION SORT
	LimpaTela();
	MenuProduto();
	LimpaEntrada();
}

void ConsultaCli(void)
{
	tpClientes R;
	int i,C,L,pos;
	char CPF[11];
	
	FILE *Ptr = fopen("clientes.dat","rb");
	
	if(QtdeCli(Ptr)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM CLIENTES CADASTRADOS!");
		getch();
	}
	else
	{
		textcolor(12);
		gotoxy(3,10);
		printf("[B] CONSULTA");
		textcolor(15);
		InicioTela(C,L);
		printf("CONSULTA DE CLIENTES");
		gotoxy(31,9);
		printf("CPF DO CLIENTE: ");
		LimpaEntrada();
		strcpy(R.cpf,ValidaString());
		while(strcmp(R.cpf,"0")!=0)
		{
			pos=BuscaCPF(Ptr,R.cpf);
			if(pos==-1)
			{
				EscrMsg();
				printf("CLIENTE NAO ENCONTRADO!");
			}
			else
			{
				fseek(Ptr,pos,0);
				fread(&R,sizeof(tpClientes),1,Ptr);
				InicioTela(C,L);
				gotoxy(C,L);
				printf("CPF: ");
				for(i=0;i<11;i++)
				{
					printf("%c",R.cpf[i]);
					if((i!=8) && (i+1)%3==0)
						printf(".");
					if(i==8)
						printf("-");
				}
				L++;
				gotoxy(C,L);
				printf("NOME: %s",R.NomeC);
				L++;
				gotoxy(C,L);
				printf("QUANTIDADE DE COMPRAS: %d",R.QtdeCompras);
				L++;
				gotoxy(C,L);
				printf("VALOR TOTAL COMPRADO: R$ %.2f",R.ValorTotComp);
				L+=2;
			}
			getch();
			InicioTela(C,L);
			printf("CONSULTA DE CLIENTES");
			gotoxy(31,9);
			printf("CPF DO CLIENTE: ");
			LimpaMsg();
			LimpaEntrada();
			strcpy(R.cpf,ValidaString());
		}
		fclose(Ptr);
	}
	LimpaEntrada();
}

void ConsultaForn(void)
{
	tpFornecedores R;
	int i,C,L,pos;
	
	FILE *Ptr = fopen("forn.dat","rb");
	
	if(QtdeForn(Ptr)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM FORNECEDORES CADASTRADOS!");
		getch();
	}
	else
	{
		textcolor(12);
		gotoxy(3,10);
		printf("[B] CONSULTA");
		textcolor(15);
		InicioTela(C,L);
		printf("CONSULTA DE FORNECEDORES");
		gotoxy(31,9);
		printf("CODIGO DO FORNECEDOR: ");
		LimpaEntrada();
		ValidaInt(R.CodForn);
		while(R.CodForn>0)
		{
			pos=BuscaCodForn(Ptr,R.CodForn);
			if(pos==-1)
			{
				EscrMsg();
				printf("FORNECEDOR NAO ENCONTRADO");
			}
			else
			{
				fseek(Ptr,pos,0);
				fread(&R,sizeof(tpFornecedores),1,Ptr);
				InicioTela(C,L);
				gotoxy(C,L);
				printf("CODIGO: %d",R.CodForn);
				L++;
				gotoxy(C,L);
				printf("NOME: %s",R.NomeForn);
				L++;
				gotoxy(C,L);
				printf("CIDADE: %s",R.Cidade);
				L+=2;
			}
			getch();
			InicioTela(C,L);
			printf("CONSULTA DE FORNECEDORES");
			gotoxy(31,9);
			printf("CODIGO DO FORNECEDOR: ");
			LimpaMsg();
			LimpaEntrada();
			ValidaInt(R.CodForn);
		}
		fclose(Ptr);
	}
	LimpaEntrada();
}

void ConsultaProd(void)
{
	tpProdutos RP;
	tpFornecedores RF;
	int i,C,L,pos,posForn;
	
	FILE *PtrProd = fopen("produtos.dat","rb");
	
	if(QtdeProd(PtrProd)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM PRODUTOS CADASTRADOS!");
		getch();
	}
	else
	{
		FILE *PtrForn = fopen("forn.dat","rb");
		textcolor(12);
		gotoxy(3,10);
		printf("[B] CONSULTA");
		textcolor(15);
		InicioTela(C,L);
		printf("CONSULTA DE PRODUTOS");
		gotoxy(31,9);
		printf("CODIGO DO PRODUTO: ");
		LimpaEntrada();
		ValidaInt(RP.CodProd);
		while(RP.CodProd>0)
		{
			pos=BuscaCodProd(PtrProd,RP.CodProd);
			if(pos==-1)
			{
				EscrMsg();
				printf("PRODUTO NAO ENCONTRADO");
			}
			else
			{
				InicioTela(C,L);
				fseek(PtrProd,pos,0);
				fread(&RP,sizeof(tpProdutos),1,PtrProd);
				printf("CODIGO: %d",RP.CodProd);
				L++;
				gotoxy(C,L);
				printf("DESCRICAO: %s",RP.Descr);
				L++;
				gotoxy(C,L);
				posForn=BuscaCodForn(PtrForn,RP.CodForn);
				fseek(PtrForn,posForn,0);
				fread(&RF,sizeof(tpFornecedores),1,PtrForn);
				printf("FORNECEDOR [%d] - %s",RP.CodForn,RF.NomeForn);
				L++;
				gotoxy(C,L);
				printf("ESTOQUE: %d   -   ",RP.Estoque);
				printf("PRECO: R$ %.2f",RP.Preco);
				L++;
				gotoxy(C,L);
				printf("VALIDADE: %d/%d/%d",RP.DtValidade.d,RP.DtValidade.m,RP.DtValidade.a);
				L+=2;
			}
			getch();
			InicioTela(C,L);
			printf("CONSULTA DE PRODUTOS");
			gotoxy(31,9);
			printf("CODIGO DO PRODUTO: ");
			LimpaMsg();
			LimpaEntrada();
			ValidaInt(RP.CodProd);
		}
		fclose(PtrForn);
		fclose(PtrProd);
	}
	LimpaEntrada();
}

void RelatorioForn(void)
{
	tpFornecedores R;
	int i,l=7,c=31,pg=1,QtdeReg;
	char op=64;
	
	FILE *Ptr = fopen("forn.dat","rb");
	QtdeReg = QtdeForn(Ptr);
	
	if(QtdeReg==0)
	{
		EscrMsg();
		printf("NAO EXISTEM FORNECEDORES CADASTRADOS!");
		getch();
	}
	else
	{
		LimpaTela();
		textcolor(12);
		gotoxy(3,13);
		printf("[E] RELATORIO");
		textcolor(15);
		gotoxy(40,6);
		printf("RELATORIO DE FORNECEDORES (%d)",QtdeReg);
		fread(&R,sizeof(tpFornecedores),1,Ptr);
		i=0;
		while(!feof(Ptr) && op!=27)
		{
			if(R.Status=='A')
			{
				gotoxy(c,l);
				printf("CODIGO: %d",R.CodForn);
				l++;
				gotoxy(c,l);
				printf("NOME: %s",R.NomeForn);
				l++;
				gotoxy(c,l);
				printf("CIDADE: %s",R.Cidade);
				l+=2;
				if((i+1)%3==0)
				{
					
					gotoxy(68,17);
					printf("PAGINA: %d",pg);
					op = getch();
					pg++;
					LimpaTela();
					gotoxy(40,6);
					printf("RELATORIO DE FORNECEDORES (%d)",QtdeReg);
					l=7;
				}
				i++;
			}
			fread(&R,sizeof(tpFornecedores),1,Ptr);
		}
		if(i%3!=0)
		{
			gotoxy(68,17);
			printf("PAGINA: %d",pg);
			getch();
		}
		fclose(Ptr);
		LimpaEntrada();
		
		MenuFornecedor();
	}
}

void RelatorioProd(void)
{
	tpProdutos RP;
	tpFornecedores RF;
	int i,l=7,c=31,pg=1,pos,QtdeReg;
	char op=64;
	
	FILE *PtrProd = fopen("produtos.dat","rb");
	QtdeReg = QtdeProd(PtrProd);

	if(QtdeReg==0)
	{
		EscrMsg();
		printf("NAO EXISTEM PRODUTOS CADASTRADOS!");
		getch();
	}
	else
	{
		FILE *PtrForn = fopen("forn.dat","rb");
		textcolor(12);
		gotoxy(3,13);
		printf("[E] RELATORIO");
		textcolor(15);
		LimpaTela();
		gotoxy(40,6);
		printf("RELATORIO DE PRODUTOS (%d)",QtdeReg);
		i=0;
		fread(&RP,sizeof(tpProdutos),1,PtrProd);
		while(!feof(PtrProd) && op!=27)
		{
			if(RP.Status=='A')
			{
				gotoxy(c,l);
				printf("CODIGO: %d",RP.CodProd);
				l++;
				gotoxy(c,l);
				printf("DESCRICAO: %s",RP.Descr);
				l++;
				gotoxy(c,l);
				pos=BuscaCodForn(PtrForn,RP.CodForn);
				fseek(PtrForn,pos,0);
				fread(&RF,sizeof(tpFornecedores),1,PtrForn);
				printf("FORNECEDOR [%d] - %s",RP.CodForn,RF.NomeForn);
				l++;
				gotoxy(c,l);
				printf("ESTOQUE: %d   -   ",RP.Estoque);
				printf("PRECO: R$ %.2f",RP.Preco);
				l++;
				gotoxy(c,l);
				printf("VALIDADE: %d/%d/%d",RP.DtValidade.d,RP.DtValidade.m,RP.DtValidade.a);
				l+=2;
				if((i+1)%2==0)
				{
					
					gotoxy(68,17);
					printf("PAGINA: %d",pg);
					fflush(stdin);
					op = getch();
					pg++;
					LimpaTela();
					gotoxy(40,6);
					printf("RELATORIO DE PRODUTOS (%d)",QtdeReg);
					l=7;
				}
				i++;
			}
			fread(&RP,sizeof(tpProdutos),1,PtrProd);
		}
		if(i%2!=0)
		{
			gotoxy(68,17);
			printf("PAGINA: %d",pg);
			fflush(stdin);
			getch();
		}
		fclose(PtrForn);
		fclose(PtrProd);
		LimpaEntrada();
		MenuProduto();
	}
}

void RelatorioVP(void)
{
	tpVendas_Prod RegVP;
	tpClientes RegCli;
	tpProdutos RegProd;
	int i,j,l=7,c=31,pg=1,pos,posProd,QtdeReg;
	char op=64;
	
	FILE *PtrVP = fopen("vendasprod.dat","rb");
	QtdeReg = QtdeVP(PtrVP);
	
	if(QtdeReg==0)
	{
		EscrMsg();
		printf("NAO EXISTEM VENDAS REGISTRADAS!");
		getch();
	}
	else
	{
		FILE *PtrProd = fopen("produtos.dat","rb");
		InicioTela(c,l);
		textcolor(12);
		gotoxy(3,10);
		printf("[B] VENDAS/PRODUTO:");
		textcolor(15);
		LimpaTela();
		gotoxy(38,6);
		printf("RELATORIO DE VENDAS/PRODUTO (%d)",QtdeReg);
		l=8;
		i=0;
		fread(&RegVP,sizeof(tpVendas_Prod),1,PtrVP);
		while(!feof(PtrVP) && op!=27)
		{
			if(RegVP.Status=='A')
			{
				gotoxy(c,l);
				printf("CODIGO DA VENDA: %d",RegVP.CodVenda);
				l++;
				gotoxy(c,l);
				posProd=BuscaCodProd(PtrProd,RegVP.CodProd);
				fseek(PtrProd,posProd,0);
				fread(&RegProd,sizeof(tpProdutos),1,PtrProd);
				printf("PRODUTO [%d] - %s",RegVP.CodProd,RegProd.Descr);
				l++;
				gotoxy(c,l);
				printf("QUANTIDADE: %d",RegVP.Qtde);
				l++;
				gotoxy(c,l);
				printf("VALOR UNITARIO: R$ %.2f",RegVP.ValorUni);
				l+=2;
				if((i+1)%2==0)
				{
					
					gotoxy(68,17);
					printf("PAGINA: %d",pg);
					op = getch();
					pg++;
					LimpaTela();
					gotoxy(38,6);
					printf("RELATORIO DE VENDAS/PRODUTO (%d)",QtdeReg);
					l=8;
				}
				i++;
			}
			fread(&RegVP,sizeof(tpVendas_Prod),1,PtrVP);
		}
		if(i%2!=0)
		{
			gotoxy(68,17);
			printf("PAGINA: %d",pg);
			getch();
		}
		fclose(PtrProd);
		fclose(PtrVP);
		LimpaEntrada();
		MenuProduto();
	}
}

void RelatorioVendas()
{
	tpClientes RC;
	tpVendas RV;
	tpVendas_Prod RVP;
	tpProdutos RP;
	tpFornecedores RF;
	
	int i=0,j=0,c,l,posProd,posForn,posCPF,pg=1,QtdeReg;
	char op=64;
	
	FILE *PtrVend = fopen("vendas.dat","rb");
	QtdeReg = QtdeVendas(PtrVend);
	
	if(QtdeReg==0)
	{
		EscrMsg();
		printf("NAO EXISTEM VENDAS REGISTRADAS");
		getch();
	}
	else
	{
		FILE *PtrCli = fopen("clientes.dat","rb");
		FILE *PtrVP = fopen("vendasprod.dat","rb");
		FILE *PtrProd = fopen("produtos.dat","rb");
		FILE *PtrForn = fopen("forn.dat","rb");
		InicioTela(c,l);
		textcolor(12);
		gotoxy(3,11);
		printf("[C] RELATORIO DE VENDAS");
		textcolor(15);
		LimpaTela();
		gotoxy(42,6);
		printf("RELATORIO DE VENDAS (%d)",QtdeReg);
		l=8;
		fread(&RV,sizeof(tpVendas),1,PtrVend);
		while(!feof(PtrVend) && op!=27)
		{
			if(RV.Status == 'A')
			{
				rewind(PtrVP);
				gotoxy(c,l);
				posCPF = BuscaCPF(PtrCli,RV.cpf);
				fseek(PtrCli,posCPF,0);
				fread(&RC,sizeof(tpClientes),1,PtrCli);
				printf("VENDA: %d - %s",RV.CodVenda,RC.NomeC);
				l++;
				gotoxy(c,l);
				printf("PRODUTOS:");
				fread(&RVP,sizeof(tpVendas_Prod),1,PtrVP);
				while(!feof(PtrVP))
				{
					if(RVP.CodVenda==RV.CodVenda && RV.Status=='A' && RVP.Status=='A')
					{
						posProd=BuscaCodProd(PtrProd,RVP.CodProd);
						fseek(PtrProd,posProd,0);
						fread(&RP,sizeof(tpProdutos),1,PtrProd);
						posForn=BuscaCodForn(PtrForn,RP.CodForn);
						fseek(PtrForn,posForn,0);
						fread(&RF,sizeof(tpFornecedores),1,PtrForn);
						l++;
						gotoxy(c,l);
						printf("[%d] - %s",RVP.CodProd, RP.Descr);
						gotoxy(50,l);
						printf("%d",RVP.Qtde);
						gotoxy(54,l);
						printf("R$ %.2f",RVP.Qtde*RVP.ValorUni);
						gotoxy(64,l);
						printf("%s",RF.NomeForn);
					}
					if(l%17==0)
					{
						fflush(stdin);
						getch();
						InicioTela(c,l);
					}
					j++;
					fread(&RVP,sizeof(tpVendas_Prod),1,PtrVP);
				}
				l++;
				if(l>=17)
					InicioTela(c,l);
				gotoxy(c,l);
				printf("TOTAL: R$ %.2f",RV.TotVenda);
				gotoxy(68,17);
				printf("PAGINA: %d",pg);
				op = getch();
				LimpaTela();
				pg++;
				gotoxy(42,6);
				printf("RELATORIO DE VENDAS (%d)",QtdeReg);
				l=8;
				i++;
			}
			fread(&RV,sizeof(tpVendas),1,PtrVend);
		}
		LimpaEntrada();
		fclose(PtrCli);
		fclose(PtrVend);
		fclose(PtrVP);
		fclose(PtrForn);
		fclose(PtrProd);
		MenuProduto();
	}
}

void RelatorioCli(void)
{
	tpClientes R;
	int i=0,j,l=7,c=31,pg=1,pos,QtdeReg;
	char op=64;
	
	FILE *Ptr = fopen("clientes.dat","rb");
	QtdeReg = QtdeCli(Ptr);
	
	if(QtdeReg==0)
	{
		EscrMsg();
		printf("NAO EXISTEM CLIENTES CADASTRADOS!");
		getch();
	}
	else
	{
		InicioTela(c,l);
		textcolor(12);
		gotoxy(3,13);
		printf("[E] RELATORIO");
		textcolor(15);
		LimpaTela();
		gotoxy(41,6);
		printf("RELATORIO DE CLIENTES (%d)",QtdeReg);
		l=8;
		fread(&R,sizeof(tpClientes),1,Ptr);
		while(!feof(Ptr) && op!=27)
		{
			if(R.Status=='A')
			{
				gotoxy(c,l);
				printf("CPF: ");
				for(j=0;j<11;j++)
				{
					printf("%c",R.cpf[j]);
					if((j!=8) && (j+1)%3==0)
						printf(".");
					if(j==8)
						printf("-");
				}
				l++;
				gotoxy(c,l);
				printf("NOME: %s",R.NomeC);
				l++;
				gotoxy(c,l);
				printf("QUANTIDADE DE COMPRAS: %d",R.QtdeCompras);
				l++;
				gotoxy(c,l);
				printf("VALOR TOTAL COMPRADO: R$ %.2f",R.ValorTotComp);
				l+=2;
				if((i+1)%2==0)
				{
					gotoxy(68,17);
					printf("PAGINA: %d",pg);
					fflush(stdin);
					op = getch();
					pg++;
					LimpaTela();
					gotoxy(41,6);
					printf("RELATORIO DE CLIENTES (%d)",QtdeReg);
					l=8;
				}
				i++;
			}
			fread(&R,sizeof(tpClientes),1,Ptr);
		}
		if(i%2!=0)
		{
			gotoxy(68,17);
			printf("PAGINA: %d",pg);
			fflush(stdin);
			getch();
		}
		fclose(Ptr);
		LimpaEntrada();
		MenuProduto();
	}
}

void ExcVenda(void)
{
	tpClientes RegCli;
	tpProdutos RegProd;
	tpVendas RegV;
	tpVendas_Prod RegVP;
	int C,L,pos,posVP,poscli,posprod,i,j,QtdeVP,QtdeV;
	char cpf[11];
	float TotMenos;
	
	FILE *PtrV = fopen("vendas.dat","rb+");
	
	if(QtdeVendas(PtrV)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM VENDAS CADASTRADAS!");
		getch();
	}
	else
	{
		InicioTela;
		LimpaMsg();
		textcolor(12);
		gotoxy(3,12);
		printf("[D] EXCLUIR VENDAS");
		textcolor(15);
		InicioTela(C,L);
		printf("EXCLUSAO DE VENDAS");
		L+=2;
		gotoxy(C,L);
		printf("CODIGO DA VENDA:");
		LimpaEntrada();
		ValidaInt(RegV.CodVenda);
		while(RegV.CodVenda>0)
		{
			rewind(PtrV);
			pos=BuscaVendaSeq(PtrV,RegV.CodVenda); // BUSCA BINÁRIA
			if(pos==-1)
			{
				EscrMsg();
				printf("VENDA NAO ENCONTRADA!");
				getch();
			}
			else
			{
				fseek(PtrV,pos,0);
				fread(&RegV,sizeof(tpVendas),1,PtrV);
				InicioTela(C,L);
				printf("EXCLUSAO DE VENDAS");
				L+=2;
				gotoxy(C,L);
				printf("CODIGO DA VENDA: %d",RegV.CodVenda);
				L++;
				
				FILE *PtrCli = fopen("clientes.dat","rb+");
				
				poscli=BuscaCPF(PtrCli,RegV.cpf);
				fseek(PtrCli,poscli,0);
				fread(&RegCli,sizeof(tpClientes),1,PtrCli);
				
				gotoxy(C,L);
				printf("CLIENTE: %s",RegCli.NomeC);
				L++;
				gotoxy(C,L);
				printf("CPF CLIENTE: ");
				for(j=0;j<11;j++)
				{
					printf("%c",RegCli.cpf[j]);
					if((j!=8) && (j+1)%3==0)
						printf(".");
					if(j==8)
						printf("-");
				}
				L++;
				gotoxy(C,L);
				printf("DATA: %d/%d/%d | TOTAL: R$ %.2f",RegV.DtVenda.d,RegV.DtVenda.m,RegV.DtVenda.a,RegV.TotVenda);
				EscrMsg();
				printf("CONFIRMA A EXCLUSAO (S/N)?");
				if(toupper(getch())=='S')
				{
					FILE *PtrVP = fopen("vendasprod.dat","rb+");
					FILE *PtrProd = fopen("produtos.dat","rb+");
					
					fseek(PtrVP,0,2);
					QtdeVP = ftell(PtrVP)/sizeof(tpVendas_Prod);
					
					for(i=0;i<QtdeVP;i++)
					{
						fseek(PtrVP,i*sizeof(tpVendas_Prod),0);
						fread(&RegVP,sizeof(tpVendas_Prod),1,PtrVP);
						if(RegVP.CodVenda==RegV.CodVenda)
						{
							posprod=BuscaCodProd(PtrProd,RegVP.CodProd);
							fseek(PtrProd,posprod,0);
							fread(&RegProd,sizeof(tpProdutos),1,PtrProd);
							RegProd.Estoque+=RegVP.Qtde;
							fseek(PtrProd,posprod,0);
							fwrite(&RegProd,sizeof(tpProdutos),1,PtrProd);
							RegVP.Status = 'I';
							fseek(PtrVP,i*sizeof(tpVendas_Prod),0);
							fwrite(&RegVP,sizeof(tpVendas_Prod),1,PtrVP);
						}
					}
					TotMenos=RegV.TotVenda;
					RegV.Status='I';
					fseek(PtrV,pos,0);
					fwrite(&RegV,sizeof(tpVendas),1,PtrV);
					RegCli.QtdeCompras-=1;
					RegCli.ValorTotComp-=TotMenos;
					fseek(PtrCli,poscli,0);
					fwrite(&RegCli,sizeof(tpClientes),1,PtrCli);
					EscrMsg();
					printf("VENDA EXCLUIDA!");
					fclose(PtrVP);
					fclose(PtrCli);
					fclose(PtrProd);
				}
				else
				{
					EscrMsg();
					printf("EXCLUSAO CANCELADA!");
				}
				getch();
			}
			if(QtdeVendas(PtrV)!=0)
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("EXCLUSAO DE VENDAS");
				L+=2;
				gotoxy(C,L);
				printf("CODIGO DA VENDA:");
				LimpaEntrada();
				ValidaInt(RegV.CodVenda);
			}
			else
			{
				EscrMsg();
				printf("NAO EXISTEM VENDAS CADASTRADAS!");
				getch();
				RegV.CodVenda=0;
			}
		}
		fclose(PtrV);
	}
}

void ExcCli(void)
{
	tpClientes RegCli;
	int pos,posVenda,i,j,C,L,VCPF,Qtde;
	
	FILE *PtrCli = fopen("clientes.dat","rb+");
	Qtde = QtdeCli(PtrCli);
	
	if(Qtde==0)
	{
		EscrMsg();
		printf("NAO EXISTEM CLIENTES CADASTRADOS!");
		getch();
	}
	else
	{
		InicioTela;
		textcolor(12);
		gotoxy(3,11);
		printf("[C] EXCLUSAO");
		textcolor(15);
		InicioTela(C,L);
		printf("EXCLUSAO DE CLIENTES");
		L+=2;
		gotoxy(C,L);
		printf("CPF DO CLIENTE: ");
		LimpaEntrada();
		strcpy(RegCli.cpf,ValidaString());
		while(strcmp(RegCli.cpf,"0"))
		{
			VCPF=ValidaCPF(RegCli.cpf);
			if(VCPF==0)
			{
				EscrMsg();
				printf("CPF INVALIDO!");
				getch();
			}
			else
			{
				pos=BuscaCPF(PtrCli,RegCli.cpf);
				if(pos==-1)
				{
					EscrMsg();
					printf("CLIENTE NAO CADASTRADO");
				}
				else
				{
					fseek(PtrCli,pos,0);
					fread(&RegCli,sizeof(tpClientes),1,PtrCli);
					InicioTela(C,L);
					printf("EXCLUSAO DE CLIENTES");
					L+=2;
					gotoxy(C,L);
					printf("CPF: ");
					for(j=0;j<11;j++)
					{
						printf("%c",RegCli.cpf[j]);
						if((j!=8) && (j+1)%3==0)
							printf(".");
						if(j==8)
							printf("-");
					}
					L++;
					gotoxy(C,L);
					printf("NOME: %s",RegCli.NomeC);
					L++;
					gotoxy(C,L);
					printf("QUANTIADE DE COMPRAS: %d",RegCli.QtdeCompras);
					L++;
					gotoxy(C,L);
					printf("VALOR TOTAL COMPRADO: R$ %.2f",RegCli.ValorTotComp);
					EscrMsg();
					printf("CONFIRMA A EXCLUSAO (S/N)?");
					if(toupper(getch())=='S')
					{
						if(RegCli.QtdeCompras==0)
						{
							RegCli.Status = 'I';
							fseek(PtrCli,pos,0);
							fwrite(&RegCli,sizeof(tpClientes),1,PtrCli);
							EscrMsg();
							printf("CLIENTE EXCLUIDO!");
						}
						else
						{
							EscrMsg();
							printf("NAO E POSSIVEL EXCLUIR CLIENTE ATIVO!");
						}
					}
					else
					{
						EscrMsg();
						printf("EXCLUSAO CANCELADA!");
					}
				}
				getch();
			}
			if(Qtde==0)
			{
				EscrMsg();
				printf("NAO EXISTEM CLIENTES CADASTRADOS!");
				getch();
				strcpy(RegCli.cpf,"0");
			}
			else
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("CPF DO CLIENTE: ");
				LimpaEntrada();
				fflush(stdin);
				gets(RegCli.cpf);
			}
		}
		fclose(PtrCli);
	}
	LimpaEntrada();
}

void ExcProd(void)
{
	tpProdutos RegProd;
	tpFornecedores RegForn;
	tpVendas_Prod RegVP;
	int Cod,pos,posForn,i,C,L,posProdVenda,Qtde;
	
	FILE *PtrProd = fopen("produtos.dat","rb+");
	Qtde = QtdeProd(PtrProd);
	
	if(Qtde==0)
	{
		EscrMsg();
		printf("NAO EXISTEM PRODUTOS CADASTRADOS!");
		getch();
	}
	else
	{
		FILE *PtrForn = fopen("forn.dat","rb");
		InicioTela;
		textcolor(12);
		gotoxy(3,11);
		printf("[C] EXCLUSAO");
		textcolor(15);
		InicioTela(C,L);
		printf("EXCLUSAO DE PRODUTOS");
		L+=2;
		gotoxy(C,L);
		printf("CODIGO DO PRODUTO: ");
		LimpaEntrada();
		ValidaInt(RegProd.CodProd);
		while(RegProd.CodProd>0)
		{
			pos=BuscaCodProd(PtrProd,RegProd.CodProd);
			if(pos==-1)
			{
				EscrMsg();
				printf("PRODUTO NAO CADASTRADO!");
				getch();
			}
			else
			{
				fseek(PtrProd,pos,0);
				fread(&RegProd,sizeof(tpProdutos),1,PtrProd);
				InicioTela(C,L);
				printf("EXCLUSAO DE PRODUTOS");
				L+=2;
				gotoxy(C,L);
				printf("CODIGO: %d",RegProd.CodProd);
				L++;
				gotoxy(C,L);
				printf("DESCRICAO: %s",RegProd.Descr);
				L++;
				gotoxy(C,L);
				posForn=BuscaCodForn(PtrForn,RegProd.CodForn);
				fseek(PtrForn,posForn,0);
				fread(&RegForn,sizeof(tpFornecedores),1,PtrForn);
				printf("FORNECEDOR [%d] - %s",RegProd.CodForn,RegForn.NomeForn);
				L++;
				gotoxy(C,L);
				printf("ESTOQUE: %d   -   ",RegProd.Estoque);
				printf("PRECO: R$ %.2f",RegProd.Preco);
				L++;
				gotoxy(C,L);
				printf("VALIDADE: %d/%d/%d",RegProd.DtValidade.d,RegProd.DtValidade.m,RegProd.DtValidade.a);
				EscrMsg();
				printf("CONFIRMA A EXCLUSAO (S/N)?");
				if(toupper(getch())=='S')
				{
					if(RegProd.Estoque == 0)
					{
						FILE *PtrVP = fopen("vendasprod.dat","rb");
						posProdVenda = BuscaVendaProd(PtrVP,RegProd.CodProd);
						fseek(PtrVP,posProdVenda,0);
						fread(&RegVP,sizeof(tpVendas_Prod),1,PtrVP);
						if(posProdVenda==-1)
						{
							RegProd.Status = 'I';
							fseek(PtrProd,pos,0);
							fwrite(&RegProd,sizeof(tpProdutos),1,PtrProd);
							EscrMsg();
							printf("PRODUTO EXCLUIDO COM SUCESSO!");
						}	
						else
						{
							EscrMsg();
							printf("NAO E POSSIVEL EXCLUIR O PRODUTO!");
						}
						fclose(PtrVP);
					}
					else
					{
						EscrMsg();
						printf("NAO E POSSIVEL EXCLUIR PRODUTO COM ESTOQUE!");
					}
				}
				else
				{
					EscrMsg();
					printf("EXCLUSAO CANCELADA!");
				}
				getch();
			}
			if(Qtde==0)
			{
				EscrMsg();
				printf("NAO EXISTEM PRODUTOS CADASTRADOS!");
				getch();
				RegProd.CodProd=0;
			}
			else
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("CODIGO DO PRODUTO: ");
				LimpaEntrada();
				ValidaInt(RegProd.CodProd);
			}
		}
		fclose(PtrForn);
		fclose(PtrProd);
	}
	LimpaEntrada();
}

void ExcForn(void)
{
	tpFornecedores RegForn;
	tpProdutos RegProd;
	int pos,posProd,i,C,L;
	
	FILE *PtrForn = fopen("forn.dat","rb+");
	
	if(QtdeForn(PtrForn)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM FORNECEDORES CADASTRADOS!");
		getch();
	}
	else
	{
		InicioTela;
		textcolor(12);
		gotoxy(3,11);
		printf("[C] EXCLUSAO");
		textcolor(15);
		InicioTela(C,L);
		printf("EXCLUSAO DE FORNECEDORES");
		L+=2;
		gotoxy(C,L);
		printf("CODIGO DO FORNECEDOR: ");
		LimpaEntrada();
		ValidaInt(RegForn.CodForn);
		while(RegForn.CodForn!=0)
		{
			pos=BuscaCodForn(PtrForn,RegForn.CodForn);
			if(pos==-1)
			{
				EscrMsg();
				printf("FORNECEDOR NAO CADASTRADO!");
				getch();
			}
			else
			{
				fseek(PtrForn,pos,0);
				fread(&RegForn,sizeof(tpFornecedores),1,PtrForn);
				InicioTela(C,L);
				printf("EXCLUSAO DE FORNECEODRES");
				L+=2;
				gotoxy(C,L);
				printf("CODIGO: %d", RegForn.CodForn);
				L++;
				gotoxy(C,L);
				printf("NOME: %s", RegForn.NomeForn);
				L++;
				gotoxy(C,L);
				printf("CIDADE: %s", RegForn.Cidade);
				L++;
				EscrMsg();
				printf("CONFIRMA A EXCLUSAO (S/N)?");
				if(toupper(getche())=='S')
				{
					FILE *PtrProd = fopen("produtos.dat","rb");
					posProd=BuscaFornProd(PtrProd,RegForn.CodForn);
					if(posProd==-1)
					{
						RegForn.Status = 'I';
						fseek(PtrForn,pos,0);
						fwrite(&RegForn,sizeof(tpFornecedores),1,PtrForn);
						EscrMsg();
						printf("FORNECEDOR EXCLUIDO!");
					}
					else
					{
						EscrMsg();
						printf("NAO E POSSIVEL EXCLUIR FORNECEDOR ATIVO!");
					}
					fclose(PtrProd);
				}
				else
				{
					EscrMsg();
					printf("EXCLUSAO CANCELADA!");
				}
				getch();
			}
			if(QtdeForn(PtrForn)==0)
			{
				EscrMsg();
				printf("NAO EXISTEM FORNECEDORES CADASTRADOS!");
				getch();
				RegForn.CodForn=0;
			}
			else
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("CODIGO DO FORNECEDOR:");
				LimpaEntrada();
				ValidaInt(RegForn.CodForn);
			}
		}
		fclose(PtrForn);
	}
}

void AltCli(void)
{
	tpClientes R;
	int i,C,L,pos;
	char CPF[11];
	
	FILE *Ptr = fopen("clientes.dat","rb+");
	
	if(QtdeCli(Ptr)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM CLIENTES CADASTRADOS!");
		getch();
	}
	else
	{
		textcolor(12);
		gotoxy(3,12);
		printf("[D] ALTERACAO");
		textcolor(15);
		InicioTela(C,L);
		printf("ALTERACAO DE CLIENTES");
		gotoxy(31,9);
		printf("CPF DO CLIENTE: ");
		LimpaEntrada();
		strcpy(R.cpf,ValidaString());
		while(strcmp(R.cpf,"0")!=0)
		{
			pos=BuscaCPF(Ptr,R.cpf);
			if(pos==-1)
			{
				EscrMsg();
				printf("CLIENTE NAO ENCONTRADO!");
				getch();
				EscrMsg();
				printf("DESEJA FAZER OUTRA ALTERACAO (S/N)?");
				if((toupper(getch()))=='S')
				{
					InicioTela(C,L);
					printf("ALTERACAO DE CLIENTES");
					gotoxy(31,9);
					printf("CPF DO CLIENTE: ");
					LimpaMsg();
					LimpaEntrada();
					strcpy(R.cpf,ValidaString());
				}
				else
				{
					EscrMsg();
					printf("MENU DE ALTERACAO ENCERRADO!");
					LimpaEntrada();
					getch();
					strcpy(R.cpf,"0");
				}
			}
			else
			{
				fseek(Ptr,pos,0);
				fread(&R,sizeof(tpClientes),1,Ptr);
				InicioTela(C,L);
				gotoxy(C,L);
				printf("CPF: ");
				for(i=0;i<11;i++)
				{
					printf("%c",R.cpf[i]);
					if((i!=8) && (i+1)%3==0)
						printf(".");
					if(i==8)
						printf("-");
				}
				L++;
				gotoxy(C,L);
				printf("NOME: %s",R.NomeC);
				L++;
				gotoxy(C,L);
				printf("QUANTIDADE DE COMPRAS: %d",R.QtdeCompras);
				L++;
				gotoxy(C,L);
				printf("VALOR TOTAL COMPRADO: R$ %.2f",R.ValorTotComp);
				L+=2;
				EscrMsg();
				printf("DESEJA ALTERAR O NOME DO CLIENTE (S/N)?");
				if((toupper(getch()))=='S')
				{
					LimpaMsg();
					InicioTela(C,L);
					printf("ALTERACAO DE CLIENTES");
					gotoxy(31,9);
					printf("NOVO NOME: ");
					LimpaEntrada();
					strcpy(R.NomeC,ValidaString());
					if(strcmp(R.NomeC,"0")==0)
					{
						EscrMsg();
						printf("ALTERACAO CANCELADA!");
						getch();
					}
					else
					{
						strupr(R.NomeC);
						gotoxy(31,9);
						printf("NOVO NOME: %s",R.NomeC);
						EscrMsg();
						printf("CONFIRMA ALTERACAO (S/N)?");
						if((toupper(getch()))=='S')
						{
							fseek(Ptr,pos,0);
							fwrite(&R,sizeof(tpClientes),1,Ptr);
							EscrMsg();
							printf("ALTERACAO REALIZADA COM SUCESSO!");	
							getch();
						}
					}
				}
				EscrMsg();
				printf("DESEJA REALIZAR OUTRA ALTERACAO (S/N)?");
				if((toupper(getch()))=='S')
				{
					InicioTela(C,L);
					printf("ALTERACAO DE CLIENTES");
					gotoxy(31,9);
					printf("CPF DO CLIENTE: ");
					LimpaMsg();
					LimpaEntrada();
					strcpy(R.cpf,ValidaString());
				}
				else
				{
					EscrMsg();
					printf("MENU DE ALTERACAO ENCERRADO!");
					LimpaEntrada();
					getch();
					strcpy(R.cpf,"0");
				}
			}
		}
		fclose(Ptr);
	}
	LimpaEntrada();
}

void AltProd(void)
{
	tpProdutos R;
	tpFornecedores RF;
	int i,C,L,pos,posForn;
	char resp;
	
	FILE *Ptr = fopen("produtos.dat","rb+");
	FILE *PtrForn = fopen("forn.dat","rb");
	
	if(QtdeProd(Ptr)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM PRODUTOS CADASTRADOS!");
		getch();
	}
	else
	{
		textcolor(12);
		gotoxy(3,12);
		printf("[D] ALTERACAO");
		textcolor(15);
		InicioTela(C,L);
		printf("ALTERACAO DE PRODUTOS");
		gotoxy(31,9);
		printf("CODIGO DO PRODUTO:");
		LimpaEntrada();
		ValidaInt(R.CodProd);
		while(R.CodProd>0)
		{
			pos=BuscaCodProd(Ptr,R.CodProd);
			if(pos==-1)
			{
				EscrMsg();
				printf("PRODUTO NAO ENCONTRADO!");
				getch();				
				EscrMsg();
				printf("DESEJA FAZER OUTRA ALTERACAO (S/N)?");
				if((toupper(getch()))=='S')
				{
					InicioTela(C,L);
					printf("ALTERACAO DE PRODUTOS");
					gotoxy(31,9);
					printf("CODIGO DO PRODUTO: ");
					LimpaMsg();
					LimpaEntrada();
					ValidaInt(R.CodProd);
				}
				else
				{
					EscrMsg();
					printf("MENU DE ALTERACAO ENCERRADO!");
					LimpaEntrada();
					getch();
					R.CodProd=0;
				}
			}
			else
			{
				fseek(Ptr,pos,0);
				fread(&R,sizeof(tpProdutos),1,Ptr);
				InicioTela(C,L);
				printf("ALTERACAO DE PRODUTOS");
				L+=2;
				gotoxy(C,L);
				printf("CODIGO: %d",R.CodProd);
				L++;
				gotoxy(C,L);
				printf("[A] DESCRICAO: %s",R.Descr);
				L++;
				gotoxy(C,L);
				posForn=BuscaCodForn(PtrForn,R.CodForn);
				fseek(PtrForn,posForn,0);
				fread(&RF,sizeof(tpFornecedores),1,PtrForn);
				printf("[B] FORNECEDOR [%d] - %s",RF.CodForn,RF.NomeForn);
				L++;
				gotoxy(C,L);
				printf("[C] ESTOQUE: %d",R.Estoque);
				L++;
				gotoxy(C,L);
				printf("[D] PRECO: R$ %.2f",R.Preco);
				L++;
				gotoxy(C,L);
				printf("[E] VALIDADE: %d/%d/%d",R.DtValidade.d,R.DtValidade.m,R.DtValidade.a);
				L+=2;
				gotoxy(C,L);
				printf("ESCOLHA UMA OPCAO DE ALTERACAO!");
				LimpaEntrada();
				resp=toupper(getch());
				if(resp=='A')
				{
					LimpaMsg();
					InicioTela(C,L);
					printf("ALTERACAO DE PRODUTOS");
					gotoxy(31,9);
					printf("NOVA DESCRICAO: ");
					LimpaEntrada();
					strcpy(R.Descr,ValidaString());
					if(strcmp(R.Descr,"0")==0)
					{
						EscrMsg();
						printf("ALTERACAO CANCELADA!");
						getch();
					}
					else
					{
						strupr(R.Descr);
						gotoxy(31,9);
						printf("NOVA DESCRICAO: %s",R.Descr);
						EscrMsg();
						printf("CONFIRMA ALTERACAO (S/N)?");
						if((toupper(getch()))=='S')
						{
							fseek(Ptr,pos,0);
							fwrite(&R,sizeof(tpProdutos),1,Ptr);
							EscrMsg();
							printf("ALTERACAO REALIZADA COM SUCESSO!");
							getch();
						}
					}
				}
				else
				{
					if(resp=='B')
					{
						LimpaMsg();
						InicioTela(C,L);
						printf("ALTERACAO DE PRODUTOS");
						gotoxy(31,9);
						printf("NOVO FORNECEDOR:");
						LimpaEntrada();
						ValidaInt(R.CodForn);
						posForn = BuscaCodForn(PtrForn,R.CodForn);
						while(R.CodForn!=0 && posForn==-1)
						{
							EscrMsg();
							printf("FORNECEDOR NAO ENCONTRADO!");
							getch();
							LimpaMsg();
							LimpaEntrada();
							ValidaInt(R.CodForn);
							posForn = BuscaCodForn(PtrForn,R.CodForn);
						}
						if(R.CodForn==0)
						{
							EscrMsg();
							printf("ALTERACAO CANCELADA!");
							getch();
						}
						else
						{
							fseek(PtrForn,posForn,0);
							fread(&RF,sizeof(tpFornecedores),1,PtrForn);
							gotoxy(31,9);
							printf("NOVO FORNECEDOR: [%d] - %s",R.CodForn,RF.NomeForn);
							EscrMsg();
							printf("CONFIRMA ALTERACAO (S/N)?");
							if((toupper(getch()))=='S')
							{
								fseek(Ptr,pos,0);
								fwrite(&R,sizeof(tpProdutos),1,Ptr);
								EscrMsg();
								printf("ALTERACAO REALIZADA COM SUCESSO!");
								getch();
							}
						}
					}
					else
					{
						if(resp=='C')
						{
							LimpaMsg();
							InicioTela(C,L);
							printf("ALTERACAO DE PRODUTOS");
							gotoxy(31,9);
							printf("NOVO ESTOQUE: ");
							LimpaEntrada();
							ValidaInt(R.Estoque);
							gotoxy(31,9);
							printf("NOVO ESTOQUE: %d",R.Estoque);
							EscrMsg();
							printf("CONFIRMA ALTERACAO (S/N)?");
							if((toupper(getch()))=='S')
							{
								fseek(Ptr,pos,0);
								fwrite(&R,sizeof(tpFornecedores),1,Ptr);
								EscrMsg();
								printf("ALTERACAO REALIZADA COM SUCESSO!");
								getch();
							}
						}
						else
						{
							if(resp=='D')
							{
								LimpaMsg();
								InicioTela(C,L);
								printf("ALTERACAO DE FORNECEDORES");
								gotoxy(31,9);
								printf("NOVO PRECO: ");
								LimpaEntrada();
								ValidaFloat(R.Preco);
								if(R.Preco==0)
								{
									EscrMsg();
									printf("ALTERACAO CANCELADA!");
									getch();
								}
								else
								{
									gotoxy(31,9);
									printf("NOVO PRECO: R$ %.2f",R.Preco);
									EscrMsg();
									printf("CONFIRMA ALTERACAO (S/N)?");
									if((toupper(getch()))=='S')
									{
										fseek(Ptr,pos,0);
										fwrite(&R,sizeof(tpFornecedores),1,Ptr);
										EscrMsg();
										printf("ALTERACAO REALIZADA COM SUCESSO!");
										getch();
									}
								}
							}
							else
								if(resp=='E')
								{
									LimpaMsg();
									InicioTela(C,L);
									printf("ALTERACAO DE PRODUTOS");
									gotoxy(31,9);
									printf("NOVA DATA DE VALIDADE: ");
									LimpaEntrada();
									ValidaData(R.DtValidade.d,R.DtValidade.m,R.DtValidade.a);
									if((R.DtValidade.d==0) && (R.DtValidade.m==0) && (R.DtValidade.a==0))
									{
										EscrMsg();
										printf("ALTERACAO CANCELADA!");
										getch();
									}
									else
									{
										gotoxy(31,9);
										printf("NOVA DATA DE VALIDADE: %d/%d/%d",R.DtValidade.d,R.DtValidade.m,R.DtValidade.a);
										EscrMsg();
										printf("CONFIRMA ALTERACAO (S/N)?");
										if((toupper(getch()))=='S')
										{
											fseek(Ptr,pos,0);
											fwrite(&R,sizeof(tpProdutos),1,Ptr);
											EscrMsg();
											printf("ALTERACAO REALIZADA COM SUCESSO!");
											getch();
										}
									}
								}
						}
					}
				}
				EscrMsg();
				printf("DESEJA FAZER OUTRA ALTERACAO (S/N)?");
				if((toupper(getch()))=='S')
				{
					InicioTela(C,L);
					printf("ALTERACAO DE PRODUTOS");
					gotoxy(31,9);
					printf("CODIGO DO PRODUTO: ");
					LimpaMsg();
					LimpaEntrada();
					ValidaInt(R.CodProd);
				}
				else
				{
					EscrMsg();
					printf("MENU DE ALTERACAO ENCERRADO!");
					LimpaEntrada();
					getch();
					R.CodProd=0;
				}
			}
		}
		fclose(Ptr);
	}
	LimpaEntrada();
}

void AltForn(void)
{
	tpFornecedores R;
	int i,C,L,pos;
	char resp;
	
	FILE *Ptr = fopen("forn.dat","rb+");
	
	if(QtdeForn(Ptr)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM FORNECEDORES CADASTRADOS!");
		getch();
	}
	else
	{
		textcolor(12);
		gotoxy(3,12);
		printf("[D] ALTERACAO");
		textcolor(15);
		InicioTela(C,L);
		printf("ALTERACAO DE FORNECEDORES");
		gotoxy(31,9);
		printf("CODIGO DO FORNECEDOR: ");
		LimpaEntrada();
		ValidaInt(R.CodForn);
		while(R.CodForn>0)
		{
			pos=BuscaCodForn(Ptr,R.CodForn);
			if(pos==-1)
			{
				EscrMsg();
				printf("FORNECEDOR NAO ENCONTRADO!");
				EscrMsg();
				printf("DESEJA FAZER OUTRA ALTERACAO? [S/N]");
				if((toupper(getch()))=='S')
				{
					InicioTela(C,L);
					printf("ALTERACAO DE FORNECEDORES");
					gotoxy(31,9);
					printf("CODIGO DO FORNECEDOR: ");
					LimpaMsg();
					LimpaEntrada();
					ValidaInt(R.CodForn);
				}
				else
				{
					EscrMsg();
					printf("MENU DE ALTERACAO ENCERRADO!");
					LimpaEntrada();
					getch();
					R.CodForn=0;
				}
			}
			else
			{
				fseek(Ptr,pos,0);
				fread(&R,sizeof(tpFornecedores),1,Ptr);
				InicioTela(C,L);
				printf("ALTERACAO DE FORNECEDORES");
				L+=2;
				gotoxy(C,L);
				printf("CODIGO: %d",R.CodForn);
				L++;
				gotoxy(C,L);
				printf("[A] NOME: %s",R.NomeForn);
				L++;
				gotoxy(C,L);
				printf("[B] CIDADE: %s",R.Cidade);
				L+=2;
				EscrMsg();
				printf("ESCOLHA UMA OPCAO DE ALTERACAO!");
				LimpaEntrada();
				resp=toupper(getch());
				if(resp=='A')
				{
					LimpaMsg();
					InicioTela(C,L);
					printf("ALTERACAO DE FORNECEDORES");
					gotoxy(31,9);
					printf("NOVO NOME: ");
					LimpaEntrada();
					strcpy(R.NomeForn,ValidaString());
					if(strcmp(R.NomeForn,"0")==0)
					{
						EscrMsg();
						printf("ALTERACAO CANCELADA!");
						getch();
					}
					else
					{
						strupr(R.NomeForn);
						gotoxy(31,9);
						printf("NOVO NOME: %s",R.NomeForn);
						EscrMsg();
						printf("CONFIRMA ALTERACAO (S/N)?");
						if((toupper(getch()))=='S')
						{
							fseek(Ptr,pos,0);
							fwrite(&R,sizeof(tpFornecedores),1,Ptr);
							EscrMsg();
							printf("ALTERACAO REALIZADA COM SUCESSO!");
							getch();
						}
					}
				}
				else
					if(resp=='B')
					{
						LimpaMsg();
						InicioTela(C,L);
						printf("ALTERACAO DE FORNECEDORES");
						gotoxy(31,9);
						printf("NOVA CIDADE: ");
						LimpaEntrada();
						strcpy(R.Cidade,ValidaString());
						if(strcmp(R.Cidade,"0")==0)
						{
							EscrMsg();
							printf("ALTERACAO CANCELADA!");
							getch();
						}
						else
						{
							strupr(R.Cidade);
							gotoxy(31,9);
							printf("NOVA CIDADE: %s",R.Cidade);
							EscrMsg();
							printf("CONFIRMA ALTERACAO (S/N)?");
							if((toupper(getch()))=='S')
							{
								fseek(Ptr,pos,0);
								fwrite(&R,sizeof(tpFornecedores),1,Ptr);
								EscrMsg();
								printf("ALTERACAO REALIZADA COM SUCESSO!");
								getch();
							}
						}
					}
				EscrMsg();
				printf("DESEJA REALIZAR OUTRA ALTERACAO (S/N)?");
				if((toupper(getch()))=='S')
				{
					InicioTela(C,L);
					printf("ALTERACAO DE FORNECEDORES");
					gotoxy(31,9);
					printf("CODIGO DO FORNECEDOR: ");
					LimpaMsg();
					LimpaEntrada();
					ValidaInt(R.CodForn);
				}
				else
				{
					EscrMsg();
					printf("MENU DE ALTERACAO ENCERRADO!");
					LimpaEntrada();
					getch();
					R.CodForn=0;
				}
			}
		}
		fclose(Ptr);
	}
	LimpaEntrada();
}

void AumentoForn(void)
{
	tpProdutos RP;
	tpFornecedores RF;
	int C,L,i,posForn,Qtde,rep=0;
	float porc;
	
	FILE *PtrForn = fopen("forn.dat","rb");
	
	if(QtdeForn(PtrForn) == 0)
	{
		EscrMsg();
		printf("NAO EXISTEM FORNECEDORES CADASTRADOS!");
		getch();
	}
	else
	{
		FILE *PtrProd = fopen("produtos.dat","rb+");
		if(PtrProd == NULL)
		{
			EscrMsg();
			printf("NAO EXISTEM PRODUTOS CADASTRADOS!");
			getch();
		}
		else
		{
			LimpaMsg();
			LimpaTela();
			textcolor(12);
			gotoxy(3,14);
			printf("[F] AUMENTO DE PRECOS");
			textcolor(15);
			InicioTela(C,L);
			printf("AUMENTO DE PRECO DE FORNECEDORES");
			gotoxy(C,L);
			L+=2;
			gotoxy(C,L);
			printf("CODIGO DO FORNECEDOR: ");
			L++;
			LimpaEntrada();
			ValidaInt(RF.CodForn);
			while(RF.CodForn>0)
			{
				posForn=BuscaCodForn(PtrForn,RF.CodForn);
				if(posForn==-1)
				{
					EscrMsg();
					printf("FORNECEDOR NAO ENCONTRADO!");
					getch();
				}
				else
				{
					fseek(PtrForn,posForn,0);
					fread(&RF,sizeof(tpFornecedores),1,PtrForn);
					InicioTela(C,L);
					printf("AUMENTO DE PRECO DE FORNECEDORES");
					L+=2;
					gotoxy(C,L);
					printf("CODIGO [%d] - ",RF.CodForn);
					printf("%s",RF.NomeForn);
					L+=2;
					gotoxy(C,L);
					printf("INFORME A PORCENTAGEM DE AUMENTO:");
					LimpaEntrada();
					ValidaFloat(porc);
					EscrMsg();
					printf("CONFIRMA O AUMENTO DE %.2f%% (S/N)",porc);
					if(toupper(getch())=='S')
					{
						fseek(PtrProd,0,2);
						Qtde = ftell(PtrProd)/sizeof(tpProdutos);
						for(i=0;i<Qtde;i++)
						{
							fseek(PtrProd,i*sizeof(tpProdutos),0);
							fread(&RP,sizeof(tpProdutos),1,PtrProd);
							if(RF.CodForn == RP.CodForn)
							{
								RP.Preco*=(1+(porc/100));
								fseek(PtrProd,i*sizeof(tpProdutos),0);
								fwrite(&RP,sizeof(tpProdutos),1,PtrProd);
								rep=1;
							}
							//fread(&RP,sizeof(tpProdutos),1,PtrProd);
						}
						if(rep==1)
						{
							EscrMsg();
							printf("REPASSE EFETUADO COM SUCESSO!");
							getch();
						}
					}
					else
					{
						EscrMsg();
						printf("OPERACAO CANCELADA!");
						getch();
					}
				}
				LimpaMsg();
				InicioTela(C,L);
				printf("AUMENTO DE PRECO DE FORNECEORES");
				gotoxy(C,L);
				L+=2;
				gotoxy(C,L);
				printf("CODIGO DO FORNECEDOR: ");
				L++;
				LimpaEntrada();
				ValidaInt(RF.CodForn);
			}
			fclose(PtrProd);
		}
		fclose(PtrForn);
	}
}

void ConsultaCF(void)
{
	tpVendas_Prod RegVP;
	tpVendas RegVendas;
	tpClientes RegCli;
	tpProdutos RegProd;
	int Cod,C,L,i,posCPF,posProd,posCupom;
	
	FILE *PtrVendas = fopen("vendas.dat","rb");
	
	if(QtdeVendas(PtrVendas)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM CUPONS FISCAIS CADASTRADOS!");
		getch();
	}
	else
	{
		LimpaMsg();
		LimpaTela();
		textcolor(12);
		gotoxy(3,13);
		printf("[E] CONSULTAR CUPOM");
		textcolor(15);
		InicioTela(C,L);
		printf("INSIRA O CODIGO DA VENDA:");
		LimpaEntrada();
		ValidaInt(RegVendas.CodVenda);
		while(RegVendas.CodVenda>0)
		{
			posCupom=BuscaCupom(PtrVendas,RegVendas.CodVenda);
			if(posCupom==-1)
			{
				EscrMsg();
				printf("CUPOM FISCAL NAO ENCONTRADO!");
				getch();
			}
			else
			{
				fseek(PtrVendas,posCupom,0);
				fread(&RegVendas,sizeof(tpVendas),1,PtrVendas);
				InicioTela(C,L);
				gotoxy(C,L-1);
				printf("CUPOM FISCAL [%d]",RegVendas.CodVenda);
				gotoxy(67,L-1);
				printf("%d/%d/%d",RegVendas.DtVenda.d,RegVendas.DtVenda.m,RegVendas.DtVenda.a);
				L++;
				gotoxy(C,L);
				FILE *PtrCli = fopen("clientes.dat","rb");
				posCPF=BuscaCPF(PtrCli,RegVendas.cpf);
				fseek(PtrCli,posCPF,0);
				fread(&RegCli,sizeof(tpClientes),1,PtrCli);
				printf("CLIENTE %s - CPF: ",RegCli.NomeC);
				for(i=0;i<11;i++)
				{
					printf("%c",RegVendas.cpf[i]);
					if((i!=8) && (i+1)%3==0)
						printf(".");
					if(i==8)
						printf("-");
				}
				L++;
				gotoxy(C,L);
				printf("-----------------------------------------------");
				L++;
				gotoxy(C,L);
				printf("QTDE  ITEM  DESCR                       VALOR  ");
				FILE *PtrProd = fopen("produtos.dat","rb");
				FILE *PtrVP = fopen("vendasprod.dat","rb");
				fread(&RegVP,sizeof(tpVendas_Prod),1,PtrVP);
				i=0;
				while(!feof(PtrVP))
				{
					if(RegVP.CodVenda==RegVendas.CodVenda)
					{
						L++;
						posProd=BuscaCodProd(PtrProd,RegVP.CodProd);
						fseek(PtrProd,posProd,0);
						fread(&RegProd,sizeof(tpProdutos),1,PtrProd);
						gotoxy(C,L);
						printf("%d",RegVP.Qtde);
						gotoxy(37,L);
						printf("%d",RegVP.CodProd);
						gotoxy(43,L);
						printf("%s",RegProd.Descr);
						gotoxy(71,L);
						printf("%.2f",RegVP.ValorUni);
					}
					if(L%16==0)
					{
						fflush(stdin);
						getch();
						InicioTela(C,L);
					}
					i++;
					fread(&RegVP,sizeof(tpVendas_Prod),1,PtrVP);
				}
				if(L>14)
					InicioTela(C,L);
				L++;
				gotoxy(C,L);
				printf("-----------------------------------------------");
				L++;
				gotoxy(58,L);
				printf("TOTAL: R$ %.2f",RegVendas.TotVenda);
				getch();
				fclose(PtrCli);
				fclose(PtrProd);
			}
			EscrMsg();
			printf("CONSULTAR OUTRO CUPOM (S/N)?");
			if(toupper(getch())=='S')
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("INSIRA O CODIGO DA VENDA:");
				LimpaEntrada();
				ValidaInt(RegVendas.CodVenda);
			}
			else
				RegVendas.CodVenda=0;
		}
		fclose(PtrVendas);
	}
}

int VerMenuSec(int op)
{
	if(op!='A' && op!='B' && op!='C' && op!='D' && op!='E' && op!='R')
		return -1;
	else
		return op;
}

int VerMenuBackup(int op)
{
	if(op!='A' && op!='B'&& op!='C' && op!='R')
		return -1;
	else
		return op;
}


int VerMenuVendas(int op)
{
	if(op!='A' && op!='B' && op!='C' && op!='D' && op!='E' && op!='R')
		return -1;
	else
		return op;
}

int VerMenuForn(int op)
{
	if(op!='A' && op!='B' && op!='C' && op!='D' && op!='E' && op!='F' && op!='R')
		return -1;
	else
		return op;
}

int VerMenuP(int op)
{
	if(op!='C' && op!='P' && op!='B' && op!='F' && op!='V' && op!='I' && op!=27)
		return -1;
	else
		return op;
}

void Venda(void)
{
	tpClientes RC;
	tpProdutos RP;
	tpFornecedores RF;
	tpVendas RV;
	tpVendas_Prod RVP;
	int C,L,i,posCPF,posProd,posForn,posVenda,qtde,auxd,auxm,auxa,vpcpf,venda,QtdeV;
	float totvendaprod,totvenda;
	
	FILE *PtrCli = fopen("clientes.dat","rb+");
	FILE *PtrVP = fopen("vendasprod.dat","rb+");
	FILE *PtrVend = fopen("vendas.dat","ab+");
	
	fseek(PtrVend,0,2);
	QtdeV = ftell(PtrVend)/sizeof(tpVendas);
	
	for(i=0;i<QtdeV;i++)
	{
		fseek(PtrVend,i*sizeof(tpVendas),0);
		fread(&RV,sizeof(tpVendas),1,PtrVend);
		if(RV.Status=='A')
			venda=RV.CodVenda+1;
		else
			venda=1;
	}
	fseek(PtrVend,0,2);
		
	if(QtdeCli(PtrCli)==0)
	{
		EscrMsg();
		printf("NAO EXISTEM CLIENTES CADASTRADOS!");
		getch();
	}
	else
	{
		FILE *PtrProd = fopen("produtos.dat","rb+");
		if(PtrProd==NULL)
		{
			EscrMsg();
			printf("NAO EXISTEM PRODUTOS CADASTRADOS!");
			getch();
		}
		else
		{
			FILE *PtrForn = fopen("forn.dat","rb");
			LimpaMsg();
			LimpaTela();
			textcolor(12);
			gotoxy(3,9);
			printf("[A] REALIZAR VENDA");
			textcolor(15);
			InicioTela(C,L);
			printf("VENDA");
			gotoxy(C,L);
			L+=2;
			gotoxy(C,L);
			printf("CPF DO CLIENTE: ");
			L++;
			LimpaEntrada();
			strcpy(RC.cpf,ValidaString());
			while(strcmp(RC.cpf,"0")!=0)
			{
				vpcpf=0;
				totvenda=0;
				posCPF=BuscaCPF(PtrCli,RC.cpf);
				if(posCPF==-1)
				{
					EscrMsg();
					printf("CLIENTE NAO CADASTRADO!");
					getch();
				}
				else
				{
					fseek(PtrCli,posCPF,0);
					fread(&RC,sizeof(tpClientes),1,PtrCli);
					InicioTela(C,L);
					printf("VENDA: %d",venda);
					gotoxy(36,L);
					textcolor(15);
					L+=2;
					gotoxy(C,L);
					printf("DATA DA VENDA: ");
					ValidaData(auxd,auxm,auxa);
					gotoxy(46,L);
					printf("%d/%d/%d",auxd,auxm,auxa);
					L++;
					gotoxy(C,L);
					printf("CODIGO DO PRODUTO: ");
					LimpaEntrada();
					ValidaInt(RP.CodProd);
					while(RP.CodProd>0)
					{
						posProd=BuscaCodProd(PtrProd,RP.CodProd);
						if(posProd==-1)
						{
							EscrMsg();
							printf("PRODUTO NAO ENCONTRADO");
							getch();
						}
						else
						{
							fseek(PtrProd,posProd,0);
							fread(&RP,sizeof(tpProdutos),1,PtrProd);
							totvendaprod=0;
							InicioTela(C,L);
							printf("VENDA: ");
							printf("%d",venda);
							printf("     DATA: %d/%d/%d",auxd,auxm,auxa);
							L+=2;
							gotoxy(C,L);
							printf("CODIGO: %d",RP.CodProd);
							L++;
							gotoxy(C,L);
							printf("DESCRICAO: %s",RP.Descr);
							L++;
							gotoxy(C,L);
							posForn=BuscaCodForn(PtrForn,RP.CodForn);
							fseek(PtrForn,posForn,0);
							fread(&RF,sizeof(tpFornecedores),1,PtrForn);
							printf("FORNECEDOR [%d] - %s",RP.CodForn,RF.NomeForn);
							L++;
							gotoxy(C,L);
							printf("ESTOQUE: %d   -   ",RP.Estoque);
							printf("PRECO: R$ %.2f",RP.Preco);
							L++;
							gotoxy(C,L);
							printf("VALIDADE: %d/%d/%d",RP.DtValidade.d,RP.DtValidade.m,RP.DtValidade.a);
							EscrMsg();
							printf("CONFIRMA PRODUTO (S/N)?");
							if(toupper(getch())=='S')
							{
								LimpaMsg();
								L++;
								gotoxy(C,L);
								printf("QUANTIDADE: ");
								L+=2;
								LimpaEntrada();
								ValidaInt(qtde);
								if(qtde>0 && RP.Estoque>=qtde)
								{
									EscrMsg();
									totvendaprod = qtde*RP.Preco;
									gotoxy(C,L);
									printf("PRECO FINAL: %.2f",totvendaprod);
									EscrMsg();
									printf("CONFIRMA VENDA (S/N)?");
									if(toupper(getch())=='S')
									{
										RP.Estoque-=qtde;
										posVenda = BuscaProdVenda(PtrVP,RP.CodProd,venda);
										if(posVenda==-1)
										{
											RVP.Qtde=qtde;
											RVP.CodVenda=venda;
											RVP.CodProd=RP.CodProd;
											RVP.ValorUni=RP.Preco;
											fseek(PtrVP,0,2);
											vpcpf++;
										}
										else
										{
											fseek(PtrVP,posVenda,0);
											fread(&RVP,sizeof(tpVendas_Prod),1,PtrVP);
											RVP.Qtde+=qtde;
											fseek(PtrVP,posVenda,0);
										}
										RVP.Status='A';
										totvenda+=totvendaprod;
										fseek(PtrProd,posProd,0);
										fwrite(&RP,sizeof(tpProdutos),1,PtrProd);
										fwrite(&RVP,sizeof(tpVendas_Prod),1,PtrVP);
										EscrMsg();
										printf("VENDA DO PRODUTO REALIZADA!");
									}
									else
									{
										EscrMsg();
										printf("VENDA DO PRODUTO CANCELADA!");
									}
								}
								else
								{
									EscrMsg();
									printf("QUANTIDADE NAO DISPONIVEL EM ESTOQUE!");
								}
							}
							else
							{
								EscrMsg();
								printf("PRODUTO NAO ADICIONADO!");
							}
							getch();
							LimpaMsg();
							LimpaEntrada();
						}
						EscrMsg();
						printf("ADICIONAR OUTRO PRODUTO (S/N)?");
						if(toupper(getch())=='S')
						{
							InicioTela(C,L);
							printf("VENDA: ");
							printf("%d",venda);
							gotoxy(C,L);
							printf("CODIGO DO PRODUTO: ");
							L++;
							LimpaMsg();
							LimpaEntrada();
							ValidaInt(RP.CodProd);
						}
						else
							RP.CodProd=0;
					}
					if(vpcpf>0)
					{
						strcpy(RV.cpf,RC.cpf);
						RV.DtVenda.d=auxd;
						RV.DtVenda.m=auxm;
						RV.DtVenda.a=auxa;
						RV.TotVenda=totvenda;
						RV.CodVenda=venda;
						RV.Status='A';
						RC.QtdeCompras++;
						RC.ValorTotComp+=totvenda;
						EscrMsg();
						fseek(PtrCli,posCPF,0);
						fwrite(&RC,sizeof(tpClientes),1,PtrCli);
						fwrite(&RV,sizeof(tpVendas),1,PtrVend);
						printf("VENDA FINALIZADA");
						venda++;
						getch();
						LimpaMsg();
						InicioTela(C,L);
						gotoxy(C,L-1);
						printf("CUPOM FISCAL");
						gotoxy(67,L-1);
						printf("%d/%d/%d",RV.DtVenda.d=auxd,RV.DtVenda.m=auxm,RV.DtVenda.a=auxa);
						L++;
						gotoxy(C,L);
						printf("CLIENTE %s - CPF: ",RC.NomeC);
						for(i=0;i<11;i++)
						{
							printf("%c",RC.cpf[i]);
							if((i!=8) && (i+1)%3==0)
								printf(".");
							if(i==8)
								printf("-");
						}
						L++;
						gotoxy(C,L);
						printf("-----------------------------------------------");
						L++;
						gotoxy(C,L);
						printf("QTDE  ITEM  DESCR                       VALOR  ");
						rewind(PtrVP);
						fread(&RVP,sizeof(tpVendas_Prod),1,PtrVP);
						while(!feof(PtrVP))
						{
							if(RVP.CodVenda==RV.CodVenda)
							{
								posProd=BuscaCodProd(PtrProd,RVP.CodProd);
								fseek(PtrProd,posProd,0);
								fread(&RP,sizeof(tpProdutos),1,PtrProd);
								L++;
								gotoxy(C,L);
								printf("%d",RVP.Qtde);
								gotoxy(37,L);
								printf("%d",RVP.CodProd);
								gotoxy(43,L);
								printf("%s",RP.Descr);
								gotoxy(71,L);
								printf("%.2f",RVP.ValorUni);
							}
							if(L%16==0)
							{
								fflush(stdin);
								getch();
								InicioTela(C,L);
							}
							fread(&RVP,sizeof(tpVendas_Prod),1,PtrVP);
						}
						if(L>14)
							InicioTela(C,L);
						L++;
						gotoxy(C,L);
						printf("-----------------------------------------------");
						L++;
						gotoxy(58,L);
						printf("TOTAL: R$ %.2f",RV.TotVenda);
					}
					else
					{
						EscrMsg();
						printf("NENHUM PRODUTO VENDIDO");
					}
					getch();
				}
				EscrMsg();
				printf("REALIZAR NOVA VENDA (S/N)?");
				if(toupper(getch())=='S')
				{
					InicioTela(C,L);
					printf("VENDA");
					gotoxy(C,L);
					L+=2;
					gotoxy(C,L);
					printf("CPF DO CLIENTE: ");
					L++;
					LimpaMsg();
					LimpaEntrada();
					strcpy(RC.cpf,ValidaString());
				}
				else
				{
					EscrMsg();
					printf("MENU DE VENDAS ENCERRADO!");
					LimpaEntrada();
					getch();
					strcpy(RC.cpf,"0");
				}
			}
			fclose(PtrProd);
			fclose(PtrForn);
		}
		fclose(PtrCli);
	}
	fclose(PtrVend);
	fclose(PtrVP);
}

void Inserir(void)
{
	tpProdutos Prod;
	tpFornecedores Forn;
	tpClientes Cli;
	tpVendas Ven;
	tpVendas_Prod VP;
	
	FILE *PtrProd = fopen("produtos.dat","wb");
	
	Prod.CodProd=1000;
	strcpy(Prod.Descr,"SUCO");
	Prod.Status='A';
	Prod.Estoque=188;
	Prod.Preco=1.62;
	Prod.DtValidade.d=15;
	Prod.DtValidade.m=5;
	Prod.DtValidade.a=2025;
	Prod.CodForn=500;
	fwrite(&Prod,sizeof(tpProdutos),1,PtrProd);
	
	Prod.CodProd=4000;
	strcpy(Prod.Descr,"BISCOITO");
	Prod.Status='A';
	Prod.Estoque=63;
	Prod.Preco=4.56;
	Prod.DtValidade.d=22;
	Prod.DtValidade.m=11;
	Prod.DtValidade.a=2024;
	Prod.CodForn=300;
	fwrite(&Prod,sizeof(tpProdutos),1,PtrProd);
	
	Prod.CodProd=7000;
	strcpy(Prod.Descr,"LASANHA");
	Prod.Status='A';
	Prod.Estoque=52;
	Prod.Preco=9.98;
	Prod.DtValidade.d=10;
	Prod.DtValidade.m=9;
	Prod.DtValidade.a=2024;
	Prod.CodForn=200;
	fwrite(&Prod,sizeof(tpProdutos),1,PtrProd);
	fclose(PtrProd);
	
	FILE *PtrForn = fopen("forn.dat","wb");
	
	Forn.CodForn=200;
	strcpy(Forn.NomeForn,"FABRICA MATAO");
	strcpy(Forn.Cidade,"MATAO");
	Forn.Status='A';
	fwrite(&Forn,sizeof(tpFornecedores),1,PtrForn);
	
	Forn.CodForn=300;
	strcpy(Forn.NomeForn,"BASTECK");
	strcpy(Forn.Cidade,"GUARAPUAVA");
	Forn.Status='A';
	fwrite(&Forn,sizeof(tpFornecedores),1,PtrForn);
	
	Forn.CodForn=500;
	strcpy(Forn.NomeForn,"SAPORE S.A");
	strcpy(Forn.Cidade,"CAMPINAS");
	Forn.Status='A';
	fwrite(&Forn,sizeof(tpFornecedores),1,PtrForn);
	fclose(PtrForn);
	
	FILE *PtrCli = fopen("clientes.dat","wb");
	
	strcpy(Cli.cpf,"50388983000");
	strcpy(Cli.NomeC,"ARMELINDA");
	Cli.Status='A';
	Cli.QtdeCompras=11;
	Cli.ValorTotComp=1982.54;
	fwrite(&Cli,sizeof(tpClientes),1,PtrCli);
	
	strcpy(Cli.cpf,"64065512069");
	strcpy(Cli.NomeC,"ASTOLFO");
	Cli.Status='A';
	Cli.QtdeCompras=2;
	Cli.ValorTotComp=1450.25;
	fwrite(&Cli,sizeof(tpClientes),1,PtrCli);
	
	strcpy(Cli.cpf,"40456069801");
	strcpy(Cli.NomeC,"MATHEUS");
	Cli.Status='A';
	Cli.QtdeCompras=0;
	Cli.ValorTotComp=0;
	fwrite(&Cli,sizeof(tpClientes),1,PtrCli);
	
	strcpy(Cli.cpf,"48070830077");
	strcpy(Cli.NomeC,"WINDISLAISSON");
	Cli.Status='A';
	Cli.QtdeCompras=5;
	Cli.ValorTotComp=2841.63;
	fwrite(&Cli,sizeof(tpClientes),1,PtrCli);
	fclose(PtrCli);
	
	FILE *PtrV = fopen("vendas.dat","wb");
	
	Ven.CodVenda=1;
	strcpy(Ven.cpf,"64065512069");
	Ven.Status='A';
	Ven.DtVenda.d=10;
	Ven.DtVenda.m=8;
	Ven.DtVenda.a=2023;
	Ven.TotVenda=451.90;
	fwrite(&Ven,sizeof(tpVendas),1,PtrV);
	
	Ven.CodVenda=2;
	strcpy(Ven.cpf,"48070830077");
	Ven.Status='A';
	Ven.DtVenda.d=15;
	Ven.DtVenda.m=7;
	Ven.DtVenda.a=2023;
	Ven.TotVenda=45.60;
	fwrite(&Ven,sizeof(tpVendas),1,PtrV);
	
	Ven.CodVenda=3;
	strcpy(Ven.cpf,"50388983000");
	Ven.Status='A';
	Ven.DtVenda.d=6;
	Ven.DtVenda.m=4;
	Ven.DtVenda.a=2023;
	Ven.TotVenda=9.98;
	fwrite(&Ven,sizeof(tpVendas),1,PtrV);
	fclose(PtrV);
	
	FILE *PtrVP = fopen("vendasprod.dat","wb");
	
	VP.CodVenda=1;
	VP.Status='A';
	VP.CodProd=1000;
	VP.Qtde=10;
	VP.ValorUni=1.62;
	fwrite(&VP,sizeof(tpVendas_Prod),1,PtrVP);
	
	VP.CodVenda=1;
	VP.Status='A';
	VP.CodProd=7000;
	VP.Qtde=20;
	VP.ValorUni=9.98;
	fwrite(&VP,sizeof(tpVendas_Prod),1,PtrVP);
	
	VP.CodVenda=1;
	VP.Status='A';
	VP.CodProd=4000;
	VP.Qtde=53;
	VP.ValorUni=4.56;
	fwrite(&VP,sizeof(tpVendas_Prod),1,PtrVP);
	
	VP.CodVenda=2;
	VP.Status='A';
	VP.CodProd=4000;
	VP.Qtde=10;
	VP.ValorUni=4.56;
	fwrite(&VP,sizeof(tpVendas_Prod),1,PtrVP);
	
	VP.CodVenda=3;
	VP.Status='A';
	VP.CodProd=7000;
	VP.Qtde=1;
	VP.ValorUni=9.98;
	fwrite(&VP,sizeof(tpVendas_Prod),1,PtrVP);
	fclose(PtrVP);
	
	EscrMsg();
	printf("DADOS INSERIDOS COM SUCESSO!");
	getch();
}

void Backup(void)
{
	tpClientes C;
	tpFornecedores F;
	tpProdutos P;
	tpVendas V;
	tpVendas_Prod VP;
	
	FILE *PtrC = fopen("clientes.dat","rb");
	FILE *BC = fopen("bclientes.dat","wb");
	if(PtrC!=NULL)
	{
		fread(&C,sizeof(tpClientes),1,PtrC);
		while(!feof(PtrC))
		{
			fwrite(&C,sizeof(tpClientes),1,BC);
			fread(&C,sizeof(tpClientes),1,PtrC);
		}
		fclose(PtrC);
		fclose(BC);
	}
	
	FILE *PtrF = fopen("forn.dat","rb");
	FILE *BF = fopen("bforn.dat","wb");
	if(PtrC!=NULL)
	{
		fread(&F,sizeof(tpFornecedores),1,PtrF);
		while(!feof(PtrF))
		{
			fwrite(&F,sizeof(tpFornecedores),1,BF);
			fread(&F,sizeof(tpFornecedores),1,PtrF);
		}
		fclose(PtrF);
		fclose(BF);
	}
	
	FILE *PtrP = fopen("produtos.dat","rb");
	FILE *BP = fopen("bprodutos.dat","wb");
	if(PtrC!=NULL)
	{
		fread(&P,sizeof(tpProdutos),1,PtrP);
		while(!feof(PtrP))
		{
			fwrite(&P,sizeof(tpProdutos),1,BP);
			fread(&P,sizeof(tpProdutos),1,PtrP);
		}
		fclose(PtrP);
		fclose(BP);
	}
	
	FILE *PtrV = fopen("vendas.dat","rb");
	FILE *BV = fopen("bvendas.dat","wb");
	if(PtrC!=NULL)
	{
		fread(&V,sizeof(tpVendas),1,PtrV);
		while(!feof(PtrV))
		{
			fwrite(&V,sizeof(tpVendas),1,BV);
			fread(&V,sizeof(tpVendas),1,PtrV);
		}
		fclose(PtrV);
		fclose(BV);
	}
	
	FILE *PtrVP = fopen("vendasprod.dat","rb");
	FILE *BVP = fopen("bvendasprod.dat","wb");
	if(PtrC!=NULL)
	{
		fread(&VP,sizeof(tpVendas_Prod),1,PtrVP);
		while(!feof(PtrC))
		{
			fwrite(&VP,sizeof(tpVendas_Prod),1,BVP);
			fread(&VP,sizeof(tpVendas_Prod),1,PtrVP);
		}
		fclose(PtrVP);
		fclose(BVP);
	}
}

void LimpezaFisica(void)
{
	tpProdutos P;
	tpClientes C;
	tpFornecedores F;
	tpVendas V;
	tpVendas_Prod VP;
	int QtdeVP,QtdeV,i,j,k;
	
	FILE *PtrProd = fopen("produtos.dat","rb");
	FILE *PtrProdTemp = fopen("temp.dat","ab");
	fread(&P,sizeof(tpProdutos),1,PtrProd);
	while(!feof(PtrProd))
	{
		if(P.Status=='A')
			fwrite(&P,sizeof(tpProdutos),1,PtrProdTemp);
		fread(&P,sizeof(tpProdutos),1,PtrProd);
	}
	fclose(PtrProd);
	fclose(PtrProdTemp);
	remove("produtos.dat");
	rename("temp.dat","produtos.dat");
	
	FILE *PtrCli = fopen("clientes.dat","rb");
	FILE *PtrCliTemp = fopen("tempcli.dat","ab");
	fread(&C,sizeof(tpClientes),1,PtrCli);
	while(!feof(PtrCli))
	{
		if(C.Status=='A')
			fwrite(&C,sizeof(tpClientes),1,PtrCliTemp);
		fread(&C,sizeof(tpClientes),1,PtrCli);
	}
	fclose(PtrCli);
	fclose(PtrCliTemp);
	remove("clientes.dat");
	rename("tempcli.dat","clientes.dat");
	
	FILE *PtrForn = fopen("forn.dat","rb");
	FILE *PtrFornTemp = fopen("tempforn.dat","ab");
	fread(&F,sizeof(tpFornecedores),1,PtrForn);
	while(!feof(PtrForn))
	{
		if(F.Status=='A')
			fwrite(&F,sizeof(tpFornecedores),1,PtrFornTemp);
		fread(&F,sizeof(tpFornecedores),1,PtrForn);
	}
	fclose(PtrForn);
	fclose(PtrFornTemp);
	remove("forn.dat");
	rename("tempforn.dat","forn.dat");
	
	FILE *PtrVend = fopen("vendas.dat","rb");
	FILE *PtrVendTemp = fopen("tempv.dat","ab");
	fread(&V,sizeof(tpVendas),1,PtrVend);
	while(!feof(PtrVend))
	{
		if(V.Status=='A')
			fwrite(&V,sizeof(tpVendas),1,PtrVendTemp);
		fread(&V,sizeof(tpVendas),1,PtrVend);
	}
	fclose(PtrVend);
	fclose(PtrVendTemp);
	remove("vendas.dat");
	rename("tempv.dat","vendas.dat");
	
	FILE *PtrVP = fopen("vendasprod.dat","rb");
	FILE *PtrVPTemp = fopen("tempvp.dat","ab");
	fread(&VP,sizeof(tpVendas_Prod),1,PtrVP);
	while(!feof(PtrVP))
	{
		if(VP.Status=='A')
			fwrite(&VP,sizeof(tpVendas_Prod),1,PtrVPTemp);
		fread(&VP,sizeof(tpVendas_Prod),1,PtrVP);
	}
	fclose(PtrVP);
	fclose(PtrVPTemp);
	remove("vendasprod.dat");
	rename("tempvp.dat","vendasprod.dat");
	
	FILE *PtrOrdV = fopen("vendas.dat","rb+");
	FILE *PtrOrdVP = fopen("vendasprod.dat","rb+");
	
	fseek(PtrOrdV,0,2);
	fseek(PtrOrdVP,0,2);
	
	QtdeV = ftell(PtrOrdV)/sizeof(tpVendas);
	QtdeVP = ftell(PtrOrdVP)/sizeof(tpVendas_Prod);
	
	j=1;
	for(i=0;i<QtdeV;i++)
	{
		fseek(PtrOrdV,i*sizeof(tpVendas),0);
		fread(&V,sizeof(tpVendas),1,PtrOrdV);
		
		for(k=0;k<QtdeVP;k++)
		{
			fseek(PtrOrdVP,k*sizeof(tpVendas_Prod),0);
			fread(&VP,sizeof(tpVendas_Prod),1,PtrOrdVP);
			if(VP.CodVenda==V.CodVenda)
			{
				VP.CodVenda=j;
				fseek(PtrOrdVP,k*sizeof(tpVendas_Prod),0);
				fwrite(&VP,sizeof(tpVendas_Prod),1,PtrOrdVP);
			}
		}
		V.CodVenda=j;
		fseek(PtrOrdV,i*sizeof(tpVendas),0);
		fwrite(&V,sizeof(tpVendas),1,PtrOrdV);
		j++;
	}
	
	fclose(PtrOrdV);
	fclose(PtrOrdVP);
					

	EscrMsg();
	printf("LIMPEZA CONCLUIDA COM SUCESSO!");
	getch();
							
}

void RecuperarDados(void)
{              
	remove("produtos.dat");
	rename("bprodutos.dat","produtos.dat");
	remove("forn.dat");
	rename("bforn.dat","forn.dat");
	remove("clientes.dat");
	rename("bclientes.dat","clientes.dat");
	remove("vendas.dat");
	rename("bvendas.dat","vendas.dat");
	remove("vendasprod.dat");
	rename("bvendasprod.dat","vendasprod.dat");
	Backup();
	
	EscrMsg();
	printf("RECUPERACAO DE DADOS REALIZADA!");
	getch();
}

void CriaArquivos(void)
{
	FILE *F = fopen("forn.dat","ab");
	fclose(F);
	FILE *P = fopen("produtos.dat","ab");
	fclose(P);
	FILE *C = fopen("clientes.dat","ab");
	fclose(C);
	FILE *V = fopen("vendas.dat","ab");
	fclose(V);
	FILE *VP = fopen("vendasprod.dat","ab");
	fclose(VP);
	FILE *FB = fopen("bforn.dat","ab");
	fclose(FB);
	FILE *PB = fopen("bprodutos.dat","ab");
	fclose(PB);
	FILE *CB = fopen("bclientes.dat","ab");
	fclose(CB);
	FILE *VB = fopen("bvendas.dat","ab");
	fclose(VB);
	FILE *VPB = fopen("bvendasprod.dat","ab");
	fclose(VPB);
}

int main(void)
{
	int i;
	char op;
	
	CriaArquivos();
	
	do
	{
		op=Menu();
		LimpaMsg();
		LimpaEntrada();
		if(VerMenuP(op)==-1)
			EntInv();
		else
			switch(op)
			{
				case 'P':
					do
					{
						MenuProduto();
						op = toupper(getch());
						if(VerMenuSec(op)==-1)
							EntInv();
						else
							switch(op)
							{
								case 'A':
									CadProd();
									break;
								case 'B':
									ConsultaProd();
									break;
								case 'C':
									ExcProd();
									break;
								case 'D':
									AltProd();
									break;
								case 'E':
									RelatorioProd();
									break;
							}
					}while(op!='R');
					break;
				case 'F':
					do
					{
						MenuFornecedor();
						op = toupper(getch());
						if(VerMenuForn(op)==-1)
							EntInv();
						else
						switch(op)
							{
								case 'A':
									CadForn();
									break;
								case 'B':
									ConsultaForn();
									break;
								case 'C':
									ExcForn();
									break;
								case 'D':
									AltForn();
									break;
								case 'E':	
									RelatorioForn();
									break;
								case 'F':
									AumentoForn();
									break;
							}
					}while(op!='R');
					break;
				case 'C':
					do
					{
						MenuCliente();
						op = toupper(getch());
						if(VerMenuSec(op)==-1)
							EntInv();
						else
							switch(op)
							{
								case 'A':
									CadCli();
									break;
								case 'B':
									ConsultaCli();
									break;
								case 'C':
									ExcCli();
									break;
								case 'D':
									AltCli();
									break;
								case 'E':
									RelatorioCli();
									break;
							}
					}while(op!='R');
					break;
				case 'V':
					do
					{
						MenuVendas();
						op = toupper(getch());
						if(VerMenuVendas(op)==-1)
							EntInv();
						else
							switch(op)
							{
								case 'A':
									Venda();
									break;
								case 'B':
									RelatorioVP();
									break;
									break;
								case 'C':
									RelatorioVendas();
									break;
								case 'D':
									ExcVenda();
									break;
								case 'E':
									ConsultaCF();
									break;
							}
					}while(op!='R');
					break;
				case 'B':
					do
					{
						MenuBackup();
						op = toupper(getch());
						if(VerMenuBackup(op)==-1)
							EntInv();
						else
							switch(op)
							{
								case 'A':
									Backup();
									EscrMsg();
									printf("BACKUP REALIZADO COM SUCESSO!");
									getch();
									break;
								case 'B':
									RecuperarDados();
									break;
								case 'C':
									LimpezaFisica();
							}
					}while(op!='R');
					break;
				case 'I':
					Inserir();
			} 
	}while(op!=27);
	
	for(i=5;i<22;i++)
	{
		gotoxy(2,i);
		printf("                                                                              ");
	}
	gotoxy(35,7);
	printf("INTEGRANTES");
	gotoxy(23,14);
	printf("262319446 - MATHEUS OLIVEIRA DA SILVA");
	gotoxy(3,23);
	printf("                                                                            ");
	gotoxy(27,23);
	printf("PROF. LEANDRO LUIZ DE ALMEIDA");
	Moldura(2,5,79,21,1,15);
	
	getch();
	
	gotoxy(1,27);
	return 0;
}
