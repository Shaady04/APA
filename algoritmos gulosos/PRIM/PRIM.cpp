#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

void printv(vector<int>&v){
for(int i=0;i<v.size();i++){
	cout<<" "<<v[i];
}
	cout<<endl;
}

void invertev(vector<int>&v){
	vector<int> tmp;
for(int i=v.size()-1;i>=0;i--){
	tmp.push_back(v[i]);
}
for(int i=0;i<v.size();i++)
	v[i]=tmp[i];
}

int main()
{
	vector<vector<int> > graph;
	fstream file; 
	vector<int> g;
	int flag=0;
	int s,k,m=0;
	int cont;
	file.open("dij10.txt");//abre o arquivo d mesmo diretorio do projeto com o nome entrada.txt

	if(!file.is_open()) cout<<"error while opening the file"<<endl;
	else cout<<"opened successfully"<<endl;// testa se abre sem problemas
	
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

//Implementa o algoritmo aqui

 
    return 0;
}
