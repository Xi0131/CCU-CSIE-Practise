#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

class qubit{
    public:
        vector<int> vec;
        void swap_vec(qubit &x);
        void add_connection(int node);
};

// swap connected node
void qubit::swap_vec(qubit &x){
    vec.swap(x.vec);
}

void qubit::add_connection(int node){
    vec.push_back(node);
}

void bfs(){
    
}

int main()
{
    int logQubits, gates, precedences, phyQubits, phyLinks;
    cin >> logQubits >> gates >> precedences >> phyQubits >> phyLinks;
    // gates
    // int cntGate[logQubits + 1];
    vector<pii> cntGate(logQubits + 1);
    // memset(cntGate, 0, sizeof(cntGate));
    for(int i = 0; i < logQubits + 1; i++){
        cntGate[i] = make_pair(0, i);
    }
    vector<pii> gate_id = {{0, 0}};
    for(int i = 0, a, b, c; i < gates; i++){
        cin >> a >> b >> c;
        gate_id.push_back(make_pair(b, c));
        // cntGate[b]++;
        // cntGate[c]++;
        cntGate[b].first++;
        cntGate[c].first++;
    }
    sort(cntGate.begin(), cntGate.end());


    // container for topology
    vector<int> precedence_id[gates + 1];
    int in[gates + 1];
    for(int i = 0; i < gates + 1; i++) in[i] = 0;
    for(int i = 0, a, b, c; i < precedences; i++){
        cin >> a >> b >> c;
        precedence_id[b].push_back(c);
        in[c]++;
    }
    // container of phyQubit
    vector<qubit> qb(phyQubits + 1);
    for(int i = 0, a, b, c; i < phyLinks; i++){
        cin >> a >> b >> c;
        qb[b].add_connection(c);
        qb[c].add_connection(b);
    }
    // slot for phyQubit
    int slots[phyQubits + 1];
    // initialization for baseline
    for(int i = 0; i <= phyQubits; i++){
        // slots[cntGate[i].second] = i;
        slots[i] = i;
    }

    vector<pair<int, pair<int, int>>> ans;
    queue<int> q;
    for(int i = 1; i <= gates; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    int gate;
    while(!q.empty()){
        gate = q.front();
        q.pop();
        for(int x : precedence_id[gate]){
            in[x]--;
            if(in[x] == 0) q.push(x);
        }
        
        // determine swap
        int node1 = gate_id[gate].first, node2 = gate_id[gate].second;
        int vecSize = qb[node1].vec.size();
        bool foundAdj = false;
        // watch(node1);
        for(int i = 0; i < vecSize; i++){
            // if(node1 == 1) watch(qb[node1].vec[i]);
            if(qb[slots[node1]].vec[i] == node2){
                foundAdj = true;
                break;
            }
        }


        if(!foundAdj){
            bool foundReplace = false;
            int choose;

            for(int i = 0; i < logQubits + 1; i++){
                int tmpGate = cntGate[i].second;
                int tmpPhy = slots[tmpGate];
                for(int j = 0; j < qb[tmpPhy].vec.size(); j++){
                    if(qb[tmpPhy].vec[j] == node2){
                        choose = tmpGate;
                        foundReplace = true;
                        break;
                    }
                }
                if(foundReplace) break;
            }

            swap(slots[choose], slots[node1]);
            ans.push_back(make_pair(1, make_pair(choose, node1)));
        }


        ans.push_back(make_pair(0, make_pair(gate_id[gate].first, gate_id[gate].second)));
    }

    // output
    for(int i = 1; i <= logQubits; i++){
        cout << i << ' ' << i << '\n';
    }
    for(int i = 0; i < (int)ans.size(); i++){
        if(!ans[i].first) cout << "CNOT q" << ans[i].second.first << " q" << ans[i].second.second << '\n';
        else cout << "SWAP q" << ans[i].second.first << " q" << ans[i].second.second << '\n';
    }
    
	return 0;
}