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
        int logQubit;
        void swap_qubit(qubit &x);
        void add_connection(int node);
};

// swap connected logqubit
void qubit::swap_qubit(qubit &x){
    swap(logQubit, x.logQubit);
}

// add connection between phyqubit
void qubit::add_connection(int node){
    vec.push_back(node);
}

int bfs(int ls, int le, int (&slots)[], vector<qubit> &qb, vector<pair<int, pair<int, int>>> &ans){
    bool qvis[10000];
    int qparent[10000];
    memset(qvis, 0, sizeof(qvis));
    memset(qparent, 0, sizeof(qparent));
    
    int sQubit = slots[ls];
    queue<int> q;
    q.push(sQubit);
    
    int qtmp = q.front();
    while(!q.empty()){
        q.pop();

        // break if found
        if(qb[qtmp].logQubit == le){            
            break;
        }

        for(int x : qb[qtmp].vec){
            if(!qvis[x]){
                q.push(x);
                qparent[x] = qtmp;
                qvis[x] = true;
            }
        }
        
        qtmp = q.front();
    }

    int qbacktrack = qtmp;
    while(qparent[qbacktrack] != sQubit){
        ans.push_back(make_pair(1, make_pair(qb[qbacktrack].logQubit, qb[qparent[qbacktrack]].logQubit)));
        swap(slots[qb[qbacktrack].logQubit], slots[qb[qparent[qbacktrack]].logQubit]);
        swap(qb[qbacktrack].logQubit, qb[qparent[qbacktrack]].logQubit);
        qbacktrack = qparent[qbacktrack];
    }
    return 0;
}

int main()
{
    int logQubits, gates, precedences, phyQubits, phyLinks;
    cin >> logQubits >> gates >> precedences >> phyQubits >> phyLinks;
    // gates
    vector<pii> gate_id = {{0, 0}};
    for(int i = 0, a, b, c; i < gates; i++){
        cin >> a >> b >> c;
        gate_id.push_back(make_pair(b, c));
    }
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
        qb[i].logQubit = i;
        slots[i] = i;
    }

    vector<pair<int, pair<int, int>>> ans;
    queue<int> q;
    for(int i = 1; i <= gates; i++)
        if(in[i] == 0) q.push(i);


    int gate;
    while(!q.empty()){
        gate = q.front();
        q.pop();
        for(int x : precedence_id[gate]){
            in[x]--;
            if(in[x] == 0) q.push(x);
        }
        
        // determine swap
        int lnode1 = gate_id[gate].first, lnode2 = gate_id[gate].second;
        int vecSize = qb[lnode1].vec.size();
        bool foundAdj = false;
        int pos = slots[lnode1];
        for(int i = 0; i < vecSize; i++){
            if(qb[pos].logQubit == lnode2){
                foundAdj = true;
                break;
            }
        }

        // if not adjacent, find position and swap trough bfs
        if(!foundAdj){
            bfs(lnode1, lnode2, slots, qb, ans);
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