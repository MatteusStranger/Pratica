#include <iostream>
#include <vector>
#include <map>
#define INFINITO 10000000

using namespace std;

int main(int argc, char *argv[])
{
	int L, C;

	cin >> L;
	cin >> C;

	vector<vector<string> > mat(L);
	for(int i = 0 ; i < L ; i++)
		mat[i].resize(C);

	int vet_linhas[L], vet_colunas[C];
	map<string, int> valores;

	for(int i = 0; i < L; i++)
	{
		for(int j = 0; j < C; j++)
		{
			cin >> mat[i][j];
			valores[mat[i][j]] = INFINITO;
		}
		cin >> vet_linhas[i];
	}
	for(int i = 0; i < C; i++)
		cin >> vet_colunas[i];
	int qte_vars = valores.size();

	int qte_descobertas = 0;
	while(true)
	{
		if(qte_descobertas == qte_vars)
			break;
			for(int i = 0; i < L; i++)
		{
			string var_desconhecida;
			int vars_conhecidas = 0, qtd_desconhecida = 0, soma = 0;
			int linha_verdade = true;

			for(int j = 0; j < C; j++)
			{
				if(valores[mat[i][j]] == INFINITO)
				{
					if(qtd_desconhecida >= 1 && var_desconhecida != mat[i][j]
							&& var_desconhecida.size() != 0)
					{
						linha_verdade = false;
						break;
					}
					var_desconhecida = mat[i][j];
					qtd_desconhecida++;
				}
				else
				{
					soma += valores[mat[i][j]];
					vars_conhecidas++;
				}
			}

			if(linha_verdade && vars_conhecidas < C)
			{
				if(vars_conhecidas == 0)
				{
					valores[var_desconhecida] = vet_linhas[i] / C;
				}
				else
				{
					valores[var_desconhecida] = (vet_linhas[i] - soma) / qtd_desconhecida;
				}
			qte_descobertas++;
			}
		}
		for(int i = 0; i < C; i++)
		{
			string var_desconhecida;
			int vars_conhecidas = 0, qtd_desconhecida = 0, soma = 0;
			int coluna_verdade = true;

			for(int j = 0; j < L; j++)
			{
				if(valores[mat[j][i]] == INFINITO)
				{
					if(qtd_desconhecida >= 1 && var_desconhecida != mat[j][i]
							&& var_desconhecida.size() != 0)
					{
						coluna_verdade = false;
						break;
					}
					var_desconhecida = mat[j][i];
					qtd_desconhecida++;
				}
				else
				{
					soma += valores[mat[j][i]];
					vars_conhecidas++;
				}
			}
			if(coluna_verdade && vars_conhecidas < L)
			{
				if(vars_conhecidas == 0)
				{
					valores[var_desconhecida] = vet_colunas[i] / L;
				}
				else
				{
					valores[var_desconhecida] = (vet_colunas[i] - soma) / qtd_desconhecida;
				}
				qte_descobertas++;
			}
		}
	}
	map<string, int>::iterator it;
	for(it = valores.begin(); it != valores.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}
