#include <bits/stdc++.h>

using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>

int main(){
	priority_queue<int> client;
	priority_queue<ii> func;
	priority_queue<iii>tempo;

	int n, m, x;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> x;
		func.push(ii(-i,-x));
	}
	for(int i = 0 ; i < m ; i++){
		cin >> x;
		client.push(x);
	}
	int ans;
	for(ans = 0; ans <= 1e8; ans++){ //caminhando pela linha do tempo
		if(client.empty()){//todos foram atendidos ou estão sendo
			while(tempo.size()!= 1) tempo.pop();
			cout << -tempo.top().first << endl;//resp é o tempo que o ultimo vai terminar de ser atendido
			return 0;
		}	
		while(!tempo.empty() and ans == -tempo.top().first){//linha do tempo bateu com o tempo que um funcionário vai acabar de atender
			ii l = tempo.top().second;
			func.push(l);//devolvendo o func para a fila 
			tempo.pop();
		}
		while(!func.empty()){//jogando cliente pros funcionários
			if(client.empty()){
				while(tempo.size()!= 1) tempo.pop();
				cout << -tempo.top().first << endl;
				return 0;
			}	
			int aux;
			ii help;
			help = func.top();
			aux = ((func.top().second) * client.top()) - ans; //tempo que o atendimento do funcionário com o cliente
			tempo.push(iii(aux,help)); // tempo que vai acabar o atendimento do funcionário x
			func.pop();
			client.pop();
		}
	}	
}