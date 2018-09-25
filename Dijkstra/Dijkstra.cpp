// Caio Assunção Albuquerque 

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstdio>
#include <list>
#include <stdio.h>
#include <limits.h>

#define INF 10000000

using namespace std;

//funcoes

void printv(vector<int>&v){
for(int i=0;i<v.size();i++){
	cout<<" "<<v[i];
}
	cout<<endl<<endl;
}

void printm(vector< vector<int> > matrix){
for(int i=0;i<matrix.size();i++)printv(matrix[i]);}

void invertev(vector<int>&v){
	vector<int> tmp;
for(int i=v.size()-1;i>=0;i--){
	tmp.push_back(v[i]);
}
for(int i=0;i<v.size();i++)
	v[i]=tmp[i];
}

//#############################Main

/*int main()
{


//############################## fim de leitura

//Implementa o algoritmo aqui

    return 0;
}*/

int main(int argc, char** argv)
{
	vector<vector<int> > graph;
	fstream file; 
	vector<int> g;
	int flag=0;
	int s,k,m=0;
	int cont;
	file.open("dij10.txt");//abre o arquivo d mesmo diretorio do projeto com o nome entrada.txt

while(file.good()){//enquanto o arquivo nao terminar
if(flag==0){
	file>>s;
	flag=1;
	m=s;	
	k=s-1;
	continue;

}else{
	file>>s;
	g.push_back(s);
	cont++;
}
}
int u=0;
int h=0;
for(int i=0;i<m;i++){ 
	vector<int> gr;
for(int j=0;j<k;j++){
	gr.push_back(g[h]);
	h++;
}
	u=m-k;
	k--;
	invertev(gr);
for(int q=0;q<u;q++){
	gr.push_back(0);
}
	invertev(gr);
	graph.push_back(gr);
	gr.clear();
}


	int temp = 0;
	//int sz;
	int* dist; //vetor de distancias
	bool* visited; //vetor de visitados
	list<pair<int, int> >* adj; //lista de adj
	priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	//cin >> sz;
	
	adj = new list<pair<int, int> >[m];
	dist = new int[m];
	visited = new bool[m];

	if(!file.is_open()) cout<<"error while opening the file"<<endl;
	else cout<<"opened successfully"<<endl;// testa se abre 
	
	

	for(int i = 0; i < m; i++)
	{
		dist[i] = INF;
		visited[i] = false;
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
		{	
			if(i == j)
			{
				adj[i].push_back(make_pair(j, 0));
			}
			else if(graph[i][j] != 0) {}
			else
			{
				if(j<i) graph[i][j]=graph[j][i];
				adj[i].push_back(make_pair(j, graph[i][j]));
			}
		}
	}
	

	dist[0] = 0; //o primeiro sempre inicia com zero pela definição do trabalho

	pq.push(make_pair(dist[0], 0));

	while(!pq.empty())
	{
		pair<int, int> p = pq.top(); // extrai o pair do topo
		int v_p = p.second; // obtém o vértice do pair
		pq.pop(); // remove da fila

		if(visited[v_p] == false)
		{
			// marca como visitado
			visited[v_p] = true;

			list<pair<int, int> >::iterator it;

			// percorre os vértices "v" adjacentes de "u"
			for(it = adj[v_p].begin(); it != adj[v_p].end(); it++)
			{
				// obtém o vértice adjacente e o custo da aresta
				int v = it->first;
				int custo_aresta = it->second;

				// relaxamento (u, v)
				if(dist[v] > (dist[v_p] + custo_aresta))
				{
					// atualiza a distância de "v" e insere na fila
					dist[v] = dist[v_p] + custo_aresta;
					pq.push(make_pair(dist[v], v));
				}
			}
		}

	}

	cout << "Temos: "<< dist[m-1] << endl;

	return 0;

}
